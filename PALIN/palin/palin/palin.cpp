#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char gMyNum[1000002];

int main2() {

	int testcase , length, mid, checkdigit = 0, check9 = 1, i, offset = 0;

    scanf ("%d\n",&testcase);

    while (testcase) {
    
        gets (gMyNum);

        length = strlen (gMyNum); 
    
        for (i=0; i<length; i++) {
    
            if (gMyNum[i] != '9') {
    
                check9 = 0;
                break;
            }
        }
    
        if (check9 == 1) {
    
            gMyNum[0] = '1';
    
            for (i=1; i<length; i++) {

                 gMyNum[i] = '0';
            }
    
            gMyNum[length] = '1';
            gMyNum[length+1] = '\0';
    
          
        } else {
        
            for(i=0; i<length/2; i++) {
        
                if(gMyNum[i] < gMyNum[length-i-1]) 
                    checkdigit = -1; 

                else if(gMyNum[i] > gMyNum[length-i-1]) 
                    checkdigit = 1;
        
                gMyNum[length-i-1] = gMyNum[i];
            }   
        
            if(checkdigit == -1 || checkdigit == 0) {
        
               if(length%2 == 0) 
                    mid = length/2-1; 
                else
                    mid = length/2;
        
                while(gMyNum[mid-offset] == '9') {
        
                    gMyNum[mid-offset] = '0';
                    gMyNum[length-1-mid+offset] = '0';
                    offset ++;
                }
        
                gMyNum[mid-offset] ++;
                gMyNum[length-1-mid+offset] = gMyNum[mid-offset];
            }
        }
    
        printf ("%s\n",gMyNum);
    
        --testcase;
    }

    return 0;
} 


