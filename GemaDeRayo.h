//
// Created by ng573 on 1/12/2025.
//

#ifndef PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_ARENAPLAY_GEMADERAYO_H
#define PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_ARENAPLAY_GEMADERAYO_H

#include "ObjetoMagico.h"
#include <iostream>

class GemaTrueno : public ObjetoMagico {
public:
    GemaTrueno();
    ~GemaTrueno();
    void activarEfecto(Personaje* personaje) override;
};

#endif //PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_ARENAPLAY_GEMADERAYO_H