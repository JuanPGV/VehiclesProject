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

struct Spare{
    int id_spare;
    string model;
    string brand;
    string spare_name;
    string car_model;
    int car_year;
    int price;
    int existences;
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

void ActualizarCarro(){
    Car c;
    string line;
    cout<<"Ingrese el id del carro que quiere actualizar"<<endl;
    cin>>c.id;
    ifstream CarsFile("bin/Cars.csv", ios::in);
    ofstream Temp("bin/Temp.csv",ios::out);
    while(getline(CarsFile,line)){
        int actual_id = atoi(line.substr(0,line.find(',')).c_str());
        if(actual_id!=c.id){
            Temp<<line<<endl;
        }
        else{
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

            Temp << c.id << "," << c.model << "," << c.brand << "," << c.plate << "," << c.color << "," << c.year << "," << c.mileage << "," << c.was_rented << "," << c.engine << "," << c.price << "," << c.id_client <<endl;
            Temp.close();
            CarsFile.close();

            remove("bin/Cars.csv");
            rename("bin/Temp.csv","bin/Cars.csv");
            cout<<"Carro actualizado de forma exitosa"<<endl;
        }
    }
}

void ConsultarCarro(){
    Car c;
    string line;
    cout<<"Ingrese el id del carro del que desea hacer la consulta: ";
    cin>>c.id;

    ifstream CarsFile("bin/Cars.csv");
    while(getline(CarsFile,line)){
        size_t pos = 0;
        size_t next_pos = line.find(',');

        int actual_id = atoi(line.substr(0,line.find(',')).c_str());
        if(actual_id==c.id){
            pos = next_pos + 1;

            next_pos = line.find(',', pos);
            c.model = line.substr(pos, next_pos - pos);
            pos = next_pos + 1;

            next_pos = line.find(',', pos);
            c.brand = line.substr(pos, next_pos - pos);
            pos = next_pos + 1;

            next_pos = line.find(',', pos);
            c.plate = line.substr(pos, next_pos - pos);
            pos = next_pos + 1;

            next_pos = line.find(',', pos);
            c.color = line.substr(pos, next_pos - pos);
            pos = next_pos + 1;

            next_pos = line.find(',', pos);
            c.year = stoi(line.substr(pos, next_pos - pos));
            pos = next_pos + 1;

            next_pos = line.find(',', pos);
            c.mileage = stoi(line.substr(pos, next_pos - pos));
            pos = next_pos + 1;

            next_pos = line.find(',', pos);
            c.was_rented = line.substr(pos, next_pos - pos);
            pos = next_pos + 1;

            next_pos = line.find(',', pos);
            c.engine = line.substr(pos, next_pos - pos);
            pos = next_pos + 1;

            next_pos = line.find(',', pos);
            c.price = stof(line.substr(pos, next_pos - pos));
            pos = next_pos + 1;

            c.id_client = stoi(line.substr(pos));

            cout << "ID: " << c.id << endl;
            cout << "Modelo: " << c.model << endl;
            cout << "Marca: " << c.brand << endl;
            cout << "Placa: " << c.plate << endl;
            cout << "Color: " << c.color << endl;
            cout << "Anio: " << c.year << endl;
            cout << "Kilometraje: " << c.mileage << endl;
            cout << "Rentado: " << c.was_rented << endl;
            cout << "Motor: " << c.engine << endl;
            cout << "Precio: " << c.price << endl;
            cout << "ID Cliente: " << c.id_client << endl;
        }
    }
    CarsFile.close();
}

void AgregarCliente(){
    Client c;
    string line;

    cout << "Ingrese los siguientes datos:" << endl;
    cout<<"Cedula: ";
    cin>>c.id_client;
    cout << "Nombre: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, c.first_name);
    cout << "Apellido: ";
    getline(cin, c.last_name);
    cout << "Email: ";
    getline(cin, c.email);
    cout << "Vehiculos rentados: ";
    cin>> c.rented_vehicles;
    cout << "Direccion: ";
    cin >> c.direction;
    cout << "Activo: ";
     cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> c.active;

    ofstream ClientsFile2("bin/Clients.csv", ios::app);
    ClientsFile2 << c.id_client << "," << c.first_name << "," << c.last_name << "," << c.email << "," << c.rented_vehicles << "," << c.direction << "," << c.active <<endl;
    ClientsFile2.close();
    cout<<"Cliente agregado con exito"<<endl;
}

void EliminarCliente(){
    Client c;
    string line;
    ifstream ClientsFile("bin/Clients.csv", ios::in);
    ofstream Temp("bin/Temp.csv",ios::out);

    cout<<"Ingrese el id del cliente que desea eliminar: ";
    cin>>c.id_client;

    while(getline(ClientsFile,line)){
        int actual_id = atoi(line.substr(0,line.find(',')).c_str());
        if(actual_id!=c.id_client){
            Temp<<line<<endl;
        }
    }

    ClientsFile.close();
    Temp.close();

    remove("bin/Clients.csv");
    rename("bin/Temp.csv","bin/Clients.csv");
    cout<<"Cliente eliminado correctamente"<<endl;
}

void AgregarRepuesto(){
    Spare s;
    string line;
    int new_id = 0;
    ifstream SpareFile("bin/Spare.csv");
    while(getline(SpareFile,line)){
        new_id++;   
    }
    SpareFile.close();

    cout << "Ingrese los siguientes datos:" << endl;
    cout<<"Modelo: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,s.model);
    cout << "Marca: ";
    getline(cin, s.brand);
    cout << "Nombre repuesto: ";
    getline(cin, s.spare_name);
    cout << "Modelo de carro al que le sirve el repuesto: ";
    getline(cin, s.car_model);
    cout << "Anio del carro al que le sirve el repuesto: ";
    cin>> s.car_year;
    cout << "Precio: ";
    cin >> s.price;
    cout << "Cantidad de repuestos disponibles: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> s.existences;
    s.id_spare = new_id;

    ofstream SpareFile2("bin/Spare.csv", ios::app);
    SpareFile2 << s.id_spare << "," << s.model << "," << s.brand << "," << s.spare_name << "," << s.car_model << "," << s.car_year << "," << s.price << "," << s.existences  <<endl;
    SpareFile2.close();
    cout<<"Repuesto agregado con exito"<<endl;
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