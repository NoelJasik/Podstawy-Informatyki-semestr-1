#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm> // przydaje sie do odwracania stringa

using namespace std;

/*
Zad. 1
Napisz program, który prosi użytkownika o podanie pojedynczego znaku i wypisuje jego kod
ASCII, to czy jest cyfrą, wielką literą, małą literą albo znakiem specjalnym.
*/
void zadanie1() {
    char znak;

    cout << "Podaj pojedynczy znak: ";
    cin >> znak;

    // Wypisanie kodu ASCII (duh)
    cout << "Kod ASCII: " << (int)znak << "\n";

    // Sprawdzanie rodzaju znaku po zakresach ASCII
    if (znak >= '0' && znak <= '9') {
        cout << "To jest cyfra.\n";
    }
    else if (znak >= 'A' && znak <= 'Z') {
        cout << "To jest wielka litera.\n";
    }
    else if (znak >= 'a' && znak <= 'z') {
        cout << "To jest mala litera.\n";
    }
    else {
        cout << "To jest znak specjalny.\n";
    }
}


// ---- funkcje do zadania 3 ----

/*
* Funkcja zamienia liczbę z systemu dziesiętnego na binarny
*/
string decToBin(int l) {
    if (l == 0) return "0";
    string wynik = "";
    while (l > 0) {
        wynik += (l % 2 == 0 ? "0" : "1");
        l /= 2;
    }
    reverse(wynik.begin(), wynik.end());
    return wynik;
}

/*
* Funkcja zamienia liczbę z systemu dziesiętnego na ósemkowy
*/
string decToOct(int l) {
    if (l == 0) return "0";
    string wynik = "";
    while (l > 0) {
        wynik += to_string(l % 8);
        l /= 8;
    }
    reverse(wynik.begin(), wynik.end());
    return wynik;
}

/*
* funkcja zamienia liczbę z systemu dziesiętnego na szesnastkowy
*/
string decToHex(int l) {
    if (l == 0) return "0";
    string wynik = "";
    char hexDigits[] = "0123456789ABCDEF";
    while (l > 0) {
        wynik += hexDigits[l % 16];
        l /= 16;
    }
    reverse(wynik.begin(), wynik.end());
    return wynik;
}

/*
* Funkcja zamienia liczbę z systemu binarnego na dziesiętny
*/
int binToDec(string l) {
    int wynik = 0;
    int potega = 1;
    for (int i = l.length() - 1; i >= 0; i--) {
        if (l[i] == '1') {
            wynik += potega;
        }
        potega *= 2;
    }
    return wynik;
}

/*
* Funkcja zamienia liczbę z systemu ósemkowego na dziesiętny
*/
int octToDec(string l) {
    int wynik = 0;
    int potega = 1;
    for (int i = l.length() - 1; i >= 0; i--) {
        int cyfra = l[i] - '0'; // zamiana char na int
        wynik += cyfra * potega;
        potega *= 8;
    }
    return wynik;
}

/*
* Funkcja zamienia liczbę z systemu szesnastkowego na dziesiętny
*/
int hexToDec(string l) {
    int wynik = 0;
    int potega = 1;
    for (int i = l.length() - 1; i >= 0; i--) {
        int cyfra;
        if (l[i] >= '0' && l[i] <= '9') {
            cyfra = l[i] - '0';
        } else if (l[i] >= 'A' && l[i] <= 'F') {
            cyfra = l[i] - 'A' + 10;
        } else if (l[i] >= 'a' && l[i] <= 'f') {
            cyfra = l[i] - 'a' + 10;
        } else {
            cyfra = 0; // zabezpieczenie
        }
        wynik += cyfra * potega;
        potega *= 16;
    }
    return wynik;
}

// ----- Konwersje pośrednie ----

/*
* Binarny -> Ósemkowy (przez dziesiętny)
*/
string binToOct(string l) {
    int temp = binToDec(l);
    return decToOct(temp);
}

/*
* Binarny -> Szesnastkowy (przez dziesiętny)
*/
string binToHex(string l) {
    int temp = binToDec(l);
    return decToHex(temp);
}

/*
* Ósemkowy -> Binarny (przez dziesiętny)
*/
string octToBin(string l) {
    int temp = octToDec(l);
    return decToBin(temp);
}

/*
* Ósemkowy -> Szesnastkowy (przez dziesiętny)
*/
string octToHex(string l) {
    int temp = octToDec(l);
    return decToHex(temp);
}

/*
* Szesnastkowy -> Binarny (przez dziesiętny)
*/
string hexToBin(string l) {
    int temp = hexToDec(l);
    return decToBin(temp);
}

/*
* Szesnastkowy -> Ósemkowy (przez dziesiętny)
*/
string hexToOct(string l) {
    int temp = hexToDec(l);
    return decToOct(temp);
}


