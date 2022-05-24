#include "cappuccino.h"


Cappuccino::Cappuccino() : EspressoBased()
{
    side_items.clear();
    name = "Cappuccino";
    ingredients.push_back(new Espresso(2));
    ingredients.push_back(new Milk(2));
    ingredients.push_back(new MilkFoam(1));
}
Cappuccino::Cappuccino(const Cappuccino& cap){
    side_items = cap.side_items;
    name = cap.name; 
    ingredients = cap.ingredients;
}

void Cappuccino::operator=(const Cappuccino& cap){
    side_items = cap.side_items;
    name = cap.name;
    ingredients = cap.ingredients;
}

std::string Cappuccino::get_name(){return name;}
double Cappuccino::price(){
    double sum{0};

    for(auto i : ingredients){
        sum += i->price();
    }
    return sum;

}

void Cappuccino::add_side_item(Ingredient* side){
    side_items.push_back(side);
};
std::vector<Ingredient*>& Cappuccino::get_side_items(){return side_items;}

Cappuccino::~Cappuccino()
{
    for(auto& i : side_items){
    i = nullptr;
     delete i;}
       
    side_items.clear();
}