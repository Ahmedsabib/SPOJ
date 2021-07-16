#include <bits/stdc++.h>

int cnt[500005];

void precalculate() {
    for (int i = 1; i < 500005; ++i) {
        for (int j = i; j < 500005; j += i) {
            cnt[j] += i;
        }
    }
}

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    precalculate();
    int T; cin >> T;
    while(T--){
        
        int64_t N; cin >> N;
        cout << cnt[N]-N << '\n';
    }
    
    return 0;
}
