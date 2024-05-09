#include <stdio.h>
long convertBinary(int);
int main()
{
    long biNo;
    int decNo;
    scanf("%d", &decNo);
    biNo = convertBinary(decNo); // call the function convertBinary
    printf("%ld", biNo);
    return 0;
}
long convertBinary(int decNo)
{
    static long biNo, r, fctor = 1;
    if (decNo != 0)
    {
        r = decNo % 2;
        biNo = biNo + r * fctor;
        fctor = fctor * 10;
        convertBinary(decNo / 2); // calling the function convertBinary itself recursively
    }
    return biNo;
}