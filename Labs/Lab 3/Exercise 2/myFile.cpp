#include "myLinkedList.h" 

#include <iomanip>

int main()
{
    Evaluation *first = nullptr; // Pointer on the first element of the list 
                                 // the list is empty, so initialization to NULL 
    int number = 0;              // number of elements in the linked list  
    int choice;                  // choice for the menu 

    do
    {
        cout << endl << endl << "1) Display of the complete linked list.\n";
        cout << "2) Inserting an element\n";
        cout << "3) Removing an element.\n";
        cout << "4) Calculation of the class average.\n";
        cout << "5) Exiting the program.\n" << endl << endl;
        cout << "Your choice ??:";
        cin >> choice;

        switch (choice)
        {
            case 1:
                display(first);
                break;
            case 2:
                first = add(first, number);
                break;
            case 3:
                first = remove(first, number);
                break;
            case 4:
                average(first, number);
                break;
            case 5:
                exit(0);
            default:
                break;
        }
    }
    while (true);

    return 0;
}

Evaluation *add(Evaluation *listNode, int &n)
{
    Evaluation *node = new Evaluation();

    flushInputBuffer();

    do
    {
        cout << "Please enter the name of the student: ";
        cin.getline(node->student, SIZE);
    }
    while ([node]()
    {
        if (cin.fail())
        {
            cout << "Invalid input. Try again." << endl;
            cin.clear();
            flushInputBuffer();
            return true;
        }

        if (!node->student[0])
        {
            cout << "You did not enter anything. Try again." << endl;
            cin.clear();
            flushInputBuffer();
            return true;
        }

        return false;
    }());

    do
    {
        cout << "Please enter the grade of the student: ";
        cin >> node->grade;
    }
    while ([]()
    {
        if (cin.fail())
        {
            cout << "Invalid input. Try again." << endl;
            cin.clear();
            flushInputBuffer();
            return true;
        }

        return false;
    }());

    int position;

    do
    {
        cout << "Please enter the position of the new node: ";
        cin >> position;
    }
    while ([position, n]()
    {
        if (cin.fail() || position < 0 || position > n)
        {
            cout << "Invalid input. Try again." << endl;
            cin.clear();
            flushInputBuffer();
            return true;
        }

        return false;
    }());

    Evaluation *ptr = listNode;

    if (position == 0)
    {
        node->next = listNode;
        listNode = node;
    }
    else if (position == n)
    {
        while (ptr->next)
            ptr = ptr->next;

        ptr->next = node;
    }
    else
    {
        while (--position > 0)
            ptr = ptr->next;

        node->next = ptr->next;
        ptr->next = node;
    }
    ++n;
    return listNode;
}

Evaluation *remove(Evaluation *listNode, int &n)
{
    if (n == 0)
    {
        cout << "No element to remove" << endl;
        return listNode;
    }

    int position;

    do
    {
        cout << "Please enter the position of the target node: ";
        cin >> position;
    }
    while ([position, n]()
    {
        if (cin.fail() || position < 0 || position >= n)
        {
            cout << "Invalid input. Try again." << endl;
            cin.clear();
            flushInputBuffer();
            return true;
        }

        return false;
    }());

    Evaluation *ptr = listNode;

    if (position == 0)
    {
        listNode = listNode->next;
        delete ptr;
    }
    else
    {
        while (--position > 0)
            ptr = ptr->next;

        Evaluation *ptr2 = ptr->next;
        ptr->next = ptr->next->next;
        delete ptr2;
    }

    --n;

    if (!n)
        listNode = nullptr;

    return listNode;
}

void display(Evaluation *listNode)
{
    cout << left;

    cout << setw(SIZE) << "Student" << '\t' << "Grade" << endl;
    while (listNode)
    {
        cout << setw(SIZE) << listNode->student << '\t' << listNode->grade << endl;
        listNode = listNode->next;
    }

    cout << internal;
}

int average(Evaluation *listNode, int const &n)
{
    cout << "Average: ";

    if (!n)
    {
        cout << 0 << endl;
        return 0;
    }
        
    int sum = 0;

    while (listNode)
    {
        sum += listNode->grade;
        listNode = listNode->next;
    }

    cout << sum / n << endl;

    return sum / n;
}

void flushInputBuffer()
{
    while (cin.get() != '\n')
        ;
}
