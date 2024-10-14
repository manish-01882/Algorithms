#include <iostream>
using namespace std;
int knapsack(int W, int weights[], int values[], int n) {
  int dp[n + 1][W + 1];
  for (int i = 0; i <= n; i++) {
    for (int w = 0; w <= W; w++) {
      if (i == 0 || w == 0) {
        dp[i][w] = 0;
      } else if (weights[i - 1] <= w) {
        dp[i][w] =
            max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
      } else {
        dp[i][w] = dp[i - 1][w];
      }
    }
  }
  return dp[n][W];
}

int main() {
  int n, W;
  cout << "Enter the number of items: ";
  cin >> n;
  cout << "Enter the capacity of the knapsack: ";
  cin >> W;
  int weights[n], values[n];
  for (int i = 0; i < n; i++) {
    cout << "Enter weight and value of item " << i + 1 << ": ";
    cin >> weights[i] >> values[i];
  }
  cout << "Maximum value in the knapsack = " << knapsack(W, weights, values, n)
       << endl;
  cout <<"Jaspreet Singh\nURN: 2203473\n";
  return 0;
}