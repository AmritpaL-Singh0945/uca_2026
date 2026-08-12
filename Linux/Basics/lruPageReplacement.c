#include <stdio.h>
#include <stdbool.h>

void simulate_lru(int page_requests[], int num_requests, int num_frames) {

    int frames[num_frames];
    int last_used[num_frames]; // Timestamp array
    int page_faults = 0;

    // Initialize empty slots

    for (int i = 0; i < num_frames; i++) {
        frames[i] = -1;
        last_used[i] = -1;
    }

    for (int time = 0; time < num_requests; time++) {
        int page = page_requests[time];
        bool hit = false;

        // TODO 1:

        for (int i=0;i<num_frames;i++){
          if (page==frames[i]){
            hit=true;
            last_used[i]=time;
            break;
          }
        }
        
        // TODO 2:

        if (hit==false){

          page_faults++;
          int empty_idx=-1;

          for (int i=0;i<num_frames;i++){
            if (frames[i]==-1){
              empty_idx=i;
              break;
            }
          }

          if (empty_idx!=-1){
            frames[empty_idx]=page;
            last_used[empty_idx]=time;

          }

          else{

            int smallest_idx=0;

            for (int i=0;i<num_frames;i++){
               if (last_used[i]<last_used[smallest_idx]) smallest_idx=i;
            }

            frames[smallest_idx]=page;

            last_used[smallest_idx]=time;
          }

        }
    }

    printf("Total Page Faults: %d\n", page_faults);
}

int main() {

    int requests[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int num_requests = sizeof(requests) / sizeof(requests[0]);
    
    simulate_lru(requests, num_requests, 3);
    return 0;
}