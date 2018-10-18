#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "BackGround.h"
#include "SimpleAudioEngine.h"
#include "EndScene.h"
#include "StartChart.h"
#include "StartScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

void AppDelegate::initGLContextAttrs()
{
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
		glview = GLViewImpl::create("DBall");
        director->setOpenGLView(glview);
		glview->setDesignResolutionSize(960, 640, ResolutionPolicy::SHOW_ALL);
    }

    director->getOpenGLView()->setDesignResolutionSize(960, 640, ResolutionPolicy::SHOW_ALL);

    director->setDisplayStats(true);

    director->setAnimationInterval(1.0f / 60);

    FileUtils::getInstance()->addSearchPath("res");

    auto scene = StartScene::createScene();

    director->runWithScene(scene);

    return true;
}

void AppDelegate::applicationDidEnterBackground() {
	CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
    Director::getInstance()->stopAnimation();
}

void AppDelegate::applicationWillEnterForeground() {
	CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    Director::getInstance()->startAnimation();
}
