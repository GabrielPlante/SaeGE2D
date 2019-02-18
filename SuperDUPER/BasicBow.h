#pragma once
#include "RangeWeapon.h"
class BasicBow :
	public RangeWeapon
{
public:
	BasicBow();
	bool attack(LifeForm* lifeForm) override;
	~BasicBow();
};

