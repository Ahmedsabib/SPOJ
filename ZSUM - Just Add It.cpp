#include <bits/stdc++.h>

const int MOD = 1e7+7;

int64_t binpow(int64_t a, int64_t b, int64_t m){

    a %= m;
    int64_t res = 1;
    while(b > 0){
        if(b&1){
            res = res * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int64_t N, M;
    while(cin >> N >> M){

        if(!N && !M) return 0;
        int64_t a = binpow(N, M, MOD);
        int64_t b = binpow(N, N, MOD);
        int64_t c = 2*binpow(N-1, N-1, MOD);
        int64_t d = 2*binpow(N-1, M, MOD);
        int64_t e = a+b+c+d;
        int64_t ans = binpow(e, 1, MOD);
        cout << ans << '\n';
    }
    
    return 0;
}
