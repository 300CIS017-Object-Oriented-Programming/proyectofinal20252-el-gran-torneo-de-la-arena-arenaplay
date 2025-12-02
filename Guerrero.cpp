//
// Created by ng573 on 14/11/2025.
//
#include <iostream>
#include <vector>
#include <string>
#include "Guerrero.h"

Guerrero::Guerrero() : Personaje("", 1, 100, 10, 5, "Guerrero") {

}

Guerrero::Guerrero(string nombre, int nivel, int vida, int ataque, int defensa, string rol) : Personaje(nombre, nivel, vida, ataque, defensa, rol) {

}

Guerrero::~Guerrero() {

}

void Guerrero::realizarAccion(Personaje* enemigo) override {
    enemigo->recibirDanio(ataque + 10);
    std::cout << nombre << " golpea con su espada a " << enemigo->getNombre() << "!\n";
}

