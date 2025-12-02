//
// Created by ng573 on 1/12/2025.
//

#include "GemaDeRayo.h"
#include <cstdlib>

GemaTrueno::GemaDeRayo()
    : ObjetoMagico("Gema de RAyo", "Incrementa ataque y puede electrocutar al enemigo", false) {}

GemaDeRayo::~GemaDeRayo() {}

void GemaDeRayo::activarEfecto(Personaje* personaje) {
    if (usado) {
        std::cout << "Este objeto ya fue usado.\n";
        return;
    }

    int aumento = (rand() % 11) + 5; // 5–15
    personaje->aumentarAtaque(aumento);

    std::cout << "La Gema de Rayo aumenta el ataque en "
              << aumento << " puntos.\n";

    int prob = rand() % 100;
    if (prob < 20) {
        std::cout << "La gema libera un rayo eléctrico causando 10 de daño adicional!\n";
    }

    usado = true;
}
