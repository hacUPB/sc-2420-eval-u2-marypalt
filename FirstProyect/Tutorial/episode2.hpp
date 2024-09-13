// episode2.hpp
#ifndef episode2_hpp
#define episode2_hpp

#include "engine.hpp"

class Episode2 : public GameEngine {
public:
    virtual void render() override;
    virtual void draw();
    virtual void update() override; // Añadir la función update

private:
    // Posiciones iniciales para los rectángulos
    int redRectX = 50, redRectY = 50;
    int blueRectX = 250, blueRectY = 50;

    // Velocidades de movimiento
    int redRectSpeedX = 2, redRectSpeedY = 1;
    int blueRectSpeedX = 1, blueRectSpeedY = 2;
};

#endif /* episode2_hpp */
