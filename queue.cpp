#include <deque>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  vector<int> v{1, 2, 3, 4, 5};
  queue<int> q;
  for (auto &i : v) {
    q.push(i);
  }

  deque<int> dq;
  for (auto &i : v) {
    dq.push_back(i);
  }

  cout << (q.front() == dq.front()) << endl;
  cout << (q.back() == dq.back()) << endl;
}
