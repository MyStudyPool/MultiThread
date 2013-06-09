// MultiThreadDlg.h : header file
//

#if !defined(AFX_MULTITHREADDLG_H__311574C5_4A79_46A2_9E23_C5323A515567__INCLUDED_)
#define AFX_MULTITHREADDLG_H__311574C5_4A79_46A2_9E23_C5323A515567__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//参数结构体的例子
struct BeepInfo
{
	DWORD Freq;
	DWORD Duration;
};

/////////////////////////////////////////////////////////////////////////////
// CMultiThreadDlg dialog

class CMultiThreadDlg : public CDialog
{
// Construction
public:
	CMultiThreadDlg(CWnd* pParent = NULL);	// standard constructor
	BeepInfo info;

// Dialog Data
	//{{AFX_DATA(CMultiThreadDlg)
	enum { IDD = IDD_MULTITHREAD_DIALOG };
	CButton	m_Button;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiThreadDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMultiThreadDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTITHREADDLG_H__311574C5_4A79_46A2_9E23_C5323A515567__INCLUDED_)
