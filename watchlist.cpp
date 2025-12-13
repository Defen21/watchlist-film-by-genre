#include "watchlist.h"

/* ================= CREATE ================= */

void createGenreList(ListGenre &LG) {
    LG.first = nullptr;
}

void createMovieList(ListMovie &LM) {
    LM.first = nullptr;
}

/* ================= ALLOCATE ================= */

adrGenre allocateGenre(string name) {
    adrGenre P = new elmGenre;
    P->info.name = name;
    P->next = nullptr;
    P->relFirst = nullptr;
    return P;
}

adrMovie allocateMovie(string title, int year, float rating) {
    adrMovie P = new elmMovie;
    P->info.title = title;
    P->info.year = year;
    P->info.rating = rating;
    P->next = nullptr;
    return P;
}

adrRelation allocateRelation(adrMovie M) {
    adrRelation R = new elmRelation;
    R->child = M;
    R->next = nullptr;
    return R;
}

/* ================= INSERT ================= */

void insertFirstGenre(ListGenre &LG, adrGenre P) {
    P->next = LG.first;
    LG.first = P;
}

void insertLastGenre(ListGenre &LG, adrGenre P) {
    if (LG.first == nullptr)
        LG.first = P;
    else {
        adrGenre Q = LG.first;
        while (Q->next != nullptr)
            Q = Q->next;
        Q->next = P;
    }
}

void insertFirstMovie(ListMovie &LM, adrMovie P) {
    P->next = LM.first;
    LM.first = P;
}

void insertLastMovie(ListMovie &LM, adrMovie P) {
    if (LM.first == nullptr)
        LM.first = P;
    else {
        adrMovie Q = LM.first;
        while (Q->next != nullptr)
            Q = Q->next;
        Q->next = P;
    }
}

/* ================= RELATION ================= */

void connectGenreMovie(adrGenre G, adrMovie M) {
    adrRelation R = allocateRelation(M);
    if (G->relFirst == nullptr)
        G->relFirst = R;
    else {
        adrRelation Q = G->relFirst;
        while (Q->next != nullptr)
            Q = Q->next;
        Q->next = R;
    }
}

/* ================= FIND ================= */

adrGenre findGenre(ListGenre LG, string name) {
    adrGenre P = LG.first;
    while (P != nullptr) {
        if (P->info.name == name)
            return P;
        P = P->next;
    }
    return nullptr;
}

adrMovie findMovie(ListMovie LM, string title) {
    adrMovie P = LM.first;
    while (P != nullptr) {
        if (P->info.title == title)
            return P;
        P = P->next;
    }
    return nullptr;
}

/* ================= SHOW ================= */

void showAllGenres(ListGenre LG) {
    adrGenre G = LG.first;
    while (G != nullptr) {
        cout << "- " << G->info.name << endl;
        G = G->next;
    }
}

void showAllMovies(ListMovie LM) {
    adrMovie M = LM.first;
    while (M != nullptr) {
        cout << "- " << M->info.title
             << " (" << M->info.year << ")"
             << " | Rating: " << M->info.rating << endl;
        M = M->next;
    }
}

void showAllGenreWithMovies(ListGenre LG) {
    adrGenre G = LG.first;
    while (G != nullptr) {
        cout << "Genre: " << G->info.name << endl;
        adrRelation R = G->relFirst;

        if (R == nullptr)
            cout << "  (Tidak ada movie)" << endl;

        while (R != nullptr) {
            cout << "  - " << R->child->info.title
                 << " (" << R->child->info.year << ")"
                 << " | Rating: " << R->child->info.rating << endl;
            R = R->next;
        }
        G = G->next;
    }
}

void showMovieWithGenres(ListGenre LG, ListMovie LM) {
    adrMovie M = LM.first;
    while (M != nullptr) {
        cout << "Movie: " << M->info.title
             << " (" << M->info.year << ")"
             << " | Rating: " << M->info.rating
             << " | Genre: ";

        bool found = false;
        adrGenre G = LG.first;

        while (G != nullptr) {
            adrRelation R = G->relFirst;
            while (R != nullptr) {
                if (R->child == M) {
                    cout << G->info.name << " ";
                    found = true;
                }
                R = R->next;
            }
            G = G->next;
        }

        if (!found)
            cout << "Tidak ada";
        cout << endl;
        M = M->next;
    }
}

/* ================= COUNT ================= */

int countRelationMovie(ListGenre LG, adrMovie M) {
    int count = 0;
    adrGenre G = LG.first;
    while (G != nullptr) {
        adrRelation R = G->relFirst;
        while (R != nullptr) {
            if (R->child == M)
                count++;
            R = R->next;
        }
        G = G->next;
    }
    return count;
}

int countUnrelatedMovies(ListGenre LG, ListMovie LM) {
    int count = 0;
    adrMovie M = LM.first;
    while (M != nullptr) {
        if (countRelationMovie(LG, M) == 0)
            count++;
        M = M->next;
    }
    return count;
}
