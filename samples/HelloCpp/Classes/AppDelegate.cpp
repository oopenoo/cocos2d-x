#include "AppDelegate.h"
#include "HelloWorldScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    CCDirector *pDirector = CCDirector::sharedDirector();

    pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());
    pDirector->setProjection(kCCDirectorProjection2D);
    
    CCSize designResolutionSize = CCSizeMake(960, 640);
	if (pDirector->getWinSize().height > 320)
	{
		CCFileUtils::sharedFileUtils()->setResourceDirectory("iphonehd");
        if (designResolutionSize.height > pDirector->getWinSize().height)
        {
            CCDirector::sharedDirector()->setContentScaleFactor(2.0f);
        }
	}
	else
    {
		CCFileUtils::sharedFileUtils()->setResourceDirectory("iphone");
        if (designResolutionSize.height > pDirector->getWinSize().height)
        {
            // render sprite 200%
            CCNode::setContentScale(2.0f);
        }
    }
	
	CCEGLView::sharedOpenGLView()->setDesignResolutionSize(designResolutionSize.width,
                                                           designResolutionSize.height,
                                                           kResolutionNoBorder);

    // turn on display FPS
//    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    CCScene *pScene = HelloWorld::scene();

    // run
    pDirector->runWithScene(pScene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
