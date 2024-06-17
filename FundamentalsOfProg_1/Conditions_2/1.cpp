#include <iostream>
using namespace std;

int main()
{
  int amount;

  // Taking the amount as input from the user
  cout << "Enter the amount: ";
  cin >> amount;

  // Variables to store the count of each denomination
  int note500 = 0, note100 = 0, note50 = 0, note10 = 0;

  // Calculating the minimum number of notes
  while (amount > 0)
  {
    switch (amount)
    {
    case 500:
      note500++;
      amount -= 500;
      break;
    case 100:
      note100++;
      amount -= 100;
      break;
    case 50:
      note50++;
      amount -= 50;
      break;
    case 10:
      note10++;
      amount -= 10;
      break;
    default:
      // If amount doesn't match any case, break the loop
      amount = 0;
      break;
    }
  }

  // Outputting the count of each denomination
  if (note500 > 0)
  {
    cout << "notes of \"500\" = " << note500 << " ";
  }
  if (note100 > 0)
  {
    cout << "and notes of \"100\" = " << note100 << " ";
  }
  if (note50 > 0)
  {
    cout << "and notes of \"50\" = " << note50 << " ";
  }
  if (note10 > 0)
  {
    cout << "and notes of \"10\" = " << note10 << " ";
  }

  return 0;
}
