
// Student Record SystemDlg.cpp : implementation file
//

#include "pch.h"
#include <fstream>
#include <sstream>
#include <string>
#include "framework.h"
#include "Student Record System.h"
#include "Student Record SystemDlg.h"
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
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CStudentRecordSystemDlg dialog



CStudentRecordSystemDlg::CStudentRecordSystemDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_STUDENT_RECORD_SYSTEM_DIALOG, pParent)
	, m_name(_T(""))
	, m_roll(_T(""))
	, m_father(_T(""))
	, m_caste(_T(""))
	, m_district(_T(""))
	, m_gpa(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStudentRecordSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_name);
	DDX_Text(pDX, IDC_EDIT_ROLL, m_roll);
	DDX_Text(pDX, IDC_EDIT_FATHER, m_father);
	DDX_Text(pDX, IDC_EDIT_CASTE, m_caste);
	DDX_Text(pDX, IDC_EDIT_DISTRICT, m_district);
	DDX_Text(pDX, IDC_EDIT_GPA, m_gpa);
}

BEGIN_MESSAGE_MAP(CStudentRecordSystemDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CStudentRecordSystemDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CStudentRecordSystemDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CStudentRecordSystemDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CStudentRecordSystemDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CStudentRecordSystemDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CStudentRecordSystemDlg message handlers

BOOL CStudentRecordSystemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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
	SetAddMode(true);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CStudentRecordSystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CStudentRecordSystemDlg::OnPaint()
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
HCURSOR CStudentRecordSystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CStudentRecordSystemDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	if (m_name.IsEmpty() || m_roll.IsEmpty() || m_father.IsEmpty() ||
		m_caste.IsEmpty() || m_district.IsEmpty() || m_gpa.IsEmpty())
	{
		AfxMessageBox(_T("Please fill all fields."));
		return;
	}

	std::ofstream file("records.txt", std::ios::app);
	if (!file.is_open())
	{
		AfxMessageBox(_T("File could not be opened."));
		return;
	}

	file << CStringA(m_name).GetString() << ","
		<< CStringA(m_roll).GetString() << ","
		<< CStringA(m_father).GetString() << ","
		<< CStringA(m_caste).GetString() << ","
		<< CStringA(m_district).GetString() << ","
		<< CStringA(m_gpa).GetString() << "\n";
	file.close();

	AfxMessageBox(_T("Record added successfully!"));

	m_name = _T("");
	m_roll = _T("");
	m_father = _T("");
	m_caste = _T("");
	m_district = _T("");
	m_gpa = _T("");
	UpdateData(FALSE);
}
// File se saare records padho
void CStudentRecordSystemDlg::LoadRecords()
{
	m_records.clear();
	std::ifstream file("records.txt");
	std::string line;
	while (std::getline(file, line))
	{
		if (line.empty()) continue;
		std::stringstream ss(line);
		std::string f[6];
		for (int i = 0; i < 6; i++)
			std::getline(ss, f[i], ',');

		Student s;
		s.name = CString(f[0].c_str());
		s.roll = CString(f[1].c_str());
		s.father = CString(f[2].c_str());
		s.caste = CString(f[3].c_str());
		s.district = CString(f[4].c_str());
		s.gpa = CString(f[5].c_str());
		m_records.push_back(s);
	}
}

// Saare records dobara file mein likho
void CStudentRecordSystemDlg::SaveRecords()
{
	std::ofstream file("records.txt", std::ios::trunc);
	for (const Student& s : m_records)
	{
		file << CStringA(s.name).GetString() << ","
			<< CStringA(s.roll).GetString() << ","
			<< CStringA(s.father).GetString() << ","
			<< CStringA(s.caste).GetString() << ","
			<< CStringA(s.district).GetString() << ","
			<< CStringA(s.gpa).GetString() << "\n";
	}
}

// Ek record text boxes mein dikhao
void CStudentRecordSystemDlg::ShowRecord(int i)
{
	m_name = m_records[i].name;
	m_roll = m_records[i].roll;
	m_father = m_records[i].father;
	m_caste = m_records[i].caste;
	m_district = m_records[i].district;
	m_gpa = m_records[i].gpa;
	UpdateData(FALSE);
}

// add = true: sirf Add chalega, add = false: Update/Delete chalenge
void CStudentRecordSystemDlg::SetAddMode(bool add)
{
	GetDlgItem(IDC_BUTTON1)->EnableWindow(add ? TRUE : FALSE);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(add ? FALSE : TRUE);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(add ? FALSE : TRUE);
}
void CStudentRecordSystemDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	if (m_name.IsEmpty() || m_roll.IsEmpty() || m_father.IsEmpty() ||
		m_caste.IsEmpty() || m_district.IsEmpty() || m_gpa.IsEmpty())
	{
		AfxMessageBox(_T("Please fill all fields."));
		return;
	}

	bool found = false;
	for (auto& s : m_records)
	{
		if (s.roll == m_roll)   // Roll Number se record dhoondo
		{
			s.name = m_name;
			s.father = m_father;
			s.caste = m_caste;
			s.district = m_district;
			s.gpa = m_gpa;
			found = true;
			break;
		}
	}

	if (!found)
	{
		AfxMessageBox(_T("Roll number not found. Roll number cannot be changed."));
		return;
	}

	SaveRecords();
	AfxMessageBox(_T("Record updated successfully!"));
}

void CStudentRecordSystemDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	if (m_index < 0 || m_index >= (int)m_records.size())
		return;

	if (AfxMessageBox(_T("Delete this record?"), MB_YESNO | MB_ICONQUESTION) != IDYES)
		return;

	m_records.erase(m_records.begin() + m_index);
	SaveRecords();

	m_name = _T(""); m_roll = _T(""); m_father = _T("");
	m_caste = _T(""); m_district = _T(""); m_gpa = _T("");
	UpdateData(FALSE);

	m_index = -1;
	SetAddMode(true);
	AfxMessageBox(_T("Record deleted."));
}

void CStudentRecordSystemDlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	if (m_index == -1)
	{
		LoadRecords();
	}

	if (m_records.empty())
	{
		AfxMessageBox(_T("No records found."));
		return;
	}

	m_index = (m_index + 1) % (int)m_records.size();
	ShowRecord(m_index);
	SetAddMode(false);
}

void CStudentRecordSystemDlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
	m_index = -1;
	m_name = _T(""); m_roll = _T(""); m_father = _T("");
	m_caste = _T(""); m_district = _T(""); m_gpa = _T("");
	UpdateData(FALSE);
	SetAddMode(true);
}
