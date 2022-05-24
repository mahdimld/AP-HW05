#include "espresso_based.h"


EspressoBased::EspressoBased(const EspressoBased& esp){

    
    name = esp.name;
    ingredients = esp.ingredients;

}

EspressoBased::EspressoBased(){
    ingredients.clear();
    name = "";

};

std::vector<Ingredient*>& EspressoBased::get_ingredients(){return ingredients;}

void EspressoBased::operator=(const EspressoBased& esp){
    name = esp.name;
    ingredients = esp.ingredients;

}

EspressoBased::~EspressoBased()
{
   for(auto& i : ingredients){
    i = nullptr;
     delete i;}
    
    ingredients.clear();
}