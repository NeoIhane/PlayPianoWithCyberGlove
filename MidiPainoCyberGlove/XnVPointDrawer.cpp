#include "XnVPointDrawer.h"
#include "XnVDepthMessage.h"
#include <XnVHandPointContext.h>

//#ifdef USE_GLUT
//#include <GL/glut.h>
//#else
//#include "opengles.h"
//#endif

XnVPointDrawer::XnVPointDrawer(XnUInt32 nHistory, xn::DepthGenerator depthGenerator) :
	XnVPointControl("XnVPointDrawer"),
	m_nHistorySize(nHistory), m_DepthGenerator(depthGenerator), m_bDrawDM(false), m_bFrameID(false)
{
	m_pfPositionBuffer = new XnFloat[nHistory*3];
}
XnVPointDrawer::~XnVPointDrawer()
{
	std::map<XnUInt32, std::list<XnPoint3D> >::iterator iter;
	for (iter = m_History.begin(); iter != m_History.end(); ++iter)
	{
		iter->second.clear();
	}
	m_History.clear();

	delete []m_pfPositionBuffer;
}
void XnVPointDrawer::SetDepthMap(XnBool bDrawDM)
{
	m_bDrawDM = bDrawDM;
}
void XnVPointDrawer::SetFrameID(XnBool bFrameID)
{
	m_bFrameID = bFrameID;
}
static XnBool bShouldPrint = false;
void XnVPointDrawer::OnPointCreate(const XnVHandPointContext* cxt)
{
	printf("** %d\n", cxt->nID);
	m_History[cxt->nID].clear();
	bShouldPrint = true;
	OnPointUpdate(cxt);
	bShouldPrint = true;
}
void XnVPointDrawer::OnPointUpdate(const XnVHandPointContext* cxt)
{
	XnPoint3D ptProjective(cxt->ptPosition);

	if (bShouldPrint)printf("Point (%f,%f,%f)", ptProjective.X, ptProjective.Y, ptProjective.Z);
	m_DepthGenerator.ConvertRealWorldToProjective(1, &ptProjective, &ptProjective);
	if (bShouldPrint)printf(" -> (%f,%f,%f)\n", ptProjective.X, ptProjective.Y, ptProjective.Z);
	m_History[cxt->nID].push_front(ptProjective);
	if (m_History[cxt->nID].size() > m_nHistorySize)
		m_History[cxt->nID].pop_back();
	bShouldPrint = false;
}
void XnVPointDrawer::OnPointDestroy(XnUInt32 nID)
{
	m_History.erase(nID);
}

#define MAX_DEPTH 10000
float g_pDepthHist[MAX_DEPTH];
unsigned int getClosestPowerOfTwo(unsigned int n)
{
	unsigned int m = 2;
	while(m < n) m<<=1;

	return m;
}

// Colors for the points
XnFloat Colors[][3] =
{
	{1,0,0},	// Red
	{0,1,0},	// Green
	{0,0.5,1},	// Light blue
	{1,1,0},	// Yellow
	{1,0.5,0},	// Orange
	{1,0,1},	// Purple
	{1,1,1}		// White. reserved for the primary point
};
XnUInt32 nColors = 6;

void XnVPointDrawer::Draw() const
{
	std::map<XnUInt32, std::list<XnPoint3D> >::const_iterator PointIterator;

	// Go over each existing hand
	for (PointIterator = m_History.begin();
		PointIterator != m_History.end();
		++PointIterator)
	{
		// Clear buffer
		XnUInt32 nPoints = 0;
		XnUInt32 i = 0;
		XnUInt32 Id = PointIterator->first;

		// Go over all previous positions of current hand
		std::list<XnPoint3D>::const_iterator PositionIterator;
		for (PositionIterator = PointIterator->second.begin();
			PositionIterator != PointIterator->second.end();
			++PositionIterator, ++i)
		{
			// Add position to buffer
			XnPoint3D pt(*PositionIterator);
			m_pfPositionBuffer[3*i] = pt.X;
			m_pfPositionBuffer[3*i + 1] = pt.Y;
			m_pfPositionBuffer[3*i + 2] = 0;//pt.Z();
		/*	px=pt.X;
			py=pt.Y;
			pz=pt.Z;*/
			
		}
		
		// Set color
		XnUInt32 nColor = Id % nColors;
		XnUInt32 nSingle = GetPrimaryID();
		if (Id == GetPrimaryID())
			nColor = 6;
	}
}

// Handle a new Message
void XnVPointDrawer::Update(XnVMessage* pMessage)
{
	// PointControl's Update calls all callbacks for each hand
	XnVPointControl::Update(pMessage);

	if (m_bDrawDM)
	{
		// Draw depth map
		xn::DepthMetaData depthMD;
		m_DepthGenerator.GetMetaData(depthMD);
	}
	if (m_bFrameID)
	{
		// Print out frame ID
		xn::DepthMetaData depthMD;
		m_DepthGenerator.GetMetaData(depthMD);
	}

	// Draw hands
	Draw();
}

void PrintSessionState(SessionState eState)
{
	XnChar strLabel[200];

	switch (eState)
	{
	case IN_SESSION:
		sprintf(strLabel, "Tracking hands"); break;
	case NOT_IN_SESSION:
		sprintf(strLabel, "Perform click or wave gestures to track hand"); break;
	case QUICK_REFOCUS:
		sprintf(strLabel, "Raise your hand for it to be identified, or perform click or wave gestures"); break;
	}

}
