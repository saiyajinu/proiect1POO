#include <iostream>
#include <string.h>

using namespace std;

int numarProduse;
int numarClienti;
int numarComenzi;

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
        bool aux;
        if(this->disponibil == 1)
            aux = 1;
        return aux;
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
        cout<<"Produsul este disponibil(0/1): ";
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
            out<<"Acestea sunt urmatoarele: ";
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
        this->nume = new char[strlen("Anonim")+1];
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
        if(index < this-> nrComenzi)
            return this->idComenzi[index];
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
        delete[] client.nume;
        client.nume = new char[strlen(auxnume)+1];
        strcpy(client.nume, auxnume);
        cout<<"Adresa clientului este: ";
        in>>client.adresa;
        cout<<"Mailul clientului este: ";
        in>>client.mail;
        cout<<"Cate puncte de loialitate are clientul: ";
        in>>client.puncteLoialitate;
        cout<<endl;
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
            out<<"\nAcestea sunt urmatoarele: ";
            for(int i=0; i<client.nrComenzi; i++)
                out<<"Comanda cu id "<<client.idComenzi[i]<<endl;
            }
        cout<<endl;
        return out;
    }

    explicit operator int(){
        return (int)this->puncteLoialitate;
    }

    void afisareComenziClient(){
        if(this->nrComenzi){
            cout<<this->nume<<" are "<<this->nrComenzi<<" comenzi"<<endl;
            cout<<"Acestea sunt urmatoarele: ";
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

    Comanda(Client client, int nrProduse, Produs* produse):idComanda(contorComenzi++){
        this->client = client;
        this->nrProduse = nrProduse;
        this->produse = new Produs[this->nrProduse];
        for(int i = 0; i < this->nrProduse; i++)
            this->produse[i]=produse[i];
    }

    Comanda(Client client):idComanda(contorComenzi++){
        this->client = client;
        this->nrProduse = 0;
    }

    Comanda(const Comanda& cmd):idComanda(cmd.idComanda){
        this->client = cmd.client;
        this->nrProduse = cmd.nrProduse;
        this->produse = new Produs[this->nrProduse];
        for(int i = 0; i < this->nrProduse; i++)
            this->produse[i] = cmd.produse[i];
    }

    ~Comanda(){
        if(this->produse != NULL)
            delete[] this->produse;
    }

    Comanda& operator=(const Comanda& cmd){
        this->client = cmd.client;
        this->nrProduse = cmd.nrProduse;
        this->produse = new Produs[this->nrProduse];
        for(int i = 0; i< this->nrProduse; i++)
            this->produse[i] = cmd.produse[i];
    }

    void setClientComanda(Client client){
        this->client = client;
    }

    void setProduseComanda(int nrProduse, Produs* produse){
        this->nrProduse = nrProduse;
        this->produse = new Produs[this->nrProduse];
        for(int i = 0; i < this->nrProduse; i++)
            this->produse[i] = produse[i];
    }

    Client getClientComanda(){
        return this->client;
    }

    Produs* getProduseComanda(){
        return this->produse;
    }

    Comanda operator+(Produs& produs){
        Produs* aux = new Produs[nrProduse];
        for(int i = 0; i < nrProduse ;i++)
            aux[i]=this->produse[i];
        delete[] this->produse;
        this->nrProduse++;
        produse = new Produs[nrProduse];
        for(int i = 0; i < nrProduse-1 ;i++)
            this->produse[i]=aux[i];
        produse[nrProduse-1]=produs;
    }

    Produs operator[](int index){
        if(index < this->nrProduse)
            return this->produse[index];
    }

    bool operator==(const Comanda& cmd){
        if(this->idComanda == cmd.idComanda)
            return true;
        else return false;
    }

    friend bool operator<(const Comanda& cmd1, const Comanda& cmd2){
        return cmd1.nrProduse < cmd2.nrProduse;
    }

    friend istream& operator>>(istream&in, Comanda& cmd){
        cin>>cmd.client;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Comanda& cmd){
        out<<"Comanda este data de:"<<endl<<cmd.client;
        out<<"Comanda are "<<cmd.nrProduse<<" produse"<<endl;
        out<<"Acestea sunt: "<<endl;
        for(int i = 0; i< cmd.nrProduse; i++){
            out<<cmd.produse[i];
           // cout<<endl;
        }
        //out<<endl;
        out<<"Comanda are id-ul "<<cmd.idComanda<<endl<<endl;
    }

    void afisareProduseComanda(){
        if(this->nrProduse){
            cout<<"Comanda cu nr "<<this->idComanda<<" contine urmatoarele produse: \n";
            for(int i = 0; i < this->nrProduse; i++)
                cout<<this->produse[i];
            cout<<endl;
        }
    }
};
int Comanda::contorComenzi=1000;

class Magazin{
private:
    string nume;
    int nrProduse;
    Produs *produse;
    Client *clienti;
    Comanda *comenzi;
    string adresa;
    double vanzariTotale;

public:
    Magazin(){
        this->nume = "PeriPC";
        this->nrProduse = 100;
        this->produse = new Produs[this->nrProduse];
        this->clienti = new Client[100];
        this->comenzi = new Comanda[100];
        this->adresa = "str. Perifericelor";
        this->vanzariTotale = 69420.3;
    }

    Magazin(string nume, int nrProduse, Produs* produse, string adresa, double vanzariTotale){
        this->nume = nume;
        this->nrProduse = nrProduse;
        for(int i = 0; i< this->nrProduse; i++)
            this->produse[i] = produse[i];
        this->adresa = adresa;
        this->vanzariTotale = vanzariTotale;
    }

    Magazin(string nume){
        this->nume = nume;
        this->nrProduse = 0;
        this->produse = NULL;
        this->adresa = "-";
        this->vanzariTotale = 0;
    }

    Magazin(string nume, string adresa){
        this->nume = nume;
        this->nrProduse = 0;
        this->produse = NULL;
        this->adresa = adresa;
        this->vanzariTotale = 0;
    }

    Magazin(const Magazin& mag){
        this->nume = mag.nume;
        this->nrProduse = mag.nrProduse;
        for(int i = 0; i < this->nrProduse; i++)
            this->produse[i] = mag.produse[i];
        this->adresa = mag.adresa;
        this->vanzariTotale = mag.vanzariTotale;
    }

    ~Magazin(){
        if(this->produse != NULL)
            delete[] this-> produse;
    }

    Magazin& operator=(const Magazin& mag){
        this->nume = mag.nume;
        this->nrProduse = mag.nrProduse;
        for(int i = 0; i < this->nrProduse; i++)
            this->produse[i] = mag.produse[i];
        this->adresa = mag.adresa;
        this->vanzariTotale = mag.vanzariTotale;
    }

    void setNumeMagazin(string nume){
        this->nume = nume;
    }

    void setAdresaMagazin(string adresa){
        this->adresa = adresa;
    }

    void setProduseMagazin(int nrProduse, Produs* produse){
        this->nrProduse = nrProduse;
        this->produse = new Produs[this->nrProduse];
        for(int i = 0; i < this->nrProduse; i++)
            this->produse[i] = produse[i];
    }

    string getNumeMagazin(){
        return this->nume;
    }

    string getAdresaMagazin(){
        return this->adresa;
    }

    Produs* getProduseComanda(){
        return this->produse;
    }

    Magazin operator+(Produs& produs){
        Produs* aux = new Produs[nrProduse];
        for(int i = 0; i < nrProduse ;i++)
            aux[i]=this->produse[i];
        delete[] this->produse;
        this->nrProduse++;
        produse = new Produs[nrProduse];
        for(int i = 0; i < nrProduse-1 ;i++)
            this->produse[i]=aux[i];
        produse[nrProduse-1]=produs;
    }

    Produs operator[](int index){
        if(index < this-> nrProduse)
            return this->produse[index];
    }

    friend istream& operator>>(istream&in, Magazin& mag){
        cout<<"Numele magazinului este: ";
        in>>mag.nume;
        cout<<"Adresa magazinului este: ";
        in>>mag.adresa;
        int alegere, continua = 1;
        mag.nrProduse = 0;
        while(continua == 1){
            cout<<"1.Add product\n";
            cout<<"2.Stop\n"<<endl;
            cin>>alegere;
            cout<<endl;
            switch (alegere){
                case 1:{
                    Produs* aux = new Produs[mag.nrProduse];
                    for(int i = 0; i< mag.nrProduse; i++)
                        aux[i] = mag.produse[i];
                    delete[] mag.produse;
                    mag.nrProduse++;
                    mag.produse = new Produs[mag.nrProduse];
                    Produs prod;
                    cin>>prod;
                    for(int i = 0; i < mag.nrProduse-1; i++)
                        mag.produse[i]=aux[i];
                    mag.produse[mag.nrProduse-1]=prod;
                    break;
                }
                case 2:{
                    continua = 0;
                    break;
                }
                default: {
                    cout<<"Comanda incorecta\n"<<endl;
                    break;
                }
            }
        }
    }

    friend ostream& operator<<(ostream& out, const Magazin& mag){
        out<<"Magazinul se numeste "<<mag.nume<<endl;
        out<<"Adresa magazinului este "<<mag.adresa<<endl;
        out<<"Magazinul are vanzari totale in valoare de "<<mag.vanzariTotale<<" lei"<<endl<<endl;
    }

    void afisProdseDisponibileDinMagazin(){
        for(int i = 0; i < this->nrProduse; i++)
            if(this->produse[i].getDisponibilProdus())
                cout<<produse[i];
    }

    void meniu(){
    int alegere, continua = 1;
    while(continua){
        cout<<"Menu"<<endl;
        cout<<"1.Create"<<endl;
        cout<<"2.Read"<<endl;
        //cout<<"3.Update"<<endl;
        //cout<<"4.Delete"<<endl;
        cout<<"0.Stop"<<endl;
        cout<<endl;
        cin>>alegere;
        cout<<endl;
        switch(alegere){
            case 1:{
                int alegereDoi;
                cout<<"1.Create product"<<endl;
                cout<<"2.Create order"<<endl;
                cout<<"3.Create customer"<<endl;
                cout<<"0.Cancel"<<endl;
                cout<<endl;
                cin>>alegereDoi;
                cout<<endl;

                switch(alegereDoi){
                    case 1:{
                        cin>>this->produse[numarProduse++];
                        break;
                    }
                    case 2:{
                        cout<<"Add customer number ";
                        int custnrr, nrProd, idProd;
                        cin>>custnrr;
                        cout<<endl;
                      //  Comanda c(this->clienti[custnrr]);
                        //cout<<c;
                        cout<<"Add number of products ";
                        cin>>nrProd;
                        cout<<endl;
                        Produs produse[nrProd];
                        for(int i = 0; i < nrProd; i++){
                            cout<<"Enter product ID ";
                            cin>>idProd;
                            cout<<endl;
                            produse[i] = this->produse[idProd];
                        }
                        Comanda c(this->clienti[custnrr], nrProd, produse);
                        comenzi[numarComenzi++] = c;
                        //cin>>this->comenzi[numarComenzi++];
                        break;
                    }
                    case 3:{
                        cin>>this->clienti[numarClienti++];
                        break;
                    }
                    case 0:{
                        cout<<"Creation cancelled"<<endl<<endl;
                        break;
                    }
                    default:{
                        cout<<"Wrong command"<<endl<<endl;
                        break;
                    }
                }
                break;}
            case 2:{
                int alegereTrei;
                cout<<"1.Read product"<<endl;
                cout<<"2.Read order"<<endl;
                cout<<"3.Read customer"<<endl;
                cout<<"0.Cancel"<<endl;
                cout<<endl;
                cin>>alegereTrei;
                cout<<endl;
                switch(alegereTrei){
                    case 1:{
                        int prodnr;
                        cout<<"Product number? ";
                        cin>>prodnr;
                        cout<<endl;
                        cout<<this->produse[prodnr];
                        break;
                    }
                    case 2:{
                        int ordnr;
                        cout<<"Order number? ";
                        cin>>ordnr;
                        cout<<endl;
                        cout<<this->comenzi[ordnr];
                        break;
                    }
                    case 3:{
                        int custnr;
                        cout<<"Customer number? ";
                        cin>>custnr;
                        cout<<endl;
                        cout<<this->clienti[custnr];
                        break;
                    }
                    case 0:{
                        cout<<"Read cancelled"<<endl<<endl;
                        break;
                    }
                    default:{
                        cout<<"Wrong command"<<endl<<endl;
                        break;
                    }
                }
                break;}
            case 3:{
                cout<<"Updating is not yet allowed"<<endl<<endl;
                break;}
            case 4:{
                cout<<"Deleting is not yet allowed"<<endl<<endl;
                break;}
            case 0:{
                continua = 0;
                cout<<"Menu has been closed"<<endl;
                break;}
            default:{
                cout<<"Wrong command"<<endl;
                break;}
            }
        }
    }
};

int main(){
    Magazin mag;
    cout<<mag;
    mag.meniu();

    return 0;
}
