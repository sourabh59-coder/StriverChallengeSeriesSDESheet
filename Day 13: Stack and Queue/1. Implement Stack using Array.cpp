#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+10;
const int INF = 1e9+10;

class Stack
{
    public:
        int top;
        int arr[N];
        
        Stack()
        {
            top = -1;
        }
        
        Stack(int t)
        {
            top = t;
        }
        
        bool isEmpty()
        {
            return (top==-1);
        }
        
        bool isFull()
        {
            return (top>=N);
        }
        
        void push(int val)
        {
            if(isFull())
                cout<<"Stack overflow condition"<<endl;
            else
            {
                top++;
                arr[top] = val;
            }
        }
        
        void pop()
        {
            if(isEmpty())   
                cout<<"Stack underflow condition"<<endl;
            else
                top--;
        }
        
        int Top()
        {
            if(isEmpty()) 
            {
                cout<<"Stack underflow condition"<<endl;
                return -1;
            }
            else
            {
                int val = arr[top];
                return val;
            }
        }
        
        int Count()
        {
            return (top+1);
        }
        
        void Display()
        {
            if(isEmpty())   
                cout<<"Stack underflow condition"<<endl;
            else
            {
                while(top!=-1)
                {
                    cout<<arr[top]<<" ";
                    top--;
                }
            }
            cout<<endl;
        }
};

signed main()
{
    Stack st;
    
    cout<<st.isFull()<<endl;
    
    cout<<st.isEmpty()<<endl;
    
    st.push(25);
    st.push(45);
    st.push(89);
    
    cout<<st.Count()<<endl;
    
    st.Display();
    
    st.push(25);
    
    cout<<st.Top()<<endl;
    st.push(45);
    
    cout<<st.Top()<<endl;
    st.push(89);
    
    cout<<st.Top()<<endl;
    
    st.pop();
    
    cout<<st.Count()<<endl;
    
    st.Display();
    
    return 0;
}
