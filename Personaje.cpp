//
// Created by ng573 on 20/11/2025.
//
#include "Personaje.h"

Personaje::Personaje() : nombre(""), nivel(1), vida(100), ataque(10), defensa(5), rol("") {

}

Personaje::Personaje(string nombre, int nivel, int vida, int ataque, int defensa, string rol) {
    this->nombre = nombre;
    this->nivel = nivel;
    this->vida = vida;
    this->ataque = ataque;
    this->defensa = defensa;
    this->rol = rol;
}

Personaje::~Personaje() {

}

void Personaje::realizarAccion() {

}

void Personaje::recibirDanio(int cantidad) {
    int danioReal;
    danioReal = cantidad - defensa;
    if (danioReal < 0) {
        danioReal = 0;
    }
    vida = vida - danioReal;
    if (vida < 0) {
        vida = 0;
    }
}

bool Personaje::estaVivo() {
    if (vida > 0) {
        return true;
    }
    else {
        return false;
    }
}

void Personaje::asignarObjeto(ObjetoMagico* objeto) {
    objetosMagicos.push_back(objeto);
    std::cout <<"Objeto asignado " << std::endl;
}

void Personaje::usarObjeto() {
    if (objetosMagicos.empty()) {
        std::cout << "No tienes objetos magicos" << std::endl;
        return;
    }

    objetosMagicos[0]->activarEfecto(this);
    objetosMagicos.erase(objetosMagicos.begin());
    std::cout <<"Objeto magico usado" << std::endl;
}

void Personaje::mostrarInfo() {
    std::cout << "Nombre: " << nombre
              << " | Rol: " << rol
              << " | Nivel: " << nivel
              << " | Vida: " << vida
              << " | Ataque: " << ataque
              << " | Defensa: " << defensa
              << std::endl;
}

void Personaje::aumentarVida(int cantidad) {
    this->vida += cantidad;
    std::cout << "El personaje gano " << cantidad << " puntos de vida" << std::endl;
}

void Personaje::aumentarAtaque(int cantidad) {
    this->ataque += cantidad;
    std::cout << "El personaje gano " << cantidad << " puntos de ataque" << std::endl;
}

void Personaje::aumentarDefensa(int cantidad){
    this->defensa += cantidad;
    std::cout << "El personaje gano " << cantidad << " puntos de defensa" << std::endl;
}

string Personaje::getNombre() {
    return nombre;
}

void Personaje::setNombre(string n) {
    nombre = n;
}
