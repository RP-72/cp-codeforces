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

bool isPrime(ll n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (ll i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
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
    ll n;
    cin >> n;
    ll cnt = 1;
    vector<ll> ans(n);
    ans[0] = 1;
    // cout << cnt << "ss" << endl;

    ll x = 2;

    ll s = n / 2;
    ll curr = 1;
    for (ll i = 1; cnt < n; i++)
    {

        if (isPrime(x))
        {
            curr = x;
        }
        else
        {
            x++;
            curr = x;
        }

        while (curr <= n && cnt < n)

        {
            ans[cnt] = curr;
            curr *= 2;
            cnt++;
        }
        x++;
    }
    cout << "2" << endl;
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
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
