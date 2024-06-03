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
  ListNode *oddEvenList(ListNode *head)
  {
    if (!head || !head->next)
      return head;

    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *evenHead = even;

    while (even && even->next)
    {
      odd->next = even->next;
      odd = odd->next;
      even->next = odd->next;
      even = even->next;
    }

    odd->next = evenHead;
    return head;
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

  vector<int> nums1 = {1, 2, 3, 4, 5};
  ListNode *list1 = createLinkedList(nums1);
  cout << "Original List: ";
  printLinkedList(list1);
  ListNode *result1 = solution.oddEvenList(list1);
  cout << "Odd-Even List: ";
  printLinkedList(result1);

  vector<int> nums2 = {2, 1, 3, 5, 6, 4, 7};
  ListNode *list2 = createLinkedList(nums2);
  cout << "Original List: ";
  printLinkedList(list2);
  ListNode *result2 = solution.oddEvenList(list2);
  cout << "Odd-Even List: ";
  printLinkedList(result2);

  return 0;
}
