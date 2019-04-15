#pragma once
struct Damage {
	//The formula used to create damage
	Damage(float damageMultiplier, short mass, float sharpness, short sharpnessDamage, short pureDamage)
		:bluntDamage{ static_cast<short>(damageMultiplier*mass) }, sharpDamage{ static_cast<short>(damageMultiplier*sharpness*sharpnessDamage) },
		pureDamage{ static_cast<short>(damageMultiplier*pureDamage) }
	{
	}
	//The formula used to take the damage
	short getDamage(float bluntResistance, float sharpResistance) const {
		return static_cast<short>(pureDamage + bluntDamage * bluntResistance + sharpDamage * sharpResistance);
	}
private:
	short bluntDamage;
	short sharpDamage;
	short pureDamage;
};
