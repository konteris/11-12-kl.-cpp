#include <iostream>

using namespace std;

int main()
{
    //---stringai---------------------------
    string foo = "taip ne";
    //cout << foo[0]; // t raide printina

    //cout<<foo.find("ne", 0); //randa kelintas yra

    //cout<<foo.substr(2, 3); "ip " padaro nauja stringa

    //pointer---------------------------------

    int age = 19;
    int *pAge = &age;//pointer

    double gpa = 2.7;
    double *pGpa = &gpa;

    string name = "Matas";

    cout << pAge<<endl;
    cout << *pAge;

    return 0;

}
