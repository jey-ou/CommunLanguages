/**
 * @file caesar.cpp
 * @author Jos Janssens (jey.janssens@studie.openuniversiteit.be)
 * @brief Ceasarversleutelaar
 *      Belangrijkste ontwikkelde functies:
 *          string encodeCeasar(int key, string s );
 *          string decodeCeasar(int key, string s );
 * @version 0.1
 * @date 2022-05-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

// function prototypes
string encodeCeasar (int key, string s );
string makeUpperString(string str);
char convertLower2Upper(char c);
string onlyTxt(string str);
string decodeCeasar (int key, string str );

//Globale variabelen
string gegevens();
int freq[26] = {75,16,12,59,189,8,34,24,65,15,23,36,22,100,61,16,0,64,37,68,20,29,15,0,0,14};
int berekendeFreq[26];

int main(){
    string str = "ab.1CDm";
    string zin = "lrvmnir bpr sumvbwvr jx bpr lmiwv yjeryrkbi jx qmbm wi bpr xjvni mkd ymibrut jx irhx wi bpr riirkvr jx ymbinlmtmipw utn qmumbr dj w ipmhh but bj rhnvwdmbr bpr yjeryrkbi jx bpr qmbm mvvjudwko bj yt wkbrusurbmbwjk lmird jk xjubt trmui jx ibndt";
    string s2;
    cout<< "test versleutelen ontcijferen"<< endl;
      
    cout<< "brutte txt: "<< str << endl;

    s2 = makeUpperString(str);
    s2 = onlyTxt(s2);
    cout<< "na opkuis: "<< s2 << endl;

    s2 = encodeCeasar(4,str);
    cout<< "cyphertext: "<< s2 << endl;

    s2 = decodeCeasar(4,s2);
    cout<< "klare tekst: "<< s2 << endl;

    for (int i=1; i<26;i++){
        cout<< "brute force "<< i << endl;
        s2 = decodeCeasar(i,onlyTxt(makeUpperString(zin)));
        cout<< "klare tekst: "<< s2 << endl;
    }

    return 0;
}

string encodeCeasar (int key, string str ){ //671 //674 //861  //875  //241    
    int lengte = str.length();
    int i, aantalCh, chgetal;
    string newString, s2;
    //int basis = (int) 'A';
    char c;

    if (str.size()==0){
        return str;
    }

    s2 = onlyTxt(str);
    s2 = makeUpperString(s2);
    //cout << s2 << endl;

    aantalCh = s2.size();

    for(i = 0; i<aantalCh; i++){
        c=s2.at(i);
        chgetal = ((int) c - (int) 'A' + key +26) % 26;
        //cout<< chgetal <<" " ;
        chgetal = chgetal + (int) 'A';
        newString += (char) chgetal;
        
    }
        
    return newString;
}

string decodeCeasar (int key, string str ){
    key = key * (-1);
    str = encodeCeasar(key, str);
    return str;
}

/**
 * @brief Zet een string om in allemaal hoofdletters
 * 
 * @param str string met willekeurige letters
 * @return string als resultaat met enkel hoofdletters
 */
string makeUpperString(string str){
    int lengte = str.size();
    string newString ="";

    if (lengte==0){
        cout<< "lege string"<< endl;
        return str;
    }

    for (int i=0; i<lengte; i++){
        char c = str.at(i);
        newString += convertLower2Upper(c);

    }
    
    return newString;
}
/**
 * @brief convertLower2Upper zet een miniscule letter om in een majuscule
 * 
 * @param c; het karakter dat al dan niet wordt omgezet
 * @return char het behandelde karakter dat majuskule is
 */
char convertLower2Upper(char c){
    if(isalpha(c) && islower(c)){
       c = toupper(c);       
    }
    return c;
}
/**
 * @brief Deze functie verwijdert alle leestekens en cijfers uit een tekst.
 * 
 * @param str, de tekst die behandeld worden.
 * @return string, de aangezuiverde tekst als resultaat.
 */
string onlyTxt(string str){
    int chgetal, i;
    int aantalch = str.size();
    char c;
    string newString = "";

    if(aantalch == 0){
        return str;
    }
    for(i = 0; i< aantalch; i++){
        c = str.at(i);
        if(isalpha(c)){
            newString += c;
        }
    }
    return newString;
}