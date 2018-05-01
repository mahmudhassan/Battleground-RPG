#pragma once

#include "Node.h"

/**********************************************************************
* Class: LinkedList
*
* Purpose: This class will create a list of objects of any type.
*
* Manager functions:
*		LinkedList()
*				This function is the default constructor for the
*				LinkedList class.
*
*		LinkedList(Node * head)
*				This function is the one argument constructor for the
*				LinkedList class.
*
*		LinkedList(const LinkedList & copy)
*				This function is the one copy constructor for the
*				LinkedList class.
*
*		~LinkedList();
*				This function is the destructor for the LinkedList
*				class.
*
* Methods:
*		LinkedList & operator=(const LinkedList & rhs)
*				This function is the operator = manager for the LinkedList
*				class.
*
*		Node * CreateNode(Potion age)
*				This function creates a node to be used by the LinkedList
*				object that it is called from.
*
*		void PushFront(Node * new_node)
*				Places a Node object at the front of a LinkedList.
*
*		void PushBack(Node * new_node)
*				Places a Node object at the back of a LinkedList.
*
*		Potion PopFront()
*				Removes a Node object at the front of a LinkedList and
*				returns its value.
*
*		Potion PopBack()
*				Removes a Node object at the back of a LinkedList and
*				returns its value.
*
*		Potion Front()
*				Returns the value of Node object at the front of
*				a LinkedList.
*
*		Potion Back()
*				Returns the value of Node object at the back of
*				a LinkedList.
*
*		Potion GetIthElement(int node_num)
*				Returns the value of Node object at a specified
*				location of a LinkedList.
*
*		int GetNumNodes()
*				Returns an int describing the number of nodes in a list.
*
*		void Purge()
*				Deletes all the data in a LinkedList.
*
************************************************************************/
template <typename T>
class LinkedList
{
	public:
		LinkedList();
		LinkedList(const LinkedList<T> & copy);
		~LinkedList();
		LinkedList<T> & operator = (const LinkedList<T> & rhs);
		Node<T> * CreateNode(T data);
		void CreatePushFront(T data);
		void CreatePushBack(T data);
		void PushFront(Node<T> * new_node);
		void PushBack(Node<T> * new_node);
		T PopFront();
		T PopBack();
		T Front();
		T Back();
		T & GetIthElement(int node_num);
		void SetIthElement(int node_num, T data);
		int GetNumNodes();
		void Swap(int position);
		void Purge();
		void PtrPurge();

	private:
		Node<T> * m_head;
};


/**********************************************************************
* Purpose: This function is the default constructor for the LinkedList
*			class.
*
* Precondition:
*		Declaration of a LinkedList type object with out arguments.
*
* Postcondition:
*		Modifies the values of m_head
*
************************************************************************/
template <typename T>
LinkedList<T>::LinkedList() : m_head(nullptr)
{ }

/**********************************************************************
* Purpose: This function is the one copy constructor for the
*			LinkedList class.
*
* Precondition:
*		Declaration of a LinkedList type object with one argument. The
*		argument must be an already declared LinkedList object.
*
* Postcondition:
*		Modifies the values of m_head
*
************************************************************************/
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> & copy) : m_head(nullptr)
{
	*this = copy;
}

/**********************************************************************
* Purpose: This function is the destructor for the LinkedList
*			class.
*
* Precondition:
*		LinkedList type object goes out of scope.
*
* Postcondition:
*		Deletes the memory allocated for the m_head data member and the
*		trailing nodes.
*
************************************************************************/
template <typename T>
LinkedList<T>::~LinkedList()
{
	Purge();
	m_head = nullptr;
}

