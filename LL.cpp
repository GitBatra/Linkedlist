#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};
node *head = NULL;

void insertAtTail(node *&head, int val)
{
    node *temp = head;
    node *newnode = new node(val);
    if (head == NULL)
    {
        head = temp = newnode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void insertAtHead(node *&head, int val)
{
    node *newnode = new node(val);
    newnode->next = head;
    head = newnode;
}

void display()
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

bool search(node *&head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void deletell()
{
    node *temp = head;
    node *nextptr;
    int i = 1, pos;
    cout << "Enter position of NODE to be deleted:";
    cin >> pos;
    if (pos == i)
    {
        nextptr = head;
        head = head->next;
        free(nextptr);
        i++;
    }

    while (i < pos - 1)
    {

        {
            temp = temp->next;
            i++;
        }

        nextptr = temp->next;
        temp->next = nextptr->next;
        free(nextptr);
    }
}

int main()
{
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    display();
    deletell();
    display();

    //insertAtHead(head,4);
    //display(head);
    //cout<<search(head,7)<<endl;
}
