#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countTriplets(vector<int> &arr, int x)
{
  int n = arr.size();
  sort(arr.begin(), arr.end());
  int count = 0;

  for (int i = 0; i < n - 2; ++i)
  {
    int left = i + 1;
    int right = n - 1;

    while (left < right)
    {
      int sum = arr[i] + arr[left] + arr[right];
      if (sum == x)
      {
        count++;
        left++;
        right--;
        // Skip duplicates
        while (left < right && arr[left] == arr[left - 1])
          left++;
        while (left < right && arr[right] == arr[right + 1])
          right--;
      }
      else if (sum < x)
      {
        left++;
      }
      else
      {
        right--;
      }
    }

    // Skip duplicates for i
    while (i < n - 2 && arr[i] == arr[i + 1])
      i++;
  }

  return count;
}

int main()
{
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int x = 15;

  int result = countTriplets(arr, x);
  cout << "Number of triplets with sum " << x << ": " << result << endl;

  return 0;
}
