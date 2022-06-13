/**
 * @file talstelsels.cpp
 * @author Jos Janssens (jey.janssens@studie.openuniversiteit.nl)
 * @brief Calulations for calculations 
 * @version 0.1
 * @date 2022-06-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>
#include <cstring>
#include <math.h>

using namespace std;

string int2bin(int getal);
int bin2int(string str);
bool checkBin(string str);

int main(int argc, char* argv[]){    
    cout<<"testen op talstelsels"<<endl;
    cout<< "-4: " << int2bin(-4)<<endl;
    cout<< "-5: " << int2bin(-5)<<endl;
    cout<< "1024: " << int2bin(1024)<<endl;
    cout<< "6: " << int2bin(6)<<endl;
    cout<< "te groot ? "<< int2bin(568778532)<<endl;
    cout<< "cijfers anders dan 0 en 1: "<< checkBin("002")<<endl;
    cout<< "-6: "<< int2bin(-6)<<" "<< bin2int(int2bin(6)) <<endl;

}

/**
 * @brief Conversion from integer to binairy 
 * 
 * @param getal for conversion to binary
 * @return string is the binary representation of the interger
 */
string int2bin(int getal){
    string str="";
    string minus = "";
    const char C0 = '0';
    const char C1 = '1';
    
    if (getal<0){
        minus = "-";
        getal *= -1;
    }
    getal % 2==0 ? str= C0 + str : str = C1 + str;
    if (getal/2 > 0) str = int2bin(getal/2) + str;

    return minus + str;
}

/**
 * @brief check of the string a binary representaion is
 * 
 * @param str the string representation of a binary to check
 * @return true when it is a binary
 * @return false when it is fals
 */
bool checkBin(string str){
    bool res = false;
    string ss = str;
    int teller = str.length()-1;

    while (teller > 0){
        char c =str.at(teller);
        c == '0' || '1' ? res = true : res = false;
        if (c='-' && teller ==0) res == true; // it is a negative value
        if (res == false) break;
        teller --;
    }

    return res;
}

/**
 * @brief converion of a binary string to an
 * 
 * @param str 
 * @return int 
 */
int bin2int(string str){
    int res = 0;
    if(! checkBin(str)) return -1;
    int index = str.length()-1;
    int teller = 0;
    int teken;
    str.at(0) == '-' ? teken = -1: teken = 1;

    while(index >= 0){
        if(str.at(index) =='1'){
            res += pow(2,teller);
        }
        index --; // going to zero
        teller++; // to calculate power of 2

    }

    return res*teken;
}