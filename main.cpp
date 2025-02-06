// include files
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Gameworld.h"
#include "Gameworld.cpp"
#include "Menu.h"
#include "Menu.cpp"
#include "Crop.h"
#include "Crop.cpp"
#include "Day.h"
#include "Day.cpp"
#include "Item.h"
#include "Item.cpp"
#include "Seed.h"
#include "Seed.cpp"
#include "Gardenbed.h"
#include "Gardenbed.cpp"
#include "Store.h"
#include "Store.cpp"
#include "Shovel.h"
#include "Shovel.cpp"
#include "User.h"
#include "User.cpp"
#include "Waterhole.h"
#include "Waterhole.cpp"
#include "Gametile.h"
#include "Gametile.cpp"
#include "StoreMenu.h"
#include "StoreMenu.cpp"
#include "GardenBedMenu.h"
#include "GardenBedMenu.cpp"
#include "Win.h"
#include "Win.cpp"

// use namespace
using namespace sf;

int main(){
    // initalisation of variables
    User* user = new User();
    user->SetMoney(100);
    user->SetWaterStorage(100);
    Day d1; 
    Day* nDay = &d1;
    WaterHole Waterhole(user);
    GardenBed Garden(10);
    Win* win = new Win(user);
    Store store(6);
    Seed* BeetrootSeed = new Seed(user, "Beetroot", 50, 5, 10);
    Crop* BeetrootCrop = new Crop(user, BeetrootSeed->GetNameOfItem(), BeetrootSeed->GetRewardForHarvesting(),  BeetrootSeed->GetCostOfItem(), 10, BeetrootSeed->GetTImeForHarvesting());
    Seed* CarrotSeed = new Seed(user, "Carrot", 70, 7, 15);
    Crop* CarrotCrop = new Crop(user, CarrotSeed->GetNameOfItem(), CarrotSeed->GetRewardForHarvesting(),  CarrotSeed->GetCostOfItem(), 10, CarrotSeed->GetTImeForHarvesting());
    Seed* RadishSeed = new Seed(user, "Radish", 90, 9, 20);
    Crop* RadishCrop = new Crop(user, RadishSeed->GetNameOfItem(), RadishSeed->GetRewardForHarvesting(),  RadishSeed->GetCostOfItem(), 10, RadishSeed->GetTImeForHarvesting());
    Seed* RiceSeed = new Seed(user, "Rice", 100, 10, 30);
    Crop* RiceCrop = new Crop(user, RiceSeed->GetNameOfItem(), RiceSeed->GetRewardForHarvesting(),  RiceSeed->GetCostOfItem(), 10, RiceSeed->GetTImeForHarvesting());
    store.AddItemToStore(BeetrootSeed);
    store.AddItemToStore(CarrotSeed);
    store.AddItemToStore(RadishSeed);
    store.AddItemToStore(RiceSeed);
    store.AddItemToStore(win);

    // Window and Menu Objects 
    RenderWindow window(sf::VideoMode(400, 400), "OOP Project");
    Menu gameMenu(window.getSize().x, window.getSize().y);
    StoreMenu storeMenu(800, 800, *user, *nDay);
    GardenBedMenu gardenMenu(400, 400);

    // Menu Background
    RectangleShape background;
    background.setSize(Vector2f(400,400));
    Texture backgroundTexture;
    if(!backgroundTexture.loadFromFile("Assets/FinishedFiles/Black.png")){
        std::cout << "Background text could not be loaded" << std::endl;
        return 0;
    };
    background.setTexture(&backgroundTexture); 
    
    // About Background
    RectangleShape aboutBackground;
    aboutBackground.setSize(Vector2f(400,400));
    Texture aboutBackgroundTexture;
    if(!aboutBackgroundTexture.loadFromFile("Assets/FinishedFiles/About_text.png")){
        std::cout << "About Background could not be loaded" << std::endl;
        return 0;
    };
    aboutBackground.setTexture(&aboutBackgroundTexture); 

    // Exit Background
    RectangleShape exitBackground;
    exitBackground.setSize(Vector2f(400,400));
    Texture exitBackgroundTexture;
    if(!exitBackgroundTexture.loadFromFile("Assets/FinishedFiles/Exit_text.png")){
        std::cout << "Exit Background could not be loaded" << std::endl;
        return 0;
    }
    exitBackground.setTexture(&exitBackgroundTexture); 

    // Store Menu Background
    RectangleShape storeMenuBackground;
    storeMenuBackground.setSize(Vector2f(800,800));
    Texture storeMenuTexture;
    if(!storeMenuTexture.loadFromFile("Assets/FinishedFiles/GardenStoreWindow.png")){
        std::cout << "Store Menu Texture could not be loaded" << std::endl;
        return 0;
    }
    storeMenuBackground.setTexture(&storeMenuTexture);

    // Player Sprite
    sf::Texture texture;
    if(!texture.loadFromFile("Assets/FinishedFiles/Player.png")){
        std::cout << "Player png could not be loaded" << std::endl;
        return 0;
    };
                                        
    sf::Sprite Player;
    Player.setTexture(texture);
    Player.setPosition(sf::Vector2f(300,50));

    // make the game object with tiles
    GameWorld gameWorld = GameWorld();
    gameWorld.setUpTiles();

    // create varying windows
    RenderWindow Play(sf::VideoMode(400, 400), "OOP Project:: Play");
    RenderWindow About(sf::VideoMode(400, 400), "OOP Project:: About");
    RenderWindow Exit(sf::VideoMode(400, 400), "OOP Project:: Exit");
    RenderWindow GardenBedMenu(sf::VideoMode(800, 800), "OOP Project:: GardenBed");
    RenderWindow StoreMenu(sf::VideoMode(800, 800), "OOP Project:: Store");

    // while window is running
    while(window.isOpen()){
        // create event
        sf::Event event;
        
        // while window open
        while (window.pollEvent(event)){
                
            // if want to close then close 
            if (event.type == sf::Event::Closed){
                window.close();
            }
    
            // conditionally execute certain key presses
            if (event.type == Event::KeyPressed){
                switch(event.key.code){
                    // up moves menu option up
                    case Keyboard::Up:
                        gameMenu.MoveUp();
                        break;
                    // down moves menu option down
                    case Keyboard::Down:
                        gameMenu.MoveDown();
                        break;
                    case Keyboard::Return:
                        // return selected item index
                    int x = gameMenu.getPressedItem();

                    
                };
            }
        };

        // draw window
        window.clear();
        window.draw(background);
        gameMenu.draw(window);
        window.display();
    };
    
    
    return 0;
};
