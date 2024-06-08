#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
  vector<int> finalPrices(vector<int> &arr)
  {
    int n = arr.size();
    vector<int> ans(n, 0);
    ans[n - 1] = arr[n - 1];
    stack<int> st;
    st.push(arr[n - 1]);

    for (int i = n - 2; i >= 0; i--)
    {
      while (st.size() > 0 && st.top() > arr[i])
      {
        st.pop();
      }
      if (st.size() == 0)
      {
        ans[i] = arr[i];
      }
      else
      {
        ans[i] = arr[i] - st.top();
      }
      st.push(arr[i]);
    }
    return ans;
  }
};

int main()
{
  // Example input
  vector<int> prices = {8, 4, 6, 2, 3};

  // Create an instance of the Solution class
  Solution solution;

  // Call the finalPrices method
  vector<int> final_prices = solution.finalPrices(prices);

  // Print the output
  for (int price : final_prices)
  {
    cout << price << " ";
  }
  cout << endl;

  return 0;
}
