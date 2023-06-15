#include<bits/stdc++.h>

/*
 * dp[i] = minimum number of coins used to get sum i
 * dp[i] = min(dp[i - j]) for all 0<=j<=c and i >= j
 * dp[0] = 1
*/ 

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	const int inf = 1e9 + 5;
	int n, x;
	cin >> n >> x;
	vector<int> c(n);
	for(int i = 0; i < n; ++i) {
		cin >> c[i];
	}
	vector<int> dp(x + 1);
	dp[0] = 0;
	for(int i = 1; i <= x; ++i) {
		dp[i] = inf;
		for(int j: c) {
			if(i >= j) {
				dp[i] = min(dp[i], dp[i - j] + 1);
			}
		}
	}
	cout << (dp[x] == inf ? -1 : dp[x]);
	return 0;
}
