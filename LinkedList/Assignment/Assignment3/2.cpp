#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    int carry = 0;
    ListNode *dummy = new ListNode(0);
    ListNode *head = dummy;

    while (l1 || l2 || carry)
    {
      int x = l1 ? l1->val : 0;
      int y = l2 ? l2->val : 0;
      int sum = x + y + carry;
      carry = sum / 10;
      head->next = new ListNode(sum % 10);
      head = head->next;

      if (l1)
        l1 = l1->next;
      if (l2)
        l2 = l2->next;
    }

    return dummy->next;
  }
};

// Utility function to create a linked list from a vector
ListNode *createLinkedList(const vector<int> &nums)
{
  if (nums.empty())
    return nullptr;
  ListNode *head = new ListNode(nums[0]);
  ListNode *current = head;
  for (size_t i = 1; i < nums.size(); ++i)
  {
    current->next = new ListNode(nums[i]);
    current = current->next;
  }
  return head;
}

// Utility function to print a linked list
void printLinkedList(ListNode *head)
{
  ListNode *current = head;
  while (current)
  {
    cout << current->val << " ";
    current = current->next;
  }
  cout << endl;
}

int main()
{
  Solution solution;

  vector<int> nums1 = {2, 4, 3};
  vector<int> nums2 = {5, 6, 4};
  ListNode *list1 = createLinkedList(nums1);
  ListNode *list2 = createLinkedList(nums2);
  cout << "List 1: ";
  printLinkedList(list1);
  cout << "List 2: ";
  printLinkedList(list2);
  ListNode *result = solution.addTwoNumbers(list1, list2);
  cout << "Sum: ";
  printLinkedList(result);

  return 0;
}
