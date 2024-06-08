#include <iostream>
#include <vector>
#include <stack>

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
  vector<int> nextLargerNodes(ListNode *head)
  {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ListNode *temp = head;
    vector<int> v;
    int n = 0;
    while (temp)
    {
      n++;
      v.push_back(temp->val);
      temp = temp->next;
    }
    stack<int> st;
    vector<int> nge(n);
    nge[n - 1] = 0;
    st.push(v[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
      while (!st.empty() && st.top() <= v[i])
      {
        st.pop();
      }
      nge[i] = st.empty() ? 0 : st.top();
      st.push(v[i]);
    }
    return nge;
  }
};

// Function to create a new ListNode
ListNode *createList(vector<int> &vals)
{
  if (vals.empty())
    return nullptr;
  ListNode *head = new ListNode(vals[0]);
  ListNode *current = head;
  for (size_t i = 1; i < vals.size(); ++i)
  {
    current->next = new ListNode(vals[i]);
    current = current->next;
  }
  return head;
}

// Function to print the elements of a vector
void printVector(const vector<int> &v)
{
  for (int x : v)
  {
    cout << x << " ";
  }
  cout << endl;
}

int main()
{
  // Example test case
  vector<int> listValues = {2, 1, 5};
  ListNode *head = createList(listValues);

  // Instantiate Solution class and call the nextLargerNodes function
  Solution sol;
  vector<int> result = sol.nextLargerNodes(head);

  // Print the result
  printVector(result);

  return 0;
}
