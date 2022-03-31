#include <stdio.h>
#include <ctype.h>

int main(void) {
  FILE * matrix = fopen("input.txt", "r");

  if (matrix == NULL) {
    printf("error");
    return 1;
  }
  
  int c;
  int lineIndex = 0;
  int width = 0;
  int height = 0;
  int A[5][19];

  while((c = fgetc(matrix)) != EOF) {
    if (c == '\n') {
      if (!height) 
      width = lineIndex;
      lineIndex = 0;
      ++height;
    } else if (isdigit(c)) {
      A[height][lineIndex++] = c;
    }
  }
  ++height;
  
  int x[2] = {-1, -1}; //предыдущий столбец
  int y[2] = {-1, -1}; //текущий столбец
  int elementIndex = 0;
  int EdgeNumber = 0;

  for (int i = 0; i != width; ++i) {
    for (int j = 0; j != height; ++j) {
      if (A[j][i] == '1') {
        y[elementIndex++] = j;
      }
    }
    elementIndex = 0;
    if ((y[0] != x[0] || 
         y[1] != x[1]) && 
         y[0] != -1 && y[1] != -1) {
      ++EdgeNumber;
    }
    for (int k = 0; k != 2; ++k) {
      x[k] = y[k];
      y[k] = -1;
    }
  }
  if (EdgeNumber > (height - 1)*(height - 2)/2)
    printf("yes\n");
  else
    printf("no\n");
  return 0;
}


