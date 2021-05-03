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

const int MAX = 10000025;

int prime[MAX], square[MAX], sum[MAX];

void run_case(){

	for(int i = 2; i < MAX; ++i){
		if(!prime[i]){
			for(int j = i+i; j < MAX; j += i){
				prime[j] = 1;
			}
		}
	}
	for(int i = 1; i*i < MAX; ++i){
		square[i*i] = 1;
	}
	for(int i = 1; i < MAX; ++i){
		sum[i] = sum[i-1];
		if(prime[i]){
			continue;
		}
		for(int j = 1; j*j*j*j <= i; ++j){
			if(square[i - j*j*j*j]){
				sum[i]++;
				break;
			}
		}
	}
	int T; cin >> T;
	while(T--){
		int N; cin >> N;
		cout << sum[N] << '\n';
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();

    return 0;
}
