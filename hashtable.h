#ifndef C___HASHTABLE_H
#define C___HASHTABLE_H

#include <vector>

using namespace std;

class hashtable {
public:
    hashtable(); //Κατασκευαστής.//
    void insert(float x); //Συνάρτηση εισαγωγής νέου στοιχείου στον Hashtable.//
    void write(); //Συνάρτηση για την εγγραφή των αποτελεσμάτων.//
    int getsize(); //Συνάρτηση για την εύρεση του πλήθους των στοιχείων του hashtable.//
    int search(float x); //Συνάρτηση για την αναζήτηση στοιχείου στον Hashtable.//

private:
    vector<float> htable[10]; //Πίνακας 10 θέσεων που αποτελείται από vector.//
    int hashfunction(float x); //Συνάρτηση κατακερματισμού.//
};


#endif //C___HASHTABLE_H
