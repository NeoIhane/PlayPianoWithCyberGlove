
#include "OgreApp5.h"


//-------------------------------------------------------------------------------------
OgreApp5::OgreApp5(void)
    : mRoot(0),
    mCamera(0),
    mSceneMgr(0),
    mWindow(0),
    mResourcesCfg(Ogre::StringUtil::BLANK),
    mPluginsCfg(Ogre::StringUtil::BLANK),
    mTrayMgr(0),
    mCameraMan(0),
    mDetailsPanel(0),
    mCursorWasVisible(false),
    mShutDown(false),
    mInputManager(0),
    mMouse(0),
    mKeyboard(0)//,mJoy(0)
{
	 cg.reset();
	 cg.connect();
	 transVector = Ogre::Vector3::ZERO;
	 world = Ogre::Vector3::ZERO;
	 int g = OgreApp5::midi.Connect();
	 int open=OpenSerial();

	 OgreApp5::_StartX=-135;
	 OgreApp5::_LongW=40;
	 OgreApp5::_LongB=25;
	 OgreApp5::_HeightW=3;
	 OgreApp5::_HeightB=4;
	 OgreApp5::_SizeX=6;
	 OgreApp5::_NumKey=45;
	 for(int i=0;i<5;i++)
	 {
		 OgreApp5::_f[i].x=6*i;
		 OgreApp5::_f[i].y=10;
		 OgreApp5::_f[i].z=32;
		 OgreApp5::_Note[i].black=false;
		 OgreApp5::_Note[i].note=-1;
	 }
	 for(int i=0;i<45;i++)
	 {
		 OgreApp5::_KeyW[i].visible=true;
		 OgreApp5::_KeyW[i].press=false;
		 OgreApp5::_KeyW[i].black=false;
		 OgreApp5::_KeyB[i].black=true;
		 OgreApp5::_KeyB[i].press=false;

		 _KeyB[i].name="B000";
		 _KeyB[i].note=-1;

		 if((i%7)==0||(i%7)==4)
			OgreApp5::_KeyB[i].visible=false;
		 else
			OgreApp5::_KeyB[i].visible=true;
	 }
	 _KeyW[0].name="B028";_KeyW[0].note=28;
	 _KeyW[1].name="B029";_KeyW[1].note=29;
	 _KeyW[2].name="B031";_KeyW[2].note=31;
	 _KeyW[3].name="B034";_KeyW[3].note=34;
	 _KeyW[4].name="B036";_KeyW[4].note=36;
	 _KeyW[5].name="B037";_KeyW[5].note=37;
	 _KeyW[6].name="B039";_KeyW[6].note=39;
	 _KeyW[7].name="B041";_KeyW[7].note=41;
	 _KeyW[8].name="B042";_KeyW[8].note=42;
	 _KeyW[9].name="B044";_KeyW[9].note=44;
	 _KeyW[10].name="B046";_KeyW[10].note=46;
	 _KeyW[11].name="B048";_KeyW[11].note=48;
	 _KeyW[12].name="B049";_KeyW[12].note=49;
	 _KeyW[13].name="B051";_KeyW[13].note=51;
	 _KeyW[14].name="B053";_KeyW[14].note=53;
	 _KeyW[15].name="B054";_KeyW[15].note=54;
	 _KeyW[16].name="B056";_KeyW[16].note=56;
	 _KeyW[17].name="B058";_KeyW[17].note=58;
	 _KeyW[18].name="B060";_KeyW[18].note=60;
	 _KeyW[19].name="B061";_KeyW[19].note=61;
	 _KeyW[20].name="B063";_KeyW[20].note=63;
	 _KeyW[21].name="B065";_KeyW[21].note=65;
	 _KeyW[22].name="B066";_KeyW[22].note=66;
	 _KeyW[23].name="B068";_KeyW[23].note=68;
	 _KeyW[24].name="B070";_KeyW[24].note=70;
	 _KeyW[25].name="B072";_KeyW[25].note=72;
	 _KeyW[26].name="B073";_KeyW[26].note=73;
	 _KeyW[27].name="B075";_KeyW[27].note=75;
	 _KeyW[28].name="B077";_KeyW[28].note=77;
	 _KeyW[29].name="B078";_KeyW[29].note=78;
	 _KeyW[30].name="B080";_KeyW[30].note=80;
	 _KeyW[31].name="B082";_KeyW[31].note=82;
	 _KeyW[32].name="B084";_KeyW[32].note=84;
	 _KeyW[33].name="B085";_KeyW[33].note=85;
	 _KeyW[34].name="B087";_KeyW[34].note=87;
	 _KeyW[35].name="B089";_KeyW[35].note=89;
	 _KeyW[36].name="B090";_KeyW[36].note=90;
	 _KeyW[37].name="B092";_KeyW[37].note=92;
	 _KeyW[38].name="B094";_KeyW[38].note=94;
	 _KeyW[39].name="B096";_KeyW[39].note=96;
	 _KeyW[40].name="B097";_KeyW[40].note=97;
	 _KeyW[41].name="B099";_KeyW[41].note=99;
	 _KeyW[42].name="B101";_KeyW[42].note=101;
	 _KeyW[43].name="B102";_KeyW[43].note=102;
	 _KeyW[44].name="B104";_KeyW[44].note=104;
//====================================================
	 _KeyB[1].name="B030";_KeyB[1].note=30;
	 _KeyB[2].name="B033";_KeyB[2].note=33;
	 _KeyB[3].name="B035";_KeyB[3].note=35;
	 _KeyB[5].name="B038";_KeyB[5].note=38;
	 _KeyB[6].name="B040";_KeyB[6].note=40;

	 _KeyB[8].name="B043";_KeyB[8].note=43;
	 _KeyB[9].name="B045";_KeyB[9].note=45;
	 _KeyB[10].name="B047";_KeyB[10].note=47;
	 _KeyB[12].name="B050";_KeyB[12].note=50;
	 _KeyB[13].name="B052";_KeyB[13].note=52;

	 _KeyB[15].name="B055";_KeyB[15].note=55;
	 _KeyB[16].name="B057";_KeyB[16].note=57;
	 _KeyB[17].name="B059";_KeyB[17].note=59;
	 _KeyB[19].name="B062";_KeyB[19].note=62;
	 _KeyB[20].name="B064";_KeyB[20].note=64;

	 _KeyB[22].name="B067";_KeyB[22].note=67;
	 _KeyB[23].name="B069";_KeyB[23].note=69;
	 _KeyB[24].name="B071";_KeyB[24].note=71;
	 _KeyB[26].name="B074";_KeyB[26].note=74;
	 _KeyB[27].name="B076";_KeyB[27].note=76;

	 _KeyB[29].name="B079";_KeyB[29].note=79;
	 _KeyB[30].name="B081";_KeyB[30].note=81;
	 _KeyB[31].name="B083";_KeyB[31].note=83;
	 _KeyB[33].name="B086";_KeyB[33].note=86;
	 _KeyB[34].name="B088";_KeyB[34].note=88;
	
	 _KeyB[36].name="B091";_KeyB[36].note=91;
	 _KeyB[37].name="B093";_KeyB[37].note=93;
	 _KeyB[38].name="B095";_KeyB[38].note=95;
	 _KeyB[40].name="B098";_KeyB[40].note=98;
	 _KeyB[41].name="B100";_KeyB[41].note=100;

	 _KeyB[43].name="B103";_KeyB[43].note=103;



	//g_bDrawDepthMap=true;
	//g_bPrintFrameID=false;
	//g_fSmoothing=0.0f;
	//g_bPause=false;
	//g_bQuit=false;
	//g_SessionState=NOT_IN_SESSION;

	 SDL_Init(SDL_INIT_JOYSTICK|SDL_INIT_NOPARACHUTE);
	 SDL_JoystickEventState(SDL_ENABLE);
	 //======================
	 mJoystick = SDL_JoystickOpen(0);
	 if( mJoystick == NULL )
	 {
		 SDL_JoystickClose(mJoystick);
	 }
	
}
//-------------------------------------------------------------------------------------
OgreApp5::~OgreApp5(void)
{
	SDL_JoystickClose(mJoystick);
	SDL_Quit();
	OgreApp5::XN_Clean();
	midi.Closed();
    if (mTrayMgr) delete mTrayMgr;
    if (mCameraMan) delete mCameraMan;

    //Remove ourself as a Window listener
    Ogre::WindowEventUtilities::removeWindowEventListener(mWindow, this);
    windowClosed(mWindow);
    delete mRoot;
}
int OgreApp5::OpenSerial()
{
	int temp = 0;
	char port[6];
	strcpy_s(port, "COM4");
	if(tests.Open((LPCSTR)port, 9600))
	{
		cout << "Serial Ok\n";
		temp = 1;
	}
	else 
		cout << "Serial Error " << port;
	
	return temp;
}
void OgreApp5::SendSerial(int send)
{
	char g1;
	switch(send)
	{
		case 1:
			g1='5';
			
		break;
		case 2:
			g1='4';
			
		break;
		case 3:
			g1='3';
		
		break;
		case 4:
			g1='2';
			
		break;
		case 5:
			g1='1';
			
		break;
	}
	tests.Write(&g1,1);
}
void OgreApp5::XN_Update()
{
	//XnMapOutputMode mode;
	//g_DepthGenerator.GetMapOutputMode(mode);
	if (!g_bPause)
	{
		g_Context.WaitAndUpdateAll();
		//g_pSessionManager->Update(&g_Context);
		//PrintSessionState(g_SessionState);
	
	}

	//std::map<XnUInt32, std::list<XnPoint3D> >::const_iterator PointIterator;
	//for (PointIterator = g_pDrawer->m_History.begin();PointIterator != g_pDrawer->m_History.end();++PointIterator)
	//{
	//	XnUInt32 nPoints = 0;
	//	XnUInt32 i = 0;
	//	XnUInt32 Id = PointIterator->first;
	//	std::list<XnPoint3D>::const_iterator PositionIterator;
	//	for (PositionIterator = PointIterator->second.begin();PositionIterator != PointIterator->second.end();++PositionIterator, ++i)
	//	{
	//		XnPoint3D pt(*PositionIterator);
	//		/*transVector.x=pt.X;
	//		transVector.y=pt.Y;
	//		transVector.z=pt.Z;*/
	//	}
	//}
	//transVector.x=g_pDrawer->px;
	//transVector.y=g_pDrawer->py;
	//transVector.z=g_pDrawer->pz;
}
int OgreApp5::XN_Init()
{
	XnStatus rc = XN_STATUS_OK;
	rc = g_Context.InitFromXmlFile(SAMPLE_XML_PATH);
	CHECK_RC(rc, "InitFromXmlFile");
	rc = g_Context.FindExistingNode(XN_NODE_TYPE_DEPTH, g_DepthGenerator);
	CHECK_RC(rc, "Find depth generator");
	rc = g_Context.FindExistingNode(XN_NODE_TYPE_HANDS, g_HandsGenerator);
	CHECK_RC(rc, "Find hands generator");
	g_pSessionManager = new XnVSessionManager;
	rc = g_pSessionManager->Initialize(&g_Context, "Click,Wave", "RaiseHand");
	CHECK_RC(rc, "SessionManager::Initialize");
	g_pSessionManager->RegisterSession(NULL, SessionStarting, SessionEnding, FocusProgress);
	g_pDrawer = new XnVPointDrawer(20, g_DepthGenerator); 
	g_pFlowRouter = new XnVFlowRouter;
	g_pFlowRouter->SetActive(g_pDrawer);
	g_pSessionManager->AddListener(g_pFlowRouter);
	g_pDrawer->RegisterNoPoints(NULL, NoHands);
	g_pDrawer->SetDepthMap(g_bDrawDepthMap);
	//transVector.x=g_pDrawer->px;
	//transVector.y=g_pDrawer->py;
	//transVector.z=g_pDrawer->pz;
	// Initialization done. Start generating
	rc = g_Context.StartGeneratingAll();
	CHECK_RC(rc, "StartGenerating");
	return 0;
}
bool OgreApp5::go(void)
{
#ifdef _DEBUG
    mResourcesCfg = "resources_d.cfg";
    mPluginsCfg = "plugins_d.cfg";
#else
    mResourcesCfg = "resources.cfg";
    mPluginsCfg = "plugins.cfg";
#endif

    // construct Ogre::Root
    mRoot = new Ogre::Root(mPluginsCfg);
    Ogre::ConfigFile cf;
    cf.load(mResourcesCfg);
    Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();
    Ogre::String secName, typeName, archName;
    while (seci.hasMoreElements())
    {
        secName = seci.peekNextKey();
        Ogre::ConfigFile::SettingsMultiMap *settings = seci.getNext();
        Ogre::ConfigFile::SettingsMultiMap::iterator i;
        for (i = settings->begin(); i != settings->end(); ++i)
        {
            typeName = i->first;
            archName = i->second;
            Ogre::ResourceGroupManager::getSingleton().addResourceLocation(
                archName, typeName, secName);
        }
    }
    if(mRoot->showConfigDialog())
    {
        mWindow = mRoot->initialise(true, "OgreApp5 Render Window");

        // Let's add a nice window icon
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
        HWND hwnd;
        mWindow->getCustomAttribute("WINDOW", (void*)&hwnd);

		LONG iconID   = (LONG)LoadIcon( GetModuleHandle(0), MAKEINTRESOURCE(IDI_APPICON) );
        SetClassLong( hwnd, GCL_HICON, iconID );
#endif
    }
    else
    {
        return false;
    }
//-------------------------------------------------------------------------------------
    // choose scenemanager
    // Get the SceneManager, in this case a generic one
    mSceneMgr = mRoot->createSceneManager(Ogre::ST_GENERIC);
//-------------------------------------------------------------------------------------
    // create camera
    mCamera = mSceneMgr->createCamera("PlayerCam");
    mCamera->setPosition(Ogre::Vector3(0,380,180));
    mCamera->lookAt(Ogre::Vector3(0,0,0));
    mCamera->setNearClipDistance(5);
    mCameraMan = new OgreBites::SdkCameraMan(mCamera);   
//-------------------------------------------------------------------------------------
    // create viewports
    Ogre::Viewport* vp = mWindow->addViewport(mCamera);
    vp->setBackgroundColour(Ogre::ColourValue(0,0,0));
    mCamera->setAspectRatio(
        Ogre::Real(vp->getActualWidth()) / Ogre::Real(vp->getActualHeight()));
//-------------------------------------------------------------------------------------
    // Set default mipmap level (NB some APIs ignore this)
    Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);
