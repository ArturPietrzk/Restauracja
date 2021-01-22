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
int licznik = 0;
ifstream fin;
ofstream fout;
fstream fio;
void pokaz_menu();
void PlaceCursor(const int x, const int y);

string welcome;
string goodbye;
string confirmed;
//string order = "";
//int choice
//int bill_price = 0;



class Zamowienie
{
public:

	char pozycje_zamowienia[100];
	char temp[100];
	Zamowienie();
	void PrzygotowanieZamowienia();

};
Zamowienie::Zamowienie() {

	pozycje_zamowienia[0] = 0;

}

class Rachunek
{
public:
	

	float koszt_zamowienia;
	Rachunek();


};

Rachunek::Rachunek() {

	koszt_zamowienia = 0;


}






class Szef_kuchni {

public:
	char character = ' ';
	unsigned tries = 3;
	Szef_kuchni();
	void LogowanieSzefKuchni();
	void WykonanieZamowienia(Rachunek);
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
	cout << PL("Wpisano login dla szefa kuchni") << endl;
	do {
		cout << PL("Wpisz hasło: ");
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
			cout << PL("\nDostępne próby: ") << tries << endl;
		}
	} while (tries > 0 && password != PasswordChef);

	if (tries == 0) cout << "\nUzytkownik zablokowany!\n";
	else cout << PL("\nHasło poprawne. Witamy w systemie!\n");
}

void Szef_kuchni::WykonanieZamowienia(Rachunek b) {



	if (licznik==0) {
		cout << PL("Brak złożonego zamówienia") << endl;



	}
	else {
		cout << PL("Zamówienie jest w trakcie wykonania") << endl;

	}


}
class Kelner
{
	
public:
	
	char character = ' ';
	unsigned tries = 3;
	Kelner();
	void LogowanieKelner();
	void pokaz_menu();

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
		cout << PL("Wpisz hasło: ");
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
			cout << PL("\nDostepne proby: ") << tries << endl;
		}
	} while (tries > 0 && password != PasswordWaiter);

	if (tries == 0) cout << "\nUzytkownik zablokowany!\n";
	else cout << PL("\nHasło poprawne. Witamy w systemie!\n");
}






class Manager {
	friend void refil();
	friend void remove();
public:

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
		cout << PL("Wpisz hasło: ");
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
			cout << PL("\nDostępne próby: ") << tries << endl;
		}
	} while (tries > 0 && password != PasswordManager);

	if (tries == 0) cout << PL("\nUżytkownik zablokowany!\n");
	else cout << PL("\nHasło poprawne. Witamy w systemie szefie!\n");
}



class Magazyn
{
	friend void PlaceCursor();
	char name[20], pass[15];
	float pr; int quant;

public:
	void get();
	void get2();
	void show();
	void show_menu();
	void disp();
	void addnew();
	void pokaz_menu();
	int stchk(char nm[30]);
	void refil(int qty);
	void withdraw(Zamowienie, Rachunek);
}st;


void Magazyn::refil(int qty)
{

	quant += qty;
	cout << "\n\nStan magazynu zaaktalizowany.";
	_getch();


}
int Magazyn::stchk(char nm[30])
{
	if (strcmp(nm, name) == 0)
	{
		return 0;
		
	}
	else
		return 1;
}
void Magazyn::get()
{
	cin >> name;
		cin >> pr;
		cin >> quant;

}
void Magazyn::get2()
{
	cin >> name >> quant;
}



