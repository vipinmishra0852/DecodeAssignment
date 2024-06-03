#include <iostream>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
  int lengthOfLoop(ListNode *head)
  {
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast)
      {
        return calculateLoopLength(slow);
      }
    }

    return 0;
  }

  int calculateLoopLength(ListNode *nodeInLoop)
  {
    int length = 1;
    ListNode *current = nodeInLoop;
    while (current->next != nodeInLoop)
    {
      current = current->next;
      length++;
    }
    return length;
  }
};

class LinkedList
{
public:
  ListNode *head;
  ListNode *tail;

  LinkedList()
  {
    head = nullptr;
    tail = nullptr;
  }

  void insert_tail(int data)
  {
    ListNode *new_node = new ListNode(data);
    if (!tail)
    {
      head = new_node;
      tail = new_node;
    }
    else
    {
      tail->next = new_node;
      tail = new_node;
    }
  }

  void createLoop(int pos)
  {
    if (pos == -1)
      return;

    ListNode *loopNode = head;
    for (int i = 1; i < pos; ++i)
    {
      loopNode = loopNode->next;
    }
    tail->next = loopNode;
  }

  void display()
  {
    ListNode *current = head;
    while (current)
    {
      cout << current->val << " -> ";
      current = current->next;
    }
    cout << "None" << endl;
  }
};

int main()
{
  LinkedList ll;
  ll.insert_tail(1);
  ll.insert_tail(2);
  ll.insert_tail(3);
  ll.insert_tail(4);
  ll.insert_tail(5);
  ll.insert_tail(6);

  ll.createLoop(3);

  Solution sol;
  int loopLength = sol.lengthOfLoop(ll.head);

  if (loopLength == 0)
  {
    cout << "No loop detected" << endl;
  }
  else
  {
    cout << "Length of the loop is: " << loopLength << endl;
  }

  return 0;
}
