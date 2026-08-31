#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *next;
};

void InsertAtBeginning(Node *&Head, int value)
{
    Node *NewNode = new Node();
    NewNode->value = value;
    NewNode->next = Head;
    Head = NewNode;
}

Node *Find(Node *Head, int value)
{
    while (Head != NULL)
    {
        if (Head->value == value)
        {
            return Head;
        }
        Head = Head->next;
    }
    return NULL;
}

void InsertAfter(Node *prevNode, int value)
{
    Node *newNode = new Node();
    newNode->value = value;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void InsertAtEnd(Node *&Head, int value)
{
    Node *newNode = new Node();
    newNode->value = value;
    newNode->next = NULL;

    if (Head == NULL)
    {
        Head = newNode;
    }
    else
    {
        Node *LastNode = Head;
        while (LastNode->next != NULL)
        {
            LastNode = LastNode->next;
        }
        LastNode->next = newNode;
    }
}

void DeleteNode(Node *&Head, int value)
{
    Node *DeletedNode = Head;
    if (Head == NULL)
        return;

    if (Head->value == value)
    {
        Head = Head->next;
        delete DeletedNode;
        return;
    }
    Node *PrevNode = Head;
    while (DeletedNode != NULL && DeletedNode->value != value)
    {
        PrevNode = DeletedNode;
        DeletedNode = DeletedNode->next;
    }

    if (DeletedNode != NULL)
    {
        PrevNode->next = DeletedNode->next;
        delete DeletedNode;
    }
}

void DeleteFirstNode(Node *&Head)
{
    if (Head == NULL)
        return;
    Node *DeletedNode = Head;
    Head = Head->next;
    delete DeletedNode;
}

void DeleteLastNode(Node *&Head)
{
    if (Head == NULL)
        return;
    Node *DeletedNode = Head;
    if (Head->next == NULL)
    {
        Head = NULL;
        delete DeletedNode;
        return;
    }
    Node *PrevNode = Head;
    while (DeletedNode->next != NULL)
    {
        PrevNode = DeletedNode;
        DeletedNode = DeletedNode->next;
    }
    PrevNode->next = NULL;
    delete DeletedNode;
}

void PrintList(Node *head)

{
    while (head != NULL)
    {
        cout << head->value << " ";
        head = head->next;
    }
}

int main()
{
    // 1. Create an empty list
    Node *Head = NULL;
    cout << "--- Linked List Testing Code ---\n\n";

    // 2. Test InsertAtBeginning
    cout << "\n\nInserting elements at beginning (10, then 20, then 30): ";
    InsertAtBeginning(Head, 10);
    InsertAtBeginning(Head, 20);
    InsertAtBeginning(Head, 30);
    PrintList(Head);

    // 3. Test InsertAtEnd
    cout << "\n\nInserting elements at end (40, then 50): ";
    InsertAtEnd(Head, 40);
    InsertAtEnd(Head, 50);
    PrintList(Head);

    // 4. Test Find and InsertAfter
    cout << "\n\nSearching for node with value 20 to insert 25 after it: ";
    Node *searchedNode = Find(Head, 20);
    if (searchedNode != NULL)
    {
        InsertAfter(searchedNode, 25);
        cout << "[Node found! 25 inserted successfully.] => ";
    }
    else
    {
        cout << "[Element not found!]";
    }
    PrintList(Head);

    // 5. Test DeleteNode (middle node)
    cout << "\n\nDeleting node with value 25 (from the middle): ";
    DeleteNode(Head, 25);
    PrintList(Head);

    // 6. Test DeleteFirstNode
    cout << "\n\nDeleting the first node: ";
    DeleteFirstNode(Head);
    PrintList(Head);

    // 7. Test DeleteLastNode
    cout << "\n\nDeleting the last node: ";
    DeleteLastNode(Head);
    PrintList(Head);

    // 8. Test searching for a non-existing element to check safety
    cout << "\n\nTesting search for a non-existing element (99): ";
    Node *notFoundNode = Find(Head, 99);
    if (notFoundNode == NULL)
    {
        cout << "Check passed: Element 99 not found, no crash occurred!";
    }

    system("pause>0");

    return 0;
}