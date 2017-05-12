#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

class Sprzet {
private:
    int id;
    string typ;
public:
    void sprzet(int id, string typ) {
        this->id = id;
        this->typ = typ;
    }

    int zwrocId() {
        return id;
    }

    string zwrocTypPojazdu() {
        return typ;
    }

    void zmienId(int id) {
        this->id = id;
    }

    void zmienTyp(string typ) {
        this->typ = typ;
    }
};

class Osoba {
private:
    int id;
    string nazwisko;
    int wiek;
public:
    void osoba(int id, string nazwisko, int wiek) {
        this->id = id;
        this->nazwisko = nazwisko;
        this->wiek = wiek;
    }

    int zwrocId() {
        return id;
    }

    string zwrocNazwisko() {
        return nazwisko;
    }

    double zwrocWiek() {
        return wiek;
    }

    void zmienId(int id) {
        this->id = id;
    }

    void zmienNazwisko(string nazwisko) {
        this->nazwisko = nazwisko;
    }

    void zmienWiek(int wiek) {
        this->wiek = wiek;
    }
};

class Wypozyczenia {
private:
    int idSprzet;
    int idOsoba;
public:
    void wypozyczenia(int idSprzet, int idOsoba) {
        this->idSprzet = idSprzet;
        this->idOsoba = idOsoba;
    }

    int zwrocIdSprzetu() {
        return idSprzet;
    }

    int zwrocIdOsoba() {
        return idOsoba;
    }

    void zmienIdSprzetu(int id) {
        this->idSprzet = id;
    }

    void zmienIdOsoby(int id) {
        this->idOsoba = id;
    }
};

void dodajSprzet(Sprzet listaSprzetu[], int &liczbaSprzetu);

void dodajOsobe(Osoba listaOsob[], int &liczbaOsob);

void dodajWypozyczenie(Wypozyczenia listaWypozyczen[], int &liczbaWypozyczen);

void zapiszTabliceDoPlikow(Sprzet listaSprzetu[], fstream &plikSprzet, int &liczbaSprzetu);

void zapiszTabliceDoPlikow(Osoba listaOsob[], fstream &plikOsoby, int &liczbaOsob);

void zapiszTabliceDoPlikow(Wypozyczenia listaWypozyczen[], fstream &plikWypozyczenia, int &liczbaWypozyczen);

void zapiszPlikDoTablicy(Sprzet listaSprzetu[], fstream &plikSprzet);

void zapiszPlikDoTablicy(Osoba listaOsob[], fstream &plikOsoby);

void zapiszPlikDoTablicy(Wypozyczenia listaWypozyczen[], fstream &plikWypozyczenia);

void wyswietlPodpunkt3(Sprzet listaSprzetu[], Osoba listaOsob[], Wypozyczenia listaWypozyczen[]);

int main() {
    int liczbaSprzetu = 0;
    int liczbaOsob = 0;
    int liczbaWypozyczen = 0;

    // Tworzymy trzy pliki do zapisu i odczytu.
    fstream plikSprzet;
    plikSprzet.open("Sprzet.txt", ios_base::in | ios_base::out | ios_base::binary);
    plikSprzet.clear();

    fstream plikOsoby;
    plikOsoby.open("Osoby.txt", ios_base::in | ios_base::out | ios_base::binary);
    plikOsoby.clear();

    fstream plikWypozyczenia;
    plikWypozyczenia.open("Wypozyczenia.txt", ios_base::in | ios_base::out | ios_base::binary);
    plikWypozyczenia.clear();

    Sprzet listaSprzetu[50];
    Osoba listaOsob[50];
    Wypozyczenia listaWypozyczen[50];

    //zapisujemy dane dla poszczegolnych obiektow w tablicach.
    dodajSprzet(listaSprzetu, liczbaSprzetu);
    dodajOsobe(listaOsob, liczbaOsob);
    dodajWypozyczenie(listaWypozyczen, liczbaWypozyczen);

    //zapisujemy zawartosc tablic w plikach
    zapiszTabliceDoPlikow(listaSprzetu, plikSprzet, liczbaSprzetu);
    zapiszTabliceDoPlikow(listaOsob, plikOsoby, liczbaOsob);
    zapiszTabliceDoPlikow(listaWypozyczen, plikWypozyczenia, liczbaWypozyczen);

    //zapisujemy zawartosc plikow w tablicach
    zapiszPlikDoTablicy(listaSprzetu, plikSprzet);
    zapiszPlikDoTablicy(listaOsob, plikOsoby);
    zapiszPlikDoTablicy(listaWypozyczen, plikWypozyczenia);

    //Wyswietlamy dane do podpunktu 3 (osoby 25 + ktore kupily hulajnoge)
    wyswietlPodpunkt3(listaSprzetu, listaOsob, listaWypozyczen);

    return 0;
}

