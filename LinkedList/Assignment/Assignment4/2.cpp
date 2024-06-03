#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
  ListNode *mergeZeroNodes(ListNode *head)
  {
    ListNode *dummy = new ListNode(0); // Dummy node to handle edge cases
    dummy->next = head;
    ListNode *prev = dummy;

    while (head)
    {
      if (head->val == 0)
      {
        int sum = 0;
        while (head && head->val == 0)
        {
          sum += head->val;
          head = head->next;
        }
        prev->next = new ListNode(sum);
      }
      else
      {
        prev->next = head;
        prev = head;
        head = head->next;
      }
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
  vector<int> nums1 = {0, 3, 1, 0, 4, 5, 2, 0};
  ListNode *list1 = createLinkedList(nums1);
  cout << "Original List 1: ";
  printLinkedList(list1);
  ListNode *result1 = solution.mergeZeroNodes(list1);
  cout << "Modified List 1: ";
  printLinkedList(result1);

  // Test case 2
  vector<int> nums2 = {0, 1, 0, 3, 0, 2, 2, 0};
  ListNode *list2 = createLinkedList(nums2);
  cout << "Original List 2: ";
  printLinkedList(list2);
  ListNode *result2 = solution.mergeZeroNodes(list2);
  cout << "Modified List 2: ";
  printLinkedList(result2);

  return 0;
}
