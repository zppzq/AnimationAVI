// Animation.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Animation.h"

#include "MainFrm.h"
#include "AnimationDoc.h"
#include "AnimationView.h"

#include "HyperLink.h"

#include <vfw.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAnimationApp

BEGIN_MESSAGE_MAP(CAnimationApp, CWinApp)
	//{{AFX_MSG_MAP(CAnimationApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAnimationApp construction

CAnimationApp::CAnimationApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CAnimationApp object

CAnimationApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CAnimationApp initialization

BOOL CAnimationApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CAnimationDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CAnimationView));
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it.


	DWORD dwMCIWndStyle;
	dwMCIWndStyle = WS_MAXIMIZE|WS_POPUP|WS_VISIBLE|MCIWNDF_NOPLAYBAR
		|MCIWNDF_NOERRORDLG|MCIWNDF_NOTIFYERROR|MCIWNDF_NOTIFYMODE;
	// 产生MCI窗口
	aviWnd=::MCIWndCreate(NULL,AfxGetInstanceHandle(),dwMCIWndStyle,NULL);
	// 
	int CX = GetSystemMetrics(SM_CXSCREEN);
	int CY = GetSystemMetrics(SM_CYSCREEN);
	// 播放动画界面
	MCIWndOpen(aviWnd,"beyond.avi",NULL);
	nFlag=TRUE;
	::MoveWindow(aviWnd,0,0,CX,CY,TRUE);
	m_dwSplashTime=::GetCurrentTime();
	MCIWndPlay(aviWnd);

	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	
	m_pMainWnd->DragAcceptFiles();

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	CHyperLink	m_mail;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	DDX_Control(pDX, IDC_MAIL, m_mail);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CAnimationApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CAnimationApp message handlers


BOOL CAnimationApp::OnIdle(LONG lCount) 
{
	// TODO: Add your specialized code here and/or call the base class
	BOOL bResult = CWinApp::OnIdle(lCount);

	if (aviWnd!=NULL&&nFlag)
	{
		if (::GetCurrentTime()-m_dwSplashTime>10000) {
			MCIWndStop(aviWnd);
			::DestroyWindow(aviWnd);
			m_pMainWnd->ShowWindow(SW_NORMAL);
			m_pMainWnd->UpdateWindow();
			nFlag=FALSE;
			aviWnd=NULL;
			bResult=FALSE;
		}
		else
		{
			bResult=TRUE;
		}
	}
	return bResult;
}

BOOL CAnimationApp::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if (aviWnd!=NULL&&
		(pMsg->message==WM_KEYDOWN||
		pMsg->message==WM_SYSKEYDOWN||
		pMsg->message==WM_LBUTTONDOWN||
		pMsg->message==WM_RBUTTONDOWN||
		pMsg->message==WM_MBUTTONDOWN||
		pMsg->message==WM_NCLBUTTONDOWN||
		pMsg->message==WM_NCRBUTTONDOWN||
		pMsg->message==WM_NCMBUTTONDOWN)) 
	{
		MCIWndStop(aviWnd);
		::DestroyWindow(aviWnd);
//		m_pMainWnd->ShowWindow(SW_NORMAL);
//		m_pMainWnd->UpdateWindow();
		nFlag=FALSE;
		aviWnd=NULL;
		return TRUE;
	}
	return CWinApp::PreTranslateMessage(pMsg);
}

BOOL CAboutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_mail.SetURL(_T("hexw@mail2.nyist.net"));
	m_mail.SetUnderline(FALSE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
