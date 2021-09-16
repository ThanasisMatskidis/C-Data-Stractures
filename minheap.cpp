#include "minheap.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>

minheap::minheap(){
    NrOfEl=0;
    file=" ";
}

minheap::minheap(int sum,string filename){
    NrOfEl=sum;
    file=filename;
}

minheap::~minheap(){
    delete[] pminheap;
}

void minheap::build(){ //Συνάρτηση κατασκευής του σωρού ελαχίστων.//
    pminheap=new float[NrOfEl];
    ifstream data;
    data.open(file);
    int i=0;
    string lines;
    while(getline(data,lines)){ //Αρχικοποίηση του πίνακα με τα δεδομένα του αρχείου.//
        pminheap[i]=stof(lines);
        i++;
    }
    i=(NrOfEl-2)/2; //Κατασκευή του σωρού ελαχίστων(αντιμετάθεση των στοιχείων του πίνακα για να πετύχουμε το επιθυμητό αποτέλεσμα).//
    float temp;
    int swap_child=NrOfEl;
    bool done_swap = true;
    while((done_swap)||(i>=0)){
        done_swap=false;
        if(((2*i)+2)<=(NrOfEl-1)){
            if(pminheap[(2*i)+1]<pminheap[(2*i)+2]){
                if(pminheap[(2*i)+1]<pminheap[i]){
                    temp=pminheap[(2*i)+1];
                    pminheap[(2*i)+1]=pminheap[i];
                    pminheap[i]=temp;
                    done_swap=true;
                    swap_child=(2*i)+1;
                }
            }
            else{
                if(pminheap[(2*i)+2]<pminheap[i]){
                    temp=pminheap[(2*i)+2];
                    pminheap[(2*i)+2]=pminheap[i];
                    pminheap[i]=temp;
                    done_swap=true;
                    swap_child=(2*i)+2;
                }
            }
        }
        else{
            if(pminheap[(2*i)+1]<pminheap[i]){
                temp=pminheap[(2*i)+1];
                pminheap[(2*i)+1]=pminheap[i];
                pminheap[i]=temp;
                done_swap=true;
                swap_child=2*i+1;
            }
        }
        if(done_swap){
            if(((swap_child*2)+1)>(NrOfEl-1)){
                i=i-1;
            }
            else{
                i=swap_child;
            }
        }
        else{
            i=i-1;
        }
    }
    ofstream screen; //Εγραφή του πίνακα στο αρχείο temp.//
    screen.open("temp.txt");
    for(i=0;i<NrOfEl;i++){
        screen<<setprecision(2)<<fixed<<pminheap[i]<<endl;
    }
    screen.close();
}

int minheap::getsize(){ //Συνάρτηση που επιστρέφει τον αριθμό των στοιχείων του σωρού ελαχίστων, δηλαδή τον αριθμό των στοιχείων το πίνακα.//
    return NrOfEl;
}

int minheap::findmin(){ //Συνάρτηση που επιστρέφει το μικρότερο στοιχείο του σωρού ελαχίστων, δηλαδή το πρώτο στοιχείο του πίνακα.//
    return pminheap[0];
}

