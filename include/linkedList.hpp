#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <iostream>

#include "tam.hpp"

using value_type = int;

struct Node {
    int data;
    Node *next;
};

void print( const Node * head )
{
    const Node *temp { head };

    std::cout << "[ ";
    while ( temp != nullptr )
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << "]\n";
}

size_t length( const Node * head )
{
    const Node* temp { head };
    value_type count = 0;

    
    while ( temp != nullptr)
    {
        temp = temp->next;
        count++;
    }

    delete temp;
    return count;
}

bool empty ( const Node * head )
{
    return length(head) == 0 ? true : false;
}

void clear ( Node * head )
{
    Node* temp1 { head };

    while (temp1 != nullptr)
    {
        temp1 = temp1->next;
        delete temp1;
    }
     
}

int front ( const Node * head )
{
    return 0;
}

int back ( const Node * head )
{

}

void push_front ( Node * head, value_type value )
{

}

void push_back ( Node * head , value_type value )
{

}

int pop_front ( Node * head )
{

}

int pop_back( Node * head )
{

}

Node * find ( Node * head, value_type target )
{

}

void insert ( Node * head, Node * prev, value_type value )
{

}

#endif // __LINKEDLIST_H__