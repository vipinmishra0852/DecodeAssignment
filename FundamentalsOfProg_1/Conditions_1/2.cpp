#include <iostream>
using namespace std;

int main()
{
  const double PI = 3.14159265358979323846;
  double radius;

  // Taking the radius of the circle as input from the user
  cout << "Enter the radius of the circle: ";
  cin >> radius;

  // Calculating the area of the circle
  double area = PI * radius * radius;

  // Calculating the circumference of the circle
  double circumference = 2 * PI * radius;

  // Comparing the area and the circumference
  if (area > circumference)
  {
    cout << "Area is greater than circumference." << endl;
  }
  else
  {
    cout << "Circumference is greater than or equal to area." << endl;
  }

  return 0;
}
