#include <bits/stdc++.h>
using namespace std;

#define fo(i, l, r) for (int i = l; i < r; i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second
typedef long long ll;

int min_operations_to_sort(string s)
{
    ll n = s.size();
    string tmp = s;

    sort(all(tmp));

    if (s == tmp)
    {
        return 0;
    }

    ll cnt = 0;
    char c = s[0];

    stack<pair<char, ll>> st;
    st.push({s[0], 0});
    fo(i, 1, n)
    {
        while (st.size() && st.top().ff < s[i])
            st.pop();
        st.push({s[i], i});
    }

    vector<ll> v;
    string tmp2;

    while (st.size())
    {
        v.pb(st.top().ss);
        tmp2 += s[st.top().ss];
        st.pop();
    }
    reverse(all(v));
    ll j = 0;
    ll sz = v.size();
    char maxi = tmp2[sz - 1];
    fo(i, 0, sz)
    {
        if (s[v[i]] == maxi)
        {
            j = i;
        }
    }
    fo(i, 0, sz / 2)
    {
        swap(s[v[i]], s[v[sz - i - 1]]);
    }

    if (s == tmp)
    {
        return sz - j - 1;
    }
    else
    {
        return -1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << min_operations_to_sort(s) << "\n";
    }

    return 0;
}