
#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;
#include "Vozidlo.h"
#include "LinkedList.h"



MyList *mL = new MyList();
MyList *mR = new MyList();
Vozidlo *voz = NULL;
Ridic *ridic = NULL;
string znacka;
string model;
string motorizace;
string palivo;
string spz;
string majitel;
string rok_vyr;

string jmeno;
string prijmeni;
string rodne_cislo;
string prestupky;
string body;

void ImportFile() {
	ifstream myFile;
	myFile.open("vozidla.csv");
	myFile.ignore(500,'\n');
	while (myFile.peek() != EOF) {
		
			getline(myFile, znacka, ';');
			getline(myFile, model, ';');
			getline(myFile, motorizace, ';');
			getline(myFile, palivo, ';');
			getline(myFile, spz, ';');
			getline(myFile, majitel, ';');
			getline(myFile, rok_vyr, '\n');

			mL->AddSorted(new Vozidlo(znacka, model, motorizace, palivo, spz, majitel, rok_vyr));
			

		
	}

	myFile.close();
}

void ImportFileRidici() {
	ifstream myFile;
	myFile.open("ridici.csv");
	myFile.ignore(500, '\n');
	while (myFile.peek() != EOF) {

		getline(myFile, jmeno, ';');
		getline(myFile, prijmeni, ';');
		getline(myFile, rodne_cislo, ';');
		getline(myFile, prestupky, ';');
		getline(myFile, body, '\n');
		

		mR->AddSortedRidic(new Ridic(jmeno, prijmeni, rodne_cislo, prestupky, body));



	}

	myFile.close();
}



void tiskMenu()
{
	cout << endl;
	cout << "----------------------" << endl;
	cout << "\tMENU" << endl;
	cout << "----------------------" << endl;
	cout << "1 - Vozidla" << endl;
	cout << "2 - Ridici" << endl;
	cout << "0 - KONEC" << endl;
	cout << "----------------------" << endl;
}

void menuVozidla() {
	cout << "--------------------------" << endl;
	cout << "\tVozidla" << endl;
	cout << "--------------------------" << endl;
	cout << "1 - Registrace vozidla" << endl;
	cout << "2 - Odregistrace vozidla" << endl;
	cout << "3 - Vypis vozidel" << endl;
	cout << "4 - Vyber podle kriteria" << endl;
	cout << "5 - Zmena majitele" << endl;
	cout << "6 - Zmena SPZ" << endl;
	cout << "7 - Export vozidel" << endl;
	cout << "0 - Zpet" << endl;
	cout << "--------------------------" << endl;
}

void menuRidici() {
	cout << "--------------------------" << endl;
	cout << "\tRidici" << endl;
	cout << "--------------------------" << endl;
	cout << "1 - Pridani ridice" << endl;
	cout << "2 - Odstraneni ridice" << endl;
	cout << "3 - Vypis ridicu" << endl;
	cout << "4 - Vyhledani podle bodu" << endl;
	cout << "5 - Vyhledani ridice" << endl;
	cout << "6 - Pridani prestupku" << endl;
	cout << "7 - Zmena poctu bodu" << endl;
	cout << "8 - Export ridicu" << endl;
	cout << "0 - Zpet" << endl;
	cout << "--------------------------" << endl;
}
  
void tiskMenuVozidlo()
{
	cout << endl << endl;
	cout << "----------------------------------------" << endl;
	cout << "\tRegistrace vozidla" << endl;
	cout << "----------------------------------------" << endl;
	cout << "1 - Rucni registrace vozidla" << endl;
	cout << "2 - Import vozidel ze souboru" << endl;
	cout << "0 - Zpet" << endl;
	cout << "----------------------------------------" << endl;

}

void tiskMenuRidici()
{
	cout << endl << endl;
	cout << "---------------------------------------" << endl;
	cout << "\tPridani ridice" << endl;
	cout << "---------------------------------------" << endl;
	cout << "1 - Rucni pridani ridice" << endl;
	cout << "2 - Import ridicu ze souboru" << endl;
	cout << "0 - Zpet" << endl;
	cout << "---------------------------------------" << endl;
}

