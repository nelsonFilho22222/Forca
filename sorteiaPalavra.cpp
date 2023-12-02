#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <string>
#include "leArquivos.h"
extern std::string palavraSecreta;
void sorteiaPalavra(){
    std::vector<std::string> palavras = leArquivos();

    srand(time(NULL));
    int indiceSorteado = rand() % palavras.size();

    palavraSecreta = palavras[indiceSorteado];
}
