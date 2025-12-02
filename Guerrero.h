//
// Created by ng573 on 14/11/2025.
//

#ifndef PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_ARENAPLAY_GUERRERO_H
#define PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_ARENAPLAY_GUERRERO_H

#include <iostream>

class Personaje;

class Guerrero : public Personaje

public:
    Guerrero();
    ~Guerrero();
    void realizarAccion() override;

};


#endif //PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_ARENAPLAY_GUERRERO_H