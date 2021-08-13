#include<bits/stdc++.h>
using namespace std;
class node{
    public:
int data;
node* next;
node(int val)
{
    data=val;
    next= NULL;
}
};
void insertAtHead(node* &head,int val)
{
      node* n= new node(val);
      if(head==NULL)
      {head=n;
      n->next=head;
      return;
    }
    node* temp = head;
    while(temp->next != head)
        {
            temp= temp->next;
        }
       n->next=head;
       head=n;
    temp->next=head;
}
void insertAtTail(node* &head,int val)
{
    if(head==NULL)
    {
        insertAtHead(head,val);
        return;
    }
    node* n= new node(val);
    node* temp= head; 
    while(temp->next!=head)
    {
        temp= temp->next;
    }
    temp->next=n;
    n->next= head;
}
void display(node* &head)
{node* temp= head;
   do
   {
       cout<<temp->data<<"->";
        temp = temp->next;
   } while (temp != head);
} 
int main()
{
    node* head = NULL;
    insertAtTail(head,3);
    insertAtTail(head,5);
    insertAtTail(head,6);
    insertAtTail(head,1);
    insertAtTail(head,8);
    insertAtHead(head,4);
    display(head);
}