#include "pch.h"
#include <iostream>
#include <fstream>
#include "LinkedList.h"
using namespace std;

ListNode::ListNode(Vozidlo value)
{
	this->value = value;
	this->pNext = NULL;
}

ListNode::ListNode(Ridic val)
{
	this->val = val;
	this->pNext = NULL;
}

MyList::MyList() {
	pHead = NULL;
}

MyList::~MyList()
{
	while (pHead != NULL)
	{
		ListNode *pTmp = pHead;
		pHead = pHead->pNext;
		delete pTmp; pTmp = NULL;
	}
}





void MyList::Tisk() const
{
	
	ListNode *pTmp = pHead;
	while (pTmp != NULL)
	{
		cout << pTmp->value;
		pTmp = pTmp->pNext;
		//cout << endl;
	}
	
}

void MyList::TiskRidic() const
{

	ListNode *pTmp = pHead;
	while (pTmp != NULL)
	{
		cout << pTmp->val;
		pTmp = pTmp->pNext;
		//cout << endl;
	}

}

void MyList::SelectingByYear(Vozidlo* value, string rok) {

	ListNode *pTmp = pHead;
	while (pTmp != NULL)
	{
		if (pTmp->value.GetRokVyroby() == rok) {
			cout << pTmp->value;
			//cout << pTmp->value.GetZnacka() << " " << pTmp->value.GetTyp() << " " << pTmp->value.GetMotorizace() << " " << pTmp->value.GetPalivo() << " " << pTmp->value.GetSPZ() << " " << pTmp->value.GetSPZ() << " " << pTmp->value.GetRokVyroby() << endl;
		}
		
		pTmp = pTmp->pNext;
	}
	cout << endl;

}

void MyList::SelectingByBrand(Vozidlo* value, string znacka) {

	ListNode *pTmp = pHead;
	while (pTmp != NULL)
	{
		if (pTmp->value.GetZnacka() == znacka) {
			cout << pTmp->value;
		}

		pTmp = pTmp->pNext;
	}
	cout << endl;

}

void MyList::SelectingByFuel(Vozidlo* value, string palivo) {

	ListNode *pTmp = pHead;
	while (pTmp != NULL)
	{
		if (pTmp->value.GetPalivo() == palivo) {
			cout << pTmp->value;
		}

		pTmp = pTmp->pNext;
	}
	cout << endl;

}

void MyList::SelectingByPoints(Ridic* val, string body) {

	ListNode *pTmp = pHead;
	while (pTmp != NULL)
	{
		if (pTmp->val.GetBody() == body) {
			cout << pTmp->val;
		}

		pTmp = pTmp->pNext;
	}
	cout << endl;

}

void MyList::SelectingDrivers(Ridic* val, string rodne_cislo) {

	ListNode *pTmp = pHead;
	while (pTmp != NULL)
	{
		if (pTmp->val.GetRodneCislo() == rodne_cislo) {
			cout << pTmp->val;
		}

		pTmp = pTmp->pNext;
	}
	cout << endl;

}

void MyList::SelectingByOwner(Vozidlo* value, string majitel) {

	ListNode *pTmp = pHead;
	while (pTmp != NULL)
	{
		if (pTmp->value.GetMajitel() == majitel) {
			cout << pTmp->value;
		}

		pTmp = pTmp->pNext;
	}
	cout << endl;

}

void MyList::ExportFile() const
{

	ListNode *pTmp = pHead;
	ofstream myFile;
	myFile.open("vozidla.csv");
	myFile << "Znacka;Model;Motorizace;Palivo;SPZ;Majitel;Rok vyroby" << endl;
	while (pTmp != NULL)
	{
		
		myFile << pTmp->value.GetZnacka() << ";" << pTmp->value.GetModel() << ";" << pTmp->value.GetMotorizace() << ";" << pTmp->value.GetPalivo() << ";" << pTmp->value.GetSPZ() << ";" << pTmp->value.GetMajitel() << ";" << pTmp->value.GetRokVyroby() << endl;
		
		pTmp = pTmp->pNext;
		//cout << endl;
		
	}
	myFile.close();
}

