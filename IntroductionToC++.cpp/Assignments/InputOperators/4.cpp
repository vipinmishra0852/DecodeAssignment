#include <iostream>
using namespace std;

// Function to calculate the volume of a cylinder
double calculateVolume(double radius, double height)
{
  const double PI = 3.14159265358979323846;
  return PI * radius * radius * height;
}

int main()
{
  double radius, height;

  // Taking radius and height as input from the user
  cout << "Enter the radius of the cylinder: ";
  cin >> radius;
  cout << "Enter the height of the cylinder: ";
  cin >> height;

  // Calculating the volume
  double volume = calculateVolume(radius, height);

  // Displaying the result
  cout << "The volume of the cylinder is: " << volume << endl;

  return 0;
}
