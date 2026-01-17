/////////////////////////////////////////////////////////////////////////
//
//  File Name   :  GeneralizedDataStructureLibrary.cpp
//  Author      :  Omkar Pramod Sudrik 
//  Date        :  13/01/2026
//  Description :  Comprehensive C++ Generic Data Structures Library
//                 - Singly Linear Linked List
//                 - Doubly Linear Linked List
//                 - Singly Circular Linked List
//                 - Doubly Circular Linked List
//                 - Stack (Linked List Implementation)
//                 - Queue (Linked List Implementation)
//
//                 This library supports insertion, deletion, display,
//                 and count operations for various generic data types.
//
//  Purpose     :  Demonstrates object-oriented design and template
//                 usage for reusable, type-independent data structures.
//                 
/////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////
//
// Required Header Files
//
////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////
//
// Class Name : SinglyLLLnode
// Description: Represents a node of singly linear linked list
//
////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class SinglyLLLnode
{
public:
    T data;
    SinglyLLLnode<T> *next;

    SinglyLLLnode(T no)
    {
        data = no;
        next = NULL;
    }
};

////////////////////////////////////////////////////////////////////////
//
// Class Name : SinglyLLL
// Description: Generic Singly Linear Linked List
//
////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyLLL
{
private:
    SinglyLLLnode<T> *first;
    int iCount;

public:
    SinglyLLL();

    void InsertFirst(T);
    void InsertLast(T);
    void DeleteFirst();
    void DeleteLast();
    void Display();
    int Count();
    void InsertAtPos(T, int);
    void DeleteAtPos(int);
};

////////////////////////////////////////////////////////////////////////
//
// Function Name : SinglyLLL (Constructor)
// Input         : None
// Output        : None
// Description   : Initializes an empty linked list
//
////////////////////////////////////////////////////////////////////////

template <class T>
SinglyLLL<T>::SinglyLLL()
{
    cout << "Object of SinglyLLL gets created.\n";
    first = NULL;
    iCount = 0;
}

////////////////////////////////////////////////////////////////////////
//
// Function Name : InsertFirst
// Input         : T no – Value to insert
// Output        : void
// Description   : Inserts a node at the beginning of the list
//
////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::InsertFirst(T no)
{
    SinglyLLLnode<T> *newn = new SinglyLLLnode<T>(no);

    newn->next = first;
    first = newn;
    iCount++;
}