void MyList::ExportFileRidici() const
{

	ListNode *pTmp = pHead;
	ofstream myFile;
	myFile.open("ridici.csv");
	myFile << "Jmeno;Prijmeni;Rodne cislo;Prestupky;Body" << endl;
	while (pTmp != NULL)
	{

		myFile << pTmp->val.GetJmeno() << ";" << pTmp->val.GetPrijmeni() << ";" << pTmp->val.GetRodneCislo() << ";" << pTmp->val.GetPrestupky() << ";" << pTmp->val.GetBody() << ";" << endl;

		pTmp = pTmp->pNext;


	}
	myFile.close();
}


void MyList::AddSorted(Vozidlo* value) {
	ListNode* temp = new ListNode(*value);
	
	temp->value.GetZnacka() = znacka;
	temp->value.GetModel() = model;
	temp->value.GetMotorizace() = motorizace;
	temp->value.GetPalivo() = palivo;
	temp->value.GetSPZ() = spz;
	temp->value.GetMajitel() = majitel;
	temp->value.GetRokVyroby() = rok_vyr;

	ListNode* temp2 = pHead;
	ListNode** temp3 = &pHead;
	
	while (temp2 != NULL && temp2->value.GetSPZ() < temp->value.GetSPZ())
	{
		temp3 = &temp2->pNext;
		temp2 = temp2->pNext;
	
	}
	*temp3 = temp;
	temp->pNext = temp2;
	
}


void MyList::AddSortedRidic(Ridic* val) {
	ListNode* temp = new ListNode(*val);
	
	temp->val.GetJmeno() = jmeno;
	temp->val.GetPrijmeni() = prijmeni;
	temp->val.GetRodneCislo() = rodne_cislo;
	temp->val.GetPrestupky() = prestupky;
	temp->val.GetBody() = body;
	 
	ListNode* temp2 = pHead;
	ListNode** temp3 = &pHead;
	
	while (temp2 != NULL && temp2->val.GetPrijmeni() < temp->val.GetPrijmeni())
	{
		temp3 = &temp2->pNext;
		temp2 = temp2->pNext;
		
	}
	*temp3 = temp;
	temp->pNext = temp2;
	
}


bool MyList::Remove(Vozidlo* value,string spz)
{
	
	ListNode *pNode = pHead, *pPrev = NULL;

	while (pNode != NULL)
	{
		if (pNode->value.GetSPZ() == spz)
		{
			if (pPrev == NULL)
				pHead = pNode->pNext; 
			else
				pPrev->pNext = pNode->pNext;
			delete pNode;
			
			return true;
		}

		pPrev = pNode;
		pNode = pNode->pNext;
	}

	return false;
}

bool MyList::RemoveRidic(Ridic* val, string rodne_cislo)
{

	ListNode *pNode = pHead, *pPrev = NULL;

	while (pNode != NULL)
	{
		if (pNode->val.GetRodneCislo() == rodne_cislo) 
		{
			if (pPrev == NULL)
				pHead = pNode->pNext;
			else
				pPrev->pNext = pNode->pNext;
			delete pNode;
			return true;
		}

		pPrev = pNode;
		pNode = pNode->pNext;
	}

	return false;
}

bool MyList::KontrolaSPZ(string spz){
	ListNode *pTmp = pHead;
	while (pTmp != NULL) {
		
			if (pTmp->value.GetSPZ() == spz) {
				cout << "SPZ jiz exituje" << endl;
				break;
				
			}
			else {
				
				pTmp = pTmp->pNext;
				
			}
			
		}
	if (pTmp == NULL) {
		return true;
	}
		
	return false;
}

bool MyList::KontrolaRC(string rodne_cislo) {
	ListNode *pTmp = pHead;
	while (pTmp != NULL) {
		
		if (pTmp->val.GetRodneCislo() == rodne_cislo) {
			cout << "Rodne cislo jiz exituje" << endl;
			
			break;
		}
		else {
			
			pTmp = pTmp->pNext;
		}
		
	}
	if (pTmp == NULL) {
		return true;
	}
	
	return false;
}

