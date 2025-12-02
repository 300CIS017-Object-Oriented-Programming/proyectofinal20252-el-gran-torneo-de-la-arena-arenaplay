//
// Created by ng573 on 30/11/2025.
//

#include "EscudoBendito.h"

EscudoBendito::EscudoBendito() : ObjetoMagico("Poción de Vida", "Restaura entre 20 y 40 puntos de vida", false){

}

EscudoBendito::~EscudoBendito() {

}

void EscudoBendito::activarEfecto(Personaje* personaje) {
    if (usado == true) {
        std::cout << "Este objeto ya fue usado" << std::endl;
        return;
    }
    int valorMinimo = 15;
    int valorMaximo = 30;
    int rango = valorMaximo - valorMinimo + 1;
    int cantidad = (rand() % rango) + valorMinimo;
    personaje->aumentarDefensa(cantidad);
    usado = true
    std::cout << "La posion aumento" << cantidad << " puntos de defensa" << std::endl;
}
