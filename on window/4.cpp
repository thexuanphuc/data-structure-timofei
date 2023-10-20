#include <iostream>
#include <stack>
using namespace std;

struct t_Pair {
    int a;
    int b;
};

void modify_pair(t_Pair *p)
{
    p->a += 1;
     (*p).a += 1;
    (*p).b += 10;
}

int main()
{
    int n;
    cin >> n ;
    bool sieve[n+1];
    for (int i=0; i<=n; i++)
    {
        sieve[i] = true;
    }
    int x = 2;
    while (x*x <= n)
    {
        if(sieve[x])
        {
            for(int y = x*x; y<= n; y = y+x)
            {
                sieve[y] = false;
            }
        }
        x++;
    }
    for (x = 0; x<=n; x++)
    {
        if(sieve[x])
            cout << x << '\t';
    }
    return 0;
}