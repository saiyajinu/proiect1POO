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
        this->rating = new int[0];
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
        if(this->rating != NULL)
            delete[] this->rating;
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

    const Produs& operator++(){
        this->pret++;
        return *this;
    }

    const Produs& operator--(){
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

    Produs& operator+=(float x){
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
        cout<<endl;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Produs& prod){
        out<<"Numele produsului este "<<prod.nume<<endl;
        out<<"Pretul produsului este "<<prod.pret<<endl;
        if(prod.disponibil)
            out<<"Produsul este disponibil"<<endl;
        else out<<"Produsul nu este disponibil"<<endl;
        out<<"Produsul are "<<prod.nrRatinguri<<" ratinguri"<<endl;
        if (prod.nrRatinguri){
            out<<"\tAcestea sunt urmatoarele: ";
            for (int i=0; i<prod.nrRatinguri; i++)
                out<<prod.rating[i]<<"/10 ";
            out<<endl;}
        out<<"Culoarea produsului este "<<prod.culoare<<endl<<endl;
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


class Client{
private:
    char* nume;
    string adresa;
    string mail;
    float puncteLoialitate;
    int nrComenzi;
    int* idComenzi;

public:
    Client(){
        this->nume = new char[strlen("Anonim"+1)];
        strcpy(this->nume,"Anonim");
        this->adresa = "-";
        this->mail = "-";
        this->puncteLoialitate = 0;
        this->nrComenzi = 0;
        this->idComenzi = NULL;
    }

    Client(char* nume , string adresa , string mail , float puncteLoialitate , int nrComenzi , int* idComenzi ){
        this->nume = new char[strlen(nume)+1];
        strcpy(this->nume, nume);
        this->adresa = adresa;
        this->mail = mail;
        this->puncteLoialitate = puncteLoialitate;
        this->nrComenzi = nrComenzi;
        this->idComenzi = new int[this->nrComenzi];
        for(int i = 0; i < this->nrComenzi; i++)
            this->idComenzi[i]=idComenzi[i];
    }

    Client(char* nume){
        this->nume = new char[strlen(nume)+1];
        strcpy(this->nume, nume);
        this->adresa = "-";
        this->mail = "-";
        this->puncteLoialitate = 0;
        this->nrComenzi = 0;
        this->idComenzi = NULL;
    }

    Client(char* nume, string mail){
        this->nume = new char[strlen(nume)+1];
        strcpy(this->nume, nume);
        this->adresa = "-";
        this->mail = mail;
        this->puncteLoialitate = 0;
        this->nrComenzi = 0;
        this->idComenzi = NULL;
    }

    Client(const Client& client){
        if(client.nume!=NULL){
            this->nume = new char[strlen(client.nume)+1];
            strcpy(this->nume, client.nume);}
        this->adresa = client.adresa;
        this->mail = client.mail;
        this->puncteLoialitate = client.puncteLoialitate;
        this->nrComenzi = client.nrComenzi;
        this->idComenzi = new int[nrComenzi];
        for(int i=0; i<this->nrComenzi; i++)
            this->idComenzi[i] = client.idComenzi[i];
    }

    ~Client(){
        if(this->nume != NULL)
            delete[] this->nume;
        if(this->idComenzi != NULL)
            delete[] this->idComenzi;
    }

    Client& operator=(const Client& client){
        if (this != &client){
            if(this->idComenzi != NULL)
                delete[] this->idComenzi;
            if(this->nume != NULL)
                delete[] this->nume;
            if(client.nume != NULL)
                this->nume = new char[strlen(client.nume)+1];
            strcpy(this->nume,client.nume);
            this->adresa = client.adresa;
            this->mail = client.mail;
            this->puncteLoialitate = client.puncteLoialitate;
            this->nrComenzi = client.nrComenzi;
            this->idComenzi = new int[this->nrComenzi];
            for(int i=0; i<this->nrComenzi; i++)
                this->idComenzi[i]=client.idComenzi[i];
        }
    }

    void setNumeClient(char* nume){
        this->nume = new char[strlen(nume)+1];
        strcpy(this->nume, nume);
    }

    void setAdresaClient(string adresa){
        this->adresa = adresa;
    }

    void setMailClient(string mail){
        this->mail = mail;
    }

    void setIdComanda(int index, int idComanda){
        this->idComenzi[index] = idComanda;
    }

    const char* getNumeClient()const{
        return this->nume;
    }

    string getAdresaClient(){
        return this->adresa;
    }

    string getMailClient(){
        return this->mail;
    }

    int getIdComanda(int index){
        return this->idComenzi[index];
    }

    const Client& operator++(){
        this->puncteLoialitate++;
        return *this;
    }

    const Client& operator--(){
        this->puncteLoialitate--;
        return *this;
    }

    Client operator+(int x){
        Client aux = *this;
        aux.puncteLoialitate = aux.puncteLoialitate + x;
        return aux;
    }

    int operator[](int index){
        if(index <= this-> nrComenzi)
            return this->idComenzi[index];
        else return 0;
    }

    bool operator==(const Client& client){
        if (this->nume == client.nume)
            return true;
        else return false;
    }

    Client operator+=(int x){
        this->puncteLoialitate += x;
        return *this;
    }

    Client operator*(int x){
        Client aux = *this;
        aux.puncteLoialitate = aux.puncteLoialitate * x;
        return aux;
    }

    friend bool operator>(const Client& client1, const Client& client2){
        return client1.puncteLoialitate > client2.puncteLoialitate;
    }

    friend istream& operator>>(istream&in, Client& client){
        cout<<"Numele clientului este: ";
        char auxnume[25];
        in>>auxnume;
        client.nume = new char[strlen(auxnume)+1];
        strcpy(client.nume, auxnume);
        cout<<"Adresa clientului este: ";
        in>>client.adresa;
        cout<<"Mailul clientului este: ";
        in>>client.mail;
        cout<<"Cate puncte de loialitate are clientul: ";
        in>>client.puncteLoialitate;
        cout<<"Cate comenzi are clientul: ";
        in>>client.nrComenzi;
        for(int i = 0; i<client.nrComenzi; i++)
            in>>client.idComenzi[i];
        return in;
    }

    friend ostream& operator<<(ostream&out, const Client& client){
        if(client.nume)
            out<<"Numele clientului este "<<client.nume<<endl;
        out<<"Adresa clientului este "<<client.adresa<<endl;
        out<<"Mailul clientului este "<<client.mail<<endl;
        out<<"Clientul are "<<client.puncteLoialitate<<" puncte de loialitate"<<endl;
        out<<"Clientul are "<<client.nrComenzi<<" comenzi"<<endl;
        if (client.nrComenzi){
            out<<"\n\tAcestea sunt urmatoarele: ";
            for(int i=0; i<client.nrComenzi; i++)
                out<<"Comanda cu id "<<client.idComenzi[i]<<endl;
            cout<<endl;
            }
        return out;
    }

    explicit operator int(){
        return (int)this->puncteLoialitate;
    }

    void afisareComenziClient(){
        if(this->nrComenzi){
            cout<<this->nume<<" are "<<this->nrComenzi<<" comenzi"<<endl;
            cout<<"\tAcestea sunt urmatoarele: ";
            for(int i = 0; i<this->nrComenzi; i++)
                cout<<this->idComenzi[i];

        }
    }

};

class Comanda{
private:
    Client client;
    int nrProduse;
    Produs *produse;
    const int idComanda;
    static int contorComenzi;

public:
    Comanda():idComanda(contorComenzi++){
        Client client;
        this->client = client;
        this->nrProduse = 0;
        this->produse = NULL;
    }

};
int Comanda::contorComenzi=1000;

class Magazin{
private:
    string nume;
    Produs *produse;
    int nrProduse;
    string adresa;
    double vanzariTotale;
};

void meniu(){
    int alegere, continua =1;
    cout<<"Meniu"<<endl;
    cout<<"1.Adauga produs"<<endl;
    cout<<"2.Adauga comanda"<<endl;
    cout<<"3.Vezi produse"<<endl;
    cout<<"4.Vezi comenzi"<<endl;

    cin>>alegere;
    switch(alegere){
        case 1:{
            Produs prod;
            cin>>prod;
            // mag = mag + prod;    (/aduagaProd() )
            break;}
        case 2:{
            //Comanda comanda;
            //cin>>comanda;
            break;}
        case 3:{
            //cout<<magazin.produse
            break;}
        case 4:{
            //cout<<magazin.comenzi
            break;}
        case 0:{
            continua = 0;
            break;}
        default:{
            cout<<"Comanda gresita";
            break;}
    }
}

int main(){

    Client p;
    ++p;
    p = p*5;
    cout<<p;


    return 0;
}
