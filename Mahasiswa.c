#include "Mahasiswa.h"


//Costructor dari struct Mahasiswa
Mahasiswa *constructor (char *Nama, float Nilai){
	if((!NamaValid(Nama)) && (!NilaiValid(Nilai))){
		printf("Data infotype Tidak Valid");
		return Nil;
	}
	infotype *temp = (infotype *) malloc (sizeof(infotype));
	if (temp == NULL){
		printf("Gagal membuat data Mahasiswa");
		return Nil;
	}
	temp->Nama = strdup(Nama);
	temp->Nilai = Nilai;
	return temp;
}

//Destructor dari struct Mahasiswa
void destructor(infotype *Destroy){
	if (Destroy == Nil) return;
    free(Destroy->Nama);
    free(Destroy);
}

// Validator struct Mahasiswa
bool isValid(infotype valid){
	return((NamaValid(valid.Nama)) && (NilaiValid(valid.Nilai)));
}

//Validator Nilai
bool NilaiValid(float Nilai){
	return ((Nilai >= 0) && (Nilai <= 4));
}

//Validator Nama
bool NamaValid(char *Nama){
	return (Nama != Nil && strlen(Nama) > 0);
}

//Getter untuk Nama
char *getNama(infotype get){
	if (get.Nama == Nil){
		printf("Data Mahasiswa Tidak Tersedia!");
		return Nil;
	}
	return get.Nama;
}

//Getter untuk Nilai
float getNilai(infotype get){
	return get.Nilai;
}

//Setter untuk Nama
void setNama(infotype *set, char *Nama){
	if ((set == Nil) && NamaValid(Nama)) {
        free(set->Nama);
        set->Nama = strdup(Nama);
        printf("Data berhasil diset!");
    }
	else{
		printf("Gagal mengset Data");
	}
}

//Setter untuk Nilai
void setNilai(infotype *set, float Nilai){
	if ((set == Nil) && NilaiValid(Nilai)) {
        set->Nilai = Nilai;
        printf("Data berhasil diset!");
    }
	else{
		printf("Gagal menset data");
	}
}

void CreateList(List* L) {
    L->First = Nil;
}

// Create a new node
address CreateNode(infotype data) {
    address newNode = (address)malloc(sizeof(ElmtList));
    if (newNode != Nil) {
        info(newNode).Nama = strdup(data.Nama);
        info(newNode).Nilai = data.Nilai;
        next(newNode) = Nil;
    }
    return newNode;
}

//Display Isi dari Struct
void printObj(infotype display){
	printf(" %s dengan Nilai UTS SDA %.2f ", getNama(display), getNilai(display));
}

//Display list
void printList(List L){
	address temp = L.First;
    
    if (temp == Nil) {
        printf("List Kosong!\n");
        return;
    }
    
    while (temp != Nil){
		printObj(info(temp));
		printf(" --> ");
		temp = next(temp);
	}
	printf(" NULL ");
}

//Insert node di awal
void insertAwal(List *L, address insert){
	if (insert == Nil) return;
	
	next(insert) = L->First;
	L->First = insert;
}

//Insert node di akhir
void insertAkhir(List *L, address insert){
	if (insert == Nil) return;
	
	address temp = L->First;
	
	if (temp == Nil) {
        temp = insert;
        return;
    }
	
	while (true){
		if ((next(temp)) == Nil){
			next(insert) = Nil;
			next(temp) = insert;
			break;
		}
		else{
			temp = next(temp);
		}		
	}
}

//insert node setelah node lain
void insertAfter(address *Before, address insert){
		
	next(insert) = next(*Before);
	next(*Before) = insert;
}

address searchNode(List L, char* nama) {
    address p = L.First;
    
    while (p != Nil) {
        if (strcmp(info(p).Nama, nama) == 0) {
            return p;
        }
        p = next(p);
    }
    
    return Nil;
}

