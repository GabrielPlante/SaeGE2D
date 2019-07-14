#include "TempStatusEffect.h"



TempStatusEffect::TempStatusEffect(float lifeTime)
	:lifeTime{ lifeTime }
{
}

bool TempStatusEffect::refresh(LifeForm* affect, float deltaTime) {
	age += deltaTime;
	return age > lifeTime;
}

TempStatusEffect::~TempStatusEffect()
{
}
