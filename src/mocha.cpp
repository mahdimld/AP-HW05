#include "mocha.h"

Mocha::Mocha(){
    side_items.clear();
    name = "Mocha";
    ingredients = {Espresso(2), Milk(2), MilkFoam(1),Chocolate(1)};
}
Mocha::Mocha(const Cappuccino& moc){
    side_items = moc.side_items;
    name = moc.name; 
    ingredients = moc.ingredients;
}
Mocha::~Mocha();
void Mocha::operator=(const Mocha& moc){
    side_items = moc.side_items;
    name = moc.name;
    ingredients = moc.ingredients;
}

virtual std::string Mocha::get_name(){return name;}
virtual double price(){return price;}

void add_side_item(Ingredient* side){
    ingredients.push(side);
};
std::vector<Ingredient*>& Mocha::get_side_items(){return side_items;}

Mocha::~Mocha()
{
    for(const auto& i : side_items)
        delete i;
    side_items.clear();
}