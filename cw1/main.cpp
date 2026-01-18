#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Zadanie 1

/*
1. Farmer hoduje kilka gatunków zwierząt
-> kurczaki, krowy i świnie.
2. Rolnik policzył swoje zwierzęta i podaje
sumę częściową dla każdego gatunku.
Musisz zaimplementować funkcję, która
zwraca całkowitą liczbę nóg wszystkich
zwierząt biegających po framie i
wyświetla tą liczbę na ekran.
Np.:
animals(2, 3, 5) ➞ 36
animals(1, 2, 3) ➞ 22
 */

int farmerHad(int _chickens, int _cows, int _pigs) {
    if (_chickens < 0 || _cows < 0 || _pigs < 0) {
cout << "Złe dane";
        return -1;
    }
    return _chickens * 2 + _cows * 4 + _pigs * 4;
}

// zadanie 2
// Napisz program z użyciem funkcji, który po wpisaniu cyfry od 1 do 5 uruchomi zadania z poprzedniego sprawozdania (bez tego z dniami tygodni)
// Switch z wywoływaniem tych funkcji jest w funkcji main

// ---------- Funkcje z poprzedniego sprawozdania (kradzione, bo zrobiłem już wtedy na funkcjach) ------------------

// Funkcja do walidacji - (potem z niej nie korzystam bo nie było wymogu walidacji)

bool isThereCinError()
{
    if(cin.fail())
    {
        cout<< "Błędne dane\n";
        cin.clear();
        cin.ignore(10000, '\n');
        return true;
    }
    else
    {
        cin.ignore(10000, '\n');
        return false;
    }
}

// 1. Napisz program, który po pobraniu pełnego roku określi, czy dany rok jest przestępny.

