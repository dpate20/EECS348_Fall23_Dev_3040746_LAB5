#include <stdio.h>
#include <stdlib.h>

void read_sales_rep(float sales[], int n){
	FILE *file;
	file = fopen("salesreport.txt", "r");
	if (file == NULL){
		printf("ERROR: CANNOT ACCESS FILE\n");
		exit(0);
	}
	for (int i=0;i<n;i++){
		fscanf(file, "%f",&sales[i]);
	}
	fclose(file);
 }

void make_sales_report(float sales[], int n) {
    printf("\n----Sales Report: ----\n");
    printf("Month\tSales\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%.2f\n", i + 1, sales[i]);
    }
 }

void make_summary(float sales[], int n) {
    float maximum_sale, minimum_sale, avg_sale, six_month_moving_avg[2];
    maximum_sale = minimum_sale = avg_sale = sales[0];
    for (int i = 0; i < n; i++) {
        minimum_sale = (sales[i] < minimum_sale) ? sales[i] : minimum_sale;
        maximum_sale = (sales[i] > maximum_sale) ? sales[i] : maximum_sale;
        avg_sale += sales[i];
    }
    avg_sale /= n;

    six_month_moving_avg[0] = (sales[0] + sales[1] + sales[2] + sales[3] + sales[4] + sales[5]) / 6;
    six_month_moving_avg[1] = (sales[6] + sales[7] + sales[8] + sales[9] + sales[10] + sales[11]) / 6;

        printf("\nSales Summary:\n");
	printf("Maximum Monthly Sales: $%.2f\n", maximum_sale);
        printf("Minimum Monthly Sales: $%.2f\n",minimum_sale);
	printf("Average Monthly Sale: $%.2f\n", avg_sale);
	printf("6-month moving averages: %.2f, %.2f\n", six_month_moving_avg[0], six_month_moving_avg[1]);
 }

void sales_rank(float sales[], int n) {
    printf("\nMonthly Sales Ranking (From Highest to Lowest):\n");
    printf("Month\tSales\n");
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sales[j] > sales[i]) {
                float temp = sales[i];
                sales[i] = sales[j];
                sales[j] = temp;
            }
        }
        printf("%d\t%.2f\n", i + 1, sales[i]);
    }
}

int main() {
    float sales[12];
    read_sales_rep(sales, 12);
    make_sales_report(sales, 12);
    make_summary(sales, 12);
    sales_rank(sales, 12);
    return 0;
}

