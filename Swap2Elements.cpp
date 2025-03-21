#include <iostream>

// Definer en struktur for elementene i listen
struct Elem {
    int data;
    Elem* next;
};

// Funksjon for å bytte to elementer i en lineær liste
void swap2Elements(Elem* p1, Elem* p2, Elem*& head) {
    if (p1 == p2) return; // Ingen bytte nødvendig hvis p1 og p2 er de samme

    Elem* prev1 = nullptr, * prev2 = nullptr, * curr = head;

    // Finn forrige element for p1 og p2
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