//-------------------------------------------------------------------------------------
    // Create any resource listeners (for loading screens)
    //createResourceListener();
//-------------------------------------------------------------------------------------
    // load resources
    Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
//-------------------------------------------------------------------------------------
    // Create the scene
    Ogre::Entity* ent = mSceneMgr->createEntity("Paino", "Paino.mesh");
    Ogre::SceneNode* node = mSceneMgr->getRootSceneNode()->
		createChildSceneNode("PainoNode",Ogre::Vector3(0.0f, 0.0f,  0.0f));
    node->attachObject(ent);

	//bone
	skelKeyX=ent->getSkeleton();

	ent=mSceneMgr->createEntity("CyberGlovex", "CyberGloveX.mesh");
	
	node = mSceneMgr->getRootSceneNode()->
		createChildSceneNode("HandNode",Ogre::Vector3(0.0f, 10.0f,  50.0f));
	node->attachObject(ent);

	//bone
	skelHand=ent->getSkeleton();
	
	ent=mSceneMgr->createEntity("Box1", "Box001.mesh");
	node = mSceneMgr->getRootSceneNode()->
		createChildSceneNode("Box1Node",Ogre::Vector3(0.0f, 10.0f,  50.0f));
	node->attachObject(ent);
	ent=mSceneMgr->createEntity("Box2", "Box001.mesh");
	node = mSceneMgr->getRootSceneNode()->
		createChildSceneNode("Box2Node",Ogre::Vector3(0.0f, 10.0f,  50.0f));
	node->attachObject(ent);
	ent=mSceneMgr->createEntity("Box3", "Box001.mesh");
	node = mSceneMgr->getRootSceneNode()->
		createChildSceneNode("Box3Node",Ogre::Vector3(0.0f, 10.0f,  50.0f));
	node->attachObject(ent);
	ent=mSceneMgr->createEntity("Box4", "Box001.mesh");
	node = mSceneMgr->getRootSceneNode()->
		createChildSceneNode("Box4Node",Ogre::Vector3(0.0f, 10.0f,  50.0f));
	node->attachObject(ent);
	ent=mSceneMgr->createEntity("Box5", "Box001.mesh");
	node = mSceneMgr->getRootSceneNode()->
		createChildSceneNode("Box5Node",Ogre::Vector3(0.0f, 10.0f,  50.0f));
	node->attachObject(ent);

    // Set ambient light
    mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));
    Ogre::Light* l = mSceneMgr->createLight("MainLight");
    l->setPosition(20,80,50);
