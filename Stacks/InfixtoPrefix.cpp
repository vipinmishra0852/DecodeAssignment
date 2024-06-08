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
string solve(string val1, string val2, char c)
{ // prefix operator + val1 + val2
  string s = "";
  s.push_back(c);
  s += val1;
  s += val2;
  return s;
}

int main()
{
  // Input expression
  string s = "(7+9)*4/8-3";

  // Stacks to hold values and operators
  stack<string> val;
  stack<char> op;

  int n = s.length();

  // Parsing the input string
  for (int i = 0; i < n; i++)
  {
    // If the character is a digit
    if (isdigit(s[i]))
      val.push(to_string(s[i] - '0')); // Push the numeric value onto the value stack
    else
    {
      // Handle different cases for operators and parentheses
      if (op.empty())
        op.push(s[i]); // Push the operator onto the operator stack if it's empty
      else if (s[i] == '(')
        op.push(s[i]); // Push opening parenthesis onto the operator stack
      else if (op.top() == '(')
        op.push(s[i]); // Push operator onto the stack if the top is an opening parenthesis
      else if (s[i] == ')')
      {
        // Process the stack until an opening parenthesis is found
        while (op.top() != '(')
        {
          char ch = op.top();                 // Get the top operator
          op.pop();                           // Remove the top operator
          string val2 = val.top();            // Get the top value
          val.pop();                          // Remove the top value
          string val1 = val.top();            // Get the next top value
          val.pop();                          // Remove the next top value
          string ans = solve(val1, val2, ch); // Perform the operation
          val.push(ans);                      // Push the result back onto the value stack
        }
        op.pop(); // Pop the opening parenthesis
      }
      else if (prio(s[i]) > prio(op.top()))
        op.push(s[i]); // Push the operator onto the stack if it has higher precedence
      else
      {
        // Process operators with higher or equal precedence
        while (!op.empty() && prio(s[i]) <= prio(op.top()))
        {
          char ch = op.top();                 // Get the top operator
          op.pop();                           // Remove the top operator
          string val2 = val.top();            // Get the top value
          val.pop();                          // Remove the top value
          string val1 = val.top();            // Get the next top value
          val.pop();                          // Remove the next top value
          string ans = solve(val1, val2, ch); // Perform the operation
          val.push(ans);                      // Push the result back onto the value stack
        }
        op.push(s[i]); // Push the current operator onto the stack
      }
    }
  }

  // Process remaining operators in the stack
  while (!op.empty())
  {
    char ch = op.top();                 // Get the top operator
    op.pop();                           // Remove the top operator
    string val2 = val.top();            // Get the top value
    val.pop();                          // Remove the top value
    string val1 = val.top();            // Get the next top value
    val.pop();                          // Remove the next top value
    string ans = solve(val1, val2, ch); // Perform the operation
    val.push(ans);                      // Push the result back onto the value stack
  }

  // Output the final result
  cout << val.top() << endl; // Output the final result from the value stack

  return 0;
}
