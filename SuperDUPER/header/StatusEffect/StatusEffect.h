#pragma once
class LifeForm;
class StatusEffect
{
public:
	StatusEffect();
	virtual bool refresh(LifeForm* affected, float deltaTime) = 0;
	~StatusEffect();
};

