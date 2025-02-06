#ifndef USER
#define USER
class User{
    //this is the User1 class holds the money andn the water usage of the User1 
private: 
int Money; // the money of the user 
int WaterStorage; //the waterstroage of the user 
public:
User(); //user constructor 
~User(); //destructors 
void SetMoney(int Money);
int GetMoney();
void SetWaterStorage(int WaterStorage);
int GetWaterStorage();
};
#endif