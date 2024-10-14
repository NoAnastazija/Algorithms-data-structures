#include <iostream>


using namespace std;


struct Vozlisce {
    int key;
    Vozlisce* oce;
    Vozlisce* leviSin;
    Vozlisce* desniSin;
};

void menu() {
    cout<<endl;
    cout << "============================" << endl;
    cout << "=========== MENU ===========" << endl;
    cout << "============================" << endl;
    cout << "1....VNOS PODATKA" << endl;
    cout << "2....UREJEN IZPIS VREDNOSTI" << endl;
    cout << "3....IZPIS POVEZAV" << endl;
    cout << "4....ISKANJE" << endl;
    cout << "5....IZPISI MINIMUM IN MAKSIMUM" << endl;
    cout << "6....IZPISI PREDHODNIKA IN NASLEDNIKA" << endl;
    cout << "7....BRISI VREDNOST" << endl;
    cout << "8....TESTIRAJ PRAVILNOST DELOVANJA" << endl;
    cout << "0....IZHOD" << endl;
    cout << "============================" << endl;
    cout << "Select: ";
}


void urejenIzpisVrednosti(Vozlisce* &koren){
    if(koren != NULL){
        urejenIzpisVrednosti(koren->leviSin);
        cout << koren->key << " ";
        urejenIzpisVrednosti(koren->desniSin);
    }
}

Vozlisce * iskanje(Vozlisce* &koren, int k){
    Vozlisce* x = koren;
    while (x != nullptr && x->key != k) {
        if (k < x->key)
            x = x->leviSin;
        else
            x = x->desniSin;
    }
    if (x != nullptr)
        cout << "Key found:  " << k << endl;
    else
        cout << "Key not found:  " << k << endl;
    return x;
}

Vozlisce* ustvari(int k) {
    Vozlisce* novoVozlisce = new Vozlisce;
    novoVozlisce->key = k;
    novoVozlisce->oce = nullptr;
    novoVozlisce->leviSin = nullptr;
    novoVozlisce->desniSin = nullptr;
    return novoVozlisce;
}

void vstavi(Vozlisce* &T, int k){
    Vozlisce* y = nullptr;
    Vozlisce* x = T;

    while (x != nullptr) {
        y = x;
        if (k < x->key)
            x = x->leviSin;
        else if (k > x->key)
            x = x->desniSin;
        else {
            cout << "Errrorr" << endl;
            return;
        }
    }
    Vozlisce* z = ustvari(k);
    z->oce = y;

    if (y == nullptr)
        T = z;
    else if (k < y->key)
        y->leviSin = z;
    else
        y->desniSin = z;
}

void izpisPovezav(Vozlisce* x) {
    if (x->leviSin != nullptr) {
        cout << "(" << x->key << " -> " << x->leviSin->key << ")" << endl;
        izpisPovezav(x->leviSin);
    }
    if (x->desniSin != nullptr) {
        cout << "(" << x->key << " -> " << x->desniSin->key << ")" << endl;
        izpisPovezav(x->desniSin);
    }
}

void minMax(Vozlisce* T) {
    Vozlisce* minNode = T;
    Vozlisce* maxNode = T;

    // Find the minimum node
    while (minNode->leviSin != nullptr) {
        minNode = minNode->leviSin;
    }

    // Find the maximum node
    while (maxNode->desniSin != nullptr) {
        maxNode = maxNode->desniSin;
    }

    // Print the minimum and maximum key values
    cout << "Minimum: " << minNode->key << endl;
    cout << "Maximum: " << maxNode->key << endl;
}

void naslednikPredhodnik(Vozlisce* T, int key) {

    Vozlisce* x = iskanje(T, key);

    if (x == nullptr) {
        cout << "Node with key " << key << " not found." << endl;
        return;
    }

    // Finding successor
    Vozlisce* nasl = nullptr;
    if (x->desniSin != nullptr) {
        nasl = x->desniSin;
        while (nasl->leviSin != nullptr) {
            nasl = nasl->leviSin;
        }
    } else {
        Vozlisce* y = x->oce;
        while (y != nullptr && x == y->desniSin) {
            x = y;
            y = y->oce;
        }
        nasl = y;
    }

    // Finding predecessor
    Vozlisce* pred = nullptr;
    if (x->leviSin != nullptr) {
        pred = x->leviSin;
        while (pred->desniSin != nullptr) {
            pred = pred->desniSin;
        }
    } else {
        Vozlisce* y = x->oce;
        while (y != nullptr && x == y->leviSin) {
            x = y;
            y = y->oce;
        }
        pred = y;
    }

    // Print the keys of successor and predecessor
    cout << "Successor of " << key << ": ";
    if (nasl != nullptr)
        cout << nasl->key << endl;
    else
        cout << "None" << endl;

    cout << "Predecessor of " << key << ": ";
    if (pred != nullptr)
        cout << pred->key << endl;
    else
        cout << "None" << endl;
}

