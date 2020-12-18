#include<iostream>
#include<conio.h>
#include<Windows.h>

using namespace std;
class Szef_kuchni {

public:
	int NumerIDPracownika;
	string ImieSzefaKuchni;
	string NazwiskoSzefaKuchni;
	char character = ' ';
	unsigned tries = 3;
	Szef_kuchni();
	void LogowanieSzefKuchni();
private:
	string PasswordChef;
	string password = "";
};
Szef_kuchni::Szef_kuchni()
{
	PasswordChef = "szefkuchni";
}
void Szef_kuchni::LogowanieSzefKuchni()
{
	cout << "Wpisano login dla szefa kuchni" << endl;
	do {
		cout << "Wpisz haslo: ";
		while ((character = _getch()) != '\r') {
			cout << "*";
			password += character;
		}

		if (password != PasswordChef) {
			password = "";
			tries -= 1;
			cout << "\nDostepne proby: " << tries << endl;
		}
	} while (tries > 0 && password != PasswordChef);

	if (tries == 0) cout << "\nUzytkownik zablokowany!\n";
	else cout << "\nHaslo poprawne. Witamy w systemie!\n";
}

class Kelner
{
public:
	int NumerIDPracownika;
	string ImieKelnera;
	string NazwiskoKelnera;
	char character = ' ';
	unsigned tries = 3;
	Kelner();
	void LogowanieKelner();
private:
	string PasswordWaiter;
	string password = "";
};

Kelner::Kelner()
{
	PasswordWaiter = "kelner";
}
void Kelner::LogowanieKelner()
{
	cout << "Wpisano login dla kelnera" << endl;
	do {
		cout << "Wpisz haslo: ";
		while ((character = _getch()) != '\r') {
			cout << "*";
			password += character;
		}

		if (password != PasswordWaiter) {
			password = "";
			tries -= 1;
			cout << "\nDostepne proby: " << tries << endl;
		}
	} while (tries > 0 && password != PasswordWaiter);

	if (tries == 0) cout << "\nUzytkownik zablokowany!\n";
	else cout << "\nHaslo poprawne. Witamy w systemie!\n";
}

class Dostawca {

public:
	int NumerIDPracownika;
	string ImieDostawcy;
	string NazwiskoDostawcy;
	char character = ' ';
	unsigned tries = 3;
	Dostawca();
	void LogowanieDostawca();
private:
	string PasswordSupplier;
	string password = "";
};

Dostawca::Dostawca()
{
	PasswordSupplier = "dostawca";
}
void Dostawca::LogowanieDostawca()
{
	cout << "Wpisano login dla dostawcy" << endl;
	do {
		cout << "Wpisz haslo: ";
		while ((character = _getch()) != '\r') {
			cout << "*";
			password += character;
		}

		if (password != PasswordSupplier) {
			password = "";
			tries -= 1;
			cout << "\nDostepne proby: " << tries << endl;
		}
	} while (tries > 0 && password != PasswordSupplier);

	if (tries == 0) cout << "\nUzytkownik zablokowany!\n";
	else cout << "\nHaslo poprawne. Witamy w systemie!\n";


}

class Manager {

public:
	int NumerIDPracownika;
	string ImieManagera;
	string NazwiskoManagera;
	char character = ' ';
	unsigned tries = 3;
	Manager();
	void LogowanieManager();
private:
	string PasswordManager;
	string password = "";
};
Manager::Manager()
{
	PasswordManager = "manager";
}
void Manager::LogowanieManager()
{
	cout << "Wpisano login dla Managera" << endl;
	do {
		cout << "Wpisz haslo: ";
		while ((character = _getch()) != '\r') {
			cout << "*";
			password += character;
		}

		if (password != PasswordManager) {
			password = "";
			tries -= 1;
			cout << "\nDostepne proby: " << tries << endl;
		}
	} while (tries > 0 && password != PasswordManager);

	if (tries == 0) cout << "\nUzytkownik zablokowany!\n";
	else cout << "\nHaslo poprawne. Witamy w systemie szefie!\n";
}

class Napoje
{

friend class Magazyn;

public:
	int NumerIDNapoju;
	string NazwaNapoju;
	double Ilosc_Napoju;
	double CenaNapoju;

};

class Produkty
{
    friend class Posilki;

public:
    int NumerIDProduktu;
	string NazwaProduktu;
	double Ilosc_Produktu;
	double CenaProduktu;

};

class Posilki
{
friend class Magazyn;

public:
    int ilosc_produktow;
    Produkty* tab_Produktow;
	int NumerIDPosilku;
	string NazwaPosilku;

