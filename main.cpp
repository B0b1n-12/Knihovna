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

int main() {
    Autor a1("Franz Kafka");
    Autor a2("George Orwell");

    Kniha b1("Promena", &a1);
    Kniha b3("Proces", &a1);
    Kniha b2("Farma_zvirat", &a2);

    // OPRAVA: Voláme konstruktor jen s jedním parametrem (jméno police)
    Shelf jedna("Kafkova_police");

    cout << b1.getNazev() << endl;
    cout << b1.isborrowed() << endl;

    b1.borrow();
    b1.returnbook();

    // OPRAVA: Opět jen jeden parametr
    Shelf kafka("Kafkova sekce");
    kafka.addKniha(&b1);
    kafka.addKniha(&b3);

    // OPRAVA: Voláme metodu, která skutečně existuje
    kafka.vypisKnihy();

    return 0;
}
