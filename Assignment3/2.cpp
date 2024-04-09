#include <bits/stdc++.h>
using namespace std;

void printIncreasingSequences(int curr, int n, int k, vector<int> ans)
{
  if (ans.size() == k)
  {
    // Print the sequence
    for (int i = 0; i < k; ++i)
    {
      cout << ans[i] << " ";
    }
    cout << endl;
    return;
  }

  for (int i = curr + 1; i <= n; ++i)
  {
    ans.push_back(i);
    printIncreasingSequences(i, n, k, ans);
    ans.pop_back();
  }
}

int main()
{
  int n, k;
  cin >> n >> k;

  vector<int> ans;
  printIncreasingSequences(0, n, k, ans);

  return 0;
}
