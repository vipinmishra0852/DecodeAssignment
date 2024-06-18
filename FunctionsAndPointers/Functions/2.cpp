#include <iostream>
#include <cmath> // for M_PI

using namespace std;

double calculateArea(double radius)
{
  // Area of a circle = π * radius^2
  return M_PI * radius * radius;
}

int main()
{
  double radius;
  cout << "Enter the radius of the circle: ";
  cin >> radius;

  double area = calculateArea(radius);
  cout << "The area of the circle with radius " << radius << " is " << area << endl;

  return 0;
}
