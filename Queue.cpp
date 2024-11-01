#include <iostream>
using namespace std;

class Queue 
{
    int* arr;      
    int capacity;   
    int front;      
    int rear;       
    int count;    

public:

    Queue(int size = 4) 
    {
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }

    ~Queue() 
    {
        delete[] arr;
    }

    void push(int item) 
    {
        if (count == capacity) 
        {
            resize();
        }
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        count++;
    }

    void pop() 
    {
        if (isEmpty()) 
        {
            cout << "Queue empty\n";
            return;
        }
        front = (front + 1) % capacity;
        count--;
    }

    int top() const 
    {
        if (isEmpty()) 
        {
            cout << "Queue empty\n";
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() const 
    {
        return count == 0;
    }

private:
    void resize() 
    {
        int newCapacity = capacity * 2;
        int* newArr = new int[newCapacity];

        for (int i = 0; i < count; i++) 
        {
            newArr[i] = arr[(front + i) % capacity];
        }

        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
        front = 0;
        rear = count - 1;
    }
};

int main() 
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout << "First element: " << q.top() << "\n";
    q.pop();
    cout << "First element after remove: " << q.top() << "\n";
}