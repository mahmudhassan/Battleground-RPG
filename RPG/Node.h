#pragma once

/**********************************************************************
* Class: Node
*
* Purpose:	Holds data and a pointer.
*
* Manager functions:
*		Node()
*			This function is the default constructor for the Node class.
*
*		Node(Potion values)
*			This function is the one argument constructor for the
*			Node class.
*
*		~Node()
*			This function is the destructor for the Node
*			class.
* Methods:
*		N/A
*
************************************************************************/

template<typename T>
class Node
{
	template<typename T>
	friend class LinkedList;

	Node();
	Node(T values);
	Node(T * values);
	~Node();

	T m_values;
	Node<T> * m_nxt;
};


/**********************************************************************
* Purpose: This function is the default constructor for the Node class.
*
* Precondition:
*		Instantiation of a Node type object with out any parameters.
*
* Postcondition:
*		Modifies the values of m_nxt and m_values to their default
*		setting.
*
************************************************************************/
template <typename T>
Node<T>::Node() : m_values(), m_nxt(nullptr)
{ }

/**********************************************************************
* Purpose: This function is the one argument constructor for the
*		Node class.
*
* Precondition:
*		Instantiation of a Node type object with one any parameters.
*		The parameter must be a Potion type object.
*
* Postcondition:
*		Modifies the values of m_nxt to its default setting. Sets the
*		value of m_values to the Potion objects data.
*
************************************************************************/
template <typename T>
Node<T>::Node(T values) : m_values(values), m_nxt(nullptr)
{ }

/**********************************************************************
* Purpose: 
*
* Precondition:
*		
*
* Postcondition:
*		
*
************************************************************************/
template <typename T>
Node<T>::Node(T * values)
{
	m_values = new T;
	m_values = values;
}

/**********************************************************************
* Purpose: This function is the destructor for the Node
*			class.
*
* Precondition:
*		Node type object goes out of scope.
*
* Postcondition:
*		There is not post condition.
*
************************************************************************/
template <typename T>
Node<T>::~Node()
{
	m_nxt = nullptr;
}
