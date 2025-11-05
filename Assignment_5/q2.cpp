#include<iostream>
using namespace std;

class Node{
   public:
   int data;
   Node *next;
   Node(int v){
      data=v;
      next=NULL;
   }
};

Node* insertEnd(Node *head,int val){
   Node *n=new Node(val);
   if(head==NULL) return n;
   Node *t=head;
   while(t->next!=NULL) t=t->next;
   t->next=n;
   return head;
}

int deleteAll(Node* &head,int key){
   int c=0;
   while(head!=NULL && head->data==key){
      Node *d=head;
      head=head->next;
      delete d;
      c++;
   }
   Node *t=head;
   while(t!=NULL && t->next!=NULL){
      if(t->next->data==key){
         Node *d=t->next;
         t->next=t->next->next;
         delete d;
         c++;
      } else t=t->next;
   }
   return c;
}

void display(Node *head){
   if(head==NULL){ cout<<"List empty"; return; }
   Node *t=head;
   while(t){
      cout<<t->data;
      if(t->next) cout<<"->";
      t=t->next;
   }
   cout<<endl;
}

int main(){
   Node *head=NULL;
   int n,x,key;
   cout<<"How many nodes: "; cin>>n;
   for(int i=0;i<n;i++){
      cin>>x;
      head=insertEnd(head,x);
   }
   cout<<"Enter key: "; cin>>key;
   int cnt=deleteAll(head,key);
   cout<<"Count: "<<cnt<<" , Updated Linked List: ";
   display(head);
}