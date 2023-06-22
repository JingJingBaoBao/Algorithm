#include <iostream>

using namespace std;

const int N = 100010;

int m;
int q[N], hh = 0, tt = -1;

void push(int x)
{
    q[++ tt] = x;
}

void pop()
{
    hh ++ ;
}

void empty()
{
    if (hh <= tt) cout << "NO" << endl;
    else cout << "YES" << endl;
}

void query()
{
    cout << q[hh] << endl;
}

int main()
{
    cin >> m;

    string op;

    while (m -- )
    {
        cin >> op;
        if (op == "push")
        {
            int x;
            cin >> x;
            push(x);
        }
        else if (op == "pop")
        {
            pop();
        }
        else if (op == "empty")
        {
            empty();
        }
        else 
        {
            query();
        }
    }

    return 0;
}