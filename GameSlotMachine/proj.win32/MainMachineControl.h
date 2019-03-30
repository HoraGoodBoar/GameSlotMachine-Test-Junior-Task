#pragma once
#include "cocos2d.h"
#include "Lever.h"
#include "DataParameters.h"
#include "Money.h"
#include "Music.h"


class MainMachineControl
{
public:
	MainMachineControl();
	~MainMachineControl();
	void StartGame(cocos2d::Scene *scene);
	void LoadSceneMachine();
private:
	cocos2d::Scene *scene;
	Lever lever;
};

