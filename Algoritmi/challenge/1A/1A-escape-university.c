#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int binarySearch(int arr[], int l, int r, int x) {
  if (r >= l) {
    int mid = l + (r - l) / 2;
    if (arr[mid] == x)
        return 1;
    if (arr[mid] > x) {
      return binarySearch(arr, l, mid - 1, x);
    }
    return binarySearch(arr, mid + 1, r, x);
  }
  return 0;
}

int main (void) {

  FILE *input = fopen("input.txt", "r");
  FILE *output = fopen("output.txt", "w");

  if (!input || !output) {
    printf("open files");
    return -1;
  }

  int N;
  int Q;
  int id;
  int s;
  int x;
  int i;
  int j;
  int k;

  fscanf(input, "%d", &N);
  fscanf(input, "%d", &Q);

  // fill values matrix
  int mat[N][1010];
  
  for(i=0; i<N; i++) {
    fscanf(input, "%d", &mat[i][0]); // id
    fscanf(input, "%d", &mat[i][1]); // s

    mat[i][2] = mat[i][1]; // s in third position too

    // fill row
    for(j=0; j<mat[i][1] - 1; j++) {
      fscanf(input, "%d", &mat[i][j + 3]);
    }

    // sort row
    insertionSort(mat[i] + 2, mat[i][1]);
  }

  // print matrix
  // for(int a=0; a<N; a++) {
  //   for(int b=0; b<mat[a][1] + 2; b++) {
  //     printf("%d ", mat[a][b]);
  //   }
  //   printf("\n");
  // }

  // fill requests array

  int requests[Q];
  int requestsLength;
  
  for(i=0; i<Q; i++) {
    fscanf(input, "%d", &requests[i]);
  }

  requestsLength = sizeof(requests) / 4;

  // look for requests in file
  int found;
  
  for(k=0; k<requestsLength; k++) {
      found = 0;

      for(i=0; i<N && !found; i++) {
        if(binarySearch(mat[i] + 2, 0, mat[i][1], requests[k])) {
          fprintf(output, "%d ", mat[i][0]);
          found = 1;
        }
      }

      if (!found) fprintf(output, "%s ", "NULL");
    }


  fclose(input);
  fclose(output);

  return 0;
}