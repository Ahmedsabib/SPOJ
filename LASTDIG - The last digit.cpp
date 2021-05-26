#include <bits/stdc++.h>

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
        
        int64_t a, b; cin >> a >> b;
        int64_t x = binpow(a, b, 10);
        printf("%01d\n", x);
    }
    
    return 0;
}
