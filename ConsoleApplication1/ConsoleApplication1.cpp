#include <iostream>

void takeDamage(int* hp, int damage) {
    if (*hp - damage < 0)
        *hp = 0;
    else
        *hp = *hp - damage;

}

void heal(int* hp, int amount) {
    if (*hp + amount > 100)
        *hp = 100;
    else
        *hp = *hp + amount;
}

void printHp(const int* hp) { std::cout << "HP: " << *hp << "\n" << std::endl; }

bool isAlive(const int* hp) {
    if (*hp > 0) return true;
    else return false;
}

int main()
{
    int hp = 100;
    std::cout << "Player in dungeon" << "\n";
    printHp(&hp);

    takeDamage(&hp, 20);
    std::cout << "Trap did 20 damage" << "\n";
    printHp(&hp);

    takeDamage(&hp, 35);
    std::cout << "Goblin did 35 damage" << "\n";
    printHp(&hp);

    heal(&hp, 20);
    std::cout << "Player use potion: +25 HP" << "\n";
    printHp(&hp);

    takeDamage(&hp, 80);
    std::cout << "Orc did 80 damage" << "\n";
    printHp(&hp);

    if (isAlive(&hp)) std::cout << "Game over";
    else std::cout << "You is alive!!";


}