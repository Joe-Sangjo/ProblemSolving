#if 0

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <malloc.h>


typedef struct _score{

	int id;
	int jumsu;
	char name[10];
}SCORE;	

#define MAX_ST 20

#if 0
	#define HASH_KEY 10
	#define STEP 1
#else
	#define HASH_KEY 7
	#define STEP 9
#endif


SCORE Hash_table[MAX_ST];


int Create_Data(SCORE *p);
int Get_Hash_Key(int id);
void Init_Hash_Table(void);
void Print_All_Data(void);
int Insert_Data(SCORE * d);
SCORE * Search_Data(int id);
int Delete_Data(int id);

SCORE test[MAX_ST+2] = {{10, 50, "kim"}, {2, 80, "lew"}, {8, 50, "lew"}, {4, 45, "lee"}, {1, 90, "song"},\
                               {3, 45, "kim"}, {5, 50, "song"}, {9, 100, "lee"}, {7, 75, "moon"}, {6, 90, "park"}, \
                               {15, 90, "ki"}, {11, 20, "kong"}, {14, 40, "shin"}, {12, 50, "son"}, {17, 48, "lee"}, \
                               {20, 100, "min"}, {19, 80, "you"}, {13, 45, "song"}, {16, 54, "no"}, {18, 100, "yang"}, \
							   {21, 58, "seo"}, {23, 88, "oh"}}; 




int Create_Data(SCORE * p)
{
	printf("\n사번을 입력하시오 => ");
	scanf("%d", &p->id);
	fflush(stdin);
	printf("이름을 입력하시오 => ");
	scanf("%s", p->name);
	fflush(stdin);
	printf("점수를 입력하시오 => ");
	scanf("%d", &p->jumsu);
	fflush(stdin);

	return 1;
}


int Get_Hash_Key(int id){
	return id % HASH_KEY;
}

void Init_Hash_Table(void){
	int i;

	for(i = 0; i < MAX_ST; i++){
		Hash_table[i].id = -1;
	}
}

void Print_All_Data(void){
	int i;

	for(i = 0; i < MAX_ST; i++){
		if((Hash_table[i].id != -1) && (Hash_table[i].id != -2)) printf("[%d] ID: %d, NAME: %s\n", i, Hash_table[i].id, Hash_table[i].name);
	}
}

int Delete_Data(int id){

	SCORE *p;

	p = Search_Data(id);
	if(p == (SCORE *)0) return -1;

	p->id = -2;
	return 1;
}

int Insert_Data(SCORE * d){
	int pos;
	int cnt = 0;
	static int insert_cnt;

	pos = Get_Hash_Key(d -> id);

	for(;;){

		if((Hash_table[pos].id == -1) || (Hash_table[pos].id == -2)){
			Hash_table[pos] = *d;
			insert_cnt += cnt + 1;
			printf("cnt = %d, total insert count = %d\n",cnt + 1, insert_cnt );
			return pos;
		}

		pos += STEP;
		cnt++;

		if(cnt >= MAX_ST) return -1;
		if(pos >= MAX_ST) pos %= MAX_ST;
	}
}


SCORE * Search_Data(int id){

	int pos;
	int cnt = 0;
	static int search_cnt;

	pos = Get_Hash_Key(id);

	for(;;){

		if(Hash_table[pos].id == id) return &Hash_table[pos];
		if(Hash_table[pos].id == -1) return (SCORE *)0;

		pos	+= STEP;
		cnt++;
		search_cnt += cnt + 1;
		printf("cnt = %d, total search count = %d\n", cnt+1, search_cnt);
		if(cnt >= MAX_ST) return (SCORE *)0;		
		if(pos >= MAX_ST) pos %= MAX_ST;
	}
}

#endif


#if 1


#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <malloc.h>

typedef struct _score{

	int id;
	int jumsu;
	char name[10];
	struct _score *next;

}SCORE;



#define MAX_ST 20
#define HASH_KEY 5


SCORE Hash_table[HASH_KEY];




int Create_Data(SCORE *p);
int Get_Hash_Key(int id);
void Init_Hash_Table(void);
void Print_All_Data(void);
int Insert_Data(SCORE *d);
SCORE * Search_Data(int id);
int Delete_Data(int id);

SCORE test[MAX_ST+2] = {{10, 50, "kim"}, {2, 80, "lew"}, {8, 50, "lew"}, {4, 45, "lee"}, {1, 90, "song"},\
                               {3, 45, "kim"}, {5, 50, "song"}, {9, 100, "lee"}, {7, 75, "moon"}, {6, 90, "park"}, \
                               {15, 90, "ki"}, {11, 20, "kong"}, {14, 40, "shin"}, {12, 50, "son"}, {17, 48, "lee"}, \
                               {20, 100, "min"}, {19, 80, "you"}, {13, 45, "song"}, {16, 54, "no"}, {18, 100, "yang"}, \
							   {21, 58, "seo"}, {23, 88, "oh"}}; 


int Create_Data(SCORE * p)
{
	printf("\n사번을 입력하시오 => ");
	scanf("%d", &p->id);
	fflush(stdin);
	printf("이름을 입력하시오 => ");
	scanf("%s", p->name);
	fflush(stdin);
	printf("점수를 입력하시오 => ");
	scanf("%d", &p->jumsu);
	fflush(stdin);

	return 1;
}


int Get_Hash_Key(int id){
	return id % HASH_KEY;
}

void Init_Hash_Table(void){

	int i;

	for(i = 0; i < MAX_ST; i++){
		Hash_table[i].next = (SCORE *)0;
	}
}


void Print_All_Data(void){

	int i;
	SCORE *p;

	for(i = 0; i < MAX_ST; i++){

		p = Hash_table[i].next;

		for(;;){


			if(p == (SCORE *)0) break;
			printf("[%d] address:0x%.8X, ID: %d, NAME: %s, next: 0x%.8X\n", i, p, p->id, p->name, p->next);
			p = p->next;			
		}
	}
}


int Insert_Data(SCORE *d){

	SCORE *p;
	SCORE *q;

	p = &Hash_table[Get_Hash_Key(d -> id)];
	q = calloc(1, sizeof(SCORE));

	if(q == (void *)0) return -1;

	*q = *d;

	for(;;){
		if(p -> next == (SCORE *)0) break;
		p = p -> next;
	}

	p -> next = q;
	q -> next = (SCORE *)0;
	return 1;
}


int Delete_Data(int id){
	SCORE *p;
	SCORE * prev;

	prev = &Hash_table[Get_Hash_Key(id)];

	p = prev->next;

	for(;;){
		if(p -> id = id){
			prev -> next = p -> next;
			free(p);
			return 1;
		}

		if(p -> next == (SCORE *)0) return -1;


		prev = p;

		p = p -> next;
	}
}


SCORE *Search_Data(int id){
	SCORE *p; 


	p = Hash_table[Get_Hash_Key(id)].next;

	for(;;){

		if(p -> id == id) return p;
		if(p -> next == (SCORE *)0) return (SCORE *)0;
		p = p->next;
	}
}








#endif