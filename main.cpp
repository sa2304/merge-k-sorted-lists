#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

#define APPEND(head, tail, val)           \
    if (tail) {                           \
        (tail)->next = new ListNode(val); \
        (tail) = (tail)->next;            \
    } else {                              \
        head = tail = new ListNode(val);  \
    }

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *MakeList(const vector<int> &nums) {
  ListNode *head = nullptr;
  for (auto iter = nums.rbegin(); iter != nums.rend(); ++iter) {
    head = new ListNode(*iter, head);
  }

  return head;
}

class Solution {
  ListNode *mergeLists(ListNode *l1, ListNode *l2) {
    ListNode *result_head = nullptr;
    ListNode *result_tail = nullptr;
    while (l1 && l2) {
      int minval;
      if (l1->val < l2->val) {
        minval = l1->val;
        l1 = l1->next;
      } else {
        minval = l2->val;
        l2 = l2->next;
      }
      APPEND(result_head, result_tail, minval);
    }

    while (l1) {
      APPEND(result_head, result_tail, l1->val);
      l1 = l1->next;
    }

    while (l2) {
      APPEND(result_head, result_tail, l2->val);
      l2 = l2->next;
    }

    return result_head;
  }

 public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    while (1 < lists.size()) {
      lists[0] = mergeLists(lists[0], lists[1]);
      std::swap(lists[1], lists.back());
      lists.pop_back();
    }

    return !lists.empty() ? lists.front() : nullptr;
  }
};

void Test1() {
  Solution s;
  vector<ListNode *> lists{MakeList({1, 4, 5}), MakeList({1, 3, 4}), MakeList({2, 6})};
  ListNode *result = s.mergeKLists(lists);
  for (; result; result = result->next) {
    cout << result->val << ' ';
  }
  cout << '\n';
}

void Test2() {
  Solution s;
  vector<ListNode *> lists{};
  assert(nullptr == s.mergeKLists(lists));
}

void Test3() {
  Solution s;
  vector<ListNode *> lists{nullptr};
  assert(nullptr == s.mergeKLists(lists));
}

int main() {
  Test1();
  Test2();
  Test3();

  return 0;
}
