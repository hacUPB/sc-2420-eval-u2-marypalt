// episode2.cpp
#include "episode2.hpp"

void Episode2::render() {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, SDL_ALPHA_OPAQUE);
    SDL_RenderSetViewport(renderer, nullptr);
    SDL_RenderClear(renderer);

    draw();

    SDL_RenderPresent(renderer);
}

void Episode2::draw() {
    
    // Dibujar rectángulo rojo en su nueva posición
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, SDL_ALPHA_OPAQUE);
    SDL_Rect rect = {redRectX, redRectY, 100, 100}; // Usar las variables de posición
    SDL_RenderDrawRect(renderer, &rect);

    // Dibujar rectángulo azul lleno en su nueva posición
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, SDL_ALPHA_OPAQUE);
    rect = {blueRectX, blueRectY, 100, 100}; // Usar las variables de posición
    SDL_RenderFillRect(renderer, &rect);

    // Dibujar puntos negros
    SDL_Point points[4] = {{150, 50}, {25, 75}, {120, 150}, {150, 125}};
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);
    rect = {400, 0, 200, 200};
    SDL_RenderSetViewport(renderer, &rect);
    SDL_RenderDrawPoints(renderer, points, 4);

    // Dibujar líneas negras
    rect = {600, 0, 200, 200};
    SDL_RenderSetViewport(renderer, &rect);
    SDL_RenderDrawLines(renderer, points, 4);
}

void Episode2::update() {
    // Actualizar la posición del rectángulo rojo
    redRectX += redRectSpeedX;
    redRectY += redRectSpeedY;

    // Cambiar dirección si alcanza los límites
    if (redRectX <= 0 || redRectX + 100 >= width) redRectSpeedX = -redRectSpeedX;
    if (redRectY <= 0 || redRectY + 100 >= height) redRectSpeedY = -redRectSpeedY;

    // Actualizar la posición del rectángulo azul
    blueRectX += blueRectSpeedX;
    blueRectY += blueRectSpeedY;

    // Cambiar dirección si alcanza los límites
    if (blueRectX <= 0 || blueRectX + 100 >= width) blueRectSpeedX = -blueRectSpeedX;
    if (blueRectY <= 0 || blueRectY + 100 >= height) blueRectSpeedY = -blueRectSpeedY;
}

