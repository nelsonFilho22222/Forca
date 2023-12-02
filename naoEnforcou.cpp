#include <vector>
#include "forca.cpp"

extern std::vector<char> chutesErrados;

bool naoEnforcou(){
    return chutesErrados.size() < 5;
}
