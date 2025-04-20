#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Define time struct */
typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} time;

/* Function to calculate days in a given month */
int days_in_month(int month, int year);

/* Function to convert time to seconds since 01/01/0000 00:00:00 */
int to_seconds(time t);

/* Function to calculate the difference between two times */
time diff_time(time t1, time t2);

