#pragma once
#include "ofGraphics.h"
#include "point.h"

extern Point screen;

class Colors {
private:
	int size = 50;
	int padding = 10;

	int left;
	int right;

	std::vector<ofColor> colors = {
		ofColor(255, 255, 255),
		ofColor(255, 0, 0),
		ofColor(255, 150, 0),
		ofColor(150, 255, 0),
		ofColor(0, 255, 0),
		ofColor(0, 0, 255),
		ofColor(255, 0, 255)
	};

	Point position = Point{ screen.x - (int(colors.size()) * (size + padding)) - size / 2, screen.y - size };

	ofColor selectedColor = colors[0];

public:
	Colors() {
		
	}

	Colors(int leftKey, int rightKey) {
		left = leftKey;
		right = rightKey;
	}

	void checkForColorChange(int key) {
		std::cout << key << "\n";
	}

	void render() {
		for (int x = 0; x < colors.size(); x++) {
			ofSetColor(colors[x]);
			ofDrawRectangle(position.x + (x * size) + (padding * x), position.y, size, size);
		}
	}
};
