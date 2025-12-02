//
// Created by ng573 on 14/11/2025.
//

#include "Enemigo.h"

Enemigo::Enemigo() : Personaje("", 1, 100, 10, 5, "Mago") {

}

Enemigo::Enemigo(string nombre, int nivel, int vida, int ataque, int defensa, string rol) : Personaje(nombre, nivel, vida, ataque, defensa, rol) {

}

Enemigo::~Enemigo() {

}

void Enemigo::realizarAccion() {
    std::cout <<"El Enemigo ataca " << std::endl;
}