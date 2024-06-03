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
  ListNode *middle(ListNode *head)
  {
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *p = slow;
    while (fast->next != nullptr)
    {
      if (fast->next->next == nullptr)
      {
        p = slow;
        slow = slow->next;
        break;
      }
      else
      {
        p = slow;
        slow = slow->next;
        fast = fast->next->next;
      }
    }
    return p;
  }

  ListNode *deleteMiddle(ListNode *head)
  {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (head == nullptr)
      return head;
    if (head->next == nullptr)
    {
      return nullptr;
    }
    if (head->next->next == nullptr)
    {
      head->next = nullptr;
      return head;
    }
    ListNode *t = head;
    ListNode *d = middle(t);
    d->next = d->next->next;
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
  ll.insert_tail(3);
  ll.insert_tail(4);
  ll.insert_tail(5);

  cout << "Original List: ";
  ll.display();

  Solution sol;
  ll.head = sol.deleteMiddle(ll.head);

  cout << "After deleting the middle node: ";
  ll.display();

  return 0;
}
