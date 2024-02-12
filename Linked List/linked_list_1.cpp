#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
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

void createTail(Node *head, Node *&tail)
{
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
    }
    tail = temp;
}

void insertAtHead(Node *&head, Node *&tail, int data)
{
    // new node
    Node *temp = new Node(data);
    // when LL is empty -> head & tail both are null
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        // temp->next point to first dabba
        temp->next = head;
        // update head to point temp
        head = temp;
    }

    // now temp node has become first node of LL
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

void insertAtPosition(Node *&head, Node *&tail, int data, int pos)
{
    int length = countLL(head);
    if (pos > length)
    {
        cout << "Invalid position" << endl;
        return;
    }
    Node *newNode = new Node(data);
    // pos = 0 -> at head
    if (pos == 0)
    {
        insertAtHead(head, tail, data);
    }
    else
    {
        Node *prev = NULL;
        Node *curr = head;
        while (pos > 0)
        {
            prev = curr;
            curr = curr->next;
            pos--;
        }
        newNode->next = curr;
        prev->next = newNode;
    }
}

void deleteNode(Node *&head, Node *&tail, int pos)
{
    int length = countLL(head);
    if (head == NULL)
    {
        cout << "can't delete empty list" << endl;
        return;
    }
    else if (pos == 0 || pos > length)
    {
        cout << "Invalid position" << endl;
        return;
    }

    // single node remained
    if (head == tail)
    {
        Node *temp = head;
        delete temp;
        head = tail = NULL;
    }

    if (pos == 1)
    {
        // delete head
        Node *temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else if (pos == length)
    {
        // delete tail
        Node *curr = head;
        while (curr->next != tail)
        {
            curr = curr->next;
        }
        curr->next = NULL;
        delete tail;
        tail = curr;
    }
    else
    {
        // delete at middle
        Node *prev = NULL;
        Node *curr = head;
        while (pos != 1)
        {
            prev = curr;
            curr = curr->next;
            pos--;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    // Creation of node
    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    printingLL(head);
    deleteNode(head, tail, 5);
    printingLL(head);

    return 0;
}