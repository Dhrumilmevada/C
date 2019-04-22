#include <stdio.h>
#include <string.h>

#define N 6
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

int isSafe(int board[][N],int row, int col)
{
	int i,j;
	//printf("\n%d-%d\n",row ,col);
	for(i=0;i<col;i++)
	{
		if(board[row][i]==1)
		{
			//printf("\ncol-%d-%d\n",i,j);
			return FALSE;
		}
	}
	for(i=row,j=col ; i>=0 && j>=0 ; i--,j--)
	{
		if(board[i][j]==1)
		{
			//printf("\nupper diagonal-%d-%d\n",i,j);
			return FALSE;
		}
	}
	for(i=row,j=col ; i<N && j>=0 ; i++,j--)
	{
		if(board[i][j]==1)
		{
			//printf("\nlower diagonal-%d-%d\n",i,j);
			return FALSE;
		}
	}

	return TRUE;
} 

int Nqueen(int board[][N],int n)
{
	int i;
	if(n == N)
	{
		print(board);
		return TRUE;
	}
	for(i=0;i<N;i++)
	{
		if(isSafe(board,i,n))
		{
			board[i][n] = 1;

			Nqueen(board,n+1);
			//if(Nqueen(board,n+1)==TRUE)
				//return TRUE;

			board[i][n] = 0;
		}
	}
	return FALSE;
}
int main()
{
	int board[N][N];
	int i,j,total=0;

	memset(board,0,sizeof(board));
	Nqueen(board,0);
	//print(board);
	
	//for(i=0;i<N;i++)
	//{
	//	for(j=0;j<N;j++){
	//		total++;
	//		printf("\n%d-----%d\n",isSafe(board,i,j),total);		
	//	}
	//}	
	
return 0;
}

