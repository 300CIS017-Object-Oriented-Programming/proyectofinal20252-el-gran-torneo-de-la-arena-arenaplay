//
// Created by ng573 on 1/12/2025.
//

#include "FrascoDeSalamandra.h"
#include <cstdlib>

FrascoDeSalamandra::FrascoDeSalamandra()
    : ObjetoMagico("Frasco Ígneo", "Provoca un estallido de fuego dañino", false) {}

FrascoDeSalamandra::~FrascoDeSalamandra() {}

void FrascoDeSalamandra::activarEfecto(Personaje* personaje) {
    if (usado) {
        std::cout << "Este objeto ya fue usado.\n";
        return;
    }
    int danio = (rand() % 11) + 15; // 15–25
    std::cout << "El Frasco de Salamandra estalla causando " << danio << " puntos de daño.\n";
    int prob = rand() % 100;
    if (prob < 30) {
        std::cout << "¡El objetivo se quema! Recibe 5 puntos extra de daño.\n";
    }
    usado = true;
}
