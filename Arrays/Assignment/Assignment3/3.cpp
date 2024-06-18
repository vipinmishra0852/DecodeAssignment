#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findFirstNonRepeatingElement(const vector<int> &arr)
{
  unordered_map<int, int> frequency;

  // Count the frequency of each element in the array
  for (int num : arr)
  {
    frequency[num]++;
  }

  // Find the first element with a frequency of 1
  for (int num : arr)
  {
    if (frequency[num] == 1)
    {
      return num;
    }
  }

  // If no non-repeating element is found
  return -1; // You can return any sentinel value indicating no non-repeating element
}

int main()
{
  vector<int> arr = {4, 5, 1, 2, 0, 4};

  int result = findFirstNonRepeatingElement(arr);

  if (result != -1)
  {
    cout << "The first non-repeating element is: " << result << endl;
  }
  else
  {
    cout << "There is no non-repeating element in the array." << endl;
  }

  return 0;
}
