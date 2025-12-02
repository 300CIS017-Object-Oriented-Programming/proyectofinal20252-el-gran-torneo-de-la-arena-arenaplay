//
// Created by ng573 on 1/12/2025.
//

#ifndef PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_ARENAPLAY_FRASCODESALAMANDRA_H
#define PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_ARENAPLAY_FRASCODESALAMANDRA_H

#include "ObjetoMagico.h"
#include <iostream>

class FrascoDeSalamandra : public ObjetoMagico {
public:
    FrascoDeSalamandra();
    ~FrascoDeSalamandra();
    void activarEfecto(Personaje* personaje) override;
};

#endif //PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_ARENAPLAY_FRASCODESALAMANDRA_H

