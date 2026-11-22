#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <queue>
#include <vector>

class TreeNode {
public:
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
  TreeNode(int v, TreeNode *l, TreeNode *r) : val(v), left(l), right(r) {}
};

// Builds a tree from a level-order vector; -1 marks a missing node.
inline TreeNode *buildTree(const std::vector<int> &v) {
  if (v.empty() || v[0] == -1)
    return nullptr;

  std::queue<TreeNode *> q;
  TreeNode *root = new TreeNode(v[0]);
  q.push(root);
  int i = 1;
  while (!q.empty() && i < (int)v.size()) {
    TreeNode *curr = q.front();
    q.pop();

    if (i < (int)v.size() && v[i] != -1) {
      curr->left = new TreeNode(v[i]);
      q.push(curr->left);
    }
    i++;

    if (i < (int)v.size() && v[i] != -1) {
      curr->right = new TreeNode(v[i]);
      q.push(curr->right);
    }
    i++;
  }

  return root;
}

#endif // TREE_H
