#include <iostream>
#include <stdlib.h>
using namespace std;

const int MAX = 185;

char bitmap [MAX][MAX];
int answer[MAX][MAX];
int row	[35000];
int col [35000];
int whitecount = 0, rows, column;

inline int dis(int i,int j,int k ,int l){

        int one=i-k;
        int two=j-l;
        if (one<0)one*=-1;
        if (two<0)two*=-1;
        return one+two;
}

inline int CalculateLength (int a, int b)
{
	int dist = 35000;
	for (int i = 0; i < whitecount; i++)
	{
		//int temp = abs (a - row [i]) + abs (b - col [i]);
		int temp = dis (a,b,row[i],col[i]);

		dist = dist > temp ? temp : dist;

		if (dist == 1)
			break;
	}
	return dist;
}

inline void search (int x,int y,int i, int j){

	if(i >= 0 && i < rows && j >= 0 && j < column){

        if (bitmap [i][j] == '1') return;

        //int dist = abs (x-i) + abs (y-j);

		int dist = dis (x,y,i,j);
			
		if(answer [i][j] <= dist) return;

		answer [i][j] = dist;

        search (x,y,i,j+1);
        search (x,y,i,j-1);
        search (x,y,i-1,j);
        search (x,y,i+1,j);
	}

	else
		return;
} 

int main ()
{
	int testcase, i, j, dist;

	scanf ("%d", &testcase);

	while (testcase --)
	{
		whitecount = 0;

		 scanf ("%d%d",&rows, &column);
		 for (i=0 ;i <rows; i++)
		 {
				cin>>bitmap [i];

				for (j=0; j<column; j++) 
				{
					if (bitmap [i][j] == '1') {
						 row [whitecount] = i;
						 col [whitecount] = j;
						 whitecount ++;
					}
					answer [i][j] = 35000;

				}
		 }
		 
		 if (whitecount < 2) {
			for (i=0 ;i <rows; i++)
			{
				 for (j = 0; j< column; j++)
				{
					dist = 0;
					if (bitmap [i][j] == '0') {
						dist = CalculateLength (i,j);
					 }
					printf ("%d ", dist); 
				}
				printf ("\n");
			}
		 }

		 else { 
			for(i=0; i<whitecount; i++){

				 answer[row [i]][col [i]]=0;
               
				search (row [i], col [i], row [i], col [i]+1);
                search (row [i], col [i], row [i], col [i]-1);
                search (row [i], col [i], row [i]+1, col [i]);
                search (row [i], col [i], row [i]-1, col [i]);
            }

			for(i=0; i<rows; i++){
               for(j=0; j<column; j++){

                   printf("%d ",answer[i][j]);
                } 
               printf("\n");
            }
		 }
	}
	return 0;
}
