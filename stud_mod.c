#include"header.h"
void mod_roll(node**ptr);
void mod_name(node**ptr);
void mod_exit(void);
void mod_per(node**);
void name(node*temp);
void percentage(node*temp);
void name_byrollno(node*temp,char*name_find,int roll);
void percentage_byrollno(node*temp,char*name,int roll);
void name_by_mark(node *temp, float mark_find, int roll);
void percentage_by_mark(node *temp, float mark_find, int roll);
void stud_mod(node**ptr)
{
	char op;
	do
	{
		printf("\t\t\t\t------------------------------------\n");
                printf("\t\t\t\t| Choice | Operation               |\n");
                printf("\t\t\t\t------------------------------------\n");
                printf("\t\t\t\t| N/n    | Modify By Name          |\n");
                printf("\t\t\t\t| R/r    | Modify By roll          |\n");
		printf("\t\t\t\t| P/p    | Modify By percentage    |\n");
                printf("\t\t\t\t| E/e    | Exit                    |\n");
                printf("\t\t\t\t------------------------------------\n");
		printf("\n\n");

		printf("Enter Your Choice: ");
		scanf(" %c",&op);
		if(op=='R' || op=='r')
		{
			mod_roll(ptr);
		}
		else if(op=='N' || op=='n')
		{
			mod_name(ptr);
		}
		else if(op=='P' || op=='p')
                {
                        mod_per(ptr);
                }

		else if(op=='E' ||op=='e')
		{
			mod_exit();
		}
		else
		{
			printf("invalid case:\n\n");
		}

	}while(op!='E' && op!='e');
}
void mod_roll(node**ptr)
{
	if((*ptr)==NULL)
	{
		printf("The Data List Is Empty:\n\n");
		return;
	}
	int flag=0;
	int data;
	printf("Enter Roll No To Find: ");
	scanf("%d",&data);
	
	node*temp=(*ptr);
        while(temp!=NULL)
        {

                if(temp->roll==data)
                {
			flag=1;
			char op;
			do
			{
				printf("\t\t\t\t------------------------------------\n");
                		printf("\t\t\t\t| Choice | Operation               |\n");
				printf("\t\t\t\t------------------------------------\n");
         	        	printf("\t\t\t\t| N/n    | Modify The Name         |\n");
				printf("\t\t\t\t| P/p    | Modify The percentage   |\n");
				printf("\t\t\t\t| E/e    | Exit                    |\n");
				printf("\t\t\t\t------------------------------------\n");
				printf("\n\n");
				
				printf("Enter Your Choice: ");
                		scanf(" %c",&op);
                		if(op=='P' || op=='p')
                		{
                        		percentage(temp);
					
                		}
                		else if(op=='N' || op=='n')
                		{
                		        name(temp);
                		}
				else if(op=='E' || op=='e')
				{
					printf("Returning To Modification The Main Menu:\n\n");

				}
				else
				{
					printf("Invalid Case:\n\n");
				}

			}while(op!='E' && op!='e');
			return;

                }
                temp=temp->next;
        }
	if(flag==0)
        printf("No Data Found:\n\n");	
}

