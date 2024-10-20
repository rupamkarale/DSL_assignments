#include<iostream>
using namespace std;
class text
{
public:
string data;
text*next;
text*prev;
  text(string d)
  {
        data=d;
        next=NULL;
        prev=NULL;
      }
};
class linked
    {
    public:
    void insertstart(text* &head,string d)
       {
       
          text*n=new text(d);
          if(head==NULL)
          {
          head=n;
 }
 else
   {
    n->next=head;
    head->prev=n;
    head=n;
    }

         
}
void insertend(text* &head,string d)
       {
       
          text*n=new text(d);
          if(head==NULL)
          {
          head=n;
 }
 else
   {
    text*temp=head;
    while(temp->next!=NULL)
     {
      temp=temp->next;
 }
 n->prev=temp;
 temp->next=n;
    }

         
}
void insertbet(text* &head,string d)
       {
          string e;
           cout<<"Enter the string to insert :";
           cin>>e;
          text*n=new text(d);
          if(head==NULL)
          {
          head=n;
 }
 else
   {
    text*temp=head;
    while(temp->next->data!=d)
     {
      temp=temp->next;
 }
 n->prev=temp;
 n->next=temp->next;
 temp->next=n;
 temp->prev=n->next;
    }

         
}
     void deletestart(text* &head)
        {
       
        if(head==NULL)
          {
          return;
  }
else
  {
  text*todelete=head;
  head=head->next;
  head->prev=NULL;
  delete todelete;
  }
}
void deletbetween(text* &head,string d)
        {
           
        if(head==NULL)
          {
          cout<<"Empty list";
  }
else
  {
  text*temp=head;
  while(temp->next->data!=d)
   {
    temp=temp->next;
}
text* deletes = temp->next;
                    temp->next = deletes->next;
                    if (deletes->next != NULL) {
                       deletes->next->prev = temp;
                    }
       delete deletes;
  }
}
void deletend(text* &head)
        {
     
          if (head == NULL) {
   
              return;
            }
          if (head->next == NULL) {
               delete head;
               head = NULL;
                return;
            }
           text*temp = head;
         while (temp->next->next!=NULL) {
               temp = temp->next;
           }
        delete temp->next->next;
         temp->next = NULL;
         
}
void search(text*&head,string d)
    {
   
    if(head==NULL)
    {
    return;
}
else
 {
  text*temp=head;
  while(temp->next->data !=d)
  {
  temp=temp->next;
}
temp=temp->next;
if(temp->data==d)
  {
  cout<<"The text  is found ";
  }
else
  {
  cout<<"The text is not found";
  }
 }
}
void reverse(text*&head)
{
if(head==NULL)
  {
  return;
  }
else
{
 text*temp=head;
  while(temp->next!=NULL)
   {
    temp=temp->next;
}
head=temp;
while(temp->prev!=NULL)
{
cout<<temp->data;
temp=temp->prev;
}
cout<<temp->data;
}
}
   void display(text*head)
{
if(head==NULL)
{
cout<<"Empty list";

}
else
  {
  text*temp=head;
  while(temp!=NULL)
    {
    cout<<temp->data;
    temp=temp->next;
}
  }
}
};
int main()
  {
  text*head=NULL;
  linked a;
  string d;
  int n;
  int b;
  int f;
 
  while(b==0)
   {
  cout << "\n*press 1 to insert text at start ********\npress 2 to insert text at end\n*Press 3 to insert text in between\n**Press 4 to Delete text in between\npress 5 to Delete text at top\n*Press 6 to Delete the  at end\n**Press 7 search the element\n**Press 8 to insert text in between\n";
    cin >> n;
   if(n==1)
   {
    cout<<"Enter the no of string you wann enter :";
  cin>>f;
  for(int i=0;i<f;i++)
    {
    cout<<"Enter the string :";
    cin>>d;
    a.insertstart(head,d);
  }
a.display(head);
   }
   if(n==2)
    {
      cout<<"Enter the no of string you wann enter :";
     cin>>f;
   for(int i=0;i<f;i++)
      {
     cout<<"Enter the string :";
      cin>>d;
      a.insertend(head,d);
    }
 a.display(head);
    }
    if(n==3)
    {
   
  cout<<"Enter the no of string you wann enter :";
     cin>>f;
      for(int i=0;i<f;i++)
       {
      cout<<"Enter the string :";
       cin>>d;
       a.insertbet(head,d);
     }
a.display(head);
   }
   if(n==4)
   {
    cout<<"Enter the string you wan to delete :";
    a.deletbetween(head,d);
   }
   if(n==5)
    {
     a.deletestart(head);
     a.display(head);
    }
    if(n==6)
    {
      a.deletend(head);
      a.display(head);
    }
    if(n==7)
    {
    cout<<"Enter the string to find :";
    cin>>d;
    a.search(head,d);

}
if(n==8)
{
a.reverse(head);
}
cout<<"\nEnter 1 to stop and 0 to continue :";
cin>>b;
  }
  
  }