////////////////////////////////////////////////////////////////////////
//
// Function Name : InsertLast
// Input         : T no – Value to insert
// Output        : void
// Description   : Inserts a node at the end of the list
//
////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::InsertLast(T no)
{
    SinglyLLLnode<T> *newn = new SinglyLLLnode<T>(no);

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        SinglyLLLnode<T> *temp = first;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

////////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteFirst
// Input         : None
// Output        : void
// Description   : Deletes the first node from the list
//
////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::DeleteFirst()
{
    if (first == NULL)
    {
        return;
    }

    SinglyLLLnode<T> *temp = first;
    first = first->next;
    delete temp;
    iCount--;
}

////////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteLast
// Input         : None
// Output        : void
// Description   : Deletes the last node from the list
//
////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::DeleteLast()
{
    if (first == NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        SinglyLLLnode<T> *temp = first;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

////////////////////////////////////////////////////////////////////////
//
// Function Name : Display
// Input         : None
// Output        : void
// Description   : Displays all elements of the linked list
//
////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::Display()
{
    SinglyLLLnode<T> *temp = first;

    while (temp != NULL)
    {
        cout << "| " << temp->data << " |-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

////////////////////////////////////////////////////////////////////////
//
// Function Name : Count
// Input         : None
// Output        : int No - Number of nodes
// Description   : Returns total number of nodes in the list
//
////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyLLL<T>::Count()
{
    return iCount;
}

////////////////////////////////////////////////////////////////////////
//
// Function Name : InsertAtPos
// Input         : T no - Value to insert
//                 int pos - Position
// Output        : void
// Description   : Inserts a node at the specified position
//
////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::InsertAtPos(T no, int pos)
{
    if (pos < 1 || pos > iCount + 1)
    {
        cout << "Invalid position\n";
        return;
    }

    if (pos == 1)
    {
        InsertFirst(no);
    }
    else if (pos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        SinglyLLLnode<T> *newn = new SinglyLLLnode<T>(no);
        SinglyLLLnode<T> *temp = first;

        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
        iCount++;
    }
}

////////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteAtPos
// Input         : int pos - Position
// Output        : void
// Description   : Deletes a node from the specified position
//
////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::DeleteAtPos(int pos)
{
    if (pos < 1 || pos > iCount)
    {
        cout << "Invalid position\n";
        return;
    }

    if (pos == 1)
    {
        DeleteFirst();
    }
    else if (pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        SinglyLLLnode<T> *temp = first;

        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        SinglyLLLnode<T> *target = temp->next;
        temp->next = target->next;
        delete target;
        iCount--;
    }
}


///////////////////////////////////////////////////////////////////////
//          Doubly Linear LinlkedList using Generic Approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class DoublyLLLnode
{
    public:
        T data;
        DoublyLLLnode *next;
        DoublyLLLnode *prev;

        // Constructor: Creates a new node with given data
        DoublyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

////////////////////////////////////////////////////////////////////////
//
// Class Name : DoublyLLL
// Description: Generic Doubly Linear Linked List
//
////////////////////////////////////////////////////////////////////////

template<class T>
class DoublyLLL
{
private:
    DoublyLLLnode<T> *first;
    int iCount;

public:
    DoublyLLL();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

    void Display();
    int Count();
};

////////////////////////////////////////////////////////////////////////
//
// Function Name : DoublyLLL (Constructor)
// Input         : None
// Output        : None
// Description   : Initializes an empty doubly linked list
//
////////////////////////////////////////////////////////////////////////

template<class T>
DoublyLLL<T>::DoublyLLL()
{
    cout << "Linked List gets created\n";
    first = NULL;
    iCount = 0;
}

////////////////////////////////////////////////////////////////////////
//
// Function Name : InsertFirst
// Input         : T no - Value to insert
// Output        : void
// Description   : Inserts a node at the beginning of the list
//
////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T>::InsertFirst(T no)
{
    DoublyLLLnode<T> *newn = new DoublyLLLnode<T>(no);

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    iCount++;
}

////////////////////////////////////////////////////////////////////////
//
// Function Name : InsertLast
// Input         : T no - Value to insert
// Output        : void
// Description   : Inserts a node at the end of the list
//
////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T>::InsertLast(T no)
{
    DoublyLLLnode<T> *newn = new DoublyLLLnode<T>(no);

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        DoublyLLLnode<T> *temp = first;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}

////////////////////////////////////////////////////////////////////////
//
// Function Name : InsertAtPos
// Input         : T no - Value to insert
//                 int pos - Position
// Output        : void
// Description   : Inserts a node at the specified position
//
////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T>::InsertAtPos(T no, int pos)
{
    if (pos < 1 || pos > iCount + 1)
    {
        cout << "Invalid position\n";
        return;
    }

    if (pos == 1)
    {
        InsertFirst(no);
    }
    else if (pos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        DoublyLLLnode<T> *newn = new DoublyLLLnode<T>(no);
        DoublyLLLnode<T> *temp = first;

        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

////////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteFirst
// Input         : None
// Output        : void
// Description   : Deletes the first node of the list
//
////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T>::DeleteFirst()
{
    if (first == NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        first = first->next;
        delete first->prev;
        first->prev = NULL;
    }
    iCount--;
}

////////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteLast
// Input         : None
// Output        : void
// Description   : Deletes the last node of the list
//
////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T>::DeleteLast()
{
    if (first == NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        DoublyLLLnode<T> *temp = first;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

////////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteAtPos
// Input         : int pos - Position
// Output        : void
// Description   : Deletes a node from the specified position
//
////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T>::DeleteAtPos(int pos)
{
    if (pos < 1 || pos > iCount)
    {
        cout << "Invalid position\n";
        return;
    }

    if (pos == 1)
    {
        DeleteFirst();
    }
    else if (pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        DoublyLLLnode<T> *temp = first;

        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        DoublyLLLnode<T> *target = temp->next;
        temp->next = target->next;
        target->next->prev = temp;

        delete target;
        iCount--;
    }
}

////////////////////////////////////////////////////////////////////////
//
// Function Name : Display
// Input         : None
// Output        : void
// Description   : Displays all nodes in the list
//
////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T>::Display()
{
    DoublyLLLnode<T> *temp = first;

    cout << "NULL<=>";
    while (temp != NULL)
    {
        cout << "| " << temp->data << " |<=>";
        temp = temp->next;
    }
    cout << "NULL\n";
}

////////////////////////////////////////////////////////////////////////
//
// Function Name : Count
// Input         : None
// Output        : int - Number of nodes
// Description   : Returns total number of nodes in the list
//
////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyLLL<T>::Count()
{
    return iCount;
}


///////////////////////////////////////////////////////////////////////
//          Doubly Linear LinlkedList using Generic Approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)

template<class T>
class SinglyCLLnode
{
    public:
        T data;
        SinglyCLLnode<T>* next;

        SinglyCLLnode(T no)
        {
            data = no;
            next = NULL;
        }
};

template<class T>
class SinglyCLL
{
    private:
        SinglyCLLnode<T>* first;
        SinglyCLLnode<T>* last;
        int iCount;

    public:
        SinglyCLL();

        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(T,int);
        void DeleteAtPos(int);
        void Display();
        int Count();
};

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     SinglyCLL (Constructor)
//  Input         :     None
//  Output        :     None
//  Description   :     Initializes empty singly circular linked list
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
SinglyCLL<T>::SinglyCLL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}


/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Input         :     Data of node
//  Output        :     None
//  Description   :     Inserts node at first position
//
/////////////////////////////////////////////////////////////////////////////


template<class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    SinglyCLLnode<T>* newn = new SinglyCLLnode<T>(no);

    if(first == NULL)
    {
        first = last = newn;
        last->next = first;
    }
    else
    {
        newn->next = first;
        first = newn;
        last->next = first;
    }
    iCount++;
}


/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast
//  Input         :     Data of node
//  Output        :     None
//  Description   :     Inserts node at last position
//
/////////////////////////////////////////////////////////////////////////////


template<class T>
void SinglyCLL<T>::InsertLast(T no)
{
    SinglyCLLnode<T>* newn = new SinglyCLLnode<T>(no);

    if(first == NULL)
    {
        first = last = newn;
        last->next = first;
    }
    else
    {
        last->next = newn;
        last = newn;
        last->next = first;
    }
    iCount++;
}


/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst
//  Input         :     None
//  Output        :     None
//  Description   :     Deletes first node from the list
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T>::DeleteFirst()
{
    if(first == NULL)
        return;

    if(first == last)
    {
        delete first;
        first = last = NULL;
    }
    else
    {
        SinglyCLLnode<T>* temp = first;
        first = first->next;
        delete temp;
        last->next = first;
    }
    iCount--;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast
//  Input         :     None
//  Output        :     None
//  Description   :     Deletes last node from the list
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T>::DeleteLast()
{
    if(first == NULL)
        return;

    if(first == last)
    {
        delete first;
        first = last = NULL;
    }
    else
    {
        SinglyCLLnode<T>* temp = first;
        while(temp->next != last)
        {
            temp = temp->next;
        }
        delete last;
        last = temp;
        last->next = first;
    }
    iCount--;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Input         :     Data of node, Position
//  Output        :     None
//  Description   :     Inserts node at specified position
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T>::InsertAtPos(T no, int pos)
{
    if(pos < 1 || pos > iCount + 1)
        return;

    if(pos == 1)
        InsertFirst(no);
    else if(pos == iCount + 1)
        InsertLast(no);
    else
    {
        SinglyCLLnode<T>* newn = new SinglyCLLnode<T>(no);
        SinglyCLLnode<T>* temp = first;

        for(int i = 1; i < pos - 1; i++)
            temp = temp->next;

        newn->next = temp->next;
        temp->next = newn;
        iCount++;
    }
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos
//  Input         :     Position
//  Output        :     None
//  Description   :     Deletes node at specified position
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T>::DeleteAtPos(int pos)
{
    if(pos < 1 || pos > iCount)
        return;

    if(pos == 1)
        DeleteFirst();
    else if(pos == iCount)
        DeleteLast();
    else
    {
        SinglyCLLnode<T>* temp = first;

        for(int i = 1; i < pos - 1; i++)
            temp = temp->next;

        SinglyCLLnode<T>* targ = temp->next;
        temp->next = targ->next;
        delete targ;
        iCount--;
    }
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input         :     None
//  Output        :     Displays list elements
//  Description   :     Displays all nodes of the list
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T>::Display()
{
    if(first == NULL)
        return;

    SinglyCLLnode<T>* temp = first;

    do
    {
        cout << "| " << temp->data << " |-> ";
        temp = temp->next;
    } while(temp != first);

    cout << "(First)\n";
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input         :     None
//  Output        :     Number of nodes
//  Description   :     Returns total node count
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyCLL<T>::Count()
{
    return iCount;
}


////////////////////////////////////////////////////////////////////////
//
// Doubly Circular Linked List using Generic Approach
//
////////////////////////////////////////////////////////////////////////

#pragma pack(1)

////////////////////////////////////////////////////////////////////////
//
// Class Name : node
// Description: Represents a node of doubly linked list
//
////////////////////////////////////////////////////////////////////////

template<class T>
class node
{
public:
    T data;
    node<T> *next;
    node<T> *prev;
};

////////////////////////////////////////////////////////////////////////
//
// Class Name : DoublyCLL
// Description: Generic Doubly Linked List
//
////////////////////////////////////////////////////////////////////////

template<class T>
class DoublyCLL
{
private:
    node<T> *first;
    int iCount;

public:
    DoublyCLL();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

    void Display();
    int Count();
};

////////////////////////////////////////////////////////////////////////
//
// Function Name : DoublyCLL (Constructor)
// Input         : None
// Output        : None
// Description   : Initializes an empty doubly linked list
//
////////////////////////////////////////////////////////////////////////

template<class T>
DoublyCLL<T>::DoublyCLL()
{
    cout << "Object of DoublyLL gets created.\n";
    first = NULL;
    iCount = 0;
}

////////////////////////////////////////////////////////////////////////
//
// Function Name : InsertFirst
// Input         : T no - Value to insert
// Output        : void
// Description   : Inserts a node at the beginning of the list
//
////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::InsertFirst(T no)
{
    node<T> *newn = new node<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    iCount++;
}

////////////////////////////////////////////////////////////////////////
//
// Function Name : InsertLast
// Input         : T no - Value to insert
// Output        : void
// Description   : Inserts a node at the end of the list
//
////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::InsertLast(T no)
{
    node<T> *newn = new node<T>;
    node<T> *temp = first;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}

////////////////////////////////////////////////////////////////////////
//
// Function Name : InsertAtPos
// Input         : T no - Value to insert
//                 int pos - Position
// Output        : void
// Description   : Inserts a node at the specified position
//
////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::InsertAtPos(T no, int pos)
{
    if (pos < 1 || pos > iCount + 1)
    {
        return;
    }

    if (pos == 1)
    {
        InsertFirst(no);
    }
    else if (pos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        node<T> *newn = new node<T>;
        node<T> *temp = first;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;

        temp->next->prev = newn;
        temp->next = newn;

        iCount++;
    }
}

////////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteFirst
// Input         : None
// Output        : void
// Description   : Deletes the first node of the list
//
////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::DeleteFirst()
{
    if (first == NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        first = first->next;
        delete first->prev;
        first->prev = NULL;
    }
    iCount--;
}

////////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteLast
// Input         : None
// Output        : void
// Description   : Deletes the last node of the list
//
////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::DeleteLast()
{
    if (first == NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        node<T> *temp = first;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->prev->next = NULL;
        delete temp;
    }
    iCount--;
}

////////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteAtPos
// Input         : int pos - Position
// Output        : void
// Description   : Deletes a node from the specified position
//
////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::DeleteAtPos(int pos)
{
    if (pos < 1 || pos > iCount)
    {
        return;
    }

    if (pos == 1)
    {
        DeleteFirst();
    }
    else if (pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        node<T> *temp = first;

        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
        iCount--;
    }
}

////////////////////////////////////////////////////////////////////////
//
// Function Name : Display
// Input         : None
// Output        : void
// Description   : Displays all nodes of the list
//
////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::Display()
{
    node<T> *temp = first;

    while (temp != NULL)
    {
        cout << "| " << temp->data << " | <=> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

////////////////////////////////////////////////////////////////////////
//
// Function Name : Count
// Input         : None
// Output        : int - Number of nodes
// Description   : Returns total number of nodes in the list
//
////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyCLL<T>::Count()
{
    return iCount;
}


/////////////////////////////////////////////////////////////////////////
//
// Stack using Generic Approach
//
////////////////////////////////////////////////////////////////////////

#pragma pack(1)

////////////////////////////////////////////////////////////////////////
//
// Class Name : Stacknode
// Description: Represents a node of stack
//
////////////////////////////////////////////////////////////////////////

template<class T>
class Stacknode
{
public:
    T data;
    Stacknode<T> *next;

    Stacknode(T no)
    {
        data = no;
        next = NULL;
    }
};

////////////////////////////////////////////////////////////////////////
//
// Class Name : Stack
// Description: Generic Stack implementation using linked list
//
////////////////////////////////////////////////////////////////////////

template<class T>
class Stack
{
private:
    Stacknode<T> *first;
    int iCount;

public:
    Stack();

    void push(T);
    T pop();
    T peep();
    void Display();
    int Count();
};

////////////////////////////////////////////////////////////////////////
//
// Function Name : Stack (Constructor)
// Input         : None
// Output        : None
// Description   : Initializes an empty stack
//
////////////////////////////////////////////////////////////////////////

template<class T>
Stack<T>::Stack()
{
    cout << "Stack gets created successfully\n";
    first = NULL;
    iCount = 0;
}

////////////////////////////////////////////////////////////////////////
//
// Function Name : push
// Input         : T no - Value to be pushed
// Output        : void
// Description   : Inserts an element at the top of the stack
//
////////////////////////////////////////////////////////////////////////

template<class T>
void Stack<T>::push(T no)
{
    Stacknode<T> *newn = new Stacknode<T>(no);

    newn->next = first;
    first = newn;
    iCount++;
}

////////////////////////////////////////////////////////////////////////
//
// Function Name : pop
// Input         : None
// Output        : T – Removed element
// Description   : Removes and returns the top element of the stack
//
////////////////////////////////////////////////////////////////////////

template<class T>
T Stack<T>::pop()
{
    if (first == NULL)
    {
        cout << "Stack is empty\n";
        return -1;
    }

    T Value = first->data;
    Stacknode<T> *temp = first;

    first = first->next;
    delete temp;
    iCount--;

    return Value;
}

////////////////////////////////////////////////////////////////////////
//
// Function Name : peep
// Input         : None
// Output        : T - Top element
// Description   : Returns the top element without removing it
//
////////////////////////////////////////////////////////////////////////

template<class T>
T Stack<T>::peep()
{
    if (first == NULL)
    {
        cout << "Stack is empty\n";
        return -1;
    }

    return first->data;
}

////////////////////////////////////////////////////////////////////////
//
// Function Name : Display
// Input         : None
// Output        : void
// Description   : Displays all elements of the stack
//
////////////////////////////////////////////////////////////////////////

template<class T>
void Stack<T>::Display()
{
    if (first == NULL)
    {
        cout << "Stack is empty\n";
        return;
    }

    Stacknode<T> *temp = first;

    while (temp != NULL)
    {
        cout << "|\t" << temp->data << "\t|\n";
        temp = temp->next;
    }
}

////////////////////////////////////////////////////////////////////////
//
// Function Name : Count
// Input         : None
// Output        : int – Number of elements
// Description   : Returns total number of elements in the stack
//
////////////////////////////////////////////////////////////////////////

template<class T>
int Stack<T>::Count()
{
    return iCount;
}


////////////////////////////////////////////////////////////////////////
//
// Queue using Generic Approach
//
////////////////////////////////////////////////////////////////////////

#pragma pack(1)

////////////////////////////////////////////////////////////////////////
//
// Class Name : Queuenode
// Description: Represents a node of queue
//
////////////////////////////////////////////////////////////////////////

template<class T>
class Queuenode
{
public:
    T data;
    Queuenode<T> *next;

    Queuenode(T no)
    {
        data = no;
        next = NULL;
    }
};

////////////////////////////////////////////////////////////////////////
//
// Class Name : Queue
// Description: Generic Queue implementation using linked list
//
////////////////////////////////////////////////////////////////////////

template<class T>
class Queue
{
private:
    Queuenode<T> *first;
    Queuenode<T> *last;
    int iCount;

public:
    Queue();

    void enqueue(T);
    T dequeue();
    void Display();
    int Count();
};

////////////////////////////////////////////////////////////////////////
//
// Function Name : Queue (Constructor)
// Input         : None
// Output        : None
// Description   : Initializes an empty queue
//
////////////////////////////////////////////////////////////////////////

template<class T>
Queue<T>::Queue()
{
    cout << "Queue gets created successfully\n";
    first = NULL;
    last = NULL;
    iCount = 0;
}

////////////////////////////////////////////////////////////////////////
//
// Function Name : enqueue
// Input         : T no – Value to be inserted
// Output        : void
// Description   : Inserts element at the rear of the queue
//
////////////////////////////////////////////////////////////////////////

template<class T>
void Queue<T>::enqueue(T no)
{
    Queuenode<T> *newn = new Queuenode<T>(no);

    if (first == NULL && last == NULL)
    {
        first = last = newn;
    }
    else
    {
        last->next = newn;
        last = newn;
    }
    iCount++;
}

////////////////////////////////////////////////////////////////////////
//
// Function Name : dequeue
// Input         : None
// Output        : T – Removed element
// Description   : Removes element from the front of the queue
//
////////////////////////////////////////////////////////////////////////

template<class T>
T Queue<T>::dequeue()
{
    if (first == NULL && last == NULL)
    {
        cout << "Queue is empty\n";
        return -1;
    }

    T Value = first->data;
    Queuenode<T> *temp = first;

    first = first->next;
    delete temp;
    iCount--;

    return Value;
}

////////////////////////////////////////////////////////////////////////
//
// Function Name : Display
// Input         : None
// Output        : void
// Description   : Displays all elements of the queue
//
////////////////////////////////////////////////////////////////////////

template<class T>
void Queue<T>::Display()
{
    if (first == NULL && last == NULL)
    {
        cout << "Queue is empty\n";
        return;
    }

    Queuenode<T> *temp = first;

    while (temp != NULL)
    {
        cout << "| " << temp->data << " | - ";
        temp = temp->next;
    }
    cout << "\n";
}

////////////////////////////////////////////////////////////////////////
//
// Function Name : Count
// Input         : None
// Output        : int – Number of elements
// Description   : Returns total number of elements in the queue
//
////////////////////////////////////////////////////////////////////////

template<class T>
int Queue<T>::Count()
{
    return iCount;
}


//////////////////////////////// End of Library //////////////////////////////////

int main()
{
SinglyLLL<int> *obj1 = new SinglyLLL<int>();

    int iRet = 0;

    obj1->InsertFirst(51);
    obj1->InsertFirst(21);
    obj1->InsertFirst(11);

    obj1->Display();

    iRet = obj1->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj1->InsertLast(101);
    obj1->InsertLast(111);
    obj1->InsertLast(121);
    
    obj1->Display();

    iRet = obj1->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj1->DeleteFirst();
    obj1->Display();

    iRet = obj1->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj1->DeleteLast();

    obj1->Display();

    iRet = obj1->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj1->InsertAtPos(105,4);

    obj1->Display();

    iRet = obj1->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj1->DeleteAtPos(4);

    obj1->Display();

    iRet = obj1->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    delete obj1;

    ///////////////////////////////////////////////////////////////////////
    
    DoublyLLL<char> *dobj = new DoublyLLL<char>();

    dobj->InsertFirst('A');
    dobj->InsertFirst('B');
    dobj->InsertFirst('C');
    
    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";

    dobj->InsertLast('X');
    dobj->InsertLast('Y');
    dobj->InsertLast('Z');
    
    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";

    dobj->DeleteFirst();

    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";

    dobj->DeleteLast();

    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";

    dobj->InsertAtPos('$',4);

    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";

    dobj->DeleteAtPos(4);

    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";
    
    delete dobj;
/////////////////////////////////////////////////////////////////////////

SinglyCLL<int> *obj3 = new SinglyCLL<int>();

    obj3->InsertFirst(101);
    obj3->InsertFirst(111);
    obj3->InsertFirst(121);

    obj3->Display();
    cout << "Count : " << obj3->Count() << endl;

    obj3->InsertLast(201);
    obj3->InsertLast(301);

    obj3->Display();
    cout << "Count : " << obj3->Count() << endl;

    obj3->InsertAtPos(999, 3);
    obj3->Display();

    obj3->DeleteAtPos(3);
    obj3->Display();

///////////////////////////////////////////////////////////////////////////

   DoublyCLL<int> *obj4 = new DoublyCLL<int>();

    obj4->InsertFirst(51);
    obj4->InsertFirst(21);
    obj4->InsertFirst(11);

    obj4->Display();
    iRet = obj4->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj4->InsertLast(101);
    obj4->InsertLast(111);
    obj4->InsertLast(121);

    obj4->Display();
    iRet = obj4->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj4->DeleteFirst();
    obj4->Display();
    iRet = obj4->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj4->DeleteLast();
    obj4->Display();
    iRet = obj4->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj4->InsertAtPos(105,4);
    obj4->Display();
    iRet = obj4->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj4->DeleteAtPos(4);
    obj4->Display();
    iRet = obj4->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

///////////////////////////////////////////////////////////////////////////
   
    Stack<char>*sobj = new Stack<char>();

    sobj->push('A');
    sobj->push('B');
    sobj->push('C');
    sobj->push('D');
    
    sobj->Display();

    cout<<"Number of elements in stack are :"<<sobj->Count()<<"\n";

    cout<<"Return value of peep is :"<<sobj->peep()<<"\n";

    sobj->Display();

    cout<<"Number of elements in stack are :"<<sobj->Count()<<"\n";

    cout<<"Poped element is : "<<sobj->pop()<<"\n";

    sobj->Display();

    cout<<"Number of elements in stack are :"<<sobj->Count()<<"\n";

    cout<<"Poped element is : "<<sobj->pop()<<"\n";

    sobj->Display();

    cout<<"Number of elements in stack are :"<<sobj->Count()<<"\n";

    sobj->push('E');

    sobj->Display();

    cout<<"Number of elements in stack are :"<<sobj->Count()<<"\n";

    delete sobj;

///////////////////////////////////////////////////////////////////////
  
    Queue<double>*qobj = new Queue<double>();

    qobj->enqueue(11.56789);
    qobj->enqueue(21.56789);
    qobj->enqueue(51.56789);
    qobj->enqueue(101.56789);
    
    qobj->Display();

    cout<<"Number of elements in Queue are :"<<qobj->Count()<<"\n";

    cout<<"Removed element is : "<<qobj->dequeue()<<"\n";

    qobj->Display();

    cout<<"Number of elements in enequeue are :"<<qobj->Count()<<"\n";

    cout<<"Removed element is : "<<qobj->dequeue()<<"\n";

    qobj->Display();

    cout<<"Number of elements in enequeue are :"<<qobj->Count()<<"\n";

    qobj->enqueue(121.56789);

    qobj->Display();

    cout<<"Number of elements in enequeue are :"<<qobj->Count()<<"\n";

    delete qobj;

    return 0;
}
