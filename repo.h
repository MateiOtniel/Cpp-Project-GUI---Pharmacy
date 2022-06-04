#pragma once
#include "domain.h"
#include <vector>
#include <random>
#include <fstream>
#include <iostream>

using namespace std;

class RepoMedicamente{
public:
	RepoMedicamente() {}
	RepoMedicamente(const RepoMedicamente&){}
	size_t getSize();
	const Medicament& getMedicamentind(int ind);
	vector <Medicament>& getAll();
	vector <Medicament>& getRec();
	virtual void addMedicament(const Medicament& m);
	virtual void deleteMedicament(int id, Medicament& medicament);
	virtual void modifyMedicament(const Medicament& m, Medicament& medicament);
	void addMedRec(const string& nume);
	void delRec();
	void rand(int nr);
	virtual ~RepoMedicamente() = default;
protected:
	vector <Medicament> RepoMed;
	vector <Medicament> Reteta;
};

class Exception{

public:
	Exception(const string& msg): msg_(msg) {}
	~Exception() {}

	string getMessage() const {return(msg_);}
private:
	string msg_;
};

class FileRepoMedicamente: public RepoMedicamente{
private:
	string fname;
	void loadFromFile();
	void writeToFile();
public:
	FileRepoMedicamente(const string& _fname): RepoMedicamente(), fname{_fname}{
		loadFromFile();
	}
	void addMedicament(const Medicament& m) override{
		RepoMedicamente::addMedicament(m);
		writeToFile();
	}
	void deleteMedicament(int id, Medicament& medicament) override{
		RepoMedicamente::deleteMedicament(id, medicament);
		writeToFile();
	}
	void modifyMedicament(const Medicament& m, Medicament& medicament) override{
		RepoMedicamente::modifyMedicament(m, medicament);
		writeToFile();
	}
};