#include <iostream>
using namespace std;

int main()
{
  int marksA, marksB, marksC;

  // Taking the marks of students A, B, and C as input from the user
  cout << "Enter the marks of student A: ";
  cin >> marksA;
  cout << "Enter the marks of student B: ";
  cin >> marksB;
  cout << "Enter the marks of student C: ";
  cin >> marksC;

  // Finding the student with the least marks
  if (marksA <= marksB && marksA <= marksC)
  {
    cout << "'A' has the least marks." << endl;
  }
  else if (marksB <= marksA && marksB <= marksC)
  {
    cout << "'B' has the least marks." << endl;
  }
  else
  {
    cout << "'C' has the least marks." << endl;
  }

  return 0;
}
