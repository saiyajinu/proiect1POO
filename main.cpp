#include <iostream>
#include <string.h>

using namespace std;

class Produs{
private:
    string nume;
    float pret;
    bool disponibil;
    int nrRatinguri;
    int* rating;
    char culoare[10];

public:
    Produs(){
        this->nume = "Anonim";
        this->pret = 0;
        this->disponibil = false;
        this->rating = NULL;
        this->nrRatinguri = 0;
        strcpy(this->culoare, "-");
    }

    Produs(string nume, float pret, bool disponibil, int nrRatinguri, int* rating,  char culoare[]){
        this->nume = nume;
        this->pret = pret;
        this->disponibil = disponibil;
        this->nrRatinguri = nrRatinguri;
        this->rating = new int[this->nrRatinguri];
        for(int i=0; i<this->nrRatinguri; i++)
            this->rating[i]=rating[i];
        strcpy(this->culoare, culoare);
    }

    Produs(string nume, float pret){
        this->nume = nume;
        this->pret = pret;
        this->disponibil = false;
        this->nrRatinguri = 0;
        this->rating = NULL;
        strcpy(this->culoare, "-");
    }

    Produs(string nume, int nrRatinguri, int* rating){
        this->nume = nume;
        this->pret = 0;
        this->disponibil = false;
        this->nrRatinguri = nrRatinguri;
        for(int i=0; i<this->nrRatinguri; i++)
            this->rating[i]=rating[i];
        strcpy(this->culoare, "-");
    }

    Produs(const Produs& prod){
        this->nume = prod.nume;
        this->pret = prod.pret;
        this->disponibil = prod.disponibil;
        this->nrRatinguri = prod.nrRatinguri;
        this->rating = new int[this->nrRatinguri];
        for(int i=0; i<this->nrRatinguri; i++)
            this->rating[i] = prod.rating[i];
        strcpy(this->culoare, prod.culoare);
    }

    ~Produs(){
        if(this->culoare != NULL)
            delete[] this->culoare;
    }

    void setNumeProdus(string nume){
        this->nume = nume;
    }

    void setPretProdus(float pret){
        this->pret = pret;
    }

    void setDisponibilProdus(bool disponibil){
        this->disponibil = disponibil;
    }

    void setRatingProdus(int nrRatinguri, int* rating){
        this->nrRatinguri = nrRatinguri;
        this->rating = new int[nrRatinguri];
        for(int i = 0; i < this->nrRatinguri; i++)
            this->rating[i] = rating[i];
    }

    string getNumeProdus(){
        return this->nume;
    }

    float getPretProdus(){
        return this->pret;
    }

    bool getDisponibilProdus(){
        return this->disponibil;
    }

    const int* getRatingProdus()const{
        return this->rating;
    }

    int getNrRatinguriProdus(){
        return this->nrRatinguri;
    }

    Produs operator++(){
        this->pret++;
        return *this;
    }

    Produs operator++(int){
        Produs aux = *this;
        this->pret++;
        return aux;
    }

    Produs operator--(){
        this->pret--;
        return *this;
    }

    Produs operator+(float x){
        Produs aux = *this;
        aux.pret = aux.pret + x;
        return aux;
    }

    Produs operator*(float x){
        Produs aux = *this;
        aux.pret = aux.pret * x;
        return aux;
    }

    Produs operator+=(float x){
        this->pret += x;
        return *this;
    }

    bool operator==(const Produs& prod){
        if (this->nume == prod.nume)
            return true;
        else return false;
    }

    friend bool operator>(const Produs& prod1, const Produs& prod2){
        return prod1.pret > prod2.pret;
    }

    Produs& operator=(const Produs& prod){
        if(this != &prod){
            if(this->rating != NULL)
                delete[] this->rating;
            this->nume = prod.nume;
            this->pret = prod.pret;
            this->disponibil = prod.disponibil;
            this->nrRatinguri = prod.nrRatinguri;
            this->rating = new int[this->nrRatinguri];
            for(int i = 0; i < this->nrRatinguri; i++)
                this->rating[i] = prod.rating[i];
            strcpy(this->culoare, prod.culoare);
        }
        return *this;
    }

    friend istream& operator>>(istream& in, Produs& prod){
        cout<<"Numele produsului este: ";
        in>>prod.nume;
        cout<<"Pretul produsului este: ";
        in>>prod.pret;
        cout<<"Produsul este disponibil: ";
        in>>prod.disponibil;
        cout<<"Numarul de ratinguri ale produsului este: ";
        in>>prod.nrRatinguri;
        cout<<"Ratinguri: ";
        prod.rating = new int[prod.nrRatinguri];
        for (int i=0; i<prod.nrRatinguri; i++)
            in>>prod.rating[i];
        cout<<"Culoarea produsului este: ";
        in>>prod.culoare;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Produs& prod){
        out<<"\nNumele produsului este "<<prod.nume;
        out<<"\nPretul produsului este "<<prod.pret;
        if(prod.disponibil)
            out<<"\nProdusul este disponibil";
        else out<<"\nProdusul nu este disponibil";
        out<<"\nProdusul are "<<prod.nrRatinguri<<" ratinguri.";
        if (prod.nrRatinguri)
            out<<"\tAcestea sunt urmatoarele: ";
        for (int i=0; i<prod.nrRatinguri; i++)
            out<<prod.rating<<"/10, ";
        out<<"\nCuloarea produsului este "<<prod.culoare<<endl;
        return out;
    }

    explicit operator int(){
        return (int)this->pret;
    }

    int operator[](int index){
        if(index <= this->nrRatinguri)
            return this->rating[index];
        else return 0;
    }

    void produsEsteNegru(){
        if (this->culoare[0] == 'n')
            cout<<this->nume<<" are culoarea neagra";
    }
};

class Comanda{
private:
    string dataComanda;
    Produs *produse;
    const int id;
    static int contorComenzi;

};

class Client{
private:
    char* nume;
    Comanda *comenzi;
    string mail;
    int nrComenzi;

};


class Magazin{
private:
    string nume;
    Produs *produse;
    string adresa;
    double vanzariTotale;
};

int main(){
    Produs prod;
    cout<<prod;
    cin>>prod;
    prod.produsEsteNegru();

    return 0;
}
