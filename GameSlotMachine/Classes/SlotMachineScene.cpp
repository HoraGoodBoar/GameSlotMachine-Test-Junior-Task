#include <iostream>
#include "SlotMachineScene.h"

USING_NS_CC;

Scene* SlotMachineScene::createScene() {
	return SlotMachineScene::create();
}

bool SlotMachineScene::init() {
	if (!Scene::init())
		return false;
	mainmachinecontrol.StartGame(this);

	return true;
}