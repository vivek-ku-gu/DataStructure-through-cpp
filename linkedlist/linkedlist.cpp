#include<iostream>
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
// insertion of data at the tail in a linked list
void insertAtTail(node* &head,int val){
    node* n = new node(val); 
    node* temp = head;
if(head == NULL){
  head= n;
  return;
}
else
while(temp->next != NULL)
{
    temp = temp->next;
}
temp -> next =n;
}
// insert the node at the begining
void insertAtHead(node* &head,int val)
{
    node* n = new node(val);
    n->next= head;
    head=n;
}

// display the nodes of the linked list
void display(node* head)
{
    node*temp = head;
while(temp->next != NULL){
    cout<<"->"<< temp->data;
    temp=temp->next;
}
    cout<<"->"<<temp->data<<endl;
}
// delete a node from the begining
void deleteNodeAtBeg(node* &head)
{
if(head==NULL)
{cout<<"there is no data to delete";
    return;}
    else{
            node* todelete = head;
    head = head-> next;
    delete todelete;
    return;
    }
}
//delete any node
void deleteNode(node* &head,int val){
if(head==NULL || head->next==NULL){
    deleteNodeAtBeg(head); 
    return;
}
  else{
        node* temp;
  temp = head;
while((temp -> next -> data )!= val)
{
  temp = temp -> next;
}
node* todelete;
todelete= temp->next;
temp->next = temp->next->next;
delete todelete;
  }
}
// reverse a linked list using iterative method
node* reverselist(node* head)
{
    node* prevptr;node* curptr;node* nextptr;
prevptr = NULL;
curptr= head;
while(curptr != NULL)
{
    nextptr = curptr-> next;
   curptr-> next = prevptr;
   prevptr = curptr;
    curptr= nextptr;
}
return prevptr;
}
void makecycle(node* &head,int pos){
    node* temp= head;
    node* startnode;
    int count =1;
while(temp -> next != NULL)
{
    if(count== pos)
{
    startnode= temp;
}
    temp = temp->next;
    count++;
}
  temp->next= startnode;
}
int detectcycle(node* &head)
{
    node* slow=head;
    node* fast=head;
    while(fast!=NULL && fast->next !=NULL){
    slow=slow->next;
    fast= fast->next->next;
    if(slow == fast)
    {
        return 1;
    }
    }
    return 0;
}
void removecycle(node* &head)
{
     node* slow=head;
    node* fast=head;
    do
    {
      slow=slow-> next;
      fast= fast-> next ->next;
    } while (fast!=slow);
   
    while(fast->next!= slow->next)
    {
        fast= fast->next;
        slow=slow->next;
    }
    slow->next =  NULL;
}
int lengthofll(node* &head){
    int l =1;
    node* temp = head;
    while(temp->next!= NULL)
    {
        temp= temp->next;
        l++;
    }
    return l;
}
node* kappend(node* &head,int k)
{ node* tail= head;
  node* newtail;
  node* newhead;
  int l = lengthofll(head);
 
    int count=1;
     k=k%l;
    while(tail->next!=NULL)
    {
       
     if(count==l-k)
     {
         newtail= tail;
     }
      if(count==l-k+1)
     {
         newhead= tail;
     }
     tail= tail->next;
     count++;
    }
    newtail->next=NULL;
    tail->next=head;
    return newhead;
}
node* mergeSorted(node* &head1,node* &head2)
{
    node* p1=head1;
    node* p2= head2;
    node* p3= new node(-1);
    node* toreturn = p3;
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->data >p2->data){
            p3->next=p2;
            p2=p2->next;
        }
        else{
            p3->next = p1;
            p1= p1->next;
        }
        p3= p3->next;
    }
    while (p1!=NULL)
    {
        p3->next=p1;
        p1=p1->next;
        p3= p3->next;
    }
    while (p2!=NULL)
    {
        p3->next=p2;
        p2=p2->next;
        p3= p3->next;
    }
    return toreturn->next;
}
int main()
{
    node* head = NULL;  
    node* head1 = NULL;  
    node* head2 = NULL;  

// insertAtHead(head, 1);
// insertAtHead(head, 2);
// insertAtHead(head, 3);
// insertAtHead(head, 4);
// insertAtTail(head,0);
// deleteNodeAtBeg(head);
// deleteNode(head,2);
// display(head);
// node* a=reverselist(head);
// display(a);
// makecycle(head,2);
// removecycle(head);
// display(head);
// int a =lengthofll(head);
// cout<<a;
// node* temp= kappend(head,3);
// display(temp);
int arr1[]={1,2,5};
int arr2[]={3,4,6};
for(int i=0;i<3;i++)
{
    insertAtTail(head1,arr1[i]);
}
for(int i=0;i<3;i++)
{
    insertAtTail(head2,arr2[i]);
}
display(head1);
display(head2);
node* head3=mergeSorted(head1,head2);
display(head3);
} 












