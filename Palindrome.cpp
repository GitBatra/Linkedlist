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
node *head = 0;
node *temp;

void insertNode(int val)
{
    class node *newnode = new node(val);
    if (head == NULL)
    {
        head = temp = newnode;
    }
    else
    {
        temp->next = newnode;
        temp = newnode;
    }
}

void display()
{
    temp = head;
    while (temp != 0)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

node *reverse(node *head)
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
    return prevptr;
}

bool Palindrome(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }
    node *slow = head;
    node *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = reverse(slow->next);
    slow = slow->next;
    while (slow != NULL)
    {
        if (head->data != slow->data)
        {
            return false;
        }
        head = head->next;
        slow = slow->next;
    }
    return true;
}

int main()
{
    insertNode(1);
    insertNode(2);
    insertNode(3);
    insertNode(3);
    insertNode(2);
    insertNode(1);
    display();
    cout << Palindrome(head);
    reverse();
    display();
}