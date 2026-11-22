#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct st
{
	int roll;
	char name[50];
	float percentage;

	struct st *next;
}node;
extern int next_roll;
void stud_add(node**);
void stud_del(node**);
void stud_show(node*);
void stud_mod(node**);
int stud_save(node*);
void stud_sort(node**);
void stud_exit(node*ptr);
void stud_load(node**ptr);
