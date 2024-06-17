#include <iostream>
using namespace std;

int main()
{
  double length, breadth;

  // Taking the length and breadth of the rectangle as input from the user
  cout << "Enter the length of the rectangle: ";
  cin >> length;
  cout << "Enter the breadth of the rectangle: ";
  cin >> breadth;

  // Calculating the area of the rectangle
  double area = length * breadth;

  // Calculating the perimeter of the rectangle
  double perimeter = 2 * (length + breadth);

  // Comparing the area and the perimeter
  if (area > perimeter)
  {
    cout << "Area is greater than perimeter." << endl;
  }
  else
  {
    cout << "Perimeter is greater than or equal to area." << endl;
  }

  return 0;
}
