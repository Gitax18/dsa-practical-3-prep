#include "tree.h"
#include <iostream>
#include <stack>
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

vector<int> preorderiter(TreeNode *root) {
  vector<int> res;
  stack<TreeNode *> st;
  st.push(root);
  while (!st.empty()) {
    auto curr = st.top();
    res.push_back(curr->val);
    st.pop();

    if (curr->right != nullptr) {
      st.push(curr->right);
    }

    if (curr->left != nullptr) {
      st.push(curr->left);
    }
  }

  return res;
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

  // preorder traversal - iterative and recursive
  cout << "Preorder: ";
  preorder(root);
  auto vpi = preorderiter(root);
  cout << " | ";
  for (auto i : vpi)
    cout << i << " ";
  cout << endl;

  return 0;
}
