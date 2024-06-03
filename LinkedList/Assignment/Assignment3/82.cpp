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
  ListNode *deleteDuplicates(ListNode *head)
  {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *temp = dummy;
    while (head != nullptr)
    {
      if (head->next && head->val == head->next->val)
      {
        while (head->next && head->val == head->next->val)
        {
          head = head->next;
        }
        temp->next = head->next;
      }
      else
      {
        temp = temp->next;
      }
      head = head->next;
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

  vector<int> nums1 = {1, 2, 3, 3, 4, 4, 5};
  ListNode *list1 = createLinkedList(nums1);
  cout << "Original List: ";
  printLinkedList(list1);
  ListNode *result1 = solution.deleteDuplicates(list1);
  cout << "List after deleting duplicates: ";
  printLinkedList(result1);

  vector<int> nums2 = {1, 1, 1, 2, 3};
  ListNode *list2 = createLinkedList(nums2);
  cout << "Original List: ";
  printLinkedList(list2);
  ListNode *result2 = solution.deleteDuplicates(list2);
  cout << "List after deleting duplicates: ";
  printLinkedList(result2);

  return 0;
}
