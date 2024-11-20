

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
    Autobuz() : idAutobuz(++nrAutobuze) {
        this->capacitate = 30;
        this->nrPersoaneImbarcate = 0;
        this->producator = new char[strlen("Dacia") + 1];
        strcpy_s(this->producator, strlen("Dacia") + 1, "Dacia");
    }
    Autobuz(int capacitate, int nrPersoaneImbarcate, const char* producator) : idAutobuz(++nrAutobuze) {
        this->capacitate = capacitate;
        this->nrPersoaneImbarcate = nrPersoaneImbarcate;
        this->producator = new char[strlen(producator) + 1];
        strcpy_s(this->producator, strlen(producator) + 1, producator);

    }

    ~Autobuz() {

        cout << endl << "S-a apelat destuctorul";

        delete[] this->producator;
    }

    void setcapacitate(int capacitate) {
        this->capacitate = capacitate;

    }
    void setnrPersoaneImbarcate(int nrPersoaneImbarcate) {
        this->nrPersoaneImbarcate = nrPersoaneImbarcate;
    }
    int getcapacitate() {
        return this->capacitate;
    }
    int getnrPersoaneImbarcate() {
        return this->nrPersoaneImbarcate;
    }
    Autobuz(const Autobuz& copie) : idAutobuz(++nrAutobuze) {
        this->capacitate = copie.capacitate;
        this->nrPersoaneImbarcate = copie.nrPersoaneImbarcate;
        this->producator = new char[strlen(copie.producator) + 1];
        strcpy_s(this->producator, strlen(copie.producator) + 1, copie.producator);
    }
    void afisareAutobuz() const {
        cout << this->idAutobuz << " Autobuzul cu capacitatea " << this->capacitate
            << " si cu producatorul " << this->producator;
        if (this->nrPersoaneImbarcate >= 0) {
            cout << " are " << this->nrPersoaneImbarcate << " persoane imbarcate.";
        }
    }
};
    int Autobuz::nrAutobuze = 0;

    int main()
    {
        int capacitatea;

        cout << "Introduceti capacitatea";
        cin >> capacitatea;
        Autobuz varAutobuz1;
        cout << varAutobuz1.getcapacitate() << endl;

        varAutobuz1.setcapacitate(55);
        cout << varAutobuz1.getcapacitate() << endl;

        Autobuz varAutobuz2 = varAutobuz1;
        cout << "autobuzul 2 capacitate:" << varAutobuz2.getcapacitate() << endl;
        std::cout << "Hello World!\n";
    }

