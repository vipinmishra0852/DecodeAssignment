#include <iostream>
#include <vector>
#include <algorithm> // for sort
using namespace std;

bool containsDuplicates(vector<int> &nums)
{
  // Sort the array
  sort(nums.begin(), nums.end());

  // Check for duplicates
  for (int i = 1; i < nums.size(); ++i)
  {
    if (nums[i] == nums[i - 1])
    {
      return true; // Found duplicates
    }
  }

  return false; // No duplicates found
}

int main()
{
  vector<int> nums1 = {1, 2, 3, 4, 5};    // No duplicates
  vector<int> nums2 = {1, 2, 3, 4, 5, 1}; // Duplicates: 1
  vector<int> nums3 = {3, 1, 4, 1, 5, 9}; // Duplicates: 1

  cout << "nums1 contains duplicates: " << boolalpha << containsDuplicates(nums1) << endl;
  cout << "nums2 contains duplicates: " << boolalpha << containsDuplicates(nums2) << endl;
  cout << "nums3 contains duplicates: " << boolalpha << containsDuplicates(nums3) << endl;

  return 0;
}
