#include <iostream>
using namespace std;

template <typename T>

class clsDblLinkedList
{
public:
    class Node
    {
        T _value;

    public:
        Node *_next;
        Node *_prev;
        void value(T value)
        {
            _value = value;
        }
        T value()
        {
            return _value;
        }
    };

protected:
    Node *_head;
    Node *_tail;
    int _size;

public:
    clsDblLinkedList()
    {
        _head = NULL;
        _tail = NULL;
        _size = 0;
    }

    int Size()
    {
        return _size;
    }

    bool IsEmpty()
    {
        return _size == 0;
    }

    void Clear()
    {
        while (_size > 0)
        {
            DeleteFirstNode();
        }
    }

    void Reverse()
    {
        if (_head == NULL || _head->_next == NULL)
            return;

        Node *current = _head;
        Node *temp = NULL;

        _tail = _head;

        while (current != NULL)
        {
            temp = current->_prev;
            current->_prev = current->_next;
            current->_next = temp;
            current = current->_prev;
        }

        if (temp != NULL)
        {
            _head = temp->_prev;
        }
    }

    Node *Find(T value)
    {
        Node *current = _head;
        while (current != NULL)
        {
            if (current->value() == value)
                return current;
            current = current->_next;
        }
        return NULL;
    }

    Node *GetNode(int index)
    {
        if (index < 0 || index >= _size)
            return NULL;

        if (_head == NULL || index == 0)
            return _head;
        if (index == _size - 1)
            return _tail;
        Node *current = _head;
        int Counter = 0;
        while (current->_next != NULL)
        {
            if (Counter == index)
                break;

            current = current->_next;
            Counter++;
        }

        return current;
    }

    T GetItem(int index)
    {
        Node *node = GetNode(index);
        if (node != NULL)
            return node->value();
        else
            return NULL;
    }

    bool UpdateItem(int index, T newValue)
    {
        Node *node = GetNode(index);
        if (node != NULL)
        {
            node->value(newValue);
            return true;
        }
        return false;
    }

    void InsertAtBeginning(T value)
    {
        Node *newNode = new Node();
        newNode->value(value);
        newNode->_next = _head;
        newNode->_prev = NULL;
        if (_tail == NULL)
        {
            _head = newNode;
            _tail = newNode;
        }
        else
        {
            _head->_prev = newNode;
            _head = newNode;
        }

        _size++;
    }

    void InsertAfter(Node *current, T value)
    {
        Node *newNode = new Node();
        newNode->value(value);
        newNode->_prev = current;
        newNode->_next = current->_next;
        if (current->_next != NULL)
        {
            current->_next->_prev = newNode;
        }
        current->_next = newNode;
        if (newNode->_next == NULL)
        {
            _tail = newNode;
        }
        _size++;
    }

    bool InsertAfter(int index, T value)
    {
        Node *current = GetNode(index);
        if (current != NULL)
        {
            InsertAfter(current, value);
            return true;
        }
        return false;
    }

    void InsertAtEnd(T value)
    {
        Node *newNode = new Node();
        newNode->_next = NULL;
        newNode->value(value);
        if (_head == NULL)
        {
            newNode->_prev = NULL;
            _head = newNode;
            _tail = newNode;
        }
        else
        {
            _tail->_next = newNode;
            newNode->_prev = _tail;
            _tail = newNode;
        }

        _size++;
    }

    void DeleteNode(Node *&NodeToDelete)
    {
        if (NodeToDelete == NULL || _head == NULL)
            return;

        if (NodeToDelete == _head)
        {
            _head = _head->_next;
            if (_head == NULL)
            {
                _tail = NULL;
            }
        }
        if (NodeToDelete == _tail)
        {
            _tail = _tail->_prev;
        }
        if (NodeToDelete->_next != NULL)
        {
            NodeToDelete->_next->_prev = NodeToDelete->_prev;
        }
        if (NodeToDelete->_prev != NULL)
        {
            NodeToDelete->_prev->_next = NodeToDelete->_next;
        }
        delete NodeToDelete;
        NodeToDelete = NULL;
        _size--;
    }

    void DeleteFirstNode()
    {
        if (_head == _tail)
        {
            delete _head;
            _head = NULL;
            _tail = NULL;
            _size--;
            return;
        }
        if (_head != NULL)
        {
            Node *temp = _head;
            _head = _head->_next;
            if (_head != NULL)
            {
                _head->_prev = NULL;
            }
            delete temp;
            _size--;
        }
    }

    void DeleteLastNode()
    {
        if (_head == NULL)
            return;

        if (_head->_next == NULL)
        {
            delete _head;
            _head = NULL;
            _tail = NULL;
            _size--;

            return;
        }

        Node *temp = _tail;
        _tail = _tail->_prev;
        _tail->_next = NULL;
        delete temp;
        _size--;
    }

    void PrintNodeDetails(Node *node)
    {
        if (node == NULL)
        {
            cout << "Node is NULL" << endl;
            return;
        }

        if (node->_prev != NULL)
            cout << node->_prev->value();
        else
            cout << "NULL";

        cout << " <--> " << node->value() << " <--> ";

        if (node->_next != NULL)
            cout << node->_next->value() << "\n";
        else
            cout << "NULL";
    }

    void PrintListDetails()
    {
        cout << "\n\n";
        Node *currentNode = _head;
        while (currentNode != NULL)
        {
            PrintNodeDetails(currentNode);
            currentNode = currentNode->_next;
        }
    }

    void PrintList()
    {
        Node *currentNode = _head;
        cout << "NULL <--> ";
        while (currentNode != NULL)
        {
            cout << currentNode->value() << " <--> ";
            currentNode = currentNode->_next;
        }
        cout << "NULL";
    }
};