#include <iostream>

void openChest(int* gold, int* chest, int* hp) {
    *gold += *chest;
    *chest = 0;
}

void takeDamage(int* hp, int damage) {
    *hp = *hp - damage;
    if (*hp < 0) *hp = 0;
}

void swapChests(int* first, int* second) {
    int tmp = *first;
    *first = *second;
    *second = tmp;
}

void printArray(const int* arr, int size) {
    std::cout << "Chests: ";
    for (int i = 0; i < size; i++) {
        std::cout << *(arr + i) << " ";
    }
    std::cout << std::endl;
}

int* findRichestChest(int* arr, int size) {
    int* maxChest = new int;
    *maxChest = 0;

    for (int i = 0; i < size; i++) {
        if (*(arr + i) > *maxChest) {
            *maxChest = *(arr + i);
        }

    }
    return maxChest;
}

void printHp(const int* hp) { std::cout << "HP: " << *hp << std::endl; }

void printGold(const int* gold) { std::cout << "Gold: " << *gold << std::endl; }

int main()
{
    int hp = 100;
    int gold = 0;
    int chests[5] = { 10, 0, 25, 50, 5 };
    int size = 5;

    std::cout << "Player in dungeon" << " HP: " << hp << "\n";
    printHp(&hp);
    printGold(&gold);
    printArray(chests, size);
    std::cout << std::endl;

    int* richestChest = findRichestChest(chests, size);
    std::cout << "The richest chest is found" << std::endl;
    std::cout << "there are " << *richestChest << " gold in it" << std::endl;

    openChest(&gold, richestChest, &hp);
    std::cout << "Player open the richest chest" << std::endl;
    printGold(&gold);
    printArray(chests, size);
    std::cout << std::endl;


    swapChests(&chests[0], &chests[4]);
    std::cout << "First and last chests is swaped" << std::endl;
    printArray(chests, size);
    std::cout << std::endl;

    openChest(&gold, &chests[1], &hp);
    std::cout << "Chest is an empty. You trapped!" << std::endl;
    takeDamage(&hp, 20);
    std::cout << "Trap did 20 damage" << std::endl;
    std::cout << std::endl;
    printHp(&hp);
    printGold(&gold);
}