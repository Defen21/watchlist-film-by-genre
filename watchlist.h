#ifndef WATCHLIST_H_INCLUDED
#define WATCHLIST_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

/* ========= STRUCT ========= */

struct Movie {
    string title;
    int year;
    float rating;
    Movie* next;
};

struct Relation {
    Movie* movie;
    Relation* next;
};

struct Genre {
    string name;
    Genre* next;
    Relation* relFirst;
};

/* ========= LIST ========= */

struct ListMovie {
    Movie* first;
};

struct ListGenre {
    Genre* first;
};

/* ========= CREATE ========= */
void createMovieList(ListMovie &LM);
void createGenreList(ListGenre &LG);

/* ========= ALLOCATE ========= */
Movie* allocateMovie(string title, int year, float rating);
Genre* allocateGenre(string name);
Relation* allocateRelation(Movie* M);

/* ========= INSERT ========= */
// Genre
void insertFirstGenre(ListGenre &LG, Genre* P);
void insertLastGenre(ListGenre &LG, Genre* P);
void insertAfterGenre(Genre* Prec, Genre* P);

// Movie
void insertFirstMovie(ListMovie &LM, Movie* P);
void insertLastMovie(ListMovie &LM, Movie* P);
void insertAfterMovie(Movie* Prec, Movie* P);

// Relation
void connectGenreMovie(Genre* G, Movie* M);

/* ========= DELETE ========= */
// Genre
void deleteFirstGenre(ListGenre &LG, Genre* &P);
void deleteLastGenre(ListGenre &LG, Genre* &P);
void deleteAfterGenre(Genre* Prec, Genre* &P);

// Movie
void deleteFirstMovie(ListMovie &LM, Movie* &P);
void deleteLastMovie(ListMovie &LM, Movie* &P);
void deleteAfterMovie(Movie* Prec, Movie* &P);

// Relation
void deleteRelation(Genre* G, Movie* M);

/* ========= FIND ========= */
Genre* findGenre(ListGenre LG, string name);
Movie* findMovie(ListMovie LM, string title);

/* ========= SHOW ========= */
void showAllGenres(ListGenre LG);
void showAllMovies(ListMovie LM);
void showAllGenreWithMovies(ListGenre LG);
void showMovieWithGenres(ListGenre LG, ListMovie LM);
void showGenresOfMovie(ListGenre LG, Movie* M);

/* ========= COUNT ========= */
int countRelationGenre(Genre* G);
int countRelationMovie(ListGenre LG, Movie* M);
int countUnrelatedMovies(ListGenre LG, ListMovie LM);

/* ========= EDIT ========= */
void editRelation(Genre* G, Movie* oldM, Movie* newM);

#endif // WATCHLIST_H_INCLUDED