/**********************************************************************
* Purpose: This function is the operator = manager for the LinkedList
*			class.
*
* Precondition:
*		Two LinkedList type objects that are already initialized
*		placed on both the right and left side of the statement.
*
* Postcondition:
*		Modifies the values of the invoked object data members to that
*		of the object passed. As well as deleting the current data member
*		values on the left hand side.
*
************************************************************************/
template <typename T>
LinkedList<T> & LinkedList<T>::operator = (const LinkedList<T> & rhs)
{
	if (this != &rhs)
	{
		Purge();

		Node<T> * travel = rhs.m_head;

		while (travel != nullptr)
		{
			PushBack(CreateNode(travel->m_values));
			travel = travel->m_nxt;
		}
	}

	return *this;
}

/**********************************************************************
* Purpose: This function creates a node to be used by the LinkedList
*		object that it is called from.
*
* Precondition:
*		Must be passed the data that will be used to initialize the
*		object.
*
* Postcondition:
*		Returns a Node type object that will contain the data passed
*		to the function as well as pointer to another node.
*
************************************************************************/
template<typename T>
Node<T> * LinkedList<T>::CreateNode(T data)
{
	Node<T> * new_node = new Node<T>;

	new_node->m_values = data;
	new_node->m_nxt = nullptr;

	return new_node;
}

/**********************************************************************
* Purpose: This function creates a node to be used by the LinkedList
*		object that it is called from.
*
* Precondition:
*		Must be passed the data that will be used to initialize the
*		object.
*
* Postcondition:
*		Returns a Node type object that will contain the data passed
*		to the function as well as pointer to another node.
*
************************************************************************/
template<typename T>
void LinkedList<T>::CreatePushFront(T data)
{
	Node<T> * new_node = CreateNode(data);
	PushFront(new_node);
}

/**********************************************************************
*																	  *
**********************************************************************/
template<typename T>
void LinkedList<T>::CreatePushBack(T data)
{
	Node<T> * new_node = CreateNode(data);
	PushBack(new_node);
}

/**********************************************************************
* Purpose: Places a Node object at the front of a LinkedList.
*
* Precondition:
*		Must be passed a Node pointer.
*
* Postcondition:
*		Returns nothing sets Node at front of a LinkedList object.
*
************************************************************************/
template <typename T>
void LinkedList<T>::PushFront(Node<T> * new_node)
{
	new_node->m_nxt = m_head;
	m_head = new_node;
}

/**********************************************************************
* Purpose: Places a Node object at the back of a LinkedList.
*
* Precondition:
*		Must be passed a Node pointer.
*
* Postcondition:
*		Returns nothing sets Node at back of a LinkedList object.
*
************************************************************************/
template <typename T>
void LinkedList<T>::PushBack(Node<T> * new_node)
{
	Node<T> * travel = m_head;

	if (m_head == nullptr)
		m_head = new_node;
	else
	{
		while (travel->m_nxt != nullptr)
			travel = travel->m_nxt;

		travel->m_nxt = new_node;
	}
}

/**********************************************************************
* Purpose: Removes a Node object at the front of a LinkedList and
*		returns its value.
*
* Precondition:
*		LinkedList must exist.
*
* Postcondition:
*		Returns data that was contained in the removed node.
*
************************************************************************/
template <typename T>
T LinkedList<T>::PopFront()
{
	if (m_head == nullptr)
		throw - 1;

	Node<T> * temp_ptr = m_head;
	T temp = m_head->m_values;
	
	m_head = m_head->m_nxt;
	delete temp_ptr;

	return temp;
}

/**********************************************************************
* Purpose: Removes a Node object at the back of a LinkedList and
*		returns its value.
*
* Precondition:
*		LinkedList must exist.
*
* Postcondition:
*		Returns data that was contained in the removed node.
*
************************************************************************/
template <typename T>
T LinkedList<T>::PopBack()
{
	if (m_head == nullptr)
		throw - 1;

	Node<T> * tail_previous = nullptr;
	Node<T> * tail = nullptr;
	T temp;

	tail_previous = m_head;
	tail = m_head->m_nxt;

	while (tail->m_nxt != nullptr)
	{
		tail_previous = tail;
		tail = tail->m_nxt;
	}

	temp = tail->m_values;

	delete tail;
	tail_previous->m_nxt = nullptr;

	return temp;
}

