// ejercicio5.cpp
#include "ejercicio5.hpp"

void Ejercicio5::render() {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, SDL_ALPHA_OPAQUE);
    SDL_RenderSetViewport(renderer, nullptr);
    SDL_RenderClear(renderer);

    draw();

    SDL_RenderPresent(renderer);
}

void Ejercicio5::draw() {
    // Dibujar rectángulo rojo con cambio de color y rotación
    SDL_SetRenderDrawColor(renderer, redColorR, redColorG, redColorB, SDL_ALPHA_OPAQUE);
    SDL_Rect rect = {redRectX, redRectY, redRectWidth, redRectHeight};
    SDL_RenderDrawRect(renderer, &rect);

    // Dibujar rectángulo azul lleno con cambio de tamaño y rotación
    SDL_SetRenderDrawColor(renderer, blueColorR, blueColorG, blueColorB, SDL_ALPHA_OPAQUE);
    rect = {blueRectX, blueRectY, blueRectWidth, blueRectHeight};
    SDL_RenderFillRect(renderer, &rect);
}

void Ejercicio5::update() {
    // Actualizar la posición del rectángulo rojo
    redRectX += redRectSpeedX;
    redRectY += redRectSpeedY;

    // Cambiar dirección si alcanza los límites
    if (redRectX <= 0 || redRectX + redRectWidth >= width) redRectSpeedX = -redRectSpeedX;
    if (redRectY <= 0 || redRectY + redRectHeight >= height) redRectSpeedY = -redRectSpeedY;

    // Actualizar la posición del rectángulo azul
    blueRectX += blueRectSpeedX;
    blueRectY += blueRectSpeedY;

    // Cambiar dirección si alcanza los límites
    if (blueRectX <= 0 || blueRectX + blueRectWidth >= width) blueRectSpeedX = -blueRectSpeedX;
    if (blueRectY <= 0 || blueRectY + blueRectHeight >= height) blueRectSpeedY = -blueRectSpeedY;

    // Actualizar el tamaño de las figuras
    redRectWidth += sizeChangeRate;
    redRectHeight += sizeChangeRate;
    blueRectWidth += sizeChangeRate;
    blueRectHeight += sizeChangeRate;

    // Cambiar la dirección de cambio de tamaño si se alcanza un límite
    if (redRectWidth > 150 || redRectWidth < 50) sizeChangeRate = -sizeChangeRate;

    // Actualizar el color de las figuras
    redColorR = (redColorR + colorChangeRate) % 256;
    blueColorB = (blueColorB + colorChangeRate) % 256;

    // Actualizar el ángulo de rotación
    rotationAngle += rotationSpeed;
    if (rotationAngle >= 360.0) rotationAngle -= 360.0;
}
