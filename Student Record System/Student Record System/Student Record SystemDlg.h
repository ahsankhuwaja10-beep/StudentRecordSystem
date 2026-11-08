
// Student Record SystemDlg.h : header file
//

#pragma once
#include <vector>

struct Student
{
	CString name, roll, father, caste, district, gpa;
};

// CStudentRecordSystemDlg dialog
class CStudentRecordSystemDlg : public CDialogEx
{
// Construction
public:
	CStudentRecordSystemDlg(CWnd* pParent = nullptr);	// standard constructor
	std::vector<Student> m_records;   // saare records
	int m_index = -1;                 // abhi kaunsa record dikh raha hai
	void LoadRecords();
	void SaveRecords();
	void ShowRecord(int i);
	void SetAddMode(bool add);
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STUDENT_RECORD_SYSTEM_DIALOG };
#endif

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
	CString m_name;
	CString m_roll;
	CString m_father;
	CString m_caste;
	CString m_district;
	CString m_gpa;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
};
