#include <bits/stdc++.h>
 
int main() {
  using namespace std;
  ios::sync_with_stdio(false); cin.tie(nullptr);
 
  long long N = 1e8;
  vector<int>primes;
  vector<char> is_prime(N+1, true);
  is_prime[0] = is_prime[1] = false;
  for(int i = 2; i*i <= N; ++i){
   if(is_prime[i]){
    for(int j = i*i; j <= N; j += i){
     is_prime[j] = false;
    }
   }
  }
  for(int i = 2; i <= N; ++i){
   if(is_prime[i]) primes.push_back(i);
  }
  for(int i = 1; i < primes.size(); i += 100) cout << primes[i-1] << '\n';
  return 0;
} 