//delete node awal
void deleteAwal(List *L){
	
	if((L->First) == Nil){
		printf("\nList Kosong Tidak bisa menghapus\n");
		return;
	}
	
	address temp = L->First;
	L->First = next(L->First);
	
	free((info(temp)).Nama);
	free(temp);
}

//delete node Akhir
void deleteAkhir(List *L){
	
	address temp = L->First;
	while (temp != Nil){
		if ((next(next(temp))) == Nil){
			free((info(next(temp))).Nama);
			free(next(temp));
			next(temp) = Nil;
			return;
		}
		else{
			temp = next(temp);
		}
	}
	printf("\nList Kosong Tidak bisa menghapus\n");
}

// delete node setelah node lainnya
void deleteAfter(address *Before){

	address temp = next(*Before);
	next(*Before) = next(next(*Before));
	free((info(temp)).Nama);
	free(temp);
}

//menghapus seluruh list
void ClearList(List *L){
	
	if((L->First) == Nil){
		printf("List Kosong Tidak bisa menghapus");
		return;
	}
	
	while ((L->First) != Nil){
		deleteAwal(L);
//		printf("Node dengan isi %d telah dihapus!\n\n", Hapus);
	}
	printf("\nList Telah Kosong Head menunjuk kembali ke Nil\n");
}

//Memodifikasi nilai node di awal
void modifyAwal(List *L, Mahasiswa modify){
	if (L->First == Nil) return;
    
    free(info(L->First).Nama);
    info(L->First).Nama = strdup(modify.Nama);
    info(L->First).Nilai = modify.Nilai;
}

//memodifikasi nilai node di akhir
void modifyAkhir(List *L, Mahasiswa modify){
	if (L->First == Nil) return;
    
    address temp = L->First;
    while (next(temp) != Nil) {
        temp = next(temp);
    }
    
    free(info(temp).Nama);
    info(temp).Nama = strdup(modify.Nama);
    info(temp).Nilai = modify.Nilai;
}

//memodifikasi nilai node setelah nilai node lainnya
void modifyAfter(address *before, Mahasiswa modify){
	if (*before == Nil || next(*before) == Nil) return;
    
    free(info(next(*before)).Nama);
    info(next(*before)).Nama = strdup(modify.Nama);
    info(next(*before)).Nilai = modify.Nilai;
}

//mengurutkan List secara ascending
void sortNilai(List *L){
	if (L->First == Nil || next(L->First) == Nil) return;
    
    address i, j;
    Mahasiswa temp;
    
    for (i = L->First; next(i) != Nil; i = next(i)) {
        for (j = next(i); j != Nil; j = next(j)) {
            if (getNilai(info(i)) > getNilai(info(j))) {
                temp = info(i);
                info(i) = info(j);
                info(j) = temp;
            }
        }
    }
}

//mengurutkan List secara descending
void sortNilaiReverse(List *L){
	if (L->First == Nil || next(L->First) == Nil) return;
    
    address i, j;
    Mahasiswa temp;
    
    for (i = L->First; next(i) != Nil; i = next(i)) {
        for (j = next(i); j != Nil; j = next(j)) {
            if (getNilai(info(i)) < getNilai(info(j))) {
                temp = info(i);
                info(i) = info(j);
                info(j) = temp;
            }
        }
    }
}

void sortNama(List *L){
	if (L->First == Nil || next(L->First) == Nil) return;
    
    address i, j;
    Mahasiswa temp;
    
    for (i = L->First; next(i) != Nil; i = next(i)) {
        for (j = next(i); j != Nil; j = next(j)) {
            if (strcmp(getNama(info(i)), getNama(info(j))) > 0) {
                temp = info(i);
                info(i) = info(j);
                info(j) = temp;
            }
        }
    }
}

