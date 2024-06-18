// Q->1A function may be called more than once from any other function
#include <iostream>
using namespace std;
void second()
{
  cout << "Kya haal  chal " << endl;
  cout << "Arre main hu second function jo tumne nhi printMessage ne call kiya hai" << endl;
}
void printMessage()
{
  cout << "Hello, World!" << endl;
  second();
}

int main()
{
  printMessage(); // First call
                  //  Q-->2 ka answer -> it is not necessary to return any value from a function (ex->void funtion)
  return 0;
}
