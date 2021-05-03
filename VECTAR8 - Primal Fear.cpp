#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
 
template <typename T> T exp(T b, T p){T x = 1; while(p){ if(p & 1) x = (x * b); b = (b * b); p = p >> 1; }return x;}
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int MAX = 1e6+5;

int freq[MAX];
int is_prime[MAX];

void seive(){

    is_prime[0] = is_prime[1] = 1;
    for (int i = 2; i * i <= 1000000; i++) {
    if (!is_prime[i]) {
        for (int j = i * i; j <= 1000000; j += i)
            is_prime[j] = 1;
        }
    }
}

bool okay(long long N){

    long long digit = 0, num = N;
    while(num > 0){
        long long r = num%10;
        if(r == 0) return false;
        ++digit;
        num /= 10;
    }
    long long div = exp((long long)10, digit-1);
    num = N;
    while(num > 0){
        num %= div;
        div /= 10;
        if(num != 0 && is_prime[num]) return false;
    }
    return true;
}

void prefix(){

    for(int i = 2; i <= 1000000; ++i){
        freq[i] = freq[i-1];
        if(!is_prime[i]){
            if(okay(i)){
                freq[i]++;
            }
        }
    }
}

void run_case(){

    seive();
    prefix();
    int tests;
    cin >> tests;
    while(tests-- > 0){
    
        int N; cin >> N;
        cout << freq[N] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();

    return 0;
}
