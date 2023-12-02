#include <iostream>
#include <map>
#include "letraExiste.h"
#include <vector>
#include "chuta.h"
extern std::map<char, bool> chutou;
extern std::vector<char> chutesErrados;
void chuta(){
        std::cout<<std::endl << "Qual seu chute?"<<std::endl;
        char chute;
        std::cin >> chute;

        chutou[chute] = true;

        if(letraExiste(chute)){
            std::cout << "Voce acertou, seu chute esta na palavra " <<std::endl;
        }else{
            std::cout << "Voce errou, tente novamente " << std::endl;
            chutesErrados.push_back(chute);
        }
    std::cout<<std::endl;
}
