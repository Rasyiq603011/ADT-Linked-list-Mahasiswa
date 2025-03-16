#include "Mahasiswa.h"

List reverse(List L){
	
	address temp = next(p);
	address reverse = next(next(p));
	next(p) = Nil;
	
	if (!isEmpty(p)){
		while(true){
			next(temp) = p;
			p = temp;
			temp = reverse;
			reverse = next(reverse);
				
			if (isEmpty(next(reverse))){
				next(temp) = p;
				next(reverse) = temp;
				return reverse;
			}
		}		
	}
	else{
		printf("List Kosong");
	}		
}
