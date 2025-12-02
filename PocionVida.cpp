//
// Created by ng573 on 30/11/2025.
//

#include "PocionVida.h"

PocionVida::PocionVida() : ObjetoMagico("Poción de Vida", "Restaura entre 20 y 40 puntos de vida", false){

}

PocionVida::~PocionVida() {

}

void PocionVida::activarEfecto(Personaje* personaje) {
    if (usado == true) {
        std::cout << "Este objeto ya fue usado" << std::endl;
        return;
    }
    int valorMinimo = 20;
    int valorMaximo = 40;

    int rango = valorMaximo - valorMinimo + 1;
    int cantidad = (rand() % rango) + valorMinimo;
    personaje->aumentarVida(cantidad);
    usado = true
    std::cout << "La posion restauro" << cantidad << " puntos de vida" << std::endl;
}
