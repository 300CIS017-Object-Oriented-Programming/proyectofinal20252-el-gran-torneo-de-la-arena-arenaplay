//
// Created by ng573 on 30/11/2025.
//

#include "AmuletoFuria.h"

AmuletoFuria::AmuletoFuria() : ObjetoMagico("Amuleto de Furia", "Auemnta entre 10 y 20 puntos de ataque", false){

}

AmuletoFuria::~AmuletoFuria() {

}

void AmuletoFuria::activarEfecto(Personaje* personaje) {
    if (usado == true) {
        std::cout << "Este objeto ya fue usado" << std::endl;
        return;
    }
    int valorMinimo = 10;
    int valorMaximo = 20;
    int rango = valorMaximo - valorMinimo + 1;
    int cantidad = (rand() % rango) + valorMinimo;
    personaje->aumentarAtaque(cantidad);
    usado = true
    std::cout << "La posion aumento" << cantidad << " puntos de ataque" << std::endl;
}