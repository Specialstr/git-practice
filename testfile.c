/**
 *Summary of File:
 *
 *	This file copies the job and index values among the pre-defined registration structure values to the index structure,
 *	receives the user's job input value, and searches for the index struct of the matching job. Based on the corresponding
 *	index value, the name, age, and job are printed from the registration structure.
 */
#include<stdio.h>
#include<string.h>

struct REG{
	int index;
	char name[50];
	int age;
	char job[50];
};
struct INDEX{
	char job[50];
	int index;
};

void create_index(struct REG *, struct INDEX *);
int search_job(struct REG *, struct INDEX *);

int main(){
	int idx;
	struct REG registration[4] = {	//defining structs and assigning values.
	{0, "park", 25, "student"}, {1, "jung", 35, "engineer"},
	{2, "kim", 40, "professor"}, {3, "lee", 33, "staff"}
	};
	struct INDEX index[4];
	
	create_index(registration, index);
	idx = search_job(registration, index);
	
	if(idx == 53){	//When there are no search results.
		printf("No search result found.\n");
		return 0;
	}
	
	printf("\nName: %s \nAge: %d \nJob: %s\n", registration[idx].name, registration[idx].age, registration[idx].job);
	
	return 0;
}


/**
 *
 *void create_index(struct REG *, struct INDEX *)
 *
 *Summary of the create_index function:
 *
 *	The create_index function copies the age and job value of registration struct to index struct.
 *
 *Parameters: REG, idx = Pre-defined struct.
 *
 */
void create_index(struct REG *reg, struct INDEX *idx){
	int i = 0;
	while(i<5){
		(idx+i)->index = (reg+i)->index;
		strcpy((idx+i)->job, (reg+i)->job);
		i++;
	}
}

/**
 *
 *int search_job(struct REG *, struct INDEX *)
 *
 *Summary of the search_job function:
 *
 *	The search_job function literally searches the job. When user enters the job(string),
 *	the function will start seraching from idx(struct) database. When it finds the result
 *	that matches the job, it returns the index value to main function.
 *
 *Parameters: REG, idx = Pre-defined struct.
 *
 */
int search_job(struct REG *reg, struct INDEX *idx){
	char search[50];
	int i = 0, j;
	
	printf("Enter job.\n");
	gets(search);
	
	while(i<5){
		j = strcmp((idx+i)->job, search);
		if(j == 0)
			break;
		if(i == 4){
			return 53; // return 53 when there is no result. 53 means nothing. just for returning certain values.
		}
		i++;
	}
	
	return i;
}
