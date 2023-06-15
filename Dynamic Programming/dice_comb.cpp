#include<bits/stdc++.h>

/*
 * let dp[i] = Number of ways to create a sum using 6 numbers [1, 2, ...6]
 * dp[i] = dp[i - j] + 1 where 1<=x<=6 and i >= j
 * dp[0] = 1
*/ 

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	const int m = 1e9 + 7;
	int n;
	cin >> n;
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	for(int i = 1; i<= n; ++i) {
		for(int j: {1, 2, 3, 4, 5, 6}) {
			if(i >= j) {
				(dp[i] += dp[i -j]) %= m;
			}
		}
	}
	cout << dp[n];
	
	return 0;
}
