//
// Created by ng573 on 14/11/2025.
//

#include "ObjetoMagico.h"

ObjetoMagico::ObjetoMagico() : nombre(), descripcion(), usado() {

}

ObjetoMagico::ObjetoMagico(string nombre, string descripcion, bool usado) {
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->usado = usado;
}

ObjetoMagico::~ObjetoMagico() {

}
