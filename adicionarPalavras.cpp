#include <iostream>
#include <string>
#include <vector>
#include "leArquivos.h"
#include "salvaArquivo.h"
void adicionarPalavras(){
    std::cout << "digite a nova palavra (USANDO LETRAS MAIUSCULAS)" <<std::endl;
    std::string novaPalavra;
    std::cin >> novaPalavra;

    std::vector<std::string> listaPalavras = leArquivos();
    listaPalavras.push_back(novaPalavra);

    salvaArquivo(listaPalavras);

}
