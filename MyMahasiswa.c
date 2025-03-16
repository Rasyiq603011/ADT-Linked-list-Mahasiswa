#include "Mahasiswa.h"

int main(int argc, char *argv[]) {

    List L1, L2;
    infotype data;
    address newNode;
    
    // 2) Buat List L1 dan L2 untuk menampung daftar mahasiswa
    CreateList(&L1);
    CreateList(&L2);
    
    printf("===== Program ADT Linked List Mahasiswa =====\n\n");
    
    // 3) Isikan sejumlah elemen ke pada List L1, pastikan setiap pengisian elemen, 
    // isi List harus terurut Ascending menurut Nama.
    printf("Mengisi List L1 dengan data mahasiswa (terurut ascending berdasarkan nama):\n");
    
    // Data 1
    data.Nama = "Zainal";
    data.Nilai = 85.5;
    newNode = CreateNode(data);
    insertSortedByName(&L1, newNode);
    
    // Data 2
    data.Nama = "Budi";
    data.Nilai = 70.0;
    newNode = CreateNode(data);
    insertSortedByName(&L1, newNode);
    
    // Data 3
    data.Nama = "Diana";
    data.Nilai = 90.5;
    newNode = CreateNode(data);
    insertSortedByName(&L1, newNode);
    
    // Data 4
    data.Nama = "Ali";
    data.Nilai = 65.5;
    newNode = CreateNode(data);
    insertSortedByName(&L1, newNode);
    
    // Data 5
    data.Nama = "Fadli";
    data.Nilai = 75.0;
    newNode = CreateNode(data);
    insertSortedByName(&L1, newNode);
    
    // Data 6
    data.Nama = "Cindy";
    data.Nilai = 82.0;
    newNode = CreateNode(data);
    insertSortedByName(&L1, newNode);
    
    // Data 7
    data.Nama = "Eva";
    data.Nilai = 72.5;
    newNode = CreateNode(data);
    insertSortedByName(&L1, newNode);
    
    // Data 8
    data.Nama = "Diana";  // Duplicate name for testing
    data.Nilai = 88.0;
    newNode = CreateNode(data);
    insertSortedByName(&L1, newNode);
    
    // 4) Tampilkan isi List L1 (Nama, Nilai UTS SDA) terurut ascending berdasarkan nama
    printf("\n4) Tampilkan isi List L1 terurut ascending berdasarkan nama:\n");
    sortNama(&L1);
    printList(L1);
    
    // 5) Tampilkan isi List L1 (Nama, Nilai UTS SDA) terurut desending berdasarkan nilai
    printf("\n5) Tampilkan isi List L1 terurut descending berdasarkan nilai:\n");
    sortNilaiReverse(&L1);
    printList(L1);
    
    // 6) Hitung Jumlah elemen (jumlah mahasiswa pada list), kemudian tampilkan
    printf("\n6) Jumlah elemen (jumlah mahasiswa) pada List L1: %d\n", sumElmt(L1));
    
    // Sort back by name for clear output
    sortNama(&L1);
    
    // 7) Copy seluruh elemen pada list L1 yang Nilainya > 70 ke List L2
    printf("\n7) Copy elemen pada list L1 yang Nilainya > 70 ke List L2\n");
    
    
    // 8) Tampilkan Isi elemen List L2
    printf("\n8) Tampilkan Isi elemen List L2:\n");
    printList(L2);
    
    // 9) Jika pada L2 ada yang namanya sama, maka nama yang sama tersebut 
    // hanya boleh ada 1 pada list
    printf("\n9) Menghapus data dengan nama duplikat pada List L2 (tetap menyimpan yang pertama):\n");
    removeDuplicateNames(&L2);
    
    // 10) Tampilkan elemen List L2 yang baru
    printf("\n10) Tampilkan elemen List L2 yang baru:\n");
    printList(L2);
    
    // 11) Hapus List L1 dan List L2
    printf("\n11) Hapus List L1 dan List L2\n");
    ClearList(&L1);
    ClearList(&L2);
    
    printf("\nProgram selesai!\n");
    
    return 0;
}

