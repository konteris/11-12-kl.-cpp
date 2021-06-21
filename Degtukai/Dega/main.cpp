#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

void Sprendimas(int n, int & s, int & a, int & b, int & m); // n-rinkiniu skaicius; m-kiek liko

int main ()
{
    int n, x;
    int s, a, b, m;
    ifstream in ("degtukai.txt");
    ofstream out ("sprendimai.txt");
    in >> n;
    for (int i = 1; i <= n; i++)
    {
        in>>x;
        Sprendimas (x, s, a, b, m);
        out << s << " " << a << " " << b << " " << m << endl;
    }
    in.close();
    out.close();
    return 0;
}
void Sprendimas(int n, int & s, int & a, int & b, int & m)
{
    if (n < 4)
    {
        s = 0;
        a = 0;
        b = 0;
        m = n;
    }
    else
    {
        if (n % 4 < 2)
        {
            a = n / 4;
            b = a;
        }
        else
        {
            a = n / 4;
            b = a + 1;
        }
        s = a * b;
        m = n - 2 * (a + b);
    }
}

