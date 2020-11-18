#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <iostream>

using size_type = size_t;
using value_type = int;

namespace ls
{
	template <class T>
	class list
	{
		private:
			struct Node 
			{
				T data;
				Node *prev;
				Node *next;
				Node( T d = T(), Node *p = nullptr, Node *n = nullptr ):
				data(d), prev(p), next(n)
				{

				}
			};

			size_type length;			
			Node *head;			
			Node *tail;		
				
		
		public:
			class const_iterator
			{
				public:
					const_iterator() = default;

					const T &operator*() const;

					const_iterator &operator++();

					const_iterator operator++( value_type );

					const_iterator &operator--();

					const_iterator operator--( value_type );

					const_iterator &operator-( value_type );

					const_iterator &operator+( value_type );

					bool operator==( const const_iterator & ) const;

					bool operator!=( const const_iterator & ) const;

				protected:
					Node *current;

					const_iterator( Node *p ): current(p){}

					friend class list<T>;
			};

			class iterator: public const_iterator
			{
				public:

					iterator() : const_iterator(){}

					T &operator*();

					iterator &operator++();

					iterator operator++( value_type );

					iterator &operator--();

					iterator operator--( value_type );

					iterator &operator-( value_type );

					iterator &operator+( value_type );

					bool operator==( const iterator & ) const;

					bool operator!=( const iterator & ) const;


				protected:
					iterator( Node *p ): 
					const_iterator(p) 
					{

					}

					friend class list<T>;
			};

			iterator begin();
			iterator end();
			const_iterator cbegin() const;
			const_iterator cend() const;
			void init();
			list();
			explicit list( size_type count );
			template <class InitIt>
			list( InitIt first, InitIt last );
			list( const list &other );
			list( std::initializer_list<T> ilist );
			~list(  );
			list &operator=( const list &other );
			list &operator=( std::initializer_list<T> ilist );
			size_type size(  ) const;	
			void clear(  );
			bool empty(  );
			void push_front( const T &value );
			void push_back( const T &value );
			void pop_back(  );
			void pop_front(  );
			const T &back(  ) const;
			const T &front(  ) const;
			void assign( const T &value );
			bool operator==( const list &rhs );
			bool operator!=( const list &rhs );
			iterator insert( list::iterator, const T & );
			template <class InitIt>
			iterator insert( list::iterator, InitIt, InitIt );
			iterator insert( list::const_iterator , std::initializer_list<T> );
			iterator erase( list::iterator );
			iterator erase( list::iterator, list::iterator );
			void assign( T, T );
			void assign( std::initializer_list<T> );
	};
}

#include "linkedList.inl"
#endif // __LINKEDLIST_H__