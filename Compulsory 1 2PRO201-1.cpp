
#include <iostream>
#include <string>

void Task1_2();
void Task3();

#pragma region Task 1 and 2
class Animal
{
private:
    short Animal_ID;

public:
    std::string name;
    std::string place_of_birth;
    short Age;

    Animal(std::string _name, std::string PlaceOfBirth, short _Age) : name{ _name }, place_of_birth{ PlaceOfBirth }, Age{ _Age }
    {
        //this is just some random ID. :D 
        Animal_ID = (_name.length() * PlaceOfBirth.length()) / Age;
    };

    Animal()
    {
        std::cout << "What is the name of this animal? \n";
        std::getline(std::cin, name);
        std::cout << "Where was it born?\n";
        std::getline(std::cin, place_of_birth);
        std::cout << "Okay, now how old is this animal?\n";
        std::string __age;
        std::getline(std::cin, __age);
        Age = std::stoi(__age);

        Animal_ID = (name.length() * place_of_birth.length()) / Age;
    };

    virtual void Speak()
    {

    }

    //This operator compare the age between two animals and returns true if they are the same age
    bool operator * (Animal const& anim)
    {
        return anim.Age == Age;
    }

};
class Dog : public Animal
{
public:
    Dog() { };

    void Speak() override
    {
        std::cout << name << " just said WOOF WOOF ^^, whilst waggling its tail\n";
    }
};
class Cat : public Animal
{
public:
    Cat() { };

    void Speak() override
    {
        std::cout << name << " just said Meow, followed by a angery HISSSSSS\n";
    }
};
class Bird : public Animal
{
public:
    Bird() { };

    void Speak() override
    {
        std::cout << name << " just said Tweet tweet \n";
    }
};

void Task1_2()
{
    std::cout << "Lets add an animal, firstly a bird!\n";
    Bird bird;
    std::cout << "Great, now lets create a cat!\n";
    Cat cat;

    if (cat * bird)
    {
        std::cout << cat.name << " is the same age as " << bird.name << std::endl;
    }
    else
    {
        std::cout << cat.name << " and " << bird.name << " are not the same age\n";
    }
    bird.Speak();
    cat.Speak();

}

#pragma endregion

#pragma region Task 3

template<class T1, class T2>
class Template
{
    T1 x;
    T2 y;
    
public:
    Template()
    {

    }
    Template(T1 _x,T2 _y)
    {
        x = _x;
        y = _y;
    }
    std::string Combine(T1 _x, T2 _y)
    {
        std::string temp = _x + _y;
        return string();
        
        return temp;
    }
};

void Task3()
{
    Template<std::string, std::string> MyTemplateObject{};
    std::cout << "Combined is " << MyTemplateObject.Combine("Lightspeed = ", "300 000 000");
}

#pragma endregion



int main()
{
    Task1_2();

    Task3();
}