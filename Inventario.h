    /
// Created by ng573 on 14/11/2025.
//

#ifndef PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_ARENAPLAY_INVENTARIO_H
#define PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_ARENAPLAY_INVENTARIO_H

#include "ObjetoMagico.h"
#include <vector>
#include "Personaje.h"

class Inventario {
private:
    std::vector<ObjetoMagico*> objetosDisponibles;
public:
    Inventario();
    virtual ~Inventario();
    void agregarObjeto(ObjetoMagico* objeto);
    void eliminarObjeto(int idc);
    void asignarObjetoAHeroe(Personaje* heroe);
    void retirarObjetoAHeroe(Personaje* heroe);
    ObjetoMagico* consumirObjeto();
};

#endif //PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_ARENAPLAY_INVENTARIO_H