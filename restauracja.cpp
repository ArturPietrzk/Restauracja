#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<fstream>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#pragma warning(disable : 4996)

using namespace std;

std::string PL(const char* text)
{
	std::string result;
	for (; *text; text++)
		switch (*text)
		{
		case 'ą': result += static_cast <char>(0xa5); break;
		case 'ć': result += static_cast <char>(0x86); break;
		case 'ę': result += static_cast <char>(0xa9); break;
		case 'ł': result += static_cast <char>(0x88); break;
		case 'ń': result += static_cast <char>(0xe4); break;
		case 'ó': result += static_cast <char>(0xa2); break;
		case 'ś': result += static_cast <char>(0x98); break;
		case 'ż': result += static_cast <char>(0xbe); break;
		case 'ź': result += static_cast <char>(0xab); break;
		case 'Ą': result += static_cast <char>(0xa4); break;
		case 'Ć': result += static_cast <char>(0x8f); break;
		case 'Ę': result += static_cast <char>(0xa8); break;
		case 'Ł': result += static_cast <char>(0x9d); break;
		case 'Ń': result += static_cast <char>(0xe3); break;
		case 'Ó': result += static_cast <char>(0xe0); break;
		case 'Ś': result += static_cast <char>(0x97); break;
		case 'Ż': result += static_cast <char>(0xbd); break;
		case 'Ź': result += static_cast <char>(0x8d); break;
		default: result += *text; break;
		}
	return result;
}



int i, n;
ifstream fin;
ofstream fout;
fstream fio;
void pokaz_menu();
void PlaceCursor(const int x, const int y);

string welcome;
string goodbye;
string confirmed;
//string order = "";
//int choice;
int dlugosc;
//int bill_price = 0;
char counter;



int pierogi_ruskie_cena = 15;
int pierogi_z_miesem_cena = 17;
int pierogi_z_truskawkami_cena = 16;
int nalesniki_cena = 12;
int kotlet_cena = 20;

int woda_mineralna_cena = 5;
int pepsi_cena = 7;
int mirinda_cena = 7;
int sprite_cena = 7;
int tymbark_pomarancza_cena = 6;
int tymbark_wisnia_cena = 6;

//
////string pierogi_ruskie = "pierogi ruskie,";
//string pierogi_z_miesem = "pierogi z miesem,";
//string pierogi_z_truskawkami = "pierogi z truskawkami,";
//string nalesniki = "nalesniki z serem,";
//string kotlet = "kotlet schabowy z grillowanymi warzywami,";
//
//string woda_mineralna = "woda mineralna,";
//string pepsi = "pepsi,";
//string mirinda = "mirinda,";
//string sprite = "spirte,";
//string tymbark_pomarancza = "tymbark pomarancza,";
//string tymbark_wisnia = "tymbark wisnia jablko,";
class Zamowienie
{
public:
	int NumerIDZamowienia;
	//date TerminZamowienia;
	int NumerKelnetaTegoZamowienia;
	int KolejnoscZamowienia;
	double ZnizkaNaZamowienie;
	string StatusZamowienia;
	string RodzajPlatnosciZaZamowienie;
	string order;
	int choice;
	Zamowienie();
	void PrzygotowanieZamowienia();
	void SerwowanieZamowienia();
	void WydrukRachunku();
};
Zamowienie::Zamowienie() {
	order = "";
	choice = 0;



}

class Rachunek
{
public:
	int NumerIDRachunku;
	//Data wystawienia rachunku
	string PozycjeZamowienia;
	double CalkowityKosztZamowienia;
	int bill_price;
	Rachunek();
	void PrzekazanieRachunku();
	double OdebranieZaplaty();
};

Rachunek::Rachunek() {
	bill_price = 0;


}

void menu()
{
	cout << "_______________________________________________________" << endl;
	cout << "MENU NASZEJ RESTAURACJI: " << endl << endl;
	cout << "       POSILKI                                   CENA" << endl;
	cout << "   1. Pierogi ruskie                              15" << endl;
	cout << "   2. Pierogi z miesem                            17" << endl;
	cout << "   3. Pierogi z truskawkami                       16" << endl;
	cout << "   4. Nalesniki z serem                           12" << endl;
	cout << "   5. Kotlet schabowy z grillowanymi warzywami    20" << endl <<

		endl;
	cout << "       NAPOJE" << endl;
	cout << "   6. Woda mineralna  (0,5l)                      5" << endl;
	cout << "   7. Pepsi  (0,5l)                               7" << endl;
	cout << "   8. Mirinda  (0,5l)                             7" << endl;
	cout << "   9. Sprite  (0,5l)                              7" << endl;
	cout << "   10. Tymbark - pomarancza  (0,5l)               6" << endl;
	cout << "   11. Tymbark - wisnia, jablko  (0,5l)           6" << endl;
	cout << "_______________________________________________________" << endl;
}


