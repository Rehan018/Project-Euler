
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
// less: it is the basic for comparison of two function. Use less_equal for ordered multiset.
// order_of_key(k): Number of items strictly smaller than k
// find_by_order(k): kth element in a set (counting from zero) 
const int N = 1e5+2;
#define int long long
/* ----------------------------  Code Start Here ------------------------------ */


void run(){
    int n;
    cin>>n;

    int sum1 = (n * (n + 1) * (2*n + 1)) / 6;
    int sum2 = (n*(n+1))/2;
    sum2*=sum2;

    cout<<abs(sum1-sum2);
}

/* ----------------------------  Code End Here ---------------------------------*/

int32_t main(){
   FASTIO;
   const clock_t begin_time = clock();
   ll t=1;
   cin>>t;
   while(t--){
      run();
      nextline;
   }
   //timeTaken;
   return 0;
}
