

#include <iostream>
#include <cstring>
using namespace std;

class Autobuz
{
private:
    static int nrAutobuze;
    const int idAutobuz;
    int capacitate;
    int nrPersoaneImbarcate;
    char* producator;

public:
    Autobuz() : idAutobuz(++nrAutobuze) {  // definim construcotrul fara param
        this->capacitate = 30;
        this->nrPersoaneImbarcate = 0;
        this->producator = new char[strlen("Dacia") + 1];
        strcpy_s(this->producator, strlen("Dacia") + 1, "Dacia");
    }
    Autobuz(int capacitate, int nrPersoaneImbarcate, const char* producator) : idAutobuz(++nrAutobuze) {  // definim construcotrul cu param
        this->capacitate = capacitate;
        this->nrPersoaneImbarcate = nrPersoaneImbarcate;
        this->producator = new char[strlen(producator) + 1];
        strcpy_s(this->producator, strlen(producator) + 1, producator);

    }

    ~Autobuz() {     // definim destructorul 

        cout << endl << "S-a apelat destuctorul";

        delete[] this->producator;
    }

    void setcapacitate(int capacitate) {   // definim metodata setcapacitate
        this->capacitate = capacitate;

    }
    void setnrPersoaneImbarcate(int nrPersoaneImbarcate) {  // definim metodata setnrPersoaneImbarcate
        this->nrPersoaneImbarcate = nrPersoaneImbarcate;
    }
    int getcapacitate() {   // definim metodata getcapacitate
        return this->capacitate;
    }
    int getnrPersoaneImbarcate() {   // definim metodata getnrPersoaneImbarcate
        return this->nrPersoaneImbarcate;
    }
    Autobuz(const Autobuz& copie) : idAutobuz(++nrAutobuze) { // definim constructorul de copiere
        this->capacitate = copie.capacitate;
        this->nrPersoaneImbarcate = copie.nrPersoaneImbarcate;
        this->producator = new char[strlen(copie.producator) + 1];
        strcpy_s(this->producator, strlen(copie.producator) + 1, copie.producator);
    }
    void afisareAutobuz() const {  // definim metoda afisareAutobuz
        cout << " Autobuzul: " << this->idAutobuz << " cu capacitatea " << this->capacitate
            << " si cu producatorul " << this->producator;
        if (this->nrPersoaneImbarcate >= 0) {
            cout << " are " << this->nrPersoaneImbarcate << " persoane imbarcate. " << endl;
        }
    }
    Autobuz& operator=(const Autobuz& bus) { //definim metoda operator =
        if (this != &bus) {

            this->capacitate = bus.capacitate;
            this->nrPersoaneImbarcate = bus.nrPersoaneImbarcate;
            delete[] this->producator;
            this->producator = new char[strlen(bus.producator) + 1];
            strcpy_s(this->producator, strlen(bus.producator) + 1, bus.producator);
        }
    }
    int getNumarLocuriLibere() {    //definim metoda calcul NumarLocuriLibere ramase in autobuz
        if (this->capacitate > this->nrPersoaneImbarcate)
            return (this->capacitate - this->nrPersoaneImbarcate);
        else
            return 0;
    }

    bool operator>(const Autobuz& a) { //definim metoda operator >
        return this->capacitate > a.capacitate;
    }

};

int Autobuz::nrAutobuze = 0; //initializam atributul static nrAutobuze 

int main()
{
    int capacitatea;

    cout << "Introduceti capacitatea pentru autobuzul 1: ";
    cin >> capacitatea;
    cout << endl;
    Autobuz varAutobuz1; //se contrieste varAutobuz1 apeland constructorulul fara parametrii
    varAutobuz1.setcapacitate(capacitatea); //setam capacitatea autobuzului varAutobuz1 folosind set -arul setcapacit
    cout << varAutobuz1.getcapacitate() << endl; // verificam afisand valoarea capacitate a autobuzului varAutobuz1 utilizand get arul getcapacitate

    varAutobuz1.setcapacitate(55); //modificam inca o data capacitatea lui varAutobuz1 cu o noua valoare
    cout << varAutobuz1.getcapacitate() << endl; //afisam valoarea atributului capacitate al lui  varAutobuz1

    varAutobuz1.afisareAutobuz();
    cout << endl;

    Autobuz varAutobuz2(60, 3, "Mercedezz");//se contrieste varAutobuz2 apeland constructorulul cu  parametrii
    cout << endl;
    varAutobuz2.afisareAutobuz();

    Autobuz varAutobuz3 = varAutobuz1; //construim un al 3 lea obiect autobuz 
    cout << "autobuzul 3 capacitate:" << varAutobuz3.getcapacitate() << endl;

    cout << "Numar locuri libere ale autobuzului 2:" << varAutobuz2.getNumarLocuriLibere() << endl; // afisam nr locuri libere apeland metoda getNumarLocuriLibere

    varAutobuz3.afisareAutobuz();
    cout << endl;

    varAutobuz2.afisareAutobuz();
    cout << endl;

    if (varAutobuz3 > varAutobuz2) cout << "varAutobuz3 este mai mare decat varAutobuz2" << endl;
    else  "varAutobuz2 este mai mare decat varAutobuz3";

}

