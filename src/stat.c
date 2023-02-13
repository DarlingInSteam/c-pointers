#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 1) {
        printf("n/a");
        return 1;
    } else {
        output(data, n);
        output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
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

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d", *p);

        if (n - 1 > p - a) {
            printf(" ");
        }
    }
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("\n%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
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