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
	class list{
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
				const T & operator * ( ) const;
				const_iterator & operator ++ ( );		// ++it;
				const_iterator operator ++ ( int ); 	// it++;
				const_iterator & operator -- ( ); 		// --it;
				const_iterator operator -- ( int ); 	// it--;
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
				const T & operator * ( ) const;
				T & operator * ( );
			
				iterator & operator++ ();
				iterator operator++ (int);
				iterator & operator-- ();
				iterator operator-- (int);
		
			protected :
				iterator( Node *p ) : const_iterator( p ){}
				friend class list<T>;
		};

		// [I] SPECIAL MEMBERS

		list(void);
		~list( );	
		list( std::initializer_list<T> ilist );
		explicit list(size_type count);		
		list( const list& );				
		list & operator= ( const list & );		 
		
		// [II] ITERATORS
	
		iterator begin();	
		const_iterator begin( ) const;				
		iterator end( );	
		const_iterator end( ) const;

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
		void assign( const T& value );
			
		// [IV-a] Modifiers with iterators

		template < class InItr >
		void assign( InItr first, InItr last );

		void assign( std::initializer_list<T> ilist );
		iterator insert( iterator itr, const T & value );
		iterator insert( const_iterator pos, std::initializer_list<T> ilist );
		
		template <typename InItr>	
		iterator insert(iterator pos, InItr first, InItr last);	
		iterator erase( iterator pos );
		iterator erase( iterator first, iterator last );

		const_iterator find( const T & value ) const;
		
};
	template <typename T>
	bool operator==(const list<T>& lhs,const list<T>& rhs);
	template <typename T>
	bool operator!=(const list<T>& lhs,const list<T>& rhs);

}

#include "linkedList.inl"
#endif