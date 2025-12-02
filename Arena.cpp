//
// Created by ng573 on 14/11/2025.
//

#include "Arena.h"

Arena::Arena() {
    turnoActual = 1;
    inventario = new Inventario();
}

Arena::~Arena() {
    delete inventario;
}

void Arena::agregarHeroe(Personaje* h) {
    heroes.push_back(h);
}

void Arena::agregarEnemigo(Personaje* e) {
    enemigos.push_back(e);
}

void Arena::iniciarCombate() {
    if (enemigos.empty()) {
        std::cout <<"No hay enemigos para combatir\n" << std::endl;
        return;
    }
    if (heroes.empty()) {
        std::cout <<"No hay heroes para combatir\n" << std::endl;
        return;
    }
    turnoActual = 1;
    std::cout << "Inicio de combate\n" << std::endl;
    std::cout << "==== HEROES ====\n" << std::endl;
    for (int i = 0; i < heroes.size(); i++) {
        heroes[i]->mostrarInfo();
    }

    std::cout << "\n==== ENEMIGOS ====" << std::endl;
    for (int i = 0; i < enemigos.size(); i++) {
        enemigos[i]->mostrarInfo();
    }
    std::cout << "\nEl combate comienza ahora!\n" << std::endl;
}

void Arena::ejecutarTurno() {
    int accion = seleccionarAccion();
    if (accion != -1)
        resolverAccion(accion);

    turnoActual++;
}

int Arena::seleccionarAccion() {
	// Si el turno es par → turno del enemigo (control automático)
    if (turnoActual % 2 == 0) {
        std::cout << "\n--- Turno del Enemigo ---\n";
        // Buscar el primer enemigo vivo
        Personaje* enemigo = nullptr;
        for (Personaje* e : enemigos) {
            if (e->estaVivo()) {
                enemigo = e;
                break;
            }
        }
        // Si no hay enemigos vivos, error controlado
        if (enemigo == nullptr) {
            std::cout << "No hay enemigos vivos.\n";
            return -1; // código especial
        }
        // Decisión aleatoria del enemigo
        int decision = rand() % 100;   // número entre 0 y 99
        if (decision < 80) {
            std::cout << "El enemigo decidio atacar\n";
            return 1; // 1 = atacar
        }
        else {
            std::cout << "El enemigo decidio usar objeto\n";
            return 2; // 2 = usar objeto
        }
    }
    else {
        std::cout << "\n--- Turno del Heroe ---\n";
        // Buscar el primer héroe vivo
        Personaje* heroe = nullptr;
        for (Personaje* h : heroes) {
            if (h->estaVivo()) {
                heroe = h;
                break;
            }
        }
        if (heroe == nullptr) {
            std::cout << "No hay heroes vivos.\n";
            return -1;
        }
        int opcion = 0;
        std::cout << " ¿Qué deseas hacer?\n";
        std::cout << " 1. Atacar\n";
        std::cout << " 2. Usar objeto\n";
        std::cout << " Opcion: ";
        std::cin >> opcion;
        if (opcion != 1 && opcion != 2) {
            std::cout << "Opcion invalida\n";
            return 1;
        }
        return opcion;
    }
}

void Arena::resolverAccion(int accion) {
    if (turnoActual % 2 == 0) {   // ENEMIGO
        Personaje* enemigo = obtenerPrimerEnemigoVivo();
        Personaje* heroe = obtenerPrimerHeroeVivo();

        if (accion == 1) {
            enemigo->realizarAccion(heroe);
        }
        if (accion == 2) {
            enemigo->usarObjeto();
        }
    }
    else {                        // HÉROE
        Personaje* heroe = obtenerPrimerHeroeVivo();
        Personaje* enemigo = obtenerPrimerEnemigoVivo();

        if (accion == 1) {
            heroe->realizarAccion(enemigo);
        }
        if (accion == 2) {
            heroe->usarObjeto();
        }
    }
}

void Personaje::realizarAccion(Personaje* objetivo) {
    objetivo->recibirDanio(this->ataque);
    std::cout << nombre << " ataco a " << objetivo->getNombre() << " causando daño.\n";
}

void Arena::distribuirObjetosPreparacion() {
    std::cout << "Preparando objetos...\n";
    inventario->agregarObjeto(new PocionVida());
    inventario->agregarObjeto(new AmuletoFuria());
    inventario->agregarObjeto(new EscudoBendito());
    inventario->agregarObjeto(new GemaDeRayo());
    inventario->agregarObjeto(new OrbeDeKripto());
    inventario->agregarObjeto(new FrascoDeSalamanda());
    std::cout << "Objetos agregados al inventario.\n";
}

void Arena::asignarObjetoAHeroe() {
    if (heroes.empty()) {
        std::cout << "No hay heroes disponibles.\n";
        return;
    }

    Personaje* h = nullptr;
    for (Personaje* heroe : heroes) {
        if (heroe->estaVivo()) {
            h = heroe;
            break;
        }
    }

    if (h == nullptr) {
        std::cout << "No hay heroes vivos.\n";
        return;
    }

    ObjetoMagico* obj = inventario->consumirObjeto();

    if (obj == nullptr) {
        std::cout << "No hay objetos para asignar.\n";
        return;
    }

    h->asignarObjeto(obj);
    std::cout << "Objeto asignado al heroe.\n";
}

bool Arena::verificarFin() {
    bool hayHeroeVivo = false;
    bool hayEnemigoVivo = false;

    for (Personaje* h : heroes) {
        if (h->estaVivo())
            hayHeroeVivo = true;
    }

    for (Personaje* e : enemigos) {
        if (e->estaVivo())
            hayEnemigoVivo = true;
    }

    return (!hayHeroeVivo || !hayEnemigoVivo);
}

void Arena::declararGanador() {
    bool hayHeroeVivo = false;
    bool hayEnemigoVivo = false;

    for (Personaje* h : heroes)
        if (h->estaVivo()) hayHeroeVivo = true;

    for (Personaje* e : enemigos) {
        if (e->estaVivo()) {
            hayEnemigoVivo = true;
        }
    }
    std::cout << "\n=== FIN DEL COMBATE ===\n";

    if (hayHeroeVivo && !hayEnemigoVivo) {
        std::cout << "Ganador: Equipo del jugador.\n";
        std::cout << "Motivo: todos los enemigos fueron derrotados.\n";
    }
    else if (!hayHeroeVivo && hayEnemigoVivo) {
        std::cout << "Ganador: Enemigos.\n";
        std::cout << "Motivo: todos los heroes fueron derrotados.\n";
    }
    else {
        std::cout << "Empate inesperado.\n";
    }

    std::cout << "\nSupervivientes:\n";

    for (Personaje* h : heroes) {
        if (h->estaVivo()) {
            h->mostrarInfo();
        }
    }

    for (Personaje* e : enemigos)
        if (e->estaVivo()) {
            e->mostrarInfo();
        }
}

Personaje* Arena::obtenerPrimerHeroeVivo() {
    for (Personaje* h : heroes) {
        if (h->estaVivo()) return h;
    }
    return nullptr;
}

Personaje* Arena::obtenerPrimerEnemigoVivo() {
    for (Personaje* e : enemigos) {
        if (e->estaVivo()) return e;
    }
    return nullptr;
}
