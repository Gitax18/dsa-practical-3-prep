#include "tree.h"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void postorder(TreeNode *root) {
  if (root != nullptr) {
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
  }
}

void preorder(TreeNode *root) {
  if (root != nullptr) {
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
  }
}

void inorder(TreeNode *root) {
  if (root != nullptr) {
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
  }
}

int main() {
  vector<int> v{1, 2, 3, 4, 5, 6, -1, -1, -1, -1, -1, -1};
  TreeNode *root = buildTree(v);
  cout << "*** Tree Traversal ***" << endl;
  cout << "Inorder: ";
  inorder(root);
  cout << endl;
  cout << "Postorder: ";
  postorder(root);
  cout << endl;
  cout << "Preorder: ";
  preorder(root);
  cout << endl;
  return 0;
}
