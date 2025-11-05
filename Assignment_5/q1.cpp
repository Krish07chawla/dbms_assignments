#include<iostream>
using namespace std;

class Node{
   public:
   int data;
   Node *next;
   Node(int val){
      data=val;
      next=NULL;
   }
};

class List{
   Node *head;
   public:
   List(){
      head=NULL;
   }

   void insertBeg(int val){
      Node *n = new Node(val);
      n->next=head;
      head=n;
   }

   void insertEnd(int val){
      Node *n=new Node(val);
      if(head==NULL){ head=n; return;}
      Node *temp=head;
      while(temp->next!=NULL) temp=temp->next;
      temp->next=n;
   }

   void insertBefore(int x,int y){
      if(head==NULL) return;
      if(head->data==y){
         insertBeg(x);
         return;
      }
      Node *temp=head;
      while(temp->next!=NULL && temp->next->data!=y)
         temp=temp->next;
      if(temp->next==NULL) return;
      Node *n=new Node(x);
      n->next=temp->next;
      temp->next=n;
   }

   void insertAfter(int x,int y){
      Node *temp=head;
      while(temp!=NULL && temp->data!=y)
         temp=temp->next;
      if(temp==NULL) return;
      Node *n=new Node(x);
      n->next=temp->next;
      temp->next=n;
   }

   void delBeg(){
      if(head==NULL) return;
      Node *temp=head;
      head=head->next;
      delete temp;
   }

   void delEnd(){
      if(head==NULL) return;
      if(head->next==NULL){ delete head; head=NULL; return;}
      Node *temp=head;
      while(temp->next->next!=NULL)
         temp=temp->next;
      delete temp->next;
      temp->next=NULL;
   }

   void delVal(int x){
      if(head==NULL) return;
      if(head->data==x){ delBeg(); return;}
      Node *temp=head;
      while(temp->next!=NULL && temp->next->data!=x)
         temp=temp->next;
      if(temp->next==NULL) return;
      Node *d=temp->next;
      temp->next=temp->next->next;
      delete d;
   }

   void searchNode(int x){
      Node *temp=head;
      int pos=1;
      while(temp!=NULL){
         if(temp->data==x){
            cout<<"Node found at position "<<pos<<endl;
            return;
         }
         pos++;
         temp=temp->next;
      }
      cout<<"Node not found"<<endl;
   }

   void display(){
      Node *temp=head;
      if(temp==NULL){ cout<<"List is empty"<<endl; return;}
      cout<<"List: ";
      while(temp!=NULL){
         cout<<temp->data<<" ";
         temp=temp->next;
      }
      cout<<endl;
   }
};


int main(){
   List l;
   int ch, val, x, y;
   while(true){
      cout<<"\n1.Insert Beg\n2.Insert End\n3.Insert Before\n4.Insert After\n5.Del Beg\n6.Del End\n7.Del Specific\n8.Search\n9.Display\n10.Exit\n";
      cout<<"Enter choice: ";
      cin>>ch;
      switch(ch){
         case 1: cout<<"Value: "; cin>>val; l.insertBeg(val); break;
         case 2: cout<<"Value: "; cin>>val; l.insertEnd(val); break;
         case 3: cout<<"Value to insert: "; cin>>x; cout<<"Before which value: "; cin>>y; l.insertBefore(x,y); break;
         case 4: cout<<"Value to insert: "; cin>>x; cout<<"After which value: "; cin>>y; l.insertAfter(x,y); break;
         case 5: l.delBeg(); break;
         case 6: l.delEnd(); break;
         case 7: cout<<"Value to delete: "; cin>>x; l.delVal(x); break;
         case 8: cout<<"Value to search: "; cin>>x; l.searchNode(x); break;
         case 9: l.display(); break;
         case 10: return 0;
         default: cout<<"Invalid\n";
      }
   }
}