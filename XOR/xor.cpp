#include <stdio.h>
#include <iostream>
using namespace std;

const long MAX = 1000001;
int arr [MAX];
int main () {
    int testcase, noofint, lb, ub, X;
    scanf ("%d", &noofint);
    for (int i =0; i<noofint; i++) scanf ("%d", &arr [i]);
    
	scanf ("%d", &testcase);
    while (testcase) {

        scanf ("%d%d%d", &lb, &ub, &X);
        
        int minimum = arr [lb-1] ^ X;
		int pos = lb-1;
        int count = 1;
        for (int j = lb; j<ub; j++) {
            int c= arr [j] ^ X;
            if (minimum > c ) {
                minimum = c;
				pos = j;
                count = 1;
            }
			else if (minimum == c) count ++;
        }

        printf("%d %d\n", arr[pos], count);

        testcase --;
    }
    return 0;
}

