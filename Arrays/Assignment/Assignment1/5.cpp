#include <iostream>
#include <vector>
using namespace std;

int findSmallestMissingPositive(vector<int> &nums)
{
  int n = nums.size();
  int expected = 1; // Start with the smallest positive integer

  for (int i = 0; i < n; ++i)
  {
    // Skip non-positive numbers and duplicates
    while (i < n && (nums[i] <= 0 || (i > 0 && nums[i] == nums[i - 1])))
    {
      ++i;
    }

    // Check if the current number equals the expected smallest positive integer
    if (i < n && nums[i] == expected)
    {
      ++expected; // Move to the next expected positive integer
    }
    else
    {
      break; // Found the smallest missing positive integer
    }
  }

  return expected;
}

int main()
{
  vector<int> nums1 = {1, 2, 3, 4, 5};          // No missing positive element
  vector<int> nums2 = {1, 2, 3, 5};             // Missing 4
  vector<int> nums3 = {1, 2, 3, 4, 4, 5};       // No missing positive element
  vector<int> nums4 = {2, 3, 6, 7, 8, 9};       // Missing 1
  vector<int> nums5 = {1, 1, 1, 2, 2, 3, 3, 5}; // Missing 4

  cout << "Smallest missing positive in nums1: " << findSmallestMissingPositive(nums1) << endl;
  cout << "Smallest missing positive in nums2: " << findSmallestMissingPositive(nums2) << endl;
  cout << "Smallest missing positive in nums3: " << findSmallestMissingPositive(nums3) << endl;
  cout << "Smallest missing positive in nums4: " << findSmallestMissingPositive(nums4) << endl;
  cout << "Smallest missing positive in nums5: " << findSmallestMissingPositive(nums5) << endl;

  return 0;
}
