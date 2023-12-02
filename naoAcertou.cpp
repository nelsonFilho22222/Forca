#include <string>
#include <map>
#include "forca.cpp"

extern std::string palavraSecreta;
extern std::map<char, bool> chutou;

 bool naoAcertou(){
    for(char letra : palavraSecreta){
        if(!chutou[letra]){
            return  true;
        }
    }
    return  false;
}
