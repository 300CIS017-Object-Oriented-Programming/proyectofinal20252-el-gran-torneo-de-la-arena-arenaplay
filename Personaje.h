//
// Created by ng573 on 20/11/2025.
//

#ifndef PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_ARENAPLAY_PERSONAJE_H
#define PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_ARENAPLAY_PERSONAJE_H

#include <iostream>
#include <string>
#include <vector>
#include "ObjetoMagico.h"


class Personaje {
private:
    string nombre;
    int nivel;
    int vida;
    int ataque;
    int defensa;
    string rol;
    std::vector<ObjetoMagico*> objetosMagicos;

public:
    Personaje();
    Personaje(string nombre, int nivel, int vida, int ataque, int defensa, string rol);
    virtual ~Personaje();
    virtual void realizarAccion(Personaje* objetivo) = 0;
    void recibirDanio(int cantidad);
    bool estaVivo();
    void asignarObjeto(ObjetoMagico* objeto);
    void usarObjeto();
    void mostrarInfo() const;
    void aumentarVida(int cantidad)
    void aumentarAtaque(int cantidad)
    void aumentarDefensa(int cantidad)
    string getNombre();
    void setNombre(string n);
};

#endif //PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_ARENAPLAY_PERSONAJE_H