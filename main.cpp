//
// Created by ng573 on 1/12/2025.
//
#include <iostream>
#include "Arena.h"
#include "Guerrero.h"
#include "Mago.h"
#include "Sanador.h"
#include "Inventario.h"

void cargarHeroesIniciales(std::vector<Personaje*>& heroes) {

    std::cout << "Cargando heroes iniciales..." << std::endl;

    heroes.push_back(new Guerrero("Arthos", 2, 120, 15, 8, "Guerrero"));
    heroes.push_back(new Mago("Lyra", 1, 80, 20, 4, "Mago"));
    heroes.push_back(new Sanador("Taren", 1, 90, 8, 6, "Sanador"));

    std::cout << "Heroes creados correctamente" << std::endl;
}

void menuHeroes(std::vector<Personaje*>& heroes) {

    int opcion = 0;

    while (opcion != 4) {

        std::cout << "\n=== GESTION DE HEROES ===" << std::endl;
        std::cout << "1. Listar heroes" << std::endl;
        std::cout << "2. Consultar un heroe" << std::endl;
        std::cout << "3. Retirar heroe" << std::endl;
        std::cout << "4. Volver" << std::endl;
        std::cout << "Opcion: ";
        std::cin >> opcion;

        switch (opcion) {

        case 1:
            std::cout << "\n--- Lista de heroes ---" << std::endl;
            for (int i = 0; i < heroes.size(); i++) {
                heroes[i]->mostrarInfo();
            }
            break;

        case 2: {
            std::cout << "Nombre del heroe: ";
            std::string nombre;
            std::cin >> nombre;

            bool encontrado = false;

            for (int i = 0; i < heroes.size(); i++) {
                if (heroes[i]->getNombre() == nombre) {
                    heroes[i]->mostrarInfo();
                    encontrado = true;
                }
            }

            if (!encontrado) {
                std::cout << "Heroe no encontrado" << std::endl;
            }

            break;
        }

        case 3: {
            std::cout << "Nombre del heroe a retirar: ";
            std::string nombre;
            std::cin >> nombre;

            bool eliminado = false;

            for (int i = 0; i < heroes.size(); i++) {
                if (heroes[i]->getNombre() == nombre) {

                    delete heroes[i];
                    heroes.erase(heroes.begin() + i);

                    std::cout << "Heroe retirado correctamente" << std::endl;
                    eliminado = true;
                    break;
                }
            }

            if (!eliminado) {
                std::cout << "No existe ese heroe" << std::endl;
            }

            break;
        }

        }
    }
}

void menuInventario(Inventario* inventario) {

    int opcion = 0;

    while (opcion != 3) {

        std::cout << "\n=== INVENTARIO GLOBAL ===" << std::endl;
        std::cout << "1. Listar objetos" << std::endl;
        std::cout << "2. Consumir objeto" << std::endl;
        std::cout << "3. Volver" << std::endl;
        std::cout << "Opcion: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            inventario->listarObjetos();
            break;

        case 2:
            inventario->consumirObjeto();
            break;
        }
    }
}

int main() {

    std::vector<Personaje*> heroes;
    std::vector<Personaje*> enemigos;

    cargarHeroesIniciales(heroes);

    Inventario* inventario = new Inventario();
    Arena arena;

    int opcion = 0;

    while (opcion != 4) {

        std::cout << "\n===== MENU PRINCIPAL =====" << std::endl;
        std::cout << "1. Gestion de Heroes" << std::endl;
        std::cout << "2. Inventario" << std::endl;
        std::cout << "3. Arena de combate" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout << "Opcion: ";
        std::cin >> opcion;

        switch (opcion) {

        case 1:
            menuHeroes(heroes);
            break;

        case 2:
            menuInventario(inventario);
            break;

        case 3:
            std::cout << "\nEntrando a la arena..." << std::endl;

            // PREPARAR HEROES PARA LA ARENA
            for (int i = 0; i < heroes.size(); i++) {
                arena.agregarHeroe(heroes[i]);
            }

            // CREAR ENEMIGOS
            enemigos.push_back(new Guerrero("Dravos", 2, 100, 12, 7, "Guerrero"));
            enemigos.push_back(new Mago("Selene", 1, 70, 18, 4, "Mago"));

            for (int i = 0; i < enemigos.size(); i++) {
                arena.agregarEnemigo(enemigos[i]);
            }

            arena.distribuirObjetosPreparacion();
            arena.iniciarCombate();

            while (!arena.verificarFin()) {
                arena.ejecutarTurno();
            }

            arena.declararGanador();

            break;
        }
    }

    return 0;
}

