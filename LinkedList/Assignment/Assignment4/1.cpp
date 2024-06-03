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
  ListNode *swapPairs(ListNode *head)
  {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *prev = dummy;

    while (prev->next && prev->next->next)
    {
      ListNode *first = prev->next;
      ListNode *second = prev->next->next;

      // Swapping
      prev->next = second;
      first->next = second->next;
      second->next = first;

      prev = first;
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

  // Test case 1
  vector<int> nums1 = {1, 2, 3, 4};
  ListNode *list1 = createLinkedList(nums1);
  cout << "Original List 1: ";
  printLinkedList(list1);
  ListNode *result1 = solution.swapPairs(list1);
  cout << "Swapped List 1: ";
  printLinkedList(result1);

  // Test case 2
  vector<int> nums2 = {};
  ListNode *list2 = createLinkedList(nums2);
  cout << "Original List 2: ";
  printLinkedList(list2);
  ListNode *result2 = solution.swapPairs(list2);
  cout << "Swapped List 2: ";
  printLinkedList(result2);

  // Test case 3
  vector<int> nums3 = {1};
  ListNode *list3 = createLinkedList(nums3);
  cout << "Original List 3: ";
  printLinkedList(list3);
  ListNode *result3 = solution.swapPairs(list3);
  cout << "Swapped List 3: ";
  printLinkedList(result3);

  return 0;
}
