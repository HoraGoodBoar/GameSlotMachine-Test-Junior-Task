#pragma once
#include "cocos2d.h"
#include <vector>
#include "DataParameters.h"
#include "Slot.h"
#include "WinOrLose.h"
#include <stdlib.h>
#include <time.h>

class SlotControl {
public:
	void LoadSlotBg(cocos2d::Scene *scene);
	void LoadSlots(cocos2d::Scene *scene);
	void StartAnimations(bool *IsAnimation);

private:
	std::vector<Slot> ColFirst;
	std::vector<Slot> ColSecond;
	std::vector<Slot> ColThird;

	std::vector<std::string> SlotImgsPath{
		"Image/pw_slot.png",
		"Image/slot_feather.png",
		"Image/slot_gold.png",
		"Image/slot_seven.png",
		"Image/slot_tickets.png"
	};

	WinOrLose winOrLose;
};
