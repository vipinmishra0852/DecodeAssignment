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
  ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
  {
    ListNode *temp1 = list1;
    ListNode *temp2 = list1;
    ListNode *t = list2;
    int count = 1;
    while (count != a)
    {
      temp1 = temp1->next;
      count++;
    }
    count = 0;
    while (count != b)
    {
      temp2 = temp2->next;
      count++;
    }
    bool flag = false;
    if (temp2->next != nullptr)
    {
      temp2 = temp2->next;
      flag = true;
    }
    temp1->next = t;
    while (t->next != nullptr)
    {
      t = t->next;
    }
    if (flag)
      t->next = temp2;
    return list1;
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
  LinkedList list1;
  list1.insert_tail(0);
  list1.insert_tail(1);
  list1.insert_tail(2);
  list1.insert_tail(3);
  list1.insert_tail(4);
  list1.insert_tail(5);

  LinkedList list2;
  list2.insert_tail(1000000);
  list2.insert_tail(1000001);
  list2.insert_tail(1000002);

  cout << "List 1 before merge: ";
  list1.display();

  cout << "List 2: ";
  list2.display();

  Solution sol;
  list1.head = sol.mergeInBetween(list1.head, 3, 4, list2.head);

  cout << "List 1 after merge: ";
  list1.display();

  return 0;
}