//mengurutkan List secara descending
void sortNamaReverse(List *L){
	if (L->First == Nil || next(L->First) == Nil) return;
    
    address i, j;
    Mahasiswa temp;
    
    for (i = L->First; next(i) != Nil; i = next(i)) {
        for (j = next(i); j != Nil; j = next(j)) {
            if (strcmp(getNama(info(i)), getNama(info(j))) < 0) {
                temp = info(i);
                info(i) = info(j);
                info(j) = temp;
            }
        }
    }
}

//fungsi yang akan mereturn list yang telah di filter berdasarkan nilai
List *filterByNilai(List L, float Awal, float Akhir){
	
	List *result = (List *) malloc (sizeof(List));
	result->First = Nil;
	
	address temp = L.First;
	address newNode;
	
	while(temp != Nil){
		if(getNilai(info(temp)) >= Awal && Akhir >= getNilai(info(temp))){
			newNode = (address)malloc(sizeof(ElmtList));
            info(newNode).Nama = strdup(getNama(info(temp)));
            info(newNode).Nilai = getNilai(info(temp));
            next(newNode) = Nil;
            
            insertAkhir(result, newNode);
		}
		temp = next(temp);
	}
	return result;
}

//function yang akan mereturn list yang telah difilter berdasarkan abjad nama
List *filterByAbjad(List L, char Awal, char Akhir){
	
	List *result = (List*)malloc(sizeof(List));
    result->First = Nil;
    
    address temp = L.First;
    address newNode;
    
    while (temp != Nil) {
        char firstChar = info(temp).Nama[0];
        if (firstChar >= Awal && firstChar <= Akhir) {
            newNode = (address)malloc(sizeof(ElmtList));
            info(newNode).Nama = strdup(info(temp).Nama);
            info(newNode).Nilai = info(temp).Nilai;
            next(newNode) = Nil;
            
            insertAkhir(result, newNode);
        }
        temp = next(temp);
    }
    return result;
}

// membalikan urutan list
List reverse(List L){
	
	 if (L.First == Nil || next(L.First) == Nil) {
        return L;
    }
    
    List result;
    result.First = Nil;
    
    address current = L.First;
    
    while (current != Nil) {
        address temp = current;
        current = next(current);
        next(temp) = Nil;
        
        insertAwal(&result, temp);
    }
    
    return result;
}

// menghitung Banyak element pada suatu list
int sumElmt(List L){
	int count = 0;
    address temp = L.First;
    
    while (temp != Nil) {
        count++;
        temp = next(temp);
    }
    
    return count;
}

//menghitung rata rata nilai pada suatu list
float rerataNilai(List L){
	if (L.First == Nil) return 0.0;
    
    float sum = 0.0;
    int count = 0;
    address current = L.First;
    
    while (current != Nil) {
        sum += info(current).Nilai;
        count++;
        current = next(current);
    }
    
    return (count > 0) ? sum / count : 0.0;
}


void insertSortedByName(List* L, address newNode) {
    if (newNode == Nil) return;
    
    // If the list is empty or the new node should be the first
    if (L->First == Nil || strcmp(getNama(info(newNode)), getNama(info(L->First))) < 0) {
        insertAwal(L, newNode);
        return;
    }
    
    // Find the position to insert
    address current = L->First;
    while (next(current) != Nil && 
           strcmp(getNama(info(newNode)), getNama(info(next(current)))) > 0) {
        current = next(current);
    }
    
    insertAfter(&current, newNode);
}

void removeDuplicateNames(List* L) {
    if (L->First == Nil || next(L->First) == Nil) return;
    
    address current, runner, temp;
    
    for (current = L->First; current != Nil; current = next(current)) {
        runner = current;
        
        while (next(runner) != Nil) {
            if (strcmp(getNama(info(current)), getNama(info(next(runner)))) == 0) {
                temp = next(runner);
                next(runner) = next(next(runner));
                free(info(temp).Nama);
                free(temp);
            } else {
                runner = next(runner);
            }
        }
    }
}














