#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+10;
const int INF = 1e9+10;

class Queue
{
    public:
        int front;
        int rear;
        int arr[N];
        int cnt;
        
        Queue()
        {
            front = -1;
            rear = -1;
            cnt = 0;
        }
        
        Queue()
        {
            front = -1;
            rear = -1;
            cnt = 0;
        }
        
        bool isEmpty()
        {
            return (front==-1 && rear==-1);
        }
        
        bool isFull()
        {
            return (rear==N-1);
        }
        
        void Push()
        {
            if (isFull()) {
              cout << "Queue full" << endl;
              return;
            } else if (isEmpty()) {
              rear = 0;
              front = 0;
              arr[rear] = val;
            } else {
              rear++;
              arr[rear] = val;
            }
        }
        
        void Pop()
        {
            int x = 0;
            if (isEmpty()) {
              cout << "Queue is Empty" << endl;
              return x;
            } else if (rear == front) {
              x = arr[rear];
              rear = -1;
              front = -1;
              return x;
            } else {
              cout << "front value: " << front << endl;
              x = arr[front];
              arr[front] = 0;
              front++;
              return x;
            }
        }
        
        int Count()
        {
            return cnt;
        }
        
        void Display()
        {
            if(isEmpty())
            {
                cout<<"Queue is empty"<<endl;
            }
            else
            {
                for(int i=front;i>=rear;i--)
                {
                    cout<<arr[i]<<" ";
                }
                cout<<endl;
            }
        }
};
