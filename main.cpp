#include <iostream>
using namespace std;

signed int cautare(unsigned int vector[], unsigned int interval_size, unsigned int &stanga, unsigned int &dreapta, unsigned int valoare_cautata) {
    while (stanga <= dreapta) {
        unsigned int mijloc1 = stanga + (dreapta - stanga) / 2;
        unsigned int mijloc2 = stanga + (dreapta - stanga) / 2 + 1;

        if (valoare_cautata < vector[mijloc1])
            dreapta = mijloc1 - 1;
        else if (valoare_cautata == vector[mijloc1])
            return mijloc1;
        else if (valoare_cautata > vector[mijloc1] && valoare_cautata < vector[mijloc2]) {
            stanga = mijloc1 + 1;
            dreapta = mijloc2 - 1;
            return 0; // Indicate that we need to continue searching
        }
        else if (valoare_cautata == vector[mijloc2])
            return mijloc2;
        else if (valoare_cautata > vector[mijloc2])
            stanga = mijloc2 + 1;
    }
    return -1; // Handle the case when the value is not found
}

int main() {
    cout << "\tHELLO! Si bine ati venit la cautare pe intervale:\n";
    unsigned int vector[] = {1, 5, 7, 9, 10, 12, 14, 15, 17, 19, 23, 25, 26, 30, 31, 37};
    unsigned int number_of_intervals;
    unsigned int interval_size;
    signed int rezultat;
    unsigned int stanga = 0;
    unsigned int dreapta = sizeof(vector) / sizeof(vector[0]) - 1;
    unsigned int valoare_cautata;

    cout << "Alegeti numarul cautat: ";
    cin >> valoare_cautata;

    cout << "Alegeti in cate intervale doriti sa impartiti la fiecare apel al functiei cautare: ";
    cin >> number_of_intervals;

    do {
        interval_size = (dreapta - stanga + 1) / number_of_intervals;
        rezultat = cautare(vector, interval_size, stanga, dreapta, valoare_cautata);
    } while (rezultat == 0);

    if (rezultat != -1)
        cout << "Valoarea cautata se afla la pozitia " << rezultat << ".\n";
    else
        cout << "Valoarea cautata nu a fost gasita.\n";

    return 0;
}
