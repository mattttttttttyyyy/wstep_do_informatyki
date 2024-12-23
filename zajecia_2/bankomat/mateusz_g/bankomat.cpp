// Aplikacja Bankomatowa
// Kod aplikacji:
// C++
#include <iostream>
#include <string>

using namespace std;

string PIN = "1234";
const double STAN_KONTA = 1000.0;

bool sprawdz_PIN(string wprowadzony_PIN)
{
    cout << "OBECNY_PIN: " << PIN << endl;
    return wprowadzony_PIN == PIN;
}

bool zmien_PIN()
{
    string wprowadzony_PIN;
    cout << "Prosze podac PIN: ";
    cin >> wprowadzony_PIN;
    if (sprawdz_PIN(wprowadzony_PIN))
    {
        string nowy_PIN;

        cout << "Prosze podac nowy PIN: ";
        cin >> nowy_PIN;

        if (nowy_PIN.length() != 4)
        {
            cout << "PIN powinien zawierać 4 cyfry." << endl;
            return false;
        }

        string *pPIN = &PIN;
        *pPIN = nowy_PIN;

        cout << "Kod PIN został zmieniony." << endl;
        return true;
    }
    else
    {
        cout << "Podany PIN jest niepoprawny." << endl;
        return false;
    }
}

void pokaz_stan_konta(double stan_konta)
{
    cout << endl
         << "Aktualny stan konta: " << stan_konta << " PLN" << endl;
}

double wybierz_pieniadze(double stan_konta, double kwota)
{
    if (kwota > stan_konta)
    {
        cout << "Nie ma wystarczająco dużo środków na koncie. Proszę wybrać kwotę mniejszą bądź równą " << stan_konta << "." << endl;
    }
    else
    {
        return stan_konta;
    }
    return 0;
}

double wplac_pieniadze(double stan_konta, double kwota)
{
    stan_konta += kwota;
    cout << "Wplacono " << kwota << " PLN" << endl;
    return stan_konta;
}

void bankomatMainFunction(){
    string wprowadzony_PIN;
    double stan_konta = STAN_KONTA;
    int wybor;
    double kwota;
    int proby = 3;

    while (proby > 0)
    {
        cout << "Prosze podac PIN: ";
        cin >> wprowadzony_PIN;

        if (sprawdz_PIN(wprowadzony_PIN))
        {
            break;
        }
        else
        {
            proby--;
            if (proby > 0)
            {
                cout << "Podany PIN nie jest poprawny. Pozostało prób: " << proby << endl;
            }
            else
            {
                cout << "Wykorzystane zostały wszystkie 3 podejścia. Bankomat tymczasowo zablokowany. Proszę jeszcze raz uruchomić program." << endl;
                return;
            }
        }
    }
    do
    {
        cout << "1. Chcę zobaczyć aktualny stan konta" << endl;
        cout << "2. Chcę wybrać pieniądze" << endl;
        cout << "3. Chcę wpłacić pieniądze" << endl;
        cout << "4. Chcę zmienić kod PIN" << endl;
        cout << "5. Zakończ program" << endl;
        cout << "Wybierz jedną z dostępnych opcji: ";
        cin >> wybor;
        switch (wybor)
        {
        case 1:
            pokaz_stan_konta(stan_konta);
            break;
        case 2:
            cout << "Proszę podać kwotę do wypłaty: ";
            cin >> kwota;
            stan_konta = wybierz_pieniadze(stan_konta, kwota);
            break;
        case 3:
            cout << "Proszę podać kwotę do wpłaty: ";
            cin >> kwota;
            stan_konta = wplac_pieniadze(stan_konta, kwota);
            break;
        case 4:
            zmien_PIN();
            break;
        case 5:
            cout << "Dziękuję za skorzystanie z bankomatu." << endl;
            break;
        default:
            cout << "Nieprawidłowa opcja, proszę wybrać jeszcze raz (1-4)." << endl;
        }
    } while (wybor != 5 && wybor != 4);

    if (wybor == 4)
    {
       bankomatMainFunction();
    }
}

int main()
{
    
    bankomatMainFunction();
    return 0;
}

/*Opis działania:
Przedstawiony program został napisany w języku C++ i ma za zadanie imitować
działanie bankomatu. Główne menu aplikacji zawiera kilka opcji - umożliwia
użytkownikowi wprowadzenie PIN-u, sprawdzenie stanu konta, wypłatę oraz wpłatę
pieniędzy, jak również zakończenie działania programu.
Stałe i zmienne globalne, wykorzystane w programie:
PIN – stała wartość PIN-u ustawiona jest na 1234.
STAN_KONTA – początkowy stan konta wynoszący 1000.00 zł.
stan_konta – zmienna przechowująca bieżący stan konta użytkownika.
Funkcje, wykorzystywane w programie, do obsługi poszczególnych opcji:
sprawdz_PIN()
Na początku, użytkownik ma trzy próby na wprowadzenie poprawnego PIN-u - jeśli
PIN jest poprawny, użytkownik przechodzi do głównego menu, natomiast jeśli
wprowadzi błędny PIN aż trzy razy, program zostaje zakończony.
pokaz_stan_konta()
Funkcja ta wyświetla bieżący stan konta użytkownika.
wybierz_pieniadze()
Użytkownik podaje kwotę do wypłaty, a program sprawdza, czy na koncie są
wystarczające środki. Jeśli tak, pieniądze są wypłacane, a stan konta odpowiednio
zmniejszony. Jeśli nie, wyświetlany jest komunikat o niewystarczających środkach.
wplac_pieniadze()
Użytkownik podaje kwotę do wpłaty, a program zwiększa stan konta o tę kwotę.
Obsługa poszczególnych opcji odbywa się za pomocą pętli switch, która obsługuje 4
przypadki (opcje).
Program kończy się komunikatem podziękowania "Dziękuję za skorzystanie z
bankomatu.". Sprawdza także, czy wybrana przez użytkownika opcja jest prawidłowa.
Jeśli nie jest, użytkownik ma szansę na ponowne wybranie, tym razem poprawnej opcji
spośród wszystkich (1-4) dostępnych.

*/