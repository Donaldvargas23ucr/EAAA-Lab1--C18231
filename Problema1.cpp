#include <fstream>
#include <iostream>
#include <cmath>
#include <limits>
using namespace std;
void ingreso_numeros(double &a,double &b,double &c);
double validar(const string& mensaje, const string& error);
void calcularRaices(double a, double b, double c, double* r1, double* r2,double discriminante);
void validacion_discriminante(double discriminante,double raiz1,double raiz2);
int main() {
    double a, b, c;
    double raiz1, raiz2;
    cout << "Bienvenido al solucionador de ecuaciones cuadráticas, ingrese los valores para a, b y c para conocer sus raices reales."<< endl;
    ingreso_numeros(a,b,c);
    double discriminante = b*b - 4*a*c;
    calcularRaices(a, b, c, &raiz1, &raiz2, discriminante); // le paso la dirección de memoria
    validacion_discriminante(discriminante,raiz1,raiz2);

    return 0;


}

 void ingreso_numeros(double &a,double &b,double &c){

    a = validar( "Ingrese el valor para a: ", "Error: debe ingresar un número.");
    cout << "Número ingresado: " << a << endl;


    b = validar( "Ingrese el valor para b: ", "Error: debe ingresar un número.");
    cout << "Número ingresado: " << b << endl;


    c = validar( "Ingrese el valor para c: ", "Error: debe ingresar un número.");
    cout << "Número ingresado: " << c << endl;
    cout << "La funcion ingresada corresponde a: "<< a <<"X^2+"<< b << "X+"<<c<<endl;
}


void validacion_discriminante(double discriminante,double raiz1,double raiz2){
    if (discriminante>0){
        cout<< "La ecuación tiene dos raices reales"<<endl;
        cout<< "Raiz numero 1: "<<raiz1<<endl;
        cout<< "Raiz numero 2: "<<raiz2<<endl;}


    else if (discriminante==0){
        cout << "La ecuación tiene una unica raiz real"<< endl;
        cout << "Su unica raiz real es: "<< raiz1<<endl;}
    cout << "Programa terminado." << endl;
    cout << "Presione ENTER para salir...";
    cin.ignore(); // descarta lo que haya en el buffer
    cin.get();    // espera ENTER


}



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
void calcularRaices(double a, double b, double c, double* r1, double* r2,double discriminante) {
    if (discriminante >= 0) {
        *r1 = (-b + sqrt(discriminante)) / (2*a); // se guarda en la variable "afuera"
        *r2 = (-b - sqrt(discriminante)) / (2*a);
    } else {
        cout << "Discriminante menor a 0, no existen soluciones reales"<< endl;
    } }





