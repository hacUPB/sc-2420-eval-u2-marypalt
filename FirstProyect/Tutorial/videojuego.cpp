// videojuego.cpp
#include "videojuego.hpp"
#include "sdl.hpp" 
#include <cstdlib>
#include <ctime>

// Constantes para el control de FPS
const int FPS = 60;
const int FRAME_DELAY = 1000 / FPS;

Videojuego::Videojuego()
    : playerX(100), playerY(250), playerSpeed(10), playerWidth(50), playerHeight(50),
      blockSpeed(5), spawnTimer(0) {
    std::srand(static_cast<unsigned>(std::time(nullptr))); // Inicializa el generador de números aleatorios
}

void Videojuego::render() {
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE); // Fondo negro
    SDL_RenderClear(renderer);

    draw();

    SDL_RenderPresent(renderer);
}

void Videojuego::update() {
    // Control de tiempo para asegurar que se respeten los FPS
    Uint32 frameStart = SDL_GetTicks(); // Inicia el contador de tiempo

    // Actualiza la posición de cada bloque
    for (auto &block : blocks) {
        block.x -= blockSpeed;
    }

    // Elimina bloques que salen de la pantalla
    blocks.erase(
        std::remove_if(blocks.begin(), blocks.end(), [](const Block &block) {
            return block.x + block.width < 0;
        }),
        blocks.end()
    );

    // Genera nuevos bloques a intervalos regulares
    spawnTimer++;
    if (spawnTimer > 60) { // Ajustar el temporizador para mayor o menor frecuencia
        Block newBlock = {800, std::rand() % (550 - 50) + 25, 50, 50}; // Crear un bloque en una posición aleatoria
        blocks.push_back(newBlock);
        spawnTimer = 0;
    }

    // Verifica colisiones entre el jugador y los bloques
    for (const auto &block : blocks) {
        if (checkCollision(block)) {
            quit = true; // Termina el juego en caso de colisión
        }
    }

    // Control del tiempo para limitar la velocidad del juego a los FPS deseados
    Uint32 frameTime = SDL_GetTicks() - frameStart;
    if (FRAME_DELAY > frameTime) {
        SDL_Delay(FRAME_DELAY - frameTime);
    }
}

void Videojuego::handleEvent(SDL_Event &event) {
    if (event.type == SDL_QUIT) {
        quit = true;
    } else if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_UP:
                playerY -= playerSpeed; // Mueve el jugador hacia arriba
                if (playerY < 0) playerY = 0; // Limita el movimiento superior
                break;
            case SDLK_DOWN:
                playerY += playerSpeed; // Mueve el jugador hacia abajo
                if (playerY + playerHeight > height) playerY = height - playerHeight; // Limita el movimiento inferior
                break;
            default:
                break;
        }
    }
}

void Videojuego::draw() {
    // Dibuja al jugador
    SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, SDL_ALPHA_OPAQUE); // Jugador verde
    SDL_Rect playerRect = {playerX, playerY, playerWidth, playerHeight};
    SDL_RenderFillRect(renderer, &playerRect);

    // Dibuja los bloques
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, SDL_ALPHA_OPAQUE); // Bloques rojos
    for (const auto &block : blocks) {
        SDL_Rect blockRect = {block.x, block.y, block.width, block.height};
        SDL_RenderFillRect(renderer, &blockRect);
    }
}

bool Videojuego::checkCollision(const Block &block) {
    // Detección de colisión entre el jugador y un bloque
    return !(playerX + playerWidth < block.x ||
             playerX > block.x + block.width ||
             playerY + playerHeight < block.y ||
             playerY > block.y + block.height);
}
