#include "ui.h"

int Console::getRand(){
	std::mt19937 mt{std::random_device{}()};
	std::uniform_int_distribution<> dist(0, 999999);
	return dist(mt);
}

void Console::InitButtons(){
	//main app

	newvl = new QVBoxLayout();

	shw = new QListWidget;
	lst = new QListView();
	lst->setUniformItemSizes(true);
	model = new MyTableModel(lst, srv.srvgetAll());
	lst->setModel(model);

	shw2 = new QTableWidget;
	w = new QWidget();
	add = new QPushButton("&Add");
	modify = new QPushButton("&Modify");
	del = new QPushButton("&Delete");
	filByPRice = new QPushButton("&FilByPrice");
	filBySubst = new QPushButton("&FilBySubst");
	sortDen = new QPushButton("&SortByName");
	sortProd = new QPushButton("&SortByProd");
	sortSubstPret = new QPushButton("&SortBySubstPrice");
	undo = new QPushButton("&Undo");
	show = new QPushButton("&Show");
	append = new QPushButton("Append");
	erase = new QPushButton("&Erase");
	rand = new QPushButton("&Rand");
	exp = new QPushButton("&Export");
	hLay1 = new QHBoxLayout();
	hLay2 = new QHBoxLayout();
	hLay3 = new QHBoxLayout();
	hlay4 = new QHBoxLayout();
	vl = new QVBoxLayout();
	hl = new QHBoxLayout();

	//secondary app
	w1 = new QWidget;
	w2 = new QWidget;
	w3 = new QWidget;
	w4 = new QWidget;
	w5 = new QWidget;

	vL = new QVBoxLayout;
	fL = new QFormLayout;
	details1 = new QWidget;
	add1 = new QPushButton("&Add Medicine");
	vL2 = new QVBoxLayout;
	fL2 = new QFormLayout;
	details2 = new QWidget;
	modify1 = new QPushButton("&Modify Medicine");
	vL3 = new QVBoxLayout;
	fL3 = new QFormLayout;
	details3 = new QWidget;
	delete1 = new QPushButton("&Delete Medicine");
	vL4 = new QVBoxLayout;
	fL4 = new QFormLayout;
	details4 = new QWidget;
	filter = new QPushButton("&Filter");

	vL5 = new QVBoxLayout;
	fL5 = new QFormLayout;
	details5 = new QWidget;
	ret = new QPushButton("&Do");


	lblName = new QLabel("Denumire");
	txtName = new QLineEdit;
	lblPrice = new QLabel("Pret");
	txtPrice = new QLineEdit;
	lblProd = new QLabel("Producator");
	txtProd = new QLineEdit;
	lblSubst = new QLabel("Substanta activa");
	txtSubst = new QLineEdit;

	lblId1 = new QLabel("Id");
	txtId1 = new QLineEdit;
	lblName1 = new QLabel("Denumire");
	txtName1 = new QLineEdit;
	lblPrice1 = new QLabel("Pret");
	txtPrice1 = new QLineEdit;
	lblProd1 = new QLabel("Producator");
	txtProd1 = new QLineEdit;
	lblSubst1 = new QLabel("Substanta activa");
	txtSubst1 = new QLineEdit;

	lblId2 = new QLabel("Id");
	txtId2 = new QLineEdit;

	lblFil = new QLabel("Pret/Substanta");
	txtFil = new QLineEdit;

	lblRet = new QLabel("Input: ");
	txtRet = new QLineEdit;

	hlay5 = new QHBoxLayout;
	coscrudgui = new QPushButton("CosCRUDGUI");
	cosreadonlygui = new QPushButton("CosReadOnlyGUI");
}

