#include <iostream>
#include <vector>

using namespace std;

class MyCircularQueue
{
public:
  int f; // front
  int b; // back/rear
  int s; // current size
  int c; // capacity
  vector<int> arr;

  MyCircularQueue(int k)
  {
    f = 0;
    b = 0;
    s = 0;
    c = k;
    vector<int> v(k);
    arr = v;
  }

  bool enQueue(int value)
  {
    if (s == c)
      return false;
    arr[b] = value;
    b = (b + 1) % c;
    s++;
    return true;
  }

  bool deQueue()
  {
    if (s == 0)
      return false;
    f = (f + 1) % c;
    s--;
    return true;
  }

  int Front()
  {
    if (s == 0)
      return -1;
    return arr[f];
  }

  int Rear()
  {
    if (s == 0)
      return -1;
    return arr[(b - 1 + c) % c];
  }

  bool isEmpty()
  {
    return s == 0;
  }

  bool isFull()
  {
    return s == c;
  }
};

int main()
{
  MyCircularQueue *obj = new MyCircularQueue(3);

  // Testing enQueue
  cout << "Enqueue 1: " << (obj->enQueue(1) ? "True" : "False") << endl;
  cout << "Enqueue 2: " << (obj->enQueue(2) ? "True" : "False") << endl;
  cout << "Enqueue 3: " << (obj->enQueue(3) ? "True" : "False") << endl;
  cout << "Enqueue 4: " << (obj->enQueue(4) ? "True" : "False") << endl; // This should fail since the queue is full

  // Testing Front and Rear
  cout << "Front: " << obj->Front() << endl;
  cout << "Rear: " << obj->Rear() << endl;

  // Testing isEmpty and isFull
  cout << "Is Empty: " << (obj->isEmpty() ? "True" : "False") << endl;
  cout << "Is Full: " << (obj->isFull() ? "True" : "False") << endl;

  // Testing deQueue
  cout << "Dequeue: " << (obj->deQueue() ? "True" : "False") << endl;

  // Testing Front and Rear again after dequeue
  cout << "Front after dequeue: " << obj->Front() << endl;
  cout << "Rear after dequeue: " << obj->Rear() << endl;

  // Clean up
  delete obj;

  return 0;
}
