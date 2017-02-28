#include <iostream>
#include <string>
#include <sstream> // for ostringstream
#include <cassert>

#include "arrayFuncs.h"
#include "linkedList.h"
#include "linkedListFuncs.h"


// Pre-condition:'a' is a valid array with 
// zero or more elements, specified by 'size'
// Post-condition: A linked-list with 'size' number of nodes
// If size is zero, a valid 'empty' list is returned
LinkedList * arrayToLinkedList(int *a, int size) {
  
  LinkedList * list = new LinkedList;

  list->head=NULL; 
  list->tail=NULL;

  for (int i=0; i<size; i++) {
    // add array[i] to the list

    if ( list->head==NULL) {
      list->head = new Node;
      list->head->data = a[i]; // (*head).data = a[i];
      list->head->next = NULL;
      list->tail = list->head;
    } else {
      list->tail->next = new Node;
      list->tail = list->tail->next;
      list->tail->next = NULL;
      list->tail->data = a[i];
    }
  }

  return list; // return ptr to new list

}

// intToString converts an int to a string

std::string intToString(int i) {
// creates a stream like cout, cerr that writes to a string
  std::ostringstream oss; 
  oss << i;
  return oss.str(); // return the string result
}

// Precondition: A valid array 'a' with non-negative size
// Postcondition: A string representation of the elements of the array

std::string arrayToString(int a[], int size) {

  std::ostringstream oss;
  // fencepost problem; first element gets no comma in front
  oss << "{"; 

  if (size>0)
    oss << intToString(a[0]); 

  for (int i=1; i<size; i++) {
    oss << "," << intToString(a[i]);
  }
  oss << "}";

  return oss.str();
  
}


// free up every node on this linked list
// nice clean code thanks to @sashavolv2 (on Twitter) #woot
// Precondition: A valid linked-list on heap memory
// Postcondition: Every element of the linked-list is deleted
// The list structure is also deleted

void freeLinkedList(LinkedList * list) {

  Node *next;

  for (Node *p=list->head; p!=NULL; p=next) {
    next = p->next;
    delete p;
  }

  delete list; // returns memory to the heap (freestore)
}

// Precondition: A valid linked-list on heap memory, which
// may be possibly empty
// Postcondition: Returns a string representation of the elements
// of the linked-list

std::string linkedListToString(LinkedList *list) {

  std::string result="";
  for (const Node *  p=list->head; p!=NULL; p=p->next) {
    result += "[" + intToString(p->data) + "]->";
  }
  result += "null";
  return result;
}

// Precondition: A valid linked-list that may possibly be empty
// and an integer value
// Postcondition: A new node with provided value is added to the 
// the end of the list. The head and tail pointers are appropriately 
// updated
void addIntToEndOfList(LinkedList *list, int value) {
  assert(list!=NULL); // if list is NULL, we can do nothing.

   // temporary pointer

  // TODO:
  // (1) Allocate a new node.  p will point to it.
  Node* p = new Node;

  // (2) Set p's data field to the value passed in
  p->data = value;
  // (3) Set p's next field to NULL
  p->next = NULL;

  if (list->head == NULL) {

  // (4) Make both head and tail of this list point to p
  list->head = p;
  list->tail = p;
    
  } else {

    // Add p at the end of the list.   

    // (5) The current node at the tail? Make it point to p instead of NULL
    list->tail->next = p;
    // (6) Make the tail of the list be p now.
    list->tail = p;
  }

}

// Precondition: A valid linked-list on the heap and an integer value
// Postcondition: A new node is created with provided value and is
// added to the start of the list. The head and tail pointers are 
// appropriately updated
void addIntToStartOfList(LinkedList *list, int value) {
  assert(list!=NULL); // if list is NULL, we can do nothing.

  Node* p = new Node;
  p->data = value;
  p->next = NULL;
  
  if (list->head == NULL){
    list->head = p;//if no item in the list, the p is the only item
    list->tail = p;
  }else{
    p->next = list->head;// link the p to the old list
    list->head  = p;// the p becomes the new link we want
  }

}
