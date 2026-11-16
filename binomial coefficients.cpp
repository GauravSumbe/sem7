
#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, k;
    cout << "Enter n and k: ";
    cin >> n >> k;

    int dp[n+1][k+1];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=min(i,k); j++){

            if(j == 0 || j == i){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        }
    }

    cout << "Binomial Coefficient: " << dp[n][k];

    return 0;
}

// Explanation: Binomial Coefficient using Dynamic Programming
// 1. Binomial coefficient is used to calculate the number of ways to select k elements from n elements.

// 2. It is represented as \(C(n,k)\) and calculated using the following recurrence relation:
// \[
// C(n,k)=C(n-1,k-1)+C(n-1,k)
// \]

// 3. We use a 2D DP table to store previously calculated results and avoid repeated calculations.

// 4. The base conditions are:
// - \(C(n,0)=1\)
// - \(C(n,n)=1\)
// 5. Finally, the value stored in dp[n][k] gives the required binomial coefficient.

// Complexity:
// - Time Complexity: \(O(n \times k)\)
// - Space Complexity: \(O(n \times k)\)
