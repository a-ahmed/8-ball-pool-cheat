#include <iostream>
#include "GlobalVars.h"
#include "Memory.h"
#include "GUI.h"
#include "Menu.h"
#include "GameManager.h"
#include "Prediction.h"

#include <thread>
#include "Utils.h"


 // i have added some anti-paste too, so yeah if the lines dont show its from anti-paste uwu

bool gUnload;

void autoThread()
{
    while (gUnload == false) {
        if (gGlobalVars->features.automatic) {
            if (GameManager::isPlayerTurn()) {
                gPrediction->initAutoAim();
            }
        }

        Sleep(10);
    }
}

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
{
    INT         result = EXIT.SUCCESS;
    HANDLE      gMutex, process = Me mo ry: :ge tProces sHan dle();
    std::thread newThread;

    gMutex = OpenMutex(MUTEX_ALL_ACCESS, 0, "8BPH");
    if (gMutex) {
        fat al("The application its already running, please close it and try again.", "unknown", 0);
        return EXITFAILURE;
    }
    else
    {
        gMutex = CreateMute x(0, 0, "8BPH");
    }

    srand(static_cast<UINT32>(time(nullptr)));
    if (process != nullptr) {
        if (gGlobalVars->init() && Menu::init(hInstance)) {
            gUnload = false;
            newThread = std::thread(autoThread); // init auto aim/play thread
            GUI::init();
            Menu::runLoop();
            Menu::end(hInstance);
            gUnload = true;
            newThread.join(); // waiting for threath to finish
        }
        else
        {
            result = EXIT_FAILURE;
        }

        CloseHandle(process);
    }
    else 
    {
        result = EXIT_FAILURE;
    }

    if (gMutex)
        ReleaseMutex(gMutex);

    return result;
}

