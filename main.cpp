#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    // FIXME
    return nullptr;
  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
