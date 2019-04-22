/*
*write a program to multiply two metrix and print result metric will be print as output.
*/


/*
*	@file	mul_matrix.c
*	@author	Dhrumil Mevada
*	@brief	This file will multiply a two given matrix and give multiplied matrix as output.
*	@date	Aug/10/2018,created
*/

/*
* This program will work in foolowing manner:
* User can have to give some input from console:-
* 1. Number of rows and coloums in first metrics.
* 2. Number of rows and coloums in second metrics.
* 3. Elements for both matrics as specified above.
*
* then program will perfom multiplication and after that it will print result matric. 
*
* CONSTRAINTS:
* 1. number of coloum in first metric will be same with number of rows in second metric.
*/


/***************
 * Include Files
 ***************/
#include <stdio.h>

/*********************
 * Function Prototypes
 *********************/
void printMatrix(int*,int,int);
void getMatrix(int* ,int,int);
void mulMatrix(int*,int,int,int*,int,int,int*);


/** Function    main
 * @date        Aug/10/2018
 * @brief       Main function of the program.
 * 
 *	        
 * @return      int: the result of execution.
 *		        0: success
 *		        -ve: on various failures.
 *                  -1: if command line is incorrect.
 */
int main()
{
	int  r1, c1, r2, c2;	//to store number of rows and col
	int i, j, k;		//to use as loop counter

    printf("Enter rows and column for first matrix: ");		
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and column for second matrix: ");
    scanf("%d %d",&r2, &c2);

    int mat_1[r1][c1], mat_2[r2][c2], final_mat[r2][c1];	//to store the element of metrics

    while (c1 != r2)
    {
        printf("Error! column of first matrix not equal to row of second.\n\n");
        printf("Enter rows and column for first matrix: ");				//to check cols of first matrix and 
        scanf("%d %d", &r1, &c1);							//rows of second metrix are same if yes move ahead
        printf("Enter rows and column for second matrix: ");				//else ask to input once again correctly
        scanf("%d %d",&r2, &c2);
    }

    printf("\nEnter elements of matrix 1:\n\n\n");
    getMatrix((int *)mat_1,r1,c1);			//function to get element of first metric

    printf("\nEnter elements of matrix 2:\n\n\n");
    getMatrix((int*)mat_2,r2,c2);			//function to get element of first metric

    for(i=0; i<r1; ++i)
        for(j=0; j<c2; ++j)
        {
            final_mat[i][j] = 0;			//to iniallize resultant metric with all element to zero
        }
    mulMatrix((int*)mat_1,r1,c1,(int*)mat_2,r2,c2,(int*)final_mat);    //function to multiply two given metrix
    printf("\nOutput Matrix:\n");
    printMatrix((int *)final_mat,r1,c2);			//function to print given metric

    return 0;
}


/** Function    getMatrix
 * @date        Aug/10/2018
 * @brief       to get data for metric
 * @param       int *: array: matrix in which we have to give data 
 *	        int : row: number of rows in metric
 * 	        int : col: number of cols in metric
 * @return      NULL
 */
void getMatrix(int* array,int row,int col)
{
  int i,j;
  for (i=0;i<row;i++)
  {
    for(j=0;j<col;j++)
    {
         printf("Enter elements mat_1:%d%d: ",i+1, j+1);
        scanf("%d",(array+(i*col)+j));
    }
  }
}


/** Function    printMatrix
 * @date        Aug/10/2018
 * @brief       to print data for metric
 * @param       int *: array: matrix  which we have to print 
 *	        int : row: number of rows in metric
 * 	        int : col: number of cols in metric
 * @return      NULL
 */
void printMatrix(int* array,int row,int col)
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d  ",*(array+(i*col)+j));
        }
        printf("\n");
    }
}


/** Function    mulMatrix
 * @date        Aug/10/2018
 * @brief       to multiply data of two metric
 * @param       int *: mat_1: matrix one which are going to multiply 
 *	        int : r1: number of rows in metric one 
 * 	        int : c1: number of cols in metric one
 *		int *: mat_2:matrix one which are going to multiply  
 *		int : r2: number of rows in metric two
 *		int : c2: number of cols in metric two 
 *
 * @return      NULL
 */
void mulMatrix(int* mat_1,int r1,int c1,int* mat_2,int r2,int c2,int *final_mal)
{
    int i,j,k;

    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            for(k=0;k<r2;k++)
                {
                    *(final_mal+(i*c2)+j) += (*(mat_1+(i*c1)+k))*(*(mat_2+(k*c1)+j));
                }
        }
    }
}
