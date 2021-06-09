#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int Gao = 10000000;
struct Node
{
    char name[12];
    int card[6];
    int val;
};
char s1[12], s2[12];
Node arr[100008];

int check8(int c[])
{
    for (int i = 9; i >= 1; --i)
    {
        if (c[i] && c[i + 1] && c[i + 2] && c[i + 3] && c[i + 4])
            return i + 4;
    }
    return 0;
}

int check7(int c[])
{
    for (int i = 1; i <= 13; ++i)
    {
        if (c[i] == 5)
            return i * 100000 + i * 1000;
        else if (c[i] == 4)
        {
            for (int j = 1; j <= 13; ++j)
                if (c[j] == 1)
                    return i * 100000 + j * 1000;
        }
    }
    return 0;
}

int check6(int c[])
{
    for (int i = 1; i <= 13; ++i)
    {
        for (int j = 1; j <= 13; ++j)
        {
            if (i == j)
                continue;
            if (c[i] == 2 && c[j] == 3)
            {
                return j * 100000 + i * 1000;
            }
        }
    }
    return 0;
}

int check5(int c[])
{
    for (int i = 1; i <= 13; ++i)
    {
        if (c[i] == 3)
        {
            int ret = 0;
            for (int j = 1; j <= 13; ++j)
            {
                if (i == j)
                    continue;
                if (c[j])
                    ret += j;
            }
            return i * 100000 + ret * 1000;
        }
    }
    return 0;
}

int check4(int c[])
{
    for (int i = 1; i <= 13; ++i)
    {
        for (int j = i + 1; j <= 13; ++j)
        {
            if (c[i] == 2 && c[j] == 2)
            {
                for (int k = 1; k <= 13; ++k)
                {
                    if (c[k] == 1)
                        return j * 100000 + i * 1000 + k * 10;
                }
            }
        }
    }
    return 0;
}

int check3(int c[])
{
    for (int i = 1; i <= 13; ++i)
    {
        if (c[i] == 2)
        {
            int ret = 0;
            for (int j = 1; j <= 13; ++j)
            {
                if (j == i)
                    continue;
                if (c[j])
                    ret += j;
            }
            return i * 100000 + ret;
        }
    }
    return 0;
}

int fuck(int card[])
{
    int c[16];
    memset(c, 0, sizeof(c));
    int ttt = 0;
    for (int i = 1; i <= 5; ++i)
        c[card[i]]++;
    if (c[10] && c[11] && c[12] && c[13] && c[1])
        return 9 * Gao + 100;
    else if (ttt = check8(c))
        return 8 * Gao + 10000 * ttt;
    else if (ttt = check7(c))
        return 7 * Gao + ttt;
    else if (ttt = check6(c))
        return 6 * Gao + ttt;
    else if (ttt = check5(c))
        return 5 * Gao + ttt;
    else if (ttt = check4(c))
        return 4 * Gao + ttt;
    else if (ttt = check3(c))
        return 3 * Gao + ttt;
    else
    {
        int ret = 0;
        for (int i = 1; i <= 5; ++i)
            ret += card[i];
        return ret;
    }

}

bool cmp(Node x, Node y)
{
    if (x.val != y.val)
        return x.val > y.val;
    else
        return strcmp(x.name, y.name) < 0;
}

int main()
{
    int n;
    while (~scanf("%d", &n) && n)
    {
        for (int i = 1; i <= n; ++i)
        {
            scanf("%s %s", arr[i].name, s2);
            int id = 0;
            int _ = strlen(s2);
            for (int j = 0; j < _; ++j)
            {
                if (s2[j] == 'A')
                    arr[i].card[++id] = 1;
                else if (s2[j] == 'J')
                    arr[i].card[++id] = 11;
                else if (s2[j] == 'Q')
                    arr[i].card[++id] = 12;
                else if (s2[j] == 'K')
                    arr[i].card[++id] = 13;
                else if (s2[j] == '1')
                {
                    if (j + 1 < _ && s2[j + 1] == '0')
                        arr[i].card[++id] = 10;
                    else
                        arr[i].card[++id] = 1;
                }
                else if (s2[j] == '0')
                    continue;
                else
                    arr[i].card[++id] = s2[j] - '0';
            }
            arr[i].val = fuck(arr[i].card);
            //cout << arr[i].val << endl;
        }
        sort(arr + 1, arr + n + 1, cmp);
        for (int i = 1; i <= n; ++i)
            printf("%s\n", arr[i].name);
    }
    return 0;
}