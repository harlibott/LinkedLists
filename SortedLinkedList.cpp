#include <iostream>
#include <cstdlib>
#include "DataType.h"
#include "ListNode.h"
#include "SortedLinkedList.h"

using namespace std;

SortedLinkedList:: SortedLinkedList(){
  head = NULL;
  count = 0;
}// sorted linked list constructor

SortedLinkedList:: ~SortedLinkedList(){
  ListNode * tempPtr;

  while(head != NULL){
    tempPtr = head;
    head = head->next;
    delete tempPtr;
  }
}// sortedliinked list destructor

int SortedLinkedList:: length() const{
  return count;
}// length

void SortedLinkedList:: insertItem(DataType &item){
  // handles inserting nodes into list
  ListNode * newNode;
  ListNode * predLoc;
  ListNode * location;
  bool search;

  location = head;
  predLoc = NULL;
  
  search = (location != NULL);
  
  while(search){ // uses the compare to function to see which sortint to use
    switch(item.compareTo(location->item)){
    case DataType::GREATER:
      predLoc = location;
      location = location->next;
      search = (location != NULL);
      break;
      
    case DataType::LESS:
      search = false;
      break;
   
    case DataType::EQUAL:
      search = false;
      break;

    default:
      break;
    }// switch
  }// while

  // prepare the node for insertion ;)
  newNode = new ListNode(item);
 
  if(predLoc == NULL){
    newNode->next = head;
    head = newNode;
  }else{
    newNode->next = location;
    predLoc->next = newNode;
  }
  count++;

}// insert itme

void SortedLinkedList:: deleteItem(DataType &item){
  // handles deleting nodes
  ListNode * location = head;
  ListNode * tempLocation;

  if(item.compareTo(head->item) == DataType::EQUAL){
    tempLocation = location;
    head = head->next; // delete first node
  }else{
    while((item.compareTo(location->next->item)) != DataType::EQUAL){
      location = location->next;
    }
    
    tempLocation = location->next;
    location->next = location->next->next;
  }
  
  delete tempLocation;
  count --;
}// deleteItem

int SortedLinkedList:: search(DataType & item){
  // handles searching for nodes
  ListNode * current;
  int index = 0;

  current = head;

  while(current != NULL){
    if(item.compareTo(current->item) == DataType::EQUAL){
      cout << "\nIndex at ";
      return index;
    }// if

    index ++;
    current = current->next;
  }// while

  cout << "\nNo value found, ";
  return -1;
}// search

void SortedLinkedList:: clear(){
  //handles clearing list
  ListNode * temp;
  
  while(head != NULL){
    temp = head;
    head = head->next;
    delete temp;
  }
  count = 0;
}// clear

void SortedLinkedList:: print(){ 
  ListNode * current;
  current = head;
  
  if(head == NULL){
    cout << "\nLIST IS EMPTY";
  }else{
    cout << "\nPRINT LIST:"<<endl;
    cout << "------------------------------------"<<endl;
    while(current != NULL){
      cout << current->item.getValue()<< "    ";
      current = current->next;
    }
  }// else
  cout << endl;
}// prints list

