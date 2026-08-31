#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;

int main()
{
    // 1. إنشاء قائمة ديناميكية للأرقام الصحيحة
    clsDblLinkedList<int> myList;

    cout << "--- Testing Insertion ---" << endl;
    myList.InsertAtBeginning(10);
    myList.InsertAtBeginning(5);
    myList.InsertAtEnd(20);
    myList.InsertAtEnd(30);

    // طباعة القائمة بعد الإدخال الأساسي (المتوقع: 5 <--> 10 <--> 20 <--> 30)
    myList.PrintList();
    cout << endl;

    cout << "\n\nNumber of nodes in the list: " << myList.Size() << endl;

    // 2. تجربة دالة البحث والإدخال بعدها
    cout << "\n--- Testing Insert After 10 ---" << endl;
    clsDblLinkedList<int>::Node *foundNode = myList.Find(10);
    myList.InsertAfter(foundNode, 15);
    myList.PrintList();
    cout << endl;

    // 3. طباعة تفاصيل الروابط لكل عقدة بشكل منفصل
    cout << "\n--- Testing List Details (Nodes Connections) ---";
    myList.PrintListDetails();

    // 4. تجربة دوال الحذف المتنوعة
    cout << "\n--- Testing Deletion Functions ---" << endl;

    cout << "Delete First Node:" << endl;
    myList.DeleteFirstNode();
    myList.PrintList();
    cout << endl;

    cout << "\nDelete Last Node:" << endl;
    myList.DeleteLastNode();
    myList.PrintList();
    cout << endl;

    cout << "\nDelete Specific Node (Value 15):" << endl;
    clsDblLinkedList<int>::Node *nodeToDelete = myList.Find(15);
    myList.DeleteNode(nodeToDelete);
    myList.PrintList();
    cout << endl;
    cout << "\nNumber of nodes in the list: " << myList.Size() << "\n\n\n";
    system("pause>0");
    return 0;
}