#include <iostream>
#include <vector>

using namespace std;

// Szyfr cezara - przesunięcie o 3 miejsca w prawo w tablicy ASCII
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

// Szyfr przestawienia - zapis do macierzy i odczyt kolumnami
string szyfrPrzestawienia(string _txt) {
    int len = _txt.length();
    int x = 1, y = 1;

    while (x * y < len) {
        if (x <= y) {
            x++;
        } else {
            y++;
        }
    }


    vector matrix(x, vector(y, ' '));
    for (int i = 0; i < len; i++) {
        matrix[i / y][i % y] = _txt[i];
    }

    // Czytaj macierz kolumnami (szyfrowanie przez przestawienie)
    string res = "";
    for (int j = 0; j < y; j++) {
        for (int i = 0; i < x; i++) {
            res += matrix[i][j];
        }
    }

    return res;
}



string odszyfrujPrzestawienia(string _txt) {
    int len = _txt.length();
    int x = 1, y = 1;
    while (x * y < len) {
        if (x <= y) x++;
        else y++;
    }

    vector matrix(x, vector(y, ' '));
    int idx = 0;
    for (int j = 0; j < y; j++) {
        for (int i = 0; i < x; i++) {
            matrix[i][j] = _txt[idx++];
        }
    }

    string res = "";
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            res += matrix[i][j];
        }
    }

    while (!res.empty() && res.back() == ' ') res.pop_back();
    return res;
}

bool menu() {
    // https://forum.pasja-informatyki.pl/307571/n-czy-endl https://stackoverflow.com/questions/64253865/whats-the-difference-between-stdendl-and-n chyba endl jest jednak lepszym wyborem xd
    cout << "Wybierz opcję:" << endl;
    cout << "1. Szyfr Cezara" << endl;
    cout << "2. Odszyfruj Cezara" << endl;
    cout << "3. Szyfr Przestawienia" << endl;
    cout << "4. Odszyfruj Przestawienia" << endl;
    cout << "5. Wyjście" << endl;
    int choice = 0;
    cin >> choice;
    string word;
    switch (choice) {
        case 1:
            cout << "Podaj słowo do szyfrowania:" << endl;
            cin >> word;
            cout << szyfrCezara(word) << endl;
            return true;
        case 2:
            cout << "Podaj słowo do odszyfrowania:" << endl;
            cin >> word;
            cout << odszyfrujCezara(word) << endl;
            return true;
        case 3:
            cout << "Podaj słowo do szyfrowania:" << endl;
            cin >> word;
            cout << szyfrPrzestawienia(word) << endl;
            return true;
        case 4:
            cout << "Podaj słowo do odszyfrowania:" << endl;
            cin >> word;
            cout << odszyfrujPrzestawienia(word) << endl;
            return true;
        case 5:
            cout << "Koniec programu." << endl;
            return false;
        default:
            cout << "Nieprawidłowy wybór. Spróbuj ponownie."
                        << endl;
            return true;
    }
}

int main() {
    bool isOn = true;
    while (isOn) {
         isOn = menu();
    }
    return 0;
}
