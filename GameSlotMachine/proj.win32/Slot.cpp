#include "Slot.h"

void Slot::LoadSlot(cocos2d::Scene * scene, std::string PathImg,int indexSlot, int indexCol, WinOrLose * winOrLose) {
	this->IdSlot = indexSlot;
	this->IndexSlot = indexSlot;
	this->IndexSlotBg = indexSlot;
	this->IndexCol = indexCol;

	this->winOrLose = winOrLose;

	this->slot = cocos2d::Sprite::create(PathImg);
	if (this->slot != nullptr) {
		this->slot->setContentSize(cocos2d::Size(120, 120));
		this->slot->setPosition(this->GetSlotPosition());

		scene->addChild(this->slot, DataParameters::z_Slot);
	}
	this->BgSlot = cocos2d::Sprite::create("Image/Frame.png");
	if (this->BgSlot != nullptr) {
		this->BgSlot->setContentSize(cocos2d::Size(132, 250));
		this->BgSlot->setPosition(this->GetShadowPosition());

		scene->addChild(this->BgSlot, DataParameters::z_SlotShadow);
	}
}
void Slot::StartAnimation(int Counter) {
	this->CountAnimSlot = this->CountAnimSlotBg = Counter;

	this->StepSpeed = (float)1/(float)Counter;
	this->SpeedSlot = this->SpeedBgSlot = this->StepSpeed;

	this->StartSlotAnim(this->CountAnimSlot);
	this->StartBgAnim(this->CountAnimSlotBg);
}