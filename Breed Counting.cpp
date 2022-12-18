#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
#define pb push_back

int N, Q;


int main() {
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    cin >> N >> Q;
    //vector with N+1 rows and 3 columns set to 0
    vector<vector<int>>prefix(N+1, vector<int>(3, 0));
    for (int i = 1; i <= N; i++){
        int id; cin >> id;
        prefix[i][0] = prefix[i-1][0] + (id == 1);
        prefix[i][1] = prefix[i-1][1] + (id == 2);
        prefix[i][2] = prefix[i-1][2] + (id == 3);
    }
    for (int i = 0; i < Q; i++){
        int a, b; cin >> a >> b;
        int prefH = prefix[b][0] - prefix[a-1][0];
        int prefG = prefix[b][1] - prefix[a-1][1];
        int prefJ = prefix[b][2] - prefix[a-1][2];
        cout << prefH << " " << prefG << " " << prefJ << endl;
    }
}