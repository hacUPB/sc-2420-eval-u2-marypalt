// ejercicio5.hpp
#ifndef ejercicio5_hpp
#define ejercicio5_hpp

#include "engine.hpp"

class Ejercicio5 : public GameEngine {
public:
    virtual void render() override;
    virtual void draw();
    virtual void update() override;

private:
    // Posiciones iniciales para los rectángulos
    int redRectX = 50, redRectY = 50;
    int blueRectX = 250, blueRectY = 50;

    // Velocidades de movimiento
    int redRectSpeedX = 2, redRectSpeedY = 1;
    int blueRectSpeedX = 1, blueRectSpeedY = 2;

    // Tamaños y sus velocidades de cambio
    int redRectWidth = 100, redRectHeight = 100;
    int blueRectWidth = 100, blueRectHeight = 100;
    int sizeChangeRate = 1;

    // Variables para el cambio de color
    int redColorR = 255, redColorG = 0, redColorB = 0;
    int blueColorR = 0, blueColorG = 0, blueColorB = 255;
    int colorChangeRate = 5;

    // Ángulo de rotación (en grados) y su velocidad de cambio
    double rotationAngle = 0.0;
    double rotationSpeed = 1.0;
};

#endif /* ejercicio5_hpp */
