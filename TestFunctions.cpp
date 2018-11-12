/*
  Smart LED Project
  COP4331C
  Pedrhom Nafisi
  Bo Williams
  Daniel Ohana
  Brandon Kessler
*/

/*
	This code checks to see if the values in the slides match the values
	stored in the output file.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <list>
using namespace std;

enum TEXTSIZE {SMALL, MEDIUM, LARGE};
enum COLOR {RED, GREEN, BLUE, YELLOW, WHITE, BLACK, CYAN, MAGENTA};
enum ANIMATION {NONE, FLASH, SCROLL, WAVE};

// Create global file so all functions can write to it
ofstream file;
ifstream inFile;

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
    int slideNum;

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

    void setSlideNum(int slideNumber) {
      slideNum = slideNumber;
    }

    string getText() {
      return text;
    }

    TEXTSIZE getTextSize() {
      return textSize;
    }

    ANIMATION getAnimation() {
      return animation;
    }

    COLOR getColor() {
      return color;
    }

    int getSlideNum() {
      return slideNum;
    }
};

// Output the number of slides and how long each will be up
void outputSlideParam(LED led) {
  file << led.getNumSlides();
  file << "\n";
  file << led.getLoopTime();
  file << "\n";
}

// Output the TextSlide values
void outputTextSlideToFile(list<TextSlide> :: iterator txtSlide) {
  file << txtSlide->getText();
  file << "\n";
  file << txtSlide->getTextSize();
  file << "\n";
  file << txtSlide->getColor();
  file << "\n";
  file << txtSlide->getAnimation();
  file << "\n";
}

// Test that values transferred correctly
void checkIfValuesMatch(LED led, list<TextSlide> slides) {
	bool success = true;
	int numSlides;
	inFile >> numSlides;
	int loopTime;
	inFile >> loopTime;

	if(numSlides != led.getNumSlides() || loopTime != led.getLoopTime()) {
		cout << "\nFailure in transferring to output text file. (led)\n";
		success = false;
	}

	for(list<TextSlide> :: iterator slide = slides.begin(); slide != slides.end(); slide++) {
		string userText;
    inFile.ignore(numeric_limits<streamsize>::max(), '\n');
    getline (inFile, userText);

		int sizeText;
		inFile >> sizeText;

		int chosenColor;
		inFile >> chosenColor;

		int chosenAnimation;
    inFile >> chosenAnimation;

		if(userText != slide->getText() || sizeText != slide->getTextSize() || chosenColor != slide->getColor() || chosenAnimation != slide->getAnimation()) {
			cout << "\nFailure in transferring to output text file. (textSlide)\n";
			success = false;
		}
	}
	if(success)
		cout << "\nTransferring to output text file was successful.\n";
}

int main() {
  LED led;
  TextSlide txtSlide;

  cout << "How many slides do you want to have (up to 4)?\n";
  int numSlides;
  cin >> numSlides;
  led.setNumberOfSlides(numSlides);
  cout << "How long do you want each slide to be displayed (in seconds)?\n";
  int loopTime;
  cin >> loopTime;
  led.setSecondsToLoop(loopTime);

  list<TextSlide> slides;

  // Get the user input for what they want outputted to LED
  for(int i = 0; i < led.numberOfSlides; i++) {
    led.setCurrentSlideNumber(i);

    cout << "Input the text you want displayed: \n";
    string userText;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline (cin, userText);
    txtSlide.setText(userText);

    cout << "Input the size for your text (small, medium, large): \n";
    string sizeText;
    cin >> sizeText;

    if(sizeText == "small")
      txtSlide.setTextSize(SMALL);
    else if(sizeText == "medium")
      txtSlide.setTextSize(MEDIUM);
    else
      txtSlide.setTextSize(LARGE);

    cout << "Choose the color you want for your text (red, green, blue, yellow, white, black, cyan, magenta): \n";
    string chosenColor;
    cin >> chosenColor;

    if(chosenColor == "red")
      txtSlide.setColor(RED);
    else if(chosenColor == "green")
      txtSlide.setColor(GREEN);
    else if(chosenColor == "blue")
      txtSlide.setColor(BLUE);
    else if(chosenColor == "yellow")
      txtSlide.setColor(YELLOW);
    else if(chosenColor == "white")
      txtSlide.setColor(WHITE);
    else if(chosenColor == "black")
      txtSlide.setColor(BLACK);
    else if(chosenColor == "cyan")
      txtSlide.setColor(CYAN);
    else
      txtSlide.setColor(MAGENTA);

    cout << "Choose the type of animation you want (none, flash, scroll, wave): \n";
    string chosenAnimation;
    cin >> chosenAnimation;

    if(chosenAnimation == "none")
      txtSlide.setAnimation(NONE);
    else if(chosenAnimation == "flash")
      txtSlide.setAnimation(FLASH);
    else if(chosenAnimation == "scroll")
      txtSlide.setAnimation(SCROLL);
    else
      txtSlide.setAnimation(WAVE);

    // Store in a list to be read from later
    slides.push_back(txtSlide);
  }

  // Output the values needed to a text file
  file.open ("out.txt");
  outputSlideParam(led);

  for(list<TextSlide> :: iterator slide = slides.begin(); slide != slides.end(); slide++) {
    outputTextSlideToFile(slide);
  }
  file.close();

	inFile.open("out.txt");
	int numSlidesThatMatch = 0;

  checkIfValuesMatch(led, slides);
	inFile.close();

  return 0;
}
