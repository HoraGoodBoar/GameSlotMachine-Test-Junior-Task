#pragma once
#include "cocos2d.h"
#include "DataParameters.h"
#include <vector>
#include "WinOrLose.h"
#include "Music.h"

class Slot {
public:
	void LoadSlot(cocos2d::Scene * scene, std::string PathImg, int indexSlot,int indexCol, WinOrLose * winOrLose);
	void StartAnimation(int Counter);
	WinOrLose * winOrLose;
	int IdSlot = 0;
private:
	cocos2d::Vec2 GetSlotPosition() {
		return cocos2d::Vec2(SlotX.at(this->IndexCol), SlotY.at(this->IndexSlot));
	}
	cocos2d::Vec2 GetShadowPosition() {
		return cocos2d::Vec2(ShadowX.at(this->IndexCol),ShadowY.at(this->IndexSlotBg));
	}

	void StartSlotAnim(int Counter) {
		if (Counter > 0) {
			if (this->IndexSlot + 1 == this->SlotY.size()) {
				this->slot->setVisible(false);
				this->IndexSlot = 0;
			}
			else
				++(this->IndexSlot);
			auto actionSlot = cocos2d::MoveTo::create(this->SpeedSlot, this->GetSlotPosition());

			this->slot->runAction(cocos2d::Sequence::create(
				actionSlot,
				cocos2d::CallFunc::create([this]() {
				if (this->IndexSlot == this->SlotY.size() / 2)
					DimaMusic::StartSlotMusicEffect();
				if (this->IndexSlot == 0)
					this->slot->setVisible(true);
				this->SpeedSlot += this->StepSpeed;
				this->StartSlotAnim(--(this->CountAnimSlot));
			}),
			nullptr
			));
		}
		else
			if (this->IndexSlot == this->SlotY.size() / 2)
				this->winOrLose->SetFlagTheEnd(this->IndexCol, this->IdSlot);
	}
	void StartBgAnim(int Counter) {
		if (Counter > 0) {
			if (this->IndexSlotBg + 1 == this->ShadowY.size()) {
				this->BgSlot->setVisible(false);
				this->IndexSlotBg = 0;
			}
			else 
				++(this->IndexSlotBg);
			auto actionShadow = cocos2d::MoveTo::create(this->SpeedBgSlot, this->GetShadowPosition());
			this->BgSlot->runAction(cocos2d::Sequence::create(
				actionShadow,
				cocos2d::CallFunc::create([this]() {
				if (this->IndexSlotBg == 0)
					this->BgSlot->setVisible(true);
				this->SpeedBgSlot += this->StepSpeed;
				this->StartBgAnim(--(this->CountAnimSlotBg));
			}),
			nullptr
			));
		}
	}

	float SpeedSlot = 1;
	float SpeedBgSlot = 1;
	float StepSpeed = 0;

	int IndexSlot = 0;
	int IndexSlotBg = 0;
	int IndexCol = 0;

	int CountAnimSlot = 0;
	int CountAnimSlotBg = 0;

	std::vector<float> SlotY{
		-220,
		30,
		280,
		530,
		780
	};
	std::vector<float> ShadowY{
		-220,
		30,
		280,
		530,
		780
	};

	std::vector<float> SlotX{
		215,
		390,
		565
	};
	std::vector<float> ShadowX{
		215,
		390,
		565
	};

	cocos2d::Sprite * slot;
	cocos2d::Sprite * BgSlot;
};