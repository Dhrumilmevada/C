/***********************************************************
*   Write Program to create telephone directory in which you can insert data alphabetically ,search by name,mobile no,area,
*   delete by name & mobile no and edit by name of entry.
****************************/

/******************************************************************************
 *
 * @file    telephone_dir.c
 * @author  Dhrumil Mevada
 * @brief   This file to create telephone directory.
 * @date
 *          AUG/14/2018,Created
 *****************************************************************************/

/***********************************************************
*  The program works in following manner :
*  1. Each time you run code it shaw list of operation in menu
*  2. Then choose appropiate option from menu then repeat this
*
*  when you run this code you would get proper message on command line.
*
*  CONSTRAINTS :-
*  1. In name and area field enter value with first character in uppercase.
*  2. This Program is develop on windows machine so that if you run it linux
*     use mingw compiler.
*************************************************************************/

/**************************
* Inclide Files
***************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>



/********************************
* Structure for a single entry
**********************************/

typedef struct p_node{

	char name[15];
	char mob_no[11];
	char area[20];
	char email_id[25];
    struct p_node* next;
}pnode;



/*********************
* Function Prototypes
*********************/

pnode* create_node();
void insert();
void get_data();
int* check_data();
void print_nodes();
void serch();
void deleteNode();
void edit();
void setFlag(int *,int);
int removeNode(pnode *,int);
int serchToDisByName();
int serchToDisByArea();
pnode* serchToDisByNum();
void display_node(pnode *);
void display_node_by_index(pnode *,int );
void sort_list();



/******************
 * Global Variables
 ******************/
int node_cnt = 0,serch_cnt=0;
pnode *serchPointer[10];
pnode *head= NULL, *last=NULL;
pnode *node;
char name[15],mob_no[10],area[20],email_id[25];




/**************
 * Function    main
 * @date        AUG/14/2018
 * @brief       Main function of the program.
 * @return      int: the result of execution.
 *		        0: success
 *		        -ve: on various failures.
 *                  -1: if command line is incorrect.
 *****************/

int main()
{
	int choice;     /**to store choice for switch case**/

	while(1)
	{
	    choice = 0;

		printf("\n\n\tMenu for Telephone directory:\n");
		printf("\n\t\t1. Insert.");
		printf("\n\t\t2. Delete.");
		printf("\n\t\t3. Search.");                 /**menu operation for telephone directory**/
		printf("\n\t\t4. Display.");
		printf("\n\t\t5. Edit.");
		printf("\n\t\t6. Quit.");


        printf("\n\nEnter your choice :- ");
        fflush(stdin);                      /**Choice for switch case**/
        scanf("%d",&choice);


		switch((int)choice){

		case 1:
		    insert();               /**to insert a data in directory**/
			break;
		case 2:
		    deleteNode();           /**to delete entry from directory**/
            break;
		case 3:
            serch();                /**to search data in directory**/
			break;
		case 4:
		    print_nodes();          /***to print all the data in directory**/
			break;
		case 5:
            edit();                    /**to edit perticular field in telephone directory**/
		    break;
        case 6:
            exit(0);                /**to come out of data directory**/
        default:
            printf("\n\tInvalid Choice.");  /**when chooden incorrect operation from menu**/

		}
	}
	return 0;
}



/**************
 * Function     edit
 * @date        AUG/15/2018
 * @brief       Main function of the program.
 *
 *****************/
