
#include <iostream>
#include <string>

using namespace std;

int main( )
{
  string s;
  int i;

// odczytujemy wiersz znaków

  cout << "Provide text: ";

  getline ( cin, s );

  cout << endl;

  int mode = 0;

  while (mode != 1 && mode != 2) {
    cout << "Podajj tryb: 1 - szyfruj, 2 - deszyfruj: ";

    cin >> mode;
  }

  int delta = 0;

  while (delta % 26 == 0) {
    cout << "Podaj odstep: ";

    cin >> delta;
  }

  if (mode == 2) {
    delta = -delta;
  }

// zamieniamy małe litery na duże
// i kodujemy szyfrem cezara

  for( i = 0; i < s.length( ); i++ )
  {
    s [ i ] = toupper ( s [ i ] );
    if( ( s [ i ] >= 'A' ) && ( s [ i ] <= 'Z' ) ) s [ i ] = char ( 65 + ( s [ i ] - 65 + delta ) % 26 );
  }

// wypisujemy zaszyfrowany tekst

  cout << s << endl << endl;
  return 0;
}