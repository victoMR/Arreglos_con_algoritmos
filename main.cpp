#include <QCoreApplication>
#include <vectores.h>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int n;
    //int ele;
    cout <<"=====================\n"<<endl;

    cout << "Cuantos elementos quieres ? ";
    cin >> n;

    cout <<"\n=====================\n"<<endl;
    vectores vec(n);

    vec.pideDatos();
    cout<<endl;
//    vec.burbuja();
//    vec.quickSort();
//    vec.insercion();
    vec.insercion2();

    cout <<"\n=====================\n"<<endl;
    vec.imprimir();
    cout <<endl;

//    cout <<"=====================\n"<<endl;

//    cout << "Elecion ? ";
//    cin >> ele;
//    cout <<endl;

//    cout <<"=====================\n"<<endl;

//    string pos= vec.busquedaBinRec(0,3,ele);
//    if(pos==to_string(-1)){
//        cout <<"No"<<endl;
//    }else{
//        cout << "Si en pos : "<<pos<<endl;
//    }

//    cout << vec.busquedaBin(ele)<<endl;

//    cout << vec.buscarSec(ele)<<endl;;
//    cout <<endl;

//    cout <<"=====================\n"<<endl;

//    int pos =vec.buscarSecRec(0,ele);
//    if (pos==-1){
//        cout << "No se encuentra"<<endl;
//    }else{
//        cout << "Se encuentra en la posicion = "<<pos<<endl;
//    }



    return a.exec();
}
