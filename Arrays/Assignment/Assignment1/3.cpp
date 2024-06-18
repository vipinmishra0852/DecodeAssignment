#include <iostream>
#include <vector>
#include <climits> // for INT_MAX
using namespace std;

int findMinimum(vector<int> &nums)
{
  int n = nums.size();
  if (n == 0)
  {
    cerr << "Array is empty." << endl;
    return INT_MAX; // return maximum integer value in case of empty array
  }

  int minVal = nums[0];

  for (int i = 1; i < n; ++i)
  {
    if (nums[i] < minVal)
    {
      minVal = nums[i];
    }
  }

  return minVal;
}

int main()
{
  vector<int> nums = {3, 1, 4, 5, 2};

  int minValue = findMinimum(nums);

  cout << "Minimum value in the array is: " << minValue << endl;

  return 0;
}
