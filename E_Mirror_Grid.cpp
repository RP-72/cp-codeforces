#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mem0(a) memset(a, 0, sizeof(a))
#define mem1(a) memset(a, -1, sizeof(a))
#define memf(a) memset(a, false, sizeof(a))
#define all(v) v.begin(), v.end()
#define sz(a) (ll) a.size()
#define F first
#define S second
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountll(x)
#define pll pair<ll, ll>
#define ld long double

const int M = 1000000007;
const int MM = 998244353;
const long double PI = acos(-1);

ll power(ll b, ll e, ll m)
{
    if (e == 0)
        return 1;
    if (e & 1)
        return b * power(b * b % m, e / 2, m) % m;
    return power(b * b % m, e / 2, m);
}
ll power(ll b, ll e)
{
    if (e == 0)
        return 1;
    if (e & 1)
        return b * power(b * b, e / 2);
    return power(b * b, e / 2);
}
template <typename T, typename U>
static inline void amin(T &x, U y)
{
    if (y < x)
        x = y;
}
template <typename T, typename U>
static inline void amax(T &x, U y)
{
    if (x < y)
        x = y;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p)
{
    return os << '(' << p.F << "," << p.S << ')';
}

vector<bool> SieveOfEratosthenes(int n)
{
    // Create a boolean array
    // "prime[0..n]" and initialize
    // all entries it as true.
    // A value in prime[i] will
    // finally be false if i is
    // Not a prime, else true.
    vector<bool> prime(n + 1, true);
    // memset(prime, true, sizeof(prime));
    // for(auto &i: prime){
    //     i = true;
    // }

    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples
            // of p greater than or
            // equal to the square of it
            // numbers which are multiple
            // of p and are less than p^2
            // are already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    return prime;
}

template <class T, class U>
bool contains(const std::vector<T> &container, const U &v)
{
    auto it = std::lower_bound(
        container.begin(),
        container.end(),
        v,
        [](const T &l, const U &r)
        { return l < r; });
    return it != container.end() && *it == v;
}

int SolveMe()
{
    int n;
    cin >> n;
    int arr[n][n];
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = (int(s[j]) - 48);
        }
    }

    int summ = 0;
    ll count = 0;
    for (int i = 0; i < (n + 1) / 2; i++)
    {
        for (int j = 0; j < (n + 1) / 2; j++)
        {
            if (arr[i][j] == arr[j][n - i - 1] && arr[j][n - i - 1] == arr[n - i - 1][n - j - 1] && arr[n - i - 1][n - j - 1] == arr[n - j - 1][i])
            {
                continue;
            }
            summ = arr[i][j] + arr[j][n - i - 1] + arr[n - j - 1][i] + arr[n - i - 1][n - j - 1];
            if (summ > 2)
            {
                arr[i][j] = arr[j][n - i - 1] = arr[n - j - 1][i] = arr[n - i - 1][n - j - 1] = 1;
            }
            else
            {
                arr[i][j] = arr[j][n - i - 1] = arr[n - j - 1][i] = arr[n - i - 1][n - j - 1] = 0;
            }
            // cout << summ << " > " << i << " , " << j << endl;
            count += min(4 - summ, summ);
        }
    }
    cout << count << endl;

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef runSieve
    sieve();
#endif
#ifdef NCR
    initialize();
#endif
    //     freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int TESTS = 1;
    cin >> TESTS;

    while (TESTS--)
        SolveMe();

    // #ifdef LOCAL_DEFINE
    // cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    // #endif
    return 0;
}
