

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
        this -> nrPersoaneImbarcate = 0;
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
        cout << endl << "S-a apelat destructorul";
        delete[] this->producator;
    }
    Autobuz(const Autobuz& copie) :idAutobuz(++nrAutobuze) {
        this->capacitate=copie.capacitate;
        this->nrPersoaneImbarcate = copie.nrPersoaneImbarcate;
        this->producator = new char[strlen(copie.producator) + 1];
        strcpy_s(this->producator, strlen(copie.producator) + 1, copie.producator);
    }
    void setcapacitate(int capacitate){
        this->capacitate = capacitate;
   }
    void setnrPersoaneImbarcate(int nrPersoaneImbarcate) {
        this->nrPersoaneImbarcate = nrPersoaneImbarcate;
    }
    int getcapacitate() {
        return capacitate;
    }
    int getnrPersoaneImbarcate() {
        return nrPersoaneImbarcate;
    }

};
  int Autobuz::nrAutobuze = 0;

int main()
{    
   
    std::cout << "Hello World!\n";
}

