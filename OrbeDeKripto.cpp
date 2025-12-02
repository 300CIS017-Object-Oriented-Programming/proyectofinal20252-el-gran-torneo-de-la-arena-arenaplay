//
// Created by ng573 on 1/12/2025.
//

#include "OrbeDeKripto.h"
#include <cstdlib>

OrbeDeKripto::OrbeDeKripto() : ObjetoMagico("Orbe de Escarcha", "Fortalece defensa y congela al enemigo", false) {

}

OrbeDeKripto::~OrbeDeKripto() {

}

void OrbeDeKripto::activarEfecto(Personaje* personaje) {
    if (usado) {
        std::cout << "Este objeto ya fue usado.\n";
        return;
    }
    int aumento = (rand() % 11) + 10; // 10–20
    personaje->aumentarDefensa(aumento);
    std::cout << "El Orbe de Kripto aumenta la defensa en " << aumento << " puntos.\n";
    std::cout << "El enemigo queda reducido y pierde -5 de defensa este turno.\n";
    usado = true;
}
