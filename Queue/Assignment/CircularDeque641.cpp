#include <iostream>
#include <vector>
using namespace std;

class MyCircularDeque
{
public:
  vector<int> dq;
  int f = -1;
  int r = -1;
  int curr = 0;
  int size = 0;

  MyCircularDeque(int k)
  {
    dq.resize(k);
    size = k;
  }

  bool insertFront(int value)
  {
    if (isFull())
      return false;
    if (isEmpty())
    {
      f = r = 0;
    }
    else if (f == 0)
    {
      f = size - 1;
    }
    else
    {
      f--;
    }
    dq[f] = value;
    curr++;
    return true;
  }

  bool insertLast(int value)
  {
    if (isFull())
      return false;
    if (isEmpty())
    {
      f = r = 0;
    }
    else if (r == size - 1)
    {
      r = 0;
    }
    else
    {
      r++;
    }
    dq[r] = value;
    curr++;
    return true;
  }

  bool deleteFront()
  {
    if (isEmpty())
      return false;
    if (f == r)
    {
      f = r = -1;
    }
    else if (f == size - 1)
    {
      f = 0;
    }
    else
    {
      f++;
    }
    curr--;
    return true;
  }

  bool deleteLast()
  {
    if (isEmpty())
      return false;
    if (f == r)
    {
      f = r = -1;
    }
    else if (r == 0)
    {
      r = size - 1;
    }
    else
    {
      r--;
    }
    curr--;
    return true;
  }

  int getFront()
  {
    if (isEmpty())
      return -1;
    return dq[f];
  }

  int getRear()
  {
    if (isEmpty())
      return -1;
    return dq[r];
  }

  bool isEmpty()
  {
    return curr == 0;
  }

  bool isFull()
  {
    return curr == size;
  }
};

int main()
{
  MyCircularDeque *obj = new MyCircularDeque(3);
  cout << boolalpha;

  // Test insertLast
  cout << "Insert 1 at last: " << obj->insertLast(1) << endl;
  cout << "Insert 2 at last: " << obj->insertLast(2) << endl;
  cout << "Insert 3 at last: " << obj->insertLast(3) << endl;
  cout << "Insert 4 at last (should fail): " << obj->insertLast(4) << endl;

  // Test getRear
  cout << "Get rear element: " << obj->getRear() << endl;

  // Test isFull
  cout << "Is deque full: " << obj->isFull() << endl;

  // Test deleteLast
  cout << "Delete last element: " << obj->deleteLast() << endl;
  cout << "Get rear element after deleteLast: " << obj->getRear() << endl;

  // Test insertFront
  cout << "Insert 4 at front: " << obj->insertFront(4) << endl;
  cout << "Get front element: " << obj->getFront() << endl;

  // Test deleteFront
  cout << "Delete front element: " << obj->deleteFront() << endl;
  cout << "Get front element after deleteFront: " << obj->getFront() << endl;

  // Test isEmpty
  cout << "Is deque empty: " << obj->isEmpty() << endl;

  delete obj;
  return 0;
}
