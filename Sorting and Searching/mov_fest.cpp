#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int,int>> vp(n);
	for(int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		vp[i] = {x, y};
	}
	sort(vp.begin(), vp.end(), [&](pair<int,int> p1, pair<int,int> p2) {
		return p1.second < p2.second;
	});
	int ans = 1;
	int curr_end = vp[0].second;
	for(int i = 1; i < n; ++i) {
		if(vp[i].first >= curr_end) {
			curr_end = vp[i].second;
			ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}
