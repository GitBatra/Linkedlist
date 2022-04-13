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

void middlelement()
{
    temp = head;
    int count = 0, i;
    while (temp != 0)
    {
        count++;
        temp = temp->next;
    }
    cout << "Length of linkedlist :" << count << endl;
    temp = head;
    for (i = 1; i <= (count / 2); i++)
    {

        temp = temp->next;
    }
    cout << "MIDDLE ELEMENT IS " << temp->data << endl;
}

int main()
{
    createll();
    display();
    middlelement();
}