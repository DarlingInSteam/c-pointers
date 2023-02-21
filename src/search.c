/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/

#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
double mean(int *a, int n);
double variance(int *a, int n);
int detected_three_sigms(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 1) {
        printf("n/a");
        return 1;
    } else {
        printf("%d", detected_three_sigms(data, n));
    }

    return 0;
}

int input(int *a, int *n) {
    char ch1;
    if (scanf("%d%c", n, &ch1) != 2 || *n > NMAX || ch1 != '\n' || *n <= 0) {
        return 1;
    }
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", p) != 1) {
            return 1;
        }
    }
    char ch2;
    if (scanf("%c", &ch2) != 1 || ch2 != '\n') {
        return 1;
    }

    return 0;
}

int max(int *a, int n) {
    int max = *a;

    for (int *p = a; p - a < n; p++) {
        if (*p > max) {
            max = *p;
        }
    }

    return max;
}

int min(int *a, int n) {
    int min = *a;

    for (int *p = a; p - a < n; p++) {
        if (*p < min) {
            min = *p;
        }
    }

    return min;
}

double mean(int *a, int n) {
    double mean_value = 0.0;

    for (int *p = a; p - a < n; p++) {
        mean_value += (double)*p / (double)n;
    }

    return mean_value;
}

double variance(int *a, int n) {
    int max_value = max(a, n);
    int min_value = min(a, n);
    int n_value = max_value - min_value + 1;
    return (double)((((double)n_value * (double)n_value) - 1.0) / 12.0);
}

int detected_three_sigms(int *a, int n) {
    double mean_value = mean(a, n);
    double variance_value = variance(a, n);
    int detected_num = 0;
    for (int *p = a; p - a < n; p++) {
        if ((*p % 2 == 0) && (*p >= mean_value) && (*p <= mean_value + 3 * sqrt(variance_value)) &&
            (*p != 0)) {
            detected_num = *p;
            break;
        }
    }

    return detected_num;
}