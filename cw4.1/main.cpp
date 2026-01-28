#include <iostream>
#

using namespace std;
string szyfrCezara(string _txt) {
    string res = "";
    for (int i = 0; i < _txt.length(); i++) {
        res += (_txt[i] + 3);
    }
    return res;
}

string odszyfrujCezara(string _txt) {
    string res = "";
    for (int i = 0; i < _txt.length(); i++) {
        res += (_txt[i] - 3);
    }
    return res;
}
//TODO - dokończyć
string szyfrPoli(string _txt) {
    string res = "";
    for (int i = 0; i < _txt.length(); i++) {
        int asciiValue = (_txt[i] + 3);
        cout << asciiValue << endl;
        if(asciiValue <= 68) {
            asciiValue + 22;
        } else if(asciiValue > 93) {
            asciiValue - 22;
        }
        cout << asciiValue << endl;

        res += asciiValue;
    }
    return res;
}
string deszyfrPoli(string _txt) {
    string res = "";
    for (int i = 0; i < _txt.length(); i++) {
        int asciiValue = (_txt[i] - 3);
        if(asciiValue <= 100) {
            asciiValue + 22;
        } else if(asciiValue > 122) {
            asciiValue - 22;
        }
        res += asciiValue;
    }
    return res;
}


int main() {
    // cout << "Podaj słowo do szyfrowania (kaiser)" << endl;
    // string word;
    // cin >> word;
    // cout << szyfrCezara(word) << endl;
    // cout << "Podaj słowo do odszyfrowania (kaiser)" << endl;
    // string word2;
    // cin >> word2;
    // cout << odszyfrujCezara(word2) << endl;
    cout << "Podaj słowo do szyfrowania (poli)" << endl;
    string word;
    cin >> word;
    cout << szyfrPoli(word) << endl;
    cout << "Podaj słowo do odszyfrowania (poli)" << endl;
    string word2;
    cin >> word2;
    cout << deszyfrPoli(word2) << endl;

    return 0;
}
