#include <iostream>
#include <vector>
using namespace std;

int countElementsGreaterThan(vector<int> &nums, int x)
{
  int count = 0;

  for (int num : nums)
  {
    if (num > x)
    {
      count++;
    }
  }

  return count;
}

int main()
{
  vector<int> nums = {1, 3, 5, 7, 9, 2, 4, 6, 8};

  int x = 5;
  int count = countElementsGreaterThan(nums, x);

  cout << "Number of elements greater than " << x << ": " << count << endl;

  return 0;
}
