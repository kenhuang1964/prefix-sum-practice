#include <bits/stdc++.h>
using namespace std;

int N;
int max_ans = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);
	cin >> N;
	vector<vector<int>>P(N+1, vector<int>(3, 0));
	for (int i = 1; i <= N; i++){
		char c; cin >> c;
		if (c == 'P') P[i][0] = P[i-1][0] + 1;
		else P[i][0] = P[i-1][0];
		if (c == 'H') P[i][1] = P[i-1][1] +1;
		else P[i][1] = P[i-1][1];
		if (c == 'S') P[i][2] = P[i-1][2] + 1;
		else P[i][2] = P[i-1][2];
	}
	for (int i = 1; i <= N; i++){
	    int largest_first_half = max({
	        P[i][0] - P[0][0],
	        P[i][1] - P[0][1],
	        P[i][2] - P[0][2]
	    });
	    int largest_second_half = max({
	        P[N][0] - P[i][0],
	        P[N][1] - P[i][1],
	        P[N][2] - P[i][2]
	    });
	    max_ans = max(max_ans, largest_first_half + largest_second_half);
	}
	cout << max_ans;
	return 0;
}