//-------------------------------------------------------------------------------------
    //create FrameListener
    Ogre::LogManager::getSingletonPtr()->logMessage("*** Initializing OIS ***");
    OIS::ParamList pl;
    size_t windowHnd = 0;
    std::ostringstream windowHndStr;

    mWindow->getCustomAttribute("WINDOW", &windowHnd);
    windowHndStr << windowHnd;
    pl.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));

    mInputManager = OIS::InputManager::createInputSystem( pl );
	
    mKeyboard = static_cast<OIS::Keyboard*>(mInputManager->createInputObject( OIS::OISKeyboard, true ));
    mMouse = static_cast<OIS::Mouse*>(mInputManager->createInputObject( OIS::OISMouse, true ));
	//mJoy = static_cast<OIS::JoyStick*>(mInputManager->createInputObject( OIS::OISJoyStick, false ));


	
    mMouse->setEventCallback(this);
    mKeyboard->setEventCallback(this);
	//mJoy->setEventCallback(this);

    //Set initial mouse clipping size
    windowResized(mWindow);

    //Register as a Window listener
    Ogre::WindowEventUtilities::addWindowEventListener(mWindow, this);

    mTrayMgr = new OgreBites::SdkTrayManager("InterfaceName", mWindow, mMouse, this);
    mTrayMgr->showFrameStats(OgreBites::TL_BOTTOMLEFT);
    mTrayMgr->showLogo(OgreBites::TL_BOTTOMRIGHT);
    mTrayMgr->hideCursor();

    // create a params panel for displaying sample details
    Ogre::StringVector items;
    items.push_back("cam.pX");
    items.push_back("cam.pY");
    items.push_back("cam.pZ");
    items.push_back("");
    items.push_back("cam.oW");
    items.push_back("cam.oX");
    items.push_back("cam.oY");
    items.push_back("cam.oZ");
    items.push_back("");
    items.push_back("Filtering");
    items.push_back("Poly Mode");

    mDetailsPanel = mTrayMgr->createParamsPanel(OgreBites::TL_NONE, "DetailsPanel", 200, items);
    mDetailsPanel->setParamValue(9, "Bilinear");
    mDetailsPanel->setParamValue(10, "Solid");
    mDetailsPanel->hide();

    mRoot->addFrameListener(this);
