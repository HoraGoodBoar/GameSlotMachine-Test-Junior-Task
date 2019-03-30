#pragma once
#include "SimpleAudioEngine.h"
class DimaMusic {
public :
	static void StartGameMusic() {
		CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("Music/1.mp3", true);
	}

	static void StartSlotMusicEffect() {
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Music/2.mp3", false);
	}

	static void StartWinMusicEffect() {
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Music/3.mp3", false);
	}
};