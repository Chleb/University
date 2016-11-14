#include "tabbit.hpp"
#include <cmath>

const int tab_bit::rozmiarSlowa = sizeof(long long) * 8;

ref::ref(tab_bit &tb)
{
    tab=tb.tab;
    nr_bitu=0;
}

ref::~ref()
{
    nr_bitu=0;
    tab=nullptr;
}

ref& ref::operator = (bool bit)
{
    int n = nr_bitu/tab_bit::rozmiarSlowa;
    int i=nr_bitu%tab_bit::rozmiarSlowa;
    unsigned long long nowe=1;
    nowe <<= i;
    if(!bit)
    {
        nowe = ~nowe;
        tab[n] &= nowe;
    }
    else
        tab[n] |= nowe;

    return *this;
}

ref& ref::operator = (const ref& bit)
{
    *this = bool(bit);
    return *this;
}

ref::operator bool() const
{
    int n = nr_bitu/tab_bit::rozmiarSlowa;
    int i=nr_bitu%tab_bit::rozmiarSlowa;
    unsigned long long nowe = tab[n];
    nowe >>= i;
    return nowe%2 == 1;
}

bool ref::operator ! () const
{
    return !bool(this);
}

ref tab_bit::operator [] (int i)
{
    ref referencja(*this);
    referencja.nr_bitu=i;
    return referencja;
}

tab_bit::tab_bit(int rozm)
{
    dl=rozm;
    int n=rozm/rozmiarSlowa;
    if(rozm%rozmiarSlowa != 0)
        n++;
    tab = new slowo[n];
    for(int z=0;z<n;z++)
        tab[z]=0;
}

tab_bit::tab_bit(slowo tb)
{
    dl=rozmiarSlowa;
    tab = new slowo[1];
    tab[0]=tb;
}

tab_bit::tab_bit()
{
    dl=rozmiarSlowa;
    tab = new slowo[1];
    tab[0]=0;
}

tab_bit::tab_bit (const tab_bit &tb)
{
    dl=tb.dl;
    int n=dl/rozmiarSlowa;
    if(dl%rozmiarSlowa != 0)
        n++;
    tab = new slowo[n];
    for(int z=0;z<n;z++)
        tab[z]=tb.tab[z];
}

tab_bit::tab_bit (tab_bit &&tb)
{
    dl=tb.dl;
    tab=tb.tab;
    tb.tab=nullptr;
}

tab_bit & tab_bit::operator = (const tab_bit &tb)
{
    if(&tb==this)
        return *this;
    this->~tab_bit();
    dl=tb.dl;
    int n=dl/rozmiarSlowa;
    if(dl%rozmiarSlowa != 0)
        n++;
    tab = new slowo[n];
    for(int z=0;z<n;z++)
        tab[z]=tb.tab[z];
    return *this;
}

tab_bit & tab_bit::operator = (tab_bit &&tb)
{
    if(&tb==this)
        return *this;
    dl=tb.dl;
    tab=tb.tab;
    tb.tab=nullptr;
    return *this;
}

tab_bit::~tab_bit ()
{
    dl=0;
    delete[] tab;
}

bool tab_bit::czytaj(int i) const
{
    if(i<0 || i>=dl)
        throw string("Indeks spoza zakresu.");
    int n = i/rozmiarSlowa;
    i-=n*rozmiarSlowa;
    slowo nowe = tab[n];
    nowe >>= i;
    return nowe%2 == 1;
}

bool tab_bit::pisz (int i, bool b) // zwraca true jesli sie powiodlo, false wpp.
{
    if(i<0 || i>=dl)
        return false;
    int n = i/rozmiarSlowa;
    i-=n*rozmiarSlowa;
    slowo nowe=1;
    nowe <<= i;
    if(!b)
    {
        nowe = ~nowe;
        tab[n] &= nowe;
        return true;
    }
    tab[n] |= nowe;
    return true;
}

bool tab_bit::operator[] (int i) const
{
    bool wynik;
    try
    {
        wynik = czytaj(i);
        return wynik;
    }
    catch(string obj)
    {
        throw obj;
    }
}

istream & operator >> (istream &we, tab_bit &tb) // jesli zostanie podany ciag bitow
                                                 //  dluzszy niz pojemnosc tab_bit to odcina najmniej znaczace bity
{
    string liczba;
    we>>liczba;
    for(unsigned int z=0;z<liczba.length();z++)
        if(liczba[z]!='0' && liczba[z]!='1')
            throw string("Niewlasciwy format danych.");
    int iter = liczba.length();
    if(iter > tb.dl)
        iter = tb.dl;
    iter--;
    bool bit;
    tb = tab_bit(tb.dl); // wyzerowanie tablicy
    for(int z=iter; z>=0; z--)
    {
        bit = (liczba[z]=='1');
        tb.pisz(iter-z, bit);
    }
    return we;
}

ostream & operator << (ostream &wy, const tab_bit &tb)
{
    int n=tb.dl-1;
    bool bit;
    for(int z=n; z>=0; z--)
    {
        bit=tb.czytaj(z);
        wy<<bit;
    }
    return wy;
}

tab_bit & tab_bit::operator |= (const tab_bit &tb)
{
    int n;
    if(dl <= tb.dl)
        n=(dl-1)/rozmiarSlowa;
    else
        n=(tb.dl-1)/rozmiarSlowa;

    for(int z=0;z<n;z++)
        tab[z] |= tb.tab[z];

    int i=min(dl-1, tb.dl-1)%rozmiarSlowa;
    if(i>0)
    {
        slowo nowe=tab[n] | tb.tab[n];
        slowo wzor=0;
        for(int z=0; z<=i; z++)
        {
            wzor+=1;
            wzor<<=1;
        }
        wzor+=1;
        nowe &= wzor;
        wzor = ~wzor;
        tab[n] &= wzor;
        tab[n] |= nowe;
    }

    return *this;
}