void tiskMenuVyber()
{
	cout << endl << endl;
	cout << "-----------------------------------------" << endl;
	cout << "\tVyber podle kriteria" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "1 - Vyber podle roku" << endl;
	cout << "2 - Vyber podle znacky" << endl;
	cout << "3 - Vyber podle paliva" << endl;
	cout << "4 - Vyber podle majitele" << endl;
	cout << "0 - Zpet" << endl;
	cout << "-----------------------------------------" << endl;

}

int volba()
{
	char v;

	tiskMenu();

	do
	{
		cin >> v;
		cout << endl;
	} while (!((v == '1') || (v == '2') || (v == '0')));
	return v - '0';
}

int volbaV()
{
	char z;

	tiskMenuVozidlo();

	do
	{
		cin >> z;

		cout << endl;
	} while (!((z == '1') || (z == '2') || (z == '0')));
	return z - '0';
}

int volbaVyber()
{
	char vyb;

	tiskMenuVyber();

	do
	{
		cin >> vyb;
		cout << endl;
	} while (!((vyb == '1') || (vyb == '2') || (vyb == '3') || (vyb == '4') || (vyb == '0')));
	return vyb - '0';
}
int volbaVozidla()
{
	char vz;

	menuVozidla();

	do
	{
		cin >> vz;
		cout << endl;
	} while (!((vz == '1') || (vz == '2') || (vz == '3') || (vz == '4') || (vz == '5') || (vz == '6') || (vz == '7') || (vz == '0')));
	return vz - '0';
}

int volbaRidici()
{
	char r;

	menuRidici();

	do
	{
		cin >> r;
		cout << endl;
	} while (!((r == '1') || (r == '2') || (r == '3') || (r == '4') || (r == '5') || (r == '6') || (r == '7') || (r == '8') || (r == '0')));
	return r - '0';
}

int volbaR()
{
	char rid;

	tiskMenuRidici();

	do
	{
		cin >> rid;

		cout << endl;
	} while (!((rid == '1') || (rid == '2') || (rid == '0')));
	return rid - '0';
}

