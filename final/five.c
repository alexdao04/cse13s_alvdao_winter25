#include "final.h"

#include <stdio.h>

#include <string.h>

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
  
  if (tree2 == NULL) {
    return tree1;
      // if tree2 is NULL, return tree1
      // this really just checks that both trees exist
  } 
  
  if(strcmp(tree1 -> word, tree2 -> word) == 0) {
    // if the words are the same
    tree1 -> count += tree2 -> count;
      // if the words are the same, we add the counts together
      // and store the result in tree1
    tree1 -> left = merge_trees(tree1 -> left, tree2 -> left);
      // we traverse the left side of the tree
    tree1 -> right = merge_trees(tree1 -> right, tree2 -> right);
      // we traverse the right side of the tree
    return tree1;
      // return the combined tree
  } 

  else {
    if(strcmp(tree1 -> word, tree2 -> word) < 0) {
      combined_tree = tree1;
        // if tree1 is less than tree2, we store tree1 in combined_tree
      combined_tree -> left = merge_trees(tree1 -> left, tree2);
        // we traverse the left side of the tree
      combined_tree -> right = merge_trees(tree1 -> right, tree2);
        // we traverse the right side of the tree
    } 
    
    else {
      combined_tree = tree2;
        // if tree2 is less than tree1, we store tree2 in combined_tree
      combined_tree -> left = merge_trees(tree1, tree2 -> left);
        // we traverse the left side of the tree
      combined_tree -> right = merge_trees(tree1, tree2 -> right);
        // we traverse the right side of the tree
    }
  }

  return combined_tree;
    // return the combined tree after traversing both
}
    
