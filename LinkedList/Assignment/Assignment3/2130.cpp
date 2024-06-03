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
  int get_size(ListNode *head)
  {
    int count = 0;
    while (head)
    {
      head = head->next;
      count++;
    }
    return count;
  }

  ListNode *reverseList(ListNode *head)
  {
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while (curr)
    {
      ListNode *next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }

  int pairSum(ListNode *head)
  {
    int size = get_size(head);
    if (size == 2)
      return head->val + head->next->val;

    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *secondHalf = reverseList(slow);
    int maxSum = 0;
    ListNode *firstHalf = head;
    while (secondHalf)
    {
      maxSum = max(maxSum, firstHalf->val + secondHalf->val);
      firstHalf = firstHalf->next;
      secondHalf = secondHalf->next;
    }

    return maxSum;
  }
};
