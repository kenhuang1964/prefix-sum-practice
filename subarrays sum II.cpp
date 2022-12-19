#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll N, X;
map<ll, ll>need;
ll ans = 0;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> N >> X;
    vector<ll>P(N+1, 0);
    need[X]++;
    for (ll i = 1; i <= N; i++){
        ll num; cin >> num;
        P[i] = P[i-1] + num;
        ans += need[P[i]];
        need[X+P[i]]++;
    }
    cout << ans;
    return 0;
}