#include <iostream>
using namespace std;

// Function with no parameters
void display()
{
  cout << "Display with no parameters" << endl;
}

// Function with one int parameter
void display(int a)
{
  cout << "Display with one int parameter: " << a << endl;
}

// Function with one double parameter
void display(double a)
{
  cout << "Display with one double parameter: " << a << endl;
}

// Function with two int parameters
void display(int a, int b)
{
  cout << "Display with two int parameters: " << a << ", " << b << endl;
}

int main()
{
  display();      // Calls the function with no parameters
  display(5);     // Calls the function with one int parameter
  display(3.14);  // Calls the function with one double parameter
  display(7, 10); // Calls the function with two int parameters
  return 0;
}
