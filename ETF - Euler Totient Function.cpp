#include <bits/stdc++.h>

//Finding the number of coprimes to n
//Normal way
//Time Complexity O(sqrt(n))
int64_t phi (int64_t n) {
    int64_t result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            result -= result / i;
        }
    }
    if (n > 1) {
        result -= result / n;
    }
    return result;
}

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int T; cin >> T;
    while (T--) {

        int N; cin >> N;
        cout << phi(N) << '\n';
    }
    
    return 0;
}
