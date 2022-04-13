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
node *temp;

void createLL(node *&head, int val)
{
    node *newnode = new node(val);
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
void display(node *head)
{
    temp = head;
    while (temp != 0)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int length(node *head)
{
    temp = head;
    int l = 0;
    while (temp != 0)
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
    if (l2 > l1)
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
    while (ptr1 != 0 && ptr2 != 0)
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
    createLL(head1, 1);
    createLL(head1, 4);
    createLL(head1, 6);
    createLL(head1, 7);
    createLL(head1, 8);
    createLL(head1, 9);
    createLL(head2, 2);
    createLL(head2, 3);
    createLL(head2, 4);
    createLL(head2, 5);
    createLL(head2, 6);
    display(head1);
    display(head2);
    cout << intersection(head1, head2) << endl;
}