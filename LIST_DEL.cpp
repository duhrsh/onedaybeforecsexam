// class 12 goa board CS

#include <iostream>
using namespace std;

class LIST_DEL
{
    struct node
    {
        int itemno;
        char name[30];
        node *link;
    } *start;

    int n;

public:
    LIST_DEL()
    {
        start = NULL;
        n = 0;
    }

    void create(); 
    void remove();
    void display();
};

void LIST_DEL::create()
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


void LIST_DEL::remove()
{
    int p;
    cout << "\nEnter position to delete: ";
    cin >> p;

    if (p < 1 || p > n)
    {
        cout << "\nInvalid Position!";
        return;
    }
    
    node *temp = start;
        if (p == 1)
        {
            start = start->link;
            delete temp;
        }
        else
        {
            for (int i = 1; i <= p-2; i++)
                temp = temp->link;

        node *last = temp->link;
        temp->link = last->link;
        delete last;

        }
        
        n--;
        cout << "\nNode deleted successfully!";

}


void LIST_DEL::display()
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
    LIST_DEL L;
    L.create();
    L.display();
    L.remove();
    L.display();
    return 0;
}
