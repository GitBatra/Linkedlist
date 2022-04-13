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

void detectloop()
{
    node *tortoise;
    node *rabbit;
    tortoise = rabbit = head;
    while (rabbit != 0 && rabbit->next != 0)
    {
        tortoise = tortoise->next;
        rabbit = rabbit->next->next;

        if (tortoise == rabbit)
        {
            cout << "LOOP IS DETECTED" << endl;
        }
        else
        {
            cout << "LOOP IS NOT DETECTED" << endl;
        }
    }
}

/*bool detectloop()
{
    if (!head)
        return false;
    else
    {
        node *tortoise = head;
        node *rabbit = head;

        while (rabbit != NULL and rabbit->next != NULL)
        {
            tortoise = tortoise->next;
            rabbit = rabbit->next->next;
            if (tortoise == rabbit)
            {
                return true;
            }
        }
        return false;
    }
}*/

int main()
{
    createll();
    display();
    detectloop();
}