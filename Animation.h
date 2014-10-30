// Animation.h : main header file for the ANIMATION application
//

#if !defined(AFX_ANIMATION_H__B3526A06_EBA3_4836_9169_9652B21B7C2D__INCLUDED_)
#define AFX_ANIMATION_H__B3526A06_EBA3_4836_9169_9652B21B7C2D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CAnimationApp:
// See Animation.cpp for the implementation of this class
//

class CAnimationApp : public CWinApp
{
public:
	CAnimationApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAnimationApp)
	public:
	virtual BOOL InitInstance();
	virtual BOOL OnIdle(LONG lCount);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CAnimationApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	DWORD m_dwSplashTime;
	BOOL  nFlag;
	HWND  aviWnd;
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANIMATION_H__B3526A06_EBA3_4836_9169_9652B21B7C2D__INCLUDED_)