void yearChecker()
{
    cout << "Podaj rok\n";
    int year = 0;
    cin >> year;
    if(isThereCinError()) return;
// według wikipedia rok zerowy nie istnieje w kalendarzu gregoriański
    if(year <= 0)
    {
        cout << "Rok musi być większy niż 0";
        cin.clear();
        return;
    }
    if(((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0)
    {
        cout << year << " rok jest przestępny :D";
    }
    else
    {
        cout << year << " rok NIE jest przestępny";
    }
}

// 2. Napisz program, który wczytuje z klawiatury dwie liczby całkowite, a następnie:
// • Wypisuje wszystkie liczby z ich przedziału (przedział otwarty)
// • Dodaje wszystkie parzyste liczby z przedziału i wypisuje wynik na ekranie

void numRange()
{
    int a = 0;
    int b = 0;
    cout << "Podaj pierwszą liczbę\n";
    cin >> a;
    if(isThereCinError()) return;
    cout << "Podaj drugą liczbę\n";
    cin >> b;
    if(isThereCinError()) return;
    if(a > b)
    {
        int _temp = a;
        a = b;
        b = _temp;
    }
    int sum = 0;
    for(int i = a + 1; i < b; i++)
    {
        cout<<i<<"\n";
        if(i%2==0)
        {
            sum += i;
        }
    }
    cout << "suma liczb parzystych: " << sum << "\n";
}



// 3. Napisz program, który wczytuje 5 liczb z klawiatury oraz:
// • Wypisuje na ekran największą i najmniejszą liczbę oraz ich różnicę

void getMinAndMax()
{

    int minNum;
    int maxNum;
    cout << "Podaj Liczbę numer 1:\n";
    cin >> minNum;
    if(isThereCinError()) return;
    maxNum = minNum;
    for(int i = 2; i <= 5; i++)
    {
        int _temp;
        cout << "Podaj Liczbę numer " << i << ":\n";
        cin >> _temp;
        if(isThereCinError()) return;
        if(_temp > maxNum)
        {
            maxNum = _temp;
        }
        if(_temp < minNum)
        {
            minNum = _temp;
        }
    }
    cout << "Min: " << minNum << "\nMax " << maxNum << "\nRóżnica " << (maxNum - minNum) << "\n";
}

// 4. Napisz program, który wczytuje N liczb z klawiatury oraz:
// • Wypisuje na ekran średnią liczb oraz x-razy liczbę 0, gdzie x = średnia wprowadzonych liczb

void avgAndZeroShower()
{
    int amount;
    float sum = 0;

    cout << "Ile chcesz liczb?\n";
    cin >> amount;
    if(isThereCinError()) return;
    if(amount <= 0)
    {
    cout << "No jak ty to sobie wyoborażasz?";
    return;
    }
    for(int i = 1; i <= amount; i++)
    {
        cout << "Podaj liczbę numer: " << i << " \n";
        float _temp;
        cin >> _temp;
        if(isThereCinError()) return;
        sum += _temp;
    }
    float avg = sum / amount;
    cout << "Średnia: " << avg << "\n";
    int roundedAvg = 0;
    if(avg > 0)
    {
        roundedAvg = (int)(avg + 0.5);
    }
    else if(avg < 0)
    {
        roundedAvg = (int)(avg - 0.5);
    }
    for(int i = 0; i < roundedAvg; i++)
    {
        cout << "0";
    }
    cout << "\n";

}

// Koniec funkcji z poprzedniego sprawozdania

// zadanie 3
/*
*Robot porusza się po 2D siatce i wykonuje sekwencję czterech ruchów.
Zaczyna w punkcie (0, 0) i kieruje się na północ (w górę), następnie obraca się
o 90 stopni zgodnie z ruchem wskazówek zegara i kieruje się na wschód,
później na południe i na końcu na zachód – na tym kończy wędrówkę. Biorąc
pod uwagę ilość kroków w każdym ruchu robota podaną przez użytkownika,
napisz funkcje, która obliczyć ostateczne współrzędne robota
 */

void getRobotPosition() {
    int moveVal = 0;
    int x = 0;
    int y = 0;
    // używam do określenia w którym momencie sekwencji jest robocik
    int part = 0;
    do {
        // To jest kłamstwo, bo każda ujemna liczba zakończy program
        cout << "Podaj przesunięcie robota (-1 kończy):\n";
        cin >> moveVal;
        part++;
        switch (part) {
            case 1:
                y += moveVal; break;
            case 2:
                x += moveVal; break;
            case 3:
                y -= moveVal; break;
            case 4:
                x -= moveVal; break;
            default:
                part = 0;
        }
    } while (moveVal >= 0);
    cout << "Pozycja robota (" << x << ", " << y << ")";

}
// Zadanie 4
/*
* Stwórz grę „kamień, papier, nożyczki” z zastosowaniem funkcji. Gra
trwa 3 rund. W każdej rundzie:
• Użytkownik podaje wartość n, która może mieć wartości: 1 -
kamień, 2 - papier, 3 – nożyczki.
• Przeciwnikiem jest komputer (losujący liczbę m z zakresu <1; 3>),
• następnie funkcja knp zwraca wynik
*/
// jak chodzi o zasady, to remis nie daje punktów ani graczowi ani przeciwnikowi
string rockPaperScissors(int _player, int _ai) {
    static int PLAYER_SCORE = 0;
    static int AI_SCORE = 0;
    static int GAME_NUM = 0;
    GAME_NUM++;
    int state = 0; // 1-remis 2-wygrana 3-przegrana
    if(_player == _ai) {
        state = 1;
    } else
    if(_player == 1 && _ai == 3) {
        PLAYER_SCORE++;
        state = 2;
    } else
    if(_player == 2 && _ai == 1) {
        PLAYER_SCORE++;
        state = 2;
    } else
    if(_player == 3 && _ai == 2) {
        PLAYER_SCORE++;
        state = 2;
    } else {
        AI_SCORE++;
state = 3;
    }

    // jeżeli mamy ostatnią gierke, to zwracam wynik, nie podaje informacji o tym czy w tej turze akurat wygraliśmy czy nie, gdyż podaje wynik końcowy
    if(GAME_NUM >= 3) {
        // wiem że te elsy są w sumie zbędne przy returnie ale pisze to tak dla lepszej czytelności kodu
        if(PLAYER_SCORE > AI_SCORE) {
            return "Wygrałeś z wynikiem " + to_string(PLAYER_SCORE) + "/" + to_string(AI_SCORE);
        } else if (PLAYER_SCORE == AI_SCORE) {
            return "Remisujesz z wynikiem " + to_string(PLAYER_SCORE) + "/" + to_string(AI_SCORE);
        } else if (PLAYER_SCORE < AI_SCORE) {
            return "Przegrałeś z wynikiem " + to_string(PLAYER_SCORE) + "/" + to_string(AI_SCORE);
        }
    }
    switch (state) {
        case(1):
            return "remisujesz";
        case(2):
            return "wygrywasz";
        case(3):
            return "przegrywasz";
    }

}

int main() {
    // inicjalizacja losowania liczb, gdzie seed'em jest czas
    srand(time(NULL));
    cout << "Zadanie 1\n\n---\n\n";
    int chick = 0;
    int cows = 0;
    int pigs = 0;
    cout << "Podaj liczbę kurczaków:\n";
    cin  >> chick;
    cout << "Podaj liczbę krów:\n";
    cin >> cows;
    cout << "Podaj liczbę świń\n";
    cin >> pigs;
    cout << "liczba nóg: " << farmerHad(chick, cows, pigs);
    cout << "\n\nZadanie 2\n\n---\n\n";
    int taskNum = 0;
    cout << "Podaj numer zadania (1-5)\n";
    cin >> taskNum;
    // switch do zadania 2
    switch (taskNum) {
        default: cout << "Błędne dane"; break;
        case 1: yearChecker(); break;
        case 2: numRange(); break;
        case 3: getMinAndMax(); break;
        case 4: avgAndZeroShower(); break;
        case 5: break;
    }
    cout << "\n\nZadanie 3\n\n---\n\n";
    getRobotPosition();
    cout << "\n\nZadanie 4\n\n---\n\n";
    // Zapętlam żeby 3 gierki odpaliło
    for (int i = 0; i < 3; i++) {
        int input = 0;
        int AiInput = (rand() % 3) + 1;
        cout << "Podaj kamień - 1 papier - 2 nożyczki - 3\n";
        cin >> input;
        cout << rockPaperScissors(input, AiInput) << "\n";
    }
    return 0;

}
