#include <stdio.h> 
#include <stdlib.h>

void magicSquare(long n){
  if(n%2==0){
    printf("error");
  }else{
    long ms[n][n];
    for(long i=0;i<n;i++){
      for(long j=0;j<n;j++){
        ms[i][j] = 0;
      }
    }

    long row = 0;
    long column = n/2;
    for(long i=1;i<n*n+1;i++){
      ms[row][column]=i;
      row = row - 1;
      column = column + 1;
      if(row==-1 && column==n){
        row = row + 2;
        column--;
      }else if(row == -1){
        row = n-1;
      }else if(column==n){
        column = 0;
      }else if(ms[row][column] != 0){
        row = row + 2;
        column = column - 1;
      }
    }

    for(long f=0; f<n; f++){
      for(long d=0;d<n; d++){
        printf("%li\t", ms[f][d]);
      }
      printf("\n");
    }
  }
}

int main(int argc, char* argv[argc+1]){
  long num = atoi(argv[1]);
  magicSquare(num);
  return EXIT_SUCCESS;
}
