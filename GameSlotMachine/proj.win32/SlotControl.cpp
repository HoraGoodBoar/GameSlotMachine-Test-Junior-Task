#include "SlotControl.h"

void SlotControl::LoadSlotBg(cocos2d::Scene *scene) {
	this->winOrLose.LoadWinOrLoss(scene);
	auto SlotBgCol1 = cocos2d::Sprite::create("Image/SlotBG.png");
	if (SlotBgCol1 != nullptr) {
		SlotBgCol1->setContentSize(cocos2d::Size(132, 250));
		SlotBgCol1->setPosition(cocos2d::Vec2(215, 280));
		scene->addChild(SlotBgCol1, DataParameters::z_SlotBg);
	}
	auto SlotBgCol2 = cocos2d::Sprite::create("Image/SlotBG.png");
	if (SlotBgCol2 != nullptr) {
		SlotBgCol2->setContentSize(cocos2d::Size(132, 250));
		SlotBgCol2->setPosition(cocos2d::Vec2(390, 280));
		scene->addChild(SlotBgCol2, DataParameters::z_SlotBg);
	}
	auto SlotBgCol3 = cocos2d::Sprite::create("Image/SlotBG.png");
	if (SlotBgCol3 != nullptr) {
		SlotBgCol3->setContentSize(cocos2d::Size(132, 250));
		SlotBgCol3->setPosition(cocos2d::Vec2(565, 280));
		scene->addChild(SlotBgCol3, DataParameters::z_SlotBg);
	}
}
void  SlotControl::LoadSlots(cocos2d::Scene *scene) {
	int index = 0;
	for each (std::string var in this->SlotImgsPath){
		Slot slot0;
		slot0.LoadSlot(scene,var,index,0, &this->winOrLose);
		this->ColFirst.push_back(slot0);
		
		Slot slot1;
		slot1.LoadSlot(scene, var, index, 1, &this->winOrLose);
		this->ColSecond.push_back(slot1);

		Slot slot2;
		slot2.LoadSlot(scene, var, index, 2, &this->winOrLose);
		this->ColThird.push_back(slot2);

		++index;
	}
}

void SlotControl::StartAnimations(bool *IsAnimation) {
	this->winOrLose.IsAnimation = IsAnimation;

	srand(time(NULL));

	int random1 = 15; //rand() % 10 + 1;
	int random2 = 5;  //rand() % 10 + 1;
	int random3 = 10; //rand() % 10 + 1;

	for (int j = 0; j < 5; ++j) {
		this->ColFirst[j].StartAnimation (random1);
		this->ColSecond[j].StartAnimation(random2);
		this->ColThird[j].StartAnimation (random3);
	}
}