#include <iostream>
using namespace std;

const int MAX_DIGITS = 5000; // Adjust based on the maximum factorial digits needed

void factorial(int n)
{
  int result[MAX_DIGITS];

  // Initialize result array with 1 (factorial of 1 is 1)
  result[0] = 1;
  int result_size = 1;

  // Perform multiplication like you would by hand
  for (int i = 2; i <= n; ++i)
  {
    int carry = 0;
    for (int j = 0; j < result_size; ++j)
    {
      int product = result[j] * i + carry;
      result[j] = product % 10; // Store the last digit of product
      carry = product / 10;     // Update carry for next iteration
    }

    while (carry)
    {
      result[result_size] = carry % 10;
      carry = carry / 10;
      result_size++;
    }
  }

  // Print the factorial in reverse order
  cout << "Factorial of " << n << " is:\n";
  for (int k = result_size - 1; k >= 0; k--)
  {
    cout << result[k];
  }
  cout << endl;
}

int main()
{
  int n;
  cout << "Enter a number to compute its factorial: ";
  cin >> n;

  factorial(n);

  return 0;
}