void Console::Init(){
	//meniu principal
	pal.setColor(QPalette::Window, QColor::QColor(84, 130, 130));
	w->setAutoFillBackground(true);
	w->setPalette(pal);

	w1->setAutoFillBackground(true);
	w1->setPalette(pal);

	w2->setAutoFillBackground(true);
	w2->setPalette(pal);

	w3->setAutoFillBackground(true);
	w3->setPalette(pal);

	w4->setAutoFillBackground(true);
	w4->setPalette(pal);

	buton->setLayout(newvl);

	hLay1->addWidget(add);
	hLay1->addWidget(modify);
	hLay1->addWidget(del);
	hLay2->addWidget(filByPRice);
	hLay2->addWidget(filBySubst);
	hLay3->addWidget(sortDen);
	hLay3->addWidget(sortProd);
	hLay3->addWidget(sortSubstPret);
	hlay4->addWidget(append);
	hlay4->addWidget(erase);
	hlay4->addWidget(rand);
	hlay4->addWidget(exp);
	hlay5->addWidget(coscrudgui);
	hlay5->addWidget(cosreadonlygui);
	vl->addLayout(hLay1);
	vl->addLayout(hLay2);
	vl->addLayout(hLay3);
	vl->addWidget(undo);
	vl->addWidget(show);
	vl->addLayout(hlay4);
	vl->addLayout(hlay5);
	hl->addLayout(vl);
	hl->addWidget(lst);
	w->setLayout(hl);
	w->resize(820, 300);

	//meniu adauga
	w1->setLayout(vL);
	details1->setLayout(fL);
	fL->addRow(lblName, txtName);
	fL->addRow(lblPrice, txtPrice);
	fL->addRow(lblProd, txtProd);
	fL->addRow(lblSubst, txtSubst);
	vL->addWidget(details1);
	vL->addWidget(add1);

	//meniu modifica
	w2->setLayout(vL2);
	details2->setLayout(fL2);
	fL2->addRow(lblId1, txtId1);
	fL2->addRow(lblName1, txtName1);
	fL2->addRow(lblPrice1, txtPrice1);
	fL2->addRow(lblProd1, txtProd1);
	fL2->addRow(lblSubst1, txtSubst1);
	vL2->addWidget(details2);
	vL2->addWidget(modify1);

	//meniu sterge
	w3->setLayout(vL3);
	details3->setLayout(fL3);
	fL3->addRow(lblId2, txtId2);
	vL3->addWidget(details3);
	vL3->addWidget(delete1);

	//meniu filtreaza
	w4->setLayout(vL4);
	details4->setLayout(fL4);
	fL4->addRow(lblFil, txtFil);
	vL4->addWidget(details4);
	vL4->addWidget(filter);

	//meniu reteta
	w5->setLayout(vL5);
	details5->setLayout(fL5);
	fL5->addRow(lblRet, txtRet);
	vL5->addWidget(details5);
	vL5->addWidget(ret);
}
void Console::bTask1(){
	shw2->setColumnCount(1);
	shw2->setRowCount(1);
	try{
		validator.validateMedicine(txtName->displayText().toStdString(), txtPrice->displayText().toStdString(),
			txtProd->displayText().toStdString(), txtSubst->displayText().toStdString());
		id = this->getRand();
		Medicament med(this->id, txtName->displayText().toStdString(), stoi(txtPrice->displayText().toStdString()),
			txtProd->displayText().toStdString(), txtSubst->displayText().toStdString());
		srv.addMedSrv(med);
		model->setMedicine(srv.srvgetAll());
		shw->addItem("Medicament adaugat cu succes!\n");
		shw2->setItem(0, 0,
			new QTableWidgetItem("Medicament adaugat cu succes!\n"));
	}
	catch(Exception& err){
		shw->addItem(QString::fromStdString(err.getMessage()));
		shw2->setItem(0, 0,
			new QTableWidgetItem(QString::fromStdString(err.getMessage())));
	}
	catch(string& x){
		shw->addItem(QString::fromStdString(x));
		shw2->setItem(0, 0,
			new QTableWidgetItem(QString::fromStdString(x)));
	}
}

