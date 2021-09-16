#ifndef C___AVLTREE_H
#define C___AVLTREE_H


#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

class AVLtree {
public:
    AVLtree(); //Κατσκευαστής.//
    void insert(float a); //Συνάρτηση για την εισαγωγή στοιχείου-κόμβου στο δέντρο AVL.//
    void deletenm(float a); //Συνάρτηση για την διαγραφή στοιχείου-κόμβου στο δέντρο AVL.//
    void write(); //Συνάρτηση για την εγγραφή των αποτελεσμάτων.//
    int getsize(); //Συνάρτηση για το πλήθος των στοιχείων του δέντρου AVL.//
    float findmin(); //Συνάρτηση για την εύρεση του μικρότερου στοιχείου στο δέντρο AVL.//
    int search(float a); //Συνάρτηση για την αναζήτηση στοιχείου στο δέντρο AVL.//

private:
    struct node{
        float key; //Μεταβλητή όπου αποθηκεύεται το κλειδί κόμβου.//
        node* leftchild; //Pointer που "δείχνει" στο αριστερό παιδί του κόμβου.//
        node* rightchild; //Pointer που "δείχνει" στο δεξί παιδί του κόμβου.//
        int height; //Μεταβλητή όπου αποθηκεύεται η τιμή που δείχνει σε ποιο ύψος βρίσκεται ο κόμβος.//
    };
    node* root;
    void initialize(node* k); //Συνάρτηση αρχικοποίησης των κόμβων.//
    int height(node* k); //Συνάρτηση για το ύψος του δέντρου.//
    void preorder(node* k); //Συνάρτηση για την εγγραφή του δέντρο AVL στο αρχείο temp με προδιατεταγμένη διάσχιση.//
    int NrOfEl(node* k); //Συνάρτηση που μετράει και επιστρέφει τον αριθμό των κόμβων.//
    node* singleRR(node* &k){ //Συνάρτηση για απλή δεξιά περιστροφή κόμβων(Εναλλάσσοντας κατάλληλα τους δείκτες).//
        node* x=k->leftchild;
        k->leftchild=x->rightchild;
        x->rightchild=k;
        k->height=max(height(k->leftchild),height(k->rightchild))+1;
        x->height=max(height(k->rightchild),k->height)+1;
        return x;
    }
    node* singleLR(node* &k){ //Συνάρτηση για απλή αριστερή περιστροφή κόμβων(Εναλλάσσοντας κατάλληλα τους δείκτες).//
        node* x=k->rightchild;
        k->rightchild=x->leftchild;
        x->leftchild=k;
        k->height=max(height(k->leftchild),height(k->rightchild))+1;
        x->height=max(height(k->rightchild),k->height)+1;
        return x;
    }
    node* doubleRR(node* &k){ //Συνάρτηση για την διπλή δεξιά περιστροφή κόμβων(Εναλλάσσοντας κατάλληλα τους δείκτες).//
        k->leftchild=singleLR(k->leftchild);
        return singleRR(k);
    }
    node* doubleLR(node* &k){ //Συνάρτηση για την διπλή αριστερή περιστροφή κόμβων(Εναλλάσσοντας κατάλληλα τους δείκτες).//
        k->rightchild=singleRR(k->rightchild);
        return singleLR(k);
    }
    node* insertion(float a,node* k){ //Συνάρτηση εισαγωγής νέου στοιχείου-κόμβου.//
        if(k==NULL){ //Περίπτωση όπου ο κόμβος είναι κενός και εισάγεται ο αριθμός.//
            k=new node;
            k->key=a;
            k->height=0;
            k->leftchild=k->rightchild=NULL;
        }
        else if(a<k->key){ //Περίπτωση όπου ο αριθμός προς εισαωγή είναι μικρότερος από τον γονέα.//
            k->leftchild=insertion(a,k->leftchild);
            if((height(k->leftchild)-height(k->rightchild))==2){
                if(a<k->leftchild->key){
                    k=singleRR(k);
                }
                else{
                    k=doubleRR(k);
                }
            }
        }
        else if(a>k->key){ //Περίπτωση όπου ο αριθμός προς εισαωγή είναι μεγαλύτερος από τον γονέα.//
            k->rightchild=insertion(a,k->rightchild);
            if((height(k->rightchild)-height(k->leftchild))==2){
                if(a>k->rightchild->key){
                    k=singleLR(k);
                }
                else{
                    k=doubleLR(k);
                }
            }
        }
        k->height=max(height(k->leftchild),height(k->rightchild))+1;
        return k;
    }
    node* findMin(node* k){ //Συνάρτηση που επιστρέφει τον pointer που δείχνει στον κόμβο που περιέχει το μικρότερο στοιχείο.//
        if(k==NULL){
            return NULL;
        }
        else if(k->leftchild==NULL){
            return k;
        }
        else{
            return findMin(k->rightchild);
        }
    }
    node* deletion(float a,node*k){ //Συνάρτηση διαγραφής στοιχείου-κόμβου από το δέντρο AVL.//
        node* x;
        if(k==NULL){ //Περίπτωση όπου το στοιχείο δεν υπάρχει.//
            return NULL;
        }
        else if(a>k->key){ //Αναζήτηση του στοιχείου σε περίπτωση που ο γενέας έχει δύο παιδιά.//
            k->rightchild=deletion(a,k->rightchild);
        }
        else if(a<k->key){
            k->leftchild=deletion(a,k->leftchild);
        }
        else if(k->rightchild&&k->leftchild){
            x=findMin(k->rightchild);
            k->key=x->key;
            k->rightchild=deletion(k->key,k->rightchild);
        }
        else{ //Αναζήτηση του στοιχείου σε περίπτωση που ο γενέας έχει ένα ή κανένα παιδί.//
            x=k;
            if(k->rightchild==NULL){
                k=k->leftchild;
            }
            else if(k->leftchild==NULL){
                k=k->rightchild;
            }
            delete x;
        }
        if(k==NULL){
            return k;
        }
        k->height=max(height(k->leftchild),height(k->rightchild))+1; //"Ενημέρωση" του ύψους του δέντρου.//
        if((height(k->leftchild)-height(k->rightchild))==-2){ //Μετατροπή του νέου δέντρου σε δέντρο AVL(εξισορρόπηση).//
            if((height(k->rightchild->rightchild)-height(k->rightchild->leftchild))==1){
                return singleLR(k);
            }
            else{
                return doubleLR(k);
            }
        }
        else if((height(k->rightchild)-height(k->leftchild))==2){
            if((height(k->leftchild->leftchild)-height(k->leftchild->rightchild))==1){
                return singleRR(k);
            }
            else{
                return doubleRR(k);
            }
        }
        return k;
    }
    node* search(float a,node* k){ //Συνάρτηση αναζήτησης στοιχείου στο δέντρο AVL.//
        if(a==k->key){
            return k;
        }
        else if(a<k->key){
            if((k->leftchild)!=NULL){
                search(a,k->leftchild);
            }
            else{
                return 0;
            }
        }
        else{
            if((k->rightchild)!=NULL){
                search(a,k->rightchild);
            }
            else{
                return 0;
            }
        }
    }
    node* minimumEl(node* k){ //Συνάρτηση εύρεσης του μικρότερου στοιχείου στο δέντρο AVL.//
        if(k==NULL){
            return k;
        }
        else if(k->leftchild==NULL){
            return k;
        }
        else if(k->leftchild!=NULL){
            minimumEl(k->leftchild);
        }
    }
};


#endif //C___AVLTREE_H
