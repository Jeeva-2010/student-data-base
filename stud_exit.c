#include"header.h"
void exit_save(node*ptr);
void exit_only(node*ptr);
void stud_exit(node*ptr)
{
	char op;
			
                        	do
				{
                                	printf("\t\t\t\t------------------------------------\n");
                                	printf("\t\t\t\t| Choice | Operation               |\n");
                                	printf("\t\t\t\t------------------------------------\n");
                                	printf("\t\t\t\t| S/s    | Save And Exit           |\n");
                                	printf("\t\t\t\t| E/e    | Exit Without Save       |\n");
                                	printf("\t\t\t\t------------------------------------\n");
                                	printf("\n\n");

                                	printf("Enter Your Choice: ");
                                	scanf(" %c",&op);
                                	if(op=='S' || op=='s')
                                	{
                                        	exit_save(ptr);

                                	}
                                	else if(op=='E' || op=='e')
                                	{
                                       		exit_only(ptr);

                               	 	}
                                	else
                                	{
                                        	printf("Invalid Case:\n\n");
                                	}

                        	}while(1);

}

void exit_save(node*ptr)
{
	if(stud_save(ptr) == 1)
	{
    	printf("Saved successfully\n");
    	exit(0);
	}
	else
	{
	    printf("Saving failed\n");
	}
}
void exit_only(node*ptr)
{
	printf("Exit The Main Menu Without Saving:\n\n");
	exit(0);
}
