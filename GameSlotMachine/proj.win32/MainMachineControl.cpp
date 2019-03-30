#include "MainMachineControl.h"

USING_NS_CC;

void MainMachineControl::StartGame(cocos2d::Scene *scene) {
	DimaMusic::StartGameMusic();
	this->scene = scene;
	LoadSceneMachine();
	lever.LoadLever(scene);
}

void MainMachineControl::LoadSceneMachine() {
	if (this->scene != nullptr) {
		auto SlotMaachineBg = Sprite::create("Image/SlotMachine.png");
		if (SlotMaachineBg != nullptr) {
			SlotMaachineBg->setPosition(Vec2(480, 290));
			SlotMaachineBg->setContentSize(Size(810, 390));
			this->scene->addChild(SlotMaachineBg, DataParameters::z_SlotMachineBg);
		}

		auto SlotMaachine = Sprite::create("Image/SlotMachineEmpty.png");
		if (SlotMaachine != nullptr) {
			SlotMaachine->setPosition(Vec2(480,290));
			SlotMaachine->setContentSize(Size(810, 390));
			this->scene->addChild(SlotMaachine, DataParameters::z_SlotMaachine);
		}

		auto MainBg = Sprite::create("Image/back.png");
		if (MainBg != nullptr) {
			MainBg->setAnchorPoint(Vec2(0, 0));
			MainBg->setContentSize(Size(1000, 600));
			this->scene->addChild(MainBg, DataParameters::z_MainBg);
		}

		auto CoinWall = Sprite::create("Image/SlotMachineForToken.png");
		if (CoinWall != nullptr) {
			CoinWall->setContentSize(Size(800, 390));
			CoinWall->setPosition(Vec2(482.3, 290));
			this->scene->addChild(CoinWall, DataParameters::z_CoinWall);
		}
		auto Arrow = Sprite::create("Image/arrow.png");
		if (Arrow != nullptr) {
			Arrow->setContentSize(Size(120, 100));
			Arrow->setPosition(Vec2(100,280));
			this->scene->addChild(Arrow, DataParameters::z_Arrow);
		}
	}
}

MainMachineControl::MainMachineControl(){
	this->scene = nullptr;
}

MainMachineControl::~MainMachineControl(){
}