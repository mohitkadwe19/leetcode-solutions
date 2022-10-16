#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue
{
public:
  int *arr;
  int front;
  int rear;
  int size;
  MyCircularQueue(int k)
  {
    size = k;
    arr = new int[k];
    front = -1;
    rear = -1;
  }

  bool enQueue(int value)
  {
    if (isFull())
      return false;
    if (isEmpty())
      front = 0;
    rear = (rear + 1) % size;
    arr[rear] = value;
    return true;
  }

  bool deQueue()
  {
    if (isEmpty())
      return false;
    if (front == rear)
    {
      front = -1;
      rear = -1;
      return true;
    }
    front = (front + 1) % size;
    return true;
  }

  int Front()
  {
    if (isEmpty())
      return -1;
    return arr[front];
  }

  int Rear()
  {
    if (isEmpty())
      return -1;
    return arr[rear];
  }

  bool isEmpty()
  {
    return front == -1;
  }

  bool isFull()
  {
    return ((rear + 1) % size) == front;
  }
};

int main()
{
  MyCircularQueue *obj = new MyCircularQueue(3);
  bool param_1 = obj->enQueue(1);
  bool param_2 = obj->deQueue();
  int param_3 = obj->Front();
  int param_4 = obj->Rear();
  bool param_5 = obj->isEmpty();
  bool param_6 = obj->isFull();
  cout << param_1 << " " << param_2 << " " << param_3 << " " << param_4 << " " << param_5 << " " << param_6 << endl;
  return 0;
}