void minheap::insertion(float x){ //Συνάρτηση είσαγωγής στοιχείου στον σωρό ελαχίστων.//
    int nrOfEl=NrOfEl+1; //Κατάλληλη μετατροπή του πίνακα για την εισαγωγή του νέου στοιχείου.//
    float *temparray=new float[nrOfEl];
    for(int i=0;i<NrOfEl;i++){
        temparray[i]=pminheap[i];
    }
    temparray[nrOfEl-1]=x;
    delete[] pminheap;
    pminheap=temparray;
    NrOfEl=nrOfEl;
    int i=(NrOfEl-2)/2; //Κατασκευή του σωρού ελαχίστων(αντιμετάθεση των στοιχείων του πίνακα για να πετύχουμε το επιθυμητό αποτέλεσμα).//
    float temp;
    int swap_child=NrOfEl;
    bool done_swap = true;
    while((done_swap)||(i>=0)){
        done_swap=false;
        if(((2*i)+2)<=(NrOfEl-1)){
            if(pminheap[(2*i)+1]<pminheap[(2*i)+2]){
                if(pminheap[(2*i)+1]<pminheap[i]){
                    temp=pminheap[(2*i)+1];
                    pminheap[(2*i)+1]=pminheap[i];
                    pminheap[i]=temp;
                    done_swap=true;
                    swap_child=(2*i)+1;
                }
            }
            else{
                if(pminheap[(2*i)+2]<pminheap[i]){
                    temp=pminheap[(2*i)+2];
                    pminheap[(2*i)+2]=pminheap[i];
                    pminheap[i]=temp;
                    done_swap=true;
                    swap_child=(2*i)+2;
                }
            }
        }
        else{
            if(pminheap[(2*i)+1]<pminheap[i]){
                temp=pminheap[(2*i)+1];
                pminheap[(2*i)+1]=pminheap[i];
                pminheap[i]=temp;
                done_swap=true;
                swap_child=2*i+1;
            }
        }
        if(done_swap){
            if(((swap_child*2)+1)>(NrOfEl-1)){
                i=i-1;
            }
            else{
                i=swap_child;
            }
        }
        else{
            i=i-1;
        }
    }
    ofstream screen; //Εγραφή του πίνακα στο αρχείο temp.//
    screen.open("temp.txt");
    for(int i=0;i<NrOfEl;i++){
        screen<<setprecision(2)<<fixed<<pminheap[i]<<endl;
    }
    screen.close();
}

void minheap::deletion(){ //Συνάρτηση διαγραφής στοιχείου από τον σωρό ελαχίστων.//
    swap(pminheap[0],pminheap[NrOfEl-1]); //Κατάλληλη μετατροπή του πίνακα για την διαγραφή του στοιχείου.//
    int nrOfEl=NrOfEl-1;
    float *temparray=new float[nrOfEl];
    for(int i=0;i<nrOfEl;i++){
        temparray[i]=pminheap[i];
    }
    delete[] pminheap;
    pminheap=temparray;
    NrOfEl=nrOfEl;
    int i=(NrOfEl-2)/2; //Κατασκευή του σωρού ελαχίστων(αντιμετάθεση των στοιχείων του πίνακα για να πετύχουμε το επιθυμητό αποτέλεσμα).//
    float temp;
    int swap_child=NrOfEl;
    bool done_swap = true;
    while((done_swap)||(i>=0)){
        done_swap=false;
        if(((2*i)+2)<=(NrOfEl-1)){
            if(pminheap[(2*i)+1]<pminheap[(2*i)+2]){
                if(pminheap[(2*i)+1]<pminheap[i]){
                    temp=pminheap[(2*i)+1];
                    pminheap[(2*i)+1]=pminheap[i];
                    pminheap[i]=temp;
                    done_swap=true;
                    swap_child=(2*i)+1;
                }
            }
            else{
                if(pminheap[(2*i)+2]<pminheap[i]){
                    temp=pminheap[(2*i)+2];
                    pminheap[(2*i)+2]=pminheap[i];
                    pminheap[i]=temp;
                    done_swap=true;
                    swap_child=(2*i)+2;
                }
            }
        }
        else{
            if(pminheap[(2*i)+1]<pminheap[i]){
                temp=pminheap[(2*i)+1];
                pminheap[(2*i)+1]=pminheap[i];
                pminheap[i]=temp;
                done_swap=true;
                swap_child=2*i+1;
            }
        }
        if(done_swap){
            if(((swap_child*2)+1)>(NrOfEl-1)){
                i=i-1;
            }
            else{
                i=swap_child;
            }
        }
        else{
            i=i-1;
        }
    }
    ofstream screen; //Εγραφή του πίνακα στο αρχείο temp.//
    screen.open("temp.txt");
    for(int i=0;i<NrOfEl;i++){
        screen<<setprecision(2)<<fixed<<pminheap[i]<<endl;
    }
    screen.close();
}