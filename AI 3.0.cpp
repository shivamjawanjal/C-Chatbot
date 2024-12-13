#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <string>

using namespace std;

class AI {
public:
    void run() {
        cout << "********************** Welcome to My A.I **********************\n\n";
        string command;
        while (true) {
            cout << "Enter a command: ";
            getline(cin, command);
            if (command == "exit") {
                PlaySound(TEXT("Andrew-buy_sir__have_a_good.wav"), NULL, SND_SYNC);
                cout << "Exiting AI. Goodbye!";
                break;
            }
            processCommand(command);
        }
    }

    void processCommand(const string& command) {
        if (command == "Hi") {
            PlaySound(TEXT("Hi.wav"), NULL, SND_SYNC);
        } else if (command == "Hello") {
            PlaySound(TEXT("Hello.wav"), NULL, SND_SYNC);
        } else if (command == "open notepad") {
            openNotepad();
        } else if (command == "open calculator") {
            openCalculator();
        } else if (command == "play video" || command == "open video") {
            playVideo();
        } else if (command == "open photo" || command == "open photos") {
            openPhoto();
        } else if (command == "open google") {
            openGoogle();
        } else if (command == "open youtube") {
            openYoutube();
        } else if (command == "chat with AI") {
            chatWithAI();
        } else if (command == "search") {
            search();
        } else if (command == "open File"){
            OpenFile();
        } else if (command == "play short") {
            PlayShort();
        } else {
            cout << "Command not recognized.\n";
        }
    }

    void openNotepad() {
        PlaySound(TEXT("notepad.wav"), NULL, SND_SYNC);
        STARTUPINFO startInfo = {0};
        PROCESS_INFORMATION processInfo = {0};
        CreateProcess(TEXT("C:\\Windows\\notepad.exe"), NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &startInfo, &processInfo);
    }

    void openCalculator() {
        PlaySound(TEXT("calculator.wav"), NULL, SND_SYNC);
        STARTUPINFO startInfo = {0};
        PROCESS_INFORMATION processInfo = {0};
        CreateProcess(TEXT("C:\\Program Files\\JetBrains\\IntelliJ IDEA Educational Edition 2022.2.2\\bin\\idea64.exe"), NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &startInfo, &processInfo);
    }

    void playVideo() {
        ShellExecute(NULL, "open", "C:\\Users\\shiva\\OneDrive\\Videos\\Kung Fu Panda The Dragon Knight S02E01 Dual Audio {Hindi-English} 720p 10bit WEB-DL ESubs [BollyFlix].mkv", NULL, NULL, SW_SHOWNORMAL);
    }

    void PlayShort(){
        ShellExecute(0, "open","https://www.youtube.com//shorts", NULL, NULL, SW_NORMAL);
    }

    void openPhoto() {
        ShellExecute(0, "open", "C:\\Users\\shiva\\OneDrive\\Pictures\\20231212_124508.jpg", NULL, NULL, SW_NORMAL);
    }
    void OpenFile() {
        string in;
        getline(cin,in);
        string re = "D:\\" + in ;
        ShellExecute(NULL,"open",re.c_str(),NULL,NULL, SW_SHOWNORMAL);
    }

    void openGoogle() {
        ShellExecute(NULL, "open", "https://www.google.com", NULL, NULL, SW_SHOWNORMAL);
    }

    void openYoutube() {
        ShellExecute(NULL, "open", "https://www.youtube.com", NULL, NULL, SW_SHOWNORMAL);
    }

    void chatWithAI() {
        cout << "Which one? chatgpt or gemini\n";
        string choice;
        getline(cin, choice);
        if (choice == "chatgpt") {
            ShellExecute(NULL, "open", "https://chat.openai.com/", NULL, NULL, SW_SHOWNORMAL);
        } else if (choice == "gemini") {
            ShellExecute(NULL, "open", "https://gemini.google.com/app", NULL, NULL, SW_SHOWNORMAL);
        } else {
            cout << "Invalid choice.\n";
        }
    }

    void search() {
        cout << "Which one would you like to search on? Google or Youtube\n";
        string choice;
        getline(cin, choice);
        if (choice == "Google") {
            string text;
            cout << "Enter search query or URL:\n";
            getline(cin, text);
            PlaySound(TEXT("Andrew-wait_for_a_minit_sir.wav"), NULL, SND_SYNC);
            string searchUrl = "https://www.google.com/search?q=" + text;
            ShellExecute(NULL, "open", searchUrl.c_str(), NULL, NULL, SW_SHOWNORMAL);
        } else if (choice == "Youtube") {
            string text;
            cout << "Enter search query or URL:\n";
            getline(cin, text);
            PlaySound(TEXT("Andrew-wait_for_a_minit_sir.wav"), NULL, SND_SYNC);
            string searchUrl = "https://www.youtube.com/results?search_query=" + text;
            ShellExecute(NULL, "open", searchUrl.c_str(), NULL, NULL, SW_SHOWNORMAL);
        } else {
            cout << "Invalid choice.\n";
        }
    }
};

int main() {
    AI ai;
    ai.run();
    return 0;
}
