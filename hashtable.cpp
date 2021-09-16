#include "hashtable.h"
#include <iostream>
#include <iomanip>
#include <fstream>

int hashtable::hashfunction(float x){ //Συνάρτηση κατακερματισμού.//
    return ((int)x%10);
}

hashtable::hashtable(){ //Κατασκευαστής.//
    for(int i=0;i<10;i++){
        htable[i].push_back(i);
    }
}

void hashtable::insert(float x){ //Εισαγωγή νέου στοιχείου στον Hashtable.//
    if(!(search(x))){ //Έλεγχος εάν το στοιχείο υπάρχει ήδη.//
        htable[hashfunction(x)].push_back(x);
    }
}

void hashtable::write(){ //Εγγραφή των αποτελεσμάτων.//
    ofstream screen; //Εγραφή του πίνακα στο αρχείο temp.//
    screen.open("temp.txt");
    for(int i=0;i<10;i++){
        screen<<i;
        for(int j=1;j<htable[i].size();j++){
            screen<<"-->"<<setprecision(2)<<fixed<<htable[i][j];
        }
        screen<<endl;
    }
    screen.close();
}

int hashtable::getsize(){ //Πλήθος στοιχείων του Hashtable.//
    int sum=0;
    for(int i=0;i<10;i++){
        sum+=(htable[i].size()-1);
    }
    return sum;
}

int hashtable::search(float x){ //Αναζήτηση στοιχείου στον Hashtable.//
    bool done=false;
    int j=1;
    while(done==false&&j<htable[hashfunction(x)].size()){
        if(x==htable[hashfunction(x)][j]){
            done=true;
        }
        j++;
    }
    if(done){ //Το στοιχείο βρέθηκε.//
        return 1;
    }
    else return 0; //Το στοιχείο δεν βρέθηκε.//
}