#include <iostream>

#include "../include/linkedList.hpp"
#include "../include/tam.hpp"


Node * build123();
void print( const Node * );


/// constroi e retorna uma lista com 3 elementos.
Node * build123()
{
    //Criando os 3 blocos
    Node *n1 = new Node;
    Node *n2 = new Node;
    Node *n3 = new Node;

    // Atribuindo conteúdo aos blocos
    n1->data = 1;
    n2->data = 2;
    n3->data = 3;

    // Estabelecendo conexão entre os blocos.
    n1->next = n2; // conectar n1 com n2
    n2->next = n3; // conectar n2 com n3
    n3->next = nullptr; // aterra o ultimo.

    return n1;
}



int main() {

    Node *head{nullptr};
    Node *l0{nullptr};

    head = build123();

    
    tam::title("PRINT FUNCTION"); std::cout << std::endl;

    print( l0 );
    print( head );
    tam::div();


    tam::title("LENGTH FUNCITON"); std::cout << std::endl;
    int s_head = length( head );
    int s_l0 = length( l0 );

    std::cout << "Length(head) = " << s_head << "\n";
    std::cout << "Length(l0) = " << s_l0 << std::endl;
    tam::div();

    tam::title("EMPTY FUNCITON"); std::cout << std::endl;
    empty(l0) == true ? std::cout << "l0 = empty" : std::cout << "l0 = no empty";  
    std::cout << std::endl;
    std::cout << std::endl;


    tam::title("CLEAR FUNCITON"); std::cout << std::endl;
    
    Node *l1{nullptr};
    l1 = build123();

    std::cout << "Before:"; print ( l1 ); std::cout << std::endl;
    clear(l1);
    std::cout << "After:"; print ( l1 ); std::cout << std::endl; 
    int s_l1 = length( l0 ); 
    std::cout << "Length(l1) = " << s_l1 << "\n";
    empty(l1) == true ? std::cout << "l1 = empty" : std::cout << "l1 = no empty"; 
    tam::div();

    return 0;
}