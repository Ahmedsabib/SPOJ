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
 
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int MAX = 11000005;
const int NEED = 20000000;

int is_prime[MAX];
int primes[NEED+1];
int N = 0;

void sieve(){

	for (int i = 2; i * i < MAX; i ++) {
        if (is_prime[i]) continue;
        for (int j = i * i; j < MAX; j += i) is_prime[j] = i;
    }
    is_prime[1] = 1;
    for (int i = 2; i < MAX && N < NEED; i ++) {
        if (is_prime[i] && is_prime[i] != i / is_prime[i] && !is_prime[is_prime[i]] && !is_prime[i / is_prime[i]]) {
            primes[N ++] = i;
        }
    }
}

void run_case(){

	long long M; cin >> M;
	cout << primes[M-1] << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();
    int tests;
    cin >> tests;
    while(tests-- > 0){

    	run_case();
    }

    return 0;
}
