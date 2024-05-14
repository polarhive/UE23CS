#include <stdio.h>

void callback(int result) {
    printf("Result: %d\n", result);
}

void add(int x, int y, void (*callback)(int)) {
    int result = x + y;
    callback(result);
}

int main() {
	add(3, 5, callback);
	return 0;
}
