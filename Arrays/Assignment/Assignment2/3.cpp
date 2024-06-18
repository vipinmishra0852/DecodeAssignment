#include <iostream>
#include <vector>
using namespace std;

bool isSorted(vector<int> &nums)
{
  int n = nums.size();

  for (int i = 0; i < n - 1; ++i)
  {
    if (nums[i] > nums[i + 1])
    {
      return false; // Array is not sorted
    }
  }

  return true; // Array is sorted
}

int main()
{
  vector<int> nums1 = {1, 2, 3, 4, 5}; // Sorted
  vector<int> nums2 = {1, 3, 2, 4, 5}; // Not sorted
  vector<int> nums3 = {5, 4, 3, 2, 1}; // Sorted in descending order

  cout << "nums1 is sorted: " << boolalpha << isSorted(nums1) << endl;
  cout << "nums2 is sorted: " << boolalpha << isSorted(nums2) << endl;
  cout << "nums3 is sorted: " << boolalpha << isSorted(nums3) << endl;

  return 0;
}
