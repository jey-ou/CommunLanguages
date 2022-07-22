/*
 * @file ggd-kgv.cpp
 * @author Jos Janssens (jey.janssens@studie.openuniversiteit.nl)
 * @brief calculation of greatest common divider, smallest common factor
 * @version 0.2
 * @date 2022-07-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
#include<cmath>
#include<cassert>

//#define NDEBUG
using namespace std;

void swap(int& x, int& y);
int ggd(int a, int b);
int kgv(int a, int b);

int main(){
    // test op swap
    int x = 8;
    int y = 45;
    int resultaat = 0;
    cout<< "\nvoor de uitvoering van de swap, x ="<< x <<" y = "<< y << endl;
    swap(x,y);
    assert(x == 45 && y == 8);
    cout<< "swap succesvol uitgevoerd"<< endl;

    cout<<"\ntesten op ggd"<< endl;
    assert(1== ggd(8,45));
    assert(2== ggd(90,8));
    // assert(ggd(0,5)>0); // fout opsporing voor null
    assert(5 == ggd(-55, 5)); 
    assert(12 == ggd(60,-24));

    cout<<"testen op ggd werden met succes afgerond"<<endl;

    cout<<endl<<"test op kgv"<<endl;
    resultaat = kgv (11,5);
    assert(55 == kgv(11,5));
    cout<<"Het kleinst gemeenveelvoud van (11 en 5) is "<< resultaat;

    return 0;
}

/**
 * @brief het swappen van twee integer variabelen
 * Hierbij wordt de techniek van 'by reference' toegepast
 * dus mogelijk met side-effects voor lokale variabelen !!
 * @param x 
 * @param y 
 */
void swap(int& x, int& y){
    int temp;
    temp = x;
    x=y;
    y=temp;
}

/**
 * @brief groots gemene deler wordt berekend van twee integers
 * De methode van eclides wordt hier gebruikt
 * En het algoritme is recursief
 * @param a eerste integer
 * @param b tweede integer
 * @return integer waarde die staat voor de ggd waarde
 */
int ggd(int a, int b){
    int resultaat;
    int temp;     

    if(a == 0 || b == 0)
        return -1;

    a= abs(a);
    b= abs(b);
    if (a<b){
        swap(a,b);
        ggd(a,b);
    }

    //cout <<"waarde a = "<< a << " waarde voor b = "<< b << endl;
    temp = a % b;
    //cout << "rest = "<< temp << endl;
     
    if (temp == 0)
        return b;
    ggd(b,temp);
    
}

/**
 * @brief kleinst gemeen veelvoud van twee intergers
 * wordt berekend met behulp van de ggd van deze twee integers
 * het gebruikt algoritme is het product van beide integers
 * gedeeld door ggd.
 * @param a 
 * @param b 
 * @return int 
 */
int kgv(int a, int b){
    // de volgorde speelt geen rol, d.w.z de swap (a,b) heeft wel een side effekt
    // (de wisseling van waarden van a en b) maar niet op het resultaat.
    // maar voor alle zekerheid. De waarden x en y zijn geen referenties
    if(a==0 || b ==0)
        return 0; //nuldeling leidt tot fouten
    int x = a;
    int y = b;
    int d = ggd(x,y);
    return a*b/d; // haakjes zijn overbodig
}