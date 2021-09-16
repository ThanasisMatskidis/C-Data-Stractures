#include "AVLtree.h"
#include <fstream>
#include <iomanip>

void AVLtree::initialize(node* k){ //Αρχικοποίηση του δέντρου AVL.//
    if(k==NULL){
        return;
    }
    initialize(k->leftchild);
    initialize(k->rightchild);
    delete k;
}

int AVLtree::height(node *k){ //Συνάρτηση που υπολογίζει και επιστρέφει το ύψος του κόμβου.//
    if(k==NULL){
        return -1;
    }
    else{
        return k->height;
    }
}

void AVLtree::preorder(node* k){ //Συνάρτηση για την εγγραφή του δέντρου AVL στο αρχείο temp με προδιατεταγμένη διάσχιση.//
    if(k==NULL){
        return;
    }
    ofstream screen; //Εγραφή του δέντρου AVL στο αρχείο temp.//
    screen.open("temp.txt",fstream::app);
    screen<<setprecision(2)<<fixed<<k->key<<endl;
    screen.close();
    preorder(k->leftchild);
    preorder(k->rightchild);
}

int AVLtree::NrOfEl(node *k){ //Συνάρτηση που υπολογίζει τον αριθμό των κόμβων του δέντρου AVL.//
    if(k!=NULL){
        return NrOfEl(k->leftchild)+NrOfEl(k->rightchild)+1;
    }
    else{
        return 0;
    }
}

AVLtree::AVLtree(){ //Κατασκευαστής.//
    root=NULL;
}

void AVLtree::insert(float a){ //Εισαγωγή νέου κόμβου στο δέντρο AVL.//
    root=insertion(a,root);
}

void AVLtree::deletenm(float a){ //Διαγραφή κόμβου από το δέντρο AVL.//
    root=deletion(a,root);
}

void AVLtree::write(){ //Εγγραφή του δέντρου AVL στο αρχείο temp(χρησιμοποιώντας την συνάρτηση preorder).//
    ofstream screen;
    screen.open("temp.txt",ofstream::out|ofstream::trunc); //Εγγραφή στο αρχείο temp χωρίς να διαγραφούν τα προηγούμενα.//
    screen.close();
    preorder(root);
}

int AVLtree::getsize(){ //Αριθμός κόμβων του δέντρου AVL(χρησιμοποιώντας τη συνάρτηση NrOfEl).//
    return NrOfEl(root);
}

float AVLtree::findmin(){ //Εύρεση μικρότερου στοιχείου στο δέντρο AVL(χρησιμοποιώντας την συνάρτηση minimumEl).//
    return minimumEl(root)->key;
}

int AVLtree::search(float a){ //Αναζήτηση στοιχείου στο δέντρο AVL.//
    if(search(a,root)==0){
        return 0;
    }
    else{
        return 1;
    }
}