void Console::task1(){
	txtName->setText("");
	txtPrice->setText("");
	txtProd->setText("");
	txtSubst->setText("");
	w1->show();
	//string denumire, producator, substanta, pret;
	QObject::connect(add1, &QPushButton::clicked, [&](){
		shw->clear();
		shw2->clear();
		this->bTask1();
		w1->close();
	});
}

void Console::bTask2(){
	shw2->setColumnCount(1);
	shw2->setRowCount(1);
	try{
		validator.validateMedicineWithId(txtId1->displayText().toStdString(), txtName1->displayText().toStdString(), txtPrice1->displayText().toStdString(),
			txtProd1->displayText().toStdString(), txtSubst1->displayText().toStdString());
		Medicament med(stoi(txtId1->displayText().toStdString()), txtName1->displayText().toStdString(), stoi(txtPrice1->displayText().toStdString()),
			txtProd1->displayText().toStdString(), txtSubst1->displayText().toStdString());
		srv.modMedSrv(med);
		model->setMedicine(srv.srvgetAll());
		shw->addItem("Medicament modificat cu succes!\n");
		shw2->setItem(0, 0,
			new QTableWidgetItem("Medicament modificat cu succes!\n"));
	}
	catch(Exception& err){
		shw->addItem(QString::fromStdString(err.getMessage()));
		shw2->setItem(0, 0,
			new QTableWidgetItem(QString::fromStdString(err.getMessage())));
	}
	catch(string x){
		shw->addItem(QString::fromStdString(x));
		shw2->setItem(0, 0,
			new QTableWidgetItem(QString::fromStdString(x)));
	}
}

void Console::task2(){
	txtId1->setText("");
	txtName1->setText("");
	txtPrice1->setText("");
	txtProd1->setText("");
	txtSubst1->setText("");
	w2->show();
	QObject::connect(modify1, &QPushButton::clicked, [&](){
		shw->clear();
		shw2->clear();
		this->bTask2();
		w2->close();
		});
}

void Console::bTask3(){
	shw2->setColumnCount(1);
	shw2->setRowCount(1);
	try{
		validator.validateId(txtId2->displayText().toStdString());
		srv.delMedSrv(txtId2->displayText().toInt());
		model->setMedicine(srv.srvgetAll());
		shw->addItem("Medicament sters cu succes!\n");
		shw2->setItem(0, 0,
			new QTableWidgetItem("Medicament sters cu succes!\n"));
	}
	catch(Exception& err){
		shw->addItem(QString::fromStdString(err.getMessage()));
		shw2->setItem(0, 0,
			new QTableWidgetItem(QString::fromStdString(err.getMessage())));
	}
	catch(string x){
		shw->addItem(QString::fromStdString(x));
		shw2->setItem(0, 0,
			new QTableWidgetItem(QString::fromStdString(x)));
	}
}

void Console::task3(){
	txtId2->clear();
	w3->show();
	QObject::connect(delete1, &QPushButton::clicked, [&](){
		shw->clear();
		shw2->clear();
		this->bTask3();
		w3->close();
		});
}

void Console::task5(int cmd){
	txtFil->setText("");
	w4->show();
	if(cmd == 1)
		QObject::connect(filter, &QPushButton::clicked, [&](){
			shw->clear();
			try{
				validator.validateMedicine("ok",
					txtFil->displayText().toStdString(), "da", "da");
				showRez(srv.filter(1, txtFil->displayText().toStdString()));
			}
			catch(string x){
				shw->addItem(QString::fromStdString(x));
			}
			w4->close();
			});
	else
		QObject::connect(filter, &QPushButton::clicked, [&](){
		shw->clear();
		try{
			validator.validateMedicine("ok", "123", "da",
				txtFil->displayText().toStdString());
			showRez(srv.filter(2, txtFil->displayText().toStdString()));
		}
		catch(string x){
			shw->addItem(QString::fromStdString(x));
		}
		w4->close();
		});
}

