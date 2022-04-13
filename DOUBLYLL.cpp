#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
};
node *head, *temp;

void createdll()
{
    int choice = 1;
    head = 0;
    while (choice)
    {
        node *newnode = new node;
        cout << "Enter data:";
        cin >> newnode->data;
        newnode->next = 0;
        newnode->prev = 0;
        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
        cout << "Do you want to continue(0,1)";
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

void insertAtBeg()
{

    node *newnode = new node;
    cout << "Enter data to be inserted in beginning:";
    cin >> newnode->data;

    newnode->next = head;
    newnode->prev = NULL;
    head->prev = newnode;
    head = newnode;
}

void insertAtEnd()
{
    node *newnode = new node;
    cout << "Enter data to be inserted at end:";
    cin >> newnode->data;

    temp = head;
    while (temp->next != 0)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    newnode->next = NULL;
}

int main()
{
    createdll();
    display();
    insertAtBeg();
    insertAtEnd();
    display();
}