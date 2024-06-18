#include <iostream>
#include <vector>
using namespace std;

void modifyArray(vector<int> &nums)
{
  int n = nums.size();

  for (int i = 0; i < n; ++i)
  {
    if (i % 2 == 0)
    {
      // Even index: increment by 10
      nums[i] += 10;
    }
    else
    {
      // Odd index: multiply by 2
      nums[i] *= 2;
    }
  }
}

int main()
{
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  cout << "Original array:" << endl;
  for (int num : nums)
  {
    cout << num << " ";
  }
  cout << endl;

  modifyArray(nums);

  cout << "Modified array:" << endl;
  for (int num : nums)
  {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
