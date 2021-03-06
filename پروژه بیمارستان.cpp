// پروژه بیمارستان.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<fstream>
#include<string>
using namespace std;

class Person
{
protected:
	string name, family, phone, address;
public:
	Person() {}
	Person(string name, string family, string phone, string address);
	void setName(string name) { this->name = name; }
	void setFamily(string family) { this->family = family; }
	void setPhone(string phone) { this->phone = phone; }
	void setAddress(string address) { this->address = address; }

	string getName()const { return name; }
	string getFamily()const { return family; }
	string getPhone()const { return phone; }
	string getAddress()const { return address; }
	void printall();
};
void Person::printall()
{
	cout << name << setw(6) << family << setw(10) << phone << setw(8) << address << setw(5);
}
Person::Person(string name, string family, string phone, string address)
{
	setName(name);
	setFamily(family);
	setPhone(phone);
	setAddress(address);
}

//**************************DOCTOR****************************************************
//************************************************************************************


class Doctor:public Person
{
private:
	int dcode;
	string specialty;
public:
	Doctor(){}
	Doctor(string name, string family, string phone, string address, int dcode, string specialty)
		:Person(name, family, phone, address) {
		this->dcode = dcode;
		this->specialty = specialty;
	}
	void setCode(int dcode) { this->dcode = dcode; }
	void setSpecialty(string specialty) { this->specialty = specialty; }

	string getSpecialty()const { return specialty; }
	int getCode()const { return dcode; }
	void printall();
	void printone(int&code);

};
vector<Doctor>listD;
fstream fileDoc;
Doctor dc;
int countd = 0;
void Doctor::printall()
{
	system("cls");
	cout << "\n\n\t\t ALL  DOCTORS            \n\n";
	cout << "=============================================================\n";
	cout << "NAME     FAMILY      PHONE     ADDRESS    CODE    SPECIALTY   " << endl;
	cout << "=============================================================\n";

	for (int i = 0;i < listD.size();i++)
	{
			cout << listD[i].name << setw(10) << listD[i].family << setw(10) << listD[i].phone << setw(8) << listD[i].address << setw(8) << listD[i].dcode << setw(6)<<"   " << listD[i].specialty << setw(8)<<endl;
	}
	cout << "\nThe number of doctors are " << countd << endl;
}
void Doctor::printone(int &code) 
{
	system("cls");
	cout << "\n\n\t\tSPECIFIC DOCTOR \n\n";
	cout << "=============================================================\n";
	cout << "NAME     FAMILY      PHONE     ADDRESS    CODE    SPECIALTY   " << endl;
	cout << "=============================================================\n";
	for (int i = 0;i < listD.size();i++)
	{
		if(listD[i].dcode==code)
		cout << listD[i].name << setw(10) << listD[i].family << setw(10) << listD[i].phone << setw(8) << listD[i].address << setw(8) << listD[i].dcode << setw(6)<<"    " << listD[i].specialty << setw(8)<<endl;
	}
}
void createDoctor()
{
	Doctor d;
	string name, family, phone, address, specialty;
	int code;
		cout << "Enter Name:";
		cin >> name;
		d.setName(name);
		cout << "Enter Family:";
		cin >> family;
		d.setFamily(family);
		cout << "Enter code:";
		cin >> code;
		d.setCode(code);
		cout << "Enter Address:";
		cin >> address;
		d.setAddress(address);
		cout << "Enter Phone:";
		cin >> phone;
		d.setPhone(phone);
		cout << "Enter Specialty:";
		cin >> specialty;
		d.setSpecialty(specialty);
		
		listD.push_back(d);
		fileDoc.open("Doctor.csv", ios::app);
		fileDoc << d.getName() + "," + d.getFamily() + "," + to_string(d.getCode()) + "," + d.getAddress() + "," + d.getPhone()+ "," + d.getSpecialty() << endl;
		countd++;
	
}
void modifyDoctor(int c) //c==code
{
	int a;
	string n, f, s;
	for (int i = 0;i < listD.size();i++)
	{
		if (listD[i].getCode() == c)
		{
			cout << "\n\n\n\tSELECT MENU";
			cout << "\n\n\n\t1. NAME";
			cout << "\n\n\t2. FAMILY";
			cout << "\n\n\t3. SPECIALTY";
			cout << "\n\n\n\tEnter Choice (1/2/3)? ";
			cin >> a;

			switch (a)
			{
			case 1: cout << "Enter name:"; cin >> n; listD[i].setName(n); break;
			case 2: cout << "Enter family:"; cin >> f; listD[i].setFamily(f); break;
			case 3: cout << "Enter specialty:"; cin >> s; listD[i].setSpecialty(s); break;



			default:
				break;
			}




		}
		}
	
}

