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
    int c = 0;
    while (head)
    {
      head = head->next;
      c++;
    }
    return c;
  }

  int getDecimalValue(ListNode *head)
  {
    ListNode *temp = head;
    int size = get_size(temp);
    temp = head;
    int ans = 0;
    int i = size - 1;
    while (temp && i >= 0)
    {
      if (temp->val == 1)
      {
        ans += (1 << i);
      }
      temp = temp->next;
      i--;
    }
    return ans;
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

  vector<int> nums = {1, 0, 1};
  ListNode *list = createLinkedList(nums);
  cout << "Linked List: ";
  printLinkedList(list);
  int result = solution.getDecimalValue(list);
  cout << "Decimal Value: " << result << endl;

  return 0;
}
