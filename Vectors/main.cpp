#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v1 = {1,2,3,4};

//    cout<<v1[0]<<endl; // pirma elementa spausdina
//    cout<<v1.front()<<endl; //pirma elementa spausdina
//    cout<<v1.back()<<endl; //paskutini elementa duoda
//
//    v1.push_back(5); // appendina elementa
//    v1.pop_back(); //paskutini elementa istrina
//
//    cout<<v1.size()<<endl; // kiek elemntu
//    cout<<v1.capacity()<<endl; // kiek atminties
//    v1.insert(v1.begin(),5); //i nuline pozicija ideda nauja skaiciu
//    v1.insert(v1.begin()+1,7); //+1 - i pirma pozicija ideda naudja skc
//    cout<<v1[0]<<endl;
//
//    v1.erase(v1.begin()); //istrina nulini elementa
//    cout<<v1[0]<<endl; //todel dabar spausdina 7

    for(int i=0; i<v1.size(); i++)
    {
        cout<<v1[i]<<endl;
    }
    for(auto itr = v1.begin(); itr !=v1.end(); itr++)
    {
        cout<<*itr<<endl;
    }
    return 0;
}