void dodajSprzet(Sprzet listaSprzetu[], int &liczbaSprzetu) {
    int id;
    string typ;

    for (;;) {
        cout << " nacisnij T, aby dodac nowy Sprzet: \n";

        if (getch() != 'T') break;
        cout << "Podaj dane Sprzetu (ID | Typ): ";
        cin >> id >> typ;
        listaSprzetu[liczbaSprzetu].sprzet(id, typ);
        liczbaSprzetu++;
    }
}

void dodajOsobe(Osoba listaOsob[], int &liczbaOsob) {
    int id;
    string nazwisko;
    int wiek;

    for (;;) {
        cout << " nacisnij T, aby dodac nowa Osobe): \n";

        if (getch() != 'T') break;
        cout << "Podaj dane Osoby (ID | Nazwisko | Wiek: ";
        cin >> id >> nazwisko >> wiek;
        listaOsob[liczbaOsob].osoba(id, nazwisko, wiek);
        liczbaOsob++;
    }
}

void dodajWypozyczenie(Wypozyczenia listaWypozyczen[], int &liczbaWypozyczen) {
    int idSprzet;
    int idOsoba;

    for (;;) {
        cout << " nacisnij T, aby dodac nowe Wypozyczenie: \n";

        if (getch() != 'T') break;
        cout << "Podaj dane Wypozyczenia (IdSprzetu | IdOsoby): ";
        cin >> idSprzet >> idOsoba;
        listaWypozyczen[liczbaWypozyczen].wypozyczenia(idSprzet, idOsoba);
        liczbaWypozyczen++;
    }
}

void zapiszTabliceDoPlikow(Sprzet listaSprzetu[], fstream &plikSprzet, int &liczbaSprzetu) {
    for (int i = 0; i < liczbaSprzetu; i++) {
        plikSprzet << listaSprzetu[i].zwrocId() << " " << listaSprzetu[i].zwrocTypPojazdu() << endl;
    }
    plikSprzet.close();
}

void zapiszTabliceDoPlikow(Osoba listaOsob[], fstream &plikOsoby, int &liczbaOsob) {
    for (int i = 0; i < liczbaOsob; i++) {
        plikOsoby << listaOsob[i].zwrocId() << " " << listaOsob[i].zwrocNazwisko()
                  << " " << listaOsob[i].zwrocWiek() << endl;
    }
    plikOsoby.close();
}

void zapiszTabliceDoPlikow(Wypozyczenia listaWypozyczen[], fstream &plikWypozyczenia, int &liczbaWypozyczen) {
    for (int i = 0; i < liczbaWypozyczen; i++) {
        plikWypozyczenia << listaWypozyczen[i].zwrocIdSprzetu()
                         << " " << listaWypozyczen[i].zwrocIdOsoba() << endl;
    }
    plikWypozyczenia.close();
}

void zapiszPlikDoTablicy(Sprzet listaSprzetu[], fstream &plikSprzet) {
    int i = 0;
    int id;
    string typ;

    while (plikSprzet.good()) {
        plikSprzet >> id >> typ;
        listaSprzetu[i].zmienId(id);
        listaSprzetu[i].zmienTyp(typ);
        i++;
    }
}

void zapiszPlikDoTablicy(Osoba listaOsob[], fstream &plikOsoby) {
    int i = 0;
    int id;
    string nazwisko;
    int wiek;

    while (plikOsoby.good()) {
        plikOsoby >> id >> nazwisko >> wiek;
        listaOsob[i].zmienId(id);
        listaOsob[i].zmienNazwisko(nazwisko);
        listaOsob[i].zmienWiek(wiek);
        i++;
    }
}

void zapiszPlikDoTablicy(Wypozyczenia listaWypozyczen[], fstream &plikWypozyczenia) {
    int i = 0;
    int idSprzet;
    int idOsoba;

    while (plikWypozyczenia.good()) {
        plikWypozyczenia >> idSprzet >> idOsoba;
        listaWypozyczen[i].zmienIdSprzetu(idSprzet);
        listaWypozyczen[i].zmienIdOsoby(idOsoba);
        i++;
    }
}

void wyswietlPodpunkt3(Sprzet listaSprzetu[], Osoba listaOsob[], Wypozyczenia listaWypozyczen[]) {
    int i = 0;
    int j = 0;

    cout << "Osoby majace co najmniej 25 lat, ktore kupily hulajnoge: \n";
    for (int k = 0; k < 50; k++) {
        if (listaWypozyczen[k].zwrocIdSprzetu() == listaSprzetu[i].zwrocId()) {
            if (listaWypozyczen[k].zwrocIdOsoba() == listaOsob[j].zwrocId()) {
                if (listaOsob[j].zwrocWiek() > 25 && listaSprzetu[i].zwrocTypPojazdu() == "hulajnoga") {
                    cout << listaOsob[i].zwrocNazwisko() << endl;
                } else
                    k++;
            } else
                j++;
        } else
            i++;
    }
}


