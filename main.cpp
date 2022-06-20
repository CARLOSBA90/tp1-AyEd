//------------------------------------------------------------------------------
// Librerias
#include <windows.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <string>
//------------------------------------------------------------------------------
// Parametros de configuracion
using namespace std;
#define NOMBRE_ARCHIVO  "VentasFerreteria.Txt"
ifstream VentasAF (NOMBRE_ARCHIVO);
const int MAX_REGS = 800;
const int MAX_VENS = 100;
int cantVtas = 0;
string line = "";

struct sVendedor {
  int cod_ven;
  int cant;
  string descrip;
  double precio;
  struct {
        int dia;
        int mes;
        int anio;
      }fecha;
} rVendedor;
vector<sVendedor> vrVendedores;


//------------------------------------------------------------------------------
// Funciones
void ProcVentas(ifstream &VentasAF,vector<sVendedor> &vrVendedores,int &cantVtas);
boolean LeeUnaVta(ifstream &VentasAF,sVendedor &rVendedor);
//void ListadoCantTot(SalidaAF, vrTotales,int cantVen);
//void ListadoImpTot(SalidaAF, vrTotales,int cantVen);
//------------------------------------------------------------------------------



int main(){
    ProcVentas(VentasAF,vrVendedores,cantVtas);
  //ListadoVtasAgrupVen(SalidaAF,vrVendedores,vrTotales);
  //ListadoCantTot(SalidaAF,vrTotales,cantVen);
  //ListadoImpTot(SalidaAF,vrTotales,cantVen);
    VentasAF.close();
  //SalidaAF.close();
 
 //------------------------------------------------------------------------------

  // Pruebas de salida
  for(int i=0; i<vrVendedores.size(); i++){
          cout << "Cod_vend:  " << vrVendedores[i].cod_ven;
           cout << "- Cant:  " << vrVendedores[i].cant;
           cout << "- Descrip:  " << vrVendedores[i].descrip;
           cout << "- Precio:  " << vrVendedores[i].precio;
           cout << "- Fecha:  " << vrVendedores[i].fecha.dia << "/"<< vrVendedores[i].fecha.mes<< "/"<< vrVendedores[i].fecha.anio << endl;
  }
   cout << "ejecucion final" << endl;
  //
  return 0;
}

void ProcVentas(ifstream &VentasAF,vector<sVendedor> &vrVendedores,int  &cantVtas){

  if (VentasAF.is_open()){
     while(LeeUnaVta(VentasAF, rVendedor)){
          ++cantVtas;
         if(MAX_REGS<cantVtas){
            cout << "CANTIDAD DE REGISTROS EXCEDIDO, DEBE SER MENOR A: "<< MAX_REGS << endl;
              break;
            }
          vrVendedores.push_back(rVendedor);
   }
    
  }else{ cout << "NO SE PUDO ABRIR EL ARCHIVO"; }


}

boolean LeeUnaVta(ifstream &VentasAF,sVendedor &rVendedor){
string dato;
boolean fin = false;

/// conversion de tipos
VentasAF >> dato;
if(dato.empty()) 
{ fin = true; }
else{
  try{
      rVendedor.cod_ven = stoi(dato);

      VentasAF >> dato;
      int cantidad = 
      rVendedor.cant = stoi(dato);

      VentasAF >> dato;
      rVendedor.descrip = dato;

      VentasAF >> dato;
      rVendedor.precio = stod(dato);

      VentasAF >> dato;
      rVendedor.fecha.dia = stoi(dato);

      VentasAF >> dato;
      rVendedor.fecha.mes = stoi(dato);

      VentasAF >> dato;
      rVendedor.fecha.anio = stoi(dato);
      }
   catch (...) {
      cout << "ERROR EN LECTURA DE DATOS Y/O FORMATO INVALIDO.\n";
    }   
  }
  return !fin;
}