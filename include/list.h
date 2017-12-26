#ifndef __AISD_LIST__
#define __AISD_LIST__

#include <iostream>
using namespace std;

typedef int DataType;

struct Node
{
  DataType data;
  Node* next;
  Node(DataType d, Node* n);
  Node();
  Node(const Node &node2);
  bool operator==(const Node& node2) const;
  // здесь могут быть конструкторы, методы, деструктор Node
};

class List
{
	Node* head;
  // любые поля
public:
  List();
  List(const List& list2);
  List& operator=(const List& list2);
  bool operator==(const List& list2) const;
  ~List();

  void InserToHead(const DataType& d); // вставить элемент d первым
  void InserToTail(const DataType& d); // вставить элемент d последним
  void InsertAfter(Node* node, const DataType& d); // вставить элемент d после звена node
  void Delete(const DataType& d); // удалить звено со значением data = d
  Node* Search(const DataType& d); // найти указатель на звено со значением data = d
  void Clean(); // удалить все звенья
  int GetSize(); // узнать число звеньев в списке
  Node* GetHead(); // получить указатель на первое звено списка

  void Inverse(); // инвертировать список, т.е. звенья должны идти в обратном порядке
  List Merge(Node* node, const List& list2); // создать список3, добавив список2 в текущий список после указателя node  
  List Merge(const List& list2); // создать список3, добавив в конец текущего списка список2

  friend ostream& operator<<(ostream& os, const List& l);
};

#endif