void mod_name(node**ptr)
{
	if((*ptr)==NULL)
        {
                printf("The Data List Is Empty:\n\n");
                return;
        }
	int flag=0;
        char name_find[50];
	node*found=NULL;
	int roll;
        printf("Enter Name To Find: ");
        scanf("%49s",name_find);

        node*temp=(*ptr);
	int cmp;
        printf("\t\t--------------------------------------------------\n");
        printf("\t\t| %-13s | %-15s   | %s |\n","Roll No","Name","Percentage");
        printf("\t\t--------------------------------------------------\n");
        while(temp!=NULL)
        {
                cmp=strcmp(temp->name,name_find);
                if(cmp==0)
                {
                        flag++;
			found=temp;
                        printf("\t\t| %-10d    | %-14s    | %-8.2f   |\n",temp->roll,temp->name,temp->percentage);
                        printf("\t\t--------------------------------------------------\n");
                }
                temp=temp->next;
        }
	if(flag==0)
	{
		printf("No Data Found:\n\n");
	}
	else if(flag==1)
	{
		char op;
                        do
                        {
                                printf("\t\t\t\t------------------------------------\n");
                                printf("\t\t\t\t| Choice | Operation               |\n");
                                printf("\t\t\t\t------------------------------------\n");
                                printf("\t\t\t\t| N/n    | Modify The Name         |\n");
                                printf("\t\t\t\t| P/p    | Modify The percentage   |\n");
                                printf("\t\t\t\t| E/e    | Exit                    |\n");
                                printf("\t\t\t\t------------------------------------\n");
                                printf("\n\n");

                                printf("Enter Your Choice: ");
                                scanf(" %c",&op);
                                if(op=='P' || op=='p')
                                {
                                        percentage(found);

                                }
                                else if(op=='N' || op=='n')
                                {
                                        name(found);
                                }
                                else if(op=='E' || op=='e')
                                {
                                        printf("Returning To Modification The Main Menu:\n\n");

                                }
                                else
                                {
                                        printf("Invalid Case:\n\n");
                                }

                        }while(op!='E' && op!='e');
                        return;

	}
	else
	{
		printf("-------Multiple Student Found with This Name:-------\n\n");
                printf("Enter The Roll No: ");
                scanf("%d",&roll);

		char op;
                        do
                        {
                                printf("\t\t\t\t------------------------------------\n");
                                printf("\t\t\t\t| Choice | Operation               |\n");
                                printf("\t\t\t\t------------------------------------\n");
                                printf("\t\t\t\t| N/n    | Modify The Name         |\n");
                                printf("\t\t\t\t| P/p    | Modify The percentage   |\n");
                                printf("\t\t\t\t| E/e    | Exit                    |\n");
                                printf("\t\t\t\t------------------------------------\n");
                                printf("\n\n");

                                printf("Enter Your Choice: ");
                                scanf(" %c",&op);
                                if(op=='P' || op=='p')
                                {
                                        percentage_byrollno(*ptr, name_find, roll);

                                }
                                else if(op=='N' || op=='n')
                                {
                                        name_byrollno((*ptr), name_find, roll);
                                }
                                else if(op=='E' || op=='e')
                                {
                                        printf("Returning To Modification The Main Menu:\n\n");

                                }
                                else
                                {
                                        printf("Invalid Case:\n\n");
                                }

                        }while(op!='E' && op!='e');
                        return;

	}

}

void mod_per(node**ptr)
{
	if((*ptr)==NULL)
	{
		printf("The Data List Empty:\n\n");
		return;

	}
	int flag=0;
	float mark_find;
	printf("Enter the Percentage To Find: ");
	scanf("%f",&mark_find);
	node*temp=(*ptr);
	node*found=NULL;
	printf("\t\t--------------------------------------------------\n");
        printf("\t\t| %-13s | %-15s   | %s |\n","Roll No","Name","Percentage");
        printf("\t\t--------------------------------------------------\n");
	while(temp!=NULL)
	{
		if(temp->percentage == mark_find)
		{
			flag++;
			found=temp;
			printf("\t\t| %-10d    | %-14s    | %-8.2f   |\n",temp->roll,temp->name,temp->percentage);
                        printf("\t\t--------------------------------------------------\n");

		}
		temp=temp->next;
	}
	if(flag==0)
	{
		printf("No Data Found:\n\n");
	}
	else if(flag==1)
	{
		char op;        
                        do      
                        {
                                printf("\t\t\t\t------------------------------------\n");
                                printf("\t\t\t\t| Choice | Operation               |\n");
                                printf("\t\t\t\t------------------------------------\n");
                                printf("\t\t\t\t| N/n    | Modify The Name         |\n");
                                printf("\t\t\t\t| P/p    | Modify The percentage   |\n");
                                printf("\t\t\t\t| E/e    | Exit                    |\n");
                                printf("\t\t\t\t------------------------------------\n");
                                printf("\n\n"); 
         
                                printf("Enter Your Choice: ");
                                scanf(" %c",&op);
                                if(op=='P' || op=='p')
                                {
                                        percentage(found);

                                }
                                else if(op=='N' || op=='n')
                                {
                                        name(found);
                                }
                                else if(op=='E' || op=='e')
                                {
                                        printf("Returning To Modification The Main Menu:\n\n");

                                }
                                else
                                {
                                        printf("Invalid Case:\n\n");
                                }

                        }while(op!='E' && op!='e');
                        return;

	}
	else
	{
		printf("-------Multiple Student Found with This Mark:-------\n\n");
		int roll;
                printf("Enter The Roll No: ");
                scanf("%d",&roll);

                char op;
                        do
                        {
                                printf("\t\t\t\t------------------------------------\n");
                                printf("\t\t\t\t| Choice | Operation               |\n");
                                printf("\t\t\t\t------------------------------------\n");
                                printf("\t\t\t\t| N/n    | Modify The Name         |\n");
                                printf("\t\t\t\t| P/p    | Modify The percentage   |\n");
                                printf("\t\t\t\t| E/e    | Exit                    |\n");
                                printf("\t\t\t\t------------------------------------\n");
                                printf("\n\n");

                                printf("Enter Your Choice: ");
                                scanf(" %c",&op);
                                if(op=='P' || op=='p')
                                {
                                        percentage_by_mark((*ptr),mark_find,roll);

                                }
                                else if(op=='N' || op=='n')
                                {
                                        name_by_mark((*ptr),mark_find,roll);
                                }
                                else if(op=='E' || op=='e')
                                {
                                        printf("Returning To Modification The Main Menu:\n\n");

                                }
                                else
                                {
                                        printf("Invalid Case:\n\n");
                                }

                        }while(op!='E' && op!='e');
                        return;

	}

}

