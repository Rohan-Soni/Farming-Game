#include "Seed.h"
#include"User.h"
#include"Store.h"
#include"Item.h"
#include <iostream>
//creates the seed consturctor

Seed::Seed(User* User1, string NameOfItem, int RewardForHarvesting, int CostOfItem, int TimeRequiredToHarvesting) : Item(NameOfItem,CostOfItem), User1(User1)  {
    SetNameOfItem(NameOfItem); //sets the name of the item to be what was given as the paramater 
    SetCostOfItem(CostOfItem);//sets the cost of the item to be what was given as the paraamter 
    this->RewardForHarvesting = RewardForHarvesting; //sets the reward for harvesting to be what was given as the paramater
    this->TimeRequiredToHarvesting = TimeRequiredToHarvesting;  //sets the time required for harvesting to be what was given as the paramater 
    SetIsBought(false);
    StopThread = false;  //sets the thread to true 
};
//seed destructor 
Seed::~Seed() {
     StopThread = true;
}

void Seed::HowManyDayTillHarvest() { //gives the user how long is required to harvest the seed once planted
    std::cout << "Time required for harvesting: " << TimeRequiredToHarvesting << " days" << std::endl;
}

void Seed::StartPlantingTimer() {
    if (!GetIsBought()) {//starts planting timer if onnly the seed is bought  
        std::cout << "You need to buy the seed first!" << std::endl; 
        return;
    }

    startTime = std::chrono::system_clock::now(); //starts a timer this variable hold the current time of when the  start timer funciton is called 
    StopThread = false; //sets teh stop thread to false 
}
void Seed::CropFinishedGrowing() { 
    auto currentTime = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime);
    double elapsed_seconds = elapsed.count();

    if (elapsed_seconds < TimeRequiredToHarvesting) { // if enough time has not passed 
        std::cout << "The crop is not ready to harvest yet." << std::endl;
        return;
    } else {
        User1->SetMoney(User1->GetMoney() + RewardForHarvesting); // if enough time has passed then give the money to the user 
        StopThread = true;
        std::cout << "The crop has been harvested!" << std::endl;
    }
}



void Seed::BuyThisItem()  {
    int Cost = GetCostOfItem(); //sets the cost to the cost of the item  
    if (User1->GetMoney() >= Cost) { //checks if the user has enough money 
        User1->SetMoney(User1->GetMoney() - Cost); //subtracts the users money form the cost of the item 
        std::cout << "Item bought successfully!" << std::endl; //displays this message if succesful 
        SetIsBought(true);
    } else {
        std::cout << "Not enough money to buy this item." << std::endl; //if the use does not have enough momney 
    }
}

int Seed::GetRewardForHarvesting(){
    return RewardForHarvesting; //geter for reward for harvesting 
    } 

int Seed::GetTImeForHarvesting(){
    return TimeRequiredToHarvesting; //geter for the timer required for harvesting 
    }
