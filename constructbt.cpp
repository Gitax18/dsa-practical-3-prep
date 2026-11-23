#include "tree.h"
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

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

vector<int> postorderiter(TreeNode *root) {
  vector<int> res;
  stack<TreeNode *> st;
  st.push(root);
  while (!st.empty()) {
    auto curr = st.top();
    st.pop();
    res.push_back(curr->val);
    if (curr->left != nullptr)
      st.push(curr->left);
    if (curr->right != nullptr)
      st.push(curr->right);
  }
  reverse(res.begin(), res.end());
  return res;
}

vector<int> inorderiter(TreeNode *root) {
  vector<int> res;
  stack<TreeNode *> st;
  TreeNode *curr = root;

  while (curr || !st.empty()) {
    while (curr) {
      st.push(curr);
      curr = curr->left;
    }
    curr = st.top();
    res.push_back(curr->val);
    st.pop();
    curr = curr->right;
  }
  return res;
}

TreeNode *constructFromPRE_IN(vector<int> preorder, vector<int> inorder,
                              int &preindex, int instart, int inend) {
  if (instart > inend)
    return nullptr;

  // create a root
  TreeNode *root = new TreeNode(preorder[preindex]);
  preindex++;

  // search the root in inorder traversal
  int rootpos = instart;
  while (rootpos < inend && inorder[rootpos] != root->val) {
    rootpos++;
  }

  // now construct the left and right subtree
  root->left =
      constructFromPRE_IN(preorder, inorder, preindex, instart, rootpos - 1);
  root->right =
      constructFromPRE_IN(preorder, inorder, preindex, rootpos + 1, inend);

  return root;
}

TreeNode *constructFromPOST_IN(vector<int> postorder, vector<int> inorder,
                               int &postindex, int instart, int inend) {
  if (instart > inend)
    return nullptr;

  TreeNode *root = new TreeNode(postorder[postindex]);
  postindex--;

  int rootpos = instart;
  while (rootpos <= inend && inorder[rootpos] != root->val) {
    rootpos++;
  }

  root->right =
      constructFromPOST_IN(postorder, inorder, postindex, rootpos + 1, inend);

  root->left =
      constructFromPOST_IN(postorder, inorder, postindex, instart, rootpos - 1);

  return root;
}

int main() {
  vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, -1, -1, -1, -1, -1, -1, -1, -1, -1};
  TreeNode *root = buildTree(v);

  auto inorder = inorderiter(root);
  auto postorder = postorderiter(root);
  auto preorder = preorderiter(root);

  int preindex = 0;
  TreeNode *root2 =
      constructFromPRE_IN(preorder, inorder, preindex, 0, inorder.size() - 1);

  auto inorder2 = inorderiter(root2);
  auto preorder2 = preorderiter(root2);

  for (int k : inorder2) {
    cout << k << " ";
  }
  cout << endl;

  for (int k : preorder2) {
    cout << k << " ";
  }
  cout << endl;

  int postindex = postorder.size() - 1;
  TreeNode *root3 = constructFromPOST_IN(postorder, inorder, postindex, 0,
                                         inorder.size() - 1);
  auto inorder3 = inorderiter(root3);
  auto postorder2 = preorderiter(root3);

  for (int k : inorder3) {
    cout << k << " ";
  }
  cout << endl;

  for (int k : postorder2) {
    cout << k << " ";
  }
  cout << endl;
  return 0;
}
