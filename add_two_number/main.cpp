#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  ListNode *dummyHead = new ListNode(0);
  ListNode *current = dummyHead;
  int carry = 0;

  while (l1 != nullptr || l2 != nullptr || carry != 0) {
    int x = (l1 != nullptr) ? l1->val : 0;
    int y = (l2 != nullptr) ? l2->val : 0;

    int sum = x + y + carry;
    int digit = sum % 10;
    carry = sum / 10;

    ListNode *newNode = new ListNode(digit);

    current->next = newNode;
    current = current->next;

    if (l1 != nullptr)
      l1 = l1->next;
    if (l2 != nullptr)
      l2 = l2->next;
  }
  
  return dummyHead->next;
}

int main() {

  ListNode *l1 = new ListNode(2);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(3);

  ListNode *l2 = new ListNode(5);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(4);

  ListNode *result = addTwoNumbers(l1, l2);

  cout << "Result: [";
  while (result != nullptr) {
    cout << result->val << (result->next ? " " : "");
    result = result->next;
  }
  cout << "]" << endl;

  return 0;
}