#ifndef WATCHLIST_H
#define WATCHLIST_H

#include <iostream>
#include <string>

using namespace std;

struct infotype {
  string title;
  int year;
  float rating;
  string genre;
};

struct element;
typedef element *address;

struct element {
  infotype info;
  address next;
};

struct List {
  address first;
};

void createList(List &L);
address allocate(infotype data);
void deallocate(address &P);
void insertLast(List &L, address P);
void showList(List L);
infotype createMovie(string title, int year, float rating, string genre);

#endif