//**********************************PATIENT******************************************************
//*********************************************************************************************

class Patient:public Person
{
private:
	string disease;
	int pcode;
public:
	Patient(){}
	Patient(string name, string  family, string  phone, string address, string disease,int pcode) 
		:Person(name, family, phone, address) {
	this ->disease=disease;
	this->pcode = pcode;}
	void setDisease(string disease) { this->disease = disease; }
	void setcodeP(int pcode) { this->pcode = pcode; }
	string getDisease()const { return disease; }
	int getcodeP()const { return pcode; }
	void printall();
	void printone(int &code);
};
multimap <int, string> savedpatient;
multimap <int, string> getsavedpatient() {
	return savedpatient;
}
fstream filePT;
vector<Patient>listP;
int countp=0;

void Patient::printall()
{
	system("cls");
	cout << "\n\n\t\t ALL PATIENT            \n\n";
	cout << "=============================================================\n";
	cout << "NAME     FAMILY      PHONE     ADDRESS    CODE     DISEASE  " << endl;
	cout << "=============================================================\n";

	for (int i = 0;i < listD.size();i++)
	{
		cout << listP[i].name << setw(10) << listP[i].family << setw(10) << listP[i].phone << setw(8) << listP[i].address << setw(8) << listP[i].pcode << setw(6) << "   " << listP[i].disease << setw(8) << endl;
	}
	cout << "\nThe number of patient is "<<countp<<endl;

}
void Patient::printone(int &code)
{
	system("cls");
	cout << "\n\n\t\tSPECIFIC PATIENT \n\n";
	cout << "=============================================================\n";
	cout << "NAME     FAMILY      PHONE     ADDRESS    CODE    DISEASE   " << endl;
	cout << "=============================================================\n";
	for (int i = 0;i < listP.size();i++)
	{
		if (listP[i].pcode == code)
			cout << listP[i].name << setw(10) << listP[i].family << setw(10) << listP[i].phone << setw(8) << listP[i].address << setw(8) << listP[i].pcode << setw(6) << "   " << listP[i].disease << setw(8) << endl;
	}
}
void createPatient()
{
	dc.printall();
	Patient p;
	string disease, name, family, phone, address;
	int pcode, coded;
	cout << "Enter Name:";
	cin >> name;
	p.setName(name);
	cout << "Enter Family:";
	cin >> family;
	p.setFamily(family);
	cout << "Enter code:";
	cin >> pcode;
	p.setcodeP(pcode);
	cout << "Enter Address:";
	cin >> address;
	p.setAddress(address);
	cout << "Enter Phone:";
	cin >> phone;
	p.setPhone(phone);
	cout << "Enter Disease:";
	cin >> disease;
	p.setDisease(disease);
	cout << "Enter the code of doctor:";
	cin >>coded;
	savedpatient.insert(pair<int, string>(coded, name + " " + family));
	listP.push_back(p);
	filePT.open("Patient.csv", ios::app);
	filePT << p.getName() + "," + p.getFamily() + "," + to_string(p.getcodeP()) + "," + p.getAddress() + "," + p.getPhone() + "," + p.getDisease() << endl;
	countp++;

}
void modifyPatient(int c) //c==code
{
	int a;
	string n, f, d;
	for (int i = 0;i < listP.size();i++)
	{
		if (listP[i].getcodeP() == c)
		{
			cout << "\n\n\n\tSELECT MENU";
			cout << "\n\n\n\t1. NAME";
			cout << "\n\n\t2. FAMILY";
			cout << "\n\n\t3.DISEASE";
			cout << "\n\n\n\tEnter Choice (1/2/3)? ";
			cin >> a;

			switch (a)
			{
			case 1: cout << "Enter name:"; cin >> n; listP[i].setName(n); break;
			case 2: cout << "Enter family:"; cin >> f; listP[i].setFamily(f); break;
			case 3: cout << "Enter disease:"; cin >> d; listP[i].setDisease(d); break;



			default:
				break;
			}




		}
	}

}
void printsavedpatient(int code) {

	multimap<int, string> list = getsavedpatient();
	for (multimap<int, string> ::iterator it = list.begin(); it != list.end();it++) {

		if (code == it->first) {
			cout << it->second;
			cout << endl;
		}



	}

}
int main()
{
	int code;
	createDoctor();
	createPatient();
	cout << "enter coded:";
	cin >> code;
	printsavedpatient(code);

    return 0;
}

