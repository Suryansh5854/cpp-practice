#include <iostream>
using namespace std;

class node
{
public:
    node *pre;
    int data;
    node *next;

    node(int d)
    {
        this->pre = NULL;
        this->data = d;
        this->next = NULL;
    }
};

void insertathead(node *&head, int d)
{
    if (head == NULL)
    {
        node *temp = new node(d);
        head = temp;
    }
    else
    {
        node *temp = new node(d);
        temp->next = head;
        head->pre = temp;
        head = temp;
    }
}

void insertatttail(node *&head, int d)
{
    if (head == NULL)
    {
        node *temp = new node(d);
        head = temp;
    }
    else
    {
        node *pos = head;
        while (pos->next != NULL)
        {
            pos = pos->next;
        }
        node *temp = new node(d);
        pos->next = temp;
        temp->pre = pos;
    }
}

void insertatposition(node *&head, int position, int d)
{
    node *pos = head;
    for (int i = 1; i < position - 1; i++)
    {
        pos = pos->next;
    }

    if (position == 1)
    {
        insertathead(head, d);
        return;
    }
    if (pos->next == NULL)
    {
        insertatttail(head, d);
        return;
    }
    node *temp = new node(d);
    temp->next = pos->next;
    temp->next->pre = temp;
    pos->next = temp;
    temp->pre = pos;
}

void display(node *&head)
{
    node *dis = head;
    while (dis != NULL)
    {
        cout << dis->data << " ";
        dis = dis->next;
    }
    cout << endl;
}

void deletenode(node *&head, int position)
{
    if (head == NULL)
    {
        cout << "THERE IS NOT ANY LINKED LIST TO DELETE";
        return;
    }
    if (position == 1)
    {
        node *temp = head;
        temp->next->pre = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        node *curr = head;
        node *prev = NULL;

        for (int i = 1; i < position; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        if (curr->next == NULL)
        {
            prev->next = curr->next;
            curr->pre = NULL;
            curr->next = NULL;
            delete curr;
        }
        else
        {
            curr->next->pre = curr->pre;
            prev->next = curr->next;
            curr->pre = NULL;
            curr->next = NULL;
            delete curr;
        }
    }
}

int main()
{
    // node*head = NULL;
    node *head = new node(8);
    insertatttail(head, 10);
    insertatttail(head, 11);
    insertathead(head, 7);
    insertathead(head, 6);
    insertatposition(head, 5, 69);
    display(head);
    deletenode(head, 6);
    display(head);
    return 0;
}
