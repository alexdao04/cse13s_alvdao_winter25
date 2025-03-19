#include "final.h"

#include <stdio.h>

size_t count_increasing_columns(int **matrix, size_t rows, size_t cols) {
  // we need to count the number of columns that are increasing
  // we can do this by indexing through each column 
  // and checking if the values are increasing
  // if they are, we increment a counter and return the value at the end
  // just for my own reference: i = columns, j = rows

  size_t count = 0;
    // initialize

  if(matrix != NULL) {
    // where our matrix isn't empty
    for(size_t i = 0; i < cols; i++) {
      // we index the columns

      bool check_increasing = true;
        // initialize to true for each column (default)
        // and we run through each column, row by row for increasing values

      for(size_t j = 0; j < rows - 1; j++) {
          // index through the rows.. we dont need to check the last row
          // because there's nothing after it (we've reached the end)
        if(matrix[j][i] >= matrix[j + 1][i]) {
            // if the value at the current row is greater than or equal to the value at the next row
            // the column is not increasing.
          check_increasing = false;
            // set to false since the value at current row
            // is in fact greater than or equal to the value in the next row over
          break;
            // break out of the loop
        }
      }

      if(check_increasing) {
        // if the column is increasing
        count++;
          // increment the counter (we've found an increasing column)
      }
    }
  }

  return count;
  // return our final count
}
