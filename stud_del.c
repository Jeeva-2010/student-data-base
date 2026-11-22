#include"header.h"
void del_roll(node**ptr);
void del_name(node**ptr);
void del_exit(void);
void del1(node**ptr,int n,char*name);
void stud_del(node**ptr)
{
	char op;
	do
	{
		printf("\t\t\t\t------------------------------------\n");
                printf("\t\t\t\t| Choice | Operation               |\n");
                printf("\t\t\t\t------------------------------------\n");
                printf("\t\t\t\t| R/r    | Delete By Roll No       |\n");
                printf("\t\t\t\t| N/n    | Delete By Name          |\n");
                printf("\t\t\t\t| E/e    | Exit                    |\n");
                printf("\t\t\t\t------------------------------------\n");
		printf("\n\n");

		printf("Enter Your Choice: ");
		scanf(" %c",&op);
		if(op=='R' || op=='r')
		{
			del_roll(ptr);
		}
		else if(op=='N' || op=='n')
		{
			del_name(ptr);
		}
		else if(op=='E' ||op=='e')
		{
			del_exit();
		}
		else
		{
			printf("invalid case:\n\n");
		}

	}while(op!='E' && op!='e');
}
void del_roll(node**ptr)
{
	if((*ptr)==NULL)
	{
		printf("The Data List Is Empty:\n\n");
		return;
	}
	int data;
	printf("Enter Roll No To Find: ");
	scanf("%d",&data);
	
	node*temp=(*ptr);
        node*prv=NULL;
	printf("\t\t--------------------------------------------------\n");
        printf("\t\t| %-13s | %-15s   | %s |\n","Roll No","Name","Percentage");
        printf("\t\t--------------------------------------------------\n");
        while(temp!=NULL)
        {

                if(temp->roll==data)
                {
                        if((*ptr)==temp)
                        {
                                *ptr=(*ptr)->next;
				printf("\t\t| %-10d    | %-14s    | %-8.2f   |\n",temp->roll,temp->name,temp->percentage);
                        	printf("\t\t--------------------------------------------------\n");
                        }
                        else
                        {
                                prv->next=temp->next;
				printf("\t\t| %-10d    | %-14s    | %-8.2f   |\n",temp->roll,temp->name,temp->percentage);
                        	printf("\t\t--------------------------------------------------\n");

                        }
                        printf("deleted succesfully:\n\n");
                        free(temp);
                        return;
                }
                prv=temp;
                temp=temp->next;
        }
        printf("No Data Found:\n\n");	
}

void del_name(node**ptr)
{
	if((*ptr)==NULL)
        {
                printf("The Data List Is Empty:\n\n");
                return;
        }
	int cmp;
	int flag=0;
        char n[50];
        printf("Enter Name To Find: ");
        scanf("%49s",n);

        node*temp=(*ptr);
	int roll1=0;
	int roll2=0;
	printf("\t\t--------------------------------------------------\n");
        printf("\t\t| %-13s | %-15s   | %s |\n","Roll No","Name","Percentage");
        printf("\t\t--------------------------------------------------\n");
        while(temp!=NULL)
        {
		cmp=strcmp(temp->name,n);
                if(cmp==0)
                {
			flag++;
		    	printf("\t\t| %-10d    | %-14s    | %-8.2f   |\n",temp->roll,temp->name,temp->percentage);
                	printf("\t\t--------------------------------------------------\n");
			roll1=temp->roll;			
                }
                temp=temp->next;
        }
	if(flag==0)
	{
        	printf("No Data Found:\n\n");
	}
	else if(flag==1)
	{
		del1(ptr,roll1,n);
	}
	else
	{
		printf("-------Multiple Student Found with This Name:-------\n\n");
		printf("Enter The Roll No: ");
		scanf("%d",&roll2);
		del1(ptr,roll2,n);
	}
}
void del1(node**ptr,int n,char*name)
{
	if((*ptr)==NULL)
        {
                printf("The Data List Is Empty:\n\n");
                return;
        }
	node*temp=(*ptr);
	node*prv=NULL;
	while(temp!=NULL)
        {

                if(temp->roll == n && strcmp(temp->name, name) == 0)
                {
                        if((*ptr)==temp)
                        {
                                *ptr=(*ptr)->next;
                        }
                        else
                        {
                                prv->next=temp->next;
                        }
                        printf("Deleted Successfully:\n\n");
                        free(temp);
                        return;
                }
                prv=temp;
                temp=temp->next;
        }
	printf("No Data Found:\n\n");

}

void del_exit(void)
{
    printf("\nReturning to Main Menu...\n\n");
}
