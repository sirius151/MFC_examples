
// BasicControlDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BasicControl.h"
#include "BasicControlDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CBasicControlDlg dialog



CBasicControlDlg::CBasicControlDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBasicControlDlg::IDD, pParent)
	, rad_sum_(0)
	, rad_sub_(0)
	, rad_mul_(0)
	, rad_div_(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBasicControlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDT_VAL1, edt_val_1_);
	DDX_Control(pDX, IDC_EDT_VAL2, edt_val_2_);
	DDX_Control(pDX, IDC_EDT_RESULT, edt_result_);
	DDX_Control(pDX, IDC_BTN_CAL, btn_cal_);
	
	DDX_Check(pDX, IDC_RAD_SUM, rad_sum_);
	DDX_Check(pDX, IDC_RAD_SUB, rad_sub_);
	DDX_Check(pDX, IDC_RAD_MUL, rad_mul_);
	DDX_Check(pDX, IDC_RAD_DIV, rad_div_);
}

BEGIN_MESSAGE_MAP(CBasicControlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_CAL, &CBasicControlDlg::OnBnClickedBtnCal)
END_MESSAGE_MAP()


// CBasicControlDlg message handlers

BOOL CBasicControlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	rad_sum_ = 1;
	UpdateData(FALSE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBasicControlDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBasicControlDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBasicControlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CBasicControlDlg::OnBnClickedBtnCal()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CString str_val1 = _T("");
	CString str_val2 = _T("");
	
	edt_val_1_.GetWindowText(str_val1);
	edt_val_2_.GetWindowText(str_val2);

	float val1 = _tstof(str_val1);
	float val2 = _tstof(str_val2);
	float ret = 0.0;
	if (rad_sum_ == 1)
	{
		ret = val1 + val2;
	}
	else if (rad_sub_ == 1)
	{
		ret = val1 - val2;
	}
	else if (rad_mul_ == 1)
	{
		ret = val1 * val2;
	}
	else if (rad_div_ == 1)
	{
		if (val2 == 0)
		{
			MessageBox(_T("Value 2 cannot be zero"), _T("Error"), MB_ICONWARNING);
		}
		else
		{
			ret = val1 / val2;
		}
	}

	CString strRet;
	strRet.Format(_T("%f"), ret);
	edt_result_.SetWindowText(strRet);
	UpdateData(FALSE);
}
