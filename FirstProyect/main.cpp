//
//  main.cpp
//  FirstProyect
//
//  Created by Mary Palt on 1/09/24.
//

#include <iostream>

#include "Ejercicio5.hpp"

int main(int argc, const char *argv[]) {
    GameEngine *game = new Ejercicio5();

    if (!game->init("Ejercicio5", 800, 400)) {
        std::cout << game->errMsg << std::endl;
        game->clear();
        delete game;
        return 1;
    }
    
    game->loop();
    game->clear();
    
    delete game;
    return 0;
}
