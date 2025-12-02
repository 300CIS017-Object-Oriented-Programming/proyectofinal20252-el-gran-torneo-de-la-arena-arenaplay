//
// Created by ng573 on 30/11/2025.
//

#ifndef PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_ARENAPLAY_AMULETOFURIA_H
#define PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_ARENAPLAY_AMULETOFURIA_H

#include <iostream>
#include "ObjetoMagico.h"
#include "Personaje.h"

class Amuletofuria : public ObjetoMagico {
public:
    AmuketoFuria();
    ~AmuletoFuria();
    void activarEfecto(Personaje* personaje);

};

#endif //PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_ARENAPLAY_AMULETOFURIA_H