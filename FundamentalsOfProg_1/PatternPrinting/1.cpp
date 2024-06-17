#include <iostream>
using namespace std;

int main()
{
  // Define the number of rows and columns
  int rows = 4;
  int columns = 4;

  // Iterate through each row
  for (int i = 1; i <= rows; ++i)
  {
    // Print the number 'i' 'columns' times
    for (int j = 1; j <= columns; ++j)
    {
      cout << i << " ";
    }
    // Move to the next line after each row
    cout << endl;
  }

  return 0;
}
