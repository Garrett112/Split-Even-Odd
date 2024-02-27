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
        nodeType<int>* evensStart = nullptr;
        nodeType<int>* oddsStart = nullptr;
        nodeType<int>* evensEnd = nullptr;
        nodeType<int>* oddsEnd = nullptr;
        evensList.first = evensStart;
        oddsList.first = oddsStart;


        while (current != nullptr) {
            if (current->info % 2 == 0) {
                if (evensStart == nullptr) {
                    evensStart = current;
                    evensEnd = current;
                }
                else {
                    evensEnd->link = current;
                    evensEnd = evensEnd->link;
                }
            }
            else {
                if (oddsStart == nullptr) {
                    oddsStart = current;
                    oddsEnd = current;
                }
                else {
                    oddsEnd->link = current;
                    oddsEnd = oddsEnd->link;
                }
            }
            current = current->link;
        }
        if (oddsEnd != nullptr) {
            oddsEnd->link = nullptr;
        }
        if (evensStart != nullptr) {
            evensEnd->link = nullptr;
        }
        while (evensStart != nullptr) {
            cout << evensStart->info << endl;
            evensStart = evensStart->link;
        }
        cout << endl << endl;
        while (oddsStart != nullptr) {
            cout << oddsStart->info << endl;
            oddsStart = oddsStart->link;
        }

    }
    void printList() {
        nodeType<int>* current = this->first;
        while (current != nullptr) {
            cout << current->info << endl;
            current = current->link;
        }
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
    intLinkedList evensList;
    intLinkedList oddsList;
    unorderedList.splitEvensOddsList(evensList, oddsList);
    evensList.printList();
    oddsList.printList();
    



}
