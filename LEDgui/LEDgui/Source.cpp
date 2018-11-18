// Bo Williams
// LED GUI

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <list>
using namespace std;

enum TEXTSIZE { SMALL, MEDIUM, LARGE };
enum ANIMATION { NONE, FLASH, SCROLL, WAVE };
enum COLOR { RED, GREEN, BLUE, YELLOW, WHITE, BLACK, CYAN, MAGENTA };

class LED {
public:
	int numberOfSlides;
	int secondsToLoop;
	int currentSlideNumber;

	void setNumberOfSlides(int numSlides) {
		numberOfSlides = numSlides;
	}

	void setSecondsToLoop(int sec) {
		secondsToLoop = sec;
	}

	void setCurrentSlideNumber(int slideNum) {
		currentSlideNumber = ++slideNum % numberOfSlides;
	}

	int getLoopTime() {
		return secondsToLoop;
	}

	int getNumSlides() {
		return numberOfSlides;
	}

	int getCurrentSlide() {
		return currentSlideNumber;
	}
};

class TextSlide : public LED {
public:
	string text;
	TEXTSIZE textSize;
	ANIMATION animation;
	COLOR color;

	void setText(string userText) {
		text = userText;
	}

	void setTextSize(TEXTSIZE txtSize) {
		textSize = txtSize;
	}

	void setAnimation(ANIMATION animate) {
		animation = animate;
	}

	void setColor(COLOR colour) {
		color = colour;
	}
};

void outputSlideParam(LED led, ofstream file) {
	// file.open("out.txt");
	file << led.numberOfSlides;
	file << "\n";
	file << led.secondsToLoop;
	file << "\n";
	// file.close();
}

void outputTextSlideToFile(TextSlide txtSlide, ofstream file) {
	// file.open("out.txt");
	file << txtSlide.text;
	file << "\n";
	file << txtSlide.textSize;
	file << "\n";
	file << txtSlide.color;
	file << "\n";
	file << txtSlide.animation;
	file << "\n";
	// file.close();
}

int main() {
	LED led;
	TextSlide txtSlide;
	ofstream outFile;

	cout << "How many slides do you want to have (up to 4)?\n";
	int numSlides;
	cin >> numSlides;
	led.setNumberOfSlides(numSlides);
	cout << "How long do you want each slide to be displayed (in seconds)?\n";
	int loopTime;
	cin >> loopTime;
	led.setSecondsToLoop(loopTime);

	list<TextSlide> slides;

	for (int i = 0; i < led.numberOfSlides; i++) {
		// TODO: Create new TextSlide object to store in array
		led.setCurrentSlideNumber(i);

		cout << "Input the text you want displayed: \n";
		string userText;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, userText);
		txtSlide.setText(userText);

		cout << "Input the size for your text (small, medium, large): \n";
		string sizeText;
		cin >> sizeText;

		if (sizeText == "small")
			txtSlide.setTextSize(SMALL);
		else if (sizeText == "medium")
			txtSlide.setTextSize(MEDIUM);
		else
			txtSlide.setTextSize(LARGE);

		cout << "Choose the color you want for your text (red, green, blue, yellow, white, black, cyan, magenta): \n";
		string chosenColor;
		cin >> chosenColor;

		if (chosenColor == "red")
			txtSlide.setColor(RED);
		else if (chosenColor == "green")
			txtSlide.setColor(GREEN);
		else if (chosenColor == "blue")
			txtSlide.setColor(BLUE);
		else if (chosenColor == "yellow")
			txtSlide.setColor(YELLOW);
		else if (chosenColor == "white")
			txtSlide.setColor(WHITE);
		else if (chosenColor == "black")
			txtSlide.setColor(BLACK);
		else if (chosenColor == "cyan")
			txtSlide.setColor(CYAN);
		else
			txtSlide.setColor(MAGENTA);

		cout << "Choose the type of animation you want (none, flash, scroll, wave): \n";
		string chosenAnimation;
		cin >> chosenAnimation;

		if (chosenAnimation == "none")
			txtSlide.setAnimation(NONE);
		else if (chosenAnimation == "flash")
			txtSlide.setAnimation(FLASH);
		else if (chosenAnimation == "scroll")
			txtSlide.setAnimation(SCROLL);
		else
			txtSlide.setAnimation(WAVE);

		slides.push_back(txtSlide);
	}


	// txtSlide.outFile.open ("out.txt");
	// outputSlideParam(led, txtSlide.outFile);
	for (TextSlide slide : slides) {
		// outputTextSlideToFile(slide, txtSlide.outFile);
		cout << "\n\n";
		cout << led.getNumSlides();
		cout << "\n";
		cout << led.getLoopTime();
		cout << "\n";
		cout << txtSlide.getCurrentSlide();
		cout << "\n";
		cout << txtSlide.text;
		cout << "\n";
		cout << txtSlide.textSize;
		cout << "\n";
		cout << txtSlide.color;
		cout << "\n";
		cout << txtSlide.animation;
		cout << "\n";
	}
	// txtSlide.outFile.close();

	return 0;
}