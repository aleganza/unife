#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int w;
  int w_limit;
  int h;
  int area;
  int end;
} floor;

void printFloor(floor floor) {
  printf("%d w\n", floor.w);
  printf("%d w_limit\n", floor.w_limit);
  printf("%d h\n", floor.h);
  printf("%d area\n\n", floor.area);
}

int main(void) {

  FILE *input = fopen("input.txt", "r");
  FILE *output = fopen("output.txt", "w");

  if (!input || !output) {
    printf("open files");
    return -1;
  }

  int M;
  fscanf(input, "%d", &M);
  
  floor *floors = (floor *)malloc(2000010 * sizeof(floor));
  int max_area = 0, maybe_new_area, i, j;

  for(i=0; i<M; i++) {
    // initialize i-floor
    fscanf(input, "%d", &floors[i].w);
    floors[i].w_limit = floors[i].w;
    floors[i].h = 1;
    floors[i].area = floors[i].w;

    // update 0-to-i floors data
    for(j=0; j<i; j++) {
      if(floors[j].end == 0) {
        if(floors[i].w != 0) {
          floors[j].h++;

          if(floors[i].w < floors[j].w_limit) {
            floors[j].w_limit = floors[i].w;
          }

          maybe_new_area = floors[j].h * floors[j].w_limit;
          if(maybe_new_area > floors[j].area) {
            floors[j].area = maybe_new_area;
          }
        } else {
          floors[j].end = 1;
        }
      }

      if(floors[j].area > max_area) {
        max_area = floors[j].area;
      }
    }
  }

  printf("%d", max_area);
  fprintf(output, "%d", max_area);

  // for(i=0; i<M; i++) {
  //   printFloor(floors[i]);
  // }

  free(floors);
  fclose(input);
  fclose(output);

  return 0;
}