
class SortedLinkedList{
  
 public:
  SortedLinkedList();
  ~SortedLinkedList();
  int length() const;
  void insertItem(DataType &item);
  void deleteItem(DataType &item);
  int search(DataType &item);
  void clear();
  void print();

 private:
  int count;
  ListNode *head;
  DataType *item;
};// Sorted linked list
