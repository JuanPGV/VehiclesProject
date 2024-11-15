#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<limits>
using namespace std;

struct Car{
    int id;
    string model;
    string brand;
    string plate;
    string color;
    int year;
    int mileage;
    string was_rented;
    string engine;
    int price;
    int id_client;
};

void menu();

void AgregarCarro();
void EliminarCarro();
void ActualizarCarro();
void ConsultarCarro();


int main(){

}

void AgregarCarro(){
    Car c;
    string line;
    int newid = 0;
    ifstream CarsFile("bin/Cars.csv");

    while(getline(CarsFile,line)){
        newid++;
    }
    CarsFile.close();

    cout << "Ingrese los siguientes datos:" << endl;
    c.id = newid;
    cout << "Modelo: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, c.model);
    cout << "Marca: ";
    getline(cin, c.brand);
    cout << "Placa: ";
    getline(cin, c.plate);
    cout << "Color: ";
    getline(cin , c.color);
    cout << "Ano: ";
    cin >> c.year;
    cout << "Kilometraje: ";
    cin >> c.mileage;
    cout << "Rentado: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, c.was_rented);
    cout << "Motor: ";
    getline(cin , c.engine);
    cout << "Precio: ";
    cin >> c.price;
    cout<< "ID cliente: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin>> c.id_client;

    ofstream CarsFile2("bin/Cars.csv", ios::app);
    CarsFile2 << c.id << "," << c.model << "," << c.brand << "," << c.plate << "," << c.color << "," << c.year << "," << c.mileage << "," << c.was_rented << "," << c.engine << "," << c.price << "," << c.id_client <<endl;
    CarsFile2.close();
    cout<<"Carro agregado con exito"<<endl;
    }
