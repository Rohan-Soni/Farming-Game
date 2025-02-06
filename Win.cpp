#include"Win.h"
#include"User.h"



Win::Win(User* User1) : Item("Win",500),User1(User1){ //the win constructor, inherts from item 
    SetNameOfItem("Win"); //sets the name of the item to win 
    SetCostOfItem(500);//sets the price of the item to 500

}
void Win::BuyThisItem(){
  int Cost = GetCostOfItem(); //sets the cost of the item to the variable Cost 
    if (User1->GetMoney() >= Cost) {//if the User1 has enough money then the followinh happens   
        User1->SetMoney(User1->GetMoney() - Cost); //subtracts the money from the User1 
        std::cout << "You won!!!!!!!!! " << std::endl; //displays you won 
    } else { 
        std::cout << "Not enough money plant more crops." << std::endl;//if they  do no have enough money this will display
    }

};