#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Ability class
class Ability {
public:
    Ability(string name, int damage, int mana_cost) : name_(name), damage_(damage), mana_cost_(mana_cost) {}
    virtual void Execute() = 0;  // virtual function for executing the ability
protected:
    string name_;
    int damage_;
    int mana_cost_;
};

// Character class
class Character {
public:
    Character(string name, int health, int level) : name_(name), health_(health), level_(level) {}
    virtual void UseAbility() = 0;  // virtual function for using abilities
    virtual void PrintStatus() {  // function to print the character's status
        cout << "Name: " << name_ << endl;
        cout << "Health: " << health_ << endl;
        cout << "Level: " << level_ << endl;
    }
protected:
    string name_;
    int health_;
    int level_;
};

// Warrior class, inherits from Character
class Warrior : public Character {
public:
    Warrior(string name, int health, int level) : Character(name, health, level) {}
    void UseAbility() override {  // override the UseAbility virtual function
        cout << name_ << " uses Warrior's ability!" << endl;
        // execute the ability here
    }
};

// Archer class, inherits from Character
class Archer : public Character {
public:
    Archer(string name, int health, int level) : Character(name, health, level) {}
    void UseAbility() override {  // override the UseAbility virtual function
        cout << name_ << " uses Archer's ability!" << endl;
        // execute the ability here
    }
};

// Mage class, inherits from Character
class Mage : public Character {
public:
    Mage(string name, int health, int level) : Character(name, health, level) {}
    void UseAbility() override {  // override the UseAbility virtual function
        cout << name_ << " uses Mage's ability!" << endl;
        // execute the ability here
    }
};

int main() {
    // create some characters
    Warrior warrior("Warrior", 100, 1);
    Archer archer("Archer", 80, 2);
    Mage mage("Mage", 70, 3);

    // create some abilities
    Ability* ability1 = new Ability("Ability 1", 10, 5);
    Ability* ability2 = new Ability("Ability 2", 20, 10);
    Ability* ability3 = new Ability("Ability 3", 30, 15);

    // assign abilities to characters
    warrior.SetAbility(ability1);
    archer.SetAbility(ability2);
    mage.SetAbility(ability3);

    // let the player control the characters and use abilities during gameplay
    vector<Character*> characters = { &warrior, &archer, &mage };
    for (auto character : characters) {
        character->PrintStatus();  // print the character's status
        character->UseAbility();  // use the character's ability
    }

    // free memory allocated for abilities
    delete ability1;
    delete ability2;
    delete ability3;

    return 0;
}
