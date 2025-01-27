// ConsoleApplication3FARMACIE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
#include <stdexcept> 
#include <cstring>
#include <vector>
#include <sstream>
#include <fstream> 

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
       // cout << "S-a apelat constructorul" << endl;
    }
    Farmacie(string adresa, int nrMedicamente) :CODUnic(++nrFarmacie) {
        this->adresa = adresa;
        this->nrMedicamente = nrMedicamente;
        this->preturiMedicamente = nullptr;


    }
    Farmacie(string adresa, int nrMedicamente, float* preturiMedicamente) :CODUnic(++nrFarmacie) {
        this->adresa = adresa;
        this->nrMedicamente = nrMedicamente;
        if (nrMedicamente > 0 && preturiMedicamente != nullptr)
        {
            this->preturiMedicamente = new float[nrMedicamente];
            for (int i = 0;i < nrMedicamente;i++)
                this->preturiMedicamente[i] = preturiMedicamente[i];
        }
        else
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
       // cout << "S-a apelat destructorul" << endl;
        delete[] preturiMedicamente;
    }
    friend ostream& operator<<(ostream& out, const Farmacie& a) {
        out << "Codul unic este :" << a.CODUnic << ";Adresa este:" << a.adresa << ";Numarul de medicamente este:" << a.nrMedicamente << ";pretul medicamentelor este:";// << a.preturiMedicamente;
        if (a.preturiMedicamente != nullptr)

            for (int i = 0; i < a.nrMedicamente;i++)
                out << a.preturiMedicamente[i] << " ";

        return out;
    }

    Farmacie& operator=(const Farmacie& a) {
        if (this != &a) {

            // cout << "S-a apelat doperatorul =" << endl;
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
    // Operatorul []
    float operator[](int index) {
        if (index >= 0 && index < this->nrMedicamente) {
            return this->preturiMedicamente[index];
        }
        else {
            return -1; // Valoare implicită pentru index invalid
        }
    }
    friend ifstream& operator>>(ifstream& file, Farmacie& f) {
        int tempCODUnic;
        file >> tempCODUnic;
        if (file) {
            const_cast<int&>(f.CODUnic) = tempCODUnic;
        }


        file >> f.adresa;
        file >> f.nrMedicamente;


        if (f.preturiMedicamente != nullptr) {
            delete[] f.preturiMedicamente;
            f.preturiMedicamente = nullptr;
        }


        f.preturiMedicamente = new float[f.nrMedicamente];
        for (int i = 0; i < f.nrMedicamente; i++) {
            file >> f.preturiMedicamente[i];
        }

        return file;

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

    static void CitesteDinFisier(string numeFisier) {
        Farmacie FarmacieDinFisier;
        ifstream fis(numeFisier, ios::in);
        fis >> FarmacieDinFisier;
        fis.close();
        cout << FarmacieDinFisier;
    }

    static void ScrieInFisier(const Farmacie& f) {
        ofstream fis("Farmacie.txt", ios::out);
        fis << f;
        fis.close();
    };


};



class Angajat
{
private:
    static int nrAngajati;
    const long long CNP;
    const int id;
    string nume;
    string prenume;
    string companie;
    char* functia;

public:

    Angajat() :id(++nrAngajati), CNP(0000000000000) {
        this->nume = "Necunoscut";
        this->prenume = "Necunoscut";
        this->companie = "Necunoscuta";
        this->functia = new char[strlen("Necunoscut") + 1];
        strcpy_s(this->functia, strlen("Necunoscut") + 1, "Necunoscut");
    }

    Angajat(string nume, string prenume)
        : id(++nrAngajati), CNP(0000000000000) {
        this->nume = nume;
        this->prenume = prenume;
        this->companie = "Necunoscuta";
        this->functia = new char[strlen("Necunoscut") + 1];
        strcpy_s(this->functia, strlen("Necunoscut") + 1, "Necunoscut");
    }

    Angajat(string nume, string prenume, string companie)
        : id(++nrAngajati), CNP(0000000000000) {
        this->nume = nume;
        this->prenume = prenume;
        this->companie = companie;
        this->functia = new char[strlen("Necunoscut") + 1];
        strcpy_s(this->functia, strlen("Necunoscut") + 1, "Necunoscut");
    }
    ~Angajat() {
        delete[] this->functia;
    }

    int getId() {
        return this->id;
    }
    long long getCNP() {
        return this->CNP;
    }
    string getNume() {
        return this->nume;
    }
    string getPrenume() {
        return this->prenume;
    }
    char* getFunctie() {
        return this->functia;
    }

    void setNume(string Nume) {
        if (Nume == "") {
            this->nume = "Necunoscut";
        }
        else {
            this->nume = Nume;
        };
    };

    void setPrenume(string Prenume) {
        if (Prenume == "") {
            this->prenume = "Necunoscut";
        }
        else {
            this->prenume = Prenume;
        };
    };

    void setFunctia(const char* Functia) {
        if (this->functia != nullptr) {
            delete[] functia;
        }
        if (Functia != nullptr) {
            this->functia = new char[strlen(Functia) + 1];
            strcpy_s(this->functia, strlen(Functia) + 1, Functia);
        }
        else {
            this->functia = nullptr;
        }
    }

    static int getNrAngajati() {  //getter si setter pt variablile statice
        return Angajat::nrAngajati;
    };

    static void setNrAngajati(int nr) {
        if (nr > 0) {
            Angajat::nrAngajati = nr;
        }
        else {
            cout << "Numarul angajatilor trebuie sa fie mai mare decat 1" << endl;
        }
    }

    Angajat& operator=(const Angajat& a) {
        if (this != &a) {

            delete[] this->functia;
            this->nume = a.nume;
            this->prenume = a.prenume;
            this->functia = new char[strlen(a.functia) + 1];
            strcpy_s(this->functia, strlen(a.functia), a.functia);
        };
        return *this;
    };

    friend bool operator== (const Angajat& a1, const Angajat& a2) {
        return a1.CNP == a2.CNP;
    };

    friend ostream& operator<<(ostream& out, const Angajat& a) {
        out << a.id << "; "
            << a.CNP << "; "
            << a.nume << "; "
            << a.prenume << "; ";
        if (a.functia != nullptr) {
            out << a.functia << "; ";
        }
        else {
            out << "Functia necunoscuta";
        }
        return out;
    }



    bool LucreazaLaAceeasiCompanie(const Angajat& a1, const Angajat& a2) {
        if (a1.companie != "Necunoscuta" && a2.companie != "Necunoscuta" && a1.companie == a2.companie)
            return true;
        else
            return false;

    }
   void AfisareNume(Angajat a){
         cout << a.nume + " " + a.prenume << endl;
     };

   static void citeste_din_fisier(string numeFisier) {
        Farmacie FarmacieDinFisier;
        ifstream fis(numeFisier, ios::in);
        fis >> FarmacieDinFisier;
        fis.close();
        cout << FarmacieDinFisier;
    }

    static void scrie_in_fisier(const Farmacie& c) {
        ofstream fis("Farmacie.txt", ios::out);
        fis << c;
        fis.close();
    };
    

};





class Medicament {

public:
    static int nrMedicament;
    const int id;
    string denumire;
    float pret;
    int cantitate;
    int nrSubstanteActive;
    char* SubstanteActive;

public:
    Medicament() : id(++nrMedicament), denumire("Necunoscut"), pret(0.0), cantitate(0), nrSubstanteActive(0), SubstanteActive(nullptr) {}

    Medicament(const string denumire, float pret, int cantitate = 0)
        : id(++nrMedicament), denumire(denumire), pret(pret), cantitate(cantitate), nrSubstanteActive(0) {
        SubstanteActive = new char[strlen("Necunoscuta") + 1];
        strcpy_s(SubstanteActive, strlen("Necunoscuta") + 1, "Necunoscuta");
    }

    // Constructor de copiere
    Medicament(const Medicament& other) : id(++nrMedicament) {
        denumire = other.denumire;
        pret = other.pret;
        cantitate = other.cantitate;
        nrSubstanteActive = other.nrSubstanteActive;

        if (other.SubstanteActive != nullptr) {
            SubstanteActive = new char[strlen(other.SubstanteActive) + 1];
            strcpy_s(SubstanteActive, strlen(other.SubstanteActive) + 1, other.SubstanteActive);
        }
        else {
            SubstanteActive = nullptr;
        }
    }

    //  Destructor 
    virtual ~Medicament() {
        delete[] SubstanteActive;
    }
    //operator =
    Medicament& operator=(const Medicament& other) {
        if (this != &other) {
            denumire = other.denumire;
            pret = other.pret;
            cantitate = other.cantitate;
            nrSubstanteActive = other.nrSubstanteActive;

            delete[] SubstanteActive;

            if (other.SubstanteActive != nullptr) {
                SubstanteActive = new char[strlen(other.SubstanteActive) + 1];
                strcpy_s(SubstanteActive, strlen(other.SubstanteActive) + 1, other.SubstanteActive);
            }
            else {
                SubstanteActive = nullptr;
            }
        }
        return *this;
    }

    const string  getDenumire() {
        return this->denumire;
    }
    void setDenumire(const string denumireNoua) {
        if (denumireNoua.empty()) {
            this->denumire = "Necunoscut";
        }
        else {
            this->denumire = denumireNoua;
        }
    }

    double getPret() const {
        return pret;
    }


    void setPret(float pretNou) {
        pret = pretNou;
    }


    int getCantitate() const {
        return cantitate;
    }


    void setCantitate(int cantitateNoua) {
        cantitate = cantitateNoua;
    }
    friend ostream& operator<<(ostream& out, const Medicament& m) {
        out << m.id << "; "
            << m.denumire << "; "
            << m.cantitate << "; "
            << m.pret << "; ";

        return out;
    }

    friend istream& operator>>(istream& in, Medicament& m) {
              cout << "Introduceți denumirea medicamentului: ";
            in >> m.denumire;

            cout << "Introduceți pretul medicamentului: ";
            in >> m.pret;

            cout << "Introduceți cantitatea medicamentului: ";
            in >> m.cantitate;

            return in;
        }
      
    virtual void afisare() {
        cout << id << "; " << denumire << "; " << cantitate << "; " << pret << endl;
    }

    virtual void metodaDeSuprascris() {
        cout << "Metoda de Suprascris din clasa Medicament!" << endl;
    }




};
class MedicamentHomeopat :public Medicament {
private:
    string diluitie;


public:
    MedicamentHomeopat() : Medicament(), diluitie("Necunoscut") {}


    MedicamentHomeopat(const string& denumire, float pret, int cantitate, const  string& diluitie)
        : Medicament(denumire, pret, cantitate), diluitie(diluitie) {}



    string getdiluitie() {
        return this->diluitie;
    }




    void setdiluitie(const string diluitie) {
        this->diluitie = diluitie;
    }
    
    void afisare()   {
        Medicament::afisare();
        cout << "Dilutie: " << diluitie << endl;
    }
    
    void metodaDeSuprascris() override {
        cout << "Metoda de Suprascris din clasa MedicamentHomeopat !" << endl;
    };

};




//clasa HAS A relatie 1 la mai multe 
class GrupaMedicamente {   
private:
    static int nrGrupaMedicamente;
    int id;
    string nume;
    Medicament* medicamente;
    int nrMedicamente;

public:
    ~GrupaMedicamente() {
        if (this->medicamente != nullptr) {
            delete[] this->medicamente;
        }

    }
    GrupaMedicamente() : id(++nrGrupaMedicamente), nume("Grupa Necunoscuta"), medicamente(nullptr), nrMedicamente(0) {
    }

    GrupaMedicamente(string nume, int nrMedicamente, Medicament* medicamentePtGrupa) {
        this->id = ++nrGrupaMedicamente;
        this->nume = nume;
        this->nrMedicamente = nrMedicamente;
        if (this->nrMedicamente > 0 && this->medicamente != nullptr) {
            this->medicamente = new Medicament[nrMedicamente];
            for (int i = 0; i < nrMedicamente; i++) {
                this->medicamente[i] = medicamentePtGrupa[i];
            }
        }
        else {
            this->medicamente = nullptr;
        }

    };

    int getId() {
        return this->id;
    }
    string getNume() {
        return this->nume;
    }

    int getnrMedicamente() {
        return this->nrMedicamente;
    }

    Medicament* getmedicamente() {
        return this->medicamente;
    }

    void setId(int newId) {
        this->id = newId;
    }
    void setNume(string newName) {
        this->nume = newName;
    }

    void setnrMedicamente(int newNr) {
        this->nrMedicamente = newNr;
    }

    void setmedicamente(Medicament* newmedicamente, int newNr) {
        if (this->nrMedicamente > 0 && this->medicamente != nullptr) {
            this->medicamente = new Medicament[newNr];
            for (int i = 0; i < newNr; i++) {
                this->medicamente[i] = newmedicamente[i];
            }
        }
    }

    friend ostream& operator<<(ostream& out, const GrupaMedicamente& gm) {
        out << gm.id << endl;
        out << gm.nume << endl;
        if (gm.nrMedicamente > 0 && gm.medicamente != nullptr) {

            for (int i = 0; i < gm.nrMedicamente; i++) {
                out << gm.medicamente[i] << endl;

            }
        }
        else {
            out << "Grupa vida" << endl;
        }
        return out;

    }
    friend int operator>(const GrupaMedicamente& gm1, const GrupaMedicamente& gm2) {
        return gm1.nrGrupaMedicamente > gm2.nrGrupaMedicamente;
    }
};

int Farmacie::nrFarmacie = 0;
int GrupaMedicamente::nrGrupaMedicamente = 0;
int Medicament::nrMedicament = 0;
int Angajat::nrAngajati = 0;
int main()
{
    /* int x = 5;
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

     */

    Farmacie varFarmacie1;
    Farmacie varFarmacie2("stradaC", 2, new float[2] {5.0f, 7.9f});
    cout << varFarmacie1 << endl;
    cout << varFarmacie2 << endl;

    varFarmacie1.setadresa("Caransebes 11");
    cout << varFarmacie1.getadresa() << endl;
    varFarmacie1.setnrMedicamente(21);
    cout << varFarmacie1.getnrMedicamente() << endl;



    /* Farmacie::ScrieInFisier(varFarmacie1);
     Farmacie::CitesteDinFisier("Farmacie.txt");
     */
    ++varFarmacie2;
    cout << varFarmacie2.getnrMedicamente();  //getter getnrMedicamente
    cout << endl << varFarmacie2[1];  //operatorul []  pretul pentru al doilea produs



    Angajat varAngajat1("Neacsu", "Alexandra");cout << endl;
    Angajat varAngajat2("Neacsu", "Ion");cout << endl;
	cout<<varAngajat1 << endl;
    cout << varAngajat1 << endl;

   
  Angajat varAngajat3("Popescu", "Maria", "IBM");
  cout << varAngajat3 << endl;

    Medicament med1;
    Medicament med2("Paracetamol", 12.5, 50);
    med2.afisare();
    cout << med1<< endl; 
    Medicament med3("Berberina", 12.5, 50);
    med3.setDenumire("Insulina");
    med3.setPret(15.0);
    med3.setCantitate(100);
    med3.afisare();
    



    //upcastingul se apeleaza metodaDeSuprascris din clasa Medicament pt obiectul medUp
      med1.metodaDeSuprascris();
       Medicament* medUp = &med1;
     cout << endl;
     medUp->metodaDeSuprascris();



   GrupaMedicamente grDiabet("GrupaDiabet", 2, new Medicament[2]{ med1 , med2 }); //creere grDiabet cu apel constructor cu param pt clasa GrupaMedicamente
  
   MedicamentHomeopat mh1("Osciloccocinumg", 15.5f, 10, "CH9");
   MedicamentHomeopat mh2("Osciloccocinumg", 15.5f, 10, "CH3");

  mh1.afisare();
    cout << endl;
    mh2.afisare();
    mh1.metodaDeSuprascris();//apel metoda de suprascriere

}
