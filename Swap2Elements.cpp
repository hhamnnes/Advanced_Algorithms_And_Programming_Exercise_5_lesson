#include <iostream>

//I have used the following example on the web to understand hwo to create 
//a linked list in C++. riechan.(24th of august 2013). Pointers and linked lists. cplusplus.
// https://cplusplus.com/forum/beginner/109173/

//I have not considered cases when one of the elements is the head of the list, or that 
//the elements are outside the list. Since it was stated in the exercise: "without creating additional elements and 
//discussing all possible cases".




// I decided to create a struct to represent each element in the list
// and there properties. Based on the exercise description, I assume
// that each element in the list will represent some kind of value
// such as an integer. The struct also contains a pointer which points
// to the next element in the list.
struct Element {
    int data;
    Element* next;
};

//This will be the main function which will represent the algorithm 
//that we have been challenged to implement. The function will take 
//two pointers to Elements in the list that we want to swap, and a
//pointer to the head of the list. The function will then swap the
//two elements in the list and update the head pointer if necessary.
void swap2Elements(Element* p1, Element* p2, Element*& head) {

    // I have here created three pointers. The first two pointers
    // will be used to store the previous elements of the elements
    // that we want to swap. The third pointer will be used to
    // iterate through the list and is set to start at the begining 
    // of the list which will be the head pointer. Therefore the 
    // name; head.
    Element* prev1 = nullptr, * prev2 = nullptr, * curr = head;


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
    //This type of pointer handling was new to me, but I found it quite
    //interesting and useful. I will try to explain how it works, because
    // it took me some time to understand how to use it properly. 
    //The if statements wil check if the current pointer is pointing 
    //to the element that is in front of the element ether of the 
    //elements that we want to swap. The code curr->next == p1 will 
    //will check if the data parameter next of the current Elem is 
    //pointing to the same memory address as the p1 pointer. If so, 
    //then we know that the current element in the list is the element 
    //that is in front of the element that we want to swap.


    // After both the previous elements have been found, 
    // w now change the next pointers of the previous elements
    // to point to the swapped elements.
    prev1->next = p2;
    prev2->next = p1;

    //In order to finnish the swap process, 
    //we need to change the next pointers of the elements that we 
    //want to swap. temp will work as a temporary pinter which will
    //which will make it possible to swap the pointers of the two
    //two elements.
    
    Element* temp = p1->next;
    p1->next = p2->next;
    p2->next = temp;

}

//Just some code to make it easier to print the current list.
void printList(Element* head) {
    Element* curr = head;
    while (curr != nullptr) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

int main() {

    //This is how I can make a list.
    Element* head = new Element{1, nullptr}; //head points to the first element in the list.
    head->next = new Element{2, nullptr}; //Then the next next element is pointed at by the first element.
    head->next->next = new Element{3, nullptr}; //Then the next element is pointed at by the second element.
    head->next->next->next = new Element{4, nullptr};//And so on...

    //I print out the original list.
    std::cout << "Original list: ";
    printList(head);

    //Swaps the elements 2 and 3 in the list.
    swap2Elements(head->next, head->next->next, head);

    //And print out the list after the swap.
    std::cout << "List after swap: ";
    printList(head);

    return 0;
}



