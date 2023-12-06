#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define debug(x) cout << #x << " = " << x << endl
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
inline ll Mod(ll x, ll mod) { return x % mod >= 0 ? x % mod : x % mod + mod; }

vector<ll> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

void find_primes(int n)
{
    for (int i = 51; i <= n; i += 2)
    {
        bool flag = 0;
        for (int j : primes)
        {
            if (j * j > i)
                break;
            if (i % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
            primes.emplace_back(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    primes.reserve(20000);
    find_primes(24000);
    int n;
    cin >> n;
    int ansa = 0, ansb = 0, MAX = 0;
    for (int a = -n; a <= n; a++)
    {
        for (int b = -n; b <= n; b++)
        {
            int cnt = 0;
            while (binary_search(all(primes), cnt * cnt + cnt * a + b))
            {
                cnt++;
            }
            if (MAX < cnt)
            {
                ansa = a;
                ansb = b;
                MAX = cnt;
            }
        }
    }
    cout << ansa << " " << ansb;
}
