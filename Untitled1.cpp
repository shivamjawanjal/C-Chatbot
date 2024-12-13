#ifndef AI_H
#define AI_H

#include <string>

class AI {
public:
    void run();
    void processCommand(const std::string& command);
    void openNotepad();
    void openCalculator();
    void playVideo();
    void openPhoto();
    void openGoogle();
    void openYoutube();
    void chatWithAI();
    void search();
};

#endif // AI_H
