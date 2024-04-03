#include <stdio.h>
#include <time.h>
#include <windows.h>
#define ROWS 4
#define COLS 4

int matrix [ROWS][COLS];
int ro,co;

void move(int row, int col) {

 if( col >= 0 && row >= 0 && row < ROWS && col < COLS ) {
 ro = row;
 co = col;
 if( matrix[row][col] == 0 )
 matrix[row][col]= 1;
 }
}

void print_matrix() {
 int r,c;
 for ( r=0; r < ROWS; r++) {
 for ( c=0;c< COLS;c++) {
 printf("%d ",matrix[r][c]);
 }
 printf("\n");
 }
 printf("\n");
}

int main() {
 int r,c;
 int i;
 int max;
 double start, end;
  start = (double)clock() / CLOCKS_PER_SEC;

 for (r=0; r < ROWS; r++) {
 for (c=0;c< COLS;c++) {
 matrix[r][c]=0;
 }
 }

 srand(time(NULL));
 ro = ROWS/2;
 co = COLS/2;

 matrix[ro][co]= 1;
 print_matrix();
 Sleep(1500);

 for (i=0;i<100000; i++) {
 max=0;
 int x = rand() % 8;

 switch (x) {
 case 0: move(ro+1, co);
 break;

 case 1: move(ro+1, co+1);
 break;

 case 2: move(ro, co+1);
 break;

 case 3: move(ro-1, co+1);
 break;

 case 4: move(ro-1, co);
 break;

 case 5: move(ro-1, co-1);
 break;

 case 6: move(ro, co-1);
 break;

 case 7: move(ro+1, co-1);
 break;

 }
 print_matrix();
 Sleep(100);

 for ( int a=0; a < ROWS; a++) {
 for ( int b=0;b< COLS;b++) {
max+=matrix[a][b];
 }
 }

if(max==(ROWS*COLS))
    break;
 }
printf("딱정벌레의 총 이동수 %d \n",i);
end = (((double)clock()) / CLOCKS_PER_SEC);
printf("프로그램 수행 시간 :%lf초 \n", (end-start));
 return 0;
}