void brisi(Vozlisce* &T, Vozlisce* z) {
    if (z == nullptr)
        return;


    if (z->leviSin == nullptr && z->desniSin == nullptr) {
        if (z->oce == nullptr)
            T = nullptr;
        else if (z == z->oce->leviSin)
            z->oce->leviSin = nullptr;
        else
            z->oce->desniSin = nullptr;
        delete z;
    }

    else if (z->leviSin != nullptr && z->desniSin != nullptr) {
        Vozlisce* nasl = z->desniSin;
        while (nasl->leviSin != nullptr)
            nasl = nasl->leviSin;
        z->key = nasl->key;
        brisi(T, nasl);
    }

    else {
        Vozlisce* child = (z->leviSin != nullptr) ? z->leviSin : z->desniSin;
        if (z->oce == nullptr)
            T = child;
        else if (z == z->oce->leviSin)
            z->oce->leviSin = child;
        else
            z->oce->desniSin = child;
        if (child != nullptr)
            child->oce = z->oce;
        delete z;
    }
}

/*
void brisi_scenarij_1_2(Vozlisce* &T, Vozlisce* y) {
    Vozlisce* x;
    if (y->leviSin != nullptr) {
        x = y->leviSin;
    } else {
        x = y->desniSin;
    }
    if (x != nullptr) {
        x->oce = y->oce;
    }
    if (y->oce == nullptr) {
        T = x;
    } else {
        if (y == y->oce->leviSin) {
            y->oce->leviSin = x;
        } else {
            y->oce->desniSin = x;
        }
    }
    delete y;
}

void brisi(Vozlisce* &T, Vozlisce* z) {
    if (z->leviSin == nullptr && z->desniSin == nullptr) { // Node to delete has no children
        brisi_scenarij_1_2(T, z);
    } else {
        cout << "Cannot delete" << endl;
    }
}
*/
void test(Vozlisce* &koren) {

    vstavi(koren, 1);
    vstavi(koren, 3);
    vstavi(koren, 9);
    vstavi(koren, 20);
    vstavi(koren, 8);


    cout << "Urejen izpis vrednosti po vnosu:" << endl;
    urejenIzpisVrednosti(koren);
    cout << endl;


    cout << "Izpis povezav:" << endl;
    izpisPovezav(koren);
    cout << endl;

    cout<<"Iskanje"<<endl;
    cout<<endl;
    iskanje(koren, 12);
    iskanje(koren, 3);
    cout<<endl;

    cout<< "Naslednik, predhodnik"<<endl;
    naslednikPredhodnik(koren, 50);
    naslednikPredhodnik(koren, 5);
    cout<<endl;


    cout<< "Brisi"<<endl;
    brisi(koren, koren);
    brisi(koren, koren->leviSin);
    brisi(koren, koren->desniSin);


    cout << "Urejen izpis vrednosti po brisanju:" << endl;
    urejenIzpisVrednosti(koren);
    cout << endl;


    cout << "Izpis povezav po brisanju:" << endl;
    izpisPovezav(koren);
    cout << endl;

    cout << "Extra"<<endl;
    vstavi(koren, 20);
    vstavi(koren, 22);
    vstavi(koren, 0);

    brisi(koren, koren->leviSin->leviSin);



}


int main() {
/*
    Vozlisce *v10 = new Vozlisce();
    v10->key=10;

    Vozlisce *v4 = new Vozlisce();
    v4->key=4;

    Vozlisce *v3 = new Vozlisce();
    v3->key=3;

    Vozlisce *v12 = new Vozlisce();
    v12->key=12;

    v10->oce = NULL;
    v10->leviSin = v4;
    v10->desniSin = v12;

    v4->oce = v10;
    v4->leviSin = v3;
    v4->desniSin = NULL;


    v3->oce = v4;
    v3->leviSin = NULL;
    v3->desniSin = NULL;

    v12->oce = v10;
    v12->leviSin = NULL;
    v12->desniSin = NULL;

    Vozlisce *koren = v10;

*/

    Vozlisce* koren = NULL;


    bool running = true;
    int selection;
    do{
        menu();
        cin >> selection;
        switch (selection) {
            case 1:
                int key;
                cout << "Vnesi kljuc: ";
                cin >> key;
                vstavi(koren, key);
                 break;
            case 2:
                cout << "Urejen izpis vrednosti:" << endl;
                urejenIzpisVrednosti(koren);
                cout << " ";
                break;
            case 3:
                cout << "Izpis povezav:" << endl;
                izpisPovezav(koren);
                break;
            case 4:
                int searchkey;
                cout << "Vnesi kljuc: ";
                cin>> searchkey;
                iskanje(koren, key);
                break;
            case 5:
                cout << "Minimum and maximum:" << endl;
                minMax(koren);
                break;
            case 6:
                int searchKey;
                cout << "Vnesi kljuc za iskanje: ";
                cin >> searchKey;
                naslednikPredhodnik(koren, searchKey);
                break;
            case 7: {
                int deleteKey;
                cout << "Vnesi kljuc za brisanje: ";
                cin >> deleteKey;
                Vozlisce *nodeToDelete = iskanje(koren, deleteKey);
                if (nodeToDelete != nullptr)
                    brisi(koren, nodeToDelete);
                else {
                    cout << "Kljuc ni bil najden: " << deleteKey << endl;
                }
                break;
            }
            case 8:
                // Test functionality
                test(koren);
                break;
                break;
            case 0:
                cout<<"Izbrali ste exit"<<endl;
                break;
            default:
                cout << "Wrong selection " << endl;
                break;
        }

    } while (running);



    return 0;
}
