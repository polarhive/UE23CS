#include <stdio.h>

// declaration on enum
enum textEditor {
    BOLD = 1,
    ITALIC = 2,
    UNDERLINE = 3
};

int main(void) 
{
    // Initializing enum variable
    enum textEditor feature = ITALIC;

    switch (feature) 
    {
    case 1:
        printf("It is BOLD");
        break;

    case 2:
        printf("It is ITALIC");
        break;

    case 3:
        printf("It is UNDERLINE");
    }

    return 0;
}
