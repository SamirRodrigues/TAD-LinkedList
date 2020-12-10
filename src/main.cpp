#include <iostream>
#include <random>
#include <chrono>

#include "../include/tam.hpp"
#include "../include/linkedList.hpp"


namespace client
{
	template <class T>
	void print_it( ls::list<T> &l, char sep )
	{
		std::cout << "{ ";
		for( auto it = l.begin(); it != l.end(); it++ ){
			std::cout << *it << sep;
		}
		std::cout << "}";
		std::cout << std::endl;
	}

	// Populate a given array with random values between [0, 300).
	template <class T>
	void populate( ls::list<T> &l ){
		for( auto it = l.begin(); it != l.end(); it++ ){
			auto seed = 
				std::chrono::system_clock::now().time_since_epoch().count();
			std::mt19937 rd (seed);
			auto num = rd() % 300;
			l.push_back(num);
		}
	}
}


int main(int argc, char *argv[])
{
	

	// Special members tests 
	{
		tam::title("Special members tests"); std::cout << std::endl;

		{
			tam::bold("Empty constructor"); std::cout << std::endl;
			
			// Declaration
			ls::list<int> EmptyList;
			std::cout << "EmptyList object created!\n";

			// Populating
			std::cout << "Populating EmptyList with push_back()...\n";
			for( size_t i = 0; i < 10; i++ )
			{
				EmptyList.push_back(i);
			}

			// Simple print the object
			std::cout << "EmptyVector elements: ";
			client::print_it(EmptyList, ' ');
		}

		{
			tam::bold("Constructor with pre-defined size"); std::cout << std::endl;

			// Declaration
			std::cout << "ls::list<int> SizeList(10);\n";
			ls::list<int> SizeList(10);
			
			// Populating
			std::cout << "Populating SizeList with push_back()...\n";
			for( size_t i = 0; i < 10; i++ )
			{
				SizeList.push_back(i);
			}

			// Simple print the object
			std::cout << "SizeList elements: ";
			client::print_it( SizeList, ' ' );
		}
		
		{
			tam::bold("Copy constructor from a simple array"); std::cout << std::endl;

			// Declaration
			int Vet[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
			std::cout << "Copy list elements: ";
			ls::list<int> cList( Vet, Vet+10 );
			client::print_it( cList, ' ' );
		}
		
		{
			tam::bold("Copy constructor from another ls::list"); std::cout << std::endl;

			// Declaration
			ls::list<int> origList;
			//client::populate( origList );
			for( size_t i = 0; i < 10; i++ )
			{
				origList.push_back(i);
			}
			ls::list<int> copyList( origList );

			// Simple print
			std::cout << "Copied list elements: ";
			client::print_it( copyList, ' ' );
		}

		{
			tam::bold("Object construtor by std::initializer"); std::cout << std::endl;
			
			// Declaration
			ls::list<int> initList ( {1, 4, 3, 2, 5, 9, 10} );

			// Simple print
			std::cout << "Initializer vector elements: ";
			client::print_it(initList, ' ');
		}

		{
			tam::bold("list destructor"); std::cout << std::endl;
			// Declaration
			ls::list<int> *V = new ls::list<int>;
			std::cout << "list allocated on " << V << std::endl;
			
			std::cout << "Trying to delete " << V << "..." << std::endl;
			delete V;
			std::cout << "vector deleted with sucess!\n";
		}

		// Assignment Operator tests
		{
			tam::bold("Assignment Operator"); std::cout << std::endl;
			tam::debugAlert();
			ls::list<int> V = { 11, 13, 12, 15, 14 };
			ls::list<int> V2 = { 1, 2, 3, 4, 5 };
			ls::list<int> V3 = { 3, 4, 2 };

			std::cout << "Expected >> V = { 11, 13, 12, 15, 14 } " << std::endl;
			std::cout << "Result >> V = ";			
			client::print_it(V, ' ');
			std::cout << "Expected >> V2 = { 1, 2, 3, 4, 5 } " << std::endl;
			std::cout << "Result >> V2 = ";
			client::print_it(V2, ' ');
			std::cout << "Expected >> V3 = { 3, 4, 2 } " << std::endl;
			std::cout << "Result >> V3 = ";
			client::print_it(V3, ' ');	
			
			tam::bugAlert();
			std::cout << std::endl << "V = V2" << std::endl;
			V = V2;
			std::cout << "V = ";
			client::print_it(V, ' ');
			std::cout << "V2 = ";
			client::print_it(V2, ' ');

			tam::bugAlert();
			V = { 11, 13, 12, 15, 14 };
			std::cout << "V = ";
			client::print_it(V, ' ');
			std::cout << "V3 = ";
			client::print_it(V3, ' ');
		}

		{
			tam::bold("Assignment Operator std::initializer"); std::cout << std::endl;
			
			// Declaration
			ls::list<int> initList = {1, 4, 3, 2, 5, 9, 10};

			// Simple print
			std::cout << "Initializer vector elements: ";
			client::print_it(initList, ' ');
		}

		tam::div();
	}

	// Iterators methods tests
	{
		tam::title("Iterators methods tests");		 std::cout << std::endl;
		{		
		tam::bold("Begin & End methods"); std::cout << std::endl;
		ls::list<int> l;
		//client::populate(l);
		for( size_t i = 0; i < 10; i++ )
		{
			l.push_back(i);
		}
		std::cout << "for loop to print elements in the vector\n";

		std::cout << std::endl;
		std::cout << "for( auto &it : V ){ std::cout << it << ' '; }" << std::endl;		
		for( auto &it : l ){ std::cout << it << ' '; }

		std::cout << std::endl << std::endl;
		std::cout << "begin/end:" << std::endl;
		std::cout << "for( auto it = V.begin(); it != V.end(); it++ ){ std::cout << *it << ' '; }" << std::endl;
		for( auto it = l.begin(); it != l.end(); it++ ){ std::cout << *it << ' '; }

		std::cout << std::endl << std::endl;
		std::cout << "Const begin/end: \n(if we try to change a value, it get's a compilation error)\n";
		std::cout << "for( auto it = V.cbegin(); it != V.cend(); ++it ){ std::cout << *it << ' '; }" << std::endl;
		for( auto it = l.cbegin(); it != l.cend(); ++it ){ std::cout << *it << ' '; }
		
		std::cout << std::endl;

		tam::div();
	}
	
	// Capacity methods tests
	{
		tam::title("Capacity methods tests"); std::cout << std::endl;
		{
			tam::bold("Empty method test"); std::cout << std::endl;
			// Declaration
			ls::list<int> l(10);
			//client::populate(l);
			for( size_t i = 0; i < 10; i++ )
			{
				l.push_back(i);
			}
			std::cout << "created list l with 10 elements\n";
			ls::list<int> l_emp;	
			std::cout << "created list l_emp with 0 elements\n";

			// tests
			std::cout << "Is l empty? ";
			std::cout << ( l.empty() ? "Yes\n" : "No\n" );
			std::cout << "Is l_emp empty? ";
			std::cout << ( l_emp.empty() ? "Yes\n" : "No\n" );
		}

		{
			tam::bold("Size method test"); std::cout << std::endl;
			ls::list<int> l(10);
			//client::populate(l);
			for( size_t i = 0; i < 10; i++ )
			{
				l.push_back(i);
			}
			std::cout << "list l has " << l.size() << " elements\n";

			ls::list<int> l2(40);
			std::cout << "list l2 created\n";
			//client::populate(l2);
			for( size_t i = 0; i < 40; i++ )
			{
				l2.push_back(i);
			}
			std::cout << "list l2 has " << l2.size() << " elements\n";
		}
		
		tam::div();
	}

	// Modifiers methods tests
	{
		tam::title("Modifiers methods tests"); std::cout << std::endl;

		{
			tam::bold("Clear method test"); std::cout << std::endl;
			// Declaration
			ls::list<int> cList;
			//client::populate(cList);
			for( size_t i = 0; i < 10; i++ )
			{
				cList.push_back(i);
			}
			std::cout << "list cList created and populated ~" << &cList;	
			std::cout << std::endl << "cList elements: ";
			client::print_it(cList, ' ');

			std::cout << "Running clear() on cList\n";
			cList.clear();
			std::cout << "cList.size() = " << cList.size() << std::endl;
		}

		{
			tam::bold("Push_front & push_back method test"); std::cout << std::endl;
			ls::list<int> pList = {2, 3, 4};
			std::cout << "list pList elements: ";
			client::print_it(pList, ' ');

			pList.push_front(-20);
			pList.push_back(99);

			std::cout << "After push_back & push_front: ";
			client::print_it(pList, ' ');

		}

		{
			tam::bold("Pop_front & pop_backmethod test"); std::cout << std::endl;
			// Declaration
			ls::list<int> pList = { 1, 2, 3 };
			std::cout << "list pList elements: ";
			client::print_it(pList, ' ');

			pList.pop_back();
			pList.pop_front();

			std::cout << "after pop_front & pop_back: ";
			client::print_it(pList, ' ');
		}

		{
			tam::bold("Insert methods test"); std::cout << std::endl;

			// Declaration
			std::cout << "Creating iVec(10)\n";
			ls::list<int> iList;
			std::cout << "Populating iList...\n";
			//client::populate(iList);
			for( size_t i = 0; i < 10; i++ )
			{
				iList.push_back(i);
			}
			std::cout<< "iList =";
			client::print_it( iList, ' ' );

			std::cout << "iList.insert( iList.begin(), 10 );\n";
			iList.insert( iList.begin(), 10 );
			client::print_it( iList, ' ' );
			
			std::cout << "\nCreating Vet[] = { 10, 3, 4, 2, 10, 11 };\n";
			int Vet[] = { 10, 3, 4, 2, 10, 11 };
			
			std::cout << "iList.insert( iList.begin(), std::begin(Vet), std::end(Vet) );\n";
			iList.insert( iList.begin(), std::begin(Vet), std::end(Vet) );
			client::print_it( iList, ' ' );
			
			std::cout << "iList.insert( iList.begin(), { 10, 20, 30, 40, 50, 60 } );\n";
			iList.insert( iList.begin(), { 10, 20, 30, 40, 50, 60 } );
			client::print_it( iList, ' ' ); 
			
		}

		{
			tam::bold("Assign method test"); std::cout << std::endl;

			ls::list<int> iList;
			//client::populate(iList);
			for( size_t i = 0; i < 10; i++ )
			{
				iList.push_back(i);
			}
			std::cout << "iList elements: ";
			client::print_it(iList, ' ');

			ls::list<int> aList;
			//client::populate(aList);
			for( size_t i = 0; i < 20; i++ )
			{
				aList.push_back(i);
			}
			std::cout << "aList elements: ";
			client::print_it(aList, ' ');
						
			tam::bugAlert();
			std::cout << "\niList.assign(8, 10) = ";
			iList.assign(5, 10);
			client::print_it(iList, ' ');			

			std::cout << "iList.assign({ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}) = ";
			iList.assign({ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15});
			client::print_it(iList, ' ');

			tam::bugAlert();
			std::cout << "iList.assign(aList.begin(), aList.end()) = ";
			iList.assign(aList.begin(), aList.end());
			client::print_it(iList, ' ');
		}
		
		{
			tam::bold("Erase method with iterator"); std::cout << std::endl;
			ls::list<int> iList;
			//client::populate(iList);
			for( size_t i = 0; i < 10; i++ )
			{
				iList.push_back(i);
			}
			std::cout << "Before elements: ";
			client::print_it(iList, ' ');
			
			std::cout << "\niList.erase(iList.begin())\n" << std::endl;
			iList.erase(iList.begin());
			client::print_it(iList, ' ');
			
			std::cout << "iList.erase( iList.begin(), iList.end() - 3)" << std::endl;
			iList.erase( iList.begin(), iList.end() - 3);
			client::print_it(iList, ' ');
			
			std::cout << "\nAfter elements: ";
			client::print_it(iList, ' ');
			
		}
		tam::div();
		
	}

	// Element access methods tests
	{	
		tam::title("Element access methods tests"); std::cout << std::endl;
		{
			tam::bold("Front and back method test"); std::cout << std::endl;
			ls::list<int> list;
			//client::populate(list);
			for( size_t i = 0; i < 10; i++ )
			{
				list.push_back(i);
			}
			std::cout << "list elements: ";
			client::print_it(list, ' ');
			std::cout << "list.front() = " << list.front() << std::endl;
			std::cout << "list.back() = " << list.back() << std::endl;
		}
		tam::div();
	}

	// Operators tests 
	{
		tam::title("Operators tests"); std::cout << std::endl;
		{
			tam::bold("\"==\" and \"!=\" test"); std::cout << std::endl;

			ls::list<int> l = { 11, 13, 12, 15, 14 };
			ls::list<int> l2 = { 1, 2, 3, 4, 5 };
			ls::list<int> l3 = { 3, 4, 2 };

			std::cout << "l = "; client::print_it(l, ' ');
			std::cout << "l2 = "; client::print_it(l2, ' ');
			std::cout << "l3 = "; client::print_it(l3, ' ');

			std::cout << "\nl == l3 ? ";
			(l == l3) ? std::cout << "True\n" : std::cout << "False\n";

			std::cout << "l != l2 ? ";			
			( l != l2 ) ? std::cout << "True\n" : std::cout << "False\n";
		}
		tam::div();
	}
	
	return 0;
	
	}
}