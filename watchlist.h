#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

/* ================= CHILD (MOVIE) ================= */

struct Movie {
    string title;
    int year;
    float rating;
};

struct elmMovie;
typedef elmMovie* adrMovie;

struct elmMovie {
    Movie info;
    adrMovie next;
};

struct ListMovie {
    adrMovie first;
};

/* ================= RELATION ================= */

struct elmRelation;
typedef elmRelation* adrRelation;

struct elmRelation {
    adrMovie child;
    adrRelation next;
};

/* ================= PARENT (GENRE) ================= */

struct Genre {
    string name;
};

struct elmGenre;
typedef elmGenre* adrGenre;

struct elmGenre {
    Genre info;
    adrGenre next;
    adrRelation relFirst;
};

struct ListGenre {
    adrGenre first;
};

/* ================= CREATE ================= */

void createGenreList(ListGenre &LG);
void createMovieList(ListMovie &LM);

/* ================= ALLOCATE ================= */

adrGenre allocateGenre(string name);
adrMovie allocateMovie(string title, int year, float rating);
adrRelation allocateRelation(adrMovie M);

/* ================= INSERT GENRE ================= */

void insertFirstGenre(ListGenre &LG, adrGenre P);
void insertLastGenre(ListGenre &LG, adrGenre P);
void insertAfterGenre(adrGenre Prec, adrGenre P);

/* ================= DELETE GENRE ================= */

void deleteFirstGenre(ListGenre &LG, adrGenre &P);
void deleteLastGenre(ListGenre &LG, adrGenre &P);
void deleteAfterGenre(adrGenre Prec, adrGenre &P);

/* ================= INSERT MOVIE ================= */

void insertFirstMovie(ListMovie &LM, adrMovie P);
void insertLastMovie(ListMovie &LM, adrMovie P);
void insertAfterMovie(adrMovie Prec, adrMovie P);

/* ================= DELETE MOVIE ================= */

void deleteFirstMovie(ListMovie &LM, adrMovie &P);
void deleteLastMovie(ListMovie &LM, adrMovie &P);
void deleteAfterMovie(adrMovie Prec, adrMovie &P);

/* ================= RELATION ================= */

void connectGenreMovie(adrGenre G, adrMovie M);

/* ================= FIND ================= */

adrGenre findGenre(ListGenre LG, string name);
adrMovie findMovie(ListMovie LM, string title);

/* ================= SHOW ================= */

void showAllGenres(ListGenre LG);
void showAllMovies(ListMovie LM);
void showMoviesOfGenre(adrGenre G);
void showAllGenreWithMovies(ListGenre LG);
void showMovieWithGenres(ListGenre LG, ListMovie LM);

/* ================= COUNT ================= */

int countRelationGenre(adrGenre G);
int countRelationMovie(ListGenre LG, adrMovie M);
int countUnrelatedMovies(ListGenre LG, ListMovie LM);

#endif
