#include <iostream>
#include <queue>
#include <string>
#include <limits> // for numeric_limits

using namespace std;

int n;
int ilosc_wyrazen;

// TODO
/*
    Przykładowe wykorzystanie metody generujacej liczby losowe - t[i] = rand() % 1000 + 1;
    Liczba całkowicie randomowa (reset czasem procesora) - srand(time(NULL));
*/

int main(){
    queue<int> q;

    cout<<"How many elements add to? : ";
    cin>>ilosc_wyrazen;

    int tab[ilosc_wyrazen];

    for(int i=0; i<ilosc_wyrazen; i++)
    {
        tab[i] = rand() % 1000 + 1;
        cout << "Adding " << tab[i] << endl;


        // while (true) {
        //     cout << "Add element : ";
        //     cin >> tab[i];
        //     if(cin.fail()) {
        //         // Clear the error flag
        //         cin.clear();
        //         // Ignore the rest of the line
        //         cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //         cout << "Invalid input. Please enter an integer." << endl;
        //     } else {
        //         cout << "You entered: " << tab[i] << endl;
        //         break;
        //     }
        // }
    }

    for(int i=0;i<ilosc_wyrazen; i++)
    {
        int x=tab[i];
        q.push(x);
    }

    cout << "Now, retrieve those values in FIFO order.\n";

    while(!q.empty()) {
        cout << "Popping ";
        cout << q.front() << "\n";
        q.pop();
    }
    cout << endl;

    return 0;
}