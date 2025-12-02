//
// Created by ng573 on 14/11/2025.
//

#ifndef PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_ARENAPLAY_OBJETOMAGICO_H
#define PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_ARENAPLAY_OBJETOMAGICO_H

#include <iostream>

class ObjetoMagico {
private:
    string nombre;
    string descripcion;
    bool usado;

public:
    ObjetoMagico();
    ~ObjetoMagico();
    ObjetoMagico(string name,string descr, bool use);
    virtual void activarEfecto(Personaje* objetivo) = 0;
};

#endif //PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_ARENAPLAY_OBJETOMAGICO_H