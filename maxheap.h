#ifndef C___MAXHEAP_H
#define C___MAXHEAP_H

#include <string>

using namespace std;

class maxheap {
public:
    maxheap(); //Κατασκευαστής.//
    maxheap(int sum,string filename); //Κατασκευαστής.//
    ~maxheap(); //Καταστροφέας.//

    int getNrOfEl() {return NrOfEl;}
    void setNrOfEl(int value) {NrOfEl=value;}
    string getfile() {return file;}
    void setfile(string value) {file=value;}

    void build(); //Συνάστηση για την δημιουργία του σωρού μεγίστων.//
    float findmax(); //Συνάστηση για την εύρεση του μεγαλύτερου στοιχείου στον σωρό μεγίστων.//
    int getsize(); //Συνάρτηση για την εύρεση του αριθμού των στοιχείων του σωρού μεγίστων.//
    void insertion(float x); //Συνάρτηση για την εισαγωγή νέου στοιχείου στον σωρό μεγίστων.//
    void deletion(); //Συνάρτηση για την διαγραφή εωός στοιχείου στον σωρό μεγίστων.//

protected:

private:
    int NrOfEl; //Αριθμός των στοιχείων.//
    float *pmaxheap; //Πίνακας για την υλοποίηση του σωρού μεγίστων.//
    string file; //Το όνομα του αρχείου που περιέχει τα δεδομένα για τον σωρό μεγίστων.//
};


#endif //C___MAXHEAP_H