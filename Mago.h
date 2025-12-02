//
// Created by ng573 on 14/11/2025.
//

#ifndef PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_ARENAPLAY_MAGO_H
#define PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_ARENAPLAY_MAGO_H

#include <iostream>

class Personaje;

class Mago : public Personaje {
public:
    Mago();
    ~Mago();
    void realizarAccion() override;
};


#endif //PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_ARENAPLAY_MAGO_H