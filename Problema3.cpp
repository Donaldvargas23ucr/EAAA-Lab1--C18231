#include <fstream>
#include <iostream>
#include <cmath>
#include <limits>
using namespace std;


void maximos_minimos(double* lista_temperatura, int longitud_lista);
void calcular_promedio(double* lista_temperatura, int longitud_lista);
double validar(const string& mensaje, const string& error);
void menu(int longitud_lista);
void superior_a_umbral(double* lista_temperatura,int longitud_lista);
void temperaturas_celsius(double* lista_temperatura, int longitud_lista);
void temperaturas_fahrenheit(double* temperaturas, int longitud_lista);
double temperaturas[] = {22.5, 24.1, 21.9, 25.3, 26.0, 19.8, 23.7, 28.1, 18.5, 22.5};

//Función main donde se define la longitud de lista y se ejecuta el menú

int main() {
    int longitud_lista = 10;
    menu(longitud_lista);
return 0;

}






//Función general para validar datos numéricos positivos.
double validar(const string& mensaje, const string& error) {
    double valor;
    bool valor_bueno = false;

    while (!valor_bueno) {
        cout << mensaje;
        cin >> valor;

        if (cin.fail()) {
            cout << error << endl;
            cin.clear(); // limpiar el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // descartar lo malo
        } else {
            valor_bueno = true;
        }
    }
    return valor;
}
//Función que ejecuta el menú para mantener un orden en el programa.
void menu(int longitud_lista){

    cout << "Bienvenido al Analizador de Datos de Sensores de temperatura.\n Por favor, ingrese una de las siguientes opciones: "<<endl;
    int eleccion;
    bool bucle=true;
    cout<<" 1. Calcular valor promedio de las temperaturas registradas.\n 2. Encontrar valores maximo y minimo entre las temperaturas. \n 3. Contar temperaturas superiores a un umbral. \n 4. Mostrar datos en celsius. \n 5. Mostrar datos en Fahrenheit. \n 6. Salir del programa.\n";
    while (bucle) {
    eleccion=validar("Ingrese la opcion que desea ejecutar: ", "Error, debe ingresar solo valores numéricos:");
    switch (eleccion)
    {
    case 1:
        calcular_promedio(temperaturas, longitud_lista);
        break;
    case 2:
        maximos_minimos(temperaturas, longitud_lista);
        break;
    case 3:
        superior_a_umbral(temperaturas, longitud_lista);
        break;
    case 4:
        temperaturas_celsius(temperaturas, longitud_lista);
        break;
    case 5:
        temperaturas_fahrenheit(temperaturas, longitud_lista);
        break;
    case 6:
    cout<< "Gracias por utilizar el programa, hasta pronto"<<endl;
    bucle=false;
    break;
    default:
    cout<<"Por favor ingrese alguna de las opciones indicadas anteriormente.\n ";
        break;
    }}

}
//Función que ejecuta una acción de calcular promedio para las temperaturas dadas.
void calcular_promedio(double* lista_temperatura, int longitud_lista){
    double suma = 0;
    for (int i = 0; i < longitud_lista; i++) {
        suma += lista_temperatura[i];
    }
    cout << "El promedio entre los datos registrados para la temperatura corresponde a : " <<suma / longitud_lista<<"C "<<endl<<endl;

}
//Función que calcula los valores maximos y minimos para los datos registrados.
void maximos_minimos(double* lista_temperatura, int longitud_lista){
    double menor;
    double mayor;
    menor = lista_temperatura[0];
    mayor = lista_temperatura[0];
    for (int i = 0;i<longitud_lista; i++ ){
        if (lista_temperatura[i]<menor){
            menor = lista_temperatura[i];}
        if(lista_temperatura[i]>mayor){
            mayor = lista_temperatura[i];}
        }
        
    cout << "El valor mas alto registrado en las mediciones es " << mayor<<"C y el mas bajo registrado en las mediciones es "<< menor<<"C "<<endl<<endl;
}
//Función que contabiliza los valores mayores a cierto umbral dado por el usuario.
void superior_a_umbral(double* lista_temperatura,int longitud_lista){
    float valor_ingresado;
    int contador=0;
    valor_ingresado=validar("Ingrese la temperatura en Celsius que desee conocer cuantos valores superiores posee: ", "Error, debe ingresar solo valores numéricos:");
    for (int i=0; i < longitud_lista; i++){
        if (lista_temperatura[i]>valor_ingresado){
            contador +=1;
        }}
    cout<<"Hay "<<contador<<" temperaturas en la lista mayores a "<<valor_ingresado<<"C"<<endl;
}

//Función que imprime en terminal la temperatura en grados Celsius.
void temperaturas_celsius(double* lista_temperatura, int longitud_lista){
    cout<<"----Valores en Celsius para las temperaturas registradas----"<<endl;
    for (int i=0; i<longitud_lista; i++){
        if (longitud_lista-1==i){
            cout<< lista_temperatura[i]<<"C"<<endl;
            break;
        }
        cout << lista_temperatura[i]<<"C, ";
    }
}

//Función que transforma de Celsius a Fahrenheit y las imprime en terminal.
void temperaturas_fahrenheit(double*lista_temperatura, int longitud_lista){

    cout<<"----Valores en Fahrenheit para las temperaturas registradas----"<<endl;
    float valores_transformados = 0;
    for (int i=0; i<longitud_lista; i++){
        valores_transformados= (lista_temperatura[i]*9/5)+32;
        if (longitud_lista-1==i){
            cout<< valores_transformados<<"F"<<endl;
            break;
        }
        cout << valores_transformados<<"F, ";
    }

}