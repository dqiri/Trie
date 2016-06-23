#include "Trie.hpp"
#include <iostream>

int
main(int argc, char** argv){
    Trie x;

    std::cout << "Adding `Hello`" << std::endl;
    
    x.insert(std::string("Hello"));

    std::cout << "Was `Hello` inserted succesfully?" << std::endl;

    std::cout << x.find("Hello")->getValue() << std::endl;
    
    std::cout << "Nope " << x.find("420") << std::endl;



    return 0;
}
