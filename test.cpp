#include "test.h"

void test_domain(){
	int id = 1;
	string nume = "Parasinus";
	int pret = 123;
	string producator = "Helpnet";
	string substanta = "activa";
	Medicament med(id, nume, pret, producator, substanta);
	assert(med.getDenumire() == "Parasinus");
	assert(med.getId() == id);
	assert(med.getPret() == pret);
	assert(med.getProducator() == "Helpnet");
	assert(med.getSubstanta() == "activa");
	string newnume = "Triferment";
	med.setDenumire(newnume);
	assert(med.getDenumire() == "Triferment");
	med.setPret(122);
	assert(med.getPret() == 122);
	med.setProducator("Ducfarm");
	assert(med.getProducator() == "Ducfarm");
	med.setSubstanta("pasiva");
	assert(med.getSubstanta() == "pasiva");
}

void test_repo(){
	RepoMedicamente rep;
	string err;
	assert(rep.getSize() == 0);
	Medicament medicament;
	Medicament med1(1, "Triferment", 123, "helpnet", "activa");
	rep.addMedicament(med1);
	assert(rep.getSize() == 1);

	Medicament med2(2, "Parasinus", 123, "helpnet", "activa");
	Medicament med3(1, "Colebil", 122, "ducfarm", "inactiva");
	rep.modifyMedicament(med3, medicament);
	assert(rep.getMedicamentind(0).getDenumire() == "Colebil");
	assert(rep.getMedicamentind(0).getProducator() == "ducfarm");
	assert(rep.getMedicamentind(0).getSubstanta() == "inactiva");
	rep.addMedicament(med2);

	rep.deleteMedicament(med1.getId(), medicament);
	
	assert(rep.getSize() == 1);
	try{
		rep.deleteMedicament(3, medicament);
	}
	catch(Exception& err){
		assert(err.getMessage() == "Medicament inexistent!\n");
	}
}

void test_validate(){
	string err;
	Validator v;
	v.validateMedicine("Paracetamol", "123", "Helpnet", "benzen");
	try{
		v.validateMedicine("123", " ", "Helpnet12", "-asd");
	}
	catch(string& err){
		assert(err == "Denumire invalida!\nPret invalid!\nProducator invalid!\nSubstanta invalida!\n");
	}
	try{
		v.validateMedicine("", "1-z", "", "-");
	}
	catch(string& err){
		assert(err == "Denumire invalida!\nPret invalid!\nProducator invalid!\nSubstanta invalida!\n");
	}
	try{
		v.validateMedicine("LALAla, ", "", "Abce1", "");
	}
	catch(string& err){
		assert(err == "Denumire invalida!\nPret invalid!\nProducator invalid!\nSubstanta invalida!\n");
	}

	v.validateMedicineWithId("1","Paracetamol", "123", "Helpnet", "benzen");
	try{
		v.validateMedicineWithId("", "123", " ", "Helpnet12", "-asd");
	}
	catch(string& err){
		assert(err == "Id invalid!\nDenumire invalida!\nPret invalid!\nProducator invalid!\nSubstanta invalida!\n");
	}
	try{
		v.validateMedicineWithId("asd12","", "1-z", "", "-");
	}
	catch(string& err){
		assert(err == "Id invalid!\nDenumire invalida!\nPret invalid!\nProducator invalid!\nSubstanta invalida!\n");
	}
}

void test_service(){
	RepoMedicamente rep;
	Service srv{rep};
	srv.srvgetAll();
	assert(rep.getSize() == 0);
	Medicament med1(1, "Triferment", 123, "helpnet", "activa");
	srv.addMedSrv(med1);
	assert(rep.getSize() == 1);
	srv.modMedSrv(med1);
	srv.delMedSrv(med1.getId());
	assert(rep.getSize() == 0);

	Medicament med2(2, "Parasinus", 123, "aaa", "activa");
	srv.addMedSrv(med2);
	Medicament med3(3, "Triferment", 123, "helpnet", "activa");
	srv.addMedSrv(med3);
	Medicament med4(4, "Colebil", 123, "helpnet", "activa");
	srv.addMedSrv(med4);
	Medicament med5(5, "Nospa", 122, "helpnet", "activa");
	srv.addMedSrv(med5);

	
	auto out = srv.filter(1, "123");
	assert(out->size() == 3);
	delete out;

	out = srv.filter(2, "pa");
	assert(out->size() == 0);
	delete out;

	out = srv.sort(1);
	assert(out->at(0).getDenumire() == "Colebil");
	delete out;

	out = srv.sort(2);
	
	assert(out->at(0).getDenumire() == "Parasinus");
	delete out;

	out = srv.sort(3);
	assert(out->at(0).getDenumire() == "Nospa");
	delete out;

	srv.addMedRecSrv("Nospa");
	assert(rep.getRec().size() == 1);
	try{
		srv.addMedRecSrv("D");
	}
	catch(Exception& err){
		assert(err.getMessage() == "Medicament inexistent!\n");
	}

	srv.randSrv(15);
	assert(rep.getRec().size() == 16);

	srv.exportSrv("testoutput.csv");

	srv.delRecSrv();
	assert(rep.getRec().size() == 0);
}

void test_filerepo(){
	ofstream fout("abc.txt");
	if(fout.is_open()){
		fout << "";
		FileRepoMedicamente rep{"abc.txt"};
		Service srv{rep};
		try{
			rep.rand(15);
		}
		catch(Exception& err){
			assert(err.getMessage() == "Nu exista medicamente de adaugat in reteta!\n");
		}
		Medicament medicament;
		assert(rep.getSize() == 0);
		Medicament med1(1, "Triferment", 123, "helpnet", "activa");
		srv.addMedSrv(med1);
		assert(rep.getSize() == 1);
		Medicament med2(2, "Parasinus", 123, "helpnet", "activa");
		Medicament med3(1, "Colebil", 122, "ducfarm", "inactiva");
		srv.modMedSrv(med3);
		assert(rep.getMedicamentind(0).getDenumire() == "Colebil");
		assert(rep.getMedicamentind(0).getProducator() == "ducfarm");
		assert(rep.getMedicamentind(0).getSubstanta() == "inactiva");
		srv.addMedSrv(med2);
		srv.delMedSrv(med1.getId());
		assert(rep.getSize() == 1);
		srv.delMedSrv(med2.getId());
		assert(rep.getSize() == 0);

		srv.undo();
		assert(rep.getSize() == 1);
		srv.undo();
		assert(rep.getSize() == 2);
		srv.undo();
		assert(rep.getSize() == 1);
		srv.undo();
		srv.undo();
		assert(rep.getSize() == 0);
		try{
			srv.undo();
		}
		catch(Exception& err){
			assert(err.getMessage() == "Nu se mai poate face undo!\n");
		}
	}
}

void test_all(){
	test_domain();
	test_repo();
	test_validate();
	test_service();
	test_filerepo();
}