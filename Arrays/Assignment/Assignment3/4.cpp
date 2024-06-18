#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool isSubset(const vector<int> &larger, const vector<int> &smaller)
{
  unordered_set<int> elements;

  // Insert all elements of the larger array into the unordered_set
  for (int elem : larger)
  {
    elements.insert(elem);
  }

  // Check if all elements of the smaller array are in the unordered_set
  for (int elem : smaller)
  {
    if (elements.find(elem) == elements.end())
    {
      return false;
    }
  }

  return true;
}

int main()
{
  vector<int> larger = {1, 2, 3, 4, 5, 6};
  vector<int> smaller = {2, 4, 6};

  if (isSubset(larger, smaller))
  {
    cout << "The second array is a subset of the first array." << endl;
  }
  else
  {
    cout << "The second array is NOT a subset of the first array." << endl;
  }

  return 0;
}
