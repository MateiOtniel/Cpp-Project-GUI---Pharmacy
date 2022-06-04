#include "repo.h"

size_t RepoMedicamente::getSize(){
	return this->RepoMed.size();
}

const Medicament& RepoMedicamente::getMedicamentind(int ind){
	return RepoMed[ind];
}

vector <Medicament>& RepoMedicamente::getAll(){
	return RepoMed;
}

vector<Medicament>& RepoMedicamente::getRec(){
	return Reteta;
}

void RepoMedicamente::addMedicament(const Medicament& m){
	this->RepoMed.push_back(m);
}

void RepoMedicamente::deleteMedicament(int id, Medicament& medicament){
	auto it = find_if(RepoMed.begin(), RepoMed.end(),
		[=](const Medicament& m) {return m.getId() == id; });
	if(it != RepoMed.end()){
		medicament = *it;
		RepoMed.erase(it);
	}
	else
		throw (Exception("Medicament inexistent!\n"));
}

void RepoMedicamente::modifyMedicament(const Medicament& m, Medicament& medicament){
	auto it = find_if(RepoMed.begin(), RepoMed.end(), [&](const Medicament& otm){
		if(otm.getId() == m.getId()) 
			return 1; 
		else return 0; 
		});

	if(it != RepoMed.end()) {
		medicament = *it;
		*it = m;
	}
	else {
		throw (Exception("Medicament inexistent!\n"));
	}
}

void RepoMedicamente::addMedRec(const string& nume){
	int ok = 0;
	for(auto& med : RepoMed)
		if(med.getDenumire() == nume){
			ok = 1;
			Reteta.push_back(med);
			break;
		}
	if(!ok)
		throw (Exception("Medicament inexistent!\n"));
}

void RepoMedicamente::delRec(){
	Reteta.clear();
}

void RepoMedicamente::rand(int nr){
	if(RepoMed.size() == 0)
		throw ((Exception)("Nu exista medicamente de adaugat in reteta!\n"));
	std::mt19937 mt{std::random_device{}()};
	std::uniform_int_distribution<> dist(0, int(RepoMed.size()) - 1);

	for(int i = 0; i < nr; i++){
		int val = dist(mt);
		Reteta.push_back(RepoMed[val]);
	}
}

void FileRepoMedicamente::loadFromFile(){
	ifstream in(fname);
	if(!in.is_open()) cout << "Unable to open file: " + fname + "\n";

	while(!in.eof()){
		int id, pret;
		string denumire, producator, substanta;

		in >> id;
		in >> denumire;
		in >> pret;
		in >> producator;
		in >> substanta;
		if(denumire != "" && producator != "" && substanta != ""){
			Medicament m(id, denumire, pret,
				producator, substanta);
			RepoMedicamente::addMedicament(m);
		}
	}
	in.close();
}

void FileRepoMedicamente::writeToFile(){
	ofstream out(fname);
	if(!out.is_open()) cout << "Unable to open file: " + fname + "\n";
	for(auto& m : RepoMed)
		out << m.getId() << " " + m.getDenumire() + " " << m.getPret()
		<< " " + m.getProducator() + " " + m.getSubstanta() + "\n";
	out.close();
}
