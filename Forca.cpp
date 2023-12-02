#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
//************************funções****************************************************
#include "letraExiste.h"
#include "naoAcertou.h"
#include "naoEnforcou.h"
#include "imprimeCabecalho.h"
#include "imprimeErros.h"
#include "imprimePalavra.h"
#include "leArquivos.h"
#include "sorteiaPalavra.h"
#include "salvaArquivo.h"
#include "adicionarPalavras.h"
#include "chuta.h"
using namespace std;

string palavraSecreta;
map<char, bool> chutou;
vector<char> chutesErrados;

int main(){

    imprimeCabecalho();
//________________________________________________________________________________________________________________________________________________________________
    leArquivos();
    sorteiaPalavra();

    while(naoAcertou() && naoEnforcou()){

        imprimeErros();
        imprimePalavra();
        chuta();

    }
    cout << "Fim de jogo" << endl;
    cout << "A palavra secreta era " << palavraSecreta <<endl;
    if(naoAcertou()){
        cout << "tente novament " << endl;
    }else{
        cout << "Parabens " <<endl;
        cout << "Deseja adicionar uma palavra nova ao banco de palavras? (S/N)" <<endl;
        char resposta;
        cin >> resposta;
        if(resposta == 'S'){
            adicionarPalavras();
        }
    }

}