//-------------------------------------------------------------------------------------
    mRoot->startRendering();
	OgreApp5::XN_Init();


    return true;
}
void OgreApp5::update()
{
	resetKey();
	
	for(int i=0;i<5;i++)
		_Note[i].note=-1;
	for(int i=0;i<5;i++)
	{
		if(_f[i].z<=_LongW&&_f[i].z>=0)
		{
			if(_f[i].z<=_LongB)//Black
			{
				if(_f[i].y<=_HeightB&&_f[i].y>=2)
				{
					_Note[i].black=true;
					_Note[i].note=(int)((_f[i].x-(_StartX+3))/_SizeX);
				}
			}else//White
			{
				if(_f[i].y<=_HeightW&&_f[i].y>=0)//press
				{
					_Note[i].black=false;
					_Note[i].note=(int)((_f[i].x-_StartX)/_SizeX);
				}
			}
		}
	}
	for(int i=0;i<5;i++)
	{
		if(_Note[i].note!=-1)
		{
			if(_Note[i].black==false)
				pressKeyX(skelKeyX,_KeyW[_Note[i].note].name,true,_KeyW[_Note[i].note].note);
			else
			{
				if(_KeyB[_Note[i].note].visible==true)
					pressKeyX(skelKeyX,_KeyB[_Note[i].note].name,true,_KeyB[_Note[i].note].note);
			}
			SendSerial(i+1);
		}

	}
}
void OgreApp5::resetKey()
{
	for(int i=0;i<45;i++)
	{
		pressKeyX(skelKeyX,_KeyW[i].name,false,_KeyW[i].note);
		if(_KeyB[i].visible==true&&_KeyB[i].name!="B000")
			pressKeyX(skelKeyX,_KeyB[i].name,false,_KeyB[i].note);
	}
}
bool OgreApp5::frameRenderingQueued(const Ogre::FrameEvent& evt)
{
    if(mWindow->isClosed())
        return false;

    if(mShutDown)
        return false;

    //Need to capture/update each device
	
    mKeyboard->capture();
    mMouse->capture();
	
    mTrayMgr->frameRenderingQueued(evt);

    if (!mTrayMgr->isDialogVisible())
    {
        mCameraMan->frameRenderingQueued(evt);   // if dialog isn't up, then update the camera
        if (mDetailsPanel->isVisible())   // if details panel is visible, then update its contents
        {
            mDetailsPanel->setParamValue(0, Ogre::StringConverter::toString(mCamera->getDerivedPosition().x));
            mDetailsPanel->setParamValue(1, Ogre::StringConverter::toString(mCamera->getDerivedPosition().y));
            mDetailsPanel->setParamValue(2, Ogre::StringConverter::toString(mCamera->getDerivedPosition().z));
            mDetailsPanel->setParamValue(4, Ogre::StringConverter::toString(mCamera->getDerivedOrientation().w));
            mDetailsPanel->setParamValue(5, Ogre::StringConverter::toString(mCamera->getDerivedOrientation().x));
            mDetailsPanel->setParamValue(6, Ogre::StringConverter::toString(mCamera->getDerivedOrientation().y));
            mDetailsPanel->setParamValue(7, Ogre::StringConverter::toString(mCamera->getDerivedOrientation().z));
        }
    }

	OgreApp5::XN_Update();
		/*transVector.x=g_pDrawer->px;
		transVector.y=g_pDrawer->py;
		transVector.z=g_pDrawer->pz;*/
	

	mSceneMgr->getSceneNode("HandNode")->resetToInitialState();
	//mSceneMgr->getSceneNode("HandNode")->scale(2,2,2);
	transVector.y=20;
	SDL_JoystickUpdate();
	transVector.z =90 + SDL_JoystickGetAxis(mJoystick, 1) / 237;
	transVector.x = SDL_JoystickGetAxis(mJoystick, 0) / 237;
	mSceneMgr->getSceneNode("HandNode")->translate(transVector, Ogre::Node::TS_WORLD);
	updateHand();
	//mSceneMgr->getSceneNode("HandNode")->translate(transVector * evt.timeSinceLastFrame, Ogre::Node::TS_LOCAL);

	//Ogre::Bone* controlBone=skelHand->getBone("Bone13");
	//controlBone->getPosition().y;
	Ogre::Vector3 HandPos;

		HandPos =transVector+skelHand->getBone("Tx")->_getDerivedPosition();
		_f[0].x=HandPos.x;_f[0].y=HandPos.y;_f[0].z=HandPos.z;
		mSceneMgr->getSceneNode("Box1Node")->resetToInitialState();
		mSceneMgr->getSceneNode("Box1Node")->translate(HandPos, Ogre::Node::TS_WORLD);

		HandPos =transVector+skelHand->getBone("Ix")->_getDerivedPosition();
		_f[1].x=HandPos.x;_f[1].y=HandPos.y;_f[1].z=HandPos.z;
		mSceneMgr->getSceneNode("Box2Node")->resetToInitialState();
		mSceneMgr->getSceneNode("Box2Node")->translate(HandPos, Ogre::Node::TS_WORLD);

		HandPos =transVector+skelHand->getBone("Mx")->_getDerivedPosition();
		_f[2].x=HandPos.x;_f[2].y=HandPos.y;_f[2].z=HandPos.z;
		mSceneMgr->getSceneNode("Box3Node")->resetToInitialState();
		mSceneMgr->getSceneNode("Box3Node")->translate(HandPos, Ogre::Node::TS_WORLD);

		HandPos =transVector+skelHand->getBone("Rx")->_getDerivedPosition();
		_f[3].x=HandPos.x;_f[3].y=HandPos.y;_f[3].z=HandPos.z;
		mSceneMgr->getSceneNode("Box4Node")->resetToInitialState();
		mSceneMgr->getSceneNode("Box4Node")->translate(HandPos, Ogre::Node::TS_WORLD);

		HandPos =transVector+skelHand->getBone("Px")->_getDerivedPosition();
		_f[4].x=HandPos.x;_f[4].y=HandPos.y;_f[4].z=HandPos.z;
		mSceneMgr->getSceneNode("Box5Node")->resetToInitialState();
		mSceneMgr->getSceneNode("Box5Node")->translate(HandPos, Ogre::Node::TS_LOCAL);

	
	update();
    return true;
}
void OgreApp5::updateHand()
{


	cg.update();
	

	Ogre::Bone* controlBone=skelHand->getBone("XX");
	controlBone->setManuallyControlled(true);
	controlBone->setOrientation(controlBone->getInitialOrientation());
	controlBone->roll(Ogre::Degree(cg.angle(17)));
	

	controlBone=skelHand->getBone("I04");
	controlBone->setManuallyControlled(true);
	controlBone->setOrientation(controlBone->getInitialOrientation());
	controlBone->yaw(Ogre::Degree(-20));
	controlBone->roll(Ogre::Degree(cg.angle(4)));


	//setBone(skelHand,"Pa20",Ogre::Degree((cg.angle(15))),0);

	setBone(skelHand,"T00",Ogre::Degree(cg.angle(0)+90),2);
	setBone(skelHand,"T03",Ogre::Degree((cg.angle(3)+25)/2),1);
	setBone(skelHand,"T01",Ogre::Degree(cg.angle(1)+90),1);//$
	setBone(skelHand,"T02",Ogre::Degree(cg.angle(2)+45),1);//$
	
	//setBone(skelHand,"I04",Ogre::Degree(cg.angle(4)),2);
	setBone(skelHand,"I05",Ogre::Degree(cg.angle(5)),2);//

	controlBone=skelHand->getBone("M08");
	controlBone->setManuallyControlled(true);
	controlBone->setOrientation(controlBone->getInitialOrientation());
	controlBone->roll(Ogre::Degree(cg.angle(6)+75));
	controlBone->yaw(Ogre::Degree(cg.angle(8)-165));
	//setBone(skelHand,"M08",Ogre::Degree(cg.angle(6)+75),2);
	//setBone(skelHand,"M11",Ogre::Degree(cg.angle(8)-165),1);//#
	setBone(skelHand,"M09",Ogre::Degree(cg.angle(7)+80),2);//

	controlBone=skelHand->getBone("R12");
	controlBone->setManuallyControlled(true);
	controlBone->setOrientation(controlBone->getInitialOrientation());
	controlBone->yaw(Ogre::Degree(-(cg.angle(11)+90)/2));
	controlBone->roll(Ogre::Degree(cg.angle(9)+105));
	//setBone(skelHand,"R12",Ogre::Degree(cg.angle(9)+105),2);
	//setBone(skelHand,"R15",Ogre::Degree(-(cg.angle(11)+90)/2),1);//#
	setBone(skelHand,"R13",Ogre::Degree(cg.angle(10)+80),2);//

	setBone(skelHand,"P16",Ogre::Degree(cg.angle(12)),2);
	setBone(skelHand,"P19",Ogre::Degree(cg.angle(19)+45),1);
	setBone(skelHand,"P17",Ogre::Degree(cg.angle(13)+25),2);//

}
void OgreApp5::setBone(Ogre::SkeletonInstance* skel,Ogre::String name,Ogre::Degree degree,int axis)
{
	Ogre::Bone* controlBone=skel->getBone(name);
	controlBone->setManuallyControlled(true);
	//controlBone->resetOrientation();
	controlBone->setOrientation(controlBone->getInitialOrientation());
	switch(axis)
	{
		case 0:controlBone->pitch(degree);break;
		case 1:controlBone->yaw(degree);break;
		case 2:controlBone->roll(degree);break;
	}
}
void OgreApp5::pressKeyX(Ogre::SkeletonInstance* skel,Ogre::String name,bool press,int note)
{
	Ogre::Bone* controlBone=skel->getBone(name);
	controlBone->setManuallyControlled(true);
	controlBone->resetOrientation();
	if(press==true)
	{
		controlBone->roll(Ogre::Degree(-2));
	//else
		//controlBone->roll(Ogre::Degree(0));
	
		midi.PlaySound(note,1);
	}
}















