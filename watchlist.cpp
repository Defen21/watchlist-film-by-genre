#include "watchlist.h"
#include <iostream>
using namespace std;

/* ========= CREATE ========= */
void createMovieList(ListMovie &LM) {
    LM.first = nullptr;
}

void createGenreList(ListGenre &LG) {
    LG.first = nullptr;
}

/* ========= ALLOCATE ========= */
Movie* allocateMovie(string title, int year, float rating) {
    Movie* P = new Movie;
    P->title = title;
    P->year = year;
    P->rating = rating;
    P->next = nullptr;
    return P;
}

Genre* allocateGenre(string name) {
    Genre* P = new Genre;
    P->name = name;
    P->next = nullptr;
    P->relFirst = nullptr;
    return P;
}

Relation* allocateRelation(Movie* M) {
    Relation* R = new Relation;
    R->movie = M;
    R->next = nullptr;
    return R;
}

/* ========= INSERT GENRE ========= */
void insertFirstGenre(ListGenre &LG, Genre* P) {
    P->next = LG.first;
    LG.first = P;
}

void insertLastGenre(ListGenre &LG, Genre* P) {
    if (LG.first == nullptr)
        LG.first = P;
    else {
        Genre* Q = LG.first;
        while (Q->next != nullptr)
            Q = Q->next;
        Q->next = P;
    }
}

void insertAfterGenre(Genre* Prec, Genre* P) {
    if (Prec != nullptr) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

/* ========= INSERT MOVIE ========= */
void insertFirstMovie(ListMovie &LM, Movie* P) {
    P->next = LM.first;
    LM.first = P;
}

void insertLastMovie(ListMovie &LM, Movie* P) {
    if (LM.first == nullptr)
        LM.first = P;
    else {
        Movie* Q = LM.first;
        while (Q->next != nullptr)
            Q = Q->next;
        Q->next = P;
    }
}

void insertAfterMovie(Movie* Prec, Movie* P) {
    if (Prec != nullptr) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

/* ========= RELATION ========= */
void connectGenreMovie(Genre* G, Movie* M) {
    Relation* R = allocateRelation(M);
    R->next = G->relFirst;
    G->relFirst = R;
}

/* ========= DELETE GENRE ========= */
void deleteFirstGenre(ListGenre &LG, Genre* &P) {
    if (LG.first != nullptr) {
        P = LG.first;
        LG.first = P->next;
        P->next = nullptr;
    }
}

void deleteLastGenre(ListGenre &LG, Genre* &P) {
    if (LG.first != nullptr) {
        Genre* Q = LG.first;
        if (Q->next == nullptr) {
            P = Q;
            LG.first = nullptr;
        } else {
            while (Q->next->next != nullptr)
                Q = Q->next;
            P = Q->next;
            Q->next = nullptr;
        }
    }
}

void deleteAfterGenre(Genre* Prec, Genre* &P) {
    if (Prec != nullptr && Prec->next != nullptr) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = nullptr;
    }
}

/* ========= DELETE MOVIE ========= */
void deleteFirstMovie(ListMovie &LM, Movie* &P) {
    if (LM.first != nullptr) {
        P = LM.first;
        LM.first = P->next;
        P->next = nullptr;
    }
}

void deleteLastMovie(ListMovie &LM, Movie* &P) {
    if (LM.first != nullptr) {
        Movie* Q = LM.first;
        if (Q->next == nullptr) {
            P = Q;
            LM.first = nullptr;
        } else {
            while (Q->next->next != nullptr)
                Q = Q->next;
            P = Q->next;
            Q->next = nullptr;
        }
    }
}

void deleteAfterMovie(Movie* Prec, Movie* &P) {
    if (Prec != nullptr && Prec->next != nullptr) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = nullptr;
    }
}

/* ========= DELETE RELATION ========= */
void deleteRelation(Genre* G, Movie* M) {
    Relation* R = G->relFirst;
    Relation* prev = nullptr;

    while (R != nullptr && R->movie != M) {
        prev = R;
        R = R->next;
    }

    if (R != nullptr) {
        if (prev == nullptr)
            G->relFirst = R->next;
        else
            prev->next = R->next;
        delete R;
    }
}

/* ========= FIND ========= */
Genre* findGenre(ListGenre LG, string name) {
    Genre* G = LG.first;
    while (G != nullptr) {
        if (G->name == name)
            return G;
        G = G->next;
    }
    return nullptr;
}

Movie* findMovie(ListMovie LM, string title) {
    Movie* M = LM.first;
    while (M != nullptr) {
        if (M->title == title)
            return M;
        M = M->next;
    }
    return nullptr;
}

/* ========= SHOW ========= */
void showAllGenres(ListGenre LG) {
    Genre* G = LG.first;
    while (G != nullptr) {
        cout << G->name << endl;
        G = G->next;
    }
}

void showAllMovies(ListMovie LM) {
    Movie* M = LM.first;
    while (M != nullptr) {
        cout << M->title << " (" << M->year
             << ") rating " << M->rating << endl;
        M = M->next;
    }
}

void showAllGenreWithMovies(ListGenre LG) {
    Genre* G = LG.first;
    while (G != nullptr) {
        cout << G->name << ":\n";
        Relation* R = G->relFirst;
        while (R != nullptr) {
            cout << "  - " << R->movie->title << endl;
            R = R->next;
        }
        G = G->next;
    }
}

void showMovieWithGenres(ListGenre LG, ListMovie LM) {
    Movie* M = LM.first;
    while (M != nullptr) {
        cout << M->title << ":\n";
        showGenresOfMovie(LG, M);
        M = M->next;
    }
}

void showGenresOfMovie(ListGenre LG, Movie* M) {
    Genre* G = LG.first;
    bool found = false;

    while (G != nullptr) {
        Relation* R = G->relFirst;
        while (R != nullptr) {
            if (R->movie == M) {
                cout << "  - " << G->name << endl;
                found = true;
            }
            R = R->next;
        }
        G = G->next;
    }

    if (!found)
        cout << "  (tidak ada genre)\n";
}

/* ========= COUNT ========= */
int countRelationGenre(Genre* G) {
    int count = 0;
    Relation* R = G->relFirst;
    while (R != nullptr) {
        count++;
        R = R->next;
    }
    return count;
}

int countRelationMovie(ListGenre LG, Movie* M) {
    int count = 0;
    Genre* G = LG.first;

    while (G != nullptr) {
        Relation* R = G->relFirst;
        while (R != nullptr) {
            if (R->movie == M)
                count++;
            R = R->next;
        }
        G = G->next;
    }
    return count;
}

int countUnrelatedMovies(ListGenre LG, ListMovie LM) {
    int count = 0;
    Movie* M = LM.first;

    while (M != nullptr) {
        if (countRelationMovie(LG, M) == 0)
            count++;
        M = M->next;
    }
    return count;
}

/* ========= EDIT ========= */
void editRelation(Genre* G, Movie* oldM, Movie* newM) {
    Relation* R = G->relFirst;
    while (R != nullptr) {
        if (R->movie == oldM) {
            R->movie = newM;
            return;
        }
        R = R->next;
    }
}
