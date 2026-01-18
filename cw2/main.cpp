#include <iostream>
using namespace std;

// zadanie 1
// Napisz program, który dla dwóch podanych przez użytkownika wartości (0 lub 1)
// dla wyrażeń p i q wypisze ich:
// • negację,
// • koniunkcję,
// • alternatywę,
// • implikacje,
// • równoważność.
// Napisz odpowiednie funkcje dla powyższych z operacji.

// Implikacja to po prostu instrukcja warunkowa w formie zapisu tautologicznego/matematycznego???
// bo nie rozumiem dlaczego daje 1 kiedy p jest równe 0, jakie to ma zastosowanie?
// bo rozumiem jak to działa, ale nie rozumiem po co to nam jak da się to zapisać kombinacją równań tautologicznych.
// np (p /\ q) \/ -p
bool implication(bool p, bool q) {
    bool implcatiom = true;
    if(p && q == 0) {
        implcatiom = false;
    }
    return implcatiom;
}

// innych operatorów logicznych nie wrzucałem do funkcji bo po co odkrywać koło na nowo, to jest marnowanie energi
void tautologion(bool p, bool q) {
    cout << "Negacja dla p: " << !p << "\n";
    cout << "Negacja dla q: " << !q << "\n";
    cout << "Koniunkcja: " << (p && q) << "\n";
    cout << "Alternatywa: " <<  (p || q) << "\n";
    cout << "Implikacja: " <<  (implication(p, q)) << "\n";
    cout << "Równoznaczność: " << (p == q) << "\n";
}
/*
*a) p ∧ q
• b) p ∨ q
• c) ¬p ∧ (p ∨ q)
• d) (p ∧ r) → q
• e) ¬(p (q ∨ r))
• f) [(𝑝→𝑟)∨¬𝑞] [𝑝→(𝑟∧¬𝑞)]
• g) [(¬𝑟∨𝑞)∨¬(𝑞∧𝑟)]→[¬(𝑞→𝑝)]
Następnie stwórz program, który na podstawie zdań prostych p, q, r wypisze wartości
powyższych zdań złożonych. Zastosuj funkcje, które zwrócą wynik implikacji i równoważności w
zależności od podanych argumentów. Wykorzystaj operatory logiczne oraz stworzone funkcje
do oceny prawdziwości powyższych zdań złożonych.
*/

// nie użyłem tego wcześniej bo teraz to rozkminiłem żeby wsadzić po prostu do funkcji xd
void outputLogic(string prettyText, bool expression) {
    cout << prettyText << expression << "\n";
}

void logic(bool p, bool q, bool r) {
    outputLogic("a) p ∧ q: ", (p&&q));
    outputLogic("b) p ∨ q: ", (p || q));
    outputLogic("c) ¬p ∧ (p ∨ q): ", !p && (p || q));
    outputLogic("d) (p ∧ r) → q: ", implication(p && r, q));
    outputLogic("e) ¬(p<>(q ∨ r)): ", !(p==(q&&r)));
    outputLogic("f) [(𝑝→𝑟)∨¬𝑞]<>[𝑝→(𝑟∧¬𝑞)]: ", (implication(p,r)||!q)==implication(p,(r&&!q)));
    outputLogic("g) [(¬𝑟∨𝑞)∨¬(𝑞∧𝑟)]→[¬(𝑞→𝑝)]: ", implication( (!r||q) || !(q&&r), !implication(q,p) ));

}

int main() {
    cout << "Podaj P: ";
    bool p,q,r;
    cin >> p;
    cout << "Podaj Q: ";
    cin >> q;
    cout << "Podaj R: ";
    cin >> r;
    tautologion(p, q);
    cout << "\n Zadanie 2 \n";
    logic(p, q, r);
    return 0;
}
