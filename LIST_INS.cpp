// class 12 goa board CS

#include <iostream>
using namespace std;

class LIST_INS
{
    struct node
    {
        int itemno;
        char name[30];
        node *link;
    } *start;

    int n;

public:
    LIST_INS()
    {
        start = NULL;
        n = 0;
    }

    void create(); 
    void insert();
    void display();
};

void LIST_INS::create()
{
    cout << "Enter the number of nodes to create: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        node *temp = new node;
        cout << "\nEnter item number: ";
        cin >> temp->itemno;
        cout << "Enter name: ";
        cin >> temp->name;
        temp->link = NULL;

        if (start == NULL)
            start = temp;
        else
        {
            node *curr = start;
            while (curr->link != NULL)
                curr = curr->link;
            curr->link = temp;
        }
    }

    cout << "\nLinked list created successfully!\n";
}


void LIST_INS::insert()
{
    int pos;
    node *avail, *temp;
    avail = new node;

    cout << "\nEnter the position of node: ";
    cin >> pos;

    if (pos < 1 || pos > n + 1)
    {
        cout << "\nInvalid position!";
        return;
    }
    cout << "\nEnter item number: ";
    cin >> avail->itemno;
    cout << "Enter name: ";
    cin >> avail->name;
    avail->link = NULL;

    if (pos == 1)
    {
        avail->link = start;
        start = avail;
    }
    else
    {
        temp = start;
        for (int i = 1; i <= pos - 2; i++)
            temp = temp->link;

        avail->link = temp->link;
        temp->link = avail;
    }

    n++;
    cout << "\nNode inserted successfully!";
}



void LIST_INS::display()
{
    node *curr = start;
    if (curr == NULL)
    {
        cout << "\nList is empty.";
        return;
    }

    cout << "\nCurrent Linked List:\n";
    while (curr != NULL)
    {
        cout << curr->itemno << " - " << curr->name << " -> ";
        curr = curr->link;
    }
    cout << "NULL\n";
}


int main()
{
    LIST_INS L;
    L.create();
    L.display();
    L.insert();
    L.display();
    return 0;
}
