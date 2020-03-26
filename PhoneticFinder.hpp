#include <iostream>
#include <string>
#include<exception>
#include<vector>
using std::string;
using namespace std;

namespace phonetic
{
    string find(string, string);
    bool emptyStr(string);
    void allPermotations(string, size_t);
    char* getSameWords(char);
    void allHighCasePer(string,int);

    vector<string>* split(string, string);

    static string sameWords[8] = { "v,w","b,f,p","g,j","c,k,q","s,z","d,t","o,u","i,y" };


    struct NotFoundException : public std::exception {
        public:
        NotFoundException(string msg) {eror = msg;}
        const char* what()  { return eror.c_str(); }

        private:
        string eror;
            
        };
    
    struct IllegalArgumentException : public std::exception {
        public:
        IllegalArgumentException(string msg) {eror = msg;}
        const char* what()  { return eror.c_str(); }

        private:
        string eror;
            
        };
    

    

}