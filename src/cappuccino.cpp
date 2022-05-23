#include "cappuccino.h"


Cappuccino::Cappuccino(){
    side_items.clear();
    name = "Cappuccino";
    ingredients = {Espresso(2), Milk(2), MilkFoam(1)};
}
Cappuccino::Cappuccino(const Cappuccino& cap){
    side_items = cap.side_items;
    name = cap.name; 
    ingredients = cap.ingredients;
}
Cappuccino::~Cappuccino();
void Cappuccino::operator=(const Cappuccino& cap){
    side_items = cap.side_items;
    name = cap.name;
    ingredients = cap.ingredients;
}

virtual std::string Cappuccino::get_name(){return name;}
virtual double price(){return price;}

void add_side_item(Ingredient* side){
    ingredients.push(side);
};
std::vector<Ingredient*>& Cappuccino::get_side_items(){return side_items;}

Cappuccino::~Cappuccino()
{
    for(const auto& i : side_items)
        delete i;
    side_items.clear();
}