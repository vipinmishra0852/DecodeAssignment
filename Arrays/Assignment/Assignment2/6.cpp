#include <iostream>
#include <vector>
using namespace std;

int findUnique(vector<int> &nums)
{
  int uniqueNumber = 0;

  for (int num : nums)
  {
    uniqueNumber ^= num;
  }

  return uniqueNumber;
}

int main()
{
  vector<int> nums1 = {2, 1, 1, 3, 2};             // Unique number is 3
  vector<int> nums2 = {4, 3, 3, 2, 1, 4, 1, 2, 5}; // Unique number is 5
  vector<int> nums3 = {5, 7, 7, 8, 8};             // Unique number is 5

  cout << "Unique number in nums1: " << findUnique(nums1) << endl;
  cout << "Unique number in nums2: " << findUnique(nums2) << endl;
  cout << "Unique number in nums3: " << findUnique(nums3) << endl;

  return 0;
}
