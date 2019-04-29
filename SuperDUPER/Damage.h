#pragma once
struct Damage {
	//The formula used to create damage
	Damage(float damageMultiplier, int mass, float sharpness, int sharpnessDamage, int pureDamage)
		:bluntDamage{ static_cast<int>(damageMultiplier*mass) }, sharpDamage{ static_cast<int>(damageMultiplier*sharpness*sharpnessDamage) },
		pureDamage{ static_cast<int>(damageMultiplier*pureDamage) }
	{
	}
	//The formula used to take the damage
	int getDamage(float bluntResistance, float sharpResistance) const {
		return static_cast<int>(pureDamage + bluntDamage * bluntResistance + sharpDamage * sharpResistance);
	}
private:
	int bluntDamage;
	int sharpDamage;
	int pureDamage;
};
