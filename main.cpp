#include "watchlist.h"
#include <iostream>
using namespace std;

int main() {
    ListGenre LG;
    ListMovie LM;
    createGenreList(LG);
    createMovieList(LM);

    int choice;
    string gName, title, title2;

    do {
        cout << "\n=== WATCHLIST MULTI LINKED LIST ===\n";
        cout << "1.  Tambah Genre\n";
        cout << "2.  Tambah Movie\n";
        cout << "3.  Hubungkan Genre - Movie\n";
        cout << "4.  Tampilkan Semua Genre\n";
        cout << "5.  Tampilkan Semua Movie\n";
        cout << "6.  Tampilkan Genre + Movie\n";
        cout << "7.  Tampilkan Movie + Genre\n";
        cout << "8.  Hitung Movie tanpa Genre\n";
        cout << "9.  Delete Genre (First)\n";
        cout << "10. Delete Genre (Last)\n";
        cout << "11. Delete Genre (After)\n";
        cout << "12. Delete Movie (First)\n";
        cout << "13. Delete Movie (Last)\n";
        cout << "14. Delete Movie (After)\n";
        cout << "15. Delete Relasi\n";
        cout << "16. Edit Relasi\n";
        cout << "17. Tampilkan Genre dari Movie\n";
        cout << "0.  Exit\n";
        cout << "Pilih: ";
        cin >> choice;
        cin.ignore();

        /* ===== INSERT ===== */
        if (choice == 1) {
            cout << "Nama Genre: ";
            getline(cin, gName);
            insertLastGenre(LG, allocateGenre(gName));
        }
        else if (choice == 2) {
            int year;
            float rating;
            cout << "Judul Movie: ";
            getline(cin, title);
            cout << "Tahun: ";
            cin >> year;
            cout << "Rating: ";
            cin >> rating;
            cin.ignore();
            insertLastMovie(LM, allocateMovie(title, year, rating));
        }
        else if (choice == 3) {
            cout << "Nama Genre: ";
            getline(cin, gName);
            cout << "Judul Movie: ";
            getline(cin, title);
            Genre* G = findGenre(LG, gName);
            Movie* M = findMovie(LM, title);
            if (G && M)
                connectGenreMovie(G, M);
            else
                cout << "Genre atau Movie tidak ditemukan\n";
        }

        /* ===== SHOW ===== */
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

        /* ===== DELETE GENRE ===== */
        else if (choice == 9) {
            Genre* P;
            deleteFirstGenre(LG, P);
        }
        else if (choice == 10) {
            Genre* P;
            deleteLastGenre(LG, P);
        }
        else if (choice == 11) {
            cout << "Nama Genre sebelumnya: ";
            getline(cin, gName);
            Genre* Prec = findGenre(LG, gName);
            Genre* P;
            if (Prec)
                deleteAfterGenre(Prec, P);
            else
                cout << "Genre tidak ditemukan\n";
        }

        /* ===== DELETE MOVIE ===== */
        else if (choice == 12) {
            Movie* P;
            deleteFirstMovie(LM, P);
        }
        else if (choice == 13) {
            Movie* P;
            deleteLastMovie(LM, P);
        }
        else if (choice == 14) {
            cout << "Judul Movie sebelumnya: ";
            getline(cin, title);
            Movie* Prec = findMovie(LM, title);
            Movie* P;
            if (Prec)
                deleteAfterMovie(Prec, P);
            else
                cout << "Movie tidak ditemukan\n";
        }

        /* ===== RELATION ===== */
        else if (choice == 15) {
            cout << "Nama Genre: ";
            getline(cin, gName);
            cout << "Judul Movie: ";
            getline(cin, title);
            Genre* G = findGenre(LG, gName);
            Movie* M = findMovie(LM, title);
            if (G && M)
                deleteRelation(G, M);
            else
                cout << "Genre atau Movie tidak ditemukan\n";
        }
        else if (choice == 16) {
            cout << "Nama Genre: ";
            getline(cin, gName);
            cout << "Movie Lama: ";
            getline(cin, title);
            cout << "Movie Baru: ";
            getline(cin, title2);

            Genre* G = findGenre(LG, gName);
            Movie* oldM = findMovie(LM, title);
            Movie* newM = findMovie(LM, title2);

            if (G && oldM && newM)
                editRelation(G, oldM, newM);
            else
                cout << "Data tidak ditemukan\n";
        }
        else if (choice == 17) {
            cout << "Judul Movie: ";
            getline(cin, title);
            Movie* M = findMovie(LM, title);
            if (M)
                showGenresOfMovie(LG, M);
            else
                cout << "Movie tidak ditemukan\n";
        }

    } while (choice != 0);

    return 0;
}
