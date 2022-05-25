#include "mocha.h"

Mocha::Mocha() : EspressoBased()
{
    side_items.clear();
    name = "Mocha";
    ingredients.push_back(new Espresso{2});
    ingredients.push_back(new Milk{2});
    ingredients.push_back(new MilkFoam{1});
    ingredients.push_back(new Chocolate{1});
}
Mocha::Mocha(const Mocha& moc){
    side_items = moc.side_items;
    name = moc.name; 
    ingredients = moc.ingredients;
}

void Mocha::operator=(const Mocha& moc){
    side_items = moc.side_items;
    name = moc.name;
    ingredients = moc.ingredients;
}

std::string Mocha::get_name(){return name;}
double Mocha::price(){
    double sum{0};

    for(auto i : ingredients){
        sum += i->price();
    }
    for(auto i : side_items){
        sum += i->price();
    }
    return sum;
}

void Mocha::add_side_item(Ingredient* side){
    side_items.push_back(side);
};
std::vector<Ingredient*>& Mocha::get_side_items(){return side_items;}

Mocha::~Mocha()
{
    for(auto& i : side_items){
    i = nullptr;
     delete i;}
       
    side_items.clear();
}