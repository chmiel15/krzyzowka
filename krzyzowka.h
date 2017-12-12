#ifndef KRZYZOWKA_H_INCLUDED
#define KRZYZOWKA_H_INCLUDED
#include <string>
#include <iostream>
#include <list>
#include <vector>
#include <stdlib.h>
#include <stdbool.h>
using namespace std;

struct wspolrzedne
{
int x;
int y;
};

class krzyzowka
{
private:
char **tabliczka;
int wysokosc;
int szerokosc;
list<wspolrzedne> *vertical;
list<wspolrzedne> *horizontal;

public:
int zwroc_szerokosc()const {return szerokosc;}
int zwroc_wysokosc()const {return wysokosc;}
void operator=(krzyzowka &a);
list<wspolrzedne>* poziom(int i) const
{
return & horizontal[i];
}
list<wspolrzedne>* pion(int i) const
{
return &vertical[i];
}
~krzyzowka();
krzyzowka(const krzyzowka & a);
krzyzowka():wysokosc(0), szerokosc(0), tabliczka(NULL) ,vertical(NULL), horizontal(NULL){}
krzyzowka(int width,list<wspolrzedne>* poziomo, int height, list<wspolrzedne>* pionowo, char **tab);
//metoda wyłukskania elementu tablicy
char zwroc(int i, int j) const
{
return tabliczka[i][j];
}
//metoda uzupelniajaca krzyzowke o wyraz i wstawiajaca ja do wskazanej kolejki
//TUTAJ NAJWAZNIEJSZA METODA
void wstaw_wyraz(string & wyraz, list<krzyzowka>& yyee);
//zaprzyjazniona funkcja wyswietlajaca
friend ostream& operator<<(ostream & os, krzyzowka &pr);


};


#endif // KRZYZOWKA_H_INCLUDED
