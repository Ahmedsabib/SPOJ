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

const int MAX = 1e5+5;

int is_prime[MAX];
vector<long long> primes;

void sieve(){

	for (int i = 2; i < MAX; i++) {
	    if (!is_prime[i]) {
	    	primes.push_back((long long)1*i*i);
	        for (int j = i + i; j < MAX; j += i)
	            is_prime[j] = 1;
	    }
	}
}

void run_case(){

	long long N, K; cin >> N >> K;
	int total = (int)(upper_bound(primes.begin(), primes.end(), N) - primes.begin());
	int good = total - (int)(upper_bound(primes.begin(), primes.end(), K) - primes.begin());
	if(good < 0) good = 0;
	cout << total << ' ' << good << '\n';

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
