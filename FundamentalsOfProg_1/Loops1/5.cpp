#include <iostream>
using namespace std;

int main()
{
  int n;

  // Prompt user to enter the number of terms
  cout << "Enter the number of terms (n): ";
  cin >> n;

  // Initialize variables for the GP
  int firstTerm = 3;
  int commonRatio = 4;
  int term = firstTerm;

  // Display the GP up to n terms
  cout << "Geometric Progression (GP) with " << n << " terms:" << endl;
  for (int i = 0; i < n; ++i)
  {
    cout << term;
    if (i != n - 1)
    {
      cout << ", ";
    }
    term *= commonRatio; // Multiply the current term by the common ratio to get the next term
  }
  cout << endl;

  return 0;
}