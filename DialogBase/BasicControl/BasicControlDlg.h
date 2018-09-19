
// BasicControlDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CBasicControlDlg dialog
class CBasicControlDlg : public CDialogEx
{
// Construction
public:
	CBasicControlDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_BASICCONTROL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRadio3();
protected:
	CEdit edt_val_1_;
	CEdit edt_val_2_;
	CEdit edt_result_;
	CButton btn_cal_;
	int rad_sum_;
	int rad_sub_;
	int rad_mul_;
	int rad_div_;
public:
	afx_msg void OnBnClickedBtnCal();
};
