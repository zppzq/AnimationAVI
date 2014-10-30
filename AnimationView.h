// AnimationView.h : interface of the CAnimationView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ANIMATIONVIEW_H__03E27CA7_F11D_4097_BF74_072B89107692__INCLUDED_)
#define AFX_ANIMATIONVIEW_H__03E27CA7_F11D_4097_BF74_072B89107692__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CAnimationView : public CView
{
protected: // create from serialization only
	CAnimationView();
	DECLARE_DYNCREATE(CAnimationView)

// Attributes
public:
	CAnimationDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAnimationView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAnimationView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CAnimationView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in AnimationView.cpp
inline CAnimationDoc* CAnimationView::GetDocument()
   { return (CAnimationDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANIMATIONVIEW_H__03E27CA7_F11D_4097_BF74_072B89107692__INCLUDED_)
