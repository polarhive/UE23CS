#include <stdio.h>
#include "atomic.h"

int main()
{

    atomic_t counter;
    int value;

    atomic_set(&counter,5); /* counter = 5 */

    atomic_add(10, &counter); /* counter = counter + 10 */

    atomic_sub(4, &counter); /* counter = counter - 4 */

    atomic_inc(&counter); /* counter = counter + 1 */

    value = atomic_read(&counter); /* value = 12 */

    printf("Value = %d\n", value);
}

