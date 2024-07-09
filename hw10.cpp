#include "hw10.h"

int main() {
	try {
        CardGuessingGame game;
        game.RunGame();
    	}
    	catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << "\n";
    	}
 
return 0;
}
