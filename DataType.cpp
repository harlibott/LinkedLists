#include <iostream>
#include <cstdlib>
#include "DataType.h"

using namespace std;

DataType:: DataType(int value){
  this->value = value;
}// dataType constructor

DataType:: Comparison DataType:: compareTo(DataType &item){
  // handles the comparator function
  if (getValue() == item.getValue()){
    return DataType:: EQUAL;
  }
  else if (getValue() < item.getValue()) {
    return DataType:: LESS;
  }
  else {
    return DataType:: GREATER;
  }
}// Comparison

int DataType:: getValue() const{
  return this->value;
}// getValue

void DataType:: printValue(){
  cout << "value: " << getValue() << endl;
}
