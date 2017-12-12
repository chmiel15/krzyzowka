#include <iostream>
#include "krzyzowka.h"
using namespace std;

int main()
{
    string bufor;                //bufor do wczytywania ciagu znakow
    char c;                         //zmienna przechowywujaca znak
    int bylo_k=0;
    int i;
    int j;              //Czy nastapil juz koniec schematu krzyzowki?
    int height=0;
    int width=0;
    list<string> tablica_wyrazow;   //lista przechowywujaca schemat krzyzowki
    list<string>::iterator it;      //iterator na liiste wyrazow
    int wyjscie=0;

    cout<< "Witaj w programie wspomagajacym ukladanie krzyzowek!" << endl;
    cout<< "Podaj schemat krzyzowki, znak 'X' oznacza miejsce na litere do wpisania"<<endl;
    cout<<"znak ' '(space) oznacza, miejsce zarezerwowane, oddzielajace wyrazy w krzyzowce "<<endl;
    cout<<"Jesli chcesz zamknac program podaj znak 'q'\n";
    cout<<"Przyklad krzyzowki:"<< endl;
    cout<<"X X     O M \n";
    cout<<"XXXX    PIES\n";
    cout<<"X X     A T \n";
    cout<<"XXXX    DRAN\n";
    cout<<"Wprowadz kolejne wiersze schematu krzyzowki:";
    cout<<"nacisniecie przycisku 'k' oznacza zakonczenie wprowadzania schematu krzyzowki"<<endl;


    while(bylo_k!=1 && wyjscie!=1) //tworzenie schematu krzyzowki
    {
    i=0;
    getline(cin,bufor);
    c=bufor[i];
    if(c=='q' && bufor.size()==1)
        wyjscie=1;
    while(c!='\0')
    {
        if(c=='k')
            bylo_k=1;
        i+=1;
        c=bufor[i];
    }
    if(bylo_k==0)
        tablica_wyrazow.push_back(bufor);
    }
while(wyjscie!=1)
{
    height=tablica_wyrazow.size();      //wysokosc krzyzowki
    it=tablica_wyrazow.begin();
    width=(*it).length();       //szerokosc krzyzowki
 //tworzenie schematu krzyzowki jako tablica znakow
 // cout<<"\n\nTABLICA 2D - C++\n";
    char **tab = new char *[height]; //alokacja pamieci
    for ( i = 0; i < height; ++i )
    {
    tab[i] = new char [width]; //alokacja pamieci
        for ( j = 0; j < width; ++j) //wpisanie wartosci do tablicy
            tab[i][j]=(*it)[j];
        it++;
    }
    //wypisz tab2[w][k]
/*
    for (  i = 0; i < height; ++i, cout<<endl )
    {
        for ( j = 0; j < width; ++j)
            cout<<tab[i][j];
    }

    cout<<"Oto schemat krzyzowki(lista)"<<endl;        //wyswietlanie schematu krzyzowki

    for(it=tablica_wyrazow.begin();it!=tablica_wyrazow.end();it++)
        cout<<*it<<endl;
*/


//znajdywanie poziomych miejsc na wyrazy i dodawanie ich do tablicy list
list<wspolrzedne> poziome[width+1];
list<wspolrzedne>::iterator iter;
int dlugosc=0;
wspolrzedne temp;

for(i=0;i<height;i++)
{
    for(j=0;j<width;j++)
    {
        if(tab[i][j]=='X')
        {
            dlugosc++;
        }
        else
        {
            if(dlugosc>1)
            {
            temp.x=j-dlugosc;
            temp.y=i;
            poziome[dlugosc].push_back(temp);
            }
            dlugosc=0;
        }
    }
    if(dlugosc>1)
        {
        temp.x=j-dlugosc;
        temp.y=i;
        poziome[dlugosc].push_back(temp);
        }
    dlugosc=0;
}
//wyswietlanie wspolrzednych wolych miejsc w krzyzowce
/*
for(i=0;i<width+1;i++)
{
cout<<"wyrazy poziome dlugosci"<<i<<endl;
    for(iter=poziome[i].begin();iter!=poziome[i].end();iter++)
        cout<<"x:"<<(*iter).x<<","<<"y:"<<(*iter).y<<"\t";
cout<<"\n";
}
*/
//znajdywanie pionowych miejsc na wyrazy i dodawanie ich do tablicy list
list<wspolrzedne> pionowe[height+1];
dlugosc=0;

for(j=0;j<width;j++)
{
    for(i=0;i<height;i++)
    {
        if(tab[i][j]=='X')
        {
            dlugosc++;
        }
        else
        {
            if(dlugosc>1)
            {
            temp.x=j;
            temp.y=i-dlugosc;
            pionowe[dlugosc].push_back(temp);
            }
            dlugosc=0;
        }
    }
    if(dlugosc>1)
        {
        temp.x=j;
        temp.y=i-dlugosc;
        pionowe[dlugosc].push_back(temp);
        }
    dlugosc=0;
}
//wyswietlanie wspolrzednych wolych miejsc w krzyzowce
/*
for(i=0;i<height+1;i++)
{
cout<<"wyrazy pionowe dlugosci"<<i<<endl;
    for(iter=pionowe[i].begin();iter!=pionowe[i].end();iter++)
            cout<<"x:"<<(*iter).x<<","<<"y:"<<(*iter).y<<"\t";
cout<<"\n";
}
*/
//WCZYTYWANIE LISTY SLOW Z KONSOLI
//tworzenie listy slow w zaleznosci od dlugosci wyrazu

cout<<"Podaj wyrazy do krzyzowki wpisanie 'k' konczy podawanie wyrazow\n";
getline(cin,bufor);
int max_length=0;
vector<string> wyrazy;
while(bufor.size()!=1 || bufor[0]!='k' )
{
    wyrazy.push_back(bufor);
    if(bufor.size()>max_length)
        max_length=bufor.size();
    cout<<"Podaj kolejny wyraz"<<endl;
    getline(cin,bufor);
}

//tworzenie listy slow w zaleznosci od dlugosci wyrazów
list<string> baza_slow[max_length+1];
for(i=0;i<wyrazy.size();i++)
{
baza_slow[wyrazy[i].size()].push_back(wyrazy[i]);
}
//wyswietlanie zawartosci bazy slow
list<string>::iterator ptr;
/*
for(i=0;i<max_length+1;i++)
{
cout<<"slowa majace dlugosc:"<<i<<endl;
    for(ptr=baza_slow[i].begin();ptr!=baza_slow[i].end();ptr++)
        cout<<(*ptr)<<"\t";
cout<<"\n";
}
*/
//utworzenie pustej krzyzowki
cout<<"PUSTA KRZYZOWKA\n";
krzyzowka probna(width,&poziome[0],height,&pionowe[0],tab);
cout<<probna;

//tworzenie tylu list krzyzowek ile jest wyrazow
list<krzyzowka> robocze[wyrazy.size()+1];
//wstawianie pierwszego wyrazu wszedzie gdzie to jest mozliwe
//wyszukiwanie najdluzszego wyrazu

string wstawiany;
list<string>::iterator grrr;

i=max_length;
while(baza_slow[i].size()==0)
    i--;
grrr=baza_slow[i].begin();
wstawiany=*grrr;
baza_slow[i].pop_front();
//wstawianie wyrazu do krzyzowki
//CZESC GLOWNA PROGRAMU

probna.wstaw_wyraz(wstawiany,robocze[0]);

list<krzyzowka>::iterator pendolino;
for(int j=1;j<wyrazy.size();j++)
{
i=max_length;
while(baza_slow[i].size()==0)
    i--;
grrr=baza_slow[i].begin();
wstawiany=*grrr;
baza_slow[i].pop_front();
//wstawianie wyrazu do krzyzowki
//CZESC GLOWNA PROGRAMU
for(pendolino=robocze[j-1].begin();pendolino!=robocze[j-1].end();pendolino++)
{
(*pendolino).wstaw_wyraz(wstawiany,robocze[j]);
}
}

list<krzyzowka>::iterator przejscie;
if(robocze[wyrazy.size()-1].size()>0)
{
cout<<"Oto mozliwe ulozenia krzyzowek przy podanych wyrazach\n";
for(przejscie=robocze[wyrazy.size()-1].begin();przejscie!=robocze[wyrazy.size()-1].end();przejscie++)
    cout<<*przejscie;
}
else
cout<<"Z podanych wyrazow nie mozna ulozyc krzyzowki!!!\n";
//USUWANIE ZAALOKOWANEJ PAMIECI
//usuwanie krzyzowki
while(!tablica_wyrazow.empty())
    tablica_wyrazow.pop_front();
for ( i=0; i < height; ++i )
{
    delete [] tab[i]; //uwolnienie pamieci
}
    delete [] tab; //uwolnienie pamieci

if(width>0 || height>0)
    {
        for (int i = 0; i < height+1; ++i )
        {
            while(!pionowe[i].empty())
            {
                pionowe[i].pop_front();
            }
        }
        for (int i = 0; i < width+1; ++i )
        {
            while(!poziome[i].empty())
            {
                poziome[i].pop_front();
            }
        }
    }

//WPROWADZANIE NOWEGO SCHEMTU KRZYZOWKI
    cout<< "Podaj schemat nowej krzyzowki, znak 'X' oznacza miejsce na litere do wpisania"<<endl;
    cout<<"znak ' '(space) oznacza, miejsce zarezerwowane, oddzielajace wyrazy w krzyzowce "<<endl;
    cout<<"Jesli chcesz zamknac program podaj znak 'q'\n\n";

    cout<<"Wprowadz kolejne wiersze schematu krzyzowki:";
    cout<<"nacisniecie przycisku 'k' oznacza zakonczenie wprowadzania schematu krzyzowki"<<endl;

    bylo_k=0;
    while(bylo_k!=1 && wyjscie!=1) //tworzenie schematu krzyzowki
    {
    i=0;
    getline(cin,bufor);
    c=bufor[i];
    if(c=='q' && bufor.size()==1)
        wyjscie=1;
    while(c!='\0')
    {
        if(c=='k')
            bylo_k=1;
        i+=1;
        c=bufor[i];
    }
    if(bylo_k==0)
        tablica_wyrazow.push_back(bufor);
    }
}


cout<<"Dziekuje, dowidzenia !"<<endl;

return 0;
}
