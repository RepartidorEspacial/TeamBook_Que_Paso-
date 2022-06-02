
const ll INF = INT_MAX;

void hungaro(vector<vector<ll>> &a)
{

    ll n, m;

    n = a.size() - 1;
    m = a[n].size() - 1;
    // ll a[n+1][m+1]; // matriz de costos, 1-index
    vector<ll> u(n + 1), v(m + 1), p(m + 1), way(m + 1);
    for (ll i = 1; i <= n; ++i)
    {
        p[0] = i;
        ll j0 = 0;
        vector<ll> minv(m + 1, INF);
        vector<char> used(m + 1, false);
        do
        {
            used[j0] = true;
            ll i0 = p[j0], delta = INF, j1;
            for (ll j = 1; j <= m; ++j)
                if (!used[j])
                {
                    ll cur = a[i0][j] - u[i0] - v[j];
                    if (cur < minv[j])
                        minv[j] = cur, way[j] = j0;
                    if (minv[j] < delta)
                        delta = minv[j], j1 = j;
                }
            for (ll j = 0; j <= m; ++j)
                if (used[j])
                    u[p[j]] += delta, v[j] -= delta;
                else
                    minv[j] -= delta;
            j0 = j1;
        } while (p[j0] != 0);
        do
        {
            ll j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }

    vector<ll> ans(n + 1); // Para cada fila, en que columna esta el resultado.
    for (ll j = 1; j <= m; ++j)
        ans[p[j]] = j;
    ll cost = -v[0];


}