void name(node*temp)
{
	if(temp==NULL)
	{
		printf("The Data List Is Empty:\n\n");
                return;
	}
	char new_name[50];
	printf("Enter The Name To Modify: ");
	scanf("%49s",new_name);
	strcpy(temp->name,new_name);
	printf("****************** The Name Modified successfully********************\n\n");
		
}

void percentage(node*temp)
{
        if(temp==NULL)
        {
                printf("The Data List Is Empty:\n\n");
                return;
        }
        float mark;
        printf("Enter The Mark To Modify: ");
        scanf("%f",&mark);
        temp->percentage=mark;
        printf("****************** The Percentage Modified successfully********************\n\n");
}

void name_byrollno(node*temp,char*name_find,int roll)
{
	if(temp==NULL)
        {
                printf("The Data List Is Empty:\n\n");
                return;
        }
	int flag=0;
	while(temp!=NULL)
	{
		if(temp->roll == roll && strcmp(temp->name, name_find) == 0)
		{
			flag=1;
			name(temp);
			return;
		}
		temp=temp->next;
	}
	if(flag==0)
        {
                printf("No Data Found:\n\n");
        }
}
void percentage_byrollno(node*temp,char*name_find,int roll)
{
	if(temp==NULL)
        {
                printf("The Data List Is Empty:\n\n");
                return;
        }
	int flag=0;
	while(temp!=NULL)
	{

		if(temp->roll == roll && strcmp(temp->name,name_find) ==0)
		{
			flag=1;
			percentage(temp);
			return;
		}
		temp=temp->next;
	}
	if(flag==0)
        {
                printf("No Data Found:\n\n");
        }

}

void percentage_by_mark(node*temp,float mark_find,int roll)
{
        if(temp==NULL)
        {
                printf("The Data List Is Empty:\n\n");
                return;
        }
        int flag=0;
        while(temp!=NULL)
        {

                if(temp->roll == roll && temp->percentage == mark_find)
                {
                        flag=1;
                        percentage(temp);
                        return;
                }
                temp=temp->next;
        }
        if(flag==0)
        {
                printf("No Data Found:\n\n");
        }

}

void name_by_mark(node*temp,float mark_find,int roll)
{
        if(temp==NULL)
        {
                printf("The Data List Is Empty:\n\n");
                return;
        }
        int flag=0;
        while(temp!=NULL)
        {

                if(temp->roll == roll && temp->percentage == mark_find)
                {
                        flag=1;
                        name(temp);
                        return;
                }
                temp=temp->next;
        }
        if(flag==0)
        {
                printf("No Data Found:\n\n");
        }

}


void mod_exit(void)
{
    printf("\nReturning to Main Menu...\n\n");
}
