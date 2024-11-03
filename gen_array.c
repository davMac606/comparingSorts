#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("INSUFICIENTE.\n");
        exit(1);
    }

    int count = strtol(argv[1], NULL, 10);

    srand(time(NULL));

    printf("%d\n", count);

    for (int i = 0; i < count; i++) {
        printf("%d\n", rand());
    }

    return 0;
}