	double CenaPosilku;
	Posilki();
	Posilki(int a);
	~Posilki();
	bool PrzygotowaniePosilku();
};
Posilki::Posilki()
{

}
Posilki::Posilki(int a)
{
    ilosc_produktow = a;
    tab_Produktow = new Produkty[ilosc_produktow];
}

Posilki::~Posilki()
{
    delete[] tab_Produktow;
}



class Magazyn
{
public:
    int ilosc_napojow;
	int ilosc_posilkow;

	Napoje* tab_Napoje;

	Posilki* tab_Posilki;

	int NumerIdProduktu;
	string NazwaProduktu;
	double CenaProduktu;
	Magazyn(int a, int b);
	~Magazyn();
	void SprawdzenieStanuZaopatrzenia();
	void ZlozenieZamowienia();
	void DostarczenieZamowienia();
	void ZmianaStanuMagazynu();
};

Magazyn::Magazyn(int a, int b)
{
    ilosc_napojow = a;
    ilosc_posilkow = b;
    tab_Napoje = new Napoje[ilosc_napojow];
	tab_Posilki = new Posilki[ilosc_posilkow];
}

Magazyn::~Magazyn()
{
    delete[] tab_Napoje;
	delete[] tab_Posilki;
}




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

	//  MAGAZYN  //////////////////////

	Magazyn magazyn1(6, 5);



	magazyn1.tab_Napoje[0] = { 1, "Woda mineralna 0,5l", 4, 100 };
	magazyn1.tab_Napoje[1] = { 2, "Pepsi 0,5l", 5, 100 };
	magazyn1.tab_Napoje[2] = { 3, "Mirinda 0,5l", 5, 200 };
	magazyn1.tab_Napoje[3] = { 4, "Sprite 0,5l", 5, 50 };
	magazyn1.tab_Napoje[4] = { 5, "Tymbark - pomara�cza 0,5l", 5, 20 };
	magazyn1.tab_Napoje[5] = { 6, "Tymbark - wi�nia, jab�ko 0,5l", 5, 10 };



	magazyn1.tab_Posilki[0] = { 1, "Pierogi ruskie", 15 };
	magazyn1.tab_Posilki[1] = { 2, "Pierogi z mi�sem", 17 };
	magazyn1.tab_Posilki[2] = { 3, "Pierogi z truskawkami", 14 };
	magazyn1.tab_Posilki[3] = { 4, "Nale�niki z serem", 15 };
	magazyn1.tab_Posilki[4] = { 5, "Kotlet schabowy z grillowanymi warzywami", 25 };



	//  LOGOWANIE  //////////////////
	string login;

	for (;;)
	{
		cout << "\n\n\n\n";
		cout << "\t\t*************************************************" << endl;
		cout << "\t\t*                                               *" << endl;
		cout << "\t\t*            WITAJ W SYSTEMIE RESTAURACJI !     *" << endl;
		cout << "\t\t*                                               *" << endl;
		cout << "\t\t*    DOSTEPNI UZYTKOWNICY:                      *" << endl;
		cout << "\t\t*  - Manager                                    *" << endl;
		cout << "\t\t*  - Kelner                                     *" << endl;
		cout << "\t\t*  - SzefKuchni                                 *" << endl;
		cout << "\t\t*  - Dostawca                                   *" << endl;
		cout << "\t\t*                                               *" << endl;
		cout << "\t\t*  WYBIERZ KONTO WPISUJAC LOGIN UZYTKOWNIKA     *" << endl;
		cout << "\t\t*                                               *" << endl;
		cout << "\t\t*************************************************" << endl;

		cout << "Wpisz login: " << endl;
		cin >> login;

		if (login == "Kelner")
		{
			Kelner* kelner1 = new Kelner;
			kelner1->LogowanieKelner();
			break;
		}
		else if (login == "SzefKuchni")
		{
			Szef_kuchni* szef = new Szef_kuchni;
			szef->LogowanieSzefKuchni();
			break;
		}
		else if (login == "Dostawca")
		{
			Dostawca* dostawca1 = new Dostawca;
			dostawca1->LogowanieDostawca();
			break;
		}
		else if (login == "Manager")
		{
			Manager* manager1 = new Manager;
			manager1->LogowanieManager();
			break;
		}
		else
		{
			cout << "Podano zly login, skontaktuj sie z administratorem w celu zmiany loginu i hasla badz wpisz jeszcze raz: " << endl;
			Sleep(2000);
			system("cls");
		}
	}








	cout << endl << "Restaurant project by: Michal Nycz, Jakub Pietrzak, Artur Pietrzkiewicz" << endl;



	return 0;
}
