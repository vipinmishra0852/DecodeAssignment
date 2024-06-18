#include <iostream>
#include <vector>
#include <climits> // for INT_MIN
using namespace std;

int findSecondLargest(vector<int> &nums)
{
  int n = nums.size();
  if (n < 2)
  {
    cerr << "Array should have at least two elements." << endl;
    return INT_MIN; // return minimum integer value in case of invalid input
  }

  int largest = nums[0];
  int secondLargest = INT_MIN;

  for (int i = 1; i < n; ++i)
  {
    if (nums[i] > largest)
    {
      secondLargest = largest;
      largest = nums[i];
    }
    else if (nums[i] > secondLargest && nums[i] != largest)
    {
      secondLargest = nums[i];
    }
  }

  return secondLargest;
}

int main()
{
  vector<int> nums = {3, 1, 4, 5, 2};

  int secondLargest = findSecondLargest(nums);

  if (secondLargest != INT_MIN)
  {
    cout << "Second largest element in the array is: " << secondLargest << endl;
  }

  return 0;
}