//-------------------------------------------------------------------------------------
//bool OgreApp5::axisMoved( const OIS::JoyStickEvent &e, int axis )
//{
//	int x=e.state.mAxes[axis].abs;
//	switch(axis)
//	{
//		case 0:
//		break;
//		case 1:transVector.x=x;
//		break;
//		case 2:
//		break;
//	}
//	return true;
//}
bool OgreApp5::keyPressed( const OIS::KeyEvent &arg )
{
    if (arg.key == OIS::KC_ESCAPE)
    {
        mShutDown = true;
    }

	if(arg.key == OIS::KC_Z)
	{
		//transVector = Ogre::Vector3::ZERO;
		transVector.y = -10;
	}
	if(arg.key == OIS::KC_X)
	{
		//transVector = Ogre::Vector3::ZERO;
		transVector.y = 10;
	}

	if(arg.key == OIS::KC_1)pressKeyX( OgreApp5::skelKeyX,"B060",true,60);
	if(arg.key == OIS::KC_2)pressKeyX( OgreApp5::skelKeyX,"B061",true,61);
	if(arg.key == OIS::KC_3)pressKeyX( OgreApp5::skelKeyX,"B062",true,62);
	if(arg.key == OIS::KC_4)pressKeyX( OgreApp5::skelKeyX,"B063",true,63);
	if(arg.key == OIS::KC_5)pressKeyX( OgreApp5::skelKeyX,"B064",true,64);
	if(arg.key == OIS::KC_6)pressKeyX( OgreApp5::skelKeyX,"B065",true,65);
	if(arg.key == OIS::KC_7)pressKeyX( OgreApp5::skelKeyX,"B066",true,66);
	if(arg.key == OIS::KC_8)pressKeyX( OgreApp5::skelKeyX,"B067",true,67);
	if(arg.key == OIS::KC_9)pressKeyX( OgreApp5::skelKeyX,"B068",true,68);

	if(arg.key == OIS::KC_F)_f[0].y=2;
	if(arg.key == OIS::KC_G)_f[1].y=2;
	if(arg.key == OIS::KC_H)_f[2].y=2;
	if(arg.key == OIS::KC_J)_f[3].y=2;
	if(arg.key == OIS::KC_K)_f[4].y=2;

	if(arg.key == OIS::KC_N)
	{
		transVector.x++;
	}
	if(arg.key == OIS::KC_M)
	{
		transVector.x--;
	}

    mCameraMan->injectKeyDown(arg);
    return true;
}

