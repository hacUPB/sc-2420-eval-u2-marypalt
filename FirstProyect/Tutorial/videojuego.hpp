// videojuego.hpp
#ifndef VIDEOJUEGO_HPP
#define VIDEOJUEGO_HPP

#include "engine.hpp"
#include <vector>

struct Block {
    int x, y, width, height;
};

class Videojuego : public GameEngine {
public:
    Videojuego();
    virtual void render() override;
    virtual void update() override;
    virtual void handleEvent(SDL_Event &event) override;
    virtual void draw();

private:
    int playerX, playerY;       // Posición del jugador
    int playerSpeed;            // Velocidad del jugador
    int playerWidth, playerHeight;

    std::vector<Block> blocks;  // Lista de bloques
    int blockSpeed;             // Velocidad de los bloques
    int spawnTimer;             // Temporizador para crear nuevos bloques
    bool checkCollision(const Block &block); // Función para detectar colisión
};

#endif /* VIDEOJUEGO_HPP */
