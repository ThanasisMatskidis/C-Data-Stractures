#include "maxheap.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>

maxheap::maxheap(){
    NrOfEl=0;
    file=" ";
}

maxheap::maxheap(int sum,string filename){
    NrOfEl=sum;
    file=filename;
}

maxheap::~maxheap(){
    delete[] pmaxheap;
}

void maxheap::build(){ //Συνάρτηση κατασκευής του σωρού μεγίστων.//
    pmaxheap=new float[NrOfEl];
    ifstream data;
    data.open(file);
    int i=0;
    string lines;
    while(getline(data,lines)){ //Αρχικοποίηση του πίνακα με τα δεδομένα του αρχείου.//
        pmaxheap[i]=stof(lines);
        i++;
    }
    i=floor((NrOfEl-2)/2); //Κατασκευή του σωρού μεγίστων(αντιμετάθεση των στοιχείων του πίνακα για να πετύχουμε το επιθυμητό αποτέλεσμα).//
    float temp;
    int swap_child=NrOfEl;
    bool done_swap = true;
    while((done_swap)||(i>=0)){
        done_swap=false;
        if(((2*i)+2)<=(NrOfEl-1)){
            if(pmaxheap[(2*i)+1]>pmaxheap[(2*i)+2]){
                if (pmaxheap[(2*i)+1]>pmaxheap[i]){
                    temp=pmaxheap[(2*i)+1];
                    pmaxheap[(2*i)+1]=pmaxheap[i];
                    pmaxheap[i]=temp;
                    done_swap=true;
                    swap_child=(2*i)+1;
                }
            }
            else{
                if(pmaxheap[(2*i)+2]>pmaxheap[i]){
                    temp=pmaxheap[(2*i)+2];
                    pmaxheap[(2*i)+2]=pmaxheap[i];
                    pmaxheap[i]=temp;
                    done_swap=true;
                    swap_child=(2*i)+2;
                }
            }
        }
        else{
            if(pmaxheap[(2*i)+1]>pmaxheap[i]){
                temp=pmaxheap[(2*i)+1];
                pmaxheap[(2*i)+1]=pmaxheap[i];
                pmaxheap[i]=temp;
                done_swap=true;
                swap_child=(2*i)+1;
            }
        }
        if(done_swap){
            if(((swap_child*2)+1)>(NrOfEl-1)){
                i=i-1;
            }else{
                i=swap_child;
            }
        }else{
            i=i-1;
        }
    }
    ofstream screen; //Εγραφή του πίνακα στο αρχείο temp.//
    screen.open("temp.txt");
    for(i=0;i<NrOfEl;i++){
        screen<<setprecision(2)<<fixed<<pmaxheap[i]<<endl;
    }
    screen.close();
}

int maxheap::getsize(){ //Συνάρτηση που επιστρέφει τον αριθμό των στοιχείων του σωρού μεγίστων, δηλαδή τον αριθμό των στοιχείων το πίνακα.//
    return NrOfEl;
}

float maxheap::findmax(){ //Συνάρτηση που επιστρέφει το μεγαλύτερο στοιχείο του σωρού μεγίστων, δηλαδή το πρώτο στοιχείο του πίνακα.//
    return pmaxheap[0];
}

