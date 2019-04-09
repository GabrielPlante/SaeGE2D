#pragma once
#include "Weapon.h"
class MeleeWeapon :
	public Weapon
{
public:
	MeleeWeapon(const std::string& name, int encumbrance, int baseDamage, int range, float sharpness, float fireRate = 1);
	void render(SDL_Renderer* renderer, const Camera& camera, const LifeForm& owner) const = 0;
	bool refresh(const Map& map, const std::list<std::unique_ptr<LifeForm>>& lifeForms, float deltaTime) = 0;
	//lifeForm is the life form attacked
	bool attack(LifeForm* lifeForm) override;
	~MeleeWeapon();
private:
};

