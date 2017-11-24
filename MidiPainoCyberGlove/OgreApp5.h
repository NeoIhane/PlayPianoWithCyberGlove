#ifndef __OgreApp5_h_
#define __OgreApp5_h_

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#include "../res/resource.h"
#endif

#include <OgreCamera.h>
#include <OgreEntity.h>
#include <OgreLogManager.h>
#include <OgreRoot.h>
#include <OgreViewport.h>
#include <OgreSceneManager.h>
#include <OgreRenderWindow.h>
#include <OgreConfigFile.h>
#include <OISEvents.h>
#include <OISInputManager.h>
#include <OISKeyboard.h>
#include <OISMouse.h>
#include <OISJoyStick.h>


#include <SdkTrays.h>
#include <SdkCameraMan.h>
#include <OgreSkeleton.h>
#include <OgreSkeletonInstance.h>
#include "Midi.h"
#include "CyberGlove.h"

#include <SDL.h>
#include <SDL_joystick.h>

#include <XnOpenNI.h>
#include <XnCppWrapper.h>
#include <XnHash.h>
#include <XnLog.h>
#include "XnVNite.h"
#include "XnVPointDrawer.h"
#define SAMPLE_XML_PATH "Data/Sample-Tracking.xml"
#define GL_WIN_SIZE_X 720
#define GL_WIN_SIZE_Y 480

#define CHECK_RC(rc, what)											\
	if (rc != XN_STATUS_OK)											\
	{																\
		printf("%s failed: %s\n", what, xnGetStatusString(rc));		\
		return rc;													\
	}
	xn::Context g_Context;
	xn::DepthGenerator g_DepthGenerator;
	xn::HandsGenerator g_HandsGenerator;
	XnVSessionManager* g_pSessionManager;
	XnVFlowRouter* g_pFlowRouter;
	//XnVPointDrawer* g_pDrawer;
	XnBool g_bDrawDepthMap=true;
	XnBool g_bPrintFrameID=false;
	XnFloat g_fSmoothing=0.0f;
	XnBool g_bPause=false;
	XnBool g_bQuit=false;
	SessionState g_SessionState=NOT_IN_SESSION;
	void XN_CALLBACK_TYPE FocusProgress(const XnChar* strFocus, const XnPoint3D& ptPosition, XnFloat fProgress, void* UserCxt){}
	void XN_CALLBACK_TYPE SessionStarting(const XnPoint3D& ptPosition, void* UserCxt){g_SessionState = IN_SESSION;}
	void XN_CALLBACK_TYPE SessionEnding(void* UserCxt){g_SessionState = NOT_IN_SESSION;}
	void XN_CALLBACK_TYPE NoHands(void* UserCxt){g_SessionState = QUICK_REFOCUS;}


    struct joystick
   {
      int deadZone;
      int max;
      
      int yaw;
      int pitch;
      
      int swivel;
   };

struct KeyX
{
	Ogre::String name;
	int note;
	bool visible;
	bool black;
	bool press;
};
struct SendNote
{
	int note;
	bool black;
};
struct Finger
{
	float x,y,z;
};
class OgreApp5 : public Ogre::FrameListener, public Ogre::WindowEventListener, public OIS::KeyListener, public OIS::MouseListener, OgreBites::SdkTrayListener
{
public:
	//init---------------------------------------------------
	int _NumKey;
	float _StartX,_SizeX,_LongW,_LongB,_HeightW,_HeightB;
	SendNote _Note[5];
	KeyX _KeyW[45];
	KeyX _KeyB[45];
	Finger _f[5];
	Ogre::Vector3 _hand[5];
	void update();
	void resetKey();

	CyberGlove cg;
	Serial tests;
	int OpenSerial();
	void SendSerial(int send);
	//-------------------------------------------------------
    OgreApp5(void);
    virtual ~OgreApp5(void);
    bool go(void);
protected:
    Ogre::Root *mRoot;
    Ogre::Camera* mCamera;
    Ogre::SceneManager* mSceneMgr;
    Ogre::RenderWindow* mWindow;
    Ogre::String mResourcesCfg;
    Ogre::String mPluginsCfg;

    // OgreBites
    OgreBites::SdkTrayManager* mTrayMgr;
    OgreBites::SdkCameraMan* mCameraMan;     // basic camera controller
    OgreBites::ParamsPanel* mDetailsPanel;   // sample details panel
    bool mCursorWasVisible;                  // was cursor visible before dialog appeared
    bool mShutDown;

    // OIS Input devices
    OIS::InputManager* mInputManager;
    OIS::Mouse*    mMouse;
    OIS::Keyboard* mKeyboard;

    // Ogre::FrameListener
    virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);

    // OIS::KeyListener
    virtual bool keyPressed( const OIS::KeyEvent &arg );
    virtual bool keyReleased( const OIS::KeyEvent &arg );
    // OIS::MouseListener
    virtual bool mouseMoved( const OIS::MouseEvent &arg );
    virtual bool mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
    virtual bool mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id );

    // Ogre::WindowEventListener
    virtual void windowResized(Ogre::RenderWindow* rw);
    virtual void windowClosed(Ogre::RenderWindow* rw);

public:
	SDL_Joystick* mJoystick;
	//OIS::JoyStick* mJoy;


	//virtual bool axisMoved( const OIS::JoyStickEvent &e, int axis );

	Ogre::Vector3 transVector;
	Ogre::Vector3 world;
	void pressKeyX(Ogre::SkeletonInstance* skel,Ogre::String name,bool press,int note);
	Ogre::SkeletonInstance* skelKeyX;
	Ogre::SkeletonInstance* skelHand;
	CMidi midi;
	void updateHand();
	void setBone(Ogre::SkeletonInstance* skel,Ogre::String name,Ogre::Degree degree,int axis);
//Kinect

	//xn::Context g_Context;
	//xn::DepthGenerator g_DepthGenerator;
	//xn::HandsGenerator g_HandsGenerator;
	//XnVSessionManager* g_pSessionManager;
	//XnVFlowRouter* g_pFlowRouter;
	//XnVPointDrawer* g_pDrawer;
	//XnBool g_bDrawDepthMap;//(true);
	//XnBool g_bPrintFrameID;//(false);
	//XnFloat g_fSmoothing;//(0.0f);
	//XnBool g_bPause;//(false);
	//XnBool g_bQuit;//(false);
	//SessionState g_SessionState;//(NOT_IN_SESSION);
	//void XN_CALLBACK_TYPE FocusProgress(const XnChar* strFocus, const XnPoint3D& ptPosition, XnFloat fProgress, void* UserCxt){}
	//void XN_CALLBACK_TYPE SessionStarting(const XnPoint3D& ptPosition, void* UserCxt){g_SessionState = IN_SESSION;}
	//void XN_CALLBACK_TYPE SessionEnding(void* UserCxt){g_SessionState = NOT_IN_SESSION;}
	//void XN_CALLBACK_TYPE NoHands(void* UserCxt){g_SessionState = QUICK_REFOCUS;}

	void XN_Clean(){g_Context.Shutdown();}
	XnVPointDrawer* g_pDrawer;
	void XN_Update();
	int XN_Init();

};

#endif // #ifndef __OgreApp5_h_
