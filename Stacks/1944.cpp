#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
  vector<int> canSeePersonsCount(vector<int> &heights)
  {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n = heights.size();
    vector<int> ans(n, 0);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
      int count = 0;
      while (!st.empty() && st.top() < heights[i])
      {
        st.pop();
        count++;
      }
      if (!st.empty())
        count++;
      ans[i] = count;
      st.push(heights[i]);
    }

    return ans;
  }
};

int main()
{
  Solution solution;
  vector<int> heights = {10, 6, 8, 5, 11, 9};

  vector<int> result = solution.canSeePersonsCount(heights);

  for (int count : result)
  {
    cout << count << " ";
  }

  return 0;
}
