/************************************************
*
* Wrire a program to create a circular linked list and perform verious instruction like insertion and deletion of node. 
*
*
******************************************************/



/*****************************************************************************************
*
*	@file	circular_linked_list.c
*	@author	Dhrumil Mevada
*	@brief	This file will create circular linked list and perform verious opertaion on it.
*	@date	Aug/10/2018,created
*
**********************************************************************************/


/*************************************************************
* This program will work in foolowing manner:
* 1. Each time there is one menu display on execution screen from that menu user have to choose 
*    desire operation and enter relavent number using console.  	
* 
* 
*
* then program will perfom choose opertation and again show menu items,choose appropriately. 
*
* CONSTRAINTS:
* 1. If you enter number which not available , you have to go through it again.
*/


/***************
 * Include Files
 ***************/
#include<stdio.h>
#include<stdlib.h>


/*
*   Structure defination for single node in linked list
*   
*   @member	int : val: 		to hold value of node
*		struct Node* : next: 	to link next node in list 
*
**/
typedef struct Node{

    int val;
    struct Node* next;
}snode;


/*********************
 * Function Prototypes
 *********************/
snode* create_node (int);
void insert_node_first();
void insert_node_last();
void print_linked_list();
void insertion();
void insert_node_between();
void delete_node();


/****************************
*	Global variable
**************************/
int node_cnt = 0;			//to conut number of node in list
snode *head= NULL, *last=NULL;		//to point start and end node of list
snode *node;				//to create new node in linked list


/***************************** 
 * Function    	main
 * @date        Aug/10/2018
 * @brief       Main function of the program.
 * 
 *	        
 * @return      int: the result of execution.
 *		        0: success
 *		        -ve: on various failures.
 *                  -1: if command line is incorrect.
 *
 **************************************/
int main()
{

    int choice = 0;			//to choose operation from menu

    while(1)
    {
        printf("\n\tMenu for linked list:-\n");
        printf("-------------------------------------------\n\n");
        printf("\t\t1. Insert a node.\n");
        printf("\t\t2. Delete a node.\n");
        printf("\t\t3. Print a linked list.\n");			//menu of list of operation
        printf("\t\t4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice){
        case 1:
            insertion();				//to insert a node to list
            break;
        case 2:
            delete_node();				//to delete a node to list
            break;
        case 3:
            print_linked_list();			//to print linked list
            break;
        case 4:
            exit(0);					//to exit from program
            break;
        default:
            printf("\nInvalid choice\n\n");
            break;

        }
    }
    return 0;
}


/****************************** 
 * Function	create_node    	
 * @date        Aug/10/2018
 * @brief       to create a new node 
 * @param       int : val: value to add in newly created node
 * @return      int : 0 : memory to node is not allocated.	        
 * 	        snode *: node :return newly created node. 
 *
 *************************/
snode *create_node(int val){

        node = (snode*)malloc(sizeof(snode));		//allocate memory to node

        if(node == NULL)
        {
            printf("\nMemory is not allocated.");	//memory is nor allocate
            return 0;
        }
        else{
            node->val = val;				//store value into node
            node->next = NULL;				//point to next element in list
            return node;
        }
}

/****************************** 
 * Function	insertion    	
 * @date        Aug/10/2018
 * @brief       to show menu for verious insertion operation 
 * 
 *
 *************************/
void insertion()
{
    int choice;					//to choose menu operation
    printf("\n\t1. Insert at first.");
    printf("\n\t2. Insert at last.");		//menu operation for insrtion of node
     printf("\n\t3. Insert at middle.");

    printf("\nEnter your choice:- ");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        insert_node_first();			//to insert a node at start of list
        break;
    case 2:
        insert_node_last();			//to insert a node at end of list
        break;
    case 3:
        insert_node_between();			//to insert a node in between of list
        break;

    }
}

/****************************** 
 * Function	insert_node_first   	
 * @date        Aug/10/2018
 * @brief       to insert node at start of list    
 * 
 *
 *************************/
void insert_node_first(){
    int val;

    printf("\nEnter value of node:- ");			//to enter value to store in node
    scanf("%d",&val);

    node = create_node(val);				//call a function to create new node

    if(head==NULL){
        head = last = node;
        last->next=head;			//insert a node to list if list is empty
        node_cnt++;
    }
    else{
        node->next = head;
        head = node;
        last->next = head;			//insert a node to list at start of list
        node_cnt++;
    }
}