void Magazyn::withdraw(Zamowienie a, Rachunek b)
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
	//char* tab[50];
	
	pokaz_menu();

	cout << PL("\nPodaj ilość produktów jaką chcesz zamowić \n") << endl;
	cin >> n;
	if (n != 0)
	{


		fio.open("shop.txt", ios::out | ios::in);
		for (int j = 0; j < n; j++)
		{
			cout << "\n\nPodaj nazwe produktu \n" << endl;
			cin >> a.pozycje_zamowienia;
			cout << PL("\n\nPodaj ilość: \n") << endl;
			cin >> qty;
			while (fio)
			{
				pos = fio.tellp();
				fio.read((char*)&st, sizeof(st));
				if (st.stchk(a.pozycje_zamowienia) == 0)
				{
					
					
					
					if (quant >= qty)
					{
						quant -= qty;
						cout << PL("\n\nZamowienie zostało przyjęte.\n");
						x = pr * qty;
						b.koszt_zamowienia += x;
						
						cout << PL("Twoje zamówienie to: ") << a.pozycje_zamowienia;
						cout << PL("\n\nRazem będzie: ") << b.koszt_zamowienia<<PL("zł");
						_getch();
						licznik++;

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

void Magazyn::addnew()
{


	system("cls");

	st.disp();
	_getch();
	system("cls");

	cout << PL("\nPodaj ilość produktów jaka chcesz dodać: ");
	cin >> n;


	if (n != 0)
	{

		int j, l, sum = 0;
		fout.open("shop.txt",   ios::app);
		for (i = 0; i < n; i++)

		{

			cout << PL("\n\nWprowadź Nazwe, cene i ilość produktu \n\n");
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
void Magazyn::pokaz_menu()
{
	int i = 1;
	int y = 12;
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

			PlaceCursor(0, y);
			cout << st.name;
			PlaceCursor(30, y);
			cout << st.pr;
			y++;
		}
	}
	if (i == 0)
	{
		cout << "\n\n\t\t\t!!Nie ma takiego produktu w magazynie!!";
		_getch();
	}
	fin.close();
}
void Magazyn::disp()
{
	int i = 1;
	int y = 12;
	cout << "\n==================================================================";
	cout << "\n\n===========================\tMAGAZYN\t===========================";
	cout << "\n\n==================================================================\n";
	cout << PL("\n\nNAZWA PRODUKTU \tILOŚĆ W MAGAZYNIE\t\t\t CENA");
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
		cout << PL("\n\n\t\t\t!!Nie ma żadnych produktów w magazynie!!");
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
	cout << PL("\n\nPODAJ ILOŚĆ: \n") << endl;
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
		cout << "\n\n!!Nie ma takiego produktu w magazynie!!";
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
				cout << PL("\n\n\t\tPRODUKT USUNIĘTY");
				i++;
			}
			else
				fout.write((char*)&st, sizeof(st));
	}
	if (i == 0)
		cout << "\n\n!!Nie ma takiego produktu w magazynie!!";
	fin.close();
	fout.close();
	remove("shop.txt");
	rename("temp.txt", "shop.txt");
}

int main()
{
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
	cout <<PL(  "\t\t*    DOSTĘPNI UZYTKOWNICY:                      *" )<< endl;
		cout << "\t\t*  - Manager                                    *" << endl;
		cout << "\t\t*  - Kelner                                     *" << endl;
		cout << "\t\t*  - SzefKuchni                                 *" << endl;
		cout << "\t\t*                                               *" << endl;
	cout <<PL(  "\t\t*  WYBIERZ KONTO WPISUJĄC LOGIN UŻYTKOWNIKA     *") << endl;
		cout << "\t\t*                                               *" << endl;
		cout << "\t\t*************************************************" << endl;

		cout << "Wpisz id pracownika: " << endl;
		cin >> login;
		cout << endl;

		if (login == "Kelner")
		{
			Kelner* kelner = new Kelner;
			kelner->LogowanieKelner();
			st.withdraw(zamowienie1, rachunek1);
			_getch();
			
			goto start;
			
		}
		else if (login == "SzefKuchni")
		{
			Szef_kuchni* szef = new Szef_kuchni;
			szef->LogowanieSzefKuchni();
			szef->WykonanieZamowienia(rachunek1);
			system("pause");
			
			goto start;
			
		}
		else if (login == "Manager")
		{
			Manager* manager = new Manager;
			manager->LogowanieManager();
			
		managermenu:
			system("cls");
			cout << "\n\n\n\n";
			cout << "\t\t*************************************************" << endl;
			cout << "\t\t*                                               *" << endl;
			cout << "\t\t*            WITAJ W SYSTEMIE MANAGERA !        *" << endl;
			cout << "\t\t*                                               *" << endl;
		cout <<PL(  "\t\t*   DOSTĘPNE OPCJE:                             *") << endl;
			cout << "\t\t*1. Dodaj nowy produkt                          *" << endl;
		cout <<PL(  "\t\t*2. Pokaż stan magazynu                         *") << endl;
		cout <<PL(  "\t\t*3. Uzupełnij stan                              *") << endl;
		cout <<PL(  "\t\t*4. Usuń produkty                               *") << endl;
		cout <<PL(  "\t\t*5. Wyjdź                                       *") << endl;
			cout << "\t\t*                                               *" << endl;
			cout << "\t\t*  WYBIERZ OPCJE WPISUJAC JEJ NUMER             *" << endl;
			cout << "\t\t*                                               *" << endl;
			cout << "\t\t*************************************************" << endl;

			cin >> i;
			if (i == 1)
			{
				st.addnew(); _getch();
				goto managermenu;
			}

			else if (i == 2)
			{
				system("cls");
				st.disp(); _getch(); goto managermenu;
			}
			else if (i == 3)
			{
				refill(); goto managermenu;
			}
			else if (i == 4)
			{
				remove(); _getch(); goto managermenu;
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
			cout << endl <<PL( "Podano zly login, skontaktuj sie z administratorem w celu zmiany loginu i hasla badz wpisz jeszcze raz: ") << endl << endl;
			system("pause");
			system("cls");

		}


	}






	cout << endl << "Restaurant project by: Michal Nycz, Jakub Pietrzak, Artur Pietrzkiewicz" << endl;

	
	//delete[] orders;

	system("pause");
	return 0;
}
