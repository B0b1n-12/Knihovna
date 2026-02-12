#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Autor {
private:
    string jmenoAutora;
public:
    Autor(const string& jmenoAutora):jmenoAutora(jmenoAutora) {};
    string getName()const{return jmenoAutora;}
};

class Kniha {
private:
    string nazev;
    bool isBorrowed=0;
    Autor* autor;
public:
    Kniha(const string& nazev, Autor* autor):autor(autor),nazev(nazev){};
    string getNazev()const{return nazev;}
    Autor* getAutor()const{return autor;}

    void borrow() {
        if(isBorrowed==1) {
            cout<<"Kniha je uz monentalne pujcena"<<endl;
        }else {
            cout<<"Prave jste si pujcili knihu "<<nazev<<" od "<<autor->getName()<<endl;
            isBorrowed=1;
        }
    }
    void returnbook() {
        if (isBorrowed==0) {
            cout<<"Kniha uz je vracena"<<endl;
        }else {
            cout<<"Dekujeme za vraceni"<<endl;
            isBorrowed=0;
        }
    }
    bool isborrowed()const{return isBorrowed;}
};

class Shelf {
private:
    string jmenoPolice;
    vector<Kniha*> knihy; // Seznam knih na této polici

public:
    // Teď police nepotřebuje autora, jen své jméno
    Shelf(const string& jmeno) : jmenoPolice(jmeno) {}

    void addKniha(Kniha* kniha) {
        knihy.push_back(kniha);
    }

    void vypisKnihy() const {
        cout << "Obsah police " << jmenoPolice << ":" << endl;
        for (Kniha* k : knihy) {
            cout << "- " << k->getNazev() << endl;
        }
    }
};

class Library {
private:
    string jmenoKnihovny;
    vector<Shelf> shelves;
    vector<Kniha*> allBooks;
public:
    Library(const string& jmenoKnihovny):jmenoKnihovny(jmenoKnihovny){};
    void addShelf(const string& nazev) {
        Shelf novaPolice(nazev);
        shelves.push_back(novaPolice);
    }
    void addBook(Kniha* k) {
        allBooks.push_back(k);
    }
    void findBooksByAuthor(const string& authorName) const {
        for (Kniha* k : allBooks) {
            if(k->getAutor()->getName()==authorName) {
                cout << k->getNazev() << endl;
            }
        }
    }

};

int main() {

    Library mojeKnihovna("Mestska knihovna");

    int volba = -1;


    while (volba != 0) {
        cout << "-----------------------------" << endl;
        cout << "Vitejte v knihovne: " << "Mestska knihovna" << endl;
        cout << "1. Pridat knihu" << endl;
        cout << "2. Vypsat vsechny knihy (zatim nefunkcni)" << endl;
        cout << "0. Ukoncit" << endl;
        cout << "Vase volba: ";

        cin >> volba;

        switch (volba) {
            case 1: {
                string nazevKnihy;
                string jmenoAutora;
                cin.ignore();
                cout << "Zadejte nazev knihy: ";
                getline(cin, nazevKnihy);
                cout << "Zadejte jmeno autora: ";
                getline(cin, jmenoAutora);
                Autor* novyAutor = new Autor(jmenoAutora);
                Kniha* novaKniha = new Kniha(nazevKnihy, novyAutor);
                mojeKnihovna.addBook(novaKniha);
                cout << "--> Kniha '" << nazevKnihy << "' byla uspesne pridana do evidence." << endl;
            }
            break;
            case 2:
                cout << "Implementujeme pozdeji..." << endl;
            break;
            case 0:
                cout << "Naschledanou!" << endl;
            break;
            default:
                cout << "Neplatna volba, zkuste to znovu." << endl;
        }
    }

    return 0;
}