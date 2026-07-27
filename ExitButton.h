#pragma once
#include "SimpleButton.h"

class ExitButton : public SimpleButton {
public:
	ExitButton() : SimpleButton{} { };
	void exit_if_is_clicked(sf::RenderWindow& window) { do_if_is_clicked(window, []() { exit(-1); }); }
};