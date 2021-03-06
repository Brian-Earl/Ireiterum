//
// Spike.cpp
//

#include"Event.h"
#include "EventCollision.h"
#include "EventSpike.h";
#include "WorldManager.h";
#include "Spike.h"
#include "Player.h";
#include "ResourceManager.h";
#include "LogManager.h";
#include "EventButton.h";
#include "DisplayManager.h";

Spike::Spike(int d) {


	df::Sprite *p_temp_sprite;
	if (d == 0) {
		p_temp_sprite = RM.getSprite("spike");
		if (!p_temp_sprite)
			LM.writeLog("Spike::Spike(): Warning! Sprite '%s' not found", "ship");
		else {
			setSprite(p_temp_sprite, true);
			setSpriteSlowdown(0);
		}
	}
	else if (d == 1) {
		p_temp_sprite = RM.getSprite("spikeleft");
		if (!p_temp_sprite)
			LM.writeLog("Spike::Spike(): Warning! Sprite '%s' not found", "ship");
		else {
			setSprite(p_temp_sprite, true);
			setSpriteSlowdown(0);
		}
	}
	else if (d == 2) {
		p_temp_sprite = RM.getSprite("spikeright");
		if (!p_temp_sprite)
			LM.writeLog("Spike::Spike(): Warning! Sprite '%s' not found", "ship");
		else {
			setSprite(p_temp_sprite, true);
			setSpriteSlowdown(0);
		}
	}

	setCentered(false);
	setAltitude(1);
	setType("Spike");
	setSolidness(df::HARD);

	// Set starting location.
	df::Vector pos(7.0f, DM.getVertical() / 2.0f);
	setPosition(pos);
}

int Spike::eventHandler(const df::Event *p_e) {
	if (p_e->getType() == df::COLLISION_EVENT) {
		const df::EventCollision *p_c = dynamic_cast <df::EventCollision const *> (p_e);
		if (p_c->getObject2()->getType() == "Player" || p_c->getObject1()->getType() == "Player") {
			EventSpike s;
			WM.onEvent(&s);
			return 1;
		}
	}

	if (p_e->getType() == BUTTON_EVENT) {
		const EventButton *p_c = dynamic_cast <EventButton const *> (p_e);
		EventButton *c = const_cast<EventButton *>(p_c);
		if ((c->getPos().getX() == getPosition().getX()) && c->getPos().getY() == getPosition().getY()) {
			
			df::Sprite *p_temp_sprite;
			p_temp_sprite = RM.getSprite("spike");
			if (!p_temp_sprite)
				LM.writeLog("Spike::Spike(): Warning! Sprite '%s' not found", "ship");
			else {
				p_temp_sprite->setColor(df::Color::MAGENTA);
				setSprite(p_temp_sprite, true);
				setSpriteSlowdown(0);
			}

		}
	}

	return 0;
}