#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <string.h>


/*our old friend die() from before*/
void die(const char *message)
{
    if(errno) {
        perror(message);

    } else {

        printf("Error: %s\n", message);
    }

    exit(1);
}

/* a typedef creates a fake type, int this
 *case for a function pointer */

int typedef (*compare_cb) (int a, int b);

/**
 * A classic bubble sort function that uses
 * compare_cb to do the sorting
 */

int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
    int temp = 0;
    int i = 0;
    int j = 0;
    int *target = malloc(count *sizeof(int));

   if(!target) die("Memory Error.");

   memcpy(target, numbers, count * sizeof(int));

   for (i = 0; i < count; i++) {
       for (j = 0; j < count -1; j++) {
           if(cmp(target[j], target[j+1]) > 0){
               temp = target[j+1];
               target[j] = temp;
           }
       }
   }

   return target;
}

int sorted_order(int a, int b)
{
    return a - b;
}

int reverse_order(int a, int b)
{
    return b - a;
}

int strange_order(int a, int b)
{
    if (a == 0 || b == 0) {
        return 0;

    } else {

        return a % b;
    }
}

/**
 * Used to test that we are sorting things correctly
 * by doing the sort and printing things out.
 */

void test_sorting(int *numbers, int count, compare_cb cmp)
{
    int i = 0;
    int *sorted = bubble_sort(numbers, count, cmp);

    if(!sorted) die("Failed to sort as requested.");

    for(i = 0; i < count; i++) {
        printf("%d", sorted[i]);
    }
    printf("\n");

    free(sorted);
}

int main(int argc, const char *argv[])
{
    if(argc < 2) die("Usage: ex18 4 3 1 5 6");

    int count = argc -1;
    int i = 0;
    char **inputs = argv + 1;

    int *numbers = malloc(count * sizeof(int));
    if(!numbers) die("Memory Error.");

    for(i = 0; i < count; i++) {
        numbers[i] = atoi(inputs[i]);
    }

    test_sorting(numbers, count, sorted_order);
    test_sorting(numbers, count, reverse_order);
    test_sorting(numbers, count, strange_order);

    free(numbers);

    return 0;
}


