#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int largestRectangleArea(vector<int> &arr)
  {
    int n = arr.size();
    vector<int> nsi(n);
    stack<int> st;
    nsi[n - 1] = n;
    st.push(n - 1);

    for (int i = n - 2; i >= 0; i--)
    {
      while (!st.empty() && arr[st.top()] >= arr[i])
        st.pop();
      if (st.empty())
        nsi[i] = n;
      else
        nsi[i] = st.top();
      st.push(i);
    }

    vector<int> psi(n);
    stack<int> gt;
    psi[0] = -1;
    gt.push(0);
    for (int i = 1; i < n; i++)
    {
      while (!gt.empty() && arr[gt.top()] >= arr[i])
        gt.pop();
      if (gt.empty())
        psi[i] = -1;
      else
        psi[i] = gt.top();
      gt.push(i);
    }

    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
      int height = arr[i];
      int breadth = nsi[i] - psi[i] - 1;
      int area = height * breadth;
      maxArea = max(maxArea, area);
    }
    return maxArea;
  }

  int maximalRectangle(vector<vector<char>> &a)
  {
    int n = a.size();
    if (n == 0)
      return 0;
    int m = a[0].size();
    vector<int> row(m, 0);
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (a[i][j] == '1')
          row[j] += 1;
        else
          row[j] = 0;
      }
      maxArea = max(maxArea, largestRectangleArea(row));
    }
    return maxArea;
  }
};

// Example usage
int main()
{
  Solution sol;
  vector<vector<char>> matrix = {
      {'1', '0', '1', '0', '0'},
      {'1', '0', '1', '1', '1'},
      {'1', '1', '1', '1', '1'},
      {'1', '0', '0', '1', '0'}};

  int result = sol.maximalRectangle(matrix);
  cout << "Maximum rectangle area: " << result << endl;
  return 0;
}
