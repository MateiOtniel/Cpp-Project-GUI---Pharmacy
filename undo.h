#pragma once

#include "repo.h"

class ActiuneUndo{
public:
	virtual void doUndo() = 0;
	virtual ~ActiuneUndo(){}
};

class UndoAdd: public ActiuneUndo{
private:
	Medicament med;
	RepoMedicamente& repo;
public:
	UndoAdd(RepoMedicamente& repo, const Medicament& med): repo{repo}, med{med} {}
	void doUndo() override{
		Medicament medicament;
		repo.deleteMedicament(med.getId(), medicament);
	}
};

class UndoDel: public ActiuneUndo{
private:
	Medicament med;
	RepoMedicamente& rep;
public:
	UndoDel(RepoMedicamente& _rep, const Medicament& med): rep{_rep}, med{med}{}
	void doUndo() override{
		rep.addMedicament(med);
	}
};

class UndoMod: public ActiuneUndo{
private:
	Medicament med;
	RepoMedicamente& rep;
public:
	UndoMod(RepoMedicamente& _rep, const Medicament& med): rep{_rep}, med{med} {}
	void doUndo() override{
		Medicament medicament;
		rep.modifyMedicament(med, medicament);
	}
};