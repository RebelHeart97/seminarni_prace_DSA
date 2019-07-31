#pragma once
#include "pch.h"
#include <string>
#include <iostream>
using namespace std;

class Ridic
{
private:
	//atributy ridice
	string jmeno;
	string prijmeni;
	string rodne_cislo;
	string prestupky;
	string body;
	

public:
	Ridic() { jmeno = ""; prijmeni = ""; rodne_cislo = ""; prestupky = ""; body = "0"; } //defaultni konstruktor ridice
	Ridic(string jmeno, string prijmeni, string rodne_cislo,string prestupky, string body); //parametrikcy konstruktor ridice
	~Ridic() { }; //destruktor ridice


	string GetJmeno() const; // ziskani jmena ridice
	string GetPrijmeni() const; //ziskani prijmeni ridice
	string GetRodneCislo() const; //ziskani rodneho cisla ridice
	string GetPrestupky() const; //ziskani prestupku ridice
	string GetBody() const; //ziskani bodu ridice
	


	//pretizeni vystupniho operatoru
	friend ostream& operator<<(ostream &os, const Ridic &r);




};
