#pragma once
#include "pch.h"
#include "Vozidlo.h"
#include "Ridic.h"
class ListNode
{
private:
	Vozidlo value;
	Ridic val;
	ListNode *pNext;
public:
	ListNode(Vozidlo value);
	ListNode(Ridic val);

	friend class MyList;
};


class MyList
{
public:
	ListNode *pHead;
	string znacka;
	string model;
	string motorizace;
	string palivo;
	string majitel;
	string spz;
	string rok_vyr;

	string jmeno;
	string prijmeni;
	string rodne_cislo;
	string prestupky;
	string body;
	
	
	MyList();
	~MyList();

	
	
	
	void Tisk() const; //vypis vozidel
	void TiskRidic() const; //vypis ridicu
	void SelectingByYear(Vozidlo* value, string rok); //vyber podle roku vyroby vozu
	void SelectingByBrand(Vozidlo* value, string znacka); // vyber podle znacky vozu
	void SelectingByFuel(Vozidlo* value, string palivo); // vyber vozidel podle pouzivaneho paliva
	void SelectingByPoints(Ridic* value, string body); // vyber ridicu podle poctu bodu
	void SelectingDrivers(Ridic* value, string rodne_cislo); // hledani ridice
	void SelectingByOwner(Vozidlo* value, string majitel); //vyber vozidel z listu podle majitele
	void ExportFile() const; // export vozidel do souboru
	void ExportFileRidici() const; //export ridicu do souboru
	void AddSorted(Vozidlo* value); //razene pridavani vozidla
	void AddSortedRidic(Ridic* value); // razene pridavani ridice
	bool Remove(Vozidlo* value,string spz); //odstraneni vozidla podle spz
	bool RemoveRidic(Ridic* val, string rodne_cislo); // odstraneni ridice podle rodneho cisla
	bool KontrolaSPZ(string spz); //kontrola unikatnosti spz vozidla
	bool KontrolaRC(string rodne_cislo); //kontrola unikatnosti rodneho cisla
	void UpravaVozidlaMajitel(string spz); // zmena majitele
	void UpravaVozidlaSPZ(string spz); // zmnena spz
	void UpravaRidicePrestupky(string rodne_cislo); //pridani prestupku
	void UpravaRidiceBody(string rodne_cislo); //zmena bodu ridice

	
};





