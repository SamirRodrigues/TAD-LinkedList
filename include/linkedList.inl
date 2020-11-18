#include "linkedList.hpp"

namespace ls
{  
    // TODO: Make const_iterator a real const_iterator
	template <class T>
	const T &list<T>::const_iterator::operator*() const
	{
		return this->current->data;
	}

	template <class T>
	typename list<T>::const_iterator &list<T>::const_iterator::operator++()
	{
		this->current = this->current->next;
		return *this;
	}
	template <class T>
	typename list<T>::const_iterator list<T>::const_iterator::operator++( value_type )
	{
		auto copy = *this;
		this->current = this->current->next;
		return copy;
	}

	template <class T>
	typename list<T>::const_iterator &list<T>::const_iterator::operator--()
	{
		this->current = this->current->prev;
		return *this;
	}

	template <class T>
	typename list<T>::const_iterator list<T>::const_iterator::operator--( value_type )
	{
		auto copy = *this;
		this->current = this->current->prev;
		return copy;
	}

	template <class T>
	typename list<T>::const_iterator &list<T>::const_iterator::operator+( value_type add )
	{
		for( int i = 0; i < add; ++i ){
			if( this->current == nullptr ){
				// TODO: Throw exp
			}
			this->current = this->current->next;
		}
		return *this;
	}

	template <class T>
	typename list<T>::const_iterator &list<T>::const_iterator::operator-( value_type sub )
	{
		for( int i = 0; i < sub; ++i ){
			if( this->current == nullptr ){
				// TODO: Throw exp
			}
			this->current = this->current->prev;
		}
		return *this;
	}

	template <class T>
	bool list<T>::const_iterator::operator==( const const_iterator &rhs ) const
	{
		return this->current == rhs.current;
	}

	template <class T>
	bool list<T>::const_iterator::operator!=( const const_iterator &rhs ) const
	{
		return this->current != rhs.current;
	}
	template <class T>
	T &list<T>::iterator::operator*()
	{
		return this->current->data;
	}

	template <class T>
	typename list<T>::iterator &list<T>::iterator::operator++()
	{
		this->current = this->current->next;
		return *this;
	}

	template <class T>
	typename list<T>::iterator list<T>::iterator::operator++( value_type )
	{
		auto copy = *this;
		this->current = this->current->next;
		return copy;
	}

	template <class T>
	typename list<T>::iterator &list<T>::iterator::operator--()
	{
		this->current = this->current->prev;
		return *this;
	}

	template <class T>
	typename list<T>::iterator list<T>::iterator::operator--( value_type )
	{
		auto copy = *this;
		this->current = this->current->prev;
		return copy;
	}

	template <class T>
	typename list<T>::iterator &list<T>::iterator::operator+( value_type add )
	{
		for( int i = 0; i < add; ++i ){
			if( this->current == nullptr ){
				// TODO: Throw exp
			}
			this->current = this->current->next;
		}
		return *this;
	}

	template <class T>
	typename list<T>::iterator &list<T>::iterator::operator-( value_type sub )
	{
		for( int i = 0; i < sub; ++i ){
			if( this->current == nullptr ){
				// TODO: Throw exp
			}
			this->current = this->current->prev;
		}
		return *this;
	}

	template <class T>
	bool list<T>::iterator::operator==( const iterator &rhs ) const
	{
		return this->current == rhs.current;
	}

	template <class T>
	bool list<T>::iterator::operator!=( const iterator &rhs ) const
	{
		return this->current != rhs.current;
	}

//=============================================================================

	template <class T>
	typename list<T>::iterator list<T>::begin()
	{
		return list<T>::iterator(this->head->next);
	}
		
	template <class T>
	typename list<T>::iterator list<T>::end()
	{
		return list<T>::iterator(this->tail);
	}
		
	template <class T>
	typename list<T>::const_iterator list<T>::cbegin() const
	{
		return list<T>::const_iterator(this->head->next);
	}
		
	template <class T>
	typename list<T>::const_iterator list<T>::cend() const
	{
		
		return list<T>::const_iterator(this->tail);
	}
	template <class T>
	void list<T>::init()
	{
		this->length = 0;
		this->head = new Node();
		this->tail = new Node();
		this->head->next = tail;
		this->tail->prev = head;
	 }

	template <class T>
	list<T>::list()
	{
		init();
	}
	
	template <class T>
	list<T>::list( size_type count )
	{
		init();
		for( auto i = 0; i < count; i++ ){
			push_back(0);
		}
	}
	
	template <class T>
	template <class InitIt>
	list<T>::list( InitIt first, InitIt last )
	{
		init();
		insert( begin(), first, last );
	}
	
	template <class T>
	list<T>::list( const list &other )
	{
		init();
		for( auto i = other.cbegin(); i != other.cend(); i++ ){
			push_back(*i);
		}
	}
	
