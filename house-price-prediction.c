#include <stdio.h>

float mean(float arr[], int n) {
    float sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];
    return sum / n;
}
int main() {
    int n;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    float X[n], Y[n];

    printf("Enter square footage (X) and price (Y):\n");
    for(int i = 0; i < n; i++) {
        printf("Data point %d (format: X Y): ", i+1);
        scanf("%f %f", &X[i], &Y[i]);
    }

    float x_mean = mean(X, n);
    float y_mean = mean(Y, n);

    float num = 0, den = 0;
    for(int i = 0; i < n; i++) {
        num += (X[i] - x_mean) * (Y[i] - y_mean);
        den += (X[i] - x_mean) * (X[i] - x_mean);
    }

    float b1 = num / den;
    float b0 = y_mean - b1 * x_mean;

    printf("\nLinear Regression Model: Y = %.2f + %.2fX\n", b0, b1);

    float new_x;
    printf("Enter square footage to predict price: ");
    scanf("%f", &new_x);

    float predicted_y = b0 + b1 * new_x;
    printf("Predicted Price: %.2f\n", predicted_y);

    return 0;
}
