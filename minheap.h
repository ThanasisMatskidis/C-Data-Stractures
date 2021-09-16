#ifndef C___MINHEAP_H
#define C___MINHEAP_H

#include <string>
#include <fstream>

using namespace std;

class minheap {
public:
    minheap(); //Κατασκευαστής.//
    minheap(int sum,string filename); //Κατασκευαστής.//
    ~minheap(); //Καταστροφέας.//

    int getNrOfEl() {return NrOfEl;}
    void setNrOfEl(int value) {NrOfEl=value;}
    string getfile() {return file;}
    void setfile(string value) {file=value;}

    void build(); //Συνάστηση για την δημιουργία του σωρού ελαχίστων.//
    int findmin(); //Συνάστηση για την εύρεση του μεγαλύτερου στοιχείου στον σωρό ελαχίστων.//
    int getsize(); //Συνάρτηση για την εύρεση του αριθμού των στοιχείων του σωρού ελαχίστων.//
    void insertion(float x); //Συνάρτηση για την εισαγωγή νέου στοιχείου στον σωρό ελαχίστων.//
    void deletion(); //Συνάρτηση για την διαγραφή εωός στοιχείου στον σωρό ελαχίστων.//

protected:

private:
    int NrOfEl; //Αριθμός των στοιχείων.//
    float *pminheap; //Πίνακας για την υλοποίηση του σωρού ελαχίστων.//
    string file; //Το όνομα του αρχείου που περιέχει τα δεδομένα για τον σωρό ελαχίστων.//
};


#endif //C___MINHEAP_H