void MyList::UpravaVozidlaMajitel(string spz) {
	ListNode *pTmp = pHead;
	Vozidlo *voz = NULL;
	while (pTmp != NULL) {

		if (pTmp->value.GetSPZ() == spz) {
			znacka = pTmp->value.GetZnacka();
			model = pTmp->value.GetModel();
			motorizace = pTmp->value.GetMotorizace();
			palivo = pTmp->value.GetPalivo();
			spz = pTmp->value.GetSPZ();
			rok_vyr = pTmp->value.GetRokVyroby();
			cin.ignore();
			cout << "Vlozte jmeno a prijmeni noveho majitele: ";
			getline(cin, majitel);
			Remove(voz, spz);
			AddSorted(new Vozidlo(znacka, model, motorizace, palivo, spz, majitel, rok_vyr));
			cout << "Zmena byla provedena uspesne" << endl;
			Tisk();
			break;
		}
		else {
			pTmp = pTmp->pNext;
			
		}
		
	}
	if(pTmp == NULL)
	cout << "Zadana SPZ neni v systemu" << endl;


	return;

}

void MyList::UpravaVozidlaSPZ(string spz) {
	ListNode *pTmp = pHead;
	Vozidlo *voz = NULL;
	string spzN;
	while (pTmp != NULL) {

		if (pTmp->value.GetSPZ() == spz) {
			znacka = pTmp->value.GetZnacka();
			model = pTmp->value.GetModel();
			motorizace = pTmp->value.GetMotorizace();
			palivo = pTmp->value.GetPalivo();
			majitel = pTmp->value.GetMajitel();
			rok_vyr = pTmp->value.GetRokVyroby();
			
			cout << "Vlozte novou SPZ: ";
			cin >> spzN;
			Remove(voz, spz);
			if (KontrolaSPZ(spzN) == true) {
				AddSorted(new Vozidlo(znacka, model, motorizace, palivo, spzN, majitel, rok_vyr));
				cout << "Zmena byla provedena uspesne" << endl;
				Tisk();
			}
			else {
				
			}
			
			break;
		}
		else {
			pTmp = pTmp->pNext;
		}
		
	}
	if (pTmp == NULL)
	cout << "Zadana SPZ neni v systemu" << endl;
	
	return;

}


void MyList::UpravaRidicePrestupky(string rodne_cislo) {
	ListNode *pTmp = pHead;
	Ridic *ridic = NULL;
	string pom;
	string pres;
	while (pTmp != NULL) {

		if (pTmp->val.GetRodneCislo() == rodne_cislo) {
			jmeno = pTmp->val.GetJmeno();
			prijmeni = pTmp->val.GetPrijmeni();
			rodne_cislo = pTmp->val.GetRodneCislo();
			pres = pTmp->val.GetPrestupky();
			body = pTmp->val.GetBody();
			
			cin.ignore();
			cout << "Vlozte dalsi prestupky ridice: ";
			getline(cin, prestupky);
			
			if (pres != "") {
				pom = pres + "," + prestupky;
			}
			else {
				pom = pres + prestupky;
			}
			
			RemoveRidic(ridic, rodne_cislo);
			AddSortedRidic(new Ridic(jmeno, prijmeni, rodne_cislo, pom, body));
			
			break;
		}
		else {
			pTmp = pTmp->pNext;
		}
		
	}
	if (pTmp == NULL)
	cout << "Zadane rodne cislo neni v systemu" << endl;
	

	return;

}

void MyList::UpravaRidiceBody(string rodne_cislo) {
	ListNode *pTmp = pHead;
	Ridic *ridic = NULL;
	while (pTmp != NULL) {

		if (pTmp->val.GetRodneCislo() == rodne_cislo) {
			jmeno = pTmp->val.GetJmeno();
			prijmeni = pTmp->val.GetPrijmeni();
			rodne_cislo = pTmp->val.GetRodneCislo();
			prestupky = pTmp->val.GetPrestupky();
			//body = pTmp->val.GetBody();

			
			cout << "Vlozte body  ridice: ";
			cin >> body;

			
			RemoveRidic(ridic, rodne_cislo);
			AddSortedRidic(new Ridic(jmeno, prijmeni, rodne_cislo, prestupky, body));
		
			break;
		}
		else {
			pTmp = pTmp->pNext;
		}
		
	}
	if (pTmp == NULL)
	cout << "Zadane rodne cislo neni v systemu" << endl;
	

	return;

}















