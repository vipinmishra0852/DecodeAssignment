#include <iostream>
#include <vector>
using namespace std;

int findDifference(vector<int> &nums)
{
  int sumEven = 0;
  int sumOdd = 0;

  for (int i = 0; i < nums.size(); ++i)
  {
    if (i % 2 == 0)
    {
      // Even index
      sumEven += nums[i];
    }
    else
    {
      // Odd index
      sumOdd += nums[i];
    }
  }

  return sumEven - sumOdd;
}

int main()
{
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  int difference = findDifference(nums);

  cout << "Difference between sum of elements at even indices and sum of elements at odd indices: " << difference << endl;

  return 0;
}