void Console::task6(int cmd){
	shw->clear();
	shw2->clear();
	if(cmd == 1)
		showRez(srv.sort(1));
	else if(cmd == 2)
		showRez(srv.sort(2));
	else if(cmd == 3)
		showRez(srv.sort(3));
}

void Console::bTask7(){
	shw2->setColumnCount(1);
	shw2->setRowCount(1);
	try{
		validator.validateMedicine(txtRet->text().toStdString(),
			"123", "a", "a");
		srv.addMedRecSrv(txtRet->text().toStdString());
		notify();
		shw->addItem("Medicament adauagat cu succes in reteta!\n");
		shw2->setItem(0, 0,
			new QTableWidgetItem("Medicament adauagat cu succes in reteta!\n"));
	}
	catch(Exception& err){
		shw->addItem(QString::fromStdString(err.getMessage()));
		shw2->setItem(0, 0,
			new QTableWidgetItem(QString::fromStdString(err.getMessage())));
	}
	catch(string x){
		shw->addItem(QString::fromStdString(x));
		shw2->setItem(0, 0,
			new QTableWidgetItem(QString::fromStdString(x)));
	}
	w5->close();
}

void Console::task7(){
	shw->clear();
	shw2->clear();
	txtRet->setText("");
	w5->show();
	QObject::connect(ret, &QPushButton::clicked, [&](){
		this->bTask7();
		});
}

void Console::task8()
{
	shw->clear();
	shw2->setColumnCount(1);
	shw2->setRowCount(1);
	srv.delRecSrv();
	notify();
	shw->addItem("Reteta stearsa cu succes!\n");
	shw2->setItem(0, 0,
		new QTableWidgetItem(QString::fromStdString("Reteta stearsa cu succes!\n")));
}

void Console::bTask9(){
	shw2->setColumnCount(1);
	shw2->setRowCount(1);
	try{
		for(int i = 0; i < txtRet->text().toStdString().size(); i++)
			if(txtRet->text().toStdString()[i] < '0' ||
				txtRet->text().toStdString()[i] > '9')
				throw string("Numar invalid!\n");
		if(txtRet->text().toStdString().size() > 4)
			throw string("Numar prea mare!\n");
		if(txtRet->text().toStdString() == "0")
			throw string("Numar invalid!\n");
		srv.randSrv(txtRet->text().toInt());
		notify();
		shw->addItem("Medicamente adaugate cu succes in reteta!\n");
		shw2->setItem(0, 0,
			new QTableWidgetItem(QString::fromStdString("Medicamente adaugate cu succes in reteta!\n")));
	}
	catch(Exception& err){
		shw->addItem(QString::fromStdString(err.getMessage()));
		shw2->setItem(0, 0,
			new QTableWidgetItem(QString::fromStdString(err.getMessage())));
	}
	catch(string x){
		shw->addItem(QString::fromStdString(x));
		shw2->setItem(0, 0,
			new QTableWidgetItem(QString::fromStdString(x)));
	}
	w5->close();
}

void Console::task9(){
	shw->clear();
	txtRet->setText("");
	w5->show();
	QObject::connect(ret, &QPushButton::clicked, [&](){
		this->bTask9();
		});
}

void Console::bTask10(){
	shw2->setColumnCount(1);
	shw2->setRowCount(1);
	try{
		validator.validateMedicine(txtRet->text().toStdString(),
			"123", "a", "a");
		srv.exportSrv(txtRet->text().toStdString() + ".csv");
		shw->addItem("Reteta salvata cu succes!\n");
		shw2->setItem(0, 0,
			new QTableWidgetItem("Reteta salvata cu succes!\n"));
	}
	catch(string x){
		shw->addItem(QString::fromStdString(x));
		shw2->setItem(0, 0,
			new QTableWidgetItem(QString::fromStdString(x)));
	}
}

