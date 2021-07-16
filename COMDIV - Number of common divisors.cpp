#include <bits/stdc++.h>

int cnt[1000006];

int64_t gcd (int64_t a, int64_t b) {
    return b ? gcd (b, a % b) : a;
}

void precalculate() {
    for (int i = 1; i < 1000006; ++i) {
        for (int j = i; j < 1000006; j += i) {
            cnt[j]++;
        }
    }
}

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    precalculate();
    int T; cin >> T;
    while(T--){
        
        int64_t a, b; cin >> a >> b;
        cout << cnt[gcd(a,b)] << '\n';
    }
    
    return 0;
}
