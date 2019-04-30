#pragma once
struct Attributes
{
public:
	Attributes(int moveSpeed = 300, int strenght = 0, int stamina = 0, int agility = 0, int mentalStrenght = 0,
		int craftsmanship = 0, int intellect = 0, int cunning = 0, int sociability = 0)
		:moveSpeed{ moveSpeed }, strenght{ strenght }, stamina{ stamina }, agility{ agility }, mentalStrenght{ mentalStrenght },
			craftsmanship{ craftsmanship }, intellect{ intellect }, cunning{ cunning }, sociability{ sociability }
	{}
	int moveSpeed;
	int strenght;
	int stamina;
	int agility;
	int mentalStrenght;
	int craftsmanship;
	int intellect;
	int cunning;//ruse
	int sociability;
};