void Console::task10(){
	shw->clear();
	txtRet->setText("");
	w5->show();
	QObject::connect(ret, &QPushButton::clicked, [&](){
		this->bTask10();
		});
}

void Console::task11(){
	shw->clear();
	shw2->clear();
	shw2->setColumnCount(1);
	shw2->setRowCount(1);
	try{
		srv.undo();
		model->setMedicine(srv.srvgetAll());
		shw->addItem("Undo realizat cu succes!\n");
		shw2->setItem(0, 0,
			new QTableWidgetItem("Undo realizat cu succes!!\n"));
	}
	catch(Exception& err){
		shw->addItem(QString::fromStdString(err.getMessage()));
		shw2->setItem(0, 0,
			new QTableWidgetItem(QString::fromStdString(err.getMessage())));
	}
}

void Console::showRez(vector <Medicament>* rez){
	if(rez->size() == 0){
		shw->addItem("Nu exista medicamente!\n");
		shw2->setColumnCount(1);
		shw2->setRowCount(1);
		shw2->setItem(0, 0,
			new QTableWidgetItem("Nu exista medicamente!\n"));
	}
	else{
		model->setMedicine(*rez);
		for(int i = 0; i < rez->size(); i++)
			showMed(rez->at(i));
		shw2->setColumnCount(5);
		shw2->setRowCount(rez->size());
		for(int i = 0; i < rez->size(); i++){
			shw2->setItem(i, 0,
				new QTableWidgetItem(QString::fromStdString(to_string(rez->at(i).getId()))));
			shw2->setItem(i, 1,
				new QTableWidgetItem(QString::fromStdString(rez->at(i).getDenumire())));
			shw2->setItem(i, 2,
				new QTableWidgetItem(QString::fromStdString(to_string(rez->at(i).getPret()))));
			shw2->setItem(i, 3,
				new QTableWidgetItem(QString::fromStdString(rez->at(i).getProducator())));
			shw2->setItem(i, 4,
				new QTableWidgetItem(QString::fromStdString(rez->at(i).getSubstanta())));
		}
	}
	delete rez;
}

void Console::showMed(Medicament& m){
	shw->addItem(QString::fromStdString("Id: "
		+to_string(m.getId()) + " | Nume: " + m.getDenumire()
		+ " | Pret: " + to_string(m.getPret()) + " | Prod: "
		+ m.getProducator() + " | Subst: " + m.getSubstanta() + '\n'));
}

void Console::showAll(){
	if(srv.srvgetAll().size() == 0){
		shw->addItem("Nu exista medicamente!\n");
		shw2->setColumnCount(1);
		shw2->setRowCount(1);
		shw2->setItem(0, 0,
			new QTableWidgetItem("Nu exista medicamente!\n"));
	}
	else{
		model->setMedicine(srv.srvgetAll());
		for(int i = 0; i < srv.srvgetAll().size(); i++)
			showMed(srv.srvgetAll()[i]);
		shw2->setColumnCount(5);
		shw2->setRowCount(srv.srvgetAll().size());
		for(int i = 0; i < srv.srvgetAll().size(); i++){
			shw2->setItem(i, 0,
				new QTableWidgetItem(QString::fromStdString(to_string(srv.srvgetAll()[i].getId()))));
			shw2->setItem(i, 1,
				new QTableWidgetItem(QString::fromStdString(srv.srvgetAll()[i].getDenumire())));
			shw2->setItem(i, 2,
				new QTableWidgetItem(QString::fromStdString(to_string(srv.srvgetAll()[i].getPret()))));
			shw2->setItem(i, 3,
				new QTableWidgetItem(QString::fromStdString(srv.srvgetAll()[i].getProducator())));
			shw2->setItem(i, 4,
				new QTableWidgetItem(QString::fromStdString(srv.srvgetAll()[i].getSubstanta())));
		}
	}
}