int _tmain(int argc, _TCHAR* argv[])
{
	

	int v;
	int z;
	int vyb;
	int vz;
	int r;
	int rid;

hop:
	do
	{
		//system("cls");
		v = volba();
		switch (v)
		{
		case 1:
	
			system("cls");
		gt:
		h:
			vz = volbaVozidla();
			switch (vz) {
				
			case 1:
				system("cls");
				z = volbaV();
				switch (z) {
				case 1:
					cout << "--------------------------------------------" << endl;
					cout << "\tRucni registrace vozu" << endl;
					cout << "--------------------------------------------" << endl;
					cout << "Zadejte znacku vozu: ";
					cin >> znacka;
					cout << "Zadejte model vozu: ";
					cin >> model;
					cout << "Zadejte motorizaci vozu: ";
					cin >> motorizace;
					cout << "Zadejte palivo vozu: ";
					cin >> palivo;
					cout << "Zadejte SPZ vozu: ";
					cin >> spz;
					cout << "Zadejte majitele vozu: ";
					cin.ignore();
					getline(cin, majitel);
					cout << "Zadejte rok vyroby vozu: ";
					cin >> rok_vyr;
					
				
						if (mL->KontrolaSPZ(spz)) {
							mL->AddSorted(new Vozidlo(znacka, model, motorizace, palivo, spz, majitel, rok_vyr));
							cout << "Vozidlo bylo vlozeno do systemu" << endl;
						}
						else {
							cout << "Zkuste znovu vlozit vozidlo" << endl;
						}
					
					break;

				case 2:
					cout << "Probiha import..." << endl;
					ImportFile();
					cout << "Import probehl uspesne!" << endl;
					break;


				case 0:
					goto gt;
				}
				break;
				
			case 2:
				cout << "-----------------------------------------------------" << endl;
				cout << "\tOdregistrace vozidla" << endl;
				cout << "-----------------------------------------------------" << endl;
				cout << "Zadejte SPZ vozu (bez mezery): ";
				cin >> spz;
				mL->Remove(voz, spz);
				cout << "Vozidlo bylo uspesne odstraneno" << endl;
				cout << endl;
				delete voz;
				break;
			case 3:
				cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "\t\t\t\t\t\tVypis vozidel" << endl;
				cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "Znacka\t\tModel\t\tMotorizace\t\tPalivo\t\tSPZ\t\tMajitel\t\tRok vyroby" << endl;
				cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
				mL->Tisk();
				cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
				cout << endl;
				break;
			case 4:
				system("cls");
				vyb = volbaVyber();
				switch (vyb) {

				case 1:
					cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
					cout << "\t\t\t\t\t\tVyber vozidel podle roku vyroby" << endl;
					cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
					cout << "Zadejte rok vyroby vozu: ";
					cin >> rok_vyr;
					cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
					
					cout << "Znacka\t\tModel\t\tMotorizace\t\tPalivo\t\tSPZ\t\tMajitel\t\tRok vyroby" << endl;
					cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
					mL->SelectingByYear(voz, rok_vyr);
					cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
					cout << endl;

					break;

				case 2:
					cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
					cout << "\t\t\t\t\t\tVyber podle znacky vozu" << endl;
					cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
					cout << "Zadejte znacku vozu: ";
					cin >> znacka;
					cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
					
					cout << "Znacka\t\tModel\t\tMotorizace\t\tPalivo\t\tSPZ\t\tMajitel\t\tRok vyroby" << endl;
					cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
					mL->SelectingByBrand(voz, znacka);
					cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
					cout << endl;

					break;

				case 3:
					cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
					cout << "\t\t\t\t\t\tVyber vozidel podle druhu paliva" << endl;
					cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
					cout << "Zadejte druh paliva: ";
					cin >> palivo;
					cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
					
					cout << "Znacka\t\tModel\t\tMotorizace\t\tPalivo\t\tSPZ\t\tMajitel\t\tRok vyroby" << endl;
					cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
					mL->SelectingByFuel(voz, palivo);
					cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
					cout << endl;
					break;

				case 4:
					cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
					cout << "\t\t\t\t\t\tVyber vozidel podle majitele" << endl;
					cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
					cout << "Zadejte jmeno majitele: ";
					cin.ignore();
					getline(cin, majitel);
					cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
					
					cout << "Znacka\t\tModel\t\tMotorizace\t\tPalivo\t\tSPZ\t\tMajitel\t\tRok vyroby" << endl;
					cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
					mL->SelectingByOwner(voz, majitel);
					cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
					cout << endl;
					break;
				case 0:
					goto h;
					break;
				}
				break;
			
			case 5:
				cout << "--------------------------------------------" << endl;
				cout << "\t\tZmena majitele" << endl;
				cout << "--------------------------------------------" << endl;
				cout << "Zadejte SPZ vozidla: ";
				cin >> spz;
				
				mL->UpravaVozidlaMajitel(spz);
				
				cout << endl;
				break;
			case 6:
				cout << "--------------------------------------------" << endl;
				cout << "\t\tZmena SPZ" << endl;
				cout << "--------------------------------------------" << endl;
				cout << "Zadejte SPZ vozidla: ";
				cin >> spz;

				mL->UpravaVozidlaSPZ(spz);
				
				cout << endl;
				break;

			case 7:
				cout << "Probiha export..." << endl;
				mL->ExportFile();
				cout << "Uspesne exportovano!" << endl;

				cout << endl;
				break;
			case 0:
				goto hop;
				break;
			
			
			}
			break;
		

		case 2:
			s:
			system("cls");
			r = volbaRidici();
			switch (r) {
			case 1:
				system("cls");
				rid = volbaR();
				switch (rid) {
				case 1:
					cout << "Pridani ridice" << endl;
					cout << "Zadejte krestni jmeno: ";
					cin >> jmeno;
					cout << "Zadejte prijmeni: ";
					cin >> prijmeni;
					cout << "Zadejte rodne cislo: ";
					cin >> rodne_cislo;
					cin.ignore();
					cout << "Zadejte prestupky ridice: ";
					getline(cin, prestupky);
					cout << "Zadejte trestne body: ";
					cin >> body;
					
					if (mR->KontrolaRC(rodne_cislo)) {
					mR->AddSortedRidic(new Ridic(jmeno, prijmeni, rodne_cislo,prestupky, body));
					cout << "Ridic byl vlozen do systemu" << endl;
					//break;
					}
					else {
						cout << "Zkuste znovu vlozit ridice" << endl;
						break;
					}

					break;
				case 2:
					cout << "Probiha import..." << endl;
					ImportFileRidici();
					cout << "Import probehl uspesne!" << endl;
					break;
				case 0:
					goto s;
					break;
				
				}
				break;
			case 2:
				cout << "Odstraneni ridice" << endl;
				cout << "Zadejte krestni jmeno ridice: ";
				cin >> jmeno;
				cout << "Zadejte prijmeni ridice: ";
				cin >> prijmeni;
				mR->RemoveRidic(ridic, rodne_cislo);
				cout << "Ridic byl uspesne odstranen" << endl;
				cout << endl;
				delete ridic;
				break;
			case 3:
				cout << "----------------------------------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "\t\t\t\t\t\tVypis ridicu" << endl;
				cout << "----------------------------------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "Jmeno\t\tPrijmeni\t\tRodne cislo\t\t\tPrestupky\t\t\tBody" << endl;
				cout << "----------------------------------------------------------------------------------------------------------------------------------------------" << endl;
				mR->TiskRidic();
				cout << "----------------------------------------------------------------------------------------------------------------------------------------------" << endl;
				cout << endl;
				break;
			case 4:
				cout << "---------------------------------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "\t\t\t\t\t\tVyhledani podle bodu" << endl;
				cout << "---------------------------------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "Zadejte pocet trestnych bodu: ";
				cin >> body;
				
				cout << "----------------------------------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "Jmeno\t\tPrijmeni\t\tRodne cislo\t\t\tPrestupky\t\t\tBody" << endl;
				cout << "----------------------------------------------------------------------------------------------------------------------------------------------" << endl;
				mR->SelectingByPoints(ridic, body);
				cout << endl;
				break;
			case 5:
				cout << "---------------------------------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "\t\t\t\t\t\tVyhledani ridice" << endl;
				cout << "---------------------------------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "Zadejte rodne cislo ridice: ";
				cin >> rodne_cislo;

				cout << "----------------------------------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "Jmeno\t\tPrijmeni\t\tRodne cislo\t\t\tPrestupky\t\t\tBody" << endl;
				cout << "----------------------------------------------------------------------------------------------------------------------------------------------" << endl;
				mR->SelectingDrivers(ridic, rodne_cislo);
				cout << endl;
				break;
			case 6:
				cout << "Pridani prestupku" << endl;
				cout << "Zadejte rodne cislo ridice: ";
				cin >> rodne_cislo;
				mR->UpravaRidicePrestupky(rodne_cislo);
				cout << "Zmena byla provedena uspesne" << endl;
				cout << endl;
				break;
			case 7:
				cout << "Zmena bodu u ridice" << endl;
				cout << "Zadejte rodne cislo ridice: ";
				cin >> rodne_cislo;
				mR->UpravaRidiceBody(rodne_cislo);
				cout << "Zmena byla provedena uspesne" << endl;
				cout << endl;
				break;
			case 8:
				cout << "Probiha export..." << endl;
				mR->ExportFileRidici();
				cout << "Uspesne exportovano!" << endl;

				cout << endl;
				break;
			case 0:
				goto hop;
				break;
			
			
			}
			break;
		case 0:
			mL->~MyList();
			mR->~MyList();
			cout << "Dekujeme za pouziti programu" << endl;
			break;
		}
	} while (v != 0);

	return 0;
}
