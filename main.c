#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 110


typedef struct _link {
	char letter;
	int occurrence; /* nombre d’occurrences */
	struct _link *next;
} link;

link *insert_first_list(link *lst, char letter){
		
	if(lst == NULL){
		
		link *lst = (link*) malloc( sizeof(link) ) ;
		lst->next = NULL ;
		lst->letter = letter ; 
		lst->occurrence = 1 ;
		
		return lst ;
		
	}	else	{
		
		link *newLst = (link*) malloc( sizeof(link) ) ;
		newLst->next = lst ;
		newLst->letter = letter ; 
		newLst->occurrence = 1 ;
		
		return newLst ;
	}
		
	return NULL ;
}

link *find_list(link *lst, char letter){
	
	while(lst != NULL){
		
		if(lst->letter == letter){
			lst->occurrence++ ;
			return lst ;
		}
		
		lst = lst->next ;
		
	}
	
	return NULL ;
	
}

void print_lst(link *lst){
	
	while(lst != NULL){
		printf("%c => %d \n" , lst->letter, lst->occurrence);
		lst = lst->next ;
	}

}

void free_list(link *lst){
	if(lst){
		while(lst != NULL){
			link *next = lst->next ;
			free(lst);
			lst = next ;
		}
	}
	
	free(lst) ;
}

void read_file(char word[]){
	
	FILE *file = fopen(word,"r");
	printf("DEBUT") ;
	link *lst = NULL;
	
    if ( file != NULL ){
		
        char buffer = NULL ;
		
        while(fscanf(file,"%c",&buffer)!=-1){
			if( find_list(lst, buffer) == NULL ){
				lst = insert_first_list(lst, buffer) ;
			}
        }
		
    }
	
	print_lst(lst) ;
	free_list(lst) ;
	fclose(file);
	
}


int main(int argc, char* argv[]){

	read_file("old.txt") ;

	return 0 ;
}
