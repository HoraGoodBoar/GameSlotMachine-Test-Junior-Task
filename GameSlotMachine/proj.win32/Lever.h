#pragma once
#include "cocos2d.h"
#include "DataParameters.h"
#include "Money.h"
#include "SlotControl.h"

class Lever
{
public:
	Lever();
	~Lever();
	void LoadLever(cocos2d::Scene *scene);
private:
	cocos2d::Sprite *leverDown;
	cocos2d::Sprite *leverUp;
	cocos2d::Sprite *leverEnter;

	Money money;
	SlotControl slotControl;

	bool IsAccessDown = false;
	bool IsAccessUp = false;

	void Lever::Enter(cocos2d::Event * event);
	void Lever::Down(cocos2d::Event * event);
	void Lever::Up(cocos2d::Event * event);
};

