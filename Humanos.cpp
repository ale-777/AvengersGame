#include "Humanos.h"
void Humano::generarFecha(){
    std::uniform_int_distribution<int> dist(1920, 2020);
    anno = dist(* QRandomGenerator::global());
    std::uniform_int_distribution<int> dist2(1, 12);
    mes = dist2(* QRandomGenerator::global());
    int max = 28;
    if (mes == 2){
        if((anno%4==0 && anno%100!=0) || anno%400==0){
            max = 29;
        }
    }
    std::uniform_int_distribution<int> dist3(1, max);
    anno = dist3(* QRandomGenerator::global());
}
QString Humano::generarGenero(){
    std::uniform_int_distribution<int> dist(0, 1);
    int rand = dist(* QRandomGenerator::global());
    if (rand == 1){
        return "Hombre";
    }
    return "Mujer";
}
QString Humano::generarProfresion(){
    std::uniform_int_distribution<int> dist(1, 50);
    int rand = dist(* QRandomGenerator::global());
    return planeta.profresiones[rand];
}
QString Humano::generarCreencia(){
    std::uniform_int_distribution<int> dist(1, 10);
    int rand = dist(* QRandomGenerator::global());
    return planeta.creencias[rand];
}
QString Humano::generarNombre(){
    std::uniform_int_distribution<int> dist(1, 1000);
    int rand = dist(* QRandomGenerator::global());
    return planeta.nombres[rand];
}
QString Humano::generarApellido(){
    std::uniform_int_distribution<int> dist(1, 100);
    int rand = dist(* QRandomGenerator::global());
    return planeta.apellidos[rand];
}
int Humano::generarID(){
    bool repetir = true;
    std::uniform_int_distribution<int> dist(0, 9999999);
    int rand;
    while(repetir){
        rand = dist(* QRandomGenerator::global());
        if(planeta.verificarID(rand))
            return rand;
    }
    return 0;
}
void Humano::calcularGrupo(){
    int edad = 2021-anno;
    if (edad<=1){
        grupoEtario = "Infantil";
    }
    else if(edad<=4){
        grupoEtario = "Pre-escolar";
    }
    else if(edad<=10){
        grupoEtario = "Escolar";
    }
    else if(edad<=14){
        grupoEtario = "Pubertad";
    }
    else if(edad<=19){
        grupoEtario = "Adolescencia";
    }
    else if(edad<=24){
        grupoEtario = "Joven";
    }
    else if(edad<=34){
        grupoEtario = "Adulto Joven";
    }
    else if(edad<=64){
        grupoEtario = "Adulto Maduro";
    }
    else{
        grupoEtario = "Adulto Mayor";
    }
}
QString Humano::generarPais(){
    std::uniform_int_distribution<int> dist(1, 100);
    int rand = dist(* QRandomGenerator::global());
    return planeta.paises[rand];
}
int Humano::generarCantidadE(){
    std::uniform_int_distribution<int> dist(0, 100);
    int rango;
    int rand = dist(* QRandomGenerator::global());
    if (rand<=30){
        std::uniform_int_distribution<int> dist2(0, 2);
        rango = dist(* QRandomGenerator::global());
    }
    else if(rand<=55){
        std::uniform_int_distribution<int> dist2(2, 10);
        rango = dist(* QRandomGenerator::global());
    }
    else if(rand<=75){
        std::uniform_int_distribution<int> dist2(10, 15);
        rango = dist(* QRandomGenerator::global());
    }
    else if(rand<=90){
        std::uniform_int_distribution<int> dist2(16, 25);
        rango = dist(* QRandomGenerator::global());
    }
    else{
        std::uniform_int_distribution<int> dist2(25, 100);
        rango = dist(* QRandomGenerator::global());
    }
    return rango;
}
void Humano::generarExperiencias(){
    int max = generarCantidadE();
    bool repetir;
    for(int i=0; i<max; i++){
        repetir = true;
        while(repetir){
            QString pais = generarPais();
            if(paisesVisitados.VerificarPais(pais)){
                 paisesVisitados.agregarPais(pais);
                 repetir = false;
            }
        }
    }
}
