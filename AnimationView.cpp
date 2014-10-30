// AnimationView.cpp : implementation of the CAnimationView class
//

#include "stdafx.h"
#include "Animation.h"

#include "AnimationDoc.h"
#include "AnimationView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAnimationView

IMPLEMENT_DYNCREATE(CAnimationView, CView)

BEGIN_MESSAGE_MAP(CAnimationView, CView)
	//{{AFX_MSG_MAP(CAnimationView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAnimationView construction/destruction

CAnimationView::CAnimationView()
{
	// TODO: add construction code here

}

CAnimationView::~CAnimationView()
{
}

BOOL CAnimationView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CAnimationView drawing

void CAnimationView::OnDraw(CDC* pDC)
{
	CAnimationDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CAnimationView printing

BOOL CAnimationView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CAnimationView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CAnimationView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CAnimationView diagnostics

#ifdef _DEBUG
void CAnimationView::AssertValid() const
{
	CView::AssertValid();
}

void CAnimationView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAnimationDoc* CAnimationView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAnimationDoc)));
	return (CAnimationDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAnimationView message handlers
