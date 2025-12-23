## **TUGAS BESAR STRUKTUR DATA**

### **Judul**

*Aplikasi Manajemen Watchlist Film Berbasis Genre Menggunakan Multi-Linked List*

## **Deskripsi**

Aplikasi Manajemen Watchlist Film ini dirancang untuk membantu pengguna dalam mengelola daftar film yang ingin ditonton secara terstruktur dan terorganisir. Film-film pada watchlist dapat dikelompokkan berdasarkan *genre*, sehingga memudahkan pengguna dalam pencarian, pengelolaan, serta analisis data film.

Program ini mengimplementasikan *struktur data Multi-Linked List (Relasi One-to-Many)*, di mana:

* *Satu Genre* dapat memiliki *banyak Movie*
* *Satu Movie* dapat terhubung ke *lebih dari satu Genre*

Struktur ini memungkinkan pengelolaan data yang fleksibel dan efisien, terutama dalam menangani relasi antar data film dan genre.

## **Struktur Data yang Digunakan**

1. *List Parent (Genre)*
   Menyimpan daftar genre film, seperti Action, Drama, Comedy, dan lain-lain.

2. *List Child (Movie)*
   Menyimpan data film yang terdiri dari:

   * Judul film
   * Tahun rilis
   * Rating

3. *List Relasi (Relation)*
   Menghubungkan Genre dengan Movie, membentuk relasi *many-to-many* secara implementasi melalui multi-linked list.

## **Fitur dan Menu Aplikasi**

Aplikasi menyediakan menu interaktif sebagai berikut:

1. Menambahkan genre baru
2. Menambahkan movie baru
3. Menghubungkan genre dengan movie
4. Menampilkan seluruh genre
5. Menampilkan seluruh movie
6. Menampilkan genre beserta movie yang terhubung
7. Menampilkan movie beserta genre yang dimilikinya
8. Menghitung jumlah movie yang tidak memiliki genre
9. Menghapus genre pertama
10. Menghapus genre terakhir
11. Menghapus genre setelah genre tertentu
12. Menghapus movie pertama
13. Menghapus movie terakhir
14. Menghapus movie setelah movie tertentu
15. Menghapus relasi antara genre dan movie
16. Mengubah (edit) relasi genre dengan movie
17. Menampilkan daftar genre dari suatu movie

Menu-menu tersebut memastikan seluruh operasi *CRUD (Create, Read, Update, Delete)* dapat dilakukan baik pada Genre, Movie, maupun relasinya.

## **Pembagian Tugas**

### *Anggota 1: Ramadhan Tangguh Defender*

*Fokus:* Pengelolaan List Parent (Genre)

*Tugas Implementasi:*

* Mendesain struktur data Genre
* Implementasi fungsi:

  * createGenreList
  * insertLastGenre
  * deleteFirstGenre
  * deleteLastGenre
  * deleteAfterGenre
  * findGenre
  * showAllGenres
* Menangani penghapusan genre beserta relasinya

### *Anggota 2: Zaidan Salam Rojab*

*Fokus:* Pengelolaan List Child (Movie)

*Tugas Implementasi:*

* Mendesain struktur data Movie
* Implementasi fungsi:

  * createMovieList
  * insertLastMovie
  * deleteFirstMovie
  * deleteLastMovie
  * deleteAfterMovie
  * findMovie
  * showAllMovies
* Menghitung movie yang tidak memiliki relasi genre

## *Pengerjaan Bersama (Integrasi Sistem)*

* Implementasi *Relasi Genre–Movie*:

  * connectGenreMovie
  * deleteRelation
  * editRelation
* Menampilkan data lintas relasi:

  * Genre → Movie
  * Movie → Genre
* Perancangan *menu utama interaktif (main.cpp)*
* Penyusunan laporan tugas besar dan pengujian program

## **Kesimpulan**

Dengan mengimplementasikan struktur data *Multi-Linked List*, aplikasi ini mampu mengelola data film dan genre secara efisien serta fleksibel. Program ini tidak hanya memenuhi konsep dasar struktur data, tetapi juga memberikan simulasi nyata penerapan relasi data dalam sebuah aplikasi manajemen.
