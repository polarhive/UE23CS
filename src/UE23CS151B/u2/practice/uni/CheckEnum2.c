#include <stdio.h>

#include <stdio.h>

// declaration on enum
enum textEditor {
    BOLD = 5,
    ITALIC = 9,
    UNDERLINE
};

int main(void) 
{
    // Initializing enum variable
    enum textEditor feature = ITALIC;
    printf("Selected feature is %d\n", feature);

    feature = UNDERLINE;
    printf("Selected feature is %d\n", feature);
    
    return 0;
}

