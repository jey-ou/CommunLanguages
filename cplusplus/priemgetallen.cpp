#include<iostream>
#include<cassert>
#include<cmath>

//#define NDEBUG

using namespace std;

bool isPriem(int g);
bool testen();

int main(){

    testen();

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
 * Het ontworpen algoritme is recursief
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

    temp = a % b;
     
    if (temp == 0)
        return b;
    ggd(b,temp);
    
}

/**
 * @brief Een getal is priem (een priemgetal) als het deelbaar is door 1
 *          of door zich zelf.
 * @param g het getal
 * @return true indien het een priemgetal is
 * @return false indien dit niet zo is
 */
bool isPriem (int g) {
    int half = (g / 2) + 1;
    if (g == 0) return false;
    if (g == 1 || g == 2) return true;

    for (int i = 2; i < half; i++){
        if (g % i == 0)
            return false ;
    }

    return true ;
}

/**
 * @brief zijnPriem houdt in dat twee getallen priem zijn als ze buiten 1,
 * geen gemeenschappelijke delers delen.
 * M.a.w. hun grootste gemeenschappelijke deler is 1 
 * @param a : het eerste gehele getal
 * @param b  : het tweede gehele getal
 * @return true als dit waar is
 * @return false als dit niet waar is
 */
bool zijnPriem (int a, int b){
    
    if (ggd(a,b) == 1)
        return true;

    return false;
}

bool testen(){
    cout << "testen op priemgetallen"<<endl;
    assert (isPriem(11));
    assert (not isPriem(0));
    assert (isPriem(1));
    assert (isPriem(2));
    assert (! isPriem(4));
    cout << "\ntesten op het priem zijn van 2 getallen"<< endl;
    //cout << "\ntesten op de eigenschap van priem zijn van twee getallen"<<endl;
    assert (zijnPriem(5,11));
    assert (not zijnPriem(2,4));
    
    
    cout << "De testen werden succesvol uitgevoerd"<< endl;
}