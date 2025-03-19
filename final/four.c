#include "final.h"

#include <stdio.h>

int sum_values_at_max_depth(BinaryTree *tree) {
  // we need to sum the values at the maximum depth of a binary tree
  // hence we traverse the tree with dfs 
  int dfs = 0;
  // intialize dfs and value to 0
  // these will be used to sum the values at the end of the tree
  dfs = tree -> val; 
  // value of tree is the root node
  // we want to start at the root node

  if(tree -> left == NULL && tree -> right == NULL) {
    return dfs;
  } 
  
    else {
      if(tree -> left != NULL) {
        dfs += sum_values_at_max_depth(tree -> left);
        // traverse left side

      } else {
        dfs += sum_values_at_max_depth(tree -> right);
        // traverse right side
      }
    }

  return dfs;
  // return the sum of the values at the end of the tree
}
