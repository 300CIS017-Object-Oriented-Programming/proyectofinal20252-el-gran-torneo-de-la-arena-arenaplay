//
// Created by ng573 on 14/11/2025.
//

#include "Inventario.h"

Inventario::Inventario() {
    std::cout <<"Inventario creado " << std::endl;
}

Inventario::~Inventario() {
    for (int i = 0; i < objetosDisponibles.size(); i++) {
        delete objetosDisponibles[i];
    }
    objetosDisponibles.clear();
    std::cout <<"Inventario borrado " << std::endl;
}

void Inventario::agregarObjeto(ObjetoMagico* objeto) {
    objetosDisponibles.push_back(objeto);
    std::cout << "Objeto magico agregado " << std::endl;
}

void Inventario::eliminarObjeto(int idc) {
    if (objetosDisponibles.empty()) {
        std::cout << "No hay objetos disponibles" << std::endl;
        return;
    }
    if (idc < 0 || idc >= objetosDisponibles.size()) {
        std::cout << "Fuera de rango " << std::endl;
        return;
    }
    delete objetosDisponibles[idc];
    objetosDisponibles.erase(objetosDisponibles.begin() + idc);
    std::cout << "Objeto magico eliminado " << std::endl;
}

void Inventario::asignarObjetoAHeroe(Personaje* heroe) {
    if (heroe == nullptr) {
        std::cout << "Personaje invalido" << std::endl;
        return;
    }
    if (objetosDisponibles.empty()) {
        std::cout << "No hay objetos disponibles" << std::endl;
        return;
    }
    ObjetoMagico* obj = objetosDisponibles[0];
    heroe->asignarObjeto(obj);
    objetosDisponibles.erase(objetosDisponibles.begin());
    std::cout <<"Objeto magico asigando al personaje " << std::endl;
}

void Inventario::retirarObjetoAHeroe(Personaje* heroe) {

}

ObjetoMagico* Inventario::consumirObjeto() {
    if (objetosDisponibles.empty()) {
        std::cout << "No hay objetos disponibles" << std::endl;
        return nullptr;
    }
    ObjetoMagico* obj = objetosDisponibles[0];
    objetosDisponibles.erase(objetosDisponibles.begin());
    std::cout << "Objeto magico consumido" << std::endl;
    return obj;
}