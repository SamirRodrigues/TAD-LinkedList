/**
 * @file linkedList.inl
 * @author Samir Rodrigues & Italo Lima (git @SamirRodrigues & @italo-ce)
 * @brief 
 * @version 0.1
 * @date 2020-11-18
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "linkedList.hpp"

namespace ls
{	
	// I SPECIAL MEMBERS

	
	/**
	 * @brief Construct a new list<T>::list object
	 * 
	 * @tparam T 
	 */
	template <typename T>
	list<T>::list(void)
	{
		length = 0;
		head = new Node();
		tail = new Node();
		head->next = tail;
		tail->prev = head;
	}

	/**
	 * @brief Construct a new list<T>::list object
	 * 
	 * @tparam T 
	 * @param ilist 
	 */
	template <typename T>
	list<T>::list( std::initializer_list<T> ilist ): list<T>::list()
	{
		insert(begin(),ilist.begin(),ilist.end());
	}

	/**
	 * @brief Construct a new list<T>::list object
	 * 
	 * @tparam T 
	 * @param count 
	 */
	template <typename T>
	list<T>::list(size_type count): list<T>::list() 
	{
		length = count;
		assign(0);	
	}

	
	/**
	 * @brief Construct a new list<T>::list object
	 * 
	 * @tparam T 
	 * @tparam InputIt 
	 * @param first 
	 * @param last 
	 */
	
	template <class T>
	template <typename InputIt>	
	list<T>::list(InputIt first, InputIt last): list<T>::list() 
	{
		assign(first, last);	
	}
	
	
	/**
	 * @brief Construct a new list<T>::list object
	 * 
	 * @tparam T 
	 * @param other 
	 */
	template <typename T>
	list<T>::list( const list<T> & other ): list<T>::list()
	{
		*this = other;
	} 
	
	/**
	 * @brief Operator=
	 * 
	 * @tparam T 
	 * @param other 
	 * @return list<T>& 
	 */
	template <typename T>
	list<T>& list<T>::operator= ( const list<T> & other )
	{			
		assign(other.cbegin(), other.cend());
		return *this;	
	}

	/**
	 * @brief Operator=
	 * 
	 * @tparam T 
	 * @param ilist 
	 * @return list<T>& 
	 */
	template <typename T>
	list<T>& list<T>::operator= ( std::initializer_list<T> ilist )
	{			
		assign(ilist.begin(), ilist.end());
		return *this;	
	}
	
	/**
	 * @brief Destroy the list<T>::list object
	 * 
	 * @tparam T 
	 */
	template <typename T>
	list<T>::~list()
	{
		clear();
		delete head;
		delete tail;
	}

	// [II] ITERATORS 

	/**
	 * @brief Returns a iterator to the beginning of the list 
	 * 
	 * @tparam T 
	 * @return ls::list<T>::iterator 
	 */
	template <typename T>
	typename ls::list<T>::iterator ls::list<T>::begin()
	{
		return ls::list<T>::iterator(head->next);
	}

	/**
	 * @brief Returns a constant iterator to the beginning of the list 
	 * 
	 * @tparam T 
	 * @return ls::list<T>::const_iterator 
	 */
	template <typename T>
	typename ls::list<T>::const_iterator ls::list<T>::cbegin() const
	{
		return ls::list<T>::const_iterator(head->next);
	}

	/**
	 * @brief Returns a iterator to the end of the list
	 * 
	 * @tparam T 
	 * @return ls::list<T>::iterator 
	 */
	template <typename T>
	typename ls::list<T>::iterator ls::list<T>::end()
	{
		return ls::list<T>::iterator(tail);
	}

	/**
	 * @brief Returns a constant iterator to the end of the list
	 * 
	 * @tparam T 
	 * @return ls::list<T>::const_iterator 
	 */
	template <typename T>
	typename ls::list<T>::const_iterator ls::list<T>::cend() const
	{
		return ls::list<T>::const_iterator(tail);
	}

	/**
	 * @brief Returns a reference to the object in the position who iterator points
	 * 
	 * @tparam T 
	 * @return const T& 
	 */
	template <typename T>		
	const T & list<T>::const_iterator::operator* ( ) const
	{
		return this->current->data;
	}	
	

	/**
	 * @brief Increase the iterator to the next position in list (++it)
	 * 
	 * @tparam T 
	 * @return list<T>::const_iterator& 
	 */
	template <typename T>		
	typename list<T>::const_iterator & list<T>::const_iterator::operator++ ( )
	{	
		this->current = this->current->next;
		return *this;
	}
	
	/**
	 * @brief Increase the iterator to the next position in list (it++)
	 * 
	 * @tparam T 
	 * @return list<T>::const_iterator 
	 */
	template <typename T>		
	typename list<T>::const_iterator list<T>::const_iterator::operator++ ( int )
	{	
		auto temp = *this;	
		this->current = this->current->next;
		return *temp;
	}
	
	/**
	 * @brief Decrease the iterator to the prev position in list (--it)
	 * 
	 * @tparam T 
	 * @return list<T>::const_iterator 
	 */
	template <typename T>
	typename list<T>::const_iterator list<T>::const_iterator::operator--( int )
	{
		auto temp = *this;
		this->current = this->current->prev;

		if (this->current == nullptr){
			throw std::out_of_range("Iterator went out of bounds!");
		}
		return temp;
	}	
	
	/**
	 * @brief Decrease the iterator to the prev position in list (it--)
	 * 
	 * @tparam T 
	 * @return list<T>::const_iterator& 
	 */
	template <typename T>
	typename list<T>::const_iterator & list<T>::const_iterator::operator--( )
	{
		this->current = this->current->prev;

		if (this->current == nullptr)
		{
			throw std::out_of_range("Iterator went out of bounds!");
		}
		return *this;
	}

	// [III] CAPACITY

	/**
	 * @brief Return the number of elements in the list
	 * 
	 * @tparam T 
	 * @return size_type 
	 */
	template <typename T>
	size_type list<T>::size() const 
	{
		return length;
	}

	/**
	 * @brief Check if is the list empty
	 * 
	 * @tparam T 
	 * @return true 
	 * @return false 
	 */
	template <typename T>
	bool list<T>::empty()
	{
		return (head->next == tail and tail->prev == head);
	}

	// [IV] MODIFIERS 

	/**
	 * @brief Clear the lis
	 * 
	 * @tparam T 
	 */
	template <typename T>
	void list<T>::clear()
	{		
		erase(begin(),end());
		length = 0;
	}

	/**
	 * @brief Returns a constant reference to the first element of the list 
	 * 
	 * @tparam T 
	 * @return const T& 
	 */
	template <typename T>
	const T & list<T>::front() const
	{
		if(empty())
			throw std::out_of_range("The list is empty!");
		return head->next->data;
	}

	/**
	 * @brief Returns a constant reference to the last element of the list 
	 * 
	 * @tparam T 
	 * @return const T& 
	 */
	template <typename T>
	const T & list<T>::back() const
	{
		if(empty())
			throw std::out_of_range("The list is empty!");
		return tail->prev->data;
	}

	
	/**
	 * @brief Inserts value before itr position
	 * 
	 * @tparam T 
	 * @param itr 
	 * @param value 
	 * @return list<T>::iterator 
	 */
	template <typename T>
	typename list<T>::iterator list<T>::insert (typename list<T>::iterator itr, const T & value )
	{
		typename list<T>::Node* temp =
			new typename list<T>::Node(value,itr.current->prev,itr.current);
		length++;
		itr.current->prev->next = temp;
		itr.current->prev = temp;
		return temp;
	}	

	/**
	 * @brief Inserts the initializer_list's elements before itr position
	 * 
	 * @tparam T 
	 * @param pos 
	 * @param ilist 
	 * @return list<T>::iterator 
	 */
	template <typename T>
	typename list<T>::iterator list<T>::insert( const_iterator pos, std::initializer_list<T> ilist )
	{			
		list<T>::iterator itr;

		for (auto i = ilist.begin(); i < ilist.end(); ++i) 
		{
			itr = list<T>::insert(pos,*i);	
		}

		if(itr == begin()) { return itr; }

		int size = ilist.size();
		return itr+1-size;
	}
	
	/**
	 * @brief Inserts the elements in the [first,last) range before itr position
	 * 
	 * @tparam T 
	 * @tparam InItr 
	 * @param pos 
	 * @param first 
	 * @param last 
	 * @return list<T>::iterator 
	 */
	template <typename T>
	template <typename InItr>	
	typename list<T>::iterator list<T>::insert(iterator pos, InItr first, InItr last)
	{
		list<T>::iterator itr;
		int size = 0;

		for (auto i = first; i != last; ++i) 
		{
			itr = list<T>::insert(pos,*i);	
			size++;
		}

		if(itr == begin()) {return itr;}

		return itr+1-size;
	}

	/**
	 * @brief Insert a element in the beggining of list
	 * 
	 * @tparam T 
	 * @param value 
	 */
	template <typename T>
	void list<T>::push_front( const T& value )
	{
		Node *push = new Node(value,head,head->next);
		head->next->prev = push;
		head->next = push;
		length++;
	}

	/**
	 * @brief Insert a element in the end of list
	 * 
	 * @tparam T 
	 * @param value 
	 */
	template <typename T>
	void list<T>::push_back( const T & value )
	{
		Node *push = new Node(value,tail->prev,tail);
		tail->prev->next = push;
		tail->prev = push;
		length++;
	}

	/**
	 * @brief Remove a element in the beggining of list
	 * 
	 * @tparam T 
	 */
	template <typename T>	
	void list<T>::pop_front( )
	{
		if(empty()){ throw("pop_front() cannot remove elements from a empty list"); }
		erase(begin());
	}

	/**
	 * @brief Remove a element in the end of list
	 * 
	 * @tparam T 
	 */
	template <typename T>	
	void list<T>::pop_back( )
	{
		if(empty()){ throw std::out_of_range("pop_back() cannot remove elements from a empty list"); }
		erase(ls::list<T>::iterator(tail->prev));
	}

	/**
	 * @brief Returns a reference to the object pointed by iterator
	 * 
	 * @tparam T 
	 * @return T& 
	 */
	template <typename T>
	T & list<T>::iterator::operator* ( )
	{
		return this->current->data;
	}
	
	/**
	 * @brief Increase the iterator to the next position in list (++it)
	 * 
	 * @tparam T 
	 * @return list<T>::iterator& 
	 */
	template <typename T>
	typename list<T>::iterator & list<T>::iterator::operator++( )
	{
		this->current = this->current->next;
		return *this;
	}	
	

	/**
	 * @brief Decrease the iterator to the next position in list (--it)
	 * 
	 * @tparam T 
	 * @return list<T>::iterator& 
	 */
	template <typename T>
	typename list<T>::iterator & list<T>::iterator::operator--( )
	{
		this->current = this->current->prev;
		if (this->current == nullptr){ throw std::out_of_range("Iterator went out of bounds!"); }
		return *this;
	}
	
	/**
	 * @brief Decrease the iterator to the next position in list (it--)
	 * 
	 * @tparam T 
	 * @return list<T>::iterator 
	 */
	template <typename T>
	typename list<T>::iterator list<T>::iterator::operator--( int )
	{
		auto temp = *this;
		this->current = this->current->prev;

		if (this->current == nullptr){ throw std::out_of_range("Iterator went out of bounds!"); }
		return temp;
	}

	/**
	 * @brief Increase the iterator to the next position in list (it++)
	 * 
	 * @tparam T 
	 * @return list<T>::iterator 
	 */
	template <typename T>
	typename list<T>::iterator list<T>::iterator::operator++( int )
	{
		auto temp = *this;
		this->current = this->current->next;
		if (this->current == nullptr){ throw std::out_of_range("Iterator went out of bounds!");	}
		return temp;
	}

	
	/**
	 * @brief Return true if the iterators are reference to diferent parts of list
	 * 
	 * @tparam T 
	 * @param rhs 
	 * @return true 
	 * @return false 
	 */
	template <typename T>
	bool list<T>::const_iterator::operator!= ( const const_iterator & rhs ) const
	{
		return this->current != rhs.current;
	}

	/**
	 * @brief Return true if the iterators are reference to equal parts of list
	 * 
	 * @tparam T 
	 * @param rhs 
	 * @return true 
	 * @return false 
	 */
	template <typename T>
	bool list<T>::const_iterator::operator== ( const const_iterator & rhs ) const
	{
		return this->current == rhs.current;
	}

	/**
	 * @brief Remove a element in param "pos" position
	 * 
	 * @tparam T 
	 * @param pos 
	 * @return list<T>::iterator 
	 */
	template <typename T>
	typename list<T>::iterator list<T>::erase (list<T>::iterator pos)
	{			
		auto ret = list<T>::iterator(pos.current->next); 
		if(pos != end())
		{
		pos.current->next->prev = pos.current->prev;
		pos.current->prev->next = pos.current->next;
		delete pos.current;
		}

		length--;
		return ret;
	}
	

	/**
	 * @brief Remove the elements in the interval [first, last)
	 * 
	 * @tparam T 
	 * @param first 
	 * @param last 
	 * @return list<T>::iterator 
	 */
	template <typename T>
	 typename list<T>::iterator list<T>::erase(list<T>::iterator first, list<T>::iterator last)
	 {		
		list<T>::iterator itr = erase(first);
		while(itr != last)
		{
		itr = erase(itr);
		}
		return itr;
	 }

	/**
	 * @brief Replace the content of the list with copies of the param "value"
	 * 
	 * @tparam T 
	 * @param value 
	 */
	template <typename T>
	void list<T>::assign(const T& value )
	{		
		for (int i = 0; i < (int)length; ++i)
		{
			list<T>::insert(list<T>::begin(),value);
		}
	}

	/**
	 * @brief Replace the content of the list with copies of elements in the range [first, last)
	 * 
	 * @tparam T 
	 * @tparam InItr 
	 * @param first 
	 * @param last 
	 */
	template <typename T>
	template <typename InItr >
	void list<T>::assign( InItr first, InItr last )
	{
		if(length != 0) { list<T>::clear(); } 
		
		insert(begin(),first,last);
	} 

	/**
	 * @brief Replace the content of the list with a initializer list
	 * 
	 * @tparam T 
	 * @param ilist 
	 */
	template <typename T>
	void list<T>::assign( std::initializer_list<T> ilist ){

		if(length != 0) { list<T>::clear(); }

		insert(begin(),ilist.begin(),ilist.end());
	}
	
	/**
	 * @brief List Operator ==
	 * 
	 * @tparam T 
	 * @param lhs 
	 * @param rhs 
	 * @return true 
	 * @return false 
	 */
	template <typename T>
	bool operator==(const list<T> & lhs, const list<T>& rhs)
	{
		if(lhs.size() != rhs.size()) { return false; }
		
		auto ritr = rhs.cbegin();
		for (auto itr = lhs.cbegin(); itr != lhs.cend(); ++itr, ++ritr) 
		{
			if(*itr != *ritr) { return false; }
		}
		return true;
	}
	
	/**
	 * @brief List Operator !=
	 * 
	 * @tparam T 
	 * @param lhs 
	 * @param rhs 
	 * @return true 
	 * @return false 
	 */
	template <typename T>
	bool operator!=(const list<T> & lhs,const list<T>& rhs)
	{
		if(lhs.size() != rhs.size()) { return true; }
		
		auto ritr = rhs.cbegin();
		for (auto itr = lhs.cbegin(); itr != lhs.cend(); ++itr, ++ritr) 
		{
			if(*itr != *ritr) { return true; }
		}
		return false;
	}

	/**
	 * @brief Operator+
	 * 
	 * @tparam T 
	 * @param a 
	 * @return list<T>::iterator 
	 */
	template <typename T>
	typename list<T>::iterator list<T>::iterator::operator+ (int a){
	
		auto copy = *this;
		for (int i = 0; i < a; ++i) {
			
			if (copy.current == nullptr){
				throw std::out_of_range("Iterator went out of bounds!");
			}
			copy.current = copy.current->next;
			
		}
		return copy;
	}

	/**
	 * @brief Operator-
	 * 
	 * @tparam T 
	 * @param a 
	 * @return list<T>::iterator 
	 */
	template <typename T>
	typename list<T>::iterator list<T>::iterator::operator- (int a){
		
		auto copy = *this;
		for (int i = 0; i < a; ++i) {
			
			if (copy.current == nullptr){
				throw std::out_of_range("Iterator went out of bounds!");
			}
			copy.current = copy.current->prev;
			
		}
		return copy;
	}

	/**
	 * @brief Operator-
	 * 
	 * @tparam T 
	 * @param a 
	 * @return list<T>::const_iterator& 
	 */
	template <typename T>
	typename list<T>::const_iterator & list<T>::const_iterator::operator- (int a){

		for (int i = 0; i < a; ++i) {
			
			if (this->current == nullptr){
				throw std::out_of_range("Iterator went out of bounds!");
			}
			this->current = this->current->prev;
			
		}
		return *this;
	}
}