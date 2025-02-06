#include "shovel.h"
#include"Item.h"
#include"User.h"

Shovel::Shovel(User* User1, GardenBed*Garden1) : Item("Shovel", 50),User1(User1),Garden1(Garden1) {
    SetNameOfItem("Shovel"); //sets the name of the item to shovel 
    SetCostOfItem(50);//sets the price of the item to 50 

};





Shovel::~Shovel() {} //destructors for the shovel 



void Shovel::ShovelTheGround() {
    if(!GetIsBought()){//if the item is not  baugh than this fucntion cant be used
        std::cout << "The shovel is not bought yet" << std::endl; 
        return;
    }
    std::cout << "The ground has been shoveled." << std::endl; //displays this message 
    Garden1->SetShoveled(true); //sets the gardenbed ground to be shoveled hence allowing the User1 to plant stuff in the garden bed
}

void Shovel::BuyThisItem(){
  int Cost = GetCostOfItem(); //puts the cost of the item to the variable cost 
    if (User1->GetMoney() >= Cost) {//checks if the user has enough money  
        User1->SetMoney(User1->GetMoney() - Cost); //subtracts the money from the user 
        std::cout << "Shovel bought successfully!" << std::endl; //displays this message 
        SetIsBought(true);//sets the item to baught 
    } else {
        std::cout << "Not enough money to buy the Shovel." << std::endl; //displays this message if not succesful 
    }

};