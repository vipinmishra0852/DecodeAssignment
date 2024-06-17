#include <iostream>
using namespace std;

int main()
{
  int n;
  cout << "Enter the number of rows (half the height of the diamond, excluding the middle line): ";
  cin >> n;

  int totalRows = 2 * n + 1;

  for (int i = 0; i < totalRows; ++i)
  {
    int numStars, numSpaces;

    if (i < n)
    {
      numStars = i + 1;
      numSpaces = n - i - 1;
    }
    else if (i == n)
    {
      numStars = totalRows;
      numSpaces = 0;
    }
    else
    {
      numStars = totalRows - i;
      numSpaces = i - n;
    }

    for (int j = 0; j < numSpaces; ++j)
    {
      cout << " ";
    }

    for (int j = 0; j < numStars; ++j)
    {
      cout << "*";
      if (j != numStars - 1)
      {
        int middleSpaces = (i == n) ? 0 : (numSpaces * 2 - 1);
        for (int k = 0; k < middleSpaces; ++k)
        {
          cout << " ";
        }
      }
    }

    cout << endl;
  }

  return 0;
}
