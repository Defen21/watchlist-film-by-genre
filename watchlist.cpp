#include "watchlist.h"

void createList(List &L) { L.first = NULL; }

address allocate(infotype data) {
  address P = new element;
  P->info = data;
  P->next = NULL;
  return P;
}

void deallocate(address &P) {
  delete P;
  P = NULL;
}

void insertLast(List &L, address P) {
  if (L.first == NULL) {
    L.first = P;
  } else {
    address Q = L.first;
    while (Q->next != NULL) {
      Q = Q->next;
    }
    Q->next = P;
  }
}

void deleteMovie(List &L, string title, address &P) {
  P = NULL;
  if (L.first == NULL) {
    return;
  }

  if (L.first->info.title == title) {
    P = L.first;
    L.first = L.first->next;
    P->next = NULL;
  } else {
    address Q = L.first;
    while (Q->next != NULL && Q->next->info.title != title) {
      Q = Q->next;
    }
    if (Q->next != NULL) {
      P = Q->next;
      Q->next = P->next;
      P->next = NULL;
    }
  }
}

void showList(List L) {
  if (L.first == NULL) {
    cout << "Watchlist is empty." << endl;
  } else {
    address P = L.first;
    int i = 1;
    while (P != NULL) {
      cout << "Movie " << i << ":" << endl;
      cout << "  Title : " << P->info.title << endl;
      cout << "  Year  : " << P->info.year << endl;
      cout << "  Rating: " << P->info.rating << endl;
      cout << "  Genre : " << P->info.genre << endl;
      cout << "--------------------------" << endl;
      P = P->next;
      i++;
    }
  }
}

infotype createMovie(string title, int year, float rating, string genre) {
  infotype data;
  data.title = title;
  data.year = year;
  data.rating = rating;
  data.genre = genre;
  return data;
}
