#include <iostream>
#include <fstream>

using namespace std;

void Skaitymas();

void Rasymas();

int main()
{

    return 0;
}
void Skaitymas()
{
    ifstream in("duom.txt");
    ofstream out("U1.txt");

    in.close();
    out.close();
}
