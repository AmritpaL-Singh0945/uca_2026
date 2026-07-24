#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
  
    struct stat st;

    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    if (stat(argv[1], &st) == -1) {
        perror("stat failed");
        return 1;
    }

    printf("=== File Attributes for: %s ===\n", argv[1]);
    printf("File Type:            ");

    switch (st.st_mode & S_IFMT) {
        case S_IFBLK:  printf("Block Device\n"); break;
        case S_IFCHR:  printf("Character Device\n"); break;
        case S_IFDIR:  printf("Directory\n"); break;
        case S_IFIFO:  printf("FIFO/Pipe\n"); break;
        case S_IFLNK:  printf("Symlink\n"); break;
        case S_IFREG:  printf("Regular File\n"); break;
        case S_IFSOCK: printf("Socket\n"); break;
        default:       printf("Unknown\n"); break;
    }

    printf("Permissions:          %04o\n", st.st_mode & 0777);
    printf("File Size:            %ld bytes\n", (long)st.st_size);
    printf("Hard Links Count:     %ld\n", (long)st.st_nlink);
    printf("Owner (UID):          %u\n", st.st_uid);
    printf("Group (GID):          %u\n", st.st_gid);
    
    printf("Last Access Time:     %s", ctime(&st.st_atime));
    printf("Last Modification:    %s", ctime(&st.st_mtime));
    printf("Status Change Time:   %s", ctime(&st.st_ctime));

    return 0;
}