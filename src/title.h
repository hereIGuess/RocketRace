#pragma once

class Title {
private:
	bool title;
	bool player1Ready;
	int player1UpButton = 119;

public:
	bool getTitle() {
		return title;
	}

	Title() {
		title = true;
		player1Ready = false;
	}

	void update() {
		if (player1Ready) title = false;
	}

	void checkGameStart(int key) {
		if (key = 119) player1Ready = true;
	}

	void render() {
		ofDrawRectangle(30, 30, 20, 20);
	}
};
