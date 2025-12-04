#include "GameGraphics.h"
#include "AliveState.h"
#include "DeadState.h"
#include <iostream>
#include <cmath>


using namespace std;
using namespace sf;

GameGraphics::GameGraphics(Game& game, int width, int height) //Constructor
    : game(game), isPaused(true), autoPlay(true), delayBetweenSteps(2.0f) {
    
    window.create(VideoMode(width, height), "Conway’s Game of Life",Style::Titlebar | Style::Close); //Create window
    window.setFramerateLimit(30); //Limit FPS to 30

    
    int rows = game.getGrid().getRows(); //Get rows
    int cols = game.getGrid().getCols(); //Get cols
    
    float cellWidth = (float)width / cols; //Calculate cell width
    float cellHeight = (float)height / rows; //Calculate cell height
    cellSize = min(cellWidth, cellHeight);
    
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf")) {} //Load font
    
    clock.restart();
}

GameGraphics::~GameGraphics() { //Destructor
    if (window.isOpen()) {
        window.close();
    }
}

void GameGraphics::run() { //Main loop and helpers
    cout << "         Contrôles:" << endl;
    cout << "  [Space]  : Pause/Play" << endl;
    cout << "  [↑]      : Augmenter la vitesse" << endl;            //help message
    cout << "  [↓]      : Diminuer la vitesse" << endl;
    cout << "  [→]      : Avancer d'une génération (manuel)" << endl;
    cout << "  [R]      : Reset" << endl;
    cout << "  [Échap]  : Quitter" << endl;
    
    while (window.isOpen()) { //Main loop
        handleEvents();          
        update();
        draw();
    }
}

void GameGraphics::handleEvents() { //Event handler
    Event event;
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed) {
            window.close();
        }
        
        if (event.type == Event::KeyPressed) {
            switch (event.key.code) {
                case Keyboard::Escape: // Case Escape 
                    window.close();
                    break;
                    
                case Keyboard::Space: // Case Space
                    togglePause();
                    break;
                    
                case Keyboard::R: // Case R
                    game.reset();
                    break;
                    
                case Keyboard::Right: // Case Right Arrow
                    game.step();
                    break;
                    
                case Keyboard::Up: // Case Up Arrow
                    setSpeed(delayBetweenSteps - 0.2f);
                    break;
                    
                case Keyboard::Down: // Case Down Arrow
                    setSpeed(delayBetweenSteps + 0.2f);
                    break;
                    
                default:
                    break;
            }
        }
    }
}

void GameGraphics::update() { //Method to update the game state
    if (isPaused) {
        return;
    }
    
    Time elapsed = clock.getElapsedTime();
    
    if (elapsed.asSeconds() >= delayBetweenSteps) { //Time to step
        game.step(); //Advance one generation
        clock.restart(); //Restart clock
    }
}

void GameGraphics::draw() { //Method to draw the game state
    window.clear(Color(240, 240, 240)); 
    
    drawGrid(); //Draw the grid
    drawUI(); //Draw the UI
    
    window.display(); 
}


void GameGraphics::drawGrid() {//Method to draw the grid
    Grid& grid = game.getGrid();
    
    for (int i = 0; i < grid.getRows(); i++) {
        for (int j = 0; j < grid.getCols(); j++) {
            RectangleShape cell(Vector2f(cellSize, cellSize));
            cell.setPosition(j * cellSize, i * cellSize+140);
            
            if (grid.getCell(i, j).isAlive()) {
                cell.setFillColor(Color(20, 20, 20)); // Dark color for alive cells
            } else {
                cell.setFillColor(Color(250, 250, 250)); // White color for dead cells
            }
            
            cell.setOutlineColor(Color(200, 200, 200));
            cell.setOutlineThickness(1);
            
            window.draw(cell);
        }
    }
}

void GameGraphics::drawUI() { //Method to draw the UI
    RectangleShape background(Vector2f(window.getSize().x, 120));
    background.setPosition(0, 0);                                   // Background rectangle of the GUI
    background.setFillColor(Color(240,240,240));
    window.draw(background);
    
    Text genText;
    genText.setFont(font);
    genText.setString("Generation: " + to_string(game.getIteration()));
    genText.setCharacterSize(24);
    genText.setFillColor(Color::Black);                             // Number of generation text
    genText.setStyle(Text::Bold);
    genText.setPosition(10, 10);
    window.draw(genText);
    
    Text speedText;
    speedText.setFont(font);
    speedText.setString("Vitesse: " + to_string(delayBetweenSteps).substr(0, 4) + "s/gen");
    speedText.setCharacterSize(20);
    speedText.setFillColor(Color(50, 50, 50));                      // Speed text
    speedText.setPosition(10, 45);
    window.draw(speedText);
    
    Text stateText;
    stateText.setFont(font);
    if (isPaused) {
        stateText.setString("PAUSE");
        stateText.setFillColor(Color(200, 0, 0));                    // Pause/Play state text
    } else {
        stateText.setString("EN COURS");
        stateText.setFillColor(Color(0, 150, 0));
    }
    stateText.setCharacterSize(20);
    stateText.setStyle(Text::Bold);                                  
    stateText.setPosition(10, 80);
    window.draw(stateText);
    
    int aliveCount = 0;
    Grid& grid = game.getGrid();
    for (int i = 0; i < grid.getRows(); i++) {                       // Count alive cells
        for (int j = 0; j < grid.getCols(); j++) {
            if (grid.getCell(i, j).isAlive()) {
                aliveCount++;
            }
        }
    }
    
    Text aliveText;
    aliveText.setFont(font);
    aliveText.setString("Cellules vivantes: " + to_string(aliveCount));
    aliveText.setCharacterSize(18);                                 
    aliveText.setFillColor(Color(0, 100, 200));                       // Alive cells count text
    aliveText.setPosition(10, 105);
    window.draw(aliveText);
}

void GameGraphics::setSpeed(float seconds) {
    delayBetweenSteps = seconds;
    
    if (delayBetweenSteps < 0.2f) {
        delayBetweenSteps = 0.2f;             // Minimum delay of 0.2 seconds
    }
    if (delayBetweenSteps > 2.0f) {
        delayBetweenSteps = 2.0f;             // Maximum delay of 2.0 seconds
    }
}

void GameGraphics::togglePause() {
    isPaused = !isPaused;

    if (!isPaused) {                         // If unpausing, restart the clock
        clock.restart();
    }
}