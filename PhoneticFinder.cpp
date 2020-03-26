#include <iostream>
#include <string>
#include <vector>

#define UPPER 32

using namespace std;
#include "PhoneticFinder.hpp"
using namespace phonetic;

vector<string> perm ;

string phonetic::find(string text, string word)
{
    if (phonetic::emptyStr(text))
        throw phonetic::IllegalArgumentException("");

    
    vector<string> * spt = split(text, " ");
    perm.clear();
    
    for (string temp : *spt)
    {
        allPermotations(temp, 0);

        for (string x : perm)
        {
            if (x == word)
                return temp;
        }
        perm.clear();
    }

    throw NotFoundException("");
    delete spt;
}


bool phonetic::emptyStr(string text)
{

    for (char &x : text)
    {
        if (x != ' ')
            return false;
    }

    return true;
}


void phonetic::allHighCasePer(string text,int index)
{
    if (index == text.size())
        perm.push_back(text);
    else
    {
        string withHigh = text;
        withHigh[index] = withHigh[index] - UPPER;
        allHighCasePer(withHigh, index + 1);
        allHighCasePer(text, index + 1);
    }
    
}

void phonetic::allPermotations(string word, size_t index)
{
    if (index == word.size())
    {
        perm.push_back(word);
        allHighCasePer(word,0);
    }
    else
    {
        char* same = getSameWords(word[index]);
        char* first_same = same;
        if (same != 0)
        {
            while (*same)
            {
                string newW = word;
                newW[index] = *same;
                allPermotations(newW, index + 1);
                same++;
            }
        }
       

        allPermotations(word, index+1);
        if (first_same != NULL)
            free(first_same);


    }
} 

char* phonetic::getSameWords(char w)
{
    char* same = (char*)malloc(sizeof(char*));

    if (same == NULL)
        return NULL;

    int curIndex = 0;
    bool contains = false;

    for (string temp : phonetic::sameWords)
    {
        for (char& x : temp)
        {
            if (x == w)
                contains = true;

            else if(x != ',')
            {
                *(same + curIndex) = x;
                curIndex++;
                same = (char*)realloc(same, (curIndex+1)*sizeof(char*));

                if (same == NULL)
                {
                    return NULL;
                }
            }

        }

        if (contains)
        {
            *(same + curIndex) = '\0';
            return same;
        }
        else
        {
            free(same);
            curIndex = 0;
            same = (char*)malloc(sizeof(char*));
        }
        
    }

    return NULL;
} 

vector<string>* phonetic::split(string x, string delimiter)
{
    vector<string>* words = new vector<string>;

    string token;
    size_t pos;
    while ((pos = x.find(delimiter)) != string::npos) {
        token = x.substr(0, pos);
        x.erase(0, pos + delimiter.length());
        words->push_back(token);
    }
    
    words->push_back(x);

    return words;
}