#include <algorithm>
#include <cstdio>
#include <iostream>
#define ll long long
#define MAXN 100005
using namespace std;

struct node
{
    int l, r;
    ll sum;
    ll lazyMul;
    ll lazySum;
} tree[4 * MAXN];

int arry[MAXN];

void updateNode(int n, int p)
{
    tree[n].sum = (tree[n << 1].sum + tree[(n << 1) + 1].sum) % p;
}

void build(int lf, int rg, int n, int p)
{
    tree[n].l = lf;
    tree[n].r = rg;

    tree[n].lazyMul = 1;
    tree[n].lazySum = 0;
    if (lf == rg)
    {
        tree[n].sum = arry[lf] % p;
        return;
    }
    int mid = (lf + rg) >> 1;
    build(lf, mid, n << 1, p);
    build(mid + 1, rg, (n << 1) + 1, p);
    updateNode(n, p);
}

void pushDown(int n, int p)
{
    if (tree[n].l == tree[n].r)
    {
        tree[n].lazySum = 0;
        tree[n].lazyMul = 1;
        return;
    }
    tree[2 * n].lazyMul = (ll)(tree[n << 1].lazyMul * tree[n].lazyMul) % p;
    tree[2 * n + 1].lazyMul = (ll)(tree[(n << 1) + 1].lazyMul * tree[n].lazyMul) % p;

    tree[2 * n].sum = (ll)((tree[n << 1].sum * tree[n].lazyMul) % p + (tree[n].lazySum * (tree[n << 1].r - tree[n << 1].l + 1)) % p) % p;
    tree[2 * n + 1].sum = (ll)((tree[(n << 1) + 1].sum * tree[n].lazyMul) % p + (tree[n].lazySum * (tree[(n << 1) + 1].r - tree[(n << 1) + 1].l + 1)) % p) % p;

    tree[2 * n].lazySum = (ll)((tree[n << 1].lazySum * tree[n].lazyMul) % p + tree[n].lazySum) % p;
    tree[2 * n + 1].lazySum = (ll)((tree[(n << 1) + 1].lazySum * tree[n].lazyMul) % p + tree[n].lazySum) % p;

    tree[n].lazySum = 0;
    tree[n].lazyMul = 1;
}

void updateSum(int lf, int rg, ll num, int n, int p)
{
    if ((tree[n].l > rg) || (tree[n].r < lf))
        return;
    if (tree[n].l >= lf && tree[n].r <= rg)
    {
        tree[n].sum = (tree[n].sum + (num * (tree[n].r - tree[n].l + 1)) % p) % p;
        tree[n].lazySum = (tree[n].lazySum + num) % p;
        return;
    }
    pushDown(n, p);
    updateSum(lf, rg, num, n << 1, p);
    updateSum(lf, rg, num, (n << 1) + 1, p);
    updateNode(n, p);
}

void updateMult(int lf, int rg, ll num, int n, int p)
{
    if ((tree[n].l > rg) || (tree[n].r < lf))
        return;
    if (tree[n].l >= lf && tree[n].r <= rg)
    {
        tree[n].lazySum = (tree[n].lazySum * num) % p;
        tree[n].sum = (tree[n].sum * num) % p;
        tree[n].lazyMul = (tree[n].lazyMul * num) % p;
        return;
    }
    pushDown(n, p);
    updateMult(lf, rg, num, n << 1, p);
    updateMult(lf, rg, num, (n << 1) + 1, p);
    updateNode(n, p);
}

ll quir(int lf, int rg, int n, int p)
{
    if ((tree[n].l > rg) || (tree[n].r < lf))
        return 0;
    pushDown(n, p);
    if (tree[n].l >= lf && tree[n].r <= rg)
        return tree[n].sum;
    ll ans = 0;
    ans = (ans + quir(lf, rg, n << 1, p)) % p;
    ans = (ans + quir(lf, rg, (n << 1) + 1, p)) % p;
    return ans;
}

int main()
{
    int n, m, p;
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 1; i <= n; i++)
        scanf("%d", &arry[i]);
    build(1, n, 1, p);
    for (int i = 0; i < m; i++)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            int tmpX, tmpY, k;
            scanf("%d%d%d", &tmpX, &tmpY, &k);
            updateMult(tmpX, tmpY, k, 1, p);
        }
        else if (op == 2)
        {
            int tmpX, tmpY, k;
            scanf("%d%d%d", &tmpX, &tmpY, &k);
            updateSum(tmpX, tmpY, k, 1, p);
        }
        else
        {
            int tmpX, tmpY;
            scanf("%d%d", &tmpX, &tmpY);
            printf("%lld\n", quir(tmpX, tmpY, 1, p));
        }
    }
    return 0;
}