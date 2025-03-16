#ifndef MAHASISWA_H
#define MAHASISWA_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define info(p) (p)->info
#define next(p) (p)->next
#define Nil NULL

// Struct Mahasiswa Menyimpan Nama dan Nilai
typedef struct {
	char *Nama;
	float Nilai;
}Mahasiswa;

// Membuat infotype sebagai Alias dari struct Mahasiswa
typedef Mahasiswa infotype;

//Membuat address sebagia Alias dari pofloater Struct tElmtList 
typedef struct tElmtlist *address;

// deklarasi Struct tElmtList dan membuat ElmtList Sebagai Alias
typedef struct tElmtlist {
	infotype info;
	address next;
}ElmtList;

// Deklarasi Struct List
typedef struct{
	address First;
}List;

//Costructor dari struct Mahasiswa
Mahasiswa *constructor (char *Nama, float Nilai);

//Destructor dari struct Mahasiswa
void destructor(Mahasiswa *Destroy);

// Validator struct Mahasiswa
bool isValid(Mahasiswa valid);

//Validator Nilai
bool NilaiValid(float Nilai);

//Validator Nama
bool NamaValid(char *Nama);

//Getter untuk Nama
char *getNama(Mahasiswa get);

//Getter untuk Nilai
float getNilai(Mahasiswa get);

//Setter untuk Nama
void setNama(Mahasiswa *set, char *Nama);

//Setter untuk Nilai
void setNilai(Mahasiswa *set, float Nilai);

void CreateList(List* L);
// Create a new node
address CreateNode(infotype data);

//Display Isi dari Struct
void printObj(Mahasiswa display);

//Display list
void printList(List L);

//Insert node di awal
void insertAwal(List *L, address insert);

//Insert node di akhir
void insertAkhir(List *L, address insert);

//insert node setelah node lain
void insertAfter(address *Before, address insert);

address searchNode(List L, char* nama);

//delete node awal
void deleteAwal(List *L);

//delete node Akhir
void deleteAkhir(List *L);

// delete node setelah node lainnya
void deleteAfter(address *Before);

//menghapus seluruh list
void ClearList(List *L);

//Memodifikasi nilai node di awal
void modifyAwal(List *L, Mahasiswa modify);

//memodifikasi nilai node di akhir
void modifyAkhir(List *L, Mahasiswa modify);

//memodifikasi nilai node setelah nilai node lainnya
void modifyAfter(address *before, Mahasiswa modify);

//mengurutkan List secara ascending
void sortList(List L);

//mengurutkan List secara descending
void sortListReverse(List L);

//fungsi yang akan mereturn list yang telah di filter berdasarkan nilai
List *filterByNilai(List L, float Awal, float Akhir);

//function yang akan mereturn list yang telah difilter berdasarkan abjad nama
List *filterByAbjad(List L, char Awal, char Akhir);

// membalikan urutan list
List reverse(List L);

// menghitung Banyak element pada suatu list
int sumElmt(List L);

//menghitung rata rata nilai pada suatu list
float rerataNilai(List L);

void insertSortedByName(List* L, address newNode);

void removeDuplicateNames(List* L);

#endif
