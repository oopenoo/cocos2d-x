#include "HelloWorldScene.h"

USING_NS_CC;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    
    CCLayerColor* pLayer = CCLayerColor::create(ccc4(96, 128, 128, 255));
    addChild(pLayer);

    // left bottom
    CCSprite* pSprite1 = CCSprite::create("label.png");
    pSprite1->setRotation(-90);
    pSprite1->setAnchorPoint(ccp(0, 1));
    pSprite1->setPosition(ccp(0, 0));
    this->addChild(pSprite1, 0);

    // left top
    CCSprite* pSprite2 = CCSprite::create("label.png");
    pSprite2->setAnchorPoint(ccp(0, 1));
    pSprite2->setPosition(ccp(0, 640));
    this->addChild(pSprite2, 0);
    
    // right top
    CCSprite* pSprite3 = CCSprite::create("label.png");
    pSprite3->setRotation(90);
    pSprite3->setAnchorPoint(ccp(0, 1));
    pSprite3->setPosition(ccp(960, 640));
    this->addChild(pSprite3, 0);
    
    // right bottom
    CCSprite* pSprite4 = CCSprite::create("label.png");
    pSprite4->setRotation(180);
    pSprite4->setAnchorPoint(ccp(0, 1));
    pSprite4->setPosition(ccp(960, 0));
    this->addChild(pSprite4, 0);

    // right center
    CCSprite* pSprite5 = CCSprite::create("label.png");
    pSprite5->setFlipX(true);
    pSprite5->setAnchorPoint(ccp(1, 0.5f));
    pSprite5->setPosition(ccp(960, 320));
    this->addChild(pSprite5, 0);

    // center
    CCSprite* pSprite9 = CCSprite::create("label.png");
    pSprite9->setPosition(ccp(480, 320));
    this->addChild(pSprite9, 0);
    
    return true;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
