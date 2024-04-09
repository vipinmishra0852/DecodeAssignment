#include <iostream>
#include <vector>
using namespace std;

void generateAlternateArrays(const vector<int> &A, const vector<int> &B)
{
  int idxA = 0, idxB = 0;
  while (idxB < B.size())
  {
    vector<int> current;
    // Start with an element from A
    current.push_back(A[idxA]);
    ++idxA;
    // Continue with an element from B
    current.push_back(B[idxB]);
    ++idxB;
    // Add remaining elements from A until the end of B
    while (idxB < B.size() && idxA < A.size() && A[idxA] < B[idxB])
    {
      current.push_back(A[idxA]);
      ++idxA;
    }
    // Print the generated array
    for (int num : current)
    {
      cout << num << " ";
    }
    cout << endl;
  }
}

int main()
{
  vector<int> A = {10, 15, 25};
  vector<int> B = {1, 5, 20, 30};

  generateAlternateArrays(A, B);

  return 0;
}
