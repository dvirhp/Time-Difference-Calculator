#include "time.h"

/* Function that calculates the number of days in a given month */
int days_in_month(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                return 29; /* Leap year */
            } else {
                return 28;
            }
        default:
            return 0; /* Invalid month */
    }
}

/* Function that converts the time to seconds since 01/01/0000 00:00:00 */
int to_seconds(time t) {
    int days = 0;
    int seconds = 0;
    int i = 0;

    /* Adding days from full years (including leap years if applicable) */
    for (i = 0; i < abs(t.year); i++) {
        if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
            days += 366;
        } else {
            days += 365;
        }
    }

    /* Adjusting for negative years (before common era) */
    if (t.year < 0) {
        days = -days;
    }

    /* Adding days from complete months in the current year */
    for (i = 1; i < t.month; i++) {
        days += days_in_month(i, t.year);
    }

    /* Adding days from the current month */
    days += t.day - 1;

    /* Converting to seconds */
    seconds = days * 86400;
    seconds += t.hour * 3600;
    seconds += t.minute * 60;
    seconds += t.second;

    return seconds;
}

/* Function that calculates the difference between two times */
time diff_time(time t1, time t2) {
    int prev_month_days = 0;
    time diff;  

    /* Identifying the earlier time */
    if (to_seconds(t1) < to_seconds(t2)) {
        time temp = t1;
        t1 = t2;
        t2 = temp;
    }

    /* Calculating the difference in years */
    diff.year = t1.year - t2.year;

    /* Handling months */
    if (t1.month < t2.month) {
        diff.year--;  /* If t1 is later in months, adjust the year */
        diff.month = 12 - (t2.month - t1.month);  /* Remaining months */
    } else {
        diff.month = t1.month - t2.month;
    }

    /* Handling days */
    if (t1.day < t2.day) {
        if (diff.month == 0) {
            diff.year--;  /* If no months, subtract a year */
            diff.month = 11;  /* Last month of the year */
        } else {
            diff.month--;  /* Subtract a month */
        }
        prev_month_days = days_in_month((t1.month - 1 == 0) ? 12 : t1.month - 1, t1.year);
        diff.day = prev_month_days + t1.day - t2.day;
    } else {
        diff.day = t1.day - t2.day;
    }

    /* Handling hours */
    if (t1.hour < t2.hour) {
        diff.day--;  /* If the hour in the later time is less, subtract a day */
        diff.hour = 24 - (t2.hour - t1.hour);  /* Remaining hours */
    } else {
        diff.hour = t1.hour - t2.hour;
    }

    /* Handling minutes */
    if (t1.minute < t2.minute) {
        diff.hour--;  /* If the minute in the later time is less, subtract an hour */
        diff.minute = 60 - (t2.minute - t1.minute);  /* Remaining minutes */
    } else {
        diff.minute = t1.minute - t2.minute;
    }

    /* Handling seconds */
    if (t1.second < t2.second) {
        diff.minute--;  /* If the second in the later time is less, subtract a minute */
        diff.second = 60 - (t2.second - t1.second);  /* Remaining seconds */
    } else {
        diff.second = t1.second - t2.second;
    }

    return diff;  
}


