#include <stdio.h>
#include <limits.h>

int main() {
    printf("char\n");
    printf("Size: %lu\n", sizeof(char));
    printf("Range: (%d, %d)\n", CHAR_MIN, CHAR_MAX);
    printf("\n");

    printf("unsigned char\n");
    printf("Size: %lu\n", sizeof(unsigned char));
    printf("Range: (%d, %d)\n", 0, UCHAR_MAX);
    printf("\n");

    printf("short\n");
    printf("Size: %lu\n", sizeof(short));
    printf("Range: (%d, %d)\n", SHRT_MIN, SHRT_MAX);
    printf("\n");

    printf("unsigned short\n");
    // printf("Size: %lu\n", sizeof(short unsigned int));
    printf("Size: %lu\n", sizeof(unsigned short));
    printf("Range: (%d, %u)\n", 0, USHRT_MAX);
    printf("\n");

    printf("int\n");
    printf("Size: %lu\n", sizeof(int));
    printf("Range: (%d, %d)\n", INT_MIN, INT_MAX);
    printf("\n");

    printf("unsigned int\n");
    printf("Size: %lu\n", sizeof(unsigned int));
    printf("Range: (%d, %u)\n", 0, UINT_MAX);
    printf("\n");

    printf("long\n");
    printf("Size: %lu\n", sizeof(long));
    printf("Range: (%ld, %ld)\n", LONG_MIN, LONG_MAX);
    printf("\n");

    printf("unsigned long\n");
    // printf("Size: %lu\n", sizeof(short unsigned int));
    printf("Size: %lu\n", sizeof(unsigned long));
    printf("Range: (%d, %lu)\n", 0, ULONG_MAX);
    printf("\n");

    printf("long long\n");
    printf("Size: %lu\n", sizeof(long long));
    printf("Range: (%lld, %lld)\n", LLONG_MIN, LLONG_MAX);
    printf("\n");

    printf("unsigned long long\n");
    // printf("Size: %lu\n", sizeof(short unsigned int));
    printf("Size: %lu\n", sizeof(unsigned long long));
    printf("Range: (%d, %llu)\n", 0, ULLONG_MAX);
    printf("\n");

    printf("float\n");
    printf("Size: %lu\n", sizeof(float));
    // printf("Range: (%d, %d)\n", INT_MIN, INT_MAX);
    printf("\n");

    printf("double\n");
    printf("Size: %lu\n", sizeof(double));
    // printf("Range: (%ld, %ld)\n", LONG_MIN, LONG_MAX);
    printf("\n");

    printf("long double\n");
    // printf("Size: %lu\n", sizeof(short unsigned int));
    printf("Size: %lu\n", sizeof(long double));
    // printf("Range: (%d, %lu)\n", 0, ULONG_MAX);
    printf("\n");

    return 0;
}