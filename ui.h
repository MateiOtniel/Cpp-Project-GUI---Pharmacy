#pragma once
#include "service.h"
#include "validator.h"
#include "observer.h"
#include <iostream>
#include <QApplication>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qlistwidget.h>
#include <QtWidgets/qformlayout.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qmessagebox.h>
#include <QTableWidget>
#include <qpainter.h>
#include <qlistview.h>
#include <qdebug.h>

using namespace std;


class MyTableModel: public QAbstractTableModel {
public:
	MyTableModel(QObject* parent, vector<Medicament>& lista);
	int rowCount(const QModelIndex& parent = QModelIndex()) const override;
	int columnCount(const QModelIndex& parent = QModelIndex()) const override;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
	void setMedicine(const vector<Medicament>& list) {
		this->lista = list;
		QModelIndex topLeft = createIndex(0, 0);
		QModelIndex bottomRight = createIndex(rowCount(), columnCount());
		emit dataChanged(topLeft, bottomRight);
	}
private:
	vector<Medicament> lista;
};

class Console: public QWidget, public Observable{
public:
	void InitButtons();
	void Init();
	void bTask1();
	Console(Service& srv, Validator& validator):srv{srv}, validator{validator}{
		buton = new QWidget();
		this->InitButtons();
		this->Init();
	}
	void connectButtons();
	int getRand();
	void task1();
	void bTask2();
	void task2();
	void bTask3();
	void task3();
	void task5(int cmd);
	void task6(int cmd);
	void bTask7();
	void task7();
	void task8();
	void bTask9();
	void task9();
	void bTask10();
	void task10();
	void task11();
	void showRez(vector <Medicament>*);
	void showMed(Medicament& m);
	void showAll();
	~Console(){
		delete buton;
	};
private:
	vector <pair<string, int>> substante;
	int id = 0;
	Service& srv;
	Validator& validator;
	//main app
	
	QVBoxLayout* newvl;
	QWidget* buton;
	QListWidget* shw;
	QListView* lst;
	MyTableModel* model;
	QTableWidget* shw2;

	QWidget* w;
	QPushButton* add;
	QPushButton* modify;
	QPushButton* del;
	QPushButton* filByPRice;
	QPushButton* filBySubst;
	QPushButton* sortDen;
	QPushButton* sortProd;
	QPushButton* sortSubstPret;
	QPushButton* undo;
	QPushButton* show;
	QPushButton* append;
	QPushButton* erase;
	QPushButton* rand;
	QPushButton* exp;
	QHBoxLayout* hLay1;
	QHBoxLayout* hLay2;
	QHBoxLayout* hLay3;
	QHBoxLayout* hlay4;
	QHBoxLayout* hlay5;
	QVBoxLayout* vl;
	QHBoxLayout* hl;
	QPushButton* coscrudgui;
	QPushButton* cosreadonlygui;

	//culoare GUI
	QPalette pal = QPalette();

	//secondary app
	QWidget* w1;
	QWidget* w2;
	QWidget* w3;
	QWidget* w4;
	QWidget* w5;

	QVBoxLayout* vL;
	QFormLayout* fL;
	QWidget* details1;
	QPushButton* add1;
	QVBoxLayout* vL2;
	QFormLayout* fL2;
	QWidget* details2;
	QPushButton* modify1;
	QVBoxLayout* vL3;
	QFormLayout* fL3;
	QWidget* details3;
	QPushButton* delete1;
	QVBoxLayout* vL4;
	QFormLayout* fL4;
	QWidget* details4;
	QPushButton* filter;

	QVBoxLayout* vL5;
	QFormLayout* fL5;
	QWidget* details5;
	QPushButton* ret;

	QLabel* lblName;
	QLineEdit* txtName;
	QLabel* lblPrice;
	QLineEdit* txtPrice;
	QLabel* lblProd;
	QLineEdit* txtProd;
	QLabel* lblSubst;
	QLineEdit* txtSubst;

	QLabel* lblId1;
	QLineEdit* txtId1;
	QLabel* lblName1;
	QLineEdit* txtName1;
	QLabel* lblPrice1;
	QLineEdit* txtPrice1;
	QLabel* lblProd1;
	QLineEdit* txtProd1;
	QLabel* lblSubst1;
	QLineEdit* txtSubst1;

	QLabel* lblId2;
	QLineEdit* txtId2;

	QLabel* lblFil;
	QLineEdit* txtFil;

	QLabel *lblRet;
	QLineEdit* txtRet;
};

class CosRead: public Observer{
public:
	CosRead(Console& c, Service& srv): c{c}, srv{ srv }{
		Init();
		connectSignals();
	};
	void Init();
	void connectSignals();
	void update() override;

private:
	Service& srv;
	Console& c;
	QWidget* w;
	QWidget* wdr;
	QListWidget* lst;
	QHBoxLayout* hl;
	QVBoxLayout* vl;

	QPushButton* append;
	QPushButton* erase;
	QPushButton* rand;
};

class CosDraw: public QWidget, public Observer{
public:
	CosDraw(Service& srv): srv{srv}{};
	void paintEvent(QPaintEvent* ev) override{
		QPainter p{this};
		std::mt19937 mt{std::random_device{}()};
		std::uniform_int_distribution<> dist(0, 300);
		for(const auto& el : srv.srvgetReteta()) {
			QColor colours[10] = {QColor("cyan"), QColor("magenta"), QColor("red"),
					  QColor("darkRed"), QColor("darkCyan"), QColor("darkMagenta"),
					  QColor("green"), QColor("darkGreen"), QColor("yellow"),
					  QColor("blue")};
			p.setPen(colours[dist(mt) % 10]);
			p.drawEllipse(dist(mt) % 250, dist(mt) % 250, 150, 150);
		}
	}
	void update() override{
		repaint();
	}
private:
	Service& srv;
};
