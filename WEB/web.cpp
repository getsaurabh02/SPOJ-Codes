#include<stdio.h>
#include<iostream>

const int MAX = 1000001;
char arr [MAX];

int main () {

    int testcase;

    scanf ("%d", &testcase);
    

    while (testcase) {

        scanf ("%s", arr);
        int i = 0, length = 0, vovel = 0 ;
        for (i = 4; arr[i]; i++) {

               switch (arr[i]) {
               case 'a':
               case 'e':
               case 'i':
               case 'o':
               case 'u':
                   vovel++;
                   break;
               default: lenght++;

               }
        }

        printf ("%d/%d", length, (lengh + vovel + 4) )
        testcase --;
    }

}
