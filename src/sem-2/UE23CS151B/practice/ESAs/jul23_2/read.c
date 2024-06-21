#include <stdio.h>

int main()
{
    FILE *file;
    int c;
    long int count = 0;

    file = fopen("sample.txt", "r");
    if (file == NULL)
    {
        printf("Failed to open the file.\n");
        return 1;
    }

    // read char by char
    while ((c = fgetc(file)) != EOF)
    {
        ++count;
    }

    fclose(file);
    printf("Number of characters in the file: %ld\n", count - 1); // dont count the EoF
}
