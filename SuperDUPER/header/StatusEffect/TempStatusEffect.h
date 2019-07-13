#pragma once
#include "StatusEffect.h"
class TempStatusEffect :
	public StatusEffect
{
public:
	TempStatusEffect(float lifeTime);
	bool refresh(LifeForm* affected, float deltaTime) = 0;
	~TempStatusEffect();
private:
	float lifeTime;
	float age = 0;
};

