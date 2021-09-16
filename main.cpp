#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <chrono>
#include "cmake-build-debug/minheap.h"
#include "cmake-build-debug/maxheap.h"
#include "cmake-build-debug/AVLtree.h"
#include "cmake-build-debug/hashtable.h"

using namespace std;
using namespace std::chrono;

int main() {
    ifstream file("commands.txt"); //Άνοιγμα του αρχείου που περιέχει τις εντολές για διάβασμα.//
    ofstream screen; //Άνοιγμα του αρχείου output, για εγγραφή, στο οποίο θα εμφανίσουμε τα αποτελέσματα.//
    screen.open("output.txt");

    if(file.is_open()){
        string line;
        minheap mnheap;
        maxheap mxheap;
        AVLtree AVL;
        hashtable hash;
        while(getline(file,line)){ //Ανάγνωση του αρχείου με τις εντολές γραμή προς γραμμή, όπου σε κάθε γραμμή ελέγχουμε ποια εντολή έχουμε.//
            string c1="BUILD";
            string c2="GETSIZE";
            string c3="FINDMIN";
            string c4="FINDMAX";
            string c5="SEARCH";
            string c6="INSERT";
            string c7="DELETEMIN";
            string c8="DELETEMAX";
            string c9="DELETE";
            string s1="MINHEAP";
            string s2="MAXHEAP";
            string s3="AVLTREE";
            string s4="HASHTABLE";
            if(strstr(line.c_str(),c1.c_str())){
                int sum=0;
                if(strstr(line.c_str(),s1.c_str())){
                   size_t pos=line.size();
                   string filename=line.substr(line.find_last_of(' ',pos)); //Παίρνουμε την τελευταία λέξη της γραμμής που διαβάστηκε σε μία μεταβλητή τύπου string.//
                   filename.erase(remove(filename.begin(),filename.end(),' '),filename.end()); //Αφαιρούμε από αυτήν τυχόν κενά.//
                   ifstream data; //Ανοίγουμε το αρχέιου που περιέχει τα δεδομένα για διάβασμα.//
                   data.open(filename);
                   if(data.is_open()){
                       string lines;
                       while(getline(data,lines)){ //Μετράμε πόσα δεδομένα υπάρχουν μετρώντας τις σειρές του αρχείου αφού κάθε δεδομένο καταλαμβάνει και μία σειρά.//
                           sum+=1;
                       }
                       mnheap.setNrOfEl(sum); //"Περνάμε" στην κλάση τον αριθμό των σειρών και κατ' επέκταση των δεδομένων.//
                       mnheap.setfile(filename);//"Περνάμε" στην κλάση το όνομα του αρχείου που περιέχει τα δεδομένα.//
                       auto start=high_resolution_clock::now();
                       mnheap.build(); //Συνάρτηση για το χτίσιμο του σωρού ελαχίστων.//
                       auto stop=high_resolution_clock::now();
                       auto duration=duration_cast<microseconds>(stop-start);
                       ifstream tempfile("temp.txt"); //Αντιγραφή των περιεχωμένων του αρχείου temp στο αρχείο output.//
                       string temp;
                       screen<<"MINHEAP: "<<endl;
                       while(tempfile.good()){
                           getline(tempfile,temp);
                           screen<<temp<<endl;
                       }
                       screen<<"Minheap build time: "<<duration.count()<<" microseconds."<<endl<<endl;
                   }
                   else{
                       cout<<"ERROR! Can not find the data file.("<<line<<")"<<endl;
                   }
                }
                else if(strstr(line.c_str(),s2.c_str())){
                    size_t pos=line.size();
                    string filename=line.substr(line.find_last_of(' ',pos)); //Παίρνουμε την τελευταία λέξη της γραμμής που διαβάστηκε σε μία μεταβλητή τύπου string.//
                    filename.erase(remove(filename.begin(),filename.end(),' '),filename.end()); //Αφαιρούμε από αυτήν τυχόν κενά.//
                    ifstream data; //Ανοίγουμε το αρχέιου που περιέχει τα δεδομένα για διάβασμα.//
                    data.open(filename);
                    if(data.is_open()){
                        string lines;
                        while(getline(data,lines)){ //Μετράμε πόσα δεδομένα υπάρχουν μετρώντας τις σειρές του αρχείου αφού κάθε δεδομένο καταλαμβάνει και μία σειρά.//
                            sum+=1;
                        }
                        mxheap.setNrOfEl(sum); //"Περνάμε" στην κλάση τον αριθμό των σειρών και κατ' επέκταση των δεδομένων.//
                        mxheap.setfile(filename); //"Περνάμε" στην κλάση το όνομα του αρχείου που περιέχει τα δεδομένα.//
                        auto start=high_resolution_clock::now();
                        mxheap.build(); //Συνάρτηση για το χτίσιμο του σωρού μεγίστων.//
                        auto stop=high_resolution_clock::now();
                        auto duration=duration_cast<microseconds>(stop-start);
                        ifstream tempfile("temp.txt"); //Αντιγραφή των περιεχωμένων του αρχείου temp στο αρχείο output.//
                        string temp;
                        screen<<"MAXHEAP: "<<endl;
                        while(tempfile.good()){
                            getline(tempfile,temp);
                            screen<<temp<<endl;
                        }
                        screen<<"Maxheap build time: "<<duration.count()<<" microseconds."<<endl<<endl;
                    }
                    else{
                        cout<<"ERROR! Can not find the data file.("<<line<<")"<<endl;
                    }
                }
                else if(strstr(line.c_str(),s3.c_str())){
                    size_t pos=line.size();
                    string filename=line.substr(line.find_last_of(' ',pos)); //Παίρνουμε την τελευταία λέξη της γραμμής που διαβάστηκε σε μία μεταβλητή τύπου string.//
                    filename.erase(remove(filename.begin(),filename.end(),' '),filename.end()); //Αφαιρούμε από αυτήν τυχόν κενά.//
                    ifstream data; //Ανοίγουμε το αρχέιου που περιέχει τα δεδομένα για διάβασμα.//
                    data.open(filename);
                    if(data.is_open()){
                        string lines;
                        float x;
                        auto start=high_resolution_clock::now();
                        while(getline(data,lines)){
                            x=stof(lines); //Μετατροπή της μεταβλητής τύπου string(που περιέχει το δεδομένο) σε μεταβλητή τύπου float.//
                            AVL.insert(x); //Συνάρτηση για εισαγωγή του στοιχείου στο δέντρο AVL.//
                        }
                        auto stop=high_resolution_clock::now();
                        auto duration=duration_cast<microseconds>(stop-start);
                        AVL.write(); //Συνάρτηση για να γραφεί το αποτέλεσμα στο αρχείο temp.//
                        ifstream tempfile("temp.txt"); //Αντιγραφή των περιεχωμένων του αρχείου temp στο αρχείο output.//
                        string temp;
                        screen<<"AVL(preorder): "<<endl;
                        while(tempfile.good()){
                            getline(tempfile,temp);
                            screen<<temp<<endl;
                        }
                        screen<<"AVL tree build time: "<<duration.count()<<" microseconds."<<endl<<endl;
                    }
                    else{
                        cout<<"ERROR! Can not find the data file.("<<line<<")"<<endl;
                    }
                }
                else if(strstr(line.c_str(),s4.c_str())){
                    size_t pos=line.size();
                    string filename=line.substr(line.find_last_of(' ',pos)); //Παίρνουμε την τελευταία λέξη της γραμμής που διαβάστηκε σε μία μεταβλητή τύπου string.//
                    filename.erase(remove(filename.begin(),filename.end(),' '),filename.end()); //Αφαιρούμε από αυτήν τυχόν κενά.//
                    ifstream data; //Ανοίγουμε το αρχέιου που περιέχει τα δεδομένα για διάβασμα.//
                    data.open(filename);
                    if(data.is_open()) {
                        string lines;
                        float x;
                        auto start=high_resolution_clock::now();
                        while (getline(data, lines)) {
                            x = stof(lines); //Μετατροπή της μεταβλητής τύπου string(που περιέχει το δεδομένο) σε μεταβλητή τύπου float.//
                            hash.insert(x); //Συνάρτηση για εισαγωγή του στοιχείου στον Hashtable.//
                        }
                        auto stop=high_resolution_clock::now();
                        auto duration=duration_cast<microseconds>(stop-start);
                        hash.write(); //Συνάρτηση για να γραφεί το αποτέλεσμα στο αρχείο temp.//
                        ifstream tempfile("temp.txt"); //Αντιγραφή των περιεχωμένων του αρχείου temp στο αρχείο output.//
                        string temp;
                        screen<<"HASHTABLE: "<<endl;
                        while(tempfile.good()){
                            getline(tempfile,temp);
                            screen<<temp<<endl;
                        }
                        screen<<"Hashtale build time: "<<duration.count()<<" microseconds."<<endl<<endl;
                    }
                    else{
                        cout<<"ERROR! Can not find the data file.("<<line<<")"<<endl;
                    }
                }
                else{
                    cout<<"Invalid command.("<<line<<")"<<endl;
                }
            }
            else if(strstr(line.c_str(),c2.c_str())){
                if(strstr(line.c_str(),s1.c_str())){
                    auto start=high_resolution_clock::now();
                    screen<<"The size of the minheap is: "<<mnheap.getsize()<<endl<<endl; //Γράφουμε στο αρχείο output το αποτέλεσμα της συνάρτησης που επιστρέφει το πλήθος των στοιχείων του σωρού ελαχιστων.//
                    auto stop=high_resolution_clock::now();
                    auto duration=duration_cast<microseconds>(stop-start);
                    screen<<"Get the size of Minheap in: "<<duration.count()<<" microseconds."<<endl<<endl;
                }
                else if(strstr(line.c_str(),s2.c_str())){
                    auto start=high_resolution_clock::now();
                    screen<<"The size of the maxheap is: "<<mxheap.getsize()<<endl<<endl; //Γράφουμε στο αρχείο output το αποτέλεσμα της συνάρτησης που επιστρέφει το πλήθος των στοιχείων του σωρού μεγίστων.//
                    auto stop=high_resolution_clock::now();
                    auto duration=duration_cast<microseconds>(stop-start);
                    screen<<"Get the size of Maxheap in: "<<duration.count()<<" microseconds."<<endl<<endl;
                }
                else if(strstr(line.c_str(),s3.c_str())){
                    auto start=high_resolution_clock::now();
                    screen<<"The size of the AVL is: "<<AVL.getsize()<<endl<<endl; //Γράφουμε στο αρχείο output το αποτέλεσμα της συνάρτησης που επιστρέφει το πλήθος των στοιχείων του δέντρου AVL.//
                    auto stop=high_resolution_clock::now();
                    auto duration=duration_cast<microseconds>(stop-start);
                    screen<<"Get the size of AVL tree in: "<<duration.count()<<" microseconds."<<endl<<endl;
                }
                else if(strstr(line.c_str(),s4.c_str())){
                    auto start=high_resolution_clock::now();
                    screen<<"Hashtable contains: "<<hash.getsize()<<" elements."<<endl<<endl; //Γράφουμε στο αρχείο output το αποτέλεσμα της συνάρτησης που επιστρέφει το πλήθος των στοιχείων του Hashtable.//
                    auto stop=high_resolution_clock::now();
                    auto duration=duration_cast<microseconds>(stop-start);
                    screen<<"Get the size of Hashtable in: "<<duration.count()<<" microseconds."<<endl<<endl;
                }
                else{
                    cout<<"Invalid command.("<<line<<")"<<endl;
                }
            }
            else if(strstr(line.c_str(),c3.c_str())){
                if(strstr(line.c_str(),s1.c_str())) {
                    auto start=high_resolution_clock::now();
                    screen<<"Minimum of MINHEAP: "<<setprecision(2)<<fixed<<mnheap.findmin()<<endl<<endl; //Γράφουμε στο αρχείο output το αποτέλεσμα της συνάρτησης που επιστρέφει το μικρότερο στοιχείο του σωρού ελαχίστων.//
                    auto stop=high_resolution_clock::now();
                    auto duration=duration_cast<microseconds>(stop-start);
                    screen<<"Get the minimum element of Minheap in: "<<duration.count()<<" microseconds."<<endl<<endl;
                }
                else if(strstr(line.c_str(),s3.c_str())){
                    auto start=high_resolution_clock::now();
                    screen<<"Minimum of AVL: "<<setprecision(2)<<fixed<<AVL.findmin()<<endl<<endl; //Γράφουμε στο αρχείο output το αποτέλεσμα της συνάρτησης που επιστρέφει το μικρότερο στοιχείο του δέντρου AVL.//
                    auto stop=high_resolution_clock::now();
                    auto duration=duration_cast<microseconds>(stop-start);
                    screen<<"Get the minimum element of AVL tree in: "<<duration.count()<<" microseconds."<<endl<<endl;
                }
                else{
                    cout<<"Invalid command.("<<line<<")"<<endl;
                }
            }
            else if(strstr(line.c_str(),c4.c_str())){
                if(strstr(line.c_str(),s2.c_str())){
                    auto start=high_resolution_clock::now();
                    screen<<"Max of MAXHEAP: "<<setprecision(2)<<fixed<<mxheap.findmax()<<endl<<endl; //Γράφουμε στο αρχείο output το αποτέλεσμα της συνάρτησης που επιστρέφει το μέγιστο στοιχείο του σωρού μεγίστων.//
                    auto stop=high_resolution_clock::now();
                    auto duration=duration_cast<microseconds>(stop-start);
                    screen<<"Get the max element of Maxheap in: "<<duration.count()<<" microseconds."<<endl<<endl;
                }
                else{
                    cout<<"Invalid command.("<<line<<")"<<endl;
                }
            }
            else if(strstr(line.c_str(),c5.c_str())){
                if(strstr(line.c_str(),s3.c_str())){
                    size_t pos=line.size();
                    string filename=line.substr(line.find_last_of(' ',pos)); //Παίρνουμε την τελευταία λέξη της γραμμής που διαβάστηκε σε μία μεταβλητή τύπου string.//
                    filename.erase(remove(filename.begin(),filename.end(),' '),filename.end()); //Αφαιρούμε από αυτήν τυχόν κενά.//
                    float x=stof(filename); //Μετατροπή της μεταβλητής τύπου string(που περιέχει το δεδομένο) σε μεταβλητή τύπου float.//
                    auto start=high_resolution_clock::now();
                    if(AVL.search(x)){ //Εμφάνιση στο αρχείο output του κατάλληλου αποτελέσματος ανάλογα με την τιμή της συνάρτησης αναζήτησης στο δέντρο AVL.//
                        screen<<"Search for element, with key "<<x<<", in AVL: SUCCESS"<<endl<<endl;
                    }
                    else{
                        screen<<"Search for element, with key "<<x<<", in AVL: FAILURE"<<endl<<endl;
                    }
                    auto stop=high_resolution_clock::now();
                    auto duration=duration_cast<microseconds>(stop-start);
                    screen<<"Search time of "<<x<<" in AVL tree: "<<duration.count()<<" microseconds."<<endl<<endl;
                }
                else if(strstr(line.c_str(),s4.c_str())){
                    size_t pos=line.size();
                    string filename=line.substr(line.find_last_of(' ',pos)); //Παίρνουμε την τελευταία λέξη της γραμμής που διαβάστηκε σε μία μεταβλητή τύπου string.//
                    filename.erase(remove(filename.begin(),filename.end(),' '),filename.end()); //Αφαιρούμε από αυτήν τυχόν κενά.//
                    float x=stof(filename); //Μετατροπή της μεταβλητής τύπου string(που περιέχει το δεδομένο) σε μεταβλητή τύπου float.//
                    auto start=high_resolution_clock::now();
                    if(hash.search(x)){ //Εμφάνιση στο αρχείο output του κατάλληλου αποτελέσματος ανάλογα με την τιμή της συνάρτησης αναζήτησης στον Hashtable.//
                        screen<<"Search for element "<<x<<" in Hashtable: SUCCESS"<<endl<<endl;
                    }
                    else{
                        screen<<"Search for element "<<x<<" in Hashtable: FAILURE"<<endl<<endl;
                    }
                    auto stop=high_resolution_clock::now();
                    auto duration=duration_cast<microseconds>(stop-start);
                    screen<<"Search time of "<<x<<" in Hashtable: "<<duration.count()<<" microseconds."<<endl<<endl;
                }
                else{
                    cout<<"Invalid command.("<<line<<")"<<endl;
                }
            }
            else if(strstr(line.c_str(),c6.c_str())){
                if(strstr(line.c_str(),s1.c_str())){
                    size_t pos=line.size();
                    string filename=line.substr(line.find_last_of(' ',pos)); //Παίρνουμε την τελευταία λέξη της γραμμής που διαβάστηκε σε μία μεταβλητή τύπου string.//
                    filename.erase(remove(filename.begin(),filename.end(),' '),filename.end()); //Αφαιρούμε από αυτήν τυχόν κενά.//
                    float x=stof(filename); //Μετατροπή της μεταβλητής τύπου string(που περιέχει το δεδομένο) σε μεταβλητή τύπου float.//
                    auto start=high_resolution_clock::now();
                    mnheap.insertion(x); //Συνάρτηση για την εισαγωγή του αριθμού στον σωρό ελαχίστων.//
                    auto stop=high_resolution_clock::now();
                    auto duration=duration_cast<microseconds>(stop-start);
                    ifstream tempfile("temp.txt"); //Αντιγραφή των περιεχωμένων του αρχείου temp στο αρχείο output.//
                    string temp;
                    screen<<"MINHEAP after the insertion of "<<x<<": "<<endl;
                    while(tempfile.good()){
                        getline(tempfile,temp);
                        screen<<temp<<endl;
                    }
                    screen<<"Insertion time of "<<x<<" in Minheap: "<<duration.count()<<" microseconds."<<endl<<endl;
                }
                else if(strstr(line.c_str(),s2.c_str())){
                    size_t pos=line.size();
                    string filename=line.substr(line.find_last_of(' ',pos)); //Παίρνουμε την τελευταία λέξη της γραμμής που διαβάστηκε σε μία μεταβλητή τύπου string.//
                    filename.erase(remove(filename.begin(),filename.end(),' '),filename.end()); //Αφαιρούμε από αυτήν τυχόν κενά.//
                    float x=stof(filename); //Μετατροπή της μεταβλητής τύπου string(που περιέχει το δεδομένο) σε μεταβλητή τύπου float.//
                    auto start=high_resolution_clock::now();
                    mxheap.insertion(x); //Συνάρτηση για την εισαγωγή του αριθμού στον σωρό μεγίστων.//
                    auto stop=high_resolution_clock::now();
                    auto duration=duration_cast<microseconds>(stop-start);
                    ifstream tempfile("temp.txt"); //Αντιγραφή των περιεχωμένων του αρχείου temp στο αρχείο output.//
                    string temp;
                    screen<<"MAXHEAP after the insertion of "<<x<<": "<<endl;
                    while(tempfile.good()){
                        getline(tempfile,temp);
                        screen<<temp<<endl;
                    }
                    screen<<"Insertion time of "<<x<<" in Maxheap: "<<duration.count()<<" microseconds."<<endl<<endl;
                }
                else if(strstr(line.c_str(),s3.c_str())){
                    size_t pos=line.size();
                    string filename=line.substr(line.find_last_of(' ',pos)); //Παίρνουμε την τελευταία λέξη της γραμμής που διαβάστηκε σε μία μεταβλητή τύπου string.//
                    filename.erase(remove(filename.begin(),filename.end(),' '),filename.end()); //Αφαιρούμε από αυτήν τυχόν κενά.//
                    float x=stof(filename); //Μετατροπή της μεταβλητής τύπου string(που περιέχει το δεδομένο) σε μεταβλητή τύπου float.//
                    auto start=high_resolution_clock::now();
                    AVL.insert(x); //Συνάρτηση για την εισαγωγή του αριθμού στο δέντρο AVL.//
                    auto stop=high_resolution_clock::now();
                    auto duration=duration_cast<microseconds>(stop-start);
                    AVL.write(); //Συνάρτηση για να γραφεί το αποτέλεσμα στο αρχείο temp.//
                    ifstream tempfile("temp.txt"); //Αντιγραφή των περιεχωμένων του αρχείου temp στο αρχείο output.//
                    string temp;
                    screen<<"AVL(preorder) after the insertion of "<<x<<": "<<endl;
                    while(tempfile.good()){
                        getline(tempfile,temp);
                        screen<<temp<<endl;
                    }
                    screen<<"Insertion time of "<<x<<" in AVL tree: "<<duration.count()<<" microseconds."<<endl<<endl;
                }
                else if(strstr(line.c_str(),s4.c_str())){
                    size_t pos=line.size();
                    string filename=line.substr(line.find_last_of(' ',pos)); //Παίρνουμε την τελευταία λέξη της γραμμής που διαβάστηκε σε μία μεταβλητή τύπου string.//
                    filename.erase(remove(filename.begin(),filename.end(),' '),filename.end()); //Αφαιρούμε από αυτήν τυχόν κενά.//
                    float x=stof(filename); //Μετατροπή της μεταβλητής τύπου string(που περιέχει το δεδομένο) σε μεταβλητή τύπου float.//
                    auto start=high_resolution_clock::now();
                    hash.insert(x); //Συνάρτηση για την εισαγωγή του αριθμού στον Hashtable.//
                    auto stop=high_resolution_clock::now();
                    auto duration=duration_cast<microseconds>(stop-start);
                    hash.write(); //Συνάρτηση για να γραφεί το αποτέλεσμα στο αρχείο temp.//
                    ifstream tempfile("temp.txt"); //Αντιγραφή των περιεχωμένων του αρχείου temp στο αρχείο output.//
                    string temp;
                    screen<<"Hashtable after the insertion of "<<x<<": "<<endl;
                    while(tempfile.good()){
                        getline(tempfile,temp);
                        screen<<temp<<endl;
                    }
                    screen<<"Insertion time of "<<x<<" in Hashtable: "<<duration.count()<<" microseconds."<<endl<<endl;
                }
                else{
                    cout<<"Invalid command.("<<line<<")"<<endl;
                }
            }
            else if(strstr(line.c_str(),c7.c_str())){
                if(strstr(line.c_str(),s1.c_str())){
                    auto start=high_resolution_clock::now();
                    mnheap.deletion(); //Συνάρτηση για τη διαγραφή του ελάχιστου στοιχείου από τον σωρό ελαχίστων.//
                    auto stop=high_resolution_clock::now();
                    auto duration=duration_cast<microseconds>(stop-start);
                    ifstream tempfile("temp.txt"); //Αντιγραφή των περιεχωμένων του αρχείου temp στο αρχείο output.//
                    string temp;
                    screen<<"MINHEAP after the deletion of minimum: "<<endl;
                    while(tempfile.good()){
                        getline(tempfile,temp);
                        screen<<temp<<endl;
                    }
                    screen<<"Deletion time of minimum element in Minheap: "<<duration.count()<<" microseconds."<<endl<<endl;
                }
                else{
                    cout<<"Invalid command.("<<line<<")"<<endl;
                }
            }
            else if(strstr(line.c_str(),c8.c_str())){
                if(strstr(line.c_str(),s2.c_str())){
                    auto start=high_resolution_clock::now();
                    mxheap.deletion(); //Συνάρτηση για τη διαγραφή του μέγιστου στοιχείου από τον σωρό μεγίστων.//
                    auto stop=high_resolution_clock::now();
                    auto duration=duration_cast<microseconds>(stop-start);
                    ifstream tempfile("temp.txt"); //Αντιγραφή των περιεχωμένων του αρχείου temp στο αρχείο output.//
                    string temp;
                    screen<<"MAXHEAP after the deletion of max: "<<endl;
                    while(tempfile.good()){
                        getline(tempfile,temp);
                        screen<<temp<<endl;
                    }
                    screen<<"Deletion time of max element in Maxheap: "<<duration.count()<<" microseconds."<<endl<<endl;
                }
                else{
                    cout<<"Invalid command.("<<line<<")"<<endl;
                }
            }
            else if(strstr(line.c_str(),c9.c_str())){
                if(strstr(line.c_str(),s3.c_str())){
                    size_t pos=line.size();
                    string filename=line.substr(line.find_last_of(' ',pos)); //Παίρνουμε την τελευταία λέξη της γραμμής που διαβάστηκε σε μία μεταβλητή τύπου string.//
                    filename.erase(remove(filename.begin(),filename.end(),' '),filename.end()); //Αφαιρούμε από αυτήν τυχόν κενά.//
                    float x=stof(filename); //Μετατροπή της μεταβλητής τύπου string(που περιέχει το δεδομένο) σε μεταβλητή τύπου float.//
                    auto start=high_resolution_clock::now();
                    AVL.deletenm(x); //Συνάρτηση για την διαγραφή του αριθμού από το δέντρο AVL.//
                    auto stop=high_resolution_clock::now();
                    auto duration=duration_cast<microseconds>(stop-start);
                    AVL.write(); //Συνάρτηση για να γραφεί το αποτέλεσμα στο αρχείο temp.//
                    ifstream tempfile("temp.txt"); //Αντιγραφή των περιεχωμένων του αρχείου temp στο αρχείο output.//
                    string temp;
                    screen<<"AVL(preorder) after the deletion of "<<x<<": "<<endl;
                    while(tempfile.good()){
                        getline(tempfile,temp);
                        screen<<temp<<endl;
                    }
                    screen<<"Deletion time of "<<x<<" in AVL tree: "<<duration.count()<<" microseconds."<<endl<<endl;
                }
                else{
                    cout<<"Invalid command.("<<line<<")"<<endl;
                }
            }
            else{
                cout<<"Invalid command.("<<line<<")"<<endl;
            }
        }
        file.close();
        screen.close();
    }
    else{
        cout<<"ERROR! Can not find the commands file."<<endl;
        file.close();
        exit(1);
    }
    return 0;
}