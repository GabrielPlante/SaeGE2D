#pragma once
struct Attributes
{
public:
	Attributes(int moveSpeed = 0, int meleeCombat = 0, int rangeCombat = 0, int strenght = 0, int stamina = 0, int agility = 0, int mentalStrenght = 0,
		int craftsmanship = 0, int intellect = 0, int cunning = 0, int sociability = 0)
		:moveSpeed{ moveSpeed }, meleeCombat{ meleeCombat }, rangeCombat{ rangeCombat }, strenght{ strenght }, stamina{ stamina }, agility{ agility },
		mentalStrenght{ mentalStrenght }, craftsmanship{ craftsmanship }, intellect{ intellect }, cunning{ cunning }, sociability{ sociability }
	{}
	int moveSpeed;
	int meleeCombat;
	int rangeCombat;
	int strenght;
	int stamina;
	int agility;
	int mentalStrenght;
	int craftsmanship;
	int intellect;
	int cunning;
	int sociability;
};

