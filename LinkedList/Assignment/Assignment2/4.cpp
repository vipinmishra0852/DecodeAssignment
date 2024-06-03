#include <iostream>
using namespace std;

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
  ListNode *removeElements(ListNode *head, int val)
  {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ListNode *temp1 = head;
    if (temp1->next == NULL && temp1->val == val)
      return NULL;
    ListNode *temp2 = head->next;
    while (temp2->next->next != NULL)
    {
      if (temp2->val == val)
      {
        temp1->next = temp1->next->next;
        temp1 = temp1->next;
        temp2 = temp2->next->next;
      }
      else
      {
        temp1 = temp1->next;
        temp2 = temp2->next;
      }
    }
    temp1 = temp1->next;
    temp2 = temp2->next;
    if (temp2->val == val)
    {
      temp1->next = NULL;
    }

    return head;
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

  void insert_head(int data)
  {
    ListNode *new_node = new ListNode(data);
    if (!head)
    {
      head = new_node;
      tail = new_node;
    }
    else
    {
      new_node->next = head;
      head = new_node;
    }
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
  ll.insert_tail(6);
  ll.insert_tail(3);
  ll.insert_tail(4);
  ll.insert_tail(5);
  ll.insert_tail(6);

  cout << "Original List: ";
  ll.display();

  Solution sol;
  ll.head = sol.removeElements(ll.head, 6);

  cout << "List after removing elements with value 6: ";
  ll.display();

  return 0;
}
