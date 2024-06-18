#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(vector<int> &arr)
{
  int n = arr.size();
  for (int i = 0; i < n / 2; ++i)
  {
    if (arr[i] != arr[n - i - 1])
    {
      return false; // Array is not a palindrome
    }
  }
  return true; // Array is a palindrome
}

int main()
{
  vector<int> arr1 = {1, 2, 3, 2, 1};    // Palindrome
  vector<int> arr2 = {1, 2, 3, 4, 5};    // Not a palindrome
  vector<int> arr3 = {1, 2, 3, 3, 2, 1}; // Palindrome

  cout << "arr1 is a palindrome: " << boolalpha << isPalindrome(arr1) << endl;
  cout << "arr2 is a palindrome: " << boolalpha << isPalindrome(arr2) << endl;
  cout << "arr3 is a palindrome: " << boolalpha << isPalindrome(arr3) << endl;

  return 0;
}
