#ifndef Stack_CPP
#define Stack_CPP

#include "Stack.hpp"
// Constructors
template <typename T>
Stack<T>::Stack() 
{ 
	// Default constructor.
}
template <typename T>
Stack<T>::Stack(int size) : m_current(0), m_array(size)
{
}
template <typename T>
Stack<T>::Stack(const Stack<T>& pt) : m_current(pt.m_current), m_array(pt.m_array)
{ 
	// Copy constructor
}
template <typename T>
Stack<T>::~Stack()
{ 
	// Destructor
}
template <typename T>
Stack<T>& Stack<T>::operator = (const Stack<T>& source)
{
	// Assignment operator
	if (this == &source)
	{
		return *this;
	}
	m_current = source.m_current;
	m_array = source.m_array;
}

template <typename T>
T& Stack<T>::Pop()
{
	if (m_current < 1)
	{
		return m_array[m_current];
	}
	else
	{
		m_current--;
		return m_array[m_current];
	}
}
template <typename T>
void Stack<T>::Push(const T& newT)
{
	m_array[m_current] = newT;
	m_current++;
}

#endif







