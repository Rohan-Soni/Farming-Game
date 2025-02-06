#include"Crop.h"
#include"Day.h"
#include"Seed.h"
#include"User.h"
#include <iostream>

//creates the crop constructor
Crop::Crop(User* User1, std::string name, int RewardForHarvesting, int CostOfItem,int WaterRequired, int TimeRequiredForHarvesting) : Seed(User1, name,RewardForHarvesting, CostOfItem, TimeRequiredForHarvesting) {
    this->WaterRequired = WaterRequired;  //sets the water required to the given parameter 
};

void Crop::Water(){ 
    if(WaterRequired >= User1->GetWaterStorage()){//sees if they have enough water to water the crop 
        User1->SetWaterStorage(User1->GetWaterStorage() - WaterRequired); //subtracts the amount of water the User1 used to water the crop from the users waterstorage
        this->StartPlantingTimer(); //this starts the seed planting timer 
    }   
    else {
        std::cout << "Not enough water, you need " << WaterRequired << " you have.\n" << User1->GetWaterStorage();//this just tells them how much more water they need
    };

}

int Crop::GetWaterRequired(){ //returns water required
    return WaterRequired;
};

//crop destructor     
Crop::~Crop(){};