void maxheap::insertion(float x){ //Συνάρτηση είσαγωγής στοιχείου στον σωρό μεγίστων.//
    int nrOfEl=NrOfEl+1; //Κατάλληλη μετατροπή του πίνακα για την εισαγωγή του νέου στοιχείου.//
    float *temparray=new float[nrOfEl];
    for(int i=0;i<NrOfEl;i++){
        temparray[i]=pmaxheap[i];
    }
    temparray[nrOfEl-1]=x;
    delete[] pmaxheap;
    pmaxheap=temparray;
    NrOfEl=nrOfEl;
    int i=floor((NrOfEl-2)/2); //Κατασκευή του σωρού μεγίστων(αντιμετάθεση των στοιχείων του πίνακα για να πετύχουμε το επιθυμητό αποτέλεσμα).//
    float temp;
    int swap_child=NrOfEl;
    bool done_swap = true;
    while((done_swap)||(i>=0)){
        done_swap=false;
        if(((2*i)+2)<=(NrOfEl-1)){
            if(pmaxheap[(2*i)+1]>pmaxheap[(2*i)+2]){
                if (pmaxheap[(2*i)+1]>pmaxheap[i]){
                    temp=pmaxheap[(2*i)+1];
                    pmaxheap[(2*i)+1]=pmaxheap[i];
                    pmaxheap[i]=temp;
                    done_swap=true;
                    swap_child=(2*i)+1;
                }
            }
            else{
                if(pmaxheap[(2*i)+2]>pmaxheap[i]){
                    temp=pmaxheap[(2*i)+2];
                    pmaxheap[(2*i)+2]=pmaxheap[i];
                    pmaxheap[i]=temp;
                    done_swap=true;
                    swap_child=(2*i)+2;
                }
            }
        }
        else{
            if(pmaxheap[(2*i)+1]>pmaxheap[i]){
                temp=pmaxheap[(2*i)+1];
                pmaxheap[(2*i)+1]=pmaxheap[i];
                pmaxheap[i]=temp;
                done_swap=true;
                swap_child=(2*i)+1;
            }
        }
        if(done_swap){
            if(((swap_child*2)+1)>(NrOfEl-1)){
                i=i-1;
            }else{
                i=swap_child;
            }
        }else{
            i=i-1;
        }
    }
    ofstream screen; //Εγραφή του πίνακα στο αρχείο temp.//
    screen.open("temp.txt");
    for(i=0;i<NrOfEl;i++){
        screen<<setprecision(2)<<fixed<<pmaxheap[i]<<endl;
    }
    screen.close();
}

void maxheap::deletion(){ //Συνάρτηση διαγραφής στοιχείου από τον σωρό μεγίστων.//
    swap(pmaxheap[0],pmaxheap[NrOfEl-1]); //Κατάλληλη μετατροπή του πίνακα για την διαγραφή του στοιχείου.//
    int nrOfEl=NrOfEl-1;
    float *temparray=new float[nrOfEl];
    for(int i=0;i<nrOfEl;i++){
        temparray[i]=pmaxheap[i];
    }
    delete[] pmaxheap;
    pmaxheap=temparray;
    NrOfEl=nrOfEl;
    int i=floor((NrOfEl-2)/2); //Κατασκευή του σωρού μεγίστων(αντιμετάθεση των στοιχείων του πίνακα για να πετύχουμε το επιθυμητό αποτέλεσμα).//
    float temp;
    int swap_child=NrOfEl;
    bool done_swap = true;
    while((done_swap)||(i>=0)){
        done_swap=false;
        if(((2*i)+2)<=(NrOfEl-1)){
            if(pmaxheap[(2*i)+1]>pmaxheap[(2*i)+2]){
                if (pmaxheap[(2*i)+1]>pmaxheap[i]){
                    temp=pmaxheap[(2*i)+1];
                    pmaxheap[(2*i)+1]=pmaxheap[i];
                    pmaxheap[i]=temp;
                    done_swap=true;
                    swap_child=(2*i)+1;
                }
            }
            else{
                if(pmaxheap[(2*i)+2]>pmaxheap[i]){
                    temp=pmaxheap[(2*i)+2];
                    pmaxheap[(2*i)+2]=pmaxheap[i];
                    pmaxheap[i]=temp;
                    done_swap=true;
                    swap_child=(2*i)+2;
                }
            }
        }
        else{
            if(pmaxheap[(2*i)+1]>pmaxheap[i]){
                temp=pmaxheap[(2*i)+1];
                pmaxheap[(2*i)+1]=pmaxheap[i];
                pmaxheap[i]=temp;
                done_swap=true;
                swap_child=(2*i)+1;
            }
        }
        if(done_swap){
            if(((swap_child*2)+1)>(NrOfEl-1)){
                i=i-1;
            }else{
                i=swap_child;
            }
        }else{
            i=i-1;
        }
    }
    ofstream screen; //Εγραφή του πίνακα στο αρχείο temp.//
    screen.open("temp.txt");
    for(i=0;i<NrOfEl;i++){
        screen<<setprecision(2)<<fixed<<pmaxheap[i]<<endl;
    }
    screen.close();
}