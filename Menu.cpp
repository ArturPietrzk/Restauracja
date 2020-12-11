#include<iostream>
#include<conio.h>

using namespace std;
class Szef_kuchni {

public:
	int NumerIDPracownika;
	string ImieSzefaKuchni;
	string NazwiskoSzefaKuchni;
};

class Kelner
{
public:
	int NumerIDPracownika;
	string ImieKelnera;
	string NazwiskoKelnera;
};

class Dostawca {

public:
	int NumerIDPracownika;
	string ImieDostawcy;
	string NazwiskoDostawcy;
};

class Manager {

public:
	int NumerIDPracownika;
	string ImieManagera;
	string NazwiskoManagera;
};

class Magazyn
{
public:
	int NumerIdProduktu;
	string NazwaProduktu;
	double CenaProduktu;
	void SprawdzenieStanuZaopatrzenia();
	void ZlozenieZamowienia();
	void DostarczenieZamowienia();
	void ZmianaStanuMagazynu();
};

class Napoje {

public:
	int NumerIDNapoju;
	string NazwaNapoju;
	double CenaNapoju;
};

class Posilki
{
public:
	int NumerIDPosilku;
	string NazwaPosilku;
	double CenaPosilku;
	bool PrzygotowaniePosilku();
};

class Zamowienie
{
public:
	int NumerIDZamowienia;
	//date TerminZamowienia;
	int NumerKelneraTegoZamowienia;
	int KolejnoscZamowienia;
	double ZnizkaNaZamowienie;
	string StatusZamowienia;
	string RodzajPlatnosciZaZamowienie;
	string Na_miejscu_Na_wynos;
	void PrzygotowanieZamowienia();
	void SerwowanieZamowienia();
	void WydrukRachunku();
};

class Rachunek
{
	int NumerIDRachunku;
	//Data wystawienia rachunku
	string PozycjeZamowienia;
	double CalkowityKosztZamowienia;
	void PrzekazanieRachunku();
	double OdebranieZaplaty();
};


int main()
{

//  MENU  //////////////////////
int ilosc_napojow = 6;
int ilosc_posilkow = 5;


Napoje *tab_Napoje = new Napoje[ilosc_napojow];

Posilki *tab_Posilki = new Posilki[ilosc_posilkow];

tab_Napoje[0] = {1, "Woda mineralna 0,5l", 4};
tab_Napoje[1] = {2, "Pepsi 0,5l", 5};
tab_Napoje[2] = {3, "Mirinda 0,5l", 5};
tab_Napoje[3] = {4, "Sprite 0,5l", 5};
tab_Napoje[4] = {5, "Tymbark - pomarañcza 0,5l", 5};
tab_Napoje[5] = {6, "Tymbark - wiœnia, jab³ko 0,5l", 5};

tab_Posilki[0] = {1, "Pierogi ruskie", 15};
tab_Posilki[1] = {2, "Pierogi z miêsem", 17};
tab_Posilki[2] = {3, "Pierogi z truskawkami", 14};
tab_Posilki[3] = {4, "Naleœniki z serem", 15};
tab_Posilki[4] = {5, "Kotlet schabowy z grillowanymi warzywami, 25"};



//  LOGOWANIE  //////////////////
	string login;
	string password = "";
	string correctPasswordChef = "szefkuchni";
	string correctPasswordWaiter = "kelner";
	string correctPasswordManager = "manager";
	string correctPasswordSupplier = "dostawca";
	unsigned tries = 3;
	char character = ' ';


	//cin >> login;



	for(;;){
        cout << "Podaj login" << endl;
        cin >> login;
		if (login == "Kelner")
		{
			cout << "Wpisano login dla kelnera" << endl;
			do {
				cout << "Wpisz haslo: ";
				while ((character = _getch()) != '\r') {
					cout << "*";
					password += character;
				}

				if (password != correctPasswordWaiter) {
					password = "";
					tries -= 1;
					cout << "\nDostepne proby: " << tries << endl;
				}
			} while (tries > 0 && password != correctPasswordWaiter);

			if (tries == 0) cout << "\nUzytkownik zablokowany!\n";
			else cout << "\nHaslo poprawne. Witamy w systemie!\n";
            break;
		}
		else if (login == "SzefKuchni")
		{
			cout << "Wpisano login dla szefa kuchni" << endl;
			do {
				cout << "Wpisz haslo: ";
				while ((character = _getch()) != '\r') {
					cout << "*";
					password += character;
				}

				if (password != correctPasswordChef) {
					password = "";
					tries -= 1;
					cout << "\nDostepne proby: " << tries << endl;
				}
			} while (tries > 0 && password != correctPasswordChef);

			if (tries == 0) cout << "\nUzytkownik zablokowany!\n";
			else cout << "\nHaslo poprawne. Witamy w systemie!\n";
            break;
		}

		else if (login == "Manager")
		{
			cout << "Wpisano login dla Managera" << endl;
			do {
				cout << "Wpisz haslo: ";
				while ((character = _getch()) != '\r') {
					cout << "*";
					password += character;
				}

				if (password != correctPasswordManager) {
					password = "";
					tries -= 1;
					cout << "\nDostepne proby: " << tries << endl;
				}
			} while (tries > 0 && password != correctPasswordManager);

			if (tries == 0) cout << "\nUzytkownik zablokowany!\n";
			else cout << "\nHaslo poprawne. Witamy w systemie szefie!\n";
			break;
		}

		else if (login == "Dostawca")
		{
			cout << "Wpisano login dla dostawcy" << endl;
			do {
				cout << "Wpisz haslo: ";
				while ((character = _getch()) != '\r') {
					cout << "*";
					password += character;
				}

				if (password != correctPasswordSupplier) {
					password = "";
					tries -= 1;
					cout << "\nDostepne proby: " << tries << endl;
				}
			} while (tries > 0 && password != correctPasswordSupplier);

			if (tries == 0) cout << "\nUzytkownik zablokowany!\n";
			else cout << "\nHaslo poprawne. Witamy w systemie!\n";
			break;
		}
		else{

            cout << "Podano zly login, skontaktuj sie z administratorem w celu zmiany loginu i hasla badz wpisz jeszcze raz: " << endl;
           // break;


		}
	}







	cout<<endl << "Restaurant project by: Michal Nycz, Jakub Pietrzak, Artur Pietrzkiewicz" << endl;

    delete [] tab_Napoje;
    delete [] tab_Posilki;

	return 0;
}
