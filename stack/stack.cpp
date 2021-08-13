#include<iostream>
using namespace std;
#define  n 5
class stack
{
   int top;
   int* arr;
public:
    stack()
    {
    arr = new int [n];
    top =-1;
    }
    void push(int val)
    {
if(top==n-1)
{cout<<"stack is full"<<endl;
return;}
top++;
arr[top]=val;
    }
 void pop()
 {
if(top==-1)
{cout<<"stack is empty deletion not posible"<<endl;}
top--;
 }
 bool empty()
 {
     return top==-1;
 }
 void Top()
 {
     if(top==-1)
     {cout<<"stack is empty"<<endl;return;}
     cout<<arr[top]<<endl; 
 }
};
int main()
{
   stack st;
   st.push(3);
      st.Top();
    st.push(5);
       st.Top();
     st.push(6);
        st.Top();
      st.push(4);
     
    
      st.Top();
      
      st.pop();
      cout<<st.empty()<<endl;


}

