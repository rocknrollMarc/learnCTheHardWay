#include <stdio.h>


 char fullName[] = {'Z', 'E', 'D',
                            'A',
                    'S','H', 'A', 'W',
    };

int main(int argc, const char *argv[])
{
    char fullName[] = {'Z', 'E', 'D',
                            'A',
                    'S','H', 'A', 'W','\0'
    };

    int areas[]= {10, 12, 13, 14, 20};
    char name[] = "Zed";

    printf("The size of an int:%ld\n", sizeof(int));
    printf("The size of areas (int[]): %ld\n", sizeof(areas));
    printf("The number of ints in areas: (int[]):%ld\n", sizeof(areas) / sizeof(int) );
    printf("The first area is %d, the second is %d.", areas[0], areas[1]);
    printf("The size of a char:   %ld\n", sizeof(char));
    printf("The size of name (char[]): %ld\n", sizeof(name));
    printf("The number of chars: %ld\n", sizeof(name)/sizeof(char));
    printf("The size of fullName (char[]): %ld\n", sizeof(fullName));
    printf("The number of chars: %ld\n",sizeof(fullName)/sizeof(char));
    printf("name=\"%s\" and fullName=\"%s\"\n",name, fullName);

    return 0;
}
