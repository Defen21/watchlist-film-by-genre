#include "watchlist.h"
#include <iostream>

using namespace std;

int main() {
  List L;
  createList(L);

  int choice;
  string title, genre;
  int year;
  float rating;
  address P;

  choice = -1;

  while (choice != 0) {
    cout << "=== MOVIE WATCHLIST ===" << endl;
    cout << "1. Add Movie" << endl;
    cout << "2. View Watchlist" << endl;
    cout << "0. Exit" << endl;
    cout << "Choice: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
      cout << "Enter Title: ";
      getline(cin, title);
      cout << "Enter Year: ";
      cin >> year;
      cout << "Enter Rating: ";
      cin >> rating;
      cin.ignore();
      cout << "Enter Genre: ";
      getline(cin, genre);

      P = allocate(createMovie(title, year, rating, genre));
      insertLast(L, P);

      cout << "Movie added!" << endl;
    } else if (choice == 2) {
      showList(L);
    } else if (choice == 0) {
      cout << "Exiting..." << endl;
    } else {
      cout << "Invalid choice." << endl;
    }
    cout << endl;
  }

  return 0;
}