bool OgreApp5::keyReleased( const OIS::KeyEvent &arg )
{
    mCameraMan->injectKeyUp(arg);
	if(arg.key == OIS::KC_1)pressKeyX( OgreApp5::skelKeyX,"B060",false,60);
	if(arg.key == OIS::KC_2)pressKeyX( OgreApp5::skelKeyX,"B061",false,61);
	if(arg.key == OIS::KC_3)pressKeyX( OgreApp5::skelKeyX,"B062",false,62);
	if(arg.key == OIS::KC_4)pressKeyX( OgreApp5::skelKeyX,"B063",false,63);
	if(arg.key == OIS::KC_5)pressKeyX( OgreApp5::skelKeyX,"B064",false,64);
	if(arg.key == OIS::KC_6)pressKeyX( OgreApp5::skelKeyX,"B065",false,65);
	if(arg.key == OIS::KC_7)pressKeyX( OgreApp5::skelKeyX,"B066",false,66);
	if(arg.key == OIS::KC_8)pressKeyX( OgreApp5::skelKeyX,"B067",false,67);
	if(arg.key == OIS::KC_9)pressKeyX( OgreApp5::skelKeyX,"B068",false,68);

	if(arg.key == OIS::KC_F)_f[0].y=10;
	if(arg.key == OIS::KC_G)_f[1].y=10;
	if(arg.key == OIS::KC_H)_f[2].y=10;
	if(arg.key == OIS::KC_J)_f[3].y=10;
	if(arg.key == OIS::KC_K)_f[4].y=10;


    return true;
}

