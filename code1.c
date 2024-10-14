#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static char months[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"}; // a global variable for all the months

// prints the matrix sales in line with the matrix months
void monthly_sales(float sales[12]) {
    printf("Monthly Sales Report for 2024:\n\nMonth\t\tSales\n");

    for (int i = 0; i < 12; i++) {
        if (strlen(months[i]) < 8) printf("%s\t\t%.2f\n", months[i], sales[i]);
        else printf("%s\t%.2f\n", months[i], sales[i]);
    }
    printf("\n");
}

// Calculates the sales summary and prints the summary
void sales_summary_report(float sales[12]) {
    int min = 0;
    int max = 0;
    float average = 0;

    printf("Sales Summary Report: \n\n");

    for (int i = 0; i < 12; i++) {
        if (sales[min] > sales[i]) {
            min = i;
        }
        if (sales[max] < sales[i]) {
            max = i;
        }
        average += sales[i];
    }
    average /= 12;

    printf("Minimum Sales:\t%.2f\nMaximum Sales:\t%.2f\nAverage Sales:\t%.2f\n\n", sales[min], sales[max], average);
}

// Calculates the six month moving average report and prints it
void six_month_moving_average_report(float sales[12]) {
    float average;
    printf("Six Month Moving Average Report:\n\n");

    for (int i = 0; i < 7; i++) {
        average = 0;

        for (int j = 0; j < 6; j++) {
            average += sales[j + i];
        }

        printf("%s-%s\t%.2f\n", months[i], months[i + 5], average / 6);
    }
}

// Calculates the sales report and prints it
void sales_report(float sales[12]) {
    // New arrays so the original aren't destroyed
    float sorted_sales[12];
    char sorted_months[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    printf("Sales Report (Highest to Lowest): \n\n");

    // Copying the sales array
    for (int i = 0; i < 12; i++) {
        sorted_sales[i] = sales[i];
    }

    // comparing values to find the maximum and setting the values equal to the sorted arrays
    for (int i = 0; i < 11; i++) {
        for (int j = i + 1; j < 12; j++) {
            if (sorted_sales[j] > sorted_sales[i]) {

                float temp = sorted_sales[i];
                sorted_sales[i] = sorted_sales[j];
                sorted_sales[j] = temp;

                char temp_s[10];
                strcpy(temp_s, sorted_months[i]);

                strcpy(sorted_months[i], sorted_months[j]);
                strcpy(sorted_months[j], temp_s);
            }
        }
    }

    // printing the arrays
    for (int i = 0; i < 12; i++) {
        if (strlen(sorted_months[i]) < 8) {
            printf("%s\t\t%.2f\n", sorted_months[i], sorted_sales[i]);
        } else {
            printf("%s\t%.2f\n", sorted_months[i], sorted_sales[i]);
        }
    }
    printf("\n");
}

int main() {
    FILE *fp;
    int i = 0;
    char line[40]; // Buffer to store each line
    float sales[12];

    // Open the file in read mode
    fp = fopen("data.txt", "r");

    // Check if the file was opened successfully
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read and print each line from the file
    while (fgets(line, sizeof(line), fp) != NULL) {
        sales[i] = strtof(line, NULL);
        i++;
    }

    // Close the file
    fclose(fp);

    monthly_sales(sales);

    sales_summary_report(sales);

    six_month_moving_average_report(sales);
    
    sales_report(sales);

    return 0;
}