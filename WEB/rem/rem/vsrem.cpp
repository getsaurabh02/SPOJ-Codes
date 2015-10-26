#include <stdio.h>
#include <iostream>
using namespace std;


const long MAX = 100001;
int arr [MAX];

int main () {

    int testcase, frnds, todelete;
    scanf ("%d" , &testcase);

    while (testcase) {

         scanf ("%d%d" , &frnds, &todelete);
	     for (int i =0; i<frnds ; i++) scanf ("%d", &arr [i]);
		 int j;
         for (int i =0 ; i< frnds && todelete; ) {

			 for (j = i + 1; arr [j] == -1; j++ );
			
			 if (j<frnds && (arr[i] != -1) && (arr[i] < arr[j])) {
				  arr [i] = -1;
                  todelete --;
				  if (i >0) {
					  while (arr[i] == -1) i--;
				  }
              }
			  else {
					i ++;
			  }
             
          }
		  
		 for (j = frnds -1 ; todelete ; j--) {
			if (arr[j] != -1) {
				arr[j] = -1;
				todelete--;
			}
		 }
		 for (int i= 0; i< frnds ; i++) { if (arr[i] != -1) printf ("%d ", arr[i]); }
		 printf ("\n");

        testcase --;
    }
    

	return 0;

}
