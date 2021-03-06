
// Symmetric _encryption_EVPDlg.h: 头文件
//

#pragma once


// CSymmetricencryptionEVPDlg 对话框
class CSymmetricencryptionEVPDlg : public CDialogEx
{
// 构造
public:
	CSymmetricencryptionEVPDlg(CWnd* pParent = nullptr);	// 标准构造函数

public:
	
	int encryptAES(unsigned char *PlainF, unsigned char *key,
		unsigned char *iv, unsigned char *CipherF, unsigned char *salt,int salt_len);
	int encryptDES(unsigned char *PlainF, unsigned char *key,
		unsigned char *iv, unsigned char *CipherF, unsigned char *salt, int salt_len);
	 void handleErrors(void);
	 void Get_salt( char *salt,int *salt_len);
	int  decryptAES(unsigned char *CipherF, unsigned char *key, unsigned char * iv, unsigned char * DecryptedF,int salt_len);
	int  decryptDES(unsigned char *CipherF, unsigned char *key, unsigned char * iv, unsigned char * DecryptedF, int salt_len);
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SYMMETRIC_ENCRYPTION_EVP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedbutton();
	afx_msg void OnBnClickedButton2();
	CString PlainP;
	CString CipherP;
	CString CipherW;
	CString DecryptedP;
	afx_msg void OnBnClickedjiemi();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton1();
	CString kouling;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton6();
	CString koulin2;
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton7();
};
