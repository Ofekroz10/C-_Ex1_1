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
	
    string text = "Vw bgP";
    cout << find(text, "wv");
}
