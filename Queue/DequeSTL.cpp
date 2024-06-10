#include <iostream>
#include <deque>

using namespace std;

int main()
{
  // Create a deque of integers
  deque<int> dq;

  // Insert elements at the back
  dq.push_back(1);
  dq.push_back(2);
  dq.push_back(3);

  // Insert elements at the front
  dq.push_front(0);
  dq.push_front(-1);

  // Display the elements of the deque
  cout << "Deque elements: ";
  for (int elem : dq)
  {
    cout << elem << " ";
  }
  cout << endl;

  // Access elements using indexing
  cout << "Element at index 2: " << dq[2] << endl;

  // Remove elements from the front
  dq.pop_front();
  cout << "After pop_front, first element: " << dq.front() << endl;

  // Remove elements from the back
  dq.pop_back();
  cout << "After pop_back, last element: " << dq.back() << endl;

  // Insert elements at specific positions
  auto it = dq.begin();
  dq.insert(it + 1, 99); // Insert 99 at the second position

  // Display the modified deque
  cout << "Deque after insertion: ";
  for (int elem : dq)
  {
    cout << elem << " ";
  }
  cout << endl;

  // Erase elements at specific positions
  dq.erase(dq.begin() + 1); // Erase the element at the second position

  // Display the deque after erasure
  cout << "Deque after erasure: ";
  for (int elem : dq)
  {
    cout << elem << " ";
  }
  cout << endl;

  return 0;
}
