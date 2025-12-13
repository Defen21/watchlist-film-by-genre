#include "watchlist.h"
#include <iostream>
using namespace std;

int main() {
    ListGenre LG;
    ListMovie LM;
    createGenreList(LG);
    createMovieList(LM);

    int choice;
    string gName, title;
    int year;
    float rating;

    do {
        cout << "\n=== WATCHLIST MULTI LINKED LIST ===\n";
        cout << "1. Tambah Genre\n";
        cout << "2. Tambah Movie\n";
        cout << "3. Hubungkan Genre - Movie\n";
        cout << "4. Tampilkan Semua Genre\n";
        cout << "5. Tampilkan Semua Movie\n";
        cout << "6. Tampilkan Genre + Movie\n";
        cout << "7. Tampilkan Movie + Genre\n";
        cout << "8. Hitung Movie tanpa Genre\n";
        cout << "0. Exit\n";
        cout << "Pilih: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            cout << "Nama Genre: ";
            getline(cin, gName);
            insertLastGenre(LG, allocateGenre(gName));
        }
        else if (choice == 2) {
            cout << "Judul: ";
            getline(cin, title);
            cout << "Tahun: ";
            cin >> year;
            cout << "Rating: ";
            cin >> rating;
            cin.ignore();
            insertLastMovie(LM, allocateMovie(title, year, rating));
        }
        else if (choice == 3) {
            cout << "Genre: ";
            getline(cin, gName);
            cout << "Movie: ";
            getline(cin, title);

            adrGenre G = findGenre(LG, gName);
            adrMovie M = findMovie(LM, title);

            if (G && M)
                connectGenreMovie(G, M);
            else
                cout << "Genre atau Movie tidak ditemukan!\n";
        }
        else if (choice == 4)
            showAllGenres(LG);
        else if (choice == 5)
            showAllMovies(LM);
        else if (choice == 6)
            showAllGenreWithMovies(LG);
        else if (choice == 7)
            showMovieWithGenres(LG, LM);
        else if (choice == 8)
            cout << "Movie tanpa genre: "
                 << countUnrelatedMovies(LG, LM) << endl;

    } while (choice != 0);

    return 0;
}
