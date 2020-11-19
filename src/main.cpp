#include <iostream>
#include <random>
#include <chrono>

#include "../include/tam.hpp"
#include "../include/linkedList.hpp"
/*
template <typename T>
void print_list(ls::list<T> A )
{
	std::cout << ">>> Current List: [ ";
	ls::copy( A.begin(), A.end(), std::ostream_iterator< int >( std::cout, " " ) );
	std::cout << "]\n";
	std::cout << "\n";
}
*/
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
		for( auto it = l.begin(); it != l.end(); ++it ){
			auto seed = 
				std::chrono::system_clock::now().time_since_epoch().count();
			std::mt19937 rd (seed);
			*it = rd() % 300;
		}
	}
}


int main(int argc, char *argv[])
{
	/*
	std::cout << "Chamando list() " << std::endl;
	ls::list<int> lista;
	lista.push_back(6);
	lista.push_back(1);
	lista.push_back(2);
	lista.push_back(3);
	lista.push_front(5);

	std::cout << "Teste push_front e push_back " << std::endl;
	print_list(lista);
	std::cout << std::endl;

	std::cout << "Teste insert initializer list" << std::endl;
	auto x = lista.insert(lista.begin(),{-1,-2,-3,-4,-5});
	print_list(lista);

	std::cout <<  std::endl;
	std::cout << "Teste retorno insert: initializer list: " << *x << std::endl;
	
	std::cout << "Teste insert [first,last) " << std::endl;
	print_list(lista);
	std::cout << "Teste retorno insert [first,last): " << *x << std::endl;
	
	std::cout << "Teste size: " << lista.size() << std::endl; 

	x = lista.erase(lista.begin());
	std::cout << "Teste erase pos "<< *x << std::endl;
	std::cout <<  std::endl;

	print_list(lista);

	x = lista.erase(lista.begin()+3,lista.end());
	std::cout << "Teste erase  [first,last) " << std::endl;
	print_list(lista);
	//lista.clear();
	//std::cout << "list size after clear : " << lista.size() << std::endl;
	
	
	std::cout << "Teste constructor  initializer list " << std::endl;
	ls::list<int> lista2{{1,2,3,4}};
	print_list(lista2);
	std::cout << "list2 initializer list size : " << lista2.size() << std::endl;

	print_list(lista2);
	lista2.assign(5,7);
	std::cout << "list2 assign: "  << std::endl;
	
	print_list(lista2);	

	lista2.assign(lista.begin(),lista.end());
	
	std::cout << "list2 assign [first,last): "  << std::endl;
	
	print_list(lista2);

	lista2.assign({1,2,3,4,5});
	
	std::cout << "list2 assign initializer list: "  << std::endl;
	print_list(lista2);	

	ls::list<int> lista3 = lista2;
	std::cout << "list3 assignment operator: "  << std::endl;
	print_list(lista3);
	
	ls::list<int> lista4(lista3);
	
	std::cout << "list4 copy constructor: "  << std::endl;
	print_list(lista4);
	
	std::cout << "list3 size : " << lista3.size() << std::endl;
	std::cout << "list4 size : " << lista4.size() << std::endl;

	std::cout << "Teste operator lista4 == lista3 " << (lista4 == lista3) << std::endl;
	std::cout << "Teste operator lista == lista3 " << (lista == lista3) << std::endl;
	std::cout << "Teste operator lista4 != lista3 " << (lista4 != lista3) << std::endl;

	std::cout << "Teste constructor explicit list(size_type) " << std::endl;
	ls::list<int> lista5(5);
	print_list(lista5);	
	
	std::cout << "Before pop front and back " << std::endl;
	print_list(lista3);	
	std::cout << "Teste pop front and back " << std::endl;
	lista3.pop_front();
	lista3.pop_back();
	print_list(lista3);
	*/

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
			for( int i = 0; i < 10; i++ )
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
			for( int i = 0; i < 10; i++ )
			{
				SizeList.push_back(i);
			}

			// Simple print the object
			std::cout << "SizeList elements: ";
			client::print_it( SizeList, ' ' );
		}
		/*
		{
			tam::bold("Copy constructor from a simple array"); std::cout << std::endl;

			// Declaration
			int Vet[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
			std::cout << "Copy vector elements: ";
			ls::list<int> cList( Vet, Vet+10 );
			client::print_it( cList, ' ' );
		}
		*/
		{
			tam::bold("Copy constructor from another sc::vector"); std::cout << std::endl;

			// Declaration
			ls::list<int> origList(10);
			client::populate( origList );
			ls::list<int> copyList( origList );

			// Simple print
			std::cout << "Copied vector elements: ";
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
			tam::bold("vector destructor"); std::cout << std::endl;
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
			
			std::cout << std::endl << "V = V2" << std::endl;
			V = V2;
			std::cout << "V = ";
			client::print_it(V, ' ');
			std::cout << "V2 = ";
			client::print_it(V2, ' ');

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

	return 0;
}