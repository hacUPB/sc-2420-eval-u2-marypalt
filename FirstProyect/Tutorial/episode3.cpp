//
//  episode3.cpp
//  FirstProyect
//
//  Created by Mary Palt on 8/09/24.
//

#include "episode3.hpp"

void Episode3::draw() {
    Episode2::draw();
    
    SDL_RenderSetViewport(renderer, nullptr);
    
    int cellWidth = width / 4;
    int cellHeight = height / 2;
    
    // línea gruesa verde
    SDL_Rect rect = {0, height / 2, cellWidth, cellHeight};
    SDL_RenderSetViewport(renderer, &rect);
    thickLineRGBA(renderer, 50, 50, 150, 150, 10, 0x00, 0xFF, 0x00, SDL_ALPHA_OPAQUE);
    
    // circunferencia rosada
    rect.x += cellWidth;
    SDL_RenderSetViewport(renderer, &rect);
    circleRGBA(renderer, 100, 100, 50, 0xFF, 0x00, 0xFF, SDL_ALPHA_OPAQUE);
    
    // elipse relleno rosado
    rect.x += cellWidth;
    SDL_RenderSetViewport(renderer, &rect);
    filledEllipseRGBA(renderer, 100, 100, 50, 75, 0xFF, 0x00, 0xFF, SDL_ALPHA_OPAQUE);
    
    // rectángulo redondeado azul
    rect.x += cellWidth;
    SDL_RenderSetViewport(renderer, &rect);
    roundedRectangleRGBA(renderer, 50, 50, 150, 175, 10, 0x00, 0x00, 0xFF, SDL_ALPHA_OPAQUE);
}
