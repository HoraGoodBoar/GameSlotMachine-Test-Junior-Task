#pragma once
#include "cocos2d.h"
#include "DataParameters.h"
#include "SlotControl.h"
#include "WinOrLose.h"

class Money {
public:
	Money();
	~Money();
	void LoadMoney(cocos2d::Scene *scene, SlotControl  *slotControl);
	void PlayAnimation();
private:
	cocos2d::Sprite *money;
	cocos2d::Sprite *rotateMoney;
	SlotControl *slotControl;
	bool IsAnimation = true;
};