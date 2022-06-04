#include "domain.h"
#include <iostream>

Medicament::Medicament(int id, const string& denumire, int pret, const string& producator, const string& substanta){
	this->id = id;
	this->denumire = denumire;
	this->pret = pret;
	this->producator = producator;
	this->substanta = substanta;
}

int Medicament::getId() const{
	return this->id;
}

const string& Medicament::getDenumire() const{
	return this->denumire;
}

int Medicament::getPret() const{
	return this->pret;
}

const string& Medicament::getProducator() const{
	return this->producator;
}

const string& Medicament::getSubstanta() const{
	return this->substanta;
}

void Medicament::setDenumire(const string& den){
	this->denumire = den;
}

void Medicament::setPret(double pr){
	this->pret = pr;
}

void Medicament::setProducator(const string& prod){
	this->producator = prod;
}

void Medicament::setSubstanta(const string& subst){
	this->substanta = subst;
}

Medicament::~Medicament(){
}

bool Medicament::operator==(const Medicament& m){
	return (this->getDenumire() == m.getDenumire() && this->getProducator() == m.getProducator());
}
