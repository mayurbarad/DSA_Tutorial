#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node()
    {
        this->next = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->next = NULL;
    }
    ~Node()
    {
        cout << "dtor called for " << this->data << endl;
    }
};

void printingLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

int countLL(Node *head)
{
    Node *temp = head;
    int cnt = 0;

    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void insertAtHead(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void insertAtPosition(Node *&head, Node *&tail, int data, int pos)
{
    int length = countLL(head);
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        if (pos > length)
        {
            cout << "Invalid Position" << endl;
            return;
        }
        else if (pos == 0)
        {
            insertAtHead(head, tail, data);
        }
        else if (pos == length)
        {
            insertAtTail(head, tail, data);
        }
        else
        {
            Node *newNode = new Node(data);
            Node *prevNode = NULL;
            Node *currNode = head;
            while (pos != 0)
            {
                prevNode = currNode;
                currNode = currNode->next;
                pos--;
            }
            prevNode->next = newNode;
            newNode->prev = prevNode;
            newNode->next = currNode;
            currNode->prev = newNode;
        }
    }
}

void deleteNode(Node *&head, Node *&tail, int pos)
{
    if (head == NULL)
    {
        cout << "can't delete empty DLL" << endl;
        return;
    }

    if (head == tail)
    {
        Node *temp = head;
        head = tail = NULL;
        delete temp;
    }
    int length = countLL(head);
    if (pos == 1)
    {
        // delete from head
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    else if (pos == length)
    {
        // delete from tail
        Node *currNode = tail->prev;
        currNode->next = NULL;
        tail->prev = NULL;
        delete tail;
        tail = currNode;
    }
    else
    {
        // delete from position
        Node *prevNode = NULL;
        Node *currNode = head;
        while (pos != 1)
        {
            prevNode = currNode;
            currNode = currNode->next;
            pos--;
        }
        Node *nextNode = currNode->next;

        prevNode->next = nextNode;
        currNode->prev = NULL;
        currNode->next = NULL;
        nextNode->prev = prevNode;
        delete currNode;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);

    return 0;
}