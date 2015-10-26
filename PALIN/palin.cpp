#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

char gMyNum[1000002];


int main() {
    int t,i, flag;
    scanf("%d\n",&t);

    for(i=0; i<t; i++) {
        gets(gMyNum);
        int len,i,tmp,t,tmp1;
        len = strlen(gMyNum); 
        flag = 1;
        for(i=0; i<len; i++) {
            if(gMyNum[i] != '9') {
            flag = 0;
            break;
            }
        }

        if(flag == 1) {
            gMyNum[0] = '1';
            for(i=1; i<len; i++)
                 gMyNum[i] = '0';

            gMyNum[len] = '1';
            gMyNum[len+1] = '\0';
        goto tada ;
    }

    flag = 0;
    for(i=0; i<len/2; i++) {
        if(gMyNum[i] < gMyNum[len-i-1]) flag = -1; else if(gMyNum[i] > gMyNum[len-i-1]) flag = 1;
        gMyNum[len-i-1] = gMyNum[i];
    }

    if(flag == -1 || flag==0) {
        t = 0;
        if(len%2 == 0) tmp1 = len/2-1; else tmp1 = len/2;

        while(gMyNum[tmp1-t] == '9') {
            gMyNum[tmp1-t] = '0';
            gMyNum[len-1-tmp1+t] = '0';
            t ++;
        }

        gMyNum[tmp1-t] ++;

        gMyNum[len-1-tmp1+t] = gMyNum[tmp1-t];
    }

    tada:
    printf("%s\n",gMyNum);
    }
    return 0;
} 


