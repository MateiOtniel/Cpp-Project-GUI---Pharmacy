#include "service.h"


void Service::addMedSrv(const Medicament& m){
	repo.addMedicament(m);
	undoActions.push_back(make_unique<UndoAdd>(repo, m));
}

void Service::modMedSrv(const Medicament& m){
	Medicament medicament;
	repo.modifyMedicament(m, medicament);
	undoActions.push_back(make_unique<UndoMod>(repo, medicament));
}

void Service::delMedSrv(int id){
	Medicament medicament;
	repo.deleteMedicament(id, medicament);
	undoActions.push_back(make_unique<UndoDel>(repo, medicament));
}

vector <Medicament>* Service::filter(int cmd, const string& filvar){
	vector<Medicament>& rep = repo.getAll();
	auto out = new vector<Medicament>;
	for(int i = 0; i < rep.size(); i++)
		if((cmd == 1 && rep.at(i).getPret() == stoi(filvar))
			|| (cmd == 2 && rep.at(i).getSubstanta() == filvar))
			out->push_back(rep.at(i));
	return out;
}

void Service::swap(Medicament* a, Medicament* b){
	Medicament curent;
	curent = *a;
	*a = *b;
	*b = curent;
}

bool Service::ComparaDenumire(vector <Medicament>* out, int i, int j){
	return out->at(i).getDenumire() > out->at(j).getDenumire();
}

bool Service::ComparaProducator(vector <Medicament>* out, int i, int j){
	return out->at(i).getProducator() > out->at(j).getProducator();
}

bool Service::ComparaSubstPret(vector <Medicament>* out, int i, int j){
	return (out->at(i).getSubstanta() > out->at(j).getSubstanta()
		|| (out->at(i).getSubstanta() == out->at(j).getSubstanta()
			&& out->at(i).getPret() > out->at(j).getPret()));
}

vector<Medicament>* Service::sort(int type){
	vector<Medicament>& rep = repo.getAll();

	auto out = new vector<Medicament>;
	for(int i = 0; i < rep.size(); i++)
		out->push_back(rep.at(i));

	int ok = 1;
	while(ok){
		ok = 0;
		for(int i = 0; i < out->size() - 1; i++)
			if((type == 1 && ComparaDenumire(out, i, i + 1)
				|| (type == 2 && ComparaProducator(out, i, i + 1))
				|| (type == 3 && ComparaSubstPret(out, i, i + 1)))){
				swap(&out->at(i), &out->at(i + 1));
				ok = 1;
			}
	}
	return out;
}


vector <Medicament>& Service::srvgetAll(){
	return repo.getAll();
}

vector<Medicament>& Service::srvgetReteta(){
	return repo.getRec();
}

void Service::addMedRecSrv(const string& nume){
	repo.addMedRec(nume);
}

void Service::delRecSrv(){
	repo.delRec();
}

void Service::randSrv(int nr){
	repo.rand(nr);
}

void Service::exportSrv(const string& file){
	vector <Medicament>& copie = repo.getRec();
	ofstream myfile;
	myfile.open(string(file));
	myfile << "Id,Denumire,Pret,Producator,Substanta activa\n";
	for(auto& m : copie){
		myfile  << m.getId() << "," << m.getDenumire() << "," << m.getPret()
			<< "," << m.getProducator() << "," << m.getSubstanta() << '\n';
	}
	myfile.close();
}

void Service::undo(){
	if(undoActions.empty())
		throw Exception("Nu se mai poate face undo!\n");
	undoActions.back()->doUndo();
	undoActions.pop_back();
}

Service::~Service(){
}