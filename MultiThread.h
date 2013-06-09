// MultiThread.h : main header file for the MULTITHREAD application
//

#if !defined(AFX_MULTITHREAD_H__862AE721_0D12_4DF0_951B_F82D5455C92C__INCLUDED_)
#define AFX_MULTITHREAD_H__862AE721_0D12_4DF0_951B_F82D5455C92C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMultiThreadApp:
// See MultiThread.cpp for the implementation of this class
//

class CMultiThreadApp : public CWinApp
{
public:
	CMultiThreadApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiThreadApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMultiThreadApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTITHREAD_H__862AE721_0D12_4DF0_951B_F82D5455C92C__INCLUDED_)
