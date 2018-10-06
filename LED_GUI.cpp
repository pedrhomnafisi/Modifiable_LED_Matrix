/*
  Smart LED Project
  COP4331C
  Pedrhom Nafisi
  Bo Williams
  Daniel Ohana
  Brandon Kessler
*/

/*
  This code allows the user to set the number of slides to loop through on
  the LED board and customize the text shown. The customizations include
  the actual text sent to the screen, the size and color of the text, and
  whether the text is animated or not.
*/

/*
  What the output file will be:
  1st line: number of slides to be looped through on LED.
  2nd line: length of time (in seconds) each slide will be shown for.
  The rest of the ouput file is reliant upon the first line (number of slides)
  Each slide will contain four lines in the output file, each indicating a
  different aspect of each slide:
    The first line indicates the string to be outputted to the LED.
    The second line indicates the size of the text as an enum: 0 for small,
    1 for medium, and 2 for large.
    The third line indicates the color of the text as an enum: 0 for red,
    1 for green, 2 for blue, 3 for yellow, 4 for white, 5 for black, 6 for cyan,
    and 7 for magenta.
    The fourth line indicates the animation of the text as an enum: 0 for no
    animation, 1 for flashing, 2 for scrolling, and 3 for waving.
  If there are multiple slides, the previous 4 lines will loop through again
  until we finish the last slide.
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
void outputSlideParam(LED led, ofstream file) {
  file << led.numberOfSlides;
  file << "\n";
  file << led.secondsToLoop;
  file << "\n";
}

// Output the TextSlide values
void outputTextSlideToFile(TextSlide txtSlide, ofstream file) {
  file << txtSlide.text;
  file << "\n";
  file << txtSlide.textSize;
  file << "\n";
  file << txtSlide.color;
  file << "\n";
  file << txtSlide.animation;
  file << "\n";
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
  outFile.open ("out.txt");
  // outputSlideParam(led, outFile);

  outFile << led.getNumSlides();
  outFile << "\n";
  outFile << led.getLoopTime();
  outFile << "\n";

  for(list<TextSlide> :: iterator slide = slides.begin(); slide != slides.end(); slide++) {
    // outputTextSlideToFile(slide, outFile);

    outFile << slide->getText();
    outFile << "\n";
    outFile << slide->getTextSize();
    outFile << "\n";
    outFile << slide->getColor();
    outFile << "\n";
    outFile << slide->getAnimation();
    outFile << "\n";
  }
  outFile.close();

  return 0;
}
