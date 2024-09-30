#include <iostream>
using namespace std;

void bubbleSort(float a[3][100], int row, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[row][j] < a[row][j + 1]) {  // Sort by value/weight ratio in descending order
                for (int k = 0; k < 3; k++) { // Swap the entire row
                    float temp = a[k][j];
                    a[k][j] = a[k][j + 1];
                    a[k][j + 1] = temp;
                }
            }
        }
    }
}

float GreedyKnapsack(int n, float a[3][100], float knapsackCap) {
    float tp = 0.0;  // Total profit
    float x[100] = {0};  // Fraction of items taken
    bubbleSort(a, 2, n); // Sort items by value/weight ratio

    float remainingCap = knapsackCap;

    for (int i = 0; i < n; i++) {
        if (a[0][i] <= remainingCap) {  
            x[i] = 1.0; 
            remainingCap -= a[0][i]; 
            tp += a[1][i];  
        } else {  
            x[i] = remainingCap / a[0][i];  
            tp += x[i] * a[1][i];  
            break;  
        }
    }

    return tp;
}

int main() {


    int n;
    float knapsackCap;
    float a[3][100];  // [0]: weights, [1]: values, [2]: value/weight ratio

    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the capacity of the knapsack: ";
    cin >> knapsackCap;

    for (int i = 0; i < n; i++) {
        cout << "Enter weight and value for item " << i + 1 << ": ";
        cin >> a[0][i] >> a[1][i];
        a[2][i] = a[1][i] / a[0][i];  // Calculate value/weight ratio
    }

    float totalProfit = GreedyKnapsack(n, a, knapsackCap);
    cout << "Maximum profit: " << totalProfit << endl;

    return 0;
}