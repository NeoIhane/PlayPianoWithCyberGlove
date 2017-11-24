
#ifndef _XnVPointDrawer_h_
#define _XnVPointDrawer_h_

#include <map>
#include <list>
#include <XnCppWrapper.h>
#include <XnVPointControl.h>

typedef enum
{
	IN_SESSION,
	NOT_IN_SESSION,
	QUICK_REFOCUS
} SessionState;

void PrintSessionState(SessionState eState);
class XnVPointDrawer : public XnVPointControl
{
public:
	XnVPointDrawer(XnUInt32 nHistorySize, xn::DepthGenerator depthGenerator);
	virtual ~XnVPointDrawer();
	void Update(XnVMessage* pMessage);
	void OnPointCreate(const XnVHandPointContext* cxt);
	void OnPointUpdate(const XnVHandPointContext* cxt);
	void OnPointDestroy(XnUInt32 nID);
	void Draw() const;
	void SetDepthMap(XnBool bDrawDM);
	void SetFrameID(XnBool bFrameID);
protected:
	XnUInt32 m_nHistorySize;
	//std::map<XnUInt32, std::list<XnPoint3D> > m_History;
	xn::DepthGenerator m_DepthGenerator;
	XnFloat* m_pfPositionBuffer;

	XnBool m_bDrawDM;
	XnBool m_bFrameID;
public:
		std::map<XnUInt32, std::list<XnPoint3D> > m_History;
		float px,py,pz;
};

#endif
