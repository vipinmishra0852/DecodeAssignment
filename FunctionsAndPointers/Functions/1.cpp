#include <iostream>
using namespace std;

void printSquares(int n)
{
  for (int i = 1; i <= n; ++i)
  {
    cout << i << "^2 = " << i * i << endl;
  }
}

int main()
{
  int n;
  cout << "Enter the value of n: ";
  cin >> n;
  printSquares(n);
  return 0;
}
