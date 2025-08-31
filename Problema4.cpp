#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;




void menu(vector<string>& tareas);
double validar(const string& mensaje, const string& error);
void agregar(vector<string>& tareas);
void ver(vector<string>& tareas);
void completar(vector<string>& tareas);
int main(){
vector<string> tareas;
menu(tareas);
cout << "Programa terminado." << endl;
cout << "Presione ENTER para salir...";
cin.ignore(); // descarta lo que haya en el buffer
cin.get();    // espera ENTER
return 0;
}







void menu(vector<string>& tareas){
    cout << "---Mi lista de tareas---"<<endl;
    int eleccion;
    bool bucle=true;
    cout<<"1. Agregar tarea. \n2. Ver tarea.\n3. Marcar tarea como completada. \n4. Salir del programa. \n";
    while (bucle) {
    eleccion=validar("Ingrese la opcion que desea ejecutar: ", "Error, debe ingresar solo valores numéricos:");
    switch (eleccion)
    {
    case 1:
    agregar(tareas);
    break;
    case 2:
    ver(tareas);
    break;
    case 3:
    completar(tareas);
    break;
    case 4:
    cout<< "Gracias por utilizar el programa, hasta pronto"<<endl;
    bucle=false;
    break;
    default:
    cout<<"Por favor ingrese alguna de las opciones indicadas acontinuacion.\n ";
        break;
    }}
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
    return valor;}


void agregar(vector<string>& tareas){

    string tarea_nueva;

    cout << "Ingrese la tarea que desea añadir a sus pendientes: ";
    cin >> tarea_nueva;
    tareas.push_back(tarea_nueva);
}

void ver(vector<string>& tareas){
    if(tareas.size()==0){
            cout << "Su lista de tareas está vacía"<<endl;}
        else {cout<<"---Sus tareas pendientes---"<<endl;
            for (int i=0; i<tareas.size(); i++){
                cout <<i+1<<". " <<tareas[i]<<endl;}
            cout <<"-----------------------"<<endl;}}

void completar(vector<string>& tareas){
    int tarea_completada =0;
    tarea_completada=validar("Ingrese la tarea que desea marcar como completada: ", "Error, debe ingresar solo valores numéricos:");
    if (tarea_completada > 0 && tarea_completada <= tareas.size()) {
        cout << "Tarea ´´"<<tareas[tarea_completada-1]<<"´´ completada correctamente."<<endl;
        tareas.erase(tareas.begin() + tarea_completada-1);
    } 
        else {
        cout << "Esa tarea no existe.\n";
    }
}
