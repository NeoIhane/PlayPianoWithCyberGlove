Install ogre3d SDK and ogre AppWizard ทำตามเว็บด้านล่าง
http://www.ogre3d.org/tikiwiki/The+Complete+Blanks+Guide+To+Using+The+OGRE+SDK+AppWizard&structure=Development

 
ทำการ 
Include
$(OGRE_HOME)\include
$(OGRE_HOME)\include\OIS
$(OGRE_HOME)\include\OGRE
$(OGRE_HOME)\Samples\Common\include
$(OGRE_HOME)\boost_1_42
C:\Deverlop\Engine\SDL-1.2.14\include

Link  
$(OGRE_HOME)\lib\debug
$(OGRE_HOME)\boost_1_42\lib
C:\Deverlop\Engine\SDL-1.2.14\lib


Link->Input

OgreMain_d.lib
OIS_d.lib
Winmm.lib
SDL.lib
SDLmain.lib

ใส่ 
file.mesh และ  file.skeleton ที่  OgreSDK_vc10_v1-7-2\media\models
Texture ที่  OgreSDK_vc10_v1-7-2\media\materials\textures
file.material ที่ OgreSDK_vc10_v1-7-2\media\materials\scripts

แก้ Comport ที่ 
 CyberGlove::OpenSerial()//CyberGlove.cpp 
 OgreApp5::OpenSerial()//OgreApp5.cpp