#include <iostream>
using namespace std;

int main()
{
  int x1, y1, x2, y2, x3, y3;

  // Taking coordinates of the three points as input from the user
  cout << "Enter coordinates (x1 y1) of the first point: ";
  cin >> x1 >> y1;
  cout << "Enter coordinates (x2 y2) of the second point: ";
  cin >> x2 >> y2;
  cout << "Enter coordinates (x3 y3) of the third point: ";
  cin >> x3 >> y3;

  // Check if the points are collinear
  // Using the slope formula: (y2 - y1) / (x2 - x1) == (y3 - y1) / (x3 - x1)
  if ((y2 - y1) * (x3 - x1) == (y3 - y1) * (x2 - x1))
  {
    cout << "All 3 points lie on the same line." << endl;
  }
  else
  {
    cout << "The points do not lie on the same line." << endl;
  }

  return 0;
}
