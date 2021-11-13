#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

void split(string *chaine, const char delimiteur, vector<string> *elements)
{

    size_t pos = 0;
    string souschaine;
    while ((pos = (*chaine).find(delimiteur)) != string::npos) {
        souschaine = (*chaine).substr(0, pos);
        (*elements).push_back(souschaine);
        (*chaine).erase(0, pos + 1);
    }
    (*elements).push_back(*chaine);

}