/*
Zad. 3
Na podstawie przedstawionych wcześniej sposobów konwersji liczb napisz program
konwertujący liczby w zakresie 4 systemów (binarnym, 8-kowym, 10-tnym, 16-kowym)
Napisz osobne funkcje, z których każda:
• przyjmie liczbę z systemu dziesiętnego i zwróci jej odpowiednik w systemie binarnym.
• przyjmie liczbę z systemu dziesiętnego i zwróci jej odpowiednik w systemie ósemkowym.
• przyjmie liczbę z systemu dziesiętnego i zwróci jej odpowiednik w systemie szesnastkowym.
• przyjmie liczbę z systemu binarnego i zwróci jej odpowiednik w systemie dziesiętnym.
• przyjmie liczbę z systemu binarnego i zwróci jej odpowiednik w systemie ósemkowym.
• przyjmie liczbę z systemu binarnego i zwróci jej odpowiednik w systemie szesnastkowym.
• przyjmie liczbę z systemu ósemkowego i zwróci jej odpowiednik w systemie binarny.
• przyjmie liczbę z systemu ósemkowego i zwróci jej odpowiednik w systemie dziesiętnym.
• przyjmie liczbę z systemu ósemkowego i zwróci jej odpowiednik w systemie szesnastkowym.
• przyjmie liczbę z systemu szesnastkowego i zwróci jej odpowiednik w systemie binarnym.
• przyjmie liczbę z systemu szesnastkowego i zwróci jej odpowiednik w systemie ósemkowym.
• przyjmie liczbę z systemu szesnastkowego i zwróci jej odpowiednik w systemie dziesiętnym.

twórz interfejs użytkownika (menu) które zapyta o rodzaj konwersji (lista możliwych
konwersji, lub rodzaj input/output).
Można używać konwersji pośredniej
*/
void zadanie3() {
    int wyborWejscie, wyborWyjscie;
    string liczbaStr;
    int liczbaInt;

    cout << "=== KALKULATOR SYSTEMOW ===\n";
    cout << "Wybierz system wejsciowy:\n";
    cout << "1. Dziesietny (DEC)\n";
    cout << "2. Binarny (BIN)\n";
    cout << "3. Osemkowy (OCT)\n";
    cout << "4. Szesnastkowy (HEX)\n";
    cout << "Wybor: ";
    cin >> wyborWejscie;

    cout << "\nPodaj liczbe do konwersji: ";
    if (wyborWejscie == 1) {
        cin >> liczbaInt;
    } else {
        cin >> liczbaStr;
    }

    cout << "\nWybierz system docelowy:\n";
    cout << "1. Dziesietny (DEC)\n";
    cout << "2. Binarny (BIN)\n";
    cout << "3. Osemkowy (OCT)\n";
    cout << "4. Szesnastkowy (HEX)\n";
    cout << "Wybor: ";
    cin >> wyborWyjscie;

    cout << "\nWynik: ";

    // Logika wyboru odpowiedniej funkcji
    if (wyborWejscie == 1) { // Z DEC
        if (wyborWyjscie == 1) cout << liczbaInt; // DEC -> DEC
        else if (wyborWyjscie == 2) cout << decToBin(liczbaInt);
        else if (wyborWyjscie == 3) cout << decToOct(liczbaInt);
        else if (wyborWyjscie == 4) cout << decToHex(liczbaInt);
    }
    else if (wyborWejscie == 2) { // Z BIN
        if (wyborWyjscie == 1) cout << binToDec(liczbaStr);
        else if (wyborWyjscie == 2) cout << liczbaStr; // BIN -> BIN
        else if (wyborWyjscie == 3) cout << binToOct(liczbaStr);
        else if (wyborWyjscie == 4) cout << binToHex(liczbaStr);
    }
    else if (wyborWejscie == 3) { // Z OCT
        if (wyborWyjscie == 1) cout << octToDec(liczbaStr);
        else if (wyborWyjscie == 2) cout << octToBin(liczbaStr);
        else if (wyborWyjscie == 3) cout << liczbaStr; // OCT -> OCT
        else if (wyborWyjscie == 4) cout << octToHex(liczbaStr);
    }
    else if (wyborWejscie == 4) { // Z HEX
        if (wyborWyjscie == 1) cout << hexToDec(liczbaStr);
        else if (wyborWyjscie == 2) cout << hexToBin(liczbaStr);
        else if (wyborWyjscie == 3) cout << hexToOct(liczbaStr);
        else if (wyborWyjscie == 4) cout << liczbaStr; // HEX -> HEX
    }
    else {
        cout << "Blad: Niepoprawny wybor systemu.\n";
    }
    cout << "\n";
}



int main() {
    cout << "Zadanie 1\n";
    zadanie1();
    cout << "\nZadanie 3\n";
    zadanie3();

    return 0;
}