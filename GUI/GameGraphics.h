#pragma once
#include "Game.h"
#include "AliveState.h"
#include "DeadState.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


using namespace sf;

class GameGraphics {
private:
    Game& game;
    RenderWindow window;
    float cellSize;
    Font font;
    bool isPaused;
    bool autoPlay;
    float delayBetweenSteps;
    Clock clock;
    
    // Private methods
    void handleEvents();
    void update();
    void draw();
    void drawGrid();
    void drawUI();
    
public:
    GameGraphics(Game& game, int width, int height);
    ~GameGraphics();
    void run();
    void setSpeed(float seconds);
    void togglePause();
};