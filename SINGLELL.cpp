#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};
node *head, *temp;

void createll()
{
    int choice = 1;
    head = 0;

    while (choice)
    {
        class node *newnode = new node;

        cout << "Enter data in NEWNODE:";
        cin >> newnode->data;
        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->next = 0;
            temp = newnode;
        }
        cout << "Do you want to continue(0,1)?";
        cin >> choice;
    }
}

void display()
{
    temp = head;
    while (temp != 0)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertatbeg()
{
    class node *newnode = new node;
    cout << "Enter data in newnode:";
    cin >> newnode->data;
    newnode->next = head;
    head = newnode;
}

void insertatend()
{
    class node *newnode = new node;
    cout << "Enter data that to be inserted at end:";
    cin >> newnode->data;
    temp = head;
    newnode->next = 0;
    while (temp->next != 0)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void insertatpos()
{
    int i = 1;
    int pos;
    cout << "Enter position to insert newnode:";
    cin >> pos;
    while (i < pos)
    {
        temp = temp->next;
        i++;
    }
    class node *newnode = new node;
    cout << "Enter data of newnode:";
    cin >> newnode->data;

    newnode->next = temp->next;
    temp->next = newnode;
}

void deletefrombeg()
{
    temp = head;
    head = temp->next;
    free(temp);
}

void deletefromend()
{
    class node *prevnode, *nextnode;
    nextnode = head;
    while (nextnode->next != 0)
    {
        prevnode = nextnode;
        nextnode = nextnode->next;
    }
    prevnode->next = 0;
    free(nextnode);
}

void deletefrompos()
{
    node *nextnode;
    int pos,i=1;
    temp=head;
    cout<<"Enter pos of node to be deleted:";
    cin>>pos;
    while(i<pos-1)
    {
        temp=temp->next;
        i++;


    }
    nextnode=temp->next;
    temp->next=nextnode->next;
    free(nextnode);
}

void reverse()
{
    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr;
    while (currptr != 0)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }
    head = prevptr;
}

int main()
{
    createll();
    display();
    insertatbeg();
    insertatend();
    //insertatpos();
    display();
    deletefrombeg();
    deletefromend();
    display();
    deletefrompos();
    display();
    reverse();
    display();
}