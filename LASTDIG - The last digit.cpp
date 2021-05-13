#include <bits/stdc++.h>

int64_t power(int64_t a, int64_t b, int64_t mod){
        int64_t res = 1;
        while (b > 0)
        {
            if (b & 1)
                res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
}

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int T; cin >> T;
    while(T--){
        
        int N, M; cin >> N >> M;
        cout << power(N, M, 10) << '\n';
    }
    
    return 0;
}
