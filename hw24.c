#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h> 

#define KEY_SIZE 20
#define TABLE_SIZE 17

typedef struct {
	char key[KEY_SIZE];
}element;

element hash_table[30];

void init_table(element ht[]) {
	int i;
	for (i = 0; i < TABLE_SIZE; i++) ht[i].key[0] = NULL;
}

int transform(char* key) {
	int number = 0;
	while (*key) number += *key++;
	return number;
}

int hash_function(char* key) {
	return transform(key) % TABLE_SIZE;
}

#define empty(item) (strlen(item.key)==0)
#define equal(item1,item2) (!strcmp(item1.key, item2.key))

void hash_lp_add(element item, element ht[]) {
	int i, hash_value;
	i = hash_function(item.key);
	hash_value = i;
	while (!empty(ht[i])) i = (i + 1) % TABLE_SIZE;
	ht[i] = item;
}

void hash_lp_search(element item, element ht[]) {
	int i, hash_value;
	i = hash_function(item.key);
	hash_value = i;
	element flag = {'Q'};
	if equal(item, flag) {
			printf("Exit\n");
			exit(1);
	}
	while (!empty(ht[i])) {
		if equal(item, ht[i]) {
			printf("success\n"); return;
		}	
		i = (i + 1) % 17;
		if (i == hash_value) printf("fail\n"); return;
	}
	printf("fail\n");
}

void hash_lp_print(element ht[]) {
	int i;
	for (int i = 0; i < TABLE_SIZE; i++)
		printf("[%d]: %s\n", i, ht[i].key);
}

int main(void) {
	element e;
	int num = 0;
	int i = 0;
	char name[10];
	char* s[13] = {"kim","lee","park","choi","hong","song","ryu","min","jeon","rho","wu","jeong","ko"};
	
	printf("Input bucket size: ");
	//scanf("%d", &num);
	
	//init_table(hash_table);

	for (int i = 0; i < 13; i++){
		strcpy(e.key, s[i]);
		hash_lp_add(e, hash_table);
	}
	hash_lp_print(hash_table);

	while (1) {
		printf("Input string (Q for quit):");
		scanf("%s", name);
		strcpy(e.key, name);
		hash_lp_search(e, hash_table);
	}
	return 0;
}