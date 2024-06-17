#include <iostream>
using namespace std;

int main()
{
  int n;

  // Prompt user to enter the number of terms
  cout << "Enter the number of terms (n): ";
  cin >> n;

  // Initialize variables for the AP
  int firstTerm = 4;
  int commonDifference = 3;
  int term = firstTerm;

  // Display the AP up to n terms
  cout << "Arithmetic Progression (AP) with " << n << " terms:" << endl;
  for (int i = 0; i < n; ++i)
  {
    cout << term;
    if (i != n - 1)
    {
      cout << ", ";
    }
    term += commonDifference;
  }
  cout << endl;

  return 0;
}