class Szef_kuchni {

public:
	int NumerIDPracownika;
	string ImieSzefaKuchni;
	string NazwiskoSzefaKuchni;
	char character = ' ';
	unsigned tries = 3;
	Szef_kuchni();
	void LogowanieSzefKuchni();
	void WykonanieZamowienia(Zamowienie);
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
		while ((character = _getch()) != '\r')
		{
			if (character != 8)
			{
				cout << "*";
				password += character;
			}
			else
			{
				cout << ("\b \b");
			}
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

void Szef_kuchni::WykonanieZamowienia(Zamowienie a) {



	if (a.order.empty()) {
		cout << "Brak zlozonego zamowienia" << endl;



	}
	else {
		cout << "Zamowienie:" << a.order << endl;

	}


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
	void ZamowienieKelner(Zamowienie, Rachunek);
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
		while ((character = _getch()) != '\r')
		{
			if (character != 8)
			{
				cout << "*";
				password += character;
			}
			else
			{
				cout << ("\b \b");
			}
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

void Kelner::ZamowienieKelner(Zamowienie a, Rachunek b)
{
	system("cls");
	cout << welcome;
	welcome = "WITAM W SYSTEMIE OBSLUGI!\n\n*Wchodza klienci i siadaja do stolika.*\n*Podchodzi kelner i podaje MENU.*\n";

	dlugosc = welcome.length();

	for (int j = 0; j <= dlugosc; j++)
	{
		cout << welcome[j];
		Sleep(50);
	}
	Sleep(1000);

	menu();
	cout << endl;


	cout << "KELNER: Witam, czy mozna przyjac zamowienie?" << endl;
	cout << "KLIENT: Tak, oczywiscie." << endl << endl;
	Sleep(2000);

	cout << "*Wybierz pozycje do zamowienia" << endl << endl;
	
	
	do
	{
		cin >> a.choice;

		switch (a.choice)
		{
		case 1:
		{
			cout << "KLIENT: Poprosze pierogi ruskie." << endl;
			Sleep(2000);
			cout << "KELNER: Ile razy?" << endl;

			cin >> a.choice;

			if (a.choice == 1)
			{
				cout << "KLIENT: Poprosze raz.";

				counter = '1';

				a.order = a.order + " raz pierogi ruskie, ";
			}
			else
			{
				cout << "KLIENT: " << a.choice << " razy poprosze.";

				if (a.choice == 2)
					counter = '2';
				if (a.choice == 3)
					counter = '3';
				if (a.choice == 4)
					counter = '4';
				if (a.choice == 5)
					counter = '5';
				if (a.choice == 6)
					counter = '6';
				if (a.choice == 7)
					counter = '7';
				if (a.choice == 8)
					counter = '8';
				if (a.choice == 9)
					counter = '9';
				if (a.choice == 10)
					counter = '10';
				if (a.choice == 11)
					counter = '11';

				a.order = a.order + " " + counter + "razy pierogi ruskie, ";
			}

			b.bill_price = b.bill_price + (pierogi_ruskie_cena * a.choice);
		}break;
		case 2:
		{
			cout << "KLEINT: Poprosze pierogi z miesem." << endl;
			Sleep(2000);
			cout << "KELNER: Ile razy?" << endl;

			cin >> a.choice;

			if (a.choice == 1)
			{
				cout << "KLIENT: Raz poprosze.";

				counter = '1';

				a.order = a.order + " raz pierogi z miesem, ";
			}
			else
			{
				cout << "KLIENT: " << a.choice << " razy poprosze.";

				if (a.choice == 2)
					counter = '2';
				if (a.choice == 3)
					counter = '3';
				if (a.choice == 4)
					counter = '4';
				if (a.choice == 5)
					counter = '5';
				if (a.choice == 6)
					counter = '6';
				if (a.choice == 7)
					counter = '7';
				if (a.choice == 8)
					counter = '8';
				if (a.choice == 9)
					counter = '9';
				if (a.choice == 10)
					counter = '10';
				if (a.choice == 11)
					counter = '11';

				a.order = a.order + " " + counter + "razy pierogi z miesem, ";
			}

			b.bill_price = b.bill_price + (pierogi_z_miesem_cena * a.choice);
		}break;

		case 3:
		{
			cout << "KLIENT: Poprosze pierogi z truskawkami." << endl;
			Sleep(2000);
			cout << "KELNER: Ile razy?" << endl;

			cin >> a.choice;

			if (a.choice == 1)
			{
				cout << "KLIENT: Poprosze raz.";

				counter = '1';

				a.order = a.order + " raz pierogi z truskawkami, ";
			}
			else
			{
				cout << "KLIENT: " << a.choice << " razy poprosze.";

				if (a.choice == 2)
					counter = '2';
				if (a.choice == 3)
					counter = '3';
				if (a.choice == 4)
					counter = '4';
				if (a.choice == 5)
					counter = '5';
				if (a.choice == 6)
					counter = '6';
				if (a.choice == 7)
					counter = '7';
				if (a.choice == 8)
					counter = '8';
				if (a.choice == 9)
					counter = '9';
				if (a.choice == 10)
					counter = '10';
				if (a.choice == 11)
					counter = '11';

				a.order = a.order + " " + counter + "razy pierogi z truskawkami, ";
			}

			b.bill_price = b.bill_price + (pierogi_z_truskawkami_cena * a.choice);
		}break;

		case 4:
		{
			cout << "KLIENT: Poprosze nalesniki z serem." << endl;
			Sleep(2000);
			cout << "KELNER: Ile razy?" << endl;

			cin >> a.choice;

			if (a.choice == 1)
			{
				cout << "KLIENT: Poprosze raz.";

				counter = '1';

				a.order = a.order + " raz nalesniki z serem, ";
			}
			else
			{
				cout << "KLIENT: " << a.choice << " razy poprosze.";

				if (a.choice == 2)
					counter = '2';
				if (a.choice == 3)
					counter = '3';
				if (a.choice == 4)
					counter = '4';
				if (a.choice == 5)
					counter = '5';
				if (a.choice == 6)
					counter = '6';
				if (a.choice == 7)
					counter = '7';
				if (a.choice == 8)
					counter = '8';
				if (a.choice == 9)
					counter = '9';
				if (a.choice == 10)
					counter = '10';
				if (a.choice == 11)
					counter = '11';

				a.order = a.order + " " + counter + "razy nalesniki z serem, ";
			}

			b.bill_price = b.bill_price + (nalesniki_cena * a.choice);
		}break;

		case 5:
		{
			cout << "KLIENT: Poprosze kotleta schabowego z grillowanymi warzywami." << endl;
			Sleep(2000);
			cout << "KELNER: Ile razy?" << endl;

			cin >> a.choice;

			if (a.choice == 1)
			{
				cout << "KLIENT: Poprosze raz.";

				counter = '1';

				a.order = a.order + " raz kotlet schabowy z grillowanymi warzywami, ";
			}
			else
			{
				cout << "KLIENT: " << a.choice << " razy poprosze.";

				if (a.choice == 2)
					counter = '2';
				if (a.choice == 3)
					counter = '3';
				if (a.choice == 4)
					counter = '4';
				if (a.choice == 5)
					counter = '5';
				if (a.choice == 6)
					counter = '6';
				if (a.choice == 7)
					counter = '7';
				if (a.choice == 8)
					counter = '8';
				if (a.choice == 9)
					counter = '9';
				if (a.choice == 10)
					counter = '10';
				if (a.choice == 11)
					counter = '11';

				a.order = a.order + " " + counter + "razy kotlet schabowy z grillowanymi warzywami, ";
			}

			b.bill_price = b.bill_price + (kotlet_cena * a.choice);
		}break;

		case 6:
		{
			cout << "KLIENT: Do picia poprosze wode mineralna." << endl;
			Sleep(2000);
			cout << "KELNER: Ile razy?" << endl;

			cin >> a.choice;

			if (a.choice == 1)
			{
				cout << "KLIENT: Poprosze raz.";

				counter = '1';

				a.order = a.order + " raz woda mineralna, ";
			}
			else
			{
				cout << "KLIENT: " << a.choice << " razy poprosze.";

				if (a.choice == 2)
					counter = '2';
				if (a.choice == 3)
					counter = '3';
				if (a.choice == 4)
					counter = '4';
				if (a.choice == 5)
					counter = '5';
				if (a.choice == 6)
					counter = '6';
				if (a.choice == 7)
					counter = '7';
				if (a.choice == 8)
					counter = '8';
				if (a.choice == 9)
					counter = '9';
				if (a.choice == 10)
					counter = '10';
				if (a.choice == 11)
					counter = '11';

				a.order = a.order + " " + counter + "razy woda mineralna, ";
			}

			b.bill_price = b.bill_price + (woda_mineralna_cena * a.choice);
		}break;

		case 7:
		{
			cout << "KLIENT: Do picia poprosze Pepsi." << endl;
			Sleep(2000);
			cout << "KELNER: Ile razy?" << endl;

			cin >> a.choice;

			if (a.choice == 1)
			{
				cout << "KLIENT: Poprosze raz.";

				counter = '1';

				a.order = a.order + " raz Pepsi, ";
			}
			else
			{
				cout << "KLIENT: " << a.choice << " razy poprosze.";

				if (a.choice == 2)
					counter = '2';
				if (a.choice == 3)
					counter = '3';
				if (a.choice == 4)
					counter = '4';
				if (a.choice == 5)
					counter = '5';
				if (a.choice == 6)
					counter = '6';
				if (a.choice == 7)
					counter = '7';
				if (a.choice == 8)
					counter = '8';
				if (a.choice == 9)
					counter = '9';
				if (a.choice == 10)
					counter = '10';
				if (a.choice == 11)
					counter = '11';

				a.order = a.order + " " + counter + "razy Pepsi, ";
			}

			b.bill_price = b.bill_price + (pepsi_cena * a.choice);
		}break;

		case 8:
		{
			cout << "KLIENT: Do picia poprosze Mirinde." << endl;
			Sleep(2000);
			cout << "KELNER: Ile razy?" << endl;

			cin >> a.choice;

			if (a.choice == 1)
			{
				cout << "KLIENT: Poprosze raz.";

				counter = '1';

				a.order = a.order + " raz Mirinda, ";
			}
			else
			{
				cout << "KLIENT: " << a.choice << " razy poprosze.";

				if (a.choice == 2)
					counter = '2';
				if (a.choice == 3)
					counter = '3';
				if (a.choice == 4)
					counter = '4';
				if (a.choice == 5)
					counter = '5';
				if (a.choice == 6)
					counter = '6';
				if (a.choice == 7)
					counter = '7';
				if (a.choice == 8)
					counter = '8';
				if (a.choice == 9)
					counter = '9';
				if (a.choice == 10)
					counter = '10';
				if (a.choice == 11)
					counter = '11';

				a.order = a.order + " " + counter + "razy Mirinda, ";
			}

			b.bill_price = b.bill_price + (mirinda_cena * a.choice);
		}break;

		case 9:
		{
			cout << "KLIENT: Do picia poprosze Sprite." << endl;
			Sleep(2000);
			cout << "KELNER: Ile razy?" << endl;

			cin >> a.choice;

			if (a.choice == 1)
			{
				cout << "KLIENT: Poprosze raz.";

				counter = '1';

				a.order = a.order + " raz Sprite, ";
			}
			else
			{
				cout << "KLIENT: " << a.choice << " razy poprosze.";

				if (a.choice == 2)
					counter = '2';
				if (a.choice == 3)
					counter = '3';
				if (a.choice == 4)
					counter = '4';
				if (a.choice == 5)
					counter = '5';
				if (a.choice == 6)
					counter = '6';
				if (a.choice == 7)
					counter = '7';
				if (a.choice == 8)
					counter = '8';
				if (a.choice == 9)
					counter = '9';
				if (a.choice == 10)
					counter = '10';
				if (a.choice == 11)
					counter = '11';

				a.order = a.order + " " + counter + "razy Sprite, ";
			}

			b.bill_price = b.bill_price + (sprite_cena * a.choice);
		}break;

		case 10:
		{
			cout << "KLIENT: Do picia poprosze Tymbark o smaku pomaranczowym." << endl;
			Sleep(2000);
			cout << "KELNER: Ile razy?" << endl;

			cin >> a.choice;

			if (a.choice == 1)
			{
				cout << "KLIENT: Poprosze raz.";

				counter = '1';

				a.order = a.order + " raz Tymbark pomarancza, ";
			}
			else
			{
				cout << "KLIENT: " << a.choice << " razy poprosze.";

				if (a.choice == 2)
					counter = '2';
				if (a.choice == 3)
					counter = '3';
				if (a.choice == 4)
					counter = '4';
				if (a.choice == 5)
					counter = '5';
				if (a.choice == 6)
					counter = '6';
				if (a.choice == 7)
					counter = '7';
				if (a.choice == 8)
					counter = '8';
				if (a.choice == 9)
					counter = '9';
				if (a.choice == 10)
					counter = '10';
				if (a.choice == 11)
					counter = '11';

				a.order = a.order + " " + counter + "razy Tymbark pomarancza, ";
			}

			b.bill_price = b.bill_price + (tymbark_pomarancza_cena * a.choice);
		}break;

		case 11:
		{
			cout << "KLIENT: Do picia poprosze Tymbark o smaku wisni z jablkiem." << endl;
			Sleep(2000);
			cout << "KELNER: Ile razy?" << endl;

			cin >> a.choice;

			if (a.choice == 1)
			{
				cout << "KLIENT: Poprosze raz.";

				counter = '1';

				a.order = a.order + " raz Tymbark wisnia jablko, ";
			}
			else
			{
				cout << "KLIENT: " << a.choice << " razy poprosze.";

				if (a.choice == 2)
					counter = '2';
				if (a.choice == 3)
					counter = '3';
				if (a.choice == 4)
					counter = '4';
				if (a.choice == 5)
					counter = '5';
				if (a.choice == 6)
					counter = '6';
				if (a.choice == 7)
					counter = '7';
				if (a.choice == 8)
					counter = '8';
				if (a.choice == 9)
					counter = '9';
				if (a.choice == 10)
					counter = '10';
				if (a.choice == 11)
					counter = '11';

				a.order = a.order + " " + counter + "razy Tymbark wisnia jablko, ";
			}

			b.bill_price = b.bill_price + (tymbark_wisnia_cena * a.choice);
		}break;

		default:
		{
			cout << "KELNER: Przepraszam, ale niestety nie mamy takiej pozycji w naszym MENU.";
			Sleep(2000);
		}break;
		}

		Sleep(2000);
		cout << endl << "KELNER: Czy bedzie cos jeszcze?";
		Sleep(2000);

		cout << endl << endl << "*1. Dodaj inne pozycje do zamowienia.*" << endl;
		cout << "*(dowolony przycisk) Zakoncz zamowienie.*" << endl;

		cin >> a.choice;

		if (a.choice == 1)
		{
			cout << endl << "KLIENT: Tak, jeszcze cos domowie." << endl;
			Sleep(2000);
			cout << "KELNER: Dobrze, prosze cos wybrac z MENU." << endl << endl;
			Sleep(3500);
			system("cls");
			menu();
			cout << endl << endl << "*Wybierz kolejne pozycje do zamowienia" << endl << endl;
		}
		else
		{
			cout << "" << endl;
		}

	} while (a.choice == 1);

	Sleep(1000);

	if (a.order != "")
	{
		cout << endl << endl << "KELNER: W takim razie bardzo dziekuje. Dla pewnosci powtorze zamowienie." << endl;
		Sleep(2000);
		cout << "KELNER: Mamy tutaj" << a.order << "\nCzy wszystko sie zgadza?" << endl << endl;

		system("pause");

		cout << endl << "KLIENT: Tak, zamowienie sie zgadza." << endl;
		Sleep(2000);

		cout << "KELNER: Bardzo sie ciesze. Rachunek do zaplaty bedzie wynosil " << b.bill_price << "zl" << endl;
		Sleep(2000);

		cout << endl << endl << confirmed;
		confirmed = "\t\t\t*Zamowienie zostalo zlozone*";

		dlugosc = confirmed.length();

		for (int j = 0; j <= dlugosc; j++)
		{
			cout << confirmed[j];
			Sleep(50);
		}

	}
	else
	{
		cout << endl << endl << "KELNER: W takim razie bardzo dziekuje. Niestety przykro mi, ze nic sie nie zostalo zamowione z naszego MENU. Zapraszamy ponownie, do widzenia!" << endl;
		Sleep(2000);

		cout << endl << endl << goodbye;
		goodbye = "*\t\t\tKlienci opuszczaja restauracje*\n";

		dlugosc = goodbye.length();

		for (int j = 0; j <= dlugosc; j++)
		{
			cout << goodbye[j];
			Sleep(50);
		}
		Sleep(2000);
	}

	cout << endl << endl;
	system("pause");

	system("cls");
}

class Napoje {

public:
	int NumerIDNapoju;
	string NazwaNapoju;
	double CenaNapoju;
};



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
		while ((character = _getch()) != '\r')
		{
			if (character != 8)
			{
				cout << "*";
				password += character;
			}
			else
			{
				cout << ("\b \b");
			}
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
class Posilki
{
public:
	int NumerIDPosilku;
	string NazwaPosilku;
	double CenaPosilku;
	bool PrzygotowaniePosilku();
};


class stock
{
	char name[20], pass[15];
	float pr; int quant;

public:
	void get();
	void get2();
	void show();
	void show_menu();
	void disp();
	int stchk(char nm[30]);
	void refil(int qty);
	void withdraw();
}st;


void stock::refil(int qty)
{

	quant += qty;
	cout << "\n\nStan magazynu zaaktalizowany.";
	_getch();


}
int stock::stchk(char nm[30])
{
	if (strcmp(nm, name) == 0)
		return 0;
	else
		return 1;
}
void stock::get()
{
	cin >> name;
		cin >> pr;
		cin >> quant;

}
void stock::get2()
{
	cin >> name >> quant;
}

void stock::show()
{


	PlaceCursor(0,12);
	cout  << name;
	PlaceCursor(30, 12);
	cout << quant;
	PlaceCursor(60, 12);
	cout << pr;
}
void stock::show_menu()
{
	PlaceCursor(0, 12);
	cout << name;
	PlaceCursor(30, 12);
	cout << pr;
}
void stock::withdraw()
{
	system("cls");
	char temp[100];
	int qty;
	int i = 0;
	int n;
	string zmienna;
	const string tak = "tak";
	const string nie = "nie";
	long pos = 0;
	int x;
	int l = 0;
	char* tab[50];
	
	pokaz_menu();

	cout << "\nPodaj ilosc produktow jaka chcesz zamowic \n" << endl;
	cin >> n;
	if (n != 0)
	{


		fio.open("shop.txt", ios::out | ios::in);
		for (int j = 0; j < n; j++)
		{
			cout << "\n\nPodaj nazwe produktu \n" << endl;
			cin >> temp;
			cout << "\n\nPodaj ilosc: \n" << endl;
			cin >> qty;
			while (fio)
			{
				pos = fio.tellp();
				fio.read((char*)&st, sizeof(st));
				if (st.stchk(temp) == 0)
				{
					char t[80];
					std::cin.getline(t, 80);
					tab[i] = new char[std::strlen(t)];
					strcpy(tab[i], t);
					
					if (quant >= qty)
					{
						quant -= qty;
						cout << PL("\n\nZamowienie zostało przyjęte.\n");
						x = pr * qty;
						l += x;
						cout << PL("Twoje zamówienie to: ") <<tab[j];
						cout << PL("\n\nRazem będzie: ") << l<<PL("zł");
						_getch();

					}
					else if (quant < qty)
					{
						cout << "\n\nBrak w magazynie ";
						_getch();
					}
					fio.seekp(pos);
					fio.write((char*)&st, sizeof(st));
					i++;  break;

				}
			}
		}
		kolejne_zamowienie:
		cout << PL("\n\nCzy chcesz dodać kolejne zamówienie?");
		cout << "\n\n=========Wpisz tak lub nie=========="<<endl;
		cin >> zmienna;
		if (zmienna == tak)
		{
			withdraw();
		}
		else if (zmienna ==nie)
		{
			fio.close();
			cin.get();
			system("cls");
			//pokaz_menu();

			_getch();
		}
		else
		{
			cout << PL("\nNie wpisałeś wymaganej frazy");
			cout << PL("\nSpróbuj jeszcze raz");
			goto kolejne_zamowienie;
		}

		
		
		

		if (i != 1)
			cout << "\n\n!!Nie ma takiej pozycji w menu!!";

		fio.close();
		cin.get();
		system("cls");
		disp();
		
		_getch();
	}

}

void PlaceCursor(const int x, const int y) {
	

		
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	

		
		COORD PlaceCursorHere;
	
		PlaceCursorHere.X = x;
	
		PlaceCursorHere.Y = y;
	

		
		SetConsoleCursorPosition(hConsole, PlaceCursorHere);
	
		return;
	
}

void addnew()
{


	system("cls");

	st.disp();
	_getch();
	system("cls");

	cout << "\nPodaj ilosc prouktow jaka chcesz dodac: ";
	cin >> n;


	if (n != 0)
	{

		int j, l, sum = 0;
		fout.open("shop.txt",   ios::app);
		for (i = 0; i < n; i++)

		{

			cout << "\n\nWprowadz Nazwe, cene i ilosc produktu zgodnie z kolejnoscia\n\n";
			st.get();
			fout.write((char*)&st, sizeof(st));
			cout << "\n\nProdukt zaaktualizowany";
			cin.get();


		}
		cout << "\n\nStan magazynu zaaktualizowany!!";


		fout.close();
		cin.get();
		system("cls");
		st.disp();
	}

	else
	{

		fout.close();
		cin.get();
		system("cls");
		cout << "\n\nNic nie dodajesz!\n\n";

	}
}
void pokaz_menu()
{
	int i = 1;
	cout << "\n==================================================================";
	cout << "\n\n===========================\tMENU\t===========================";
	cout << "\n\n==================================================================\n";
	cout << "\n\nNAZWA PRODUKTU \t\t\t CENA";
	cout << "\n\n============================================================\n";
	fin.open("shop.txt");
	while (!fin.eof())
	{
		fin.read((char*)&st, sizeof(st));
		if (!fin.eof())
		{
			if (fin.tellg() < 0)
			{
				i = 0; break;
			}
			st.show_menu();
		}
	}
	if (i == 0)
	{
		cout << "\n\n\t\t\t!!Empty record room!!";
		_getch();
	}
	fin.close();
}
void stock::disp()
{
	int i = 1;
	int y = 12;
	cout << "\n==================================================================";
	cout << "\n\n===========================\tMAGAZYN\t===========================";
	cout << "\n\n==================================================================\n";
	cout << "\n\nNAZWA PRODUKTU \tILOSC W MAGAZYNIE\t\t\t CENA";
	cout << "\n\n============================================================\n";
	fin.open("shop.txt");
	while (!fin.eof())
	{
		fin.read((char*)&st, sizeof(st));
		if (!fin.eof())
		{
			if (fin.tellg() < 0)
			{
				i = 0; break;
			}
			
			PlaceCursor(0, y);
			cout << name;
			PlaceCursor(30, y);
			cout << quant;
			PlaceCursor(60, y);
			cout << pr;
			y = y + 2;
		
		}
		
	}
	if (i == 0)
	{
		cout << "\n\n\t\t\t!!Empty record room!!";
		_getch();
	}
	fin.close();

}
void refill()
{
	system("cls");
	char temp[100]; int qty;
	int i = 0;
	long pos = 0;
	st.disp();
	cout << "\n\nWPISZ NAZWE PRODUKTU \n" << endl;
	cin >> temp;
	cout << "\n\nPODAJ ILOSC: \n" << endl;
	cin >> qty;
	fio.open("shop.txt", ios::out | ios::in);
	while (fio)
	{
		pos = fio.tellp();
		fio.read((char*)&st, sizeof(st));
		if (st.stchk(temp) == 0)
		{

			st.refil(qty);
			fio.seekp(pos);
			fio.write((char*)&st, sizeof(st));
			i++; break;
		}
	}
	if (i != 1)
		cout << "\n\n!!Record not found!!";
	fio.close();
	system("cls");
	cin.get();
	st.disp(); cin.get();


}
void remove()
{
	system("cls");
	int i = 0;
	char temp[30];
	cout << "\n\t\t\t\tUSUWANIE PRODUKTU";
	cout << "\n\nPODAJ NAZWE PRODUKTU:";
	cin >> temp;
	fout.open("temp.txt" );
	fin.open("shop.txt");
	while (!fin.eof())
	{
		fin.read((char*)&st, sizeof(st));
		if (!fin.eof())
			if (st.stchk(temp) == 0)
			{
				st.show();
				cout << "\n\n\t\tPRODUKT USUNIETY";
				i++;
			}
			else
				fout.write((char*)&st, sizeof(st));
	}
	if (i == 0)
		cout << "\n\n!!Record not found!!";
	fin.close();
	fout.close();
	remove("shop.txt");
	rename("temp.txt", "shop.txt");
}

int main()
{


	//  MENU  //////////////////////
	int ilosc_napojow = 6;
	int ilosc_posilkow = 5;


	Napoje* tab_Napoje = new Napoje[ilosc_napojow];

	Posilki* tab_Posilki = new Posilki[ilosc_posilkow];

	tab_Napoje[0] = { 1, "Woda mineralna 0,5l", 4 };
	tab_Napoje[1] = { 2, "Pepsi 0,5l", 5 };
	tab_Napoje[2] = { 3, "Mirinda 0,5l", 5 };
	tab_Napoje[3] = { 4, "Sprite 0,5l", 5 };
	tab_Napoje[4] = { 5, "Tymbark - pomarañcza 0,5l", 5 };
	tab_Napoje[5] = { 6, "Tymbark - winia, jab³ko 0,5l", 5 };

	tab_Posilki[0] = { 1, "Pierogi ruskie", 15 };
	tab_Posilki[1] = { 2, "Pierogi z miêsem", 17 };
	tab_Posilki[2] = { 3, "Pierogi z truskawkami", 14 };
	tab_Posilki[3] = { 4, "Naleniki z serem", 15 };
	tab_Posilki[4] = { 5, "Kotlet schabowy z grillowanymi warzywami, 25" };

	//////////// LOGOWANIE /////////
	string login;
	Zamowienie zamowienie1;
	Rachunek rachunek1;

start:
	system("cls");
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
		cout << "\t\t*                                               *" << endl;
		cout << "\t\t*  WYBIERZ KONTO WPISUJAC LOGIN UZYTKOWNIKA     *" << endl;
		cout << "\t\t*                                               *" << endl;
		cout << "\t\t*************************************************" << endl;

		cout << "Wpisz id pracownika: " << endl;
		cin >> login;
		cout << endl;

		if (login == "Kelner")
		{
			Kelner* kelner = new Kelner;
			kelner->LogowanieKelner();
			st.withdraw();
			_getch();
			//system("cls");
			//kelner->ZamowienieKelner(zamowienie1, rachunek1);
			goto start;
			//break;
		}
		else if (login == "SzefKuchni")
		{
			Szef_kuchni* szef = new Szef_kuchni;
			szef->LogowanieSzefKuchni();
			szef->WykonanieZamowienia(zamowienie1);
			
			goto start;
			//break;
		}
		else if (login == "Manager")
		{
			Manager* manager = new Manager;
			manager->LogowanieManager();
			
		dealermenu:
			system("cls");
			cout << "\n\n\n\n";
			cout << "\t\t*************************************************" << endl;
			cout << "\t\t*                                               *" << endl;
			cout << "\t\t*            WITAJ W SYSTEMIE MANAGERA !        *" << endl;
			cout << "\t\t*                                               *" << endl;
			cout << "\t\t*   DOSTEPNE OPCJE:                             *" << endl;
			cout << "\t\t*1. Dodaj nowy produkt                          *" << endl;
			cout << "\t\t*2. Pokaz stan magazynu                         *" << endl;
			cout << "\t\t*3. Uzupelnij stan                              *" << endl;
			cout << "\t\t*4. Usun produkty                               *" << endl;
			cout << "\t\t*5. Wyjdz                                       *" << endl;
			cout << "\t\t*                                               *" << endl;
			cout << "\t\t*  WYBIERZ OPCJE WPISUJAC JEJ NUMER             *" << endl;
			cout << "\t\t*                                               *" << endl;
			cout << "\t\t*************************************************" << endl;

			cin >> i;
			if (i == 1)
			{
				addnew(); _getch();
				goto dealermenu;
			}

			else if (i == 2)
			{
				system("cls");
				st.disp(); _getch(); goto dealermenu;
			}
			else if (i == 3)
			{
				refill(); goto dealermenu;
			}
			else if (i == 4)
			{
				remove(); _getch(); goto dealermenu;
			}
			else
			{
				system("cls");
				_getch();
				goto start;
			}
			// break;
		}
		else
		{
			cout << endl << "Podano zly login, skontaktuj sie z administratorem w celu zmiany loginu i hasla badz wpisz jeszcze raz: " << endl << endl;
			system("pause");
			system("cls");

		}


	}






	cout << endl << "Restaurant project by: Michal Nycz, Jakub Pietrzak, Artur Pietrzkiewicz" << endl;

	delete[] tab_Napoje;
	delete[] tab_Posilki;
	//delete[] orders;

	system("pause");
	return 0;
}
