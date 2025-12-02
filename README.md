# Proposal Tugas Besar Struktur Data
## Judul: Aplikasi Manajemen Watchlist Film Berbasis Genre

### Deskripsi
Aplikasi ini dirancang untuk membantu pengguna mengelola daftar tontonan film pribadi (Watchlist). Agar lebih terorganisir, film-film akan dikelompokkan berdasarkan **Genre**.

Program ini mengimplementasikan struktur data **Multi-Linked List (Relasi One-to-Many)**:
1.  **List Parent (Genre)**: Menyimpan kategori/genre film (contoh: Action, Drama, Horror).
2.  **List Child (Movie)**: Menyimpan data film (Judul, Tahun, Rating) yang terhubung ke salah satu Genre.

### Pembagian Tugas

#### **Anggota 1: Ramadhan Tangguh Defender**
*   **Fokus:** Mengelola **List Parent (Genre)**.
*   **Tugas Implementasi:**
    1.  Membuat struktur data untuk Genre (misal: Double Linked List atau Single Linked List).
    2.  `insertGenre`: Menambahkan kategori genre baru.
    3.  `deleteGenre`: Menghapus genre (opsional: beserta isinya).
    4.  `showAllGenres`: Menampilkan daftar genre yang tersedia.
    5.  `findGenre`: Mencari apakah suatu genre sudah ada.

#### **Anggota 2: Zaidan Salam Rojab**
*   **Fokus:** Mengelola **List Child (Movie)**.
*   **Tugas Implementasi:**
    1.  Membuat struktur data untuk Movie (Single Linked List).
    2.  `insertMovie`: Menambahkan film baru ke dalam genre tertentu.
    3.  `deleteMovie`: Menghapus film dari watchlist.
    4.  `showMoviePerGenre`: Menampilkan daftar film di dalam genre tertentu.
    5.  `countMovies`: Menghitung jumlah film yang ada.

#### **Pengerjaan Bersama (Integrasi)**
*   **Relasi:** Menghubungkan (Connect) elemen Parent (Genre) ke elemen Child (Movie).
*   **Main Menu:** Menggabungkan semua fungsi ke dalam satu menu utama yang interaktif.
*   **Laporan:** Menyusun laporan tugas besar.
