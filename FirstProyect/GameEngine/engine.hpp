//
//  engine.hpp
//  FirstProyect
//
//  Created by Mary Palt on 8/09/24.
//

#ifndef engine_hpp
#define engine_hpp

#include <string>
#include "sdl.hpp"

class GameEngine {
public:
    GameEngine();
    virtual ~GameEngine();
    
    /** Initialize all required members for the engine.
     
     @returns
     True if the initialization goes smoothly, false otherwise.
     */
    virtual bool init(const std::string title="Tutorial", int width=800, int height=600);
    
    /** Clean up all memory claimed by the engine.
     */
    virtual void clear();
    
    /** The game loop where we handle events, rendering and update.
     */
    virtual void loop();
    
    /** Handle events in game loop.
     */
    virtual void handleEvent(SDL_Event &event);
    
    /** Render in game loop.
     */
    virtual void render() {}
    
    /** Update in game loop.
     */
    virtual void update() {}
    
public:
    bool success;
    bool quit;
    char errMsg[1024];
    
    SDL_Window *window;
    SDL_Renderer *renderer;
    
    int width, height;
};

#endif /* engine_hpp */
