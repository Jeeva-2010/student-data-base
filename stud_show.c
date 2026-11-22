#include"header.h"

void stud_show(node*ptr)
{
	if(ptr == NULL)
    	{
        	printf("the data is empty:\n");
        	return;
    	}
	printf("\t\t--------------------------------------------------\n");
        printf("\t\t| %-13s | %-15s   | %s |\n","Roll No","Name","Percentage");
	printf("\t\t--------------------------------------------------\n");

    	while(ptr != NULL)
    	{
		printf("\t\t| %-10d    | %-14s    | %-8.2f   |\n",ptr->roll,ptr->name,ptr->percentage);
                printf("\t\t--------------------------------------------------\n");
		
		ptr = ptr->next;
    	}

    	printf("the data printed successfully:\n\n");

}
