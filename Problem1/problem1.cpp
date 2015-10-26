#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

void quicksort(int x[51],int first,int last){
    int pivot,j,temp,i;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(x[i]<=x[pivot]&&i<last)
                 i++;
             while(x[j]>x[pivot])
                 j--;
             if(i<j){
                 temp=x[i];
                  x[i]=x[j];
                  x[j]=temp;
             }
         }

         temp=x[pivot];
         x[pivot]=x[j];
         x[j]=temp;
         quicksort(x,first,j-1);
         quicksort(x,j+1,last);

    }
}


int diceGame (int result_size, char ** result) {

        char *      res;
        int         digit = 0;
        int         sum = 0;
		int			max_digit [51];
        int			current_digit [51];

    //Count the number of digits in each note
    res = result [0];
    while (*res) {
        max_digit [digit] = -1;
        digit++;
        res++;
         
    }

    for (int i =0 ; i< result_size ; i++) {
        
        res = result[i];

        for (int j = 0; j< digit; j++) {

            current_digit [j] = (int)  (res [j] - (int)'0');
        }

        quicksort(current_digit, 0, digit--);

        for (int j = 0; j< digit; j++) {

            if (max_digit [j] < (int) (res [j] - (int)'0')) {
                max_digit [j] = (int)  (res [j] - (int)'0');
            }
        }
    }


    for (int s = 0; s < digit; s++) {

        sum += max_digit[s];
    }

    return sum;

}

int main () {

    FILE *f = fopen (getenv ("OUTPUT_PATH"), "w");
    int res;

    int _result_size, _result_i;
    scanf ("%d\n", &_result_size);
    char * _result[51];

	for (_result_i = 0; _result_i < _result_size; _result_i++) {

        char * _result_item;
        _result_item = (char *) malloc (1024 * sizeof (char));
        scanf ("\n%[^\n]"), _result_item);

        _result[_result_i] = _result_item;
    }

    res = diceGame (_result_size, _result);
    fprint (f, "%d\n", res);

    fclose (f);
    return 0;


}

