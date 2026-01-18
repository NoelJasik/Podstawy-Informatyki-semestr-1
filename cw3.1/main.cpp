#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

/*
* Napisz program, który zapisuje w pliku tabliczkę mnożenia (w postaci
macierzy kwadratowej !!). Daj użytkownikowi możliwość wyboru rozmiaru
macierzy
 */
void zadanie1() {
    // otwarcie pliku do zapisu
    fstream file;
    file.open("../tablica.txt", ios::out);

    int** tab, yPos, xSize;
    cout << "Priviet give me x for your multiplication table: ";

    cin >> xSize;

    cout << "Priviet give me y for your multiplication table: ";

    cin >> yPos;

    tab = new int* [yPos];

    // stworzenie tabelki
    for (int i = 0; i <= yPos; i++)
    {
        tab[i] = new int[xSize];
    }

    // wypisanie tabelki
    for (int i = 1; i <= yPos; i++)
    {
        for (int j = 1; j <= xSize; j++)
        {
            tab[i][j] = i*j;
        }
    }

    if (file.good()) {
        // zapis do pliku
        for (int i = 1; i <= yPos; i++)
        {
            file << "\n";
            for (int j = 1; j <= xSize; j++)
            {
                file << setw(5) << tab[i][j];
            }
        }

        // kasowanie macierzy z pamięci
        for (int i = 0; i < yPos; i++) {
            delete[] tab[i];
        }
        delete[] tab;
    } else {
        cout << "Błąd: Nie mozna otworzyc pliku z haslem." << endl;
        return;
    }
    file.close();

}
/*
* Napisz program, dla rodzica ucznia szkoły podstawowej, który po podaniu
hasła zapisanego w pliku .txt wyświetla dziennik ocen (w postaci macierzy
kwadratowej). Dziennik ocen przygotuj w osobnym pliku .txt.
 */
void zadanie2() {
    string hasloUser, hasloPlik;
    fstream file;

    cout << "Podaj haslo do dziennika: ";
    cin >> hasloUser;

    // Odczyt poprawnego hasła z pliku
    file.open("../haslo.txt", ios::in);
    if (file.good()) {
        file >> hasloPlik;
        file.close();
    } else {
        cout << "Błąd: Nie mozna otworzyc pliku z haslem.\n";
        return;
    }

    // Weryfikacja
    if (hasloUser == hasloPlik) {
        cout << "Haslo poprawne! Wyswietlam dziennik ocen:\n";

        // Otwarcie i wypisanie dziennika
        file.open("../dziennik.txt", ios::in);
        if (file.good()) {
            // Plik już jest sformatowany więc wyświetlam linijkę po linijce
            string linia;
            while (getline(file, linia)) {
                // nwm czy są jakieś różnice między \n a endl jakiekolwiek
                cout << linia << endl;
            }
            file.close();
        } else {
            cout << "Blad: Nie znaleziono pliku z dziennikiem.\n";
        }
    } else {
        cout << "Bledne haslo! Dostep zabroniony.\n";
    }

    file.close();
}
/*
* Napisz program który wczytuje podaną przez użytkownika liczbę
wierzchołków i krawędzi oraz pary wierzchołków, a następnie wyświetla
macierz sąsiedztwa. Program ma odwzorowywać graf nieskierowany.
*/
void zadanie3() {
    int n, m, i, j, v1, v2; //liczba wierzcholkow i krawedzi, wspolrz�dne macierzy, wirzcholek startowy i koncowy
    int** A; // macierz

    cout << "Podaj liczbe wierzolkow: " << endl;
    cin >> n;          // Czytamy liczb� wierzcho�k�w
    cout << "Podaj liczbe krawedzi: " << endl;
    cin >> m;         // Czytamy liczb� kraw�dzi


    A = new int* [n];  // Tworzymy macierz

    for (i = 0; i < n; i++)
        A[i] = new int[n]; // Tworzymy wiersze

    // Macierz wypełniamy zerami

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            A[i][j] = 0;

    // Odczytujemy kolejne definicje krawędzi

    cout << "Podaj pary wierzcholkow (gdzie liczba par jest rowna liczbie krawedzi): " << endl;

    for (i = 0; i < m; i++)
    {
        cin >> v1 >> v2;
        A[v1][v2] = 1;
        A[v2][v1] = 1; // Graf nieskierowany więc zaznaczamy obustronnie

    }

    cout << endl;

    // Wypisujemy zawartość macierzy sąsiedztwa

    cout << "   ";
    for (i = 0; i < n; i++)
        cout << setw(3) << i;

    cout << endl << endl;

    for (i = 0; i < n; i++)
    {
        cout << setw(3) << i;
        for (j = 0; j < n; j++)
            cout << setw(3) << (int)A[i][j];
        cout << endl;
    }

    // Usuwamy macierz, zwalniamy miejsce w pami�i RAM

    for (i = 0; i < n; i++) delete[] A[i];
    delete[] A;

    cout << endl;

}

/*
* Zmień program z zad. 3 w taki sposób aby wczytywał dane z pliku.
*/
void zadanie4() {
    int n, m, i, j, v1, v2;
    int** A;

    // wczytanie z pliku (inny sposób, nwm czym się różni od fstream z wybranym konkretnym trybem)
    ifstream file("../matrix.txt");

    // Sprawdzamy, czy plik udało się otworzyć
    if (!file.is_open()) {
        cout << "Blad: Nie udalo sie otworzyc pliku 'dane.txt'!" << endl;
        cout << "Upewnij sie, ze plik istnieje w katalogu roboczym." << endl;
        return; // Kończymy funkcję, bo nie ma danych
    }

    // Wczytujemy dane z pliku zamiast z klawiatury (cin -> plik)S
    file >> n; // Pierwsza liczba w pliku to liczba wierzchołków
    file >> m; // Druga liczba w pliku to liczba krawędzi

    cout << "Wczytano z pliku: " << n << " wierzcholkow i " << m << " krawedzi." << endl;

    // Alokacja pamięci (bez zmian)
    A = new int* [n];
    for (i = 0; i < n; i++)
        A[i] = new int[n];

    // Zerowanie macierzy (bez zmian)
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            A[i][j] = 0;

    // 4. Pętla wczytująca krawędzie z pliku
    for (i = 0; i < m; i++)
    {
        // Czytamy parę liczb z pliku
        file >> v1 >> v2;

        // Sprawdzamy dane jakby ktoś najebany w tym pliku pisał
        if (v1 >= 0 && v1 < n && v2 >= 0 && v2 < n) {
            A[v1][v2] = 1;
            A[v2][v1] = 1; // Graf nieskierowany
        }
    }

    // Zamykamy plik, bo już wszystko przeczytaliśmy
    file.close();

    cout << endl << "Macierz sasiedztwa:" << endl;

    // Wypisujemy nagłówki kolumn
    cout << "   ";
    for (i = 0; i < n; i++)
        cout << setw(3) << i;

    cout << endl << endl;

    // Wypisujemy zawartość macierzy
    for (i = 0; i < n; i++)
    {
        cout << setw(3) << i;
        for (j = 0; j < n; j++)
            cout << setw(3) << (int)A[i][j];
        cout << endl;
    }

    // Sprzątanie świata
    for (i = 0; i < n; i++) delete[] A[i];
    delete[] A;

    cout << endl;

}


int main() {
    cout << "Zadanie 1\n";
    zadanie1();
    cout << "Zadanie 2\n";
    zadanie2();
    cout << "Zdadanie 3\n";
    zadanie3();
    cout << "Zadanie 4\n";
    zadanie4();
    return 0;
}