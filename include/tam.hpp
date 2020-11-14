#ifndef __TAM_H__
#define __TAM_H__

#include <iostream>


// Text Apparence Modifiers
namespace tam
{	
	void div( void )
	{
        std::cout << std::endl;
        std::cout << "\e[4m";
		for( int i = 0; i < 80; i++ )
			std::cout << ">";
		std::cout << "\e[0m";
		std::cout << std::endl;
        std::cout << std::endl;
	}

	
	void title(std::string phrase)
	{
		std::cout << "\e[36;4;1m"; // Azul claro
        std::cout << "~ " << phrase;
		std::cout << "\e[0m";
	}
	
	void bold(std::string phrase)
	{
		std::cout << "\e[1m";
		std::cout << "\n> ";
		std::cout << phrase << std::endl;
		std::cout << "\e[0m";
	}
	void debug(std::string phrase)
	{
		std::cout << "\e[33;4;1m";
		std::cout << phrase;
		std::cout << "\e[0m";
	}

    void debugAlert( void )
	{
		std::cout << "\e[33;1m" << std::endl;
		std::cout << ">>> ! <<<" << std::endl;
		std::cout << "\e[0m" << std::endl;
	}

	void bugAlert( void )
	{
		std::cout << "\e[31;1m" << std::endl;
		std::cout << ">>> ! <<<";
		std::cout << "\e[0m";
	}
}

// "\e[0m"  // Define o limite final do efeito
// "\e[1m"  // Negrito
// "\e[4m"  // Subinhado (Underlined / Underscore)

// "\e[30m" // Cinza
// "\e[31m" // Vermelho
// "\e[32m" // Verde
// "\e[33m" // Amarelo
// "\e[34m" // Azul
// "\e[35m" // Margenta
// "\e[36m" // Azul claro


#endif // __TAM_H__