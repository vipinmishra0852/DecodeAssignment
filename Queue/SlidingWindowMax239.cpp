#include <iostream>
#include <vector>
#include <deque>

using namespace std;

// Solution class containing the maxSlidingWindow method
class Solution
{
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k)
  {
    if (k == 1)
      return nums; // If k is 1, the maximum of each window is the element itself

    deque<int> dq;   // Deque to store indices of potential maximum values
    vector<int> ans; // Vector to store the result

    int n = nums.size(); // Size of the input array

    for (int i = 0; i < n; i++)
    {
      // Remove elements from the back of the deque that are smaller than the current element
      // since they cannot be the maximum in the current window
      while (!dq.empty() && nums[i] > nums[dq.back()])
        dq.pop_back();

      // Add the current element index to the deque
      dq.push_back(i);

      // Calculate the start of the current window
      int j = i - (k - 1);

      // Remove the front element from the deque if it is out of the bounds of the current window
      while (!dq.empty() && dq.front() < j)
        dq.pop_front();

      // Add the maximum element of the current window to the result
      if (i >= k - 1)
        ans.push_back(nums[dq.front()]);
    }

    return ans;
  }
};

int main()
{
  Solution solution;

  // Sample input
  vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  int k = 3;

  // Call the maxSlidingWindow method
  vector<int> result = solution.maxSlidingWindow(nums, k);

  // Print the result
  cout << "The maximum values in each sliding window are: ";
  for (int val : result)
  {
    cout << val << " ";
  }
  cout << endl;

  return 0;
}
