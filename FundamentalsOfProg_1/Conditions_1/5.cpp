#include <iostream>
using namespace std;

int main()
{
  double side1, side2, side3;

  // Taking the lengths of the sides of the triangle as input from the user
  cout << "Enter the length of the first side: ";
  cin >> side1;
  cout << "Enter the length of the second side: ";
  cin >> side2;
  cout << "Enter the length of the third side: ";
  cin >> side3;

  // Checking if the triangle is equilateral
  if (side1 == side2 && side2 == side3)
  {
    cout << "This is an Equilateral triangle." << endl;
  }
  // Checking if the triangle is isosceles
  else if (side1 == side2 || side2 == side3 || side1 == side3)
  {
    cout << "This is an Isosceles triangle." << endl;
  }
  // If it's not equilateral or isosceles, then it must be scalene
  else
  {
    cout << "This is a Scalene triangle." << endl;
  }

  return 0;
}
