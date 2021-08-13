#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        node* prev;
        node* next;
        int data;
    node(int val){
    prev=NULL;
    next=NULL;
    data=val;
    }
};
    void insertAtHead(node* &head,int val){
         node* temp = head;
         node* n= new node(val);
         if(head!=NULL){
         n->next= head;
         head->prev= n;
         }
         head= n;
         
    }
    void insertAtTail(node* &head, int val)
    {
        if(head==NULL)
        {
            insertAtHead(head,val);

            return;
        }
        node* temp = head;
        while (temp->next != NULL)
        {
            temp= temp->next;
        }
         node* n= new node(val);
         temp->next= n;
         n->prev= temp;   
    }
    void deleteAtHead(node* &head){
     node* todelete = head;
          head =head->next;
          head->prev = NULL;
          delete todelete;
    }
    void deleteAtPos(node* &head,int pos)
    {
        if(pos==1)
        {
            deleteAtHead(head);
            return;
        }
     node*temp= head;
     int count=1;
     while (temp->next!=NULL && count!=pos)
     {
         temp= temp->next;
         count++;
     }
     if(temp->next!=NULL){
         
         temp->next->prev = temp->prev;
     }
     temp->prev->next = temp->next;   
     delete temp; 
    }
    void display(node* &head)
    {
        node* temp= head;
        while(temp->next!=NULL){
            cout<<temp->data<<"->";
            temp= temp->next;
        }
         cout<<temp->data<<"->"<<endl;
    }
int main()
{
    node* head= NULL;
    insertAtTail(head,6);
    insertAtHead(head,2);
    insertAtHead(head,5);
    insertAtHead(head,8);
    insertAtHead(head,9);
    display(head);
    deleteAtPos(head,1);
    display(head);
}