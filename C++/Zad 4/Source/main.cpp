#include <iostream>
#include "tabbit.hpp"

using namespace std;

int main()
{
    tab_bit tab1 = tab_bit(16);
    try
    {
      cin>>tab1;
    }
    catch(string exc)
    {
        cout<<exc<<endl;
    }
    cout<<tab1<<endl;

    unsigned long long slowo = 123456789ull;
    tab_bit tab2 = tab_bit(slowo);
    cout<<tab2<<endl;

    bool bit;
    bit = tab2[2];
    cout<<bit<<endl;

    tab_bit tab3 = tab_bit(7ull);
    cout<<tab3<<endl;

    tab_bit tab4;
    tab4 = tab3;
    cout<<tab4<<endl;

    tab_bit tab5 = tab_bit(tab2);
    cout<<tab5<<endl;

    tab_bit tab6(tab_bit(5));
    cout<<tab6<<endl;

    tab_bit tab7;
    tab7 = tab_bit(3);
    cout<<tab7<<endl;

    for(int z=5;z>=0;z--)
        cout<<tab3[z];
    cout<<endl;

    tab_bit tab8;
    tab8 |= tab2;
    cout<<tab8<<endl;

    tab8 &= tab3;
    cout<<tab8<<endl;

    tab8 ^= tab2;
    cout<<tab8<<endl;

    tab8 = tab2 | tab3;
    cout<<tab8<<endl;

    tab8 = tab2 & tab3;
    cout<<tab8<<endl;

    tab8 = tab2 ^ tab3;
    cout<<tab8<<endl;

    cout<<!tab8<<endl;

    tab_bit tab9;
    tab9[0]=1;
    cout<<tab9<<endl;

    tab9[2]=true;
    cout<<tab9<<endl;

    tab9[6]=tab9[4]=tab9[2];
    cout<<tab9<<endl;

    return 0;
}
