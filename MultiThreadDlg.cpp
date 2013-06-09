// MultiThreadDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MultiThread.h"
#include "MultiThreadDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMultiThreadDlg dialog

CMultiThreadDlg::CMultiThreadDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMultiThreadDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMultiThreadDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMultiThreadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMultiThreadDlg)
	DDX_Control(pDX, IDC_BUTTON, m_Button);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMultiThreadDlg, CDialog)
	//{{AFX_MSG_MAP(CMultiThreadDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON, OnButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMultiThreadDlg message handlers




//全局变量控制线程
BOOL Running = FALSE;






BOOL CMultiThreadDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMultiThreadDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMultiThreadDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//线程实现体
UINT ThreadBody(LPVOID lpParam)
{
	BeepInfo * info = (BeepInfo *)lpParam;
	while(Running)
		Beep(info->Freq, info->Duration);
	return 0;
}



void CMultiThreadDlg::OnButton() 
{
	// TODO: Add your control notification handler code here
	if (Running == FALSE)
	{
		Running = TRUE;
		m_Button.SetWindowText("停止");

		info.Freq = 2000;
		info.Duration = 200;

		//启动线程第一个参数是调用的线程体函数名，第二个是参数的地址，
		AfxBeginThread(ThreadBody, &info);
	} 
	else
	{
		Running = FALSE;
		m_Button.SetWindowText("启动");
	}
	UpdateData(FALSE);
}

