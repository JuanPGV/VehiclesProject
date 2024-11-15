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

struct Client{
    int id_client;
    string first_name;
    string last_name;
    string email;
    int rented_vehicles;
    string direction;
    int active;
};

void menu();

void AgregarCarro();
void EliminarCarro();
void ActualizarCarro();
void ConsultarCarro();

void AgregarCliente();
void EliminarCliente();
void ActualizarCliente();
void ConsultarCliente();

void AgregarRepuesto();
void EliminarRepuesto();
void ActualizarRepuesto();
void ConsultarRepuesto();


int main(){
menu();
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

void EliminarCarro(){
    Car c;
    string line;
    cout<<"Ingrese el id del carro que desea eliminar: "<<endl;
    cin>>c.id;
    ofstream Temp("bin/Temp.csv", ios::out);
    if(!Temp){
        cout<<"El archivo temporal no se abrio correctamente"<<endl;
    }
    ifstream Carsfile("bin/Cars.csv", ios::in);
    if(!Carsfile){
        cout<<"El archivo de carros no se abrio correctamente"<<endl;
    }
    while(getline(Carsfile,line)){
        int actual_id = atoi(line.substr(0,line.find(',')).c_str());
        if(actual_id != c.id){
            Temp<<line<<endl;
        }
    }
    Temp.close();
    Carsfile.close();

    remove("bin/Cars.csv");
    rename("bin/Temp.csv","bin/Cars.csv");
    cout<<"Carro eliminado con exito"<<endl;
}

void menu(){
    int opcion=0,opcion2=0,opcion3=0,opcion4=0,opcion5=0;
     cout<<"Bienvenido a Vehiculos El Torito!!"<<endl;
    while(opcion!=5){
    cout<<"Ingrese una opcion"<<endl
    <<"1.-Agregar"<<endl
    <<"2.-Borrar"<<endl
    <<"3.-Actualizar"<<endl
    <<"4.-Consultar"<<endl
    <<"5.-Salir"<<endl;
    cin>>opcion;
   
    switch (opcion)
    {
    case 1:
            cout<<"En que archivo desea agregar un elemento?"<<endl
            <<"1.-Carros"<<endl
            <<"2.-Clientes"<<endl
            <<"3.-Repuestos"<<endl;
            cin>>opcion2;

        if(opcion2==1){
            AgregarCarro();
        }
        else if(opcion2==2){
            AgregarCliente();
        }
        else if(opcion2==3){
            AgregarRepuesto();
        }
        else{
            cout<<"Por favor ingrese un numero valido"<<endl;
        }
    
        break;
    
    case 2:
        while(opcion3<1 or opcion3>3){
            cout<<"En que archivo desea eliminar un elemento?"<<endl
            <<"1.-Carros"<<endl
            <<"2.-Clientes"<<endl
            <<"3.-Repuestos"<<endl;
            cin>>opcion3;

        if(opcion3==1){
            EliminarCarro();
        }
        else if(opcion3==2){
            EliminarCliente();
        }
        else if(opcion3==3){
            EliminarRepuesto();
        }
        else{
            cout<<"Por favor ingrese un numero valido"<<endl;
        }
    }
        break;


    case 3:
        while(opcion4<1 or opcion4>3){
            cout<<"En que archivo desea actualizar un elemento?"<<endl
            <<"1.-Carros"<<endl
            <<"2.-Clientes"<<endl
            <<"3.-Repuestos"<<endl;
            cin>>opcion4;

        if(opcion4==1){
           ActualizarCarro();
        }
        else if(opcion4==2){
            ActualizarCliente();
        }
        else if(opcion4==3){
            ActualizarRepuesto();
        }
        else{
            cout<<"Por favor ingrese un numero valido"<<endl;
        }
    }
        break;

    case 4:
        while(opcion5<1 or opcion5>3){
            cout<<"En que archivo desea hacer una consulta?"<<endl
            <<"1.-Carros"<<endl
            <<"2.-Clientes"<<endl
            <<"3.-Repuestos"<<endl;
            cin>>opcion5;

        if(opcion5==1){
            ConsultarCarro();
        }
        else if(opcion5==2){
            ConsultarCliente();
        }
        else if(opcion5==3){
            ConsultarRepuesto();
        }
        else{
            cout<<"Por favor ingrese un numero valido"<<endl;
        }
    }
        break;
    
    case 5:
        cout<<"Gracias por visitarnos:)"<<endl;
        break;
    default:
        cout<<"Por favor ingrese un numero dentro del rango"<<endl;
        break;
    }
}
}