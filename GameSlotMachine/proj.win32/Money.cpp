#include "Money.h"

void Money::LoadMoney(cocos2d::Scene *scene, SlotControl  *slotControl) {
	this->slotControl = slotControl;

	this->money = cocos2d::Sprite::create("Image/token.png");
	this->money->setPosition(1000, -100);
	this->money->setContentSize(cocos2d::Size(75, 75));

	this->rotateMoney = cocos2d::Sprite::create("Image/insertToken.png");
	this->rotateMoney->setPosition(730, 275);
	this->rotateMoney->setContentSize(cocos2d::Size(50, 75));
	this->rotateMoney->setVisible(false);

	scene->addChild(this->money, DataParameters::z_Money);
	scene->addChild(this->rotateMoney, DataParameters::z_RotateMoney);
}

void Money::PlayAnimation() {
	if (this->IsAnimation) {
		this->IsAnimation = false;
		auto MoveMoney = cocos2d::MoveTo::create(2, cocos2d::Vec2(740, 275));

		auto animation = cocos2d::Sequence::create(
			MoveMoney,
			cocos2d::CallFunc::create([this] {
			this->money->setVisible(false);
		}),
			cocos2d::CallFunc::create([this] {
			this->rotateMoney->setVisible(true);
		}),
			cocos2d::CallFunc::create([this] {
			auto MoveRotateMoney = cocos2d::MoveTo::create(2, cocos2d::Vec2(670, 275));
			this->rotateMoney->runAction(cocos2d::Sequence::create(MoveRotateMoney,
				cocos2d::CallFunc::create([this] {
				this->money->setPosition(1000, -100);
				this->rotateMoney->setPosition(730, 275);
				this->money->setVisible(true);
				this->rotateMoney->setVisible(false);

				this->slotControl->StartAnimations(&this->IsAnimation);
				//this->IsAnimation = true;
			}),
				nullptr
				));
		}),
			nullptr
			);
		this->money->runAction(animation);
	}
}

Money::Money() {
}
Money::~Money() {

}