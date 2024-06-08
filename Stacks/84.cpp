#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int largestRectangleArea(vector<int> &heights)
  {
    int n = heights.size();
    if (n == 0)
      return 0;

    vector<int> nsi(n);
    vector<int> psi(n);
    stack<int> st;

    nsi[n - 1] = n;
    st.push(n - 1);
    for (int i = n - 2; i >= 0; i--)
    {
      while (!st.empty() && heights[st.top()] >= heights[i])
        st.pop();
      if (st.empty())
        nsi[i] = n;
      else
        nsi[i] = st.top();
      st.push(i);
    }

    while (!st.empty())
      st.pop();

    psi[0] = -1;
    st.push(0);
    for (int i = 1; i < n; i++)
    {
      while (!st.empty() && heights[st.top()] >= heights[i])
        st.pop();
      if (st.empty())
        psi[i] = -1;
      else
        psi[i] = st.top();
      st.push(i);
    }

    int maxArea = 0;

    for (int i = 0; i < n; i++)
    {
      int height = heights[i];
      int breadth = nsi[i] - psi[i] - 1;
      int area = height * breadth;
      maxArea = max(maxArea, area);
    }

    return maxArea;
  }
};

int main()
{
  vector<int> heights = {2, 1, 5, 6, 2, 3};
  Solution s;
  cout << s.largestRectangleArea(heights);
  return 0;
}