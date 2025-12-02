//
// Created by ng573 on 14/11/2025.
//

#ifndef PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_ARENAPLAY_HEROE_H
#define PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_ARENAPLAY_HEROE_H

#include <iostream>

class Personaje;

class Enemigo {
public:
    Enemigo();
    ~Enemigo();
    void realizarAccion() override;
};


#endif //PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_ARENAPLAY_HEROE_H