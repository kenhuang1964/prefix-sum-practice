#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
ll N;
int max_group = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    cin >> N;
    vector<int>P(N+1, 0);
    for (int i = 1; i <= N; i++){
        int num; cin >> num;
        //i.e. 17-8 = 17%7 - 8%7 = 3-1
        //so if (y-x)%7 = 0 then we know it has to be divisible
        // y%7 = x%7
        //that means we are looking for the same modulo
        //we have to maximize the range of the same modulo to get the largest group
        P[i] = (P[i-1]+num)%7;
    }
    map<int,int>earliestMod; //{number, index}
    for (int i = 1; i <= N; i++){
        if (earliestMod[P[i]] == 0){
            earliestMod[P[i]] = i;
        }
        else{
            max_group = max(max_group, i - earliestMod[P[i]]);
        }
    }
    cout << max_group;
    return 0;
}
