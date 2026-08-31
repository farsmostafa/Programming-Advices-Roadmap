#pragma once

#include <iostream>
using namespace std;

template <typename T>
class clsDynamicArray
{
protected:
    int _Size;
    T* TempArray;
    T* OriginalArray;

public:
    clsDynamicArray(int Size = 0)
    {
        if (Size < 0)
            Size = 0;

        _Size = Size;
        OriginalArray = new T[_Size];
    }

    ~clsDynamicArray()
    {
        delete[] OriginalArray;
    }

    bool IsEmpty()
    {
        return _Size == 0;
    }

    int Size()
    {
        return _Size;
    }

    bool SetItem(int index, T value)
    {
        if (index < 0 || index >= _Size)
            return false;

        OriginalArray[index] = value;
        return true;
    }

    void PrintList()
    {
        for (int i = 0; i < _Size; i++)
            cout << OriginalArray[i] << " ";

        cout << endl;
    }

    void Resize(int NewSize)
    {
        if (NewSize < 0)
            NewSize = 0;

        TempArray = new T[NewSize];

        int count = (NewSize < _Size) ? NewSize : _Size;
        for (int i = 0; i < count; i++)
            TempArray[i] = OriginalArray[i];

        delete[] OriginalArray;
        OriginalArray = TempArray;
        _Size = NewSize;
    }

    T GetItem(int index)
    {
        if (index < 0 || index >= _Size)
            return T{};

        return OriginalArray[index];
    }

    void Reverse()
    {
        for (int i = 0; i < _Size / 2; i++)
        {
            T temp = OriginalArray[i];
            OriginalArray[i] = OriginalArray[_Size - 1 - i];
            OriginalArray[_Size - 1 - i] = temp;
        }
    }

    void Clear()
    {
        delete[] OriginalArray;
        _Size = 0;
        OriginalArray = new T[0];
    }

    bool DeleteItemAt(int index)
    {
        if (index < 0 || index >= _Size)
            return false;

        _Size--;
        TempArray = new T[_Size];

        for (int i = 0; i < index; i++)
            TempArray[i] = OriginalArray[i];

        for (int i = index; i < _Size; i++)
            TempArray[i] = OriginalArray[i + 1];

        delete[] OriginalArray;
        OriginalArray = TempArray;
        return true;
    }

    bool DeleteFirstItem()
    {
        return DeleteItemAt(0);
    }

    bool DeleteLastItem()
    {
        if (_Size == 0)
            return false;

        return DeleteItemAt(_Size - 1);
    }

    int Find(T value)
    {
        for (int i = 0; i < _Size; i++)
        {
            if (OriginalArray[i] == value)
                return i;
        }

        return -1;
    }

    bool DeleteItem(T value)
    {
        int index = Find(value);
        if (index == -1)
            return false;

        return DeleteItemAt(index);
    }

    bool InsertAt(int index, T value)
    {
        if (index < 0 || index > _Size)
            return false;

        _Size++;
        TempArray = new T[_Size];

        for (int i = 0; i < index; i++)
            TempArray[i] = OriginalArray[i];

        TempArray[index] = value;

        for (int i = index + 1; i < _Size; i++)
            TempArray[i] = OriginalArray[i - 1];

        delete[] OriginalArray;
        OriginalArray = TempArray;
        return true;
    }

    bool InsertAtBeginning(T value)
    {
        return InsertAt(0, value);
    }

    bool InsertAtEnd(T value)
    {
        return InsertAt(_Size, value);
    }

    bool InsertAfter(int index, T value)
    {
        if (index >= _Size)
            return InsertAtEnd(value);

        return InsertAt(index + 1, value);
    }

    bool InsertBefore(int index, T value)
    {
        if (index <= 0)
            return InsertAtBeginning(value);

        return InsertAt(index, value);
    }
};
