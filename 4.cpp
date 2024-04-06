#include <iostream>
#include <vector>
using namespace std;

void printSum(vector<int> &v)
{
  if (v.size() == 1)
  {
    cout << v[0] << endl;
    return;
  }

  for (int i = 0; i < v.size(); ++i)
  {
    cout << v[i];
    if (i < v.size() - 1)
    {
      cout << " ";
    }
  }
  cout << endl;

  vector<int> temp;
  for (int i = 0; i < v.size() - 1; ++i)
  {
    temp.push_back(v[i] + v[i + 1]);
  }
  printSum(temp);
}

int main()
{
  vector<int> v = {5, 4, 3, 2, 1};
  printSum(v);

  return 0;
}
