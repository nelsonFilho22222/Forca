#include <vector>
#include <iostream>

extern std::vector<char> chutesErrados;


void imprimeErros(){
    std::cout << "Chutes errados: ";
    for(char letra : chutesErrados){
        std::cout << letra;
        }
    std::cout << std::endl;
}
