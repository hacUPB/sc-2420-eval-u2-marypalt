//
//  episode4.hpp
//  FirstProyect
//
//  Created by Mary Palt on 9/09/24.
//

#ifndef episode4_hpp
#define episode4_hpp

#include "engine.hpp"

class Episode4: public GameEngine {
public:
    virtual bool init(const std::string title="Tutorial", int width=800, int height=600) override;
    virtual void render() override;
    virtual void handleEvent(SDL_Event &event) override;
    
private:
    int x, y;
    int rad;
    int step;
};

#endif /* episode4_hpp */
