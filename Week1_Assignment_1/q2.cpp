#include "bits/stdc++.h"

using namespace std;
#define inti long long
#define ll long long
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t mod = 1e9 + 7;
const int32_t MM = 998244353;

int tim = 1;
void dfs(int node, vector<vector<int>> &g, vector<int> &vis, vector<int> &inTime, vector<int> &outTime)
{
    vis[node] = 1;
    inTime[node] = tim++;
    for (auto ch : g[node])
    {
        if (!vis[ch])
        {
            dfs(ch, g, vis, inTime, outTime);
        }
    }
    outTime[node] = tim++;
    return;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> inTime(n + 1);
    vector<int> outTime(n + 1);
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> vis(n + 1, 0);
    dfs(1, g, vis, inTime, outTime);
    int q;
    cin >> q;
    while (q--)
    {
        int dir, x, y;
        cin >> dir >> x >> y;
        bool check = (inTime[x] < inTime[y]) and (outTime[y] < outTime[x]);
        check = check or ((inTime[y] < inTime[x]) and (outTime[x] < outTime[y]));
        if (check)
        {
            if ((inTime[x] < inTime[y]) and dir == 0)
            {
                cout << "YES" << endl;
            }
            else if ((inTime[y] < inTime[x]) and dir == 1)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // memset(prime, true, sizeof(prime));
    //primes(); // primes under 1lakh

    /*
  #ifdef NCR
        init();
    #endif
*/
    solve();
}