/**********************************************************************
* Purpose: Returns the value of Node object at the front of
*		a LinkedList.
*
* Precondition:
*		LinkedList must exist.
*
* Postcondition:
*		Returns data that was contained in the first Node.
*
************************************************************************/
template <typename T>
T LinkedList<T>::Front()
{
	if (m_head == nullptr)
		throw - 1;

	return m_head->m_values;;
}

/**********************************************************************
* Purpose: Returns the value of Node object at the back of
*		a LinkedList.
*
* Precondition:
*		LinkedList must exist.
*
* Postcondition:
*		Returns data that was contained in the last Node.
*
************************************************************************/
template <typename T>
T LinkedList<T>::Back()
{
	if (m_head == nullptr)
		throw - 1;

	Node<T> * travel = m_head;

	if (m_head != nullptr)
		while (travel->m_nxt != nullptr)
			travel = travel->m_nxt;

	return travel->m_values;;
}

/**********************************************************************
* Purpose: Returns the value of Node object at a specified location of
*		a LinkedList.
*
* Precondition:
*		LinkedList must exist. Must pass an int the describes the
*		location on the list to search for.
*
* Postcondition:
*		Returns data that was contained in the discovered Node.
*
************************************************************************/
template <typename T>
T & LinkedList<T>::GetIthElement(int node_num)
{
	Node<T> * travel = m_head;

	if (m_head != nullptr)
		for (int i = 0; i < node_num; ++i)
			travel = travel->m_nxt;

	return travel->m_values;
}

/**********************************************************************
* Purpose: Sets the value of a link at position X.
*
* Precondition:
*		Passed an int and data corresponding to a link.
*
* Postcondition:
*		Modifies the value of the link at position X.
*
************************************************************************/
template <typename T>
void LinkedList<T>::SetIthElement(int node_num, T data)
{
	Node<T> * travel = m_head;

	if (m_head != nullptr)
	{
		for (int i = 0; i < node_num; ++i)
			travel = travel->m_nxt;

		travel->m_values = data;
	}
}

/**********************************************************************
* Purpose: Returns an int describing the number of nodes in a list.
*
* Precondition:
*		LinkedList must exist.
*
* Postcondition:
*		Returns int equal to the number of nodes in the list.
*
************************************************************************/
template <typename T>
int LinkedList<T>::GetNumNodes()
{
	Node<T> * travel = m_head;
	int node_count = 0;

	if (travel != nullptr)
	{
		++node_count;

		while (travel->m_nxt != nullptr)
		{
			++node_count;
			travel = travel->m_nxt;
		}
	}

	return node_count;
}

/**********************************************************************
* Purpose: Swap a links value at position X with the head links value.
*
* Precondition:
*		Passed an int.
*
* Postcondition:
*		Modifies the values of m_head and link at position X.
*
************************************************************************/
template <typename T>
void LinkedList<T>::Swap(int position)
{
	Node<T> * travel = m_head;
	T temp;

	for (int i = 0; i < position; ++i)
		travel = travel->m_nxt;

	temp = m_head->m_values;
	m_head->m_values = travel->m_values;
	travel->m_values = temp;
}

/**********************************************************************
* Purpose: Deletes all the data in a LinkedList.
*
* Precondition:
*		LinkedList must exist.
*
* Postcondition:
*		There are no post conditions.
*
************************************************************************/
template <typename T>
void LinkedList<T>::Purge()
{
	Node<T> * trail = nullptr;

	while (m_head != nullptr)
	{
		trail = m_head;
		m_head = m_head->m_nxt;
		
		delete trail;
	}
}

/**********************************************************************
*																	  *
**********************************************************************/
template <typename T>
void LinkedList<T>::PtrPurge()
{
	Node<T> * trail = nullptr;

	while (m_head != nullptr)
	{
		trail = m_head;
		m_head = m_head->m_nxt;
		delete trail->m_values;
		delete trail;
	}
}
