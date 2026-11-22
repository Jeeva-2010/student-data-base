#include"header.h"
int main()
{
	char op;
	node*hptr=NULL;
	stud_load(&hptr);
	do
	{
		printf("\n\t\t\t\t**** STUDENT RECORD MENU ****\n");
        	printf("\t\t\t\t--------------------------------\n");
        	printf("\t\t\t\t| Choice | Operation            |\n");
        	printf("\t\t\t\t--------------------------------\n");
        	printf("\t\t\t\t| A/a    | Add New Record       |\n");
        	printf("\t\t\t\t| D/d    | Delete a Record      |\n");
        	printf("\t\t\t\t| S/s    | Show the List        |\n");
        	printf("\t\t\t\t| M/m    | Modify a Record      |\n");
        	printf("\t\t\t\t| V/v    | Save                 |\n");
        	printf("\t\t\t\t| T/t    | Sort the List        |\n");
        	printf("\t\t\t\t| E/e    | Exit                 |\n");
        	printf("\t\t\t\t--------------------------------\n\n");

        	printf("\n\n");

		printf("Enter your choice: ");
		scanf(" %c",&op);
		switch(op)
		{
			case 'A':
			case 'a':
                                stud_add(&hptr);
                                break;
			case 'D':
			case 'd':
				stud_del(&hptr);
				break;
			case 'S':
			case 's':
                                stud_show(hptr);
                                break;
			case 'M':
			case 'm':
                                stud_mod(&hptr);
                                break;
			case 'V':
			case 'v':
                                stud_save(hptr);
                                break;
			case 'T':
			case 't':
                                stud_sort(&hptr);
                                break;
			case 'E':
			case 'e':
                                stud_exit(hptr);
                                break;
			default:
				printf("invalid case:\n\n");
				break;

		}
	}while((op!='e') &&(op!='E'));

}