void edit(){

        int ret_value = -1;     /**to get count of serach data**/
        int loc=0;              /**to get index of data to update**/
        int i=-1;           /**loop conuter**/
        int j=1;
        int *invalid;           /**to check whether enterd number is already exits or not**/
        int wantEdit[4]={-1,-1,-1,-1};      /**to get flag to know which data to update**/


        ret_value = serchToDisByName();

        if(ret_value == 0)
            return;                                                               /**if directory is empty**/
        else if(ret_value > 0)
        {                                                               /**if directory has data that you search**/
            printf("\n\nEnter which entry do you want to edit : ");
            fflush(stdin);
            scanf("%d",&loc);                                        /**to choose which entry to select to update**/
            while(loc < 1 || loc > (ret_value)){
                printf("\n\nYou Entered incorrect choice.\n\nRe-enter correct choice from given list : ");
                fflush(stdin);
                scanf("%d",&loc);                                   /**to check entered choice is correct or not**/
            }
            printf("\n\nDo you what to edit name?[y/n]");
            setFlag(wantEdit,++i);                                   /**if want to update name that set flag to 1**/
            printf("\n\nDo you what to edit mobile number?[y/n]");
            setFlag(wantEdit,++i);                                  /**if want to update mobile no that set flag to 1**/
            printf("\n\nDo you what to edit area?[y/n]");
            setFlag(wantEdit,++i);                                      /**if want to update area that set flag to 1**/
            printf("\n\nDo you what to edit email-id?[y/n]");
            setFlag(wantEdit,++i);                                  /**if want to update email-id that set flag to 1**/

            if(wantEdit[0] == 1){
                printf("\n\nEnter name to update : ");
                fflush(stdin);                                          /**if name flag set to 1 then update name**/
                gets(name);
                strcpy(serchPointer[loc-1]->name,name);
            }
            if(wantEdit[1] == 1){
                printf("\n\nEnter mobile no. to update : ");
                fflush(stdin);                                  /**if mobile no flag set to 1 then update mobile no**/
                gets(mob_no);
                while(j)
                {
                    invalid = check_data();                         /**check if mobile no is already exits or not**/

                    if(*(invalid)==1)
                    {
                        printf("\n\n\tYour entered Mobile no. is already exist.\n\tTry something else.");
                        printf("\n\nEnter correct Mobile No. :-");
                        gets(mob_no);                /**if mobile no is already exits then enter again which not exits**/
                        *invalid = -1;
                        continue;
                    }
                    else if(*(invalid)==0 || *(invalid) == -1)
                    {
                        j=0;
                        *invalid = -1;                              /**if mobile no is correct or directory is empty**/
                        continue;
                    }
                }
                strcpy(serchPointer[loc-1]->mob_no,mob_no);
            }
            if(wantEdit[2] == 1){
                printf("\n\nEnter Area to update : ");
                fflush(stdin);                                      /**if area flag set to 1 then update area**/
                gets(area);
                strcpy(serchPointer[loc-1]->area,area);
            }
            if(wantEdit[3] == 1){
                printf("\n\nEnter email-id to update : ");
                fflush(stdin);
                gets(email_id);                                         /**if email-id flag set to 1 then update email-id**/
                strcpy(serchPointer[loc-1]->email_id,email_id);
            }
        }
        sort_list();
}



/**************
 * Function     sort_list
 * @date        AUG/15/2018
 * @brief       to sort telephone directory in ascending oreder.
 *
 *****************/

void sort_list(){

    pnode *temp,*prev,*temp2;  /**to point to data while sorting**/

    for(temp = head ; temp != NULL; temp = temp->next)
    {
        for(temp2 = temp->next; temp2 != NULL; temp2 = temp2->next)
        {
                if(strcmp(temp->name,temp2->name) > 0)
                {
                    strcpy(name,temp->name);
                    strcpy(mob_no,temp->mob_no);
                    strcpy(area,temp->area);
                    strcpy(email_id,temp->email_id);

                                                                    /**swaping data if data is not in ascending order**/
                    strcpy(temp->name,temp2->name);
                    strcpy(temp->mob_no,temp2->mob_no);
                    strcpy(temp->area,temp2->area);
                    strcpy(temp->email_id,temp2->email_id);

                    strcpy(temp2->name,name);
                    strcpy(temp2->mob_no,mob_no);
                    strcpy(temp2->area,area);
                    strcpy(temp2->email_id,email_id);
                }
        }
    }
}


/** Function    setFlag
 * @date        AUG/15/2018
 * @brief       To set flag 1 to upadte data or 0 to not to update
 * @param       int * : wantEdit : 1 to update / 0 to not update
 * @return      int: loc : at which index want to set flag
 *
 */
void setFlag(int *wantEdit,int loc){
    char confirm = 'x';

    fflush(stdin);
    scanf("%c",&confirm);
    if(confirm == 'Y' || confirm == 'y')        /**to confirm want to update**/
        *(wantEdit+loc) = 1;
    else
        *(wantEdit+loc) = 0;

}

/****************
*  Function     deleteNode
 * @date        AUG/15/2018
 * @brief       To choose which data to delete
 *
 ***********************/
