#include <iostream>

#include "../include/linkedList.hpp"

template <typename T>
void print_list(ls::list<T> A )
{
	std::cout << ">>> Current List: [ ";
	ls::copy( A.begin(), A.end(), std::ostream_iterator< int >( std::cout, " " ) );
	std::cout << "]\n";
	std::cout << "\n";
}


int main(int argc, char *argv[])
{
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

	x = lista.insert(lista.begin(),lista.begin()+2,lista.end());
	
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

	return 0;
}