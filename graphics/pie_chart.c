#include <stdio.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265
#define RADIUS 10

void print_pie_chart(int num_slices, int values[], char *labels[]) {
    int total = 0;
    for (int i = 0; i < num_slices; i++) {
        total += values[i];
    }

    char chart[RADIUS * 2 + 1][RADIUS * 2 + 1];
    memset(chart, ' ', sizeof(chart));

    double current_angle = 0;
    for (int i = 0; i < num_slices; i++) {
        double slice_angle = 2 * PI * values[i] / total;
        double end_angle = current_angle + slice_angle;

        for (double angle = current_angle; angle < end_angle; angle += 0.1) {
            int x = RADIUS + (int)(RADIUS * cos(angle));
            int y = RADIUS + (int)(RADIUS * sin(angle));
            chart[y][x] = 'A' + i;
        }

        current_angle = end_angle;
    }

    // Print the chart
    for (int i = 0; i < RADIUS * 2 + 1; i++) {
        for (int j = 0; j < RADIUS * 2 + 1; j++) {
            putchar(chart[i][j]);
        }
        putchar('\n');
    }

    // Print legend
    printf("\nLegend:\n");
    for (int i = 0; i < num_slices; i++) {
        printf("%c: %s (%d%%)\n", 'A' + i, labels[i], (values[i] * 100) / total);
    }
}

// Example usage
int main() {
    int values[] = {30, 50, 20};
    char *labels[] = {"Option A", "Option B", "Option C"};
    int num_slices = sizeof(values) / sizeof(values[0]);

    print_pie_chart(num_slices, values, labels);
    return 0;
}