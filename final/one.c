#include "final.h"
#include <stdio.h>

size_t count_increasing_columns(int **matrix, size_t rows, size_t cols) {
  // we need to count the number of columns that are increasing
  // we can do this by iterating through each column 
  // and checking if the values are increasing
  // if they are, we increment a counter and return the value at the end

  size_t count = 0;
  // initialize

  for(rows = 0; rows < 4; rows++) {
    for(cols = 0; cols < 3; cols++) {
      // we define the boundaries of this loop as a 4x3 matrix

      if(matrix[rows][cols] 
        // should check whether the current value is less than the next value
        // cols+1 is the next value over that we're comparing
        count++;
        // increment if compared value is greater
        // continue until we reach end of matrix
        // we got 4 instead of 2. why is that?
        // we need to check if we're moving to the next row
        // if we're at the end of the row, we need to move to the next row
        // we can do this by checking if we're at the end of the row

        if(cols == 2) {
          // if we're at the end of the row
          // we need to move to the next row
          // we can do this by incrementing rows
          rows++;
          // we need to reset cols to 0
          cols = 0;
          
        }
      }
    } 

  return count;
  // return our final count at the end when done indexing
}
