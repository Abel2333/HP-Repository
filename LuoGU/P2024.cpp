//x吃n+x
#include <algorithm>
#include <cstdio>
#include <iostream>
#define MAXN 50005
using namespace std;

int pre[3 * MAXN];

int findR(int root)
{
    int son = root;
    while (root != pre[root])
        root = pre[root];
    while (pre[son] != root)
    {
        int tmp = pre[son];
        pre[son] = root;
        son = tmp;
    }
    return root;
}

void unnion(int x, int y)
{
    int tmpX = findR(x);
    int tmpY = findR(y);
    if (tmpX==tmpY)
        return;
    pre[tmpY] = tmpX;
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= 3 * n; i++)
        pre[i] = i;
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);
        if (x > n || y > n)
        {
            ans++;
            continue;
        }

        if (op == 1)
        {
            if (x == y)
                continue;
            if ((findR(n + x) == findR(y))||(findR(x)==findR(n+y)))
            {
                ans++;
                continue;
            }
            else if ((findR(2*n+x)==findR(y))||(findR(x)==findR(2*n+y)))
            {
                ans++;
                continue;
            }
            else
            {
                unnion(x, y);
                unnion(n + x, n + y);
                unnion(2 * n + x, 2 * n + y);
                //cout << "* " << x << ' ' << y << endl;
                continue;
            }
        }
        else if (op == 2)
        {
            if (x == y)
            {
                ans++;
                continue;
            }
            else if (findR(x) == findR(n + y)) //y吃x
            {
                ans++;
                continue;
            }
            else if (findR(x) == findR(y)) //x和y同类
            {
                ans++;
                continue;
            }
            else
            {
                unnion(x, 2 * n + y);
                unnion(n + x, y);
                unnion(2 * n + x, n + y);
                //cout << "* " << x << ' ' << y << endl;
                continue;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}