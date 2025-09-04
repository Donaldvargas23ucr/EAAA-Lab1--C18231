#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;


void movimiento(double posx, double posy);
char verificar(string ingreso);
void cambiar_lugar(char moverse, double* posx, double* posy);


//El main que solo define las variables tipo puntero para las coordenadas y ejecuta la función movimiento.

int main(){

    double posx=1;
    double posy=1;
    movimiento(posx,posy);
    return 0;
}



//Función primordial con el switch y el while solicitados que cumple con ejecutar las funciones presentes en el resto del código.
//No se pudo implementar la lógica de ”fall-through”, puesto que el switch solo acepta variables de tipo char, por ende los strings
//como norte, sur, etc... eran inaceptables y no se me ocurrió mejor idea para su igual manejo que convertir todo ingreso a char con la
//función verificar.
void movimiento(double posx, double posy){
    string ingreso;
    char moverse;
    bool bucle=true;
    while(bucle){
    cout<<"Usted está en la habitacion "<<"["<<posx<<","<<posy<<"]."<<endl;
    cout<<"Ingrese la dirección a la que desea moverse: \n>>> ";
    cin>>ingreso;
    moverse = verificar(ingreso);
    switch (moverse){
    case 'n':
        cambiar_lugar(moverse,&posx,&posy);
        break;
    case 's':
        cambiar_lugar(moverse,&posx,&posy);
        break;
    case 'e':
        cambiar_lugar(moverse,&posx,&posy);
        break;
    case 'o':
        cambiar_lugar(moverse,&posx,&posy);
        break;
    case 'x':
    cout<<"Gracias por jugar"<<endl;
    bucle = false;
    break;
    default:
    cout <<"Ingrese solo valores coherentes para dar dirección (norte, sur, este, oeste)"<<endl;
    break;
    }}
}

//Función que ejecuta los cambios en las coordenadas x e y, dependiendo de la elección del usuario.
void cambiar_lugar(char moverse, double* posx, double* posy){
    if (moverse=='n') {
        if (*posy > 0){
            cout<<"Usted se mueve al norte"<<endl;
            (*posy =*posy -1);
        }
        else {
            cout << "No puedes ir por ahí, hay una pared"<<endl;
        }
    }
    else if (moverse=='s'){ 
        if (*posy < 2){
            cout<<"Usted se mueve al sur"<<endl;
            (*posy =*posy +1);
        }
        else {
            cout << "No puedes ir por ahí, hay una pared"<<endl;
        }
    }
    else if (moverse=='e'){ 
        if (*posx < 2){
            cout<<"Usted se mueve al este"<<endl;
            (*posx =*posx +1);
        }
        else {
            cout << "No puedes ir por ahí, hay una pared"<<endl;
        }
    }
    else if (moverse=='o'){ 
        if (*posx > 0){
            cout<<"Usted se mueve al oeste"<<endl;
            (*posx =*posx -1);
        }
        else {
            cout << "No puedes ir por ahí, hay una pared"<<endl;
        }
    }



}

// Esta función cumple con aceptar ambos tipos de ingresos, de tipo char y de tipo string, convirtiendo así ambos en un tipo char para mayor simpleza del código.
char verificar(string ingreso){
    char moverse =' ';
        if (ingreso == "n" || ingreso == "norte") moverse = 'n';
        else if (ingreso == "s" || ingreso == "sur") moverse = 's';
        else if (ingreso == "e" || ingreso == "este") moverse = 'e';
        else if (ingreso == "o" || ingreso == "oeste") moverse = 'o';
        else if (ingreso == "salir") moverse = 'x';
        else moverse = ' ';
    return moverse;

}



