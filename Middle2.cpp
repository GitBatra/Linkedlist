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
class node *head = NULL;
class node *temp;

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

int MiddleNode()
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

void DeleteNthNode()
{
    int i = 1, pos;
    cout << "Enter position:";
    cin >> pos;
    node *temp = head;
    node *slow = head;
    node *fast = head;
    while (i != pos + 1)
    {
        fast = fast->next;
        i++;
    }
    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
}

int main()
{
    insertNode(3);
    insertNode(4);
    insertNode(1);
    insertNode(3);
    insertNode(5);
    insertNode(6);
    display();
    //cout << MiddleNode() << endl;
    DeleteNthNode();
    display();
}