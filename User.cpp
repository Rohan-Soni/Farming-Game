#include "User.h"
User::User(){
    Money = 0; //sets the intial users money to 0 
    WaterStorage = 0; //sets the intial users waterstorage to 0
}
void User::SetMoney(int Money){
    this-> Money = Money; //setter for the money 
};

int User::GetMoney(){
    return Money; //getter for the money 
};
void User::SetWaterStorage(int WaterStorage){
    this->WaterStorage = WaterStorage; //setter for the waterstorage 
};
int User::GetWaterStorage(){
    return WaterStorage; //getter for the waterstorage 
};

User::~User(){ //destructor 
}