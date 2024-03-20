#include <stdio.h>

enum textEditor {
    BOLD,
    ITALIC,
    UNDERLINE
};
int main(void) 
{
    enum textEditor feature;
    feature = UNDERLINE;
    printf ("%d\n", feature);
    return 0;
}
