#include"header.h"
int next_roll = 1;
void stud_add(node**ptr)
{

	// allocate memory
	node*new=(node*)malloc(sizeof(node));

	if(new == NULL)
	{
    	printf("Memory allocation failed\n");
    	return;
	}

	// allocate data
	new->roll = next_roll;
	next_roll++;
	printf("Enter The Student Details Of Name And percentage:\n");
	scanf("%49s%f",new->name,&new->percentage);
	//linking node address
	
	if((*ptr)==NULL)
	{
		new->next=NULL;
		(*ptr)=new;
	}
	else
	{
		node*last=(*ptr);
		while(last->next != NULL)
		{
			last=last->next;
		}
		new->next=last->next;
		last->next=new;
	}

}
