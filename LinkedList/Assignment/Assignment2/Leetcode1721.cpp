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
  int get_size(ListNode *head)
  {
    ListNode *temp = head;
    int count = 1;
    while (temp->next != nullptr)
    {
      temp = temp->next;
      count++;
    }
    return count;
  }

  ListNode *swapNodes(ListNode *head, int k)
  {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ListNode *temp1 = head;
    ListNode *temp2 = head;
    int size = get_size(head);
    int i = 1;
    int j = 1;
    while (i != k)
    {
      temp1 = temp1->next;
      i++;
    }
    while (j != size - k + 1)
    {
      temp2 = temp2->next;
      j++;
    }
    ListNode *t = new ListNode(100);
    t->val = temp1->val;
    temp1->val = temp2->val;
    temp2->val = t->val;
    delete t;
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
  ll.head = sol.swapNodes(ll.head, 2);

  cout << "After swapping nodes: ";
  ll.display();

  return 0;
}
