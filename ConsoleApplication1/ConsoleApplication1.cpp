#include <iostream>
#include <limits>
#include <string>
#include <clocale>

namespace
{
	constexpr int kMaxHealth = 100;
	constexpr int kExpPerLevel = 100;
}

class Player {
private:
	std::string name;
	int level = 1;
	int health = kMaxHealth;
	int experience = 0;
	int gold = 0;

	Player() = default;
	Player(const Player&) = delete;
	Player& operator=(const Player&) = delete;

public:

	static Player& GetInstance()
	{
		static Player player;
		return player;
	}

	/*здоровье игрока не может быть меньше 0 ;
здоровье не может превышать установленное максимальное значение;
количество золота не может быть отрицательным;
нельзя потратить больше золота, чем имеется у игрока;
при накоплении определённого количества опыта уровень игрока увеличивается;
после повышения уровня количество опыта корректно пересчитывается или обнуляется;
метод Reset() возвращает игрока в начальное состояние.*/

	void SetName(const std::string& name)
	{
		this->name = name;
	}

	const std::string& GetName() const
	{
		return name;
	}

	int GetLevel() const
	{
		return level;
	}

	int GetHealth() const
	{
		return health;
	}

	int GetExperience() const
	{
		return experience;
	}

	int GetGold() const
	{
		return gold;
	}

	void TakeDamage(int damage)
	{
		if (damage < 0)
			return;

		health -= damage;
		if (health < 0)
			health = 0;
	}

	void Heal(int amount)
	{
		if (amount < 0)
			return;

		health += amount;
		if (health > kMaxHealth)
			health = kMaxHealth;
	}

	void AddExperience(int amount)
	{
		if (amount < 0)
			return;

		experience += amount;
		while (experience >= kExpPerLevel)
		{
			experience -= kExpPerLevel;
			++level;
		}
	}

	void AddGold(int amount)
	{
		if (amount < 0)
			return;

		gold += amount;
	}

	void SpendGold(int amount)
	{
		if (amount < 0 || amount > gold)
			return;

		gold -= amount;
	}

	void Reset()
	{
		name.clear();
		level = 1;
		health = kMaxHealth;
		experience = 0;
		gold = 0;
	}

	void Print() const
	{
		std::cout << name << " | level " << level
		          << " | hp " << health
		          << " | exp " << experience
		          << " | gold " << gold << '\n';
	}

	void Menu()
	{
		int choice = 0;

		do
		{
			std::cout << "\n1. Показать состояние игрока\n";
			std::cout << "2. Изменить имя\n";
			std::cout << "3. Получить урон\n";
			std::cout << "4. Восстановить здоровье\n";
			std::cout << "5. Добавить опыт\n";
			std::cout << "6. Добавить золото\n";
			std::cout << "7. Потратить золото\n";
			std::cout << "8. Сбросить состояние игрока\n";
			std::cout << "0. Выход\n";
			std::cout << "Выберите: ";

			if (!(std::cin >> choice))
			{
				if (std::cin.eof())
					break;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Неверный ввод, попробуйте ещё раз.\n";
				choice = -1;
				continue;
			}
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::string input;
			int amount = 0;

			switch (choice)
			{
			case 1:
				Print();
				break;

			case 2:
				std::cout << "Новое имя: ";
				setlocale(LC_ALL, "Russian");
				std::getline(std::cin, input);
				if (input.empty())
					std::cout << "Имя не может быть пустым.\n";
				else
					SetName(input);
				break;

			case 3:
				std::cout << "Урон: ";
				if (!(std::cin >> amount))
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Нужно ввести число.\n";
					break;
				}
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				if (amount < 0)
					std::cout << "Урон не может быть отрицательным.\n";
				else
					TakeDamage(amount);
				break;

			case 4:
				std::cout << "Количество здоровья: ";
				if (!(std::cin >> amount))
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Нужно ввести число.\n";
					break;
				}
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				if (amount < 0)
					std::cout << "Лечение не может быть отрицательным.\n";
				else
					Heal(amount);
				break;

			case 5:
				std::cout << "Количество опыта: ";
				if (!(std::cin >> amount))
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Нужно ввести число.\n";
					break;
				}
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				if (amount < 0)
					std::cout << "Опыт не может быть отрицательным.\n";
				else
					AddExperience(amount);
				break;

			case 6:
				std::cout << "Количество золота: ";
				if (!(std::cin >> amount))
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Нужно ввести число.\n";
					break;
				}
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				if (amount < 0)
					std::cout << "Золото не может быть отрицательным.\n";
				else
					AddGold(amount);
				break;

			case 7:
				std::cout << "Количество золота: ";
				if (!(std::cin >> amount))
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Нужно ввести число.\n";
					break;
				}
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				if (amount < 0)
					std::cout << "Сумма не может быть отрицательной.\n";
				else if (amount > gold)
					std::cout << "Недостаточно золота.\n";
				else
					SpendGold(amount);
				break;

			case 8:
				Reset();
				break;

			case 0:
				std::cout << "До свидания!\n";
				break;

			default:
				std::cout << "Неверный выбор.\n";
				break;
			}
		} while (choice != 0);
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	Player::GetInstance().Menu();
}
