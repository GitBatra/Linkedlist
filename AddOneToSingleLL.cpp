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
        node *newnode = new node;
        cout << "Enter data:";
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
        cout << "Do you want to continue:";
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

node *addone()
{
    node *currptr = head;
    while (currptr != NULL)
    {
        if (currptr->data == 9)
        {
            currptr->data = 0;
            currptr = currptr->next;
        }
        else if (currptr->data != 9)
        {
            currptr->data = currptr->data + 1;
            break;
        }
    }
}

void removeduplicate()
{
    temp = head;
    while (temp != 0)
    {
        if (temp->data == temp->next->data)
        {
            temp->next = temp->next->next;
            temp = temp->next;
        }
        else
        {
            temp = temp->next;
        }
    }
}

int main()
{
    createll();
    display();
    reverse();
    display();
    addone();
    reverse();
    removeduplicate();
    display();
}