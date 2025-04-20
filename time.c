#include "time.h"

/* Function that prints the difference between two times */
void print_time_difference(time t1, time t2) {
    time diff = diff_time(t1, t2);
    
    /* Print the first time */
    printf("Time 1: %d-%d-%d %d:%d:%d\n",
           t1.year, t1.month, t1.day, t1.hour, t1.minute, t1.second);

    /* Print the second time */
    printf("Time 2: %d-%d-%d %d:%d:%d\n",
           t2.year, t2.month, t2.day, t2.hour, t2.minute, t2.second);

    /* Print the difference between the two times */
    printf("Difference: %d years, %d months, %d days, %d hours, %d minutes, %d seconds\n\n",
           diff.year, diff.month, diff.day, diff.hour, diff.minute, diff.second);
}

int main(int argc, char *argv[]) {
    /* Check if the correct number of arguments are passed */
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    /* Open the file for reading */
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    time t1, t2;
    /* Read each line from the file, each line contains 12 values for two times */
    while (fscanf(file, "%d %d %d %d %d %d %d %d %d %d %d %d",
                  &t1.year, &t1.month, &t1.day, &t1.hour, &t1.minute, &t1.second,
                  &t2.year, &t2.month, &t2.day, &t2.hour, &t2.minute, &t2.second) == 12) {

        /* Calculate and print the difference between the two times */
        print_time_difference(t1, t2);
    }

    /* Close the file after processing */
    fclose(file);
    return 0;
}

