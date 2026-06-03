#include <iostream>
#include <string>
using namespace std;

// Base class Animal
class Animal
{
private:
    string nameOfAnimal;
    string habitat_area;
    string sound;
    int weight;
    int height;

public:
    Animal(const string &name, const string &habitat, const string &sound, int weight, int height)
        : nameOfAnimal(name), habitat_area(habitat), sound(sound), weight(weight), height(height) {}

    void displayInformation() const
    {
        cout << "Animal: " << nameOfAnimal << endl;
        cout << "Habitat: " << habitat_area << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Height: " << height << " cm" << endl;
    }

    void changeWeight(int _weight)
    {
        weight = _weight;
    }

    virtual void make_sound() const
    {
        cout << sound << endl;
    }

protected:
    void setSound(const string &animalSound)
    {
        sound = animalSound;
    }
};

class Cow : public Animal
{
private:
    double milkProductionInLiters;

public:
    Cow(const string &name, const string &habitat, int weight, int height, double milkProduction)
        : Animal(name, habitat, "moo", weight, height), milkProductionInLiters(milkProduction)
    {
    }

    void make_sound() const override
    {
        cout << "The cow says: ";
        Animal::make_sound();
    }

    double getMilkProduction() const
    {
        return milkProductionInLiters;
    }
};

class Chicken : protected Animal
{
private:
    int dailyEggCount;

public:
    Chicken(const string &name, const string &habitat, int weight, int height, int eggCount)
        : Animal(name, habitat, "buck buck", weight, height), dailyEggCount(eggCount) {}

    void make_sound() const
    {
        cout << "The chicken says: ";
        Animal::make_sound();
    }

    int getEggCount() const
    {
        return dailyEggCount;
    }
    void displayChickenInformation() const
    {
        displayInformation();
    }
};
class Cat : private Animal
{
public:
    Cat(const string &name, const string &habitat, int weight, int height)
        : Animal(name, habitat, "meow", weight, height) {}

    void make_sound() const
    {
        cout << "The cat says: ";
        Animal::make_sound();
    }
};

class PetCat
{
private:
    Cat petCat;
    string petName;

public:
    PetCat(const string &name, const string &petName, const string &habitat, int weight, int height)
        : petCat(name, habitat, weight, height), petName(petName) {}

    void make_sound() const
    {
        cout << petName << " the cat says: ";
        petCat.make_sound();
    }
};

int main()
{

    return 0;
}
