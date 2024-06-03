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
  ListNode *insertionSortList(ListNode *head)
  {
    ListNode *dummy = new ListNode(0);
    ListNode *temp = dummy;
    ListNode *curr = head, *nex = nullptr;

    while (curr)
    {
      nex = curr->next;
      temp = dummy;

      while (temp->next && temp->next->val < curr->val)
      {
        temp = temp->next;
      }

      curr->next = temp->next;
      temp->next = curr;
      curr = nex;
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

  vector<int> nums1 = {4, 2, 1, 3};
  ListNode *list1 = createLinkedList(nums1);
  cout << "Original List: ";
  printLinkedList(list1);
  ListNode *result1 = solution.insertionSortList(list1);
  cout << "Sorted List: ";
  printLinkedList(result1);

  vector<int> nums2 = {-1, 5, 3, 4, 0};
  ListNode *list2 = createLinkedList(nums2);
  cout << "Original List: ";
  printLinkedList(list2);
  ListNode *result2 = solution.insertionSortList(list2);
  cout << "Sorted List: ";
  printLinkedList(result2);

  return 0;
}
