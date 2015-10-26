 #include <stdio.h>
    #include <stdlib.h>

void read_file(FILE *fileptr)
    {
        char currentchar = '\0';
        int size = 0;

        while( currentchar != '\n' )
        {
            currentchar = fgetc(fileptr); printf("%c\n", currentchar);
            fseek(fileptr, -2, SEEK_CUR);
            if( currentchar == '\n') { fseek(fileptr, -2, SEEK_CUR); break; }
            else size++;

        }
        char buffer[size]; fread(buffer, 1, size, fileptr);
        printf("Length: %d chars\n", size);
        printf("Buffer: %s\n", buffer);


    }


int main()
{
    FILE *fileptr = fopen("a.out", "rb");
    fseek(fileptr, -1, SEEK_END); /* Seek to END of the file just before EOF */
    read_file(fileptr);
    return 0;

}

