#pragma once
#include "cocos2d.h"
#include "Music.h"
#include "DataParameters.h"

class WinOrLose {
public:
	const static int CountCol = 3;
	cocos2d::Scene * scene;
	int IndexCol[CountCol];
	bool *IsAnimation;
	void LoadWinOrLoss(cocos2d::Scene * sceneMain) {
		scene = sceneMain;
		SetInvalidData();
	}

	void SetFlagTheEnd(int Column,int Id) {
		IndexCol[Column] = Id;
		IsWin();
	}

	void SetInvalidData() {
		for (int i = 0; i < CountCol; ++i)
			IndexCol[i] = -1;
	}

	void IsWin() {
		bool check = true;
		for (int i = 0; i < CountCol; ++i)
			if (IndexCol[i] ==-1) {
				check = false;
				break;
			}
		if (check) {
			*IsAnimation = true;
			if (this->scene != nullptr) {
				for (int i = 0; i < CountCol - 1; ++i)
					if (IndexCol[i] != IndexCol[i + 1]){
						check = false;
						break;
					}
				if (check) {
					auto word = cocos2d::Label::createWithTTF("You win!", "fonts/Marker Felt.ttf", 150);
					word->enableShadow();
					word->setPosition(cocos2d::Vec2(500, 300));
					word->setOpacity(0);
					scene->addChild(word, DataParameters::z_WordWin);

					auto faceIn = cocos2d::FadeIn::create(2.0);
					auto faceOut = cocos2d::FadeOut::create(2.0);

					DimaMusic::StartWinMusicEffect();

					word->runAction(cocos2d::Sequence::createWithTwoActions(faceIn,faceOut));
				}
			}
			SetInvalidData();
		}
	}
};