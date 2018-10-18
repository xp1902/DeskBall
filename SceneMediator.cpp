#include "SceneMediator.h"
#include "HelloWorldScene.h"
//#include "StartScene.h"
//#include "ChoiceScene.h"

SceneMediator * SceneMediator::getInstance()
{
	//if (_instance == nullptr) {
	//	_instance = new SceneMediator();
	//}
	//return _instance;
	return nullptr;
}
//void SceneMediator::gotoChoiceScene()
//{
//	//auto scene = ChoiceScene::createScene();
//	//Director::getInstance()->replaceScene(TransitionProgressRadialCCW::create(0.25, scene));
//}
//
//void SceneMediator::gotoStartScene()
//{
//	//auto scene = StartScene::createScene();
//	//Director::getInstance()->replaceScene(TransitionProgressRadialCCW::create(0.25, scene));
//}
//
void SceneMediator::gotoGameScene()
{
	auto scene = HelloWorld::createScene();
	Director::getInstance()->replaceScene(TransitionProgressRadialCCW::create(0.25, scene));
}

