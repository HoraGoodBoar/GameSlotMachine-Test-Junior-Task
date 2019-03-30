#include "Lever.h"
USING_NS_CC;
void Lever::LoadLever(cocos2d::Scene *scene) {
	if (scene != nullptr) {
		this->money.LoadMoney(scene, &this->slotControl);
		this->slotControl.LoadSlotBg(scene);
		this->slotControl.LoadSlots(scene);

		this->leverUp = cocos2d::Sprite::create("Image/knob1.png");
		leverUp->setPosition(cocos2d::Vec2(850,380));
		leverUp->setContentSize(cocos2d::Size(85,85));

		this->leverDown= cocos2d::Sprite::create("Image/KnobDown.png");
		leverDown->setPosition(cocos2d::Vec2(849,301)); 
		leverDown->setContentSize(cocos2d::Size(85,140));

		this->leverEnter = cocos2d::Sprite::create("Image/KnobGlowHL.png");
		leverEnter->setPosition(cocos2d::Vec2(850, 380));
		leverEnter->setContentSize(cocos2d::Size(100, 100));

		scene->addChild(leverUp,DataParameters::z_Lever);
		scene->addChild(leverDown, DataParameters::z_Lever);
		scene->addChild(leverEnter, DataParameters::z_Lever);

		leverEnter->setVisible(false);
		leverDown->setVisible(false);

		auto listener = EventListenerMouse::create();
		listener->onMouseDown = CC_CALLBACK_1(Lever::Down, this);
		listener->onMouseUp = CC_CALLBACK_1(Lever::Up, this);
		listener->onMouseMove = CC_CALLBACK_1(Lever::Enter, this);

		scene->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);
	}
}


void Lever::Enter(cocos2d::Event * event) {
	if (!this->IsAccessUp) {
		EventMouse* e = (EventMouse*)event;
		if (pow(e->getCursorX() - this->leverUp->getPositionX(), 2) + pow(e->getCursorY() - this->leverUp->getPositionY(), 2) <= pow(this->leverUp->getContentSize().height / 2, 2)) {
			this->leverEnter->setVisible(true);
			this->leverUp->setVisible(false);
			this->IsAccessDown = true;
		}
		else {
			this->leverEnter->setVisible(false);
			this->leverUp->setVisible(true);
			this->IsAccessDown = false;
		}
	}
}

void Lever::Down(cocos2d::Event * event) {
	if (this->IsAccessDown) {
		this->leverEnter->setVisible(false);
		this->leverUp->setVisible(false);
		this->leverDown->setVisible(true);
		this->IsAccessUp = true;
	}
}

void Lever::Up(cocos2d::Event * event) {
	if (this->IsAccessUp) {
		this->leverUp->setVisible(true);
		this->leverDown->setVisible(false);
		this->IsAccessUp = false;
		this->money.PlayAnimation();
	//	this->slotControl.StartAnimations();
	}
}
Lever::Lever(){
}

Lever::~Lever(){
}