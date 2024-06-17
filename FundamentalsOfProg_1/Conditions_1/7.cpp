#include <iostream>
using namespace std;

int main()
{
  int x, y;

  // Taking coordinates (x, y) of the point as input from the user
  cout << "Enter the coordinates (x y) of the point: ";
  cin >> x >> y;

  // Checking the position of the point
  if (x == 0 && y == 0)
  {
    cout << "The point lies at the origin." << endl;
  }
  else if (x == 0)
  {
    cout << "The point lies on the y-axis." << endl;
  }
  else if (y == 0)
  {
    cout << "The point lies on the x-axis." << endl;
  }
  else
  {
    cout << "The point does not lie on the x-axis, y-axis, or at the origin." << endl;
  }

  return 0;
}