tab_bit & tab_bit::operator &= (const tab_bit &tb)
{
    int n;
    if(dl <= tb.dl)
        n=(dl-1)/rozmiarSlowa;
    else
        n=(tb.dl-1)/rozmiarSlowa;

    for(int z=0;z<n;z++)
        tab[z] &= tb.tab[z];

    int i=min(dl-1, tb.dl-1)%rozmiarSlowa;
    if(i>0)
    {
        slowo nowe=tab[n] & tb.tab[n];
        slowo wzor=0;
        for(int z=0; z<=i; z++)
        {
            wzor+=1;
            wzor<<=1;
        }
        wzor+=1;
        nowe &= wzor;
        wzor = ~wzor;
        tab[n] &= wzor;
        tab[n] |= nowe;
    }
    return *this;
}

tab_bit & tab_bit::operator ^= (const tab_bit &tb)
{
    int n;
    if(dl <= tb.dl)
        n=(dl-1)/rozmiarSlowa;
    else
        n=(tb.dl-1)/rozmiarSlowa;

    for(int z=0;z<n;z++)
        tab[z] ^= tb.tab[z];

    int i=min(dl-1, tb.dl-1)%rozmiarSlowa;
    if(i>0)
    {
        slowo nowe=tab[n] ^ tb.tab[n];
        slowo wzor=0;
        for(int z=0; z<=i; z++)
        {
            wzor+=1;
            wzor<<=1;
        }
        wzor+=1;
        nowe &= wzor;
        wzor = ~wzor;
        tab[n] &= wzor;
        tab[n] |= nowe;
    }
    return *this;
}

tab_bit operator | (const tab_bit &tb1, const tab_bit &tb2)
{
    unsigned long long puste=0;
    int nmin, nmax;
    nmin=min((tb1.dl-1)/tb1.rozmiarSlowa, (tb2.dl-1)/tb1.rozmiarSlowa);
    nmax=max((tb1.dl-1)/tb1.rozmiarSlowa, (tb2.dl-1)/tb1.rozmiarSlowa);

    tab_bit nowa = tab_bit(max(tb1.dl, tb2.dl));
    for(int z=0;z<=nmin;z++)
        nowa.tab[z]=tb1.tab[z] | tb2.tab[z];

    if(tb1.dl >= tb2.dl)
    {
        for(int z=nmin;z<nmax;z++)
            nowa.tab[z]=tb1.tab[z] | puste;
        nowa.dl=tb1.dl;
    }
    else
    {
        for(int z=nmin;z<nmax;z++)
            nowa.tab[z]=tb2.tab[z] | puste;
        nowa.dl=tb2.dl;
    }

    return nowa;
}

tab_bit operator & (const tab_bit &tb1, const tab_bit &tb2)
{
    unsigned long long puste=0;
    int nmin, nmax;
    nmin=min((tb1.dl-1)/tb1.rozmiarSlowa, (tb2.dl-1)/tb1.rozmiarSlowa);
    nmax=max((tb1.dl-1)/tb1.rozmiarSlowa, (tb2.dl-1)/tb1.rozmiarSlowa);

    tab_bit nowa = tab_bit(nmax*tb1.rozmiarSlowa);
    for(int z=0;z<=nmin;z++)
        nowa.tab[z]=tb1.tab[z] & tb2.tab[z];

    if(tb1.dl >= tb2.dl)
    {
        for(int z=nmin;z<nmax;z++)
            nowa.tab[z]=tb1.tab[z] & puste;
        nowa.dl=tb1.dl;
    }
    else
    {
        for(int z=nmin;z<nmax;z++)
            nowa.tab[z]=tb2.tab[z] & puste;
        nowa.dl=tb2.dl;
    }

    return nowa;
}

tab_bit operator ^ (const tab_bit &tb1, const tab_bit &tb2)
{
    unsigned long long puste=0;
    int nmin, nmax;
    nmin=min((tb1.dl-1)/tb1.rozmiarSlowa, (tb2.dl-1)/tb1.rozmiarSlowa);
    nmax=max((tb1.dl-1)/tb1.rozmiarSlowa, (tb2.dl-1)/tb1.rozmiarSlowa);

    tab_bit nowa = tab_bit(nmax*tb1.rozmiarSlowa);

    for(int z=0;z<=nmin;z++)
        nowa.tab[z]=tb1.tab[z] ^ tb2.tab[z];

    if(tb1.dl >= tb2.dl)
    {
        for(int z=nmin;z<nmax;z++)
            nowa.tab[z]=tb1.tab[z] ^ puste;
        nowa.dl=tb1.dl;
    }
    else
    {
        for(int z=nmin;z<nmax;z++)
            nowa.tab[z]=tb2.tab[z] ^ puste;
        nowa.dl=tb2.dl;
    }

    return nowa;
}

tab_bit operator ! (const tab_bit &tb)
{
    tab_bit nowa = tab_bit(tb.dl);
    nowa.dl=tb.dl;
    int n=tb.dl/tb.rozmiarSlowa;
    for(int z=0;z<n;z++)
        nowa.tab[z]= ~tb.tab[z];
    int i=tb.dl%tb.rozmiarSlowa;
    if(i > 0)
    {
        unsigned long long wzor=0;
        for(int z=0;z<i;z++)
        {
            wzor+=1;
            wzor<<=1;
        }
        nowa.tab[n]= ~tb.tab[n];
        nowa.tab[n] &= wzor;
    }

    return nowa;
}
