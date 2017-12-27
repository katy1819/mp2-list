#include "list.h"

//это для структуры
//-------------------------------------------------

Node::Node(DataType d, Node* n)
{
	data = d;
	next = n;
}

Node::Node(const Node& node2)
{
	data = node2.data;
	next = node2.next;
}

Node::Node()
{
	data = NULL;
	next = NULL;
}

bool Node::operator==(const Node& node2) const
{
	if((data == node2.data) && (next == node2.next))
		return true;
	else
		return false;
}

//это для класса
//------------------------------------------------------
List::List()
{
	head = NULL;
}

List::List(const List& list2)
{
	if(list2.head == NULL)
	{
		head = NULL;
	}
	else
	{
		head = new Node(list2.head->data, list2.head);
		Node* head1 = head;
		Node* head2 = list2.head->next;
		while(head2 != NULL)
		{
			head1->next = new Node(head2->data, head2->next);
			head1 = head1->next;
			head2 = head2->next;
		}
	}
}
		
List& List::operator=(const List& list2)
{
	if(this != &list2)
	{
		Clean();
		if(list2.head != NULL)
		{
			head = new Node(list2.head->data, list2.head);
			Node* head1 = head;
			Node* head2 = list2.head->next;
			while(head2 != NULL)
			{
				head1->next = new Node(head2->data, head2->next);
				head1 = head1->next;
				head2 = head2->next;
			}
		}
	}
	return *this;
}

bool List::operator==(const List& list2) const
{
	Node* head1 = head;
	Node* head2 = list2.head;
	while((head1 != NULL) && (head2 != NULL) && (head1->data == head2->data))
	{
		head1 = head1->next;
		head2 = head2->next;
	}
	if((head1 == NULL) && (head2 == NULL))
		return true;
	else
		return false;
}

 List::~List()
 {
	 Node* head1 = head;
	 Node* head2 = head;
	 if(head1 != NULL)
	 {
		 while(head1 != NULL)
		 {
			 head2 = head1->next;
			 delete head1;
			 head1 = head2;
		 }
	 }
 }

 void List::InserToHead(const DataType& d) // вставить элемент d первым
 {
	 if(head == NULL)
		 head = new Node(d, NULL);
	 else
	 {
		 Node* head1 = new Node(d, head);
		 head1->next = head;
		 head = head1;
	 }
 }

void List::InserToTail(const DataType& d) // вставить элемент d последним
{
	Node* head1;
	head1 = head;
	if(head1 == NULL)
	{
		head = new Node(d, NULL);
	}
	else
	{
		while(head1->next != NULL)
		{
			head1 = head1->next;
		}
		head->next = new Node(d, NULL);
	}
}

void List::InsertAfter(Node* node, const DataType& d) // вставить элемент d после звена node
{
	if(head == NULL)
		throw "error";
	if(node != NULL)
	{
	Node* head1 = new Node(d, node->next);
	node->next = head1;
	}
}

void List::Delete(const DataType& d) // удалить звено со значением data = d
{
	Node* temp1 = head;
	Node* temp2 = head;
	if(temp1 != NULL)
	{
	while((temp1->next != NULL) && (temp1->data != d))
	{
		temp2 = temp1;
		temp1 = temp1->next;
	}
	if(temp1->data == d)
	{
	temp2->next = temp1->next;
	if(temp1 == head)
	{
		head = head->next;
	}
	delete temp1;
	}
	}
}

 Node* List::Search(const DataType& d) // найти указатель на звено со значением data = d
 {
	 Node* head1 = head;
	 while((head1 != NULL) && (head1->data != d))
	 {
		 head1 = head1->next;
	 }
	 if(head1 == NULL)
		 return NULL;
	 else
		 return head1;
 }

void List::Clean() // удалить все звенья
   {
	 Node* head1 = head;
	 Node* head2 = head;
	 if(head1 != NULL)
	 {
		 while(head1->next != NULL)
		 {
			 head2 = head1->next;
			 delete head1;
			 head1 = head2;
		 }
		 delete head1;
		 head = NULL;
	 }
   }

int List::GetSize() // узнать число звеньев в списке
{
	int k = 0;
	Node* head1 = head;
	while(head1 != NULL)
	{
		k++;
		head1 = head1->next;
	}
	return k;
}

 Node* List::GetHead() // получить указатель на первое звено списка
 {
	 return head;
 }

void List::Inverse() // инвертировать список, т.е. звенья должны идти в обратном порядке
{
	if(head != NULL)
	{
		Node* head1 = head;
		Node* head2 = NULL;
		Node* head3 = head->next;
		while(head != NULL)
		{
			head3 = head1->next;
			head1->next = head2;
			head2 = head1;
			head1 = head3;
		}
		head = head2;
	}
}

List List::Merge(Node* node, const List& list2) // создать список3, добавив список2 в текущий список после указателя node  
{
	List K;
	if((head == NULL) || (head == node))
	{
		Node* head1 = list2.head;
		while(head1 != NULL)
		{
			K.InserToTail(head1->data);
			head1 = head1->next;
		}
		return K;

	}
	else
	{
		Node* head1 = head;
		while(head1 != node)
		{
			K.InserToTail(head1->data);
			head1 = head1->next;
		}
		if(head1 != NULL)
		{
			K.InserToTail(head1->data);
			Node* head2 = head1->next;
			head1 = list2.head;
			while(head1 != NULL)
			{
				K.InserToTail(head1->data);
				head1 = head1->next;
			}
			head1 = head2;
			while(head1 != NULL)
			{
				K.InserToTail(head1->data);
				head1 = head1->next;
			}
			return K;
		}
		else
		{
			Node* head2 = head1;
			head1 = list2.head;
			while(head1 != NULL)
			{
				K.InserToTail(head1->data);
				head1 = head1->next;
			}
			return K;
		}
	}
}

List List::Merge(const List& list2) // создать список3, добавив в конец текущего списка список2
{
	List K;
	Node* head1 = head;
	while(head1 != NULL)
	{
		K.InserToTail(head1->data);
		head1 = head1->next;
	}
	head1 = list2.head;
	while(head1 != NULL)
	{
		K.InserToTail(head1->data);
		head1 = head1->next;
	}
	return K;
}

ostream& operator<<(ostream& os, const List& l)
{
	Node* head1 = l.head;
	while(head1 != NULL)
	{
		os<<head1->data<<" ";
		head1 = head1->next;
	}
	return os;
}
