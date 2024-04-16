#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node*next;

    node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    ~node(){
        int value = this->data;
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"memory is free for node with data : "<<value<<endl;
    }
};

void insertathead(node *&head, int d)
{
    node *temp = new node(d);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}

void insertattail(node *&head, int d)
{
    node *temp = new node(d);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        node *point = head;
        while (point->next != NULL)
        {
            point = point->next;
        }
        point->next = temp;
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
        insertattail(head, d);
        return;
    }
    node *temp = new node(d);
    temp->next = pos->next;
    pos->next = temp;
}

void deletenode(node *&head, int position)
{
    node *del = head;
    if(del == NULL){
        cout<<"THERE IS NOT SINGLE NODE IN YOUR LINKED LIST"<<endl;
        return;
    }
    if (position == 1)
    {
        head = head->next;
        del->next = NULL;
        delete del;
    }else{
        node*pre = NULL;
        node*curr = head;

        for(int i=1;i<position;i++){
            pre = curr;
            curr = curr->next;
        }

        pre->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // node*head= NULL;
    node *head = new node(10);
    insertathead(head, 4);
    insertathead(head, 6);

    insertatposition(head, 3, 5);
    deletenode(head,3);

    display(head);
    return 0;
}