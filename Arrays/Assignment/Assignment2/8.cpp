/*
Find the error.
double getAverage(int arr[], int size);
int main () {
int balance[5] = {1000, 2, 3, 17, 50};
double avg;
avg = getAverage( balance[0], 5 ) ;
cout << "Average value is: " << avg << endl;
return 0;
}
The error in your code is in the way you are passing the array balance to the getAverage function and how you are calling the function. Let's go through the issues and correct them:
*/

#include <iostream>
using namespace std;

// Function declaration
double getAverage(int arr[], int size);

int main()
{
  int balance[5] = {1000, 2, 3, 17, 50};
  double avg;

  // Correct way to call the function: pass the array name `balance`
  avg = getAverage(balance, 5);

  cout << "Average value is: " << avg << endl;
  return 0;
}

// Function definition
double getAverage(int arr[], int size)
{
  int sum = 0;
  for (int i = 0; i < size; i++)
  {
    sum += arr[i];
  }
  return static_cast<double>(sum) / size; // Calculate average and return as double
}
