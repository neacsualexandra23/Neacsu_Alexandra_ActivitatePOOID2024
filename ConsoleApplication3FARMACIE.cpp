// ConsoleApplication3FARMACIE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
using namespace std;
class Farmacie
{
private:
    static int nrFarmacie;
    const int CODUnic;
    string adresa;
    int nrMedicamente;
    float* preturiMedicamente;

public:   
    Farmacie() : CODUnic(++nrFarmacie) {

        this->adresa = "Str_Mugurel";
        this->nrMedicamente = 3;
        this->preturiMedicamente = nullptr; //new float[3] { 10.0, 15.0, 20.0 };
        cout << "S-a apelat constructorul" << endl;
    }
    Farmacie(string adresa,int nrMedicamente,float* preturiMedicamente) :CODUnic(++nrFarmacie) {
        this->adresa = adresa;
        this->nrMedicamente = nrMedicamente;
        if (nrMedicamente > 0 && preturiMedicamente != nullptr)
        {
            this->preturiMedicamente = new float[nrMedicamente];
            for (int i = 0;i < nrMedicamente;i++)
                this->preturiMedicamente[i] = preturiMedicamente[i];
        } else
        this->preturiMedicamente = nullptr;
      

    }

    Farmacie(const Farmacie& copie) :CODUnic(++nrFarmacie) { // definim constructorul de copiere
        this->adresa = copie.adresa;
        this->nrMedicamente = copie.nrMedicamente;
        if (copie.nrMedicamente > 0 && copie.preturiMedicamente != nullptr)
        {
            this->preturiMedicamente = new float[copie.nrMedicamente];
            for (int i = 0;i < copie.nrMedicamente;i++)
                this->preturiMedicamente[i] = copie.preturiMedicamente[i];
        }
        else
            this->preturiMedicamente = nullptr;
        cout << "S-a apelat constructorul copiere" << endl;
    }
    ~Farmacie() {
        cout << "S-a apelat destructorul" << endl;
        delete[] preturiMedicamente;
    }
    friend ostream& operator <<(ostream& out, const Farmacie& a) {
        out << "Codul unic este :" << a.CODUnic << ";Adresa este:" << a.adresa << ";Numarul de medicamente este:" << a.nrMedicamente << ";pretul medicamentelor este:";// << a.preturiMedicamente;
        if (a.preturiMedicamente != nullptr)
           
            for (int i = 0; i <a.nrMedicamente;i++)
                out << a.preturiMedicamente[i]<< " ";
                
        return out;
    }

    Farmacie& operator=(const Farmacie& a) {
        if (this != &a) {

            
            this->adresa = a.adresa;
            this->nrMedicamente = a.nrMedicamente;
            delete[] this->preturiMedicamente;
            if (a.nrMedicamente > 0 && a.preturiMedicamente != nullptr)
            {
                this->preturiMedicamente = new float[a.nrMedicamente];
                for (int i = 0;i < a.nrMedicamente;i++)
                    this->preturiMedicamente[i] = a.preturiMedicamente[i];
            }
            else
                this->preturiMedicamente = nullptr;
        }
        cout << "S-a apelat operatorul = " << endl;

    }
    // Operatorul prefixat ++
    Farmacie& operator++() {
       
            ++nrMedicamente;
      
        return *this;
    }
    float operator[](int index) {
        if (index >= 0 && index < this->nrMedicamente) {
            return this->preturiMedicamente[index];
        }
        else {
            return -1; // Valoare implicită pentru index invalid
        }
    }
    
    void setadresa(string adresa) {
        this->adresa = adresa;
   }
    void setnrMedicamente(int nrMedicamente) {
        this->nrMedicamente = nrMedicamente;
    }
    string getadresa() {
        return this->adresa;
    }
    int getnrMedicamente() {
        return this->nrMedicamente;
    }
    
    
};
int Farmacie::nrFarmacie = 0;

void suma(int* a, int b) {
    (*a) = (*a) + b;
}

void suma_ref(int& a, int b) {
    a = a + b;
}
void suma_val(int a, int b) {
    a = a + b;
}


Farmacie &f() {
    static Farmacie c; 
    return c;
}


int main()
{
    int x = 5;
    int y = 3;
    int k;
    int pret;
    suma_ref(x, y);
    cout  << x;
   
    //Farmacie* fv = new Farmacie[5];
    Farmacie r1;
    Farmacie r2=r1;

   
  //  Farmacie r =f();
  //  cout << sizeof( r)<<" "<< sizeof (Farmacie);
   
    
    Farmacie varFarmacie1;
    Farmacie varFarmacie2("stradaC",2,new float[2]{5.0,9.7});
    cout << varFarmacie1 << endl;
    cout << varFarmacie2 << endl;
    
    varFarmacie1.setadresa("Caransebes 11");
    cout << varFarmacie1.getadresa() << endl;
    varFarmacie1.setnrMedicamente(21);
    cout << varFarmacie1.getnrMedicamente() << endl;
  

    ++varFarmacie2;
    cout << varFarmacie2.getnrMedicamente();  //getter getnrMedicamente
    cout << endl << varFarmacie2[1];  //operatorul []  pretul pentru al doilea produs
    std::cout << endl<<"Hello World!\n";
}

