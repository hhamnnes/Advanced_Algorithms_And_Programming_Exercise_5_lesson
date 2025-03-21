#include <iostream>

// I decided to create a struct to represent each element in the list
// and there properties. Based on the exercise description, I assume
// that each element in the list will represent some kind of value
// such as an integer. The struct also contains a pointer which points
// to the next element in the list.
struct Elem {
    int data;
    Elem* next;
};

//This will be the main function which will represent the algorithm 
//that we have been challenged to implement. The function will take 
//two pointers to elements in the list that we want to swap, and a
//pointer to the head of the list. The function will then swap the
//two elements in the list and update the head pointer if necessary.
void swap2Elements(Elem* p1, Elem* p2, Elem*& head) {

    // I have here created three pointers. The first two pointers
    // will be used to store the previous elements of the elements
    // that we want to swap. The third pointer will be used to
    // iterate through the list and is set to start at the begining 
    // of the list which will be the head pointer. Therefore the 
    // name; head.
    Elem* prev1 = nullptr, * prev2 = nullptr, * curr = head;


    // I have here implemented a loop to find the elements that are in
    // front of the elements p1 and p2 that we want to swap. This 
    // loop will run until ether the current pointer is null, which will
    // indicate that we have reached the end of the list, or until the
    // previous elements of the ones we want to swap have been found.
    while (curr != nullptr && (prev1 == nullptr || prev2 == nullptr)) {
        if (curr->next == p1) prev1 = curr;
        if (curr->next == p2) prev2 = curr;
        curr = curr->next;
    }

    // Hvis p1 eller p2 ikke finnes i listen, gjør ingenting
    if (p1 == nullptr || p2 == nullptr) return;

    // Hvis p1 eller p2 er hodet av listen
    if (p1 == head) head = p2;
    else if (p2 == head) head = p1;

    // Bytt forrige elementers next-peker
    if (prev1 != nullptr) prev1->next = p2;
    if (prev2 != nullptr) prev2->next = p1;

    // Bytt next-pekerne til p1 og p2
    Elem* temp = p1->next;
    p1->next = p2->next;
    p2->next = temp;
}

// Hjelpefunksjon for å skrive ut listen
void printList(Elem* head) {
    Elem* curr = head;
    while (curr != nullptr) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

int main() {
    // Opprett en enkel liste for testing
    Elem* head = new Elem{1, nullptr};
    head->next = new Elem{2, nullptr};
    head->next->next = new Elem{3, nullptr};
    head->next->next->next = new Elem{4, nullptr};

    std::cout << "Original list: ";
    printList(head);

    // Bytt elementene 2 og 3
    swap2Elements(head->next, head->next->next, head);

    std::cout << "List after swap: ";
    printList(head);

    // Rydd opp
    while (head != nullptr) {
        Elem* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}



