#include"header.h"
void sort_name(node**ptr);
void sort_per(node**ptr);
void stud_sort(node**ptr)
{
	char op;
                        do
                        {
                                printf("\t\t\t\t------------------------------------\n");
                                printf("\t\t\t\t| Choice | Operation               |\n");
                                printf("\t\t\t\t------------------------------------\n");
                                printf("\t\t\t\t| N/n    | Sort By Name            |\n");
                                printf("\t\t\t\t| P/p    | Sort By percentage      |\n");
                                printf("\t\t\t\t| E/e    | Exit                    |\n");
                                printf("\t\t\t\t------------------------------------\n");
                                printf("\n\n");

                                printf("Enter Your Choice: ");
                                scanf(" %c",&op);
                                if(op=='N' || op=='n')
                                {
                                        sort_name(ptr);

                                }
                                else if(op=='P' || op=='p')
                                {
                                        sort_per(ptr);
                                }
                                else if(op=='E' || op=='e')
                                {
                                        printf("Returning To The Main Menu:\n\n");

                                }
                                else
                                {
                                        printf("Invalid Case:\n\n");
                                }

                        }while(op!='E' && op!='e');
                        return;
}
void sort_name(node**ptr)
{
	if((*ptr)==NULL)
	{
		printf("The Data List Is Empty:\n\n");
		return;
	}
	node*temp=(*ptr);
	node*temp1=NULL;

	int cmp;
	int roll;
	float mark;
	char name[50];
	while(temp!=NULL)
	{
		temp1=temp->next;

		while(temp1 !=NULL)
		{
			cmp=strcmp(temp->name,temp1->name);
			if(cmp>0)
			{
				strcpy(name,temp->name);
				strcpy(temp->name,temp1->name);
				strcpy(temp1->name,name);
				
				mark=temp->percentage;
				temp->percentage=temp1->percentage;
				temp1->percentage=mark;
				
				roll=temp->roll;
				temp->roll=temp1->roll;
				temp1->roll=roll;

			}
			temp1=temp1->next;

		}
		temp=temp->next;

	}

	printf("Students Sorted By Name Successfully!\n\n");
	stud_show(*ptr);
}

void sort_per(node**ptr)
{
        if((*ptr)==NULL)
        {
                printf("The Data List Is Empty:\n\n");
                return;
        }
        node*temp=(*ptr);
        node*temp1=NULL;
        int roll;
        float mark;
        char name[50];
        while(temp!=NULL)
        {
                temp1=temp->next;

                while(temp1 !=NULL)
                {
                        
                        if(temp->percentage < temp1->percentage)
                        {
                                strcpy(name,temp->name);
                                strcpy(temp->name,temp1->name);
                                strcpy(temp1->name,name);

                                mark=temp->percentage;
                                temp->percentage=temp1->percentage;
                                temp1->percentage=mark;

                                roll=temp->roll;
                                temp->roll=temp1->roll;
                                temp1->roll=roll;

                        }
                        temp1=temp1->next;

                }
                temp=temp->next;

        }

        printf("Students Sorted By Percentage Successfully!\n\n");
        stud_show(*ptr);
}





