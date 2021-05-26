#include <bits/stdc++.h>

const int MOD = 1e9+7;

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
    
    int T; cin >> T;
    while(T--){
        
        int64_t N; cin >> N;
        if(N < 3){
            cout << N << '\n';
        } else{
            int64_t ans = 0, x;
            if(N%3 == 1){
                x = (N-4)/3;
                ans = 4*binpow(3, x, MOD);
            } else if(N%3 == 2){
                x = (N-2)/3;
                ans = 2*binpow(3, x, MOD);
            } else{
                ans = binpow(3, N/3, MOD);
            }
            ans %= MOD;
            cout << ans << '\n';
        }
    }
    
    return 0;
}
