#include "pch.h"
#include <iostream>
#include <iomanip>
using namespace std;
#include "Ridic.h"

Ridic::Ridic(string jmeno, string prijmeni, string rodne_cislo, string prestupky, string body)
{

	this->jmeno = jmeno;
	this->prijmeni = prijmeni;
	this->rodne_cislo = rodne_cislo;
	this->prestupky = prestupky;
	this->body = body;
	

}



string Ridic::GetJmeno() const
{
	return jmeno;
}

string Ridic::GetPrijmeni() const
{
	return prijmeni;
}

string Ridic::GetRodneCislo() const
{
	return rodne_cislo;
}

string Ridic::GetPrestupky() const
{
	return prestupky;
}

string Ridic::GetBody() const
{
	return body;
}




ostream& operator<<(ostream &os, const Ridic &r)
{
	os << r.jmeno << setw(16) << right << r.prijmeni << right << setw(28) << r.rodne_cislo << right << setw(50) << right << r.prestupky << right << setw(7) << r.body << endl;
	return os;
}

