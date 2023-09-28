#include "vectores.h"

vectores::vectores(int n){ // llo que esta en () son paramentros son valores de entrada para desarollar la tarea
    this ->n=n; // this hace refereinia a el objeto actual , en este caso es en n rojo y se la asigna el valor n en azul osea la variable local
    ar = new int [n]; // new es para reservar memoria  el new reserva memeria de el heap
}

void vectores::pideDatos(){
    for (int i=0; i < n; ++i){
        cout << "Vector["<<i<<"]=";
        cin >> *(ar+i);
    }
}

void vectores::imprimir(){
    for (int i=0; i < n; ++i){
        cout <<"[ "<<i <<" ] , "<< "Direccion = "<<ar<<" ,  Con el Valor = "<<"[ "<<*(ar+i)<<" ] "<<endl;
    }
    //    for (int i=0; i < n; ++i){
    //        cout << *(ar+(i)); // El nombre de al areglo siempre me guaradar el primer valor guardado
    //    }
}

string vectores::buscarSec(int ele){
    for (int i=0; i < n; ++i)
        if  (*(ar+i)==ele)
            return " si esta con la posicion :   "+ to_string(i)  ;
    return "No esta estas mensito :) ";
}
int vectores::buscarSecRec(int pos , int ele){
    if (pos>=n) return -1;
    if (*(ar+pos)==ele) return pos;
    return buscarSecRec(pos+1,ele);
}

void vectores::burbuja(){
    for (int i=0 ; i < n-1; ++i)
        for(int j = i+1; j < n; ++j)
            if (*(ar+i)>*(ar+j)){
                int temp=*(ar+i);
                *(ar+i)=*(ar+j);
                *(ar+j)=temp;
            }
}

string vectores::busquedaBin(int ele){
    int li=0;
    int ls=n-1;
    int pos=0;
    while (li <= ls){
        cout << "esto es pos "+to_string(pos)+" esto es ls "+to_string(ls)+" esto es li "+to_string(li)+" esto es ele "+to_string(ele)<<endl;
        pos = ((ls+li)/2);//i falta if si es menor o mayor
        if (*(ar+pos)==ele)
            return "El elemento : "+to_string(ele)+" esta en la pos "+to_string(pos);
        if (ele>*(ar+pos)) li=pos-1;
        else ls=pos-1;
    }
    return "No se encuentra el elemento "+to_string(ele);
}

string vectores::busquedaBinRec(int li, int ls, int ele){
    if(li>ls) return to_string(-1); // caso base cual es necesario siempre en la recusividad
    int med= (ls+li)/2;  // *(ar) = la direcion del primer elemento
    if (*(ar+med)==ele) return to_string(med); // return es para decir que ya sa acabo el metodo
    if (*(ar+med)<ele) return busquedaBinRec(med+1,ls,ele);
    return busquedaBinRec(li,med-1,ele);
}
void vectores::quickSort(){
    quickRec(0,n-1); // manda a llamar el metodo qucik rec  y le manda argumentos
} // arguemnto = valor que se le manda a el metodo
// parametros = y el parametro es el que recibe valores
void vectores::quickRec(int li, int ls){
    if (li>=ls) return;
    int pos=posPivote(li,ls); // crea una varialbe con la posision de el metodo
    quickRec(li,pos-1);
    quickRec(pos+1,ls);
}
int vectores::posPivote(int li, int ls){
    int piv = *(ar+ls); // se le asigna el valor a el pivote ; ejemplo : *(ar) = 0 y ls es 5 entonces piv = 5
    int i = li-1;
    for (int j = li; j < ls; ++j) {
        //checar
        if (*(ar+j)<piv){ // *(ar+j) esto es igual a 0+0 por lo tanto estamos en la pos 0 cual tiene como contenido 5
            //intercambiar
            i++;
            if (i<j)
                swap(*(ar+i),*(ar+j)); // estos son valores no posisiones
        }
    }
    // intercambiar ar+i+1 con el limite superior
    swap(*(ar+i+1),*(ar+ls));
    return i+1;
}


//void vectores::newQuick(){

//}

void vectores::insercion(){
    for (int i = 1; i < n; ++i) {
        cout <<"\n=====================\n"<<endl;
        cout << *(ar+i) << " esto es ar+i"<<endl;  //representa la posición en el arreglo completo
        int valorActual = *(ar+i); // esto es contenido es la derecha
        cout << "valorActual : "<<valorActual<<endl;
        int j = i-1;
        cout <<"pos a cambiar : "<<j<<endl;
        while (*(ar+j)> valorActual && j>=0) {  // ar+j es el contenido de la izq
            *(ar+j+1)=*(ar+j);
            j--;
        }
        *(ar+j+1)= valorActual; // no esto no es ar+i-1
    }
    return;
}
void vectores::insercion2(){
    // primera divicion
    int brinco = n/2; // la distancia entre los elementos que se están comparando este debara ser estatico por eso lo sacamos de los ciclos y lo iniciamos partiendo
    while (brinco > 0) { //cantidad de veces que realizamos
        for (int i = brinco; i < n; ++i) { //  i seria nuesto indice para recorrer el array
             cout <<"\n=====================\n"<<endl;
            int valorActual = *(ar+i); // y este checcaria el contenido de cada elemento de el index de el array
             cout << "valorActual : "<<valorActual<<endl;
            int j = i-brinco; // Comienza en la posición anterior de la primera sección
            cout <<"esto es j = index :"<<j<<endl;
            while (*(ar+j)> valorActual && j>=0) { // Mientras  el elemento a la izquierda sea mayor y estemos dentro de la sección
                *(ar+j+brinco)=*(ar+j);// Desplaza los elementos hacia la derecha
                j =j-brinco; // vamos a recorer hacia atras por eso el menos cuantos pasos tenga el brinco
            }
            *(ar+j+brinco)= valorActual; // Coloca el valor actual en la posición correcta en la primera sección
        }
        brinco = brinco/ 2; // Dividir el paso por 2 en cada iteración
        // segunda divicion
    }
}

