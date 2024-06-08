#include <vector>
#include <string>
#include <stack>
#include <numeric>
#include <iostream>
using namespace std;

int calPoints(vector<string> &ops)
{
  stack<int> record;

  for (string op : ops)
  {
    if (op == "+")
    {
      int top = record.top();
      record.pop();
      int newTop = top + record.top();
      record.push(top);
      record.push(newTop);
    }
    else if (op == "D")
    {
      record.push(2 * record.top());
    }
    else if (op == "C")
    {
      record.pop();
    }
    else
    {
      record.push(stoi(op));
    }
  }

  int sum = 0;
  while (!record.empty())
  {
    sum += record.top();
    record.pop();
  }

  return sum;
}

int main()
{
  vector<string> ops1 = {"5", "2", "C", "D", "+"};
  vector<string> ops2 = {"5", "-2", "4", "C", "D", "9", "+", "+"};

  int result1 = calPoints(ops1);
  int result2 = calPoints(ops2);

  cout << "Result for ops1: " << result1 << endl;
  cout << "Result for ops2: " << result2 << endl;

  return 0;
}
