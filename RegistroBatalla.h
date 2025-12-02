//
// Created by ng573 on 20/11/2025.
//

#ifndef PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_ARENAPLAY_REGISTROBATALLA_H
#define PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_ARENAPLAY_REGISTROBATALLA_H


class RegistroBatalla {
private:
    std::vector<String*> eventos;
public:
    RegistroBatalla();
    ~RegistroBatalla();
    void registrar(const string& evento);
    void mostrarRegistro();
};

#endif //PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_ARENAPLAY_REGISTROBATALLA_H