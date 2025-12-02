//
// Created by ng573 on 14/11/2025.
//

#include "Sanador.h"
#include <iostream>

#include <iostream>
#include <vector>
#include <string>
#include "Sanador.h"

Sanador::Sanador() : Personaje("", 1, 100, 10, 5, "Sanador") {

}

Sanador::Sanador(string nombre, int nivel, int vida, int ataque, int defensa, string rol) : Personaje(nombre, nivel, vida, ataque, defensa, rol) {

}

Sanador::~Sanador() {

}

void Sanador::realizarAccion(Personaje* aliado) override {
    aliado->aumentarVida(20);
    std::cout << nombre << " ha curado a " << aliado->getNombre() << "!\n";
}
