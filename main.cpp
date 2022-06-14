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
struct vendedor {
  string nombre;
  // otros;
};
struct fecha {
  string anio;
  string mes;
  string dia;
};

struct venta {
  int cod_ven;
  int cant;
  string descrip;
  double precio;
  struct fecha;
};

const MAX_REGS = 800;
const MAX_VENS = 100;

fstream ventasAF(NOMBRE_ARCHIVO);

int cantVtas = 0;
string line;
void ProcVentas(ifstream VentasAF,vector<vendedor> vrVendedores,int cantVtas);
//void ListadoCantTot(SalidaAF, vrTotales,int cantVen);
//void ListadoImpTot(SalidaAF, vrTotales,int cantVen);
vector<venta> vrVtas;
vector<vendedor> vrVendedores;


int main(){
//ifstream VentasAF("VentasFerreteria.txt");

cout<<"Mensaje a imprimir";

  //ProcVentas(VentasAF,vrVendedores,cantVtas);
  //ListadoVtasAgrupVen(SalidaAF,vrVendedores,vrTotales);
  //ListadoCantTot(SalidaAF,vrTotales,cantVen);
  //ListadoImpTot(SalidaAF,vrTotales,cantVen);
  //  VentasAF.close();
  //SalidaAF.close();
  return 0;
}

void ProcVentas(ifstream VentasAF,vector<vendedor> vrVendedores,int  cantVtas){

/*
LeeUnaVta(VentasAF, rVendedor), el cual lee una componente de datos del archivo y los almacena en una estructura interna. La función retorna un boolean, verdadero, si la lectura fue exitosa, caso contrario, falso.
ProcVentas(VtasAF, vrVtas, cVtas) //Carga c/u. de los datos leídos en vrVtas. Se debe invocar a la función LeeUnaVta. Devuelve la cantidad de registros leídos en cVtas.
OrdxBur(vrVtas, card); // Ord. x código de vendedor creciente.
OrdxBur(vrTot, card); //Ord. x cantidad total de cada vendedor decrec.
OrdxBur(card, vrTot); //Ord. x importe total de cada vendedor decrec.
IntCmb(vrVtas[i], vrVtas[i+1]); //Debe invocarse dentro de la función OrdxBur.
IntCmb(vrTot[i], vrTot[i+1]);    //Debe invocarse dentro de la función OrdxBur.

*/

}

