# TAD-LinkedList
In this project, a sequential container with a doubly linked list was implemented.

This project was proposed by professor Selan Rodrigues from UFRN, for EDB1 material from the IT course. To see more, access the PDF
`projeto_ED_list.pdf`.

# Developed by students / authors Samir Rodrigues and Italo Lima.

>> To compile this project with [cmake](https://cmake.org) follow these steps:

1. `cd TAD`: enters into the main project directory.
2. `cmake -S . -Bbuild`:  asks cmake to create the build directory and generate the Unix Makefile based on the script found in `CMakeLists.txt`, on the current level.
3. `cd build`: enter the build folder.
4. `cmake --build .` or `make`: triggers the compiling process.


>> To run with our tests, first follow the compilation step above, then run inside the folder  `cd TAD/build` the command  `./play`.

# This project is documented in the doxygen style. Possible errors can be found in the statement. If you find them, please contact us.

# Comments
1. The tests do not show the errors, if there are any, it is necessary to view them manually, one by one. 
2. The use of this code is free, for any purpose, please credit if you use them.
3. Project Authors Samir Rodrigues and Italo Lima. (gits @SamirRodrigues & @italo-ce)
4. Samir Rodrigues was responsable for the implementtion of the iterator class (const_iterator is include) and Italo Lima was responsable for the the implementation of the list class. (Although, both team members constantly participated in the implementation of all build stages) 
5. functions that are not working: 
        void assign( InputIt first, InputIt last );
        void assign ( size_type count, const T& value );
        list & operator= ( const list & );
        const T & operator* ( ) const;
            we believe that all the function that derives from the operator* are not working for some unknown reason... still working to fix it (
            help is accepted)
6. 