#include "pch.h"
#include <iostream>
using namespace std;
#include "Vozidlo.h"

Vozidlo::Vozidlo(string znacka, string model, string motorizace, string palivo, string spz, string majitel, string rok_vyr)
{
	
	this->znacka = znacka;
	this->model = model;
	this->motorizace = motorizace;
	this->palivo = palivo;
	this->majitel = majitel;
	this->spz = spz;
	this->rok_vyr = rok_vyr;
	
}




string Vozidlo::GetZnacka() const
{
	return znacka;
}

string Vozidlo::GetModel() const
{
	return model;
}

string Vozidlo::GetMotorizace() const
{
	return motorizace;
}

string Vozidlo::GetMajitel() const
{
	return majitel;
}

string Vozidlo::GetPalivo() const
{
	return palivo;
}

string Vozidlo::GetSPZ() const
{
	return spz;
}

string Vozidlo::GetRokVyroby() const
{
	return rok_vyr;
}


ostream& operator<<(ostream &os, const Vozidlo &v)
{
	os << v.znacka << "\t\t" << v.model << "\t\t" << v.motorizace << "\t\t\t" << v.palivo << "\t\t" << v.spz << "\t\t" << v.majitel << "\t" << v.rok_vyr << endl;
	return os;
}

