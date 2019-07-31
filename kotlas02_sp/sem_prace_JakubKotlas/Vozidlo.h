#pragma once
#include "pch.h"
#include <string>
#include <iostream>
using namespace std;

class Vozidlo
{
private:
	//atributy vozidla
	string znacka;
	string model;
	string motorizace;
	string palivo;
	string majitel;
	string spz;
	string rok_vyr;

public:
	Vozidlo() { znacka = ""; model = ""; motorizace = ""; palivo = "";  spz = ""; majitel = ""; rok_vyr = "0000"; } //defautlni konstruktor vozidla
	Vozidlo(string znacka, string model, string motorizace, string palivo, string spz, string majitel, string rok_vyr); //parametricky konstruktor vozidla
	~Vozidlo() { }; //destruktor vozidla

	
	string GetZnacka() const; //ziskani znacka vozidla
	string GetModel() const; //ziskani modelu vozidla
	string GetMotorizace() const; //ziskani motorizace vozidla
	string GetMajitel() const; // ziskani majitele vozidla
	string GetPalivo() const; // ziskani pouzivaneho paliva u vozidla
	string GetSPZ() const; //ziskani spz vozidla
	string GetRokVyroby() const; //ziskani roku vyroby vozidla

	

	//pretizeni vystupniho operatoru	
	friend ostream& operator<<(ostream &os, const Vozidlo &v);


	
	
};
