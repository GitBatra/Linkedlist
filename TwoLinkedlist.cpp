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
node *head1 = NULL;
node *head2 = NULL;

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

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int length(node *head)
{
    int l = 0;
    node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        l++;
    }
    return l;
}

int intersection(node *head1, node *head2)
{
    int l1 = length(head1);
    int l2 = length(head2);

    int d = 0;
    node *ptr1;
    node *ptr2;
    if (l1 > l2)
    {
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else

    {
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }
    while (d)
    {
        ptr1 = ptr1->next;
        if (ptr1 == NULL)
        {
            return -1;
        }
        d--;
    }
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->data == ptr2->data)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}

int main()
{
    insertAtTail(head1, 1);
    insertAtTail(head1, 2);
    insertAtTail(head1, 3);
    insertAtTail(head1, 4);
    insertAtTail(head1, 5);
    insertAtTail(head1, 6);
    insertAtTail(head2, 9);
    insertAtTail(head2, 10);
    insertAtTail(head2, 5);
    insertAtTail(head2, 6);
    display(head1);
    display(head2);

    cout << length(head1) << endl;
    cout << length(head2) << endl;
    cout << intersection(head1, head2) << endl;

    return 0;
}