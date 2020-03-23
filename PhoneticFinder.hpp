#include <iostream>
#include <string>
#include<exception>
using std::string;

namespace phonetic
{
    string find(string, string);

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