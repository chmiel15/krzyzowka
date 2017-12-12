#include "krzyzowka.h"
krzyzowka::krzyzowka(int width,list<wspolrzedne>* poziomo, int height, list<wspolrzedne>* pionowo, char **tab)
{
//kopiowanie wspolrzednych wyrazow poziomych
szerokosc=width;

horizontal = new list<wspolrzedne>[szerokosc+1];
for (int i = 0; i < szerokosc+1; i++)
    {
        horizontal[i]=poziomo[i];
    }
//kopiowanie wspolrzednych wyrazow pionowych
wysokosc=height;

vertical=new list<wspolrzedne>[wysokosc+1];
for (int i = 0; i < wysokosc+1; i++)
    {
        vertical[i]=pionowo[i];
    }

//kopiowanie zawartosci krzyzowki
tabliczka = new char *[wysokosc]; //alokacja pamieci
    for (int i = 0; i < wysokosc; ++i )
    {
    tabliczka[i] = new char [szerokosc]; //alokacja pamieci
        for (int j = 0; j < szerokosc; ++j) //wpisanie wartosci do tablicy
            tabliczka[i][j]=tab[i][j];
    }
}
//ZAPRZYJAZNIONA FUNKCJA WYSWIETLAJACA
ostream& operator<<(ostream & os, krzyzowka &pr)
{
int i, j;
os<<"krzyzowka:\n";
/*
os<<"miejsca na wyrazy poziome"<<endl;
list<wspolrzedne>::iterator iter;
for(i=0;i<pr.szerokosc+1;i++)
{
os<<"wyrazy poziome dlugosci"<<i<<endl;
    for(iter=pr.horizontal[i].begin();iter!=pr.horizontal[i].end();iter++)
        os<<"x:"<<(*iter).x<<","<<"y:"<<(*iter).y<<"\t";
os<<"\n";
}

os<<"miejsca na wyrazy pionowe"<<endl;
for(i=0;i<pr.wysokosc+1;i++)
{
os<<"wyrazy poziome dlugosci"<<i<<endl;
    for(iter=pr.vertical[i].begin();iter!=pr.vertical[i].end();iter++)
        os<<"x:"<<(*iter).x<<","<<"y:"<<(*iter).y<<"\t";
os<<"\n";//TUTAJ COS SIE PIERDOLI
}
*/
for (  i = 0; i < pr.wysokosc; ++i, os<<endl )
    {
        for ( j = 0; j < pr.szerokosc; ++j)
            os<<pr.tabliczka[i][j];
    }

return os;

}
void krzyzowka::wstaw_wyraz(string & wyraz, list<krzyzowka>& yyee)
{
char **ta;
int sze;
int wy;
list<wspolrzedne> *ver;
list<wspolrzedne> *hor;
//kopiowanie wspolrzednych wyrazow poziomych
sze=szerokosc;
hor = new list<wspolrzedne>[sze+1];
for (int i = 0; i < sze+1; i++)
    {
        hor[i]=horizontal[i];
    }
//kopiowanie wspolrzednych wyrazow pionowych
wy=wysokosc;
ver=new list<wspolrzedne>[wy+1];
for (int i = 0; i < wy+1; i++)
    {
        ver[i]=vertical[i];
    }
//kopiowanie zawartosci krzyzowki
ta = new char *[wy]; //alokacja pamieci
    for (int i = 0; i < wy; ++i )
    {
    ta[i] = new char [sze]; //alokacja pamieci
        for (int j = 0; j < sze; ++j) //wpisanie wartosci do tablicy
            ta[i][j]=tabliczka[i][j];
    }

//wlasciwe wstawianie wyrazu i usuwanie odpowiednich wspolrzednych z listy
list<wspolrzedne>::iterator it;
list<wspolrzedne>::iterator do_usuniecia;
int movement=0;
if(wyraz.size()<=szerokosc)
{
for(it=horizontal[wyraz.size()].begin();it!=horizontal[wyraz.size()].end();it++,movement++)
{
do_usuniecia=hor[wyraz.size()].begin();
for(int k=0;k<movement;k++)
    do_usuniecia++;
int x=(*it).x;
int y=(*it).y;
bool ok=true;
/*
cout<<"x:"<<x<<endl;
cout<<"y:"<<y<<endl;
cout<<wyraz<<endl;
cout<<wyraz.size()<<endl;
*/
for(int i=0;i<wyraz.size();i++,x++)
{
if(ta[y][x]==wyraz[i] || ta[y][x]=='X')
{
    ta[y][x]=wyraz[i];
}
else
    ok=false;
}
if(ok)// TUTAJ JESZCZE ZNISZCZENIE STARYCH ZMIENNYCH I ALOKACJA NOWYCH
{
hor[wyraz.size()].erase(do_usuniecia);
krzyzowka tymczasowa(sze, &hor[0], wy, &ver[0], ta);
yyee.push_back(tymczasowa);
//NISZCZENIE DANYCH WEJSCIOWYCH
}
if(wy>0 || sze>0)
    {
        for (int i = 0; i < wy+1; ++i )
        {
            while(!ver[i].empty())
            {
                ver[i].pop_front();
            }
        }
        for (int i = 0; i < sze+1; ++i )
        {
            while(!hor[i].empty())
            {
                hor[i].pop_front();
            }
        }
    }
    for ( int i=0; i < wy; ++i )
    {
    delete [] ta[i]; //uwolnienie pamieci
    }
    wy=0;
    sze=0;
//WPROWADZANIE DANYCH WEJSCIOWYCH
//kopiowanie wspolrzednych wyrazow poziomych
sze=szerokosc;
hor = new list<wspolrzedne>[sze+1];
for (int i = 0; i < sze+1; i++)
    {
        hor[i]=horizontal[i];
    }
//kopiowanie wspolrzednych wyrazow pionowych
wy=wysokosc;
ver=new list<wspolrzedne>[wy+1];
for (int i = 0; i < wy+1; i++)
    {
        ver[i]=vertical[i];
    }
//kopiowanie zawartosci krzyzowki
ta = new char *[wy]; //alokacja pamieci
    for (int i = 0; i < wy; ++i )
    {
    ta[i] = new char [sze]; //alokacja pamieci
        for (int j = 0; j < sze; ++j) //wpisanie wartosci do tablicy
            ta[i][j]=tabliczka[i][j];
    }
}

}
//WSTAWIANIE WYRAZU W MIEJSCA PIONOWE
movement=0;
if(wyraz.size()<=wysokosc)
{
for(it=vertical[wyraz.size()].begin();it!=vertical[wyraz.size()].end();it++,movement++)
{
do_usuniecia=ver[wyraz.size()].begin();
for(int k=0;k<movement;k++)
    do_usuniecia++;
int x=(*it).x;
int y=(*it).y;
bool ok=true;
/*
cout<<"x:"<<x<<endl;
cout<<"y:"<<y<<endl;
cout<<wyraz<<endl;
cout<<wyraz.size()<<endl;
*/
for(int i=0;i<wyraz.size();i++,y++)
{
if(ta[y][x]==wyraz[i] || ta[y][x]=='X')
{
    ta[y][x]=wyraz[i];
}
else
    ok=false;
}
if(ok)// TUTAJ JESZCZE ZNISZCZENIE STARYCH ZMIENNYCH I ALOKACJA NOWYCH
{
ver[wyraz.size()].erase(do_usuniecia);
krzyzowka tymczasowa(sze, &hor[0], wy, &ver[0], ta);
yyee.push_back(tymczasowa);
//NISZCZENIE DANYCH WEJSCIOWYCH
}
if(wy>0 || sze>0)
    {
        for (int i = 0; i < wy+1; ++i )
        {
            while(!ver[i].empty())
            {
                ver[i].pop_front();
            }
        }
        for (int i = 0; i < sze+1; ++i )
        {
            while(!hor[i].empty())
            {
                hor[i].pop_front();
            }
        }
    }
    for ( int i=0; i < wy; ++i )
    {
    delete [] ta[i]; //uwolnienie pamieci
    }
    wy=0;
    sze=0;
//WPROWADZANIE DANYCH WEJSCIOWYCH
//kopiowanie wspolrzednych wyrazow poziomych
sze=szerokosc;
hor = new list<wspolrzedne>[sze+1];
for (int i = 0; i < sze+1; i++)
    {
        hor[i]=horizontal[i];
    }
//kopiowanie wspolrzednych wyrazow pionowych
wy=wysokosc;
ver=new list<wspolrzedne>[wy+1];
for (int i = 0; i < wy+1; i++)
    {
        ver[i]=vertical[i];
    }
//kopiowanie zawartosci krzyzowki
ta = new char *[wy]; //alokacja pamieci
    for (int i = 0; i < wy; ++i )
    {
    ta[i] = new char [sze]; //alokacja pamieci
        for (int j = 0; j < sze; ++j) //wpisanie wartosci do tablicy
            ta[i][j]=tabliczka[i][j];
    }
}
}
}
//DESTRUKTOR
krzyzowka::~krzyzowka()
{
    if(wysokosc>0 || szerokosc>0)
    {
        for (int i = 0; i < wysokosc+1; ++i )
        {
            while(!vertical[i].empty())
            {
                vertical[i].pop_front();
            }
        }
        for (int i = 0; i < szerokosc+1; ++i )
        {
            while(!horizontal[i].empty())
            {
                horizontal[i].pop_front();
            }
        }
    }
    delete [] vertical;
    delete [] horizontal;

    for ( int i=0; i < wysokosc; ++i )
    {
    delete [] tabliczka[i]; //uwolnienie pamieci
    }
    delete [] tabliczka; //uwolnienie pamieci
    wysokosc=0;
    szerokosc=0;
}
//KONSTRUKTOR KOPIUJACY
krzyzowka::krzyzowka(const krzyzowka & a)
{
//kopiowanie wspolrzednych wyrazow poziomych
int i=0;
szerokosc=a.zwroc_szerokosc();
horizontal = new list<wspolrzedne>[szerokosc+1];
for (int i = 0; i < szerokosc+1; i++)
    {
        horizontal[i]=*(a.poziom(i));
    }
//kopiowanie wspolrzednych wyrazow pionowych
wysokosc=a.zwroc_wysokosc();
vertical=new list<wspolrzedne>[wysokosc+1];
for (int i = 0; i < wysokosc+1; i++)
    {
        vertical[i]=*(a.pion(i));
    }
//kopiowanie zawartosci krzyzowki
tabliczka = new char *[wysokosc]; //alokacja pamieci
for(int i;i<wysokosc;i++)
    {
    tabliczka[i] = new char [szerokosc]; //alokacja pamieci
        for (int j = 0; j < szerokosc; ++j) //wpisanie wartosci do tablicy

         tabliczka[i][j]=a.zwroc(i,j);
    }
}
//PRZECIAZONY OPERATRO PRZYPISANIA
void krzyzowka::operator=(krzyzowka &a)
{
int i=0;
szerokosc=a.zwroc_szerokosc();
horizontal = new list<wspolrzedne>[szerokosc+1];
for (int i = 0; i < szerokosc+1; i++)
    {
        horizontal[i]=*(a.poziom(i));
    }
//kopiowanie wspolrzednych wyrazow pionowych
wysokosc=a.zwroc_wysokosc();
vertical=new list<wspolrzedne>[wysokosc+1];
for (int i = 0; i < wysokosc+1; i++)
    {
        vertical[i]=*(a.pion(i));
    }
//kopiowanie zawartosci krzyzowki
tabliczka = new char *[wysokosc]; //alokacja pamieci
for(int i=0;i<wysokosc;i++)
{
    tabliczka[i] = new char [szerokosc]; //alokacja pamieci
         for (int j = 0; j < szerokosc; ++j) //wpisanie wartosci do tablicy
         tabliczka[i][j]=a.zwroc(i,j);
}
}
