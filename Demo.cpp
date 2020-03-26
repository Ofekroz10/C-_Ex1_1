/**
 * Demo program for Gimatriya calculation.
 * 
 * Date: 2020-02
 */

#include "PhoneticFinder.hpp"

#include <iostream>
#include <stdexcept>
#include<vector>
using namespace std;
using namespace phonetic;

int main() {
	
    string text = "hello world";

    cout << find(text, "vurlt") << endl;
    cout << find(text, "vurld") << endl;
    cout << find(text, "vorlt") << endl;
    cout << find(text, "vorld") << endl;
    cout << find(text, "wurlt") << endl;
    cout << find(text, "wurld") << endl;
    cout << find(text, "worlt") << endl;
    cout << find(text, "world") << endl;
}
