#include <bits/stdc++.h>

int64_t gcd (int64_t a, int64_t b) {
    return b ? gcd (b, a % b) : a;
}

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int T; cin >> T;
    for(int test_cases = 1; test_cases <= T; ++test_cases){
        
        int64_t a, b, c; cin >> a >> b >> c;
        int64_t g = gcd(a, b);
        cout << "Case " << test_cases << ": ";
        cout << (c%g == 0? "Yes":"No") << '\n';

    }
    
    return 0;
}
