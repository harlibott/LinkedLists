#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include "DataType.h"
#include "ListNode.h"
#include "SortedLinkedList.h"

using namespace std;

const char INSERT = 'i';
const char DELETE = 'd';
const char SEARCH = 's';
const char PRINT_ALL = 'p';
const char LENGTH = 'l';
const char COMMAND_LIST = 'h';
const char CLEAR_ALL = 'c';
const char QUIT = 'q';

SortedLinkedList list;

char commands[10] = {INSERT, DELETE, SEARCH, PRINT_ALL, LENGTH, COMMAND_LIST, CLEAR_ALL, QUIT};

void commandsList(){
  cout << endl;
  cout << "COMMANDS: " << endl;
  // handles printing out the commands 
  string example = "";
  for (int i = 0; i < 8; i++){
    cout << "   " << "(" << commands[i] << ") " << "- "; 
    switch(i){
    case 0:
      example = "Insert Value";
      break;
    case 1:
      example = "Delete Value";
      break;
    case 2:
      example = "Search Value";
      break;
    case 3:
      example = "Print List";
      break;
    case 4:
      example = "Print Length";
      break;
    case 5:
      example = "Command List";
      break;
    case 6: 
      example = "Clear List";
      break;
    case 7:
      example = "Quit Program";
      break;
    default: 
      example = "No options availible";
    }
    cout << example << endl;
  }// print commands
}//commands list

void commandDirection(char command){
  if(command == 'q'){
    cout << "\nQUITTING...\n" << endl;
    exit(EXIT_SUCCESS);
  }else if(command == 'h'){
    commandsList();

  }else if(command == 'i'){
    int insert;
    cout << "Enter number to insert: ";
    cin >> insert;

    DataType temp(insert);
    list.insertItem(temp); // insert and sort
    list.print();

  }else if(command == 'd'){
    int del;
    cout << "Enter number to delete: ";
    cin >> del;
    
    DataType temp(del);
    list.deleteItem(temp); // delete number 
    list.print();

  }else if(command == 's'){
    int search;
    cout << "Enter a value to search: ";
    cin >> search;
    
    DataType temp(search);
    cout << list.search(temp) << endl;
    list.print();
    // else display number index
   
  }else if(command == 'p'){
    list.print();
  
  }else if(command == 'c'){
    list.clear();
    list.print();
  
  }else if(command == 'l'){
    cout << "\nLength of list: " << list.length() << endl;
  }
}// command Direction

void prompt(){
  // handles prompt
  char command;
  string err = "There was an error. Please type only char letters listed in commands list (h) in lower case form...";
  
  cout << "\nEnter a command: ";
  cin >> command;
  
  if(command == 'h' || command == 'i' || command == 'd' || command == 's' || command == 'p' || command == 'l' ||
     command == 'c' || command == 'q'){
    commandDirection(command);
  }else{
    cout << "\n" << err << endl;
  }
  
}// prompt 

int main(int argc, char* argv[]){
  // main method that handles error checking and running the program

  //opens file
  if (argc > 1) {
    string fn = argv[1];
    int file;
    ifstream fin;
    
    fin.open(fn.c_str());
    assert(fin.is_open());
    
    //inserts list into linked list
    while(fin >> file){
      DataType temp(file);
      list.insertItem(temp);
    }

  } else {
    cout << "No file entered. Please enter a file containing a list. Exiting..."<< endl;
    return -1;
  }

  cout << endl;
  cout << "Welcome to the sorted array lists program..."<< endl;
  
commandsList();

  while(true){
    prompt();
  }
}// main