void deleteNode()
{
    int choice;   /**choice to select operation from menu**/
    int i=1;        /**loop counter**/
    int ret_value=-1;   /**to store number of data selected**/
    int loc=0;          /**at which index data to delete **/
    pnode *temp;        /**to point to data**/
    char confirm;       /**to confirm deletion**/

    while(i)
    {
        choice = -1;

        printf("\n\n\tEnter your choice you want to delete by name or Mobile No. :");

        printf("\n\n\t\t0. To exit.");
        printf("\n\t\t1. To search by name.");                        /**Delete menu**/
        printf("\n\t\t2. To search by mobile no.");

        printf("\n\nEnter your choice : ");
        fflush(stdin);                                                 /**to choose operation from menu*/
        scanf("%d",&choice);

        switch(choice){
        case 1:
            ret_value = serchToDisByName();                             /**to delete data by name**/

            if(ret_value == 0 )
                i=0;                                                    /**directory is empty*/

            else if(ret_value > 0){

                printf("\n\nEnter which entry do you want to delete: ");
                fflush(stdin);
                scanf("%d",&loc);                                       /**select index to delete data*/
                while(loc < 1 || loc > ret_value){
                    printf("\n\nYou Entered incorrect choice.\n\nRe-enter correct choice from given list : ");
                    fflush(stdin);
                    scanf("%d",&loc);                               /**if index is invalid**/
                }

                printf("\n\nDo you really want to delete?[y/n]: ");
                fflush(stdin);
                scanf("%c",&confirm);                               /**to confirm the delete operation**/
                if(confirm == 'y' || confirm == 'Y')

                if(removeNode(serchPointer[loc-1],loc))
                    printf("\n\n Deleted Successfully!");               /**if it conform then delete data**/
                else
                    continue;                                           /**else continue further execution**/
                }
            break;
        case 2:                                                                    /**to delete data by number*/
            temp = serchToDisByNum();                                             /**index where to delete data*/

            if(temp != NULL){

                display_node(temp);

                printf("\n\nDo you really want to delete?[y/n]: ");
                fflush(stdin);
                scanf("%c",&confirm);                                   /**confirm deletion*/

                if(confirm == 'y' || confirm == 'Y')
                    if(removeNode(temp,0))                              /**if confirm then delete*/
                        printf("\n\n Deleted Successfully!");
                else
                    continue;                                               /**else continue with further execution**/
            }
            else if(temp == 0 && head == NULL)
                i=0;                                                    /**if directory is empty*/
            break;
        case 0:
            i=0;                                            /**to exit from delete operation*/
            break;
        default:
            printf("\n\n\tInvalid Choice");                 /**invalid choice selected*/
            break;
        }
    }
}



/****************
*  Function     removeNode
 * @date        AUG/15/2018
 * @brief       To remove selected data
 *  @param      pnode *: target : to point to date which you want to delete
 *  @return     int : 1: if data successfully deleted
 ***********************/

int removeNode(pnode* target,int loc){
    pnode *temp,*prev;      /**to travesal of data and to point previous data to which currently you are*/
    int i = 0;
    for(temp=head; temp!=target; temp=temp->next){
        i++;
        prev = temp;
    }
    if(i == 0 && (temp->next) != NULL){
        head = temp->next;
        temp->next = NULL;              /**if there is only one data in directory*/
        free(temp);
        node_cnt--;
        return 1;
    }
    else if(i == 0 && (temp->next) == NULL){
        head = last = NULL;
        free(temp);                             /**you want to delete first data in directory*/
        return 1;
    }
    else{
        if(i > 0 && (temp->next)==NULL)
            last = prev;
        prev->next = temp->next;
        temp->next = NULL;                          /**you want to delete any data from list*/
        free(temp);
        node_cnt--;
        return 1;
    }
}



/****************
*  Function     serch
 * @date        AUG/14/2018
 * @brief       To serch data by name ,mobile no, area
 *
 ***********************/

void serch()
{
    int choice;             /**to select operation from menu*/
    int i=1;                 /**loop counter*/
    pnode *temp;                /**to point to data in directory*/
    int ret_value=999;          /**number of data selected from directory*/

    while(i)
    {
        choice=-1;
        printf("\n\n\tEnter your choice you want to serch by name or Mobile No. :");

        printf("\n\n\t\t0. To exit.");
        printf("\n\t\t1. To search by name.");
        printf("\n\t\t2. To search by mobile no.");             /**menu for search operation*/
        printf("\n\t\t3. To search by Area.");

        printf("\n\nEnter your choice : ");
        fflush(stdin);
        scanf("%d",&choice);                                /**select operation from menu*/

        switch(choice)
        {
        case 1:
            ret_value = serchToDisByName();                 /**search and display data by name*/

            if (ret_value == 0)
                i=0;                                /**if data directory is empty*/

            serch_cnt=0;                /**reset number of serch data*/
            ret_value = 999;

            break;
        case 2:
            temp = serchToDisByNum();           /**search data by mobile num and return its address*/

            if(temp !=NULL)
                display_node(temp);                 /**to display selected data*/

            else if(temp == 0 && head == NULL)
                i=0;                            /**if data directory is empty*/

            break;
        case 3:
            ret_value = serchToDisByArea();     /**serch by area and return number of data selected by search*/

            if (ret_value == 0)
                i=0;                            /**if directory is empty**/

            serch_cnt=0;                        /**reset number of selected data*/
            ret_value = 999;

            break;
        case 0:
            i=0;                            /**to exit from serach operation.*/
            break;
        default:
            printf("\n\n\tInvalid Choice");             /**choose invalid oprion from menu*/
        }
    }
}



