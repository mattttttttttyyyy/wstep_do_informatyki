// Sortowanie bąbelkowe
// dawidex44
// www.algoryt,.org

#include <iostream>
// #include <conio.h>
#include <chrono>

using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    int schowek, zamiana, ilosc, zakres; // deklaracja zmiennych, przypisanie liczb do tablicy

    cout << "Wpisz ilosc liczb: ";
    cin >> ilosc;

    cout << "Wpisz zakres liczb ";
    cin >> zakres;

    int t[ilosc] = {};

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < ilosc; i++)
    {
        int losowa_liczba = rand() % zakres;
        cout << "Wygenerowana liczba: " << endl
             << losowa_liczba << endl;
        t[i] = losowa_liczba;
    }

    do
    {
        zamiana = 0; // przed każdym "przejazdem" pętli for zmienna zamiana jest zerowana
        for (int i = 0; i < ilosc; i++)
        {
            if (t[i] > t[i + 1]) // jeśli element tablicy jest większy od następnego elementu
            {
                zamiana = zamiana + 1; // jeśli jest jakaś zmiana, to zmienne zamiana powiększa swoją wartość
                schowek = t[i];        // wartość t[i] jest kopiowana do schowka
                t[i] = t[i + 1];       // t[i] przyjmuje wartość następnego elementu, gdyż jest on mniejszy
                t[i + 1] = schowek;    // kolejny element tablicy przejmuje wcześniejszą wartość poprzedniego elementu, gdyż jest on większy
            }
        }
    } while (zamiana != 0); // jeśli zmienna zamiana miałaby wartość 0, oznaczałoby to że nie dokonano żadnych zmian, a więc nie ma potrzeby dalszego sortowania

    auto finish = std::chrono::high_resolution_clock::now();

    for (int j = 0; j <= ilosc; j++)
    {
        cout << t[j] << " \n"; // wypisanie posortowanych liczb
    }

    cout << std::chrono::duration_cast<std::chrono::nanoseconds>((finish - start) / 1000000000).count() << "s\n";

    // getch();
    return 0;
}