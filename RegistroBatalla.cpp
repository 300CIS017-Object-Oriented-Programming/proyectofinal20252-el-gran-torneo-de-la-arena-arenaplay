//
// Created by ng573 on 20/11/2025.
//

#include "RegistroBatalla.h"
#include <iostr
#include <iostream>
#include <string>
#include <vector>
#include "RegistroBatalla.h"

RegistroBatalla::RegistroBatalla() {

}

RegistroBatalla::~RegistroBatalla() {
    std::cout <<"Registro de batalla eliminado " << std::endl;
}

void RegistroBatalla::registrar(const std::string& evento) {
    eventos.push_back(evento);
    std::cout << "Se a registrado el evento " << std::endl;
}

void RegistroBatalla::mostrarRegistro() {
    if (eventos.empty()) {
        std::cout << "No hay registro de batalla\n "
        return;
    }
    for (int i = 0; i < eventos.size(); i++) {
        std::cout << eventos[i] << std::endl;
    }
}