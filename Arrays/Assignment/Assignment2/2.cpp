#include <iostream>
#include <vector>
#include <algorithm>     // for sort
#include <bits/stdc++.h> // for sort
using namespace std;

void findLargestThree(vector<int> &nums)
{
  int n = nums.size();
  if (n < 3)
  {
    cout << "Array should have at least three elements." << endl;
    return;
  }

  int first = INT_MIN;
  int second = INT_MIN;
  int third = INT_MIN;

  for (int i = 0; i < n; ++i)
  {
    if (nums[i] > first)
    {
      third = second;
      second = first;
      first = nums[i];
    }
    else if (nums[i] > second && nums[i] != first)
    {
      third = second;
      second = nums[i];
    }
    else if (nums[i] > third && nums[i] != second && nums[i] != first)
    {
      third = nums[i];
    }
  }

  cout << "Largest three elements in the array are: " << first << ", " << second << ", " << third << endl;
}

int main()
{
  vector<int> nums = {3, 1, 4, 5, 2, 9, 7, 6, 8};

  findLargestThree(nums);

  return 0;
}
