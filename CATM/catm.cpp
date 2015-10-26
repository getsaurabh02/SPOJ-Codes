#include <iostream>

using namespace std;

int CheckDiagonal (int mx, int my, int c1x, int c1y, int c2x, int c2y) {
    
    if ((mx + my == c1x + c1y) && (mx + my == c2x + c2y)) {
        return true;
    }
    if ((mx - my == c1x - c1y) && (mx - my == c2x - c2y)) {
        return true;
    }
    return false;
}

int main (int argc, char *argv[])
{
    int testcase, row, column;
    int mx, my, c1x, c1y, c2x, c2y;
   
    scanf ("%d%d", &row, &column);
    scanf ("%d", & testcase);

    while (testcase) {
        bool safe = false;
        scanf ("%d%d%d%d%d%d",&mx, &my, &c1x, &c1y, &c2x, &c2y);

        //Check the diagonal
        if (CheckDiagonal (mx, my, c1x, c1y, c2x, c2y)) {
            if (((c1x < c2x) && (c1x < mx) && (c2x > mx)) || ((c1x > c2x) && (c1x > mx) && (c2x < mx))) {
                printf("\nNO\n"); 
            }
            else {
                 printf("\nYES\n");
            }
            
        }
        else {
            printf("\nYES\n");
        }
		testcase--;
    }
    return(0);
}



