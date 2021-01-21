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

void insertAttail(int val, node *&head)
{

    node *add = new node(val);

    if (head == NULL)
    {
        head = add;
        return;
    }

    node *temp = head;

    while (temp->next)
    {
        temp = temp->next;
    }

    temp->next = add;
}

void display(node *temp)
{

    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    node *head =NULL;
    // inserting elements
    insertAttail(6, head);
    insertAttail(7, head);
    insertAttail(8, head);
    cout << "Current Linked List: ";
    display(head);
}