/****************
 *  Function     serchToDisByArea
 * @date        AUG/14/2018
 * @brief       To serch data by area
 *
 ***********************/

int serchToDisByArea(){
    pnode *temp;            /**to travesal the data in directory*/

    printf("\n\nEnter an Area you want to serch : ");
    fflush(stdin);
    gets(area);                             /**Enter area you want to search*/

    if(head == NULL)
    {
        printf("\n\nTelephone directory is currently empty.");
        return 0;                                                   /**if directory is empty*/
    }
    else {
        for(temp=head ; temp != NULL; temp = temp->next){
            if(strcmp(temp->area,area) == 0)           /**go through the directory and check area which you search for*/
            {
                display_node_by_index(temp,serch_cnt+1);           /**display if you data found with serched area*/
                serch_cnt++;
            }
        }
        if(serch_cnt == 0){
             printf("\n\nArea is not available in directory.");         /**if there is no data for which you serach*/
            return -1;
        }

    }
    return serch_cnt;                           /**return number of search data found*/
}

/****************
 *  Function    serchToDisByName
 * @date        AUG/14/2018
 * @brief       To serch data by Name
 *
 ***********************/
int serchToDisByName(){

    pnode *temp;                /**to go through the data*/
    int i;                      /**loop counter*/

    for(i=0;i<10;i++)
        serchPointer[i] = NULL;         /**make pointer to selected data null*/
    serch_cnt = 0;                      /**number of selected data to 0*/

    printf("\n\nEnter a Name you want to search : ");
    fflush(stdin);
    gets(name);                                     /**Enter name which you want to delete*/

    if(head == NULL)
    {
        printf("\n\nTelephone directory is currently empty.");  /**if directory is empty*/
        return 0;
    }
    else {
        for(temp=head ; temp != NULL; temp = temp->next){
            if(strcmp(temp->name,name) == 0)                /**chech for data with enterd name to serch*/
            {
                serchPointer[serch_cnt] = temp;             /**if data found that put search pointer on that*/
                display_node_by_index(temp,serch_cnt+1);     /**diaply selected node**/
                serch_cnt++;
            }
        }
        if(serch_cnt == 0){
             printf("\n\nName is not available in directory.");
            return -1;                                              /**searched data is not available*/
        }
    }
    return serch_cnt;    /**return number of data selected*/
}



/****************
 *  Function    serchToDisByNum
 * @date        AUG/14/2018
 * @brief       To serch data by Mobile no
 *
 ***********************/

pnode* serchToDisByNum(){

    pnode *temp;        /**to go through data in directory*/

    printf("\n\nEnter a Mobile No. you want to search : ");
    fflush(stdin);
    gets(mob_no);                                   /**Enter mobile no to search*/

    if(head == NULL)
    {
        printf("\n\nTelephone directory is currently empty.");  /**if data directory is empty*/
        return NULL;
    }
    else{
        for(temp = head ; temp != NULL; temp = temp->next){
            if (strcmp(temp->mob_no,mob_no) == 0){
                return temp;                            /**if searched mobile no is found then return its address*/
            }
        }
        if(temp == NULL)
            printf("\n\nMobile Number is not available in directory.");  /**if searched mobile no is not found*/
        return NULL;
    }
}



/****************
 *  Function    crete_node
 * @date        AUG/14/2018
 * @brief       To allocate space to store data
 *
 ***********************/
pnode* create_node()
{
	node = (pnode *)malloc(sizeof(pnode));          /**to allocate space dynamically*/

	if(node == NULL)
	{
		printf("\nMemory is not allocated.");           /**if memory is not returned*/
		return NULL;
	}
	else
	{
		strcpy(node->name,name);
		strcpy(node->mob_no,mob_no);                /**store data to allocated memory*/
		strcpy(node->area,area);
		strcpy(node->email_id,email_id);
		node->next = NULL;
		return node;
	}
}


/****************
 *  Function    insert
 * @date        AUG/14/2018
 * @brief       To append data in directory
 *
 ***********************/
void insert()
{
	int i=1;            /**loop counter*/
	int* invalid;           /**to check enter mobile no. is valid or not*/

    get_data();             /**to get data to store*/


	while(i)
	{
		invalid = check_data();             /**check mobile no if it is valid or not*/

		if(*(invalid)==1)
		{
			printf("\n\tYour entered Mobile no. is already exist.\n\tTry something else.");
			printf("\n\nEnter correct Mobile No. :-");
			gets(mob_no);
			*invalid = -1;              /**mobile no already exits so you have to enter it again*/
			continue;
		}
		else if(*(invalid)==0 || *(invalid) == -1)
		{
			i=0;
			*invalid = -1;                      /**mobile no is valid or list is empty.*/
			continue;
		}
	}
	node = create_node();                       /**allocate space for data*/

	if(head == NULL){
        head = last =node;              /**if directory is empty*/
        node_cnt++;
	}
	else{
        int i=0;
        pnode* temp,*prev;
        for(temp=head; temp!=NULL && strcmp(temp->name,node->name) < 0; temp= temp->next)
        {
            prev = temp;                            /**to travesal the data to find index at which enter data in */
            i++;                                        /***ascending order*/
        }
        if(temp == NULL)
        {
            prev->next = node;                  /**to enter data at end of list*/
            last = node;
            node_cnt++;
        }
        else if(i==0){
            node->next = temp;                  /**to enter a data at start of list*/
            head = node;
            node_cnt++;
        }
        else{
        node->next = temp;
        prev->next = node;              /**to enter a data in between list*/
        node_cnt++;
        }
	}
}


/****************
 *  Function    get_data
 * @date        AUG/14/2018
 * @brief       To get the data to store
 *
 ***********************/
void get_data()
{

    printf("\nEnter Name: ");
	fflush(stdin);                  /**to get name*/
	gets(name);
	printf("\nEnter Mobile No: ");
	fflush(stdin);
	gets(mob_no);                   /**to get mobile no*/
	//scanf("%s",mob_no);
	printf("\nEnter Area: ");
	fflush(stdin);
	gets(area);                         /**to get area*/
	printf("\nEnter Email ID: ");
	fflush(stdin);
	gets(email_id);                     /**to get email-id*/
    fflush(stdout);
}


/****************
 *  Function    check_data
 * @date        AUG/14/2018
 * @brief       To check mobile is valid or not
 * @return      int * : 0: directory is empty
 *                      1 : mobile no is not valid
 *                      -1: mobile no is valid
 ***********************/
int * check_data()
{

	static int invalid = -1;        /**to store validity of mobile no*/

	pnode *temp = head;

	if(head == NULL)
	{
	    invalid = 0;                /**directory is empty*/
        return &invalid;
	}
	else
	{
		for(temp=head; temp!=NULL; temp=temp->next)
		{
			if(strcmp(temp->mob_no,mob_no) == 0)
			{
				invalid = 1;
				return (&invalid);          /**Mobile no is not empty*/
			}
        }
        return &invalid;            /**mobile no is valid*/
	}
}


/****************
 *  Function    prints_nodes
 * @date        AUG/14/2018
 * @brief       To print all data
 *
 ***********************/
void print_nodes()
{
    pnode *temp;
    int i=1;
    if(head==NULL)
    {
        printf("\n\nTelephone Directory is currently empty.");
    }
    else{
        for(temp=head;temp!=NULL; temp = temp->next)
        {
            printf("\n\n\t %d. Name : %s",i,temp->name);
            printf("\n\t    Mobile No. : %s",temp->mob_no);
            printf("\n\t    Area : %s",temp->area);
            printf("\n\t    Email ID : %s",temp->email_id);
            i++;
        }
    }
}



/****************
 *  Function    diaplay_node
 * @date        AUG/14/2018
 * @brief       To print perticular data
 * @param       pnode* : temp :address of data which it print
 ***********************/
void display_node(pnode *temp){
    printf("\n\n\t 1. Name : %s",temp->name);
    printf("\n\t    Mobile No. : %s",temp->mob_no);
    printf("\n\t    Area : %s",temp->area);
    printf("\n\t    Email ID : %s",temp->email_id);

}



/****************
 *  Function    diaplay_node_by_index
 * @date        AUG/14/2018
 * @brief       To print perticular data with index
 * @param       pnode* : serch :address of data which it print
 *             int : cnt : index of data
 ***********************/
void display_node_by_index(pnode *serch,int cnt)
{
    printf("\n\n\t %d. Name : %s",cnt,serch->name);
    printf("\n\t    Mobile No. : %s",serch->mob_no);
    printf("\n\t    Area : %s",serch->area);
    printf("\n\t    Email ID : %s",serch->email_id);
}
