#include <iostream>
#include <string>

using namespace std;

//stringus geriau aprasyti private ir sukurti public funkcija
//constructors - funkcijos kurios veikia tik sukurus objekta
class Klase{
    public:
        void rasymas(){
            cout<<"foo"<<endl; //paprasta funkcija, kuria panaudosim sukurdami objekta
        }
        void set_vardas(string x){ //koki nori duodi varda
            vardas = x;
        }
        string get_vardas(){ //kaip int funkcija, kuri printina varda
            return vardas;
        }
    private:
        string vardas;
};

int main()
{
    Klase objektas;
    objektas.rasymas();

    Klase pasas;
    pasas.set_vardas("Matas"); //nustatom koki norim varda. tas pats kas vardas = "dasdkasd"
    cout<<pasas.get_vardas(); //galima ir pries tai dar kintamaji pasidaryti
    return 0;
}
