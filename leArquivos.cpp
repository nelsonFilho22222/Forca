#include <vector>
#include <string>
#include <fstream>
#include <iostream>


    std::vector<std::string> leArquivos(){
    std::ifstream arquivo;
    arquivo.open("forcaData.txt");

        if(arquivo.is_open()){

        int quantidadePalavras;
        arquivo >> quantidadePalavras;

        //cout << "o arquivo possui" << quantidadePalavras << endl;

        std::vector<std::string> palavrasDoArquivo;


        for(int i = 0; i<quantidadePalavras; i++){
            std::string palavraLida;
            arquivo >> palavraLida;
            //cout << "na linha " << i << ":"<< palavraLida <<endl;
            palavrasDoArquivo.push_back(palavraLida);

        }
        arquivo.close();
        return palavrasDoArquivo;
    }else{
    std::cout << "Nao foi possivel acessar o banco de palavras" <<std::endl;
    exit(0);
    }
}
