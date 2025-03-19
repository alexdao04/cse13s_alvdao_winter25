#include "final.h"

#include <stdio.h>

WordCountTree *merge_trees(WordCountTree *tree1, WordCountTree *tree2) {
  // we need to merge two binary trees
  // similar approach to #4: traverse the trees using dfs
  // reason being that merging the trees requires us to go down each possible path
  // and merge the values at each node

  struct WordCountTree *combined_tree = NULL;
  // initialize WordCountTree to store combined tree

  if(tree1 == NULL) {
    return tree2;
    // if tree1 is NULL, return tree2
  } 
  
    else if (tree2 == NULL) {
      return tree1;
      // if tree2 is NULL, return tree1
      // this just checks that both trees actually exist
      } 
      
      else {
        tree1 -> count += tree2 -> count;
        // if both trees exist, we can merge them

        tree1 -> left = merge_trees(tree1 -> left, tree2 -> left);
        // merge the left side of the trees for both tree1 and tree2

        tree1 -> right = merge_trees(tree1 -> right, tree2 -> right);
        // similarly, merge the right side of the tree for tree1 and tree2

        return tree1;
        // return the merged tree
      }

    combined_tree = merge_trees(tree1, tree2);
    // merge both trees

    return combined_tree;
  }