/****************************** 
 * Function	insert_node_last  	
 * @date        Aug/10/2018
 * @brief       to insert node at end of list    
 * 
 *
 *************************/
void insert_node_last(){

    int val;

    printf("\nEnter value of node:- ");		//to enter value to store in node 
    scanf("%d",&val);

    node = create_node(val);			//call a function to create new node

    if(head==NULL){
        head =last =node;		
        last->next=head;			//insert a node to list if list is empty
        node_cnt++;
    }
    else{
        node->next=last->next;
        last->next= node;			//insert a node to list at last of list
        last = node;
        node_cnt++;
    }
}


/****************************** 
 * Function	insert_node_between  	
 * @date        Aug/10/2018
 *
 * @brief       to insert node in between of list    
 * 
 *
 *************************/
void insert_node_between()
{
    int position=0;			//to get position where to insert a node

    while(position<1 || position>node_cnt)
    {
        printf("\n\tEnter -1 to exit.\n");
        if(node_cnt==0){
            printf("\nEnter a number between(1-%d):- ",node_cnt+1);		//if list is empty then execute this one
            scanf("%d",&position);
            if(position>=1 && position<=node_cnt+1)
            break;
        }
        else{
            printf("\nEnter a number between(1-%d):- ",node_cnt);
            scanf("%d",&position);
            if(position>=1 && position<=node_cnt)			//if list has a list of node then perform this
            break;
        }

        if(position!=-1 /*&& position!=0*/)
            printf("\n\tYour entered position is not exist.");		//enterd wrong position
        else if(position==-1){
            return ;							//to exist from operation
        }
    }
    if(position==1 /*|| position==0*/)
    {
        insert_node_first();			//to call operation if entered postion is 1 
    }
    else if(position==node_cnt)
    {
        insert_node_last();			//to call operation if entered postion is equals to number of node in list
    }
    else{					//to insert node in between list
        snode* temp;
        int i,val;				//to travesal of list ,loop counter, value to store in new node		

        temp=last;
        for(i=1; i<position-1; i++){
             temp=temp->next;			//travesal to specified position in list
        }

        printf("\nEnter value of node:- ");
        scanf("%d",&val);

        node = create_node(val);		//to create a node with specified value

        node->next = temp->next;
        temp->next = node;
        //last=node;
        node_cnt++;
    }
}


/****************************** 
 * Function	delele_node	
 * @date        Aug/10/2018
 *
 * @brief       to delete node in list    
 * 
 *
 *************************/
void delete_node(){

    if(head==NULL){				
        printf("\n\tlinked list is empty.\n");		//if list is empty
    }
    else
    {
        int position;
        snode* temp,*target;
        printf("Enter a position to be delete(1-%d):-",node_cnt);		//get a position of node to be delete
        scanf("%d",&position);

        if(position>=1 && position<=node_cnt)				//to check position is correctly entered or not
        {
            temp = head;
            if(position == 1)
            {
                if(head==last){
                    free(head);					//if postion is 1 then delete node at start of list
                    head=last=NULL;
                }
                else
                {
                    head = head->next;
                    last->next = head;				
                    temp->next = NULL;				
                    free(temp);
                }
                node_cnt--;
            }
            else if(position==node_cnt){
                int i;
                //temp  = head;
                for(i=1; i<position-1; i++)
                {
                    temp= temp->next;				//to delete node from last position of list
                }
                target = temp->next;
                temp->next = target->next;
                last = temp;
                target->next =NULL;
                free(target);
                node_cnt--;
            }
            else if(position<=node_cnt){
                int i;
                //temp  = head;
                for(i=1; i<position-1; i++)
                {
                    temp= temp->next;				//else delete node from specified location
                }						//travesal to specified location
                target = temp->next;
                temp->next = target->next;
                target->next =NULL;			
                free(target);
                node_cnt--;
            }

        }
    }
}


/****************************** 
 * Function	print_linked_list	
 * @date        Aug/10/2018
 *
 * @brief       to print linked list    
 * 
 *
 *************************/

void print_linked_list(){

    snode* temp;
    if(/*head == NULL ||*/ last==NULL){
        printf("\nLinked List is empty.");			//if linked list is empty
        return;
    }
    temp=last;
    do
    {
        printf("%d->",temp->val);
        temp=temp->next;					//travesal to list and print value of each node
    }
    while(temp!=last);
    printf("\n%d",node_cnt);
}
