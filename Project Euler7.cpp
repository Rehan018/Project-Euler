
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); 
#define ll long long
#define ull unsigned long long
#define endl "\n"
#define INF INT_MAX
#define NINF INT_MIN
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(a) ((int)((a).size()))
#define char unsigned char
#define debug(x) cout<<#x<<"-->"<<x<<endl
#define print(x) cout<<x<<endl
#define printc(x) cout<<x<<" "
#define foreach(arr) for(auto &e : arr) cout<<e<<" "
#define nextline cout<<"\n"
#define MOD 1000000007
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define timeTaken std::cout <<"\nTime: "<< float( clock () - begin_time ) /  CLOCKS_PER_SEC
using namespace std;
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int N = 1e5+2;
#define int long long
#define maxN 10000000

/* ----------------------------  Code Start Here ------------------------------ */

vector<int> primes;
void sieve(int n){
    vector<bool> isPrime(n + 1, true);
    for (int p = 2; p * p <= n; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    for (int p = 2; p <= n; ++p) {
        if (isPrime[p]) {
            primes.push_back(p);
        }
    }
}

void run(){
    int n;
    cin>>n;

    cout<<primes[n-1];
}

/* ----------------------------  Code End Here ---------------------------------*/

int32_t main(){
   FASTIO;
   const clock_t begin_time = clock();
   
   ll t=1;
   cin>>t;
   sieve(110000);
   while(t--){
      run();
      nextline;
   }
   //timeTaken;
   return 0;
}
