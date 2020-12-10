/**
 * @file linkedList.hpp
 * @author Samir Rodrigues & Italo Lima (git @SamirRodrigues & @italo-ce)
 * @brief 
 * @version 0.1
 * @date 2020-11-18
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef LIST_H_
#define LIST_H_
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iterator> 

using size_type = size_t;

namespace ls
{
	template <typename T>
	class list
	{
		private:
		struct Node {
			T data;
			Node *prev;
			Node *next;
			Node( T d = T () , Node *p = nullptr, Node *n = nullptr):data (d),prev (p), next (n){}
		};
		
		size_type length;
		Node *head;
		Node *tail;

		public:

		
		class const_iterator
		{
			public:
				const_iterator( ) = default;
				T & operator* ( );
				const_iterator & operator ++ ( );		// ++it;
				const_iterator operator ++ ( int ); 	// it++;
				const_iterator & operator -- ( ); 		// --it;
				const_iterator operator -- ( int ); 	// it--;
				const_iterator & operator- (int );
				bool operator == ( const const_iterator & rhs ) const;
				bool operator != ( const const_iterator & rhs ) const;
			
			protected :
				Node *current;
				const_iterator( Node * p ) : current( p ){}
				friend class list<T>;			
		};


		class iterator : public const_iterator {
			public :
				iterator( ) : const_iterator() { /* Empty */ }
				//T & operator * ( ) const;
				T & operator * ( );
			
				iterator & operator++ ();
				iterator operator++ (int);
				iterator  operator+ (int);
				iterator & operator-- ();
				iterator operator-- (int);
				iterator  operator- (int );
		
			protected :
				iterator( Node *p ) : const_iterator( p ){}
				friend class list<T>;
		};

		// [I] SPECIAL MEMBERS

		list(void);
		explicit list(size_type count);		
		template <typename InputIt>
		list(InputIt first, InputIt last);
		list( const list& );				
		list( std::initializer_list<T> ilist );
		~list( );	
		list & operator= ( const list & );
		list & operator= ( std::initializer_list<T> ilist );		 
		
		// [II] ITERATORS
	
		iterator begin();	
		const_iterator cbegin( ) const;				
		iterator end( );	
		const_iterator cend( ) const;

		// [III] Capacity 
				
		size_type size( ) const;		
		bool empty( );
			
		// [IV] Modifiers
		
		void clear( );
		void push_front( const T & value );					
		void push_back( const T & value );		
		void pop_front( );				
		void pop_back( );			
		const T & back( ) const;				
		const T & front( ) const;	
		void assign ( size_type count, const T& value );
			
		// [IV-a] Modifiers with iterators
	
		template < typename InputIt >
		void assign( InputIt first, InputIt last );

		void assign( std::initializer_list<T> ilist );
		iterator insert( iterator itr, const T & value );
		iterator insert( iterator pos, std::initializer_list<T> ilist );
		
		template <typename InItr>	
		iterator insert(iterator pos, InItr first, InItr last);	
		iterator erase( iterator pos );
		iterator erase( iterator first, iterator last );
		
		
		
	};
	template <typename T>
	bool operator==(const list<T>& lhs,const list<T>& rhs);	
	template <typename T>	
	bool operator!=(const list<T>& lhs,const list<T>& rhs);

}

#include "linkedList.inl"
#endif