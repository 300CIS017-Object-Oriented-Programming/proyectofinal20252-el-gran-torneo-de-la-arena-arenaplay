//
// Created by ng573 on 14/11/2025.
//

#include "Personaje.h"

Mago::Mago() : Personaje("", 1, 100, 10, 5, "Mago") {

}

Mago::Mago(string nombre, int nivel, int vida, int ataque, int defensa, string rol) : Personaje(nombre, nivel, vida, ataque, defensa, rol) {

}

Mago::~Mago() {

}

void Mago::realizarAccion(Personaje* enemigo) override {
    enemigo->recibirDanio(ataque + 5);
    std::cout << nombre << " lanza un hechizo a " << enemigo->getNombre() << "!\n";
}
