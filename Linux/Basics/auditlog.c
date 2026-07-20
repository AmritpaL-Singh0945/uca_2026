#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define LOG_FILE "audit.log"

void add_log(const char *message) {
    // Open file: Write only, create if missing, append mode. Permissions: rw-r--r--
    int fd = open(LOG_FILE, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd < 0) {
        char err[] = "Error: Cannot open log file for writing.\n";
        write(STDERR_FILENO, err, strlen(err));
        return;
    }

    // Write the message and a newline character
    write(fd, message, strlen(message));
    write(fd, "\n", 1);
    
    close(fd);
}

void view_log() {
    // Open file: Read only
    int fd = open(LOG_FILE, O_RDONLY);
    if (fd < 0) {
        char err[] = "Log file is empty or does not exist.\n";
        write(STDERR_FILENO, err, strlen(err));
        return;
    }

    char buffer[1024];
    ssize_t bytes_read;
    int line_num = 1;
    int is_new_line = 1;
    char line_prefix[32];

    // Read in chunks of 1024 bytes
    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        ssize_t start_idx = 0;
        
        for (ssize_t i = 0; i < bytes_read; ++i) {
            // If we are at the start of a new line, print the line number
            if (is_new_line) {
                int prefix_len = snprintf(line_prefix, sizeof(line_prefix), "%d: ", line_num);
                write(STDOUT_FILENO, line_prefix, prefix_len);
                is_new_line = 0;
                start_idx = i;
            }
            
            // If we hit a newline, write the chunk we've scanned so far
            if (buffer[i] == '\n') {
                write(STDOUT_FILENO, buffer + start_idx, i - start_idx + 1);
                line_num++;
                is_new_line = 1;
            }
        }
        
        // If the buffer ends but no newline was hit, flush the remaining part of the line
        if (!is_new_line && bytes_read > 0 && buffer[bytes_read - 1] != '\n') {
            write(STDOUT_FILENO, buffer + start_idx, bytes_read - start_idx);
        }
    }
    
    close(fd);
}

int main(int argc, char *argv[]) {
    if (argc == 3 && strcmp(argv[1], "--add") == 0) {
        add_log(argv[2]);
    } 
    else if (argc == 2 && strcmp(argv[1], "--view") == 0) {
        view_log();
    } 
    else {
        char usage[] = "Usage:\n  ./auditlog --add \"message\"\n  ./auditlog --view\n";
        write(STDERR_FILENO, usage, strlen(usage));
    }
    
    return 0;
}