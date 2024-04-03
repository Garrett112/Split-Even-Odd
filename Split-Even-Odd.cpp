#include <iostream>
#include "unorderLinkedList.h"

using namespace std;

class intLinkedList : public unorderedLinkedList<int> {
public:
    void splitEvensOddsList(intLinkedList& evensList, intLinkedList& oddsList) {
        if (this->first == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        nodeType<int>* current = this->first;
        evensList.first = nullptr;
        oddsList.first = nullptr;
        nodeType<int>* evensEnd = nullptr;
        nodeType<int>* oddsEnd = nullptr;

        while (current != nullptr) {                //while current pointer is not at the end of the linked list
            if (current->info % 2 == 0) {           //if the current node is evenly divisible by 2
                if (evensList.first == nullptr) {   //if evensStart equals nullptr (if evens linked list is empty)
                    evensList.first = current;      //set pointer evensStart equal to current
                    evensEnd = current;             //set pointer evensEnd equal to current
                }
                else {                              //if evensStart does not equal nullptr (if evens linked list is not empty)
                    evensEnd->link = current;       //set the link of evensEnd to current
                    evensEnd = evensEnd->link;      //set evensEnd equal to the link of itself
                }
            }
            else if (current->info % 2 != 0) {      //if the current node is not evenly divisible by 2
                if (oddsList.first == nullptr) {    //if oddsStart equals nullptr (if odds linked list is empty)
                    oddsList.first = current;       //set pointer oddsStart equal to current
                    oddsEnd = current;              //set pointer oddsEnd equal to current
                }   
                else {                              //if oddsStart does not equal nullptr (if odds linked list is not empty) 
                    oddsEnd->link = current;        //sets the link of oddsEnd to current
                    oddsEnd = oddsEnd->link;        //sets oddsEnd equal to the link of itself
                }
            }
            current = current->link;                //sets current equal to the link of itself (moves current to the next node)
        }
        if (evensList.first != nullptr) {           //if evensStart does not equal nullptr (if evens linked list is not empty)
            evensEnd->link = nullptr;               //sets the link of evensEnd to nullptr (ends the evens linked list)
        }
        if (oddsList.first != nullptr) {            //if oddsStart does not equal nullptr (if odds linked list is not empty) 
            oddsEnd->link = nullptr;                //sets the link of oddsEnd to nullptr (ends the odds linked list)
        }
        first = nullptr;
        last = nullptr;
        count = 0;
    }
};

int main()
{
    
    intLinkedList unorderedList;
    unorderedList.insertFirst(10);
    unorderedList.insertFirst(24);
    unorderedList.insertFirst(17);
    unorderedList.insertFirst(11);
    unorderedList.insertFirst(90);
    unorderedList.insertFirst(36);
    unorderedList.insertFirst(88);
    unorderedList.insertFirst(120);
    unorderedList.insertFirst(7);
    unorderedList.insertFirst(53);
    unorderedList.insertFirst(66);
    unorderedList.insertFirst(90);
    unorderedList.insertFirst(15);
    unorderedList.insertFirst(10);
    unorderedList.insertFirst(21);
    unorderedList.insertFirst(62);
    unorderedList.insertFirst(34);
    cout << "List: ";
    unorderedList.print();
    cout << endl;
    intLinkedList evensList;
    intLinkedList oddsList;
    unorderedList.splitEvensOddsList(evensList, oddsList);
    linkedListIterator<int> printer = evensList.begin();
    cout << "Evens List: ";
    while (printer != evensList.end()) {
        cout << *printer << " ";
        ++printer;
    }
    cout << endl;
    printer = oddsList.begin();
    cout << "Odds List: ";
    while (printer != oddsList.end()) {
        cout << *printer << " ";
        ++printer;
    }
}
