//
// Created by ng573 on 14/11/2025.
//

#ifndef PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_ARENAPLAY_ARENA_H
#define PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_ARENAPLAY_ARENA_H

#include <iostream>

class Arena {
private:
    int turnoActual;
    std::vector<Personaje*> heroes;
    std::vector<Personaje*> enemigos;
    Inventario *inventario;

public:
    Arena();
    ~Arena();
    void agregarHeroe(Personaje* h);
    void agregarEnemigo(Personaje* e);
    void iniciarCombate();
    void ejecutarTurno();
    int seleccionarAccion();
    void resolverAccion(int accion);
    virtual void realizarAccion(Personaje* objetivo) = 0;
    void distribuirObjetosPreparacion();
    void asiganrObjetoAHeroe();
    bool verificarFin();
    void declararGanador();
    Personaje* obtenerPrimerHeroeVivo();
    Personaje* obtenerPrimerEnemigoVivo();

};

#endif //PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_ARENAPLAY_ARENA_H