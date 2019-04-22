#include<bits/stdc++.h> 
#define N 6 
  

void printSolution(int board[N][N]) 
{ 
    static int k = 1; 
    printf("%d-\n",k++); 
    for (int i = 0; i < N; i++) 
    { 
        for (int j = 0; j < N; j++) 
            printf(" %d ", board[i][j]); 
        printf("\n"); 
    } 
    printf("\n"); 
} 
  

bool isSafe(int board[N][N], int row, int col) 
{ 
    int i, j; 
  
    // Check this row on left side 
    for (i = 0; i < col; i++) 
        if (board[row][i]) 
            return false; 
  
    // Check upper diagonal on left side 
    for (i=row, j=col; i>=0 && j>=0; i--, j--) 
        if (board[i][j]) 
            return false; 
  
    // Check lower diagonal on left side
    for (i=row, j=col; j>=0 && i<N; i++, j--) 
        if (board[i][j]) 
            return false; 
  
    return true; 
} 
  

bool solveNQUtil(int board[N][N], int col) 
{ 
   
    if (col == N) 
    { 
        printSolution(board); 
        return true; 
    } 
  
    
    bool res = false; 
    for (int i = 0; i < N; i++) 
    { 
        
        if ( isSafe(board, i, col) ) 
        { 
            
            board[i][col] = 1; 
  
             
            res = solveNQUtil(board, col + 1) || res; 
  
           
            board[i][col] = 0; 
        } 
    } 
  
    
    return res; 
} 
  

void solveNQ() 
{ 
    int board[N][N]; 
    memset(board, 0, sizeof(board)); 
  
    if (solveNQUtil(board, 0) == false) 
    { 
        printf("Solution does not exist"); 
        return ; 
    } 
  
    return ; 
} 

int main() 
{ 
    solveNQ(); 
    return 0; 
} 

/*#include <stdio.h>
#include <string.h>

#define N 4
#define TRUE 1
#define FALSE 0

void print(int board[][N])
{
	int i=0,j=0;
	static int cnt=1;
	printf("\n %d\n",cnt++);
	for(i=0;i<N;i++)
	{
		printf("\t");
		for(j=0;j<N;j++)
		{
		
			printf("%d ",board[i][j]);	
		}
		printf("\n");
	}
	printf("\n\n\n");
}

int isSafe(int board[][N],int row,int col)
{
	int i=0,j=0;
	for(i=0; i<N ; i++)
	{
		if((board[i][col]==1) || (board[row][i]==1))
			return FALSE;
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(((i+j == row + col) || (i-j == row - col) ) && board[i][j]==1)
			{
				return FALSE;			
			}
		}
	}
	return TRUE;
}

int Nqueen(int board[][N],int n)
{
	int i,j,bool=0;
	if(n==0)
	{
		print(board);
		return TRUE;
	}
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(isSafe(board,i,j))
			{
				board[i][j] = 1;
				//bool = Nqueen(board,n-1) || bool;
				if(Nqueen(board,n-1))
					return TRUE;
				board[i][j] = 0;
			}
		}
	}
	return FALSE;
	//return bool;
}
int main()
{
	int board[N][N];
	int i,j,total=0;

	memset(board,0,sizeof(board));
	//Nqueen(board,N);
	print(board);
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++){
			total++;
			printf("\n%d-----%d\n",isSafe(board,i,j),total);		
		}
	}	
	
return 0;
}*/