void Console::connectButtons(){
	QObject::connect(add, &QPushButton::clicked, [&](){
		this->task1();
		showAll();
		});
	QObject::connect(modify, &QPushButton::clicked, [&](){
		this->task2();
		showAll();
		});
	QObject::connect(del, &QPushButton::clicked, [&](){
		this->task3();
		showAll();
		});
	QObject::connect(filByPRice, &QPushButton::clicked, [&](){
		this->task5(1);
		});
	QObject::connect(filBySubst, &QPushButton::clicked, [&](){
		this->task5(2);
		});
	QObject::connect(undo, &QPushButton::clicked, [&](){
		this->task11();
		showAll();
		});
	QObject::connect(show, &QPushButton::clicked, [&](){
		shw->clear();
		shw2->clear();
		this->showAll();
		});
	QObject::connect(sortDen, &QPushButton::clicked, [&](){
		this->task6(1);
		});
	QObject::connect(sortProd, &QPushButton::clicked, [&](){
		this->task6(2);
		});
	QObject::connect(sortSubstPret, &QPushButton::clicked, [&](){
		this->task6(3);
		});
	QObject::connect(append, &QPushButton::clicked, [&](){
		this->task7();
		});
	QObject::connect(erase, &QPushButton::clicked, [&](){
		this->task8();
		});
	QObject::connect(rand, &QPushButton::clicked, [&](){
		this->task9();
		});
	QObject::connect(exp, &QPushButton::clicked, [&](){
		this->task10();
		});
	QObject::connect(coscrudgui, &QPushButton::clicked, [&](){
		auto cd = new CosRead(*this, srv);
		cd->update();
		addObserver(cd);
		});
	QObject::connect(cosreadonlygui, &QPushButton::clicked, [&](){
		auto cd = new CosDraw(srv);
		cd->update();
		cd->setFixedSize(300, 300);
		cd->show();
		addObserver(cd);
		});
	w->show();
}

void CosRead::Init(){
	w = new QWidget;
	wdr = new QWidget;
	lst = new QListWidget;
	hl = new QHBoxLayout;
	w->setLayout(hl);
	vl = new QVBoxLayout;
	wdr->setLayout(vl);

	hl->addWidget(lst);
	hl->addWidget(wdr);
	w->show();

	append = new QPushButton("Append");
	erase = new QPushButton("&Erase");
	rand = new QPushButton("&Rand");

	vl->addWidget(append);
	vl->addWidget(erase);
	vl->addWidget(rand);
}

void CosRead::connectSignals(){
	QObject::connect(append, &QPushButton::clicked, [=](){
		c.task7();
		});
	QObject::connect(erase, &QPushButton::clicked, [&](){
		c.task8();
		});
	QObject::connect(rand, &QPushButton::clicked, [&](){
		c.task9();
		});
}

void CosRead::update(){
	lst->clear();
	for(auto& m : srv.srvgetReteta())
		lst->addItem(QString::fromStdString("Id: "
			+ to_string(m.getId()) + " | Nume: " + m.getDenumire()
			+ " | Pret: " + to_string(m.getPret()) + " | Prod: "
			+ m.getProducator() + " | Subst: " + m.getSubstanta() + '\n'));
}

MyTableModel::MyTableModel(QObject* parent, vector<Medicament>& lista):
	QAbstractTableModel(parent), lista{lista} {
}
int MyTableModel::rowCount(const QModelIndex& ) const {
	return lista.size();
}
int MyTableModel::columnCount(const QModelIndex&) const {
	return 1;
}
QVariant MyTableModel::data(const QModelIndex& index, int role) const {
	if(role == Qt::DisplayRole) {
		Medicament m = lista[index.row()];
		return QString(QString::fromStdString("Id: "
			+ to_string(m.getId()) + " | Nume: " + m.getDenumire()
			+ " | Pret: " + to_string(m.getPret()) + " | Prod: "
			+ m.getProducator() + " | Subst: " + m.getSubstanta() + '\n'));
	}
	return QVariant();
}