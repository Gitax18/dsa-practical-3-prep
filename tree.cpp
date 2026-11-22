#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class TreeNode {
public:
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
  TreeNode(int v, TreeNode *l, TreeNode *r) : val(v), left(l), right(r) {}
};

TreeNode *buildTree(vector<int> v) {
  queue<TreeNode *> q;
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

int main() {
  vector<int> v = {1, 2, 3, 4, 5, 6, -1, -1, -1, -1, -1, -1};
  auto root = buildTree(v);
  return 0;
}
