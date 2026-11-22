#include"header.h"
int stud_save(node*ptr)
{
	if(ptr == NULL)
    	{
        	printf("No student records. Saving an empty file.\n");
        	
    	}
	FILE*fp=fopen("student.dat","w");

	if(fp == NULL)
	{
    	printf("File opening failed\n");
    	return 0;
	}
    	while(ptr != NULL)
    	{
		fprintf(fp,"%d %s %.2f\n",ptr->roll,ptr->name,ptr->percentage);
		ptr = ptr->next;
    	}
	if(fclose(fp) == EOF)
	{
   	 	printf("File saving failed\n");
    		return 0;
	}

    	printf("\t********************* The Data Saved Successfully: **********************\n\n");
	FILE *cfp = fopen("counter.dat", "w");

	if(cfp == NULL)
	{
    		printf("Counter file opening failed\n");
    		return 0;
	}

	fprintf(cfp, "%d\n", next_roll);

	if(fclose(cfp) == EOF)
	{
    		printf("Counter file saving failed\n");
    		return 0;
	}
	return 1;
}
void stud_load(node**ptr)
{
	FILE *fp = fopen("student.dat", "r");
                int roll;
                char name[50];
                float percentage;
                int saved_roll;
	
	if(fp!=NULL)
	{
		while((fscanf(fp,"%d %49s %f",&roll,name,&percentage))==3)
		{
			node *new = (node*)malloc(sizeof(node));
			if(new==NULL)
			{
				printf("The Node Creation Is Failed:\n\n");
				fclose(fp);
				return;
			}
			new->roll=roll;
			strcpy(new->name,name);
			new->percentage=percentage;
			if(roll >= next_roll)
			{
    				next_roll = roll + 1;
			}

			if((*ptr)==NULL)
			{
				new->next=(*ptr);
				*ptr=new;
			}
			else
			{
				node*last=*ptr;
				while(last->next!=NULL)
				{
					last=last->next;
				}
				new->next=last->next;
				last->next=new;

			}

	}
	fclose(fp);
	}
	else
	{
    		printf("No Previous Student Records Found:\n\n");
	}
	FILE *cfp = fopen("counter.dat", "r");

	if(cfp != NULL)
	{
    		if(fscanf(cfp, "%d", &saved_roll) == 1)
    		{
        		if(saved_roll > next_roll)
        		{
            			next_roll = saved_roll;
        		}
    		}

   		 fclose(cfp);
	}
        printf("Student Records Loaded Successfully\n");

}