bool OgreApp5::mouseMoved( const OIS::MouseEvent &arg )
{
    if (mTrayMgr->injectMouseMove(arg)) return true;
    mCameraMan->injectMouseMove(arg);
    return true;
}

bool OgreApp5::mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
{
    if (mTrayMgr->injectMouseDown(arg, id)) return true;
    mCameraMan->injectMouseDown(arg, id);
    return true;
}

bool OgreApp5::mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
{
    if (mTrayMgr->injectMouseUp(arg, id)) return true;
    mCameraMan->injectMouseUp(arg, id);
    return true;
}

//Adjust mouse clipping area
void OgreApp5::windowResized(Ogre::RenderWindow* rw)
{
    unsigned int width, height, depth;
    int left, top;
    rw->getMetrics(width, height, depth, left, top);

    const OIS::MouseState &ms = mMouse->getMouseState();
    ms.width = width;
    ms.height = height;
}

//Unattach OIS before window shutdown (very important under Linux)
void OgreApp5::windowClosed(Ogre::RenderWindow* rw)
{
    //Only close for window that created OIS (the main window in these demos)
    if( rw == mWindow )
    {
        if( mInputManager )
        {
            mInputManager->destroyInputObject( mMouse );
            mInputManager->destroyInputObject( mKeyboard );

            OIS::InputManager::destroyInputSystem(mInputManager);
            mInputManager = 0;
        }
    }
}




#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
#else
    int main(int argc, char *argv[])
#endif
    {
        // Create application object
        OgreApp5 app;

        try {
            app.go();
        } catch( Ogre::Exception& e ) {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
            MessageBox( NULL, e.getFullDescription().c_str(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
            std::cerr << "An exception has occured: " <<
                e.getFullDescription().c_str() << std::endl;
#endif
        }

        return 0;
    }

#ifdef __cplusplus
}
#endif
