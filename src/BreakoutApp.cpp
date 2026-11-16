#include "BreakoutApp.h"
#include "GameLayer.h"

const unsigned int SCREEN_WIDTH = 1280;
const unsigned int SCREEN_HEIGHT = 720;

BreakoutApp::BreakoutApp() : Sald::Application(SCREEN_WIDTH, SCREEN_HEIGHT, Sald::Application::Dimensions::Two)
{
    PushLayer(new GameLayer(SCREEN_WIDTH, SCREEN_HEIGHT));
}

BreakoutApp::~BreakoutApp()
{
}
