
class DataType{

 public:
  enum Comparison {GREATER, LESS, EQUAL};
  explicit DataType(int value);
  Comparison compareTo(DataType &item);
  int getValue() const;
  void printValue();
 private: 
  int value;
};