	template <class T>
	list<T>::list( std::initializer_list<T> ilist )
	{
		init();
		for( auto &i : ilist ){
			push_back(i);
		}
	}
	
	template <class T>
	list<T>::~list()
	{
		Node *temp = this->head;	
		while( temp != this->tail ){
			temp = temp->next;
			if(temp->prev != this->head){
				delete temp->prev;
			}
		}

		delete this->head;
		delete this->tail;
	}
	
	template <class T>
	list<T> &list<T>::operator=( const list &other )
	{
		if( this->length != 0 ){
			clear();
			init();
		}

		for( auto i = other.cbegin(); i != other.cend(); i++ ){
			push_back(*i);
		}

		return *this;
	}

	template <class T>
	list<T> &list<T>::operator=( std::initializer_list<T> ilist ){
		if( this->length != 0 )
		{
			clear();
			init();
		}

		for( auto &i : ilist )
		{
			push_back(i);
		}

		return *this;
	}
	template <class T>
	size_type list<T>::size() const
	{
		return this->length;
	}

	template <class T>
	void list<T>::clear()
	{
		erase(begin(), end());
		this->length = 0;
	}

	template <class T>
	bool list<T>::empty()
	{
		bool cond1 = this->head->next == this->tail;
		bool cond2 = this->tail->prev == this->head;
		return cond1 and cond2;
	}

	template <class T>
	void list<T>::push_front( const T &value )
	{		
		Node *push = new Node(value, this->head, this->head->next);
		this->head->next->prev = push;
		this->head->next = push;
		this->length++;
	}

	template <class T>
	void list<T>::push_back( const T &value )
	{
		Node *push = new Node(value, this->tail->prev, this->tail);
		this->tail->prev->next = push;
		this->tail->prev = push;
		this->length++;
	}

	template <class T>
	void list<T>::pop_back()
	{
		erase( this->head->next );
	}

	template <class T>
	void list<T>::pop_front()
	{
		erase( this->tail->prev );
	}

	template <class T>
	const T &list<T>::back() const
	{		
		return this->tail->prev->data;
	}

	template <class T>
	const T &list<T>::front() const
	{
		return this->head->next->data;
	}

	template <class T>
	void list<T>::assign( const T &value )
	{
		for( auto i = begin(); i != end(); i++ ){
			*i = value;
		}	
	}

	template <class T>
	bool list<T>::operator==( const list &rhs )
	{
		if( this->length != rhs.length ) return false;

		for( int i = 0; i < length; i++ )
		{
			if( *(cbegin() + i) != *(rhs.cbegin() + i) ) return false;
		}

		return true;
	}
	template <class T>
	bool list<T>::operator!=( const list &rhs )
	{
		if ((*this) == rhs) return false;
		return true;
	}

	template <class T>
	typename list<T>::iterator list<T>::insert(	list<T>::iterator pos, const T &value )
	{
		typename list<T>::Node* inserted =
			new typename list<T>::Node(value, pos.current->prev, pos.current);
		length++;
		pos.current->prev->next = inserted;
		pos.current->prev = inserted;
		return inserted;
	}

	template <class T>
	template <class InitIt>
	typename list<T>::iterator list<T>::insert(	list<T>::iterator pos, InitIt first, InitIt last )
	{
		list<T>::iterator itr(pos);		
		unsigned long int count = 0;

		for( auto i = first; i != last; ++i ){
			itr = list<T>::insert(pos, *i);
			count++;
		}

		if( itr == begin() ){
			return itr;
		} else {
			return itr - count + 1;
		}
	}

	template <class T>
	typename list<T>::iterator list<T>::insert(	list<T>::const_iterator pos, std::initializer_list<T> ilist )
	{
		list<T>::iterator itr;	

		for( auto i = ilist.begin(); i < ilist.end(); ++i ){
			itr = list<T>::insert(pos, *i);
		}

		if( itr == begin() ){
			return itr;
		} else {
			return itr - ilist.size() + 1;
		}
	}

	template <class T>
	typename list<T>::iterator list<T>::erase( list::iterator pos )
	{
		auto ret = list<T>::iterator(pos.current->next);

		if( pos != end() ){
			pos.current->next->prev = pos.current->prev;
			pos.current->prev->next = pos.current->next;
			delete pos.current;
		}
		length--;

		return ret;
	}

	template <class T>
	typename list<T>::iterator list<T>::erase( list<T>::iterator first, list<T>::iterator last )
	{
		list<T>::iterator itr = erase(first);

		while( itr != last ){
			itr = erase(itr);
		}

		return itr;
	}

	template <class T>
	void list<T>::assign( T first, T last )
	{
		if( this->length != 0 )
			list<T>::clear();

		insert(begin(), first, last);
	}

	template <class T>
	void list<T>::assign( std::initializer_list<T> ilist )
	{	
		if( this->length != 0 )
			list<T>::clear();	

		insert(begin(), ilist.begin(), ilist.end());
	}
}