#include <bits/stdc++.h>
using namespace std;

// Function to determine the precedence of operators
int prio(char c)
{
  if (c == '+' || c == '-')
    return 1; // Low precedence for addition and subtraction
  else
    return 2; // Higher precedence for multiplication and division
}

// Function to perform arithmetic operations based on the operator
int solve(int val1, int val2, char c)
{
  if (c == '+')
    return (val1 + val2);
  else if (c == '-')
    return (val1 - val2);
  else if (c == '*')
    return (val1 * val2);
  else
    return (val1 / val2);
}

int main()
{
  // Input expression
  string s = "7+9*4/8-3";

  // Stacks to hold values and operators
  stack<int> val;
  stack<char> op;

  int n = s.length();

  // Parsing the input string
  for (int i = 0; i < n; i++)
  {
    // If the character is a digit
    if (s[i] >= '0' && s[i] <= '9')
      val.push(s[i] - '0'); // Push the numeric value onto the value stack
    else
    {
      // If operator stack is empty or current operator has higher precedence
      if (op.size() == 0 || prio(s[i]) > prio(op.top()))
        op.push(s[i]); // Push the operator onto the operator stack
      else
      {
        // While there are operators with higher or equal precedence in the stack
        while (op.size() > 0 && prio(s[i]) <= prio(op.top()))
        {
          char ch = op.top();              // Get the top operator
          op.pop();                        // Remove the top operator
          int val2 = val.top();            // Get the top value
          val.pop();                       // Remove the top value
          int val1 = val.top();            // Get the next top value
          val.pop();                       // Remove the next top value
          int ans = solve(val1, val2, ch); // Perform the operation
          val.push(ans);                   // Push the result back onto the value stack
        }
        op.push(s[i]); // Push the current operator onto the stack
      }
    }
  }

  // Process remaining operators in the stack
  while (op.size() > 0)
  {
    char ch = op.top();              // Get the top operator
    op.pop();                        // Remove the top operator
    int val2 = val.top();            // Get the top value
    val.pop();                       // Remove the top value
    int val1 = val.top();            // Get the next top value
    val.pop();                       // Remove the next top value
    int ans = solve(val1, val2, ch); // Perform the operation
    val.push(ans);                   // Push the result back onto the value stack
  }

  // Output the final result
  cout << val.top() << endl;

  return 0;
}
