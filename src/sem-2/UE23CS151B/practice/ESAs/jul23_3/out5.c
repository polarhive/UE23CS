#include <stdio.h>
int main() {
    printf("Time: %s\n", __TIME__);
    printf("STDC Version: %ld\n", __STDC_VERSION__);
    printf("STDC Compliant?: %d\n", __STDC__);
    printf("Current Line: %d\n", __LINE__);
}
