
// Symmetric _encryption_EVPDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "Symmetric _encryption_EVP.h"
#include "Symmetric _encryption_EVPDlg.h"
#include "afxdialogex.h"
#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <string.h>
#include<stdio.h>
#include <openssl/rand.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CSymmetricencryptionEVPDlg 对话框



CSymmetricencryptionEVPDlg::CSymmetricencryptionEVPDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SYMMETRIC_ENCRYPTION_EVP_DIALOG, pParent)
	, PlainP(_T(""))
	, CipherP(_T(""))
	, CipherW(_T(""))
	, DecryptedP(_T(""))
	, kouling(_T(""))
	, koulin2(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSymmetricencryptionEVPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, PlainP);
	DDX_Text(pDX, IDC_EDIT2, CipherP);
	DDX_Text(pDX, IDC_EDIT3, CipherW);
	DDX_Text(pDX, IDC_EDIT4, DecryptedP);
	DDX_Text(pDX, IDC_EDIT5, kouling);
	DDX_Text(pDX, IDC_EDIT6, koulin2);
}

BEGIN_MESSAGE_MAP(CSymmetricencryptionEVPDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_button, &CSymmetricencryptionEVPDlg::OnBnClickedbutton)
	ON_BN_CLICKED(IDC_BUTTON2, &CSymmetricencryptionEVPDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_jiemi, &CSymmetricencryptionEVPDlg::OnBnClickedjiemi)
	ON_BN_CLICKED(IDC_BUTTON5, &CSymmetricencryptionEVPDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON1, &CSymmetricencryptionEVPDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CSymmetricencryptionEVPDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON6, &CSymmetricencryptionEVPDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON8, &CSymmetricencryptionEVPDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON4, &CSymmetricencryptionEVPDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON7, &CSymmetricencryptionEVPDlg::OnBnClickedButton7)
END_MESSAGE_MAP()


// CSymmetricencryptionEVPDlg 消息处理程序

BOOL CSymmetricencryptionEVPDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CSymmetricencryptionEVPDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CSymmetricencryptionEVPDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CSymmetricencryptionEVPDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSymmetricencryptionEVPDlg::OnBnClickedbutton()  //选择加密文件的路径
{
	
	// TODO: 在此添加控件通知处理程序代码
	// 显示文件打开对话框
		CFileDialog dlg(TRUE, NULL, _T("*.*"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
			_T("All Files (*.*)|*.*||"));
	if (dlg.DoModal() != IDOK) return;
	//获取文件的绝对路径 
	UpdateData();
	 PlainP = dlg.GetPathName();
	 UpdateData(FALSE);

}


void CSymmetricencryptionEVPDlg::OnBnClickedButton2()//添加文件的保存路径
{
	// TODO: 在此添加控件通知处理程序代码
	//创建浏览文件夹对话框  
	BROWSEINFO bi;
	TCHAR path[MAX_PATH];
	ITEMIDLIST *pidl;
	//  
	bi.hwndOwner = this->m_hWnd;
	bi.pidlRoot = 0;
	bi.pszDisplayName = path;
	bi.lpszTitle = _T("请选择查找目录：");
	bi.ulFlags = BIF_RETURNONLYFSDIRS | BIF_EDITBOX | BIF_DONTGOBELOWDOMAIN;
	bi.lpfn = 0;
	bi.lParam = 0;
	bi.iImage = 0;
	if (pidl = SHBrowseForFolder(&bi))
	{
		SHGetPathFromIDList(pidl, path);
		UpdateData();
		CipherP = path;
		UpdateData(FALSE);
	}
}


void CSymmetricencryptionEVPDlg::OnBnClickedjiemi()
{
	// TODO: 在此添加控件通知处理程序代码
	// 显示文件打开对话框
	CFileDialog dlg1(TRUE, NULL, _T("*.*"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		_T("All Files (*.*)|*.*||"));
	if (dlg1.DoModal() != IDOK) return;
	//获取文件的绝对路径 
	UpdateData();
	CipherW = dlg1.GetPathName();
	UpdateData(FALSE);
}


void CSymmetricencryptionEVPDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	//创建浏览文件夹对话框  
	BROWSEINFO bi1;
	TCHAR path[MAX_PATH];
	ITEMIDLIST *pidl1;
	//  
	bi1.hwndOwner = this->m_hWnd;
	bi1.pidlRoot = 0;
	bi1.pszDisplayName = path;
	bi1.lpszTitle = _T("请选择查找目录：");
	bi1.ulFlags = BIF_RETURNONLYFSDIRS | BIF_EDITBOX | BIF_DONTGOBELOWDOMAIN;
	bi1.lpfn = 0;
	bi1.lParam = 0;
	bi1.iImage = 0;
	if (pidl1 = SHBrowseForFolder(&bi1))
	{
		SHGetPathFromIDList(pidl1, path);
		UpdateData();
		DecryptedP = path;
		UpdateData(false);
	}
}


void CSymmetricencryptionEVPDlg::OnBnClickedButton1() //输入口令
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	MessageBox(_T("输入口令成功！"), 0, 0);
	UpdateData(FALSE);
}
void CSymmetricencryptionEVPDlg::handleErrors(void)
{
	ERR_print_errors_fp(stderr);
	abort();
}
int CSymmetricencryptionEVPDlg::encryptAES(unsigned char *PlainF, unsigned char *key,
	unsigned char *iv, unsigned char *CipherF, unsigned char *salt, int salt_len)
{
	EVP_CIPHER_CTX *ctx;
	unsigned char ciphertext[1184];  //保存密文的缓冲区
	int len;
	unsigned char plaintext[1184];   //保存原文的缓冲区

	int plaintext_len;   //读取文件件的长度

	long ciphertext_len = 0; //密文长度
	FILE *fpIn;
	FILE *fpOut;
	//打开待加密文件
	fpIn = fopen((const char *)PlainF, "rb");
	if (fpIn == NULL)
	{
		printf("，Error!\n");
		exit(0);
	}
	//打开保存密文的文件
	fpOut = fopen((const char *)CipherF, "wb");
	if (fpOut == NULL)
	{
		printf("，Error!\n");
		fclose(fpIn);
		exit(0);
	}
	/* Create and initialise the context 创建并初始化上下文*/
	if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

	/* Initialise the encryption operation. IMPORTANT - ensure you use a key
	 * and IV size appropriate for your cipher
	 * In this example we are using 256 bit AES (i.e. a 256 bit key). The
	 * IV size for *most* modes is the same as the block size. For AES this
	 * is 128 bits初始化加密操作。重要信息 - 确保使用
   适合您的密码的密钥*和IV大小
   *在此示例中，我们使用256位AES（即256位密钥）。
   *大多数*模式的* IV大小与块大小相同。对于AES，此
   *为128位*
	 */
	if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
		handleErrors();
	/* Provide the message to be encrypted, and obtain the encrypted output.
	 * EVP_EncryptUpdate can be called multiple times if necessary
	 提供要加密的消息，并获取加密输出。
   *如果需要，可以多次调用EVP_EncryptUpdate
	 */
	EVP_CIPHER_CTX_set_padding(ctx, EVP_PADDING_PKCS7);
	/*
	将盐值保存到文件的开头
	*/
	const char *flag ="#*#";
	fwrite(salt, 1, salt_len, fpOut);
	fwrite(flag, sizeof(char), 3, fpOut);
	int line = 0;
	for (;;)
	{
		plaintext_len = fread(plaintext, 1, 1024, fpIn);

		if (plaintext_len <= 0)//读取原文结束
			break;
		//加密
		if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
		{
			fclose(fpIn);
			fclose(fpOut);
			handleErrors();
		}
		ciphertext_len += len;
		line = len;
		fwrite(ciphertext, 1, len, fpOut);//保存密文到文件
	}
	//加密结束
	EVP_EncryptFinal_ex(ctx, ciphertext + len, &len);

	fwrite(ciphertext + line, 1, len, fpOut);//保存密文到文件
	ciphertext_len += len;


	fclose(fpIn);
	fclose(fpOut);

	/* Clean up */
	EVP_CIPHER_CTX_free(ctx);
	return 0;
}


void CSymmetricencryptionEVPDlg::OnBnClickedButton3() //AES256加密
{
	// TODO: 在此添加控件通知处理程序代码
	const int  ITERRATIVE_ROUND_FOR_KEY = 3;
	unsigned char key[EVP_MAX_KEY_LENGTH];      //秘钥
	unsigned char iv[EVP_MAX_IV_LENGTH];         //初始向量
	USES_CONVERSION;
	;
 //CString转char*

	//进行转换
	CString KL = kouling;

	char *passwd = T2A(KL.GetBuffer(0));
	KL.ReleaseBuffer();

	unsigned char salt[1028];

	RAND_bytes(salt, sizeof(passwd)+1024); //生成盐值salt

	const EVP_CIPHER *type;
	OpenSSL_add_all_ciphers();
	OpenSSL_add_all_digests();
	type = EVP_aes_256_cbc();      //AES加密算法
	EVP_BytesToKey(
		type,
		EVP_md5(),
		salt,
		(const unsigned char *)passwd,
		(int)strlen(passwd),
		ITERRATIVE_ROUND_FOR_KEY,
		key,
		iv
	);
	/* Encrypt the plaintext */
	int salt_len = strlen((const char *)salt);
	int ciphertext_len;
    char* PlainF = T2A(PlainP.GetBuffer(0));
	PlainP.ReleaseBuffer();
	
	CString path = PlainP;
	int local = path.ReverseFind('.');
	int len = path.GetLength();
	path.Delete(0, local);
	CString name("\\Encrypt_F");
	CString P = CipherP + name + path;
	//进行转换
	char *CipherF = T2A(P.GetBuffer(0));
	P.ReleaseBuffer();
	ciphertext_len = encryptAES((unsigned char *)PlainF, key, iv, (unsigned char *)CipherF,salt,salt_len);
	MessageBox(_T("加密成功！"), 0, 0);
}


void CSymmetricencryptionEVPDlg::OnBnClickedButton6()  //AES256 解密
{
	// TODO: 在此添加控件通知处理程序代码
	// TODO: 在此添加控件通知处理程序代码
	const int  ITERRATIVE_ROUND_FOR_KEY = 3;
	unsigned char key[EVP_MAX_KEY_LENGTH];      //秘钥
	unsigned char iv[EVP_MAX_IV_LENGTH];         //初始向量
	USES_CONVERSION;
	;
	//CString转char*

	   //进行转换
	CString KL = koulin2;

	char *passwd = T2A(KL.GetBuffer(0));
	KL.ReleaseBuffer();
	unsigned char salt[1028];

	int salt_len = 0;

	Get_salt((char *)salt, &salt_len);  //从文本中取回盐值
	const EVP_CIPHER *type;
	OpenSSL_add_all_ciphers();
	OpenSSL_add_all_digests();
	type = EVP_aes_256_cbc();      //AES加密算法
	EVP_BytesToKey(
		type,
		EVP_md5(),
		salt,
		(const unsigned char *)passwd,
		(int)strlen(passwd),
		ITERRATIVE_ROUND_FOR_KEY,
		key,
		iv
	);

	char* CipherF = T2A(CipherW.GetBuffer(0));   //带解密文件路径
	CipherW.ReleaseBuffer();

	CString path = CipherW;                       //解密好的明文保存路径
	int local = path.ReverseFind('.');
	int len = path.GetLength();
	path.Delete(0, local);
	CString name("\\Decrypt_F");
	CString P = DecryptedP + name + path;
	//进行转换
	char *DecryptedF = T2A(P.GetBuffer(0));
	P.ReleaseBuffer();

	int decryptedtext_len;
	decryptedtext_len = decryptAES((unsigned char *)CipherF, key, iv, (unsigned char *)DecryptedF,salt_len);
	MessageBox(_T("解密成功！"), 0, 0);
}
void CSymmetricencryptionEVPDlg::Get_salt(char * salt, int * salt_len)
{
	USES_CONVERSION;
	char *Cipher = T2A(CipherW.GetBuffer(0));
	CipherW.ReleaseBuffer();

	FILE *stream;
	char ch;
	if ((stream = fopen(Cipher, "rb")) == NULL)
		exit(0);
	ch = fgetc(stream);
	for (;;)
	{
		if (ch != '#')
		{
			*salt =ch;
			*salt++;
			(*salt_len)++;
			ch = fgetc(stream);
		}
		else
		{
			char s1= fgetc(stream);
			char s2= fgetc(stream);
			if (s1 == '*'&&s2 == '#')
			{
				break;
			}
			else
			{
				*salt = '#';
				*salt++;
				(*salt_len)++;
				*salt = s1;
				*salt++;
				(*salt_len)++;
				*salt = s2;
				*salt++;
				(*salt_len)++;
				ch = fgetc(stream);
			}
			
		}
	}
	fclose(stream);
	
}

void CSymmetricencryptionEVPDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	MessageBox(_T("输入口令成功！"), 0, 0);
	UpdateData(FALSE);
}

int CSymmetricencryptionEVPDlg::decryptAES(unsigned char *CipherF, unsigned char *key,  //AES解密函数
	unsigned char * iv, unsigned char * DecryptedF, int salt_len)
{
	EVP_CIPHER_CTX *ctx;
	unsigned char ciphertext[1184];  //保存密文的缓冲区
	int len;
	unsigned char plaintext[1184];   //保存原文的缓冲区

	int ciphertext_len;   //读取文件件的长度

	long plaintext_len = 0; //明文长度
	FILE *fpIn;
	FILE *fpOut;
	//打开加密文件
	fpIn = fopen((const char *)CipherF, "rb");
	if (fpIn == NULL)
	{
		printf("，Error!\n");
		exit(0);
	}
	//打开保存明文的文件
	fpOut = fopen((const char *)DecryptedF, "wb");
	if (fpOut == NULL)
	{
		
		fclose(fpIn);
		exit(0);
	}
	/* Create and initialise the context 创建并初始化上下文*/
	if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

	/* Initialise the encryption operation. IMPORTANT - ensure you use a key
	 * and IV size appropriate for your cipher
	 * In this example we are using 256 bit AES (i.e. a 256 bit key). The
	 * IV size for *most* modes is the same as the block size. For AES this
	 * is 128 bits初始化加密操作。重要信息 - 确保使用
   适合您的密码的密钥*和IV大小
   *在此示例中，我们使用256位AES（即256位密钥）。
   *大多数*模式的* IV大小与块大小相同。对于AES，此
   *为128位*
	 */
	if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
		handleErrors();

	EVP_CIPHER_CTX_set_padding(ctx, EVP_PADDING_PKCS7);
	/* Provide the message to be encrypted, and obtain the encrypted output.
	 * EVP_EncryptUpdate can be called multiple times if necessary
	 提供要加密的消息，并获取加密输出。
   *如果需要，可以多次调用EVP_EncryptUpdate
	 */

	unsigned char salt[1028];
	fread(salt, 1,(salt_len+3), fpIn);
	int line = 0;//最后一块的大小
	for (;;)
	{
		ciphertext_len = fread(ciphertext, 1, 1024, fpIn);
		if (ciphertext_len <= 0)//读取原文结束
			break;

		if (1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
		{
			fclose(fpIn);
			fclose(fpOut);
			handleErrors();
		}
		plaintext_len += len;
		fwrite(plaintext, 1, len, fpOut);//保存密文到文件
		line = len;


	}
	//解密结束


	EVP_DecryptFinal_ex(ctx, plaintext + len, &len);


	fwrite(plaintext + line, 1, len, fpOut);//保存密文到文件
	plaintext_len += len;


	fclose(fpIn);
	fclose(fpOut);

	/* Clean up */
	EVP_CIPHER_CTX_free(ctx);
	return 0;
}

void CSymmetricencryptionEVPDlg::OnBnClickedButton4()   //DES 加密
{
	// TODO: 在此添加控件通知处理程序代码
	// TODO: 在此添加控件通知处理程序代码
	const int  ITERRATIVE_ROUND_FOR_KEY = 3;
	unsigned char key[EVP_MAX_KEY_LENGTH];      //秘钥
	unsigned char iv[EVP_MAX_IV_LENGTH];         //初始向量
	USES_CONVERSION;
	;
	//CString转char*

	   //进行转换
	CString KL = kouling;

	char *passwd = T2A(KL.GetBuffer(0));
	KL.ReleaseBuffer();

	unsigned char salt[1028];

	RAND_bytes(salt, sizeof(passwd) + 1024); //生成盐值salt

	const EVP_CIPHER *type;
	OpenSSL_add_all_ciphers();
	OpenSSL_add_all_digests();
	type = EVP_des_cbc();                               //DES加密算法
	EVP_BytesToKey(
		type,
		EVP_md5(),
		salt,
		(const unsigned char *)passwd,
		(int)strlen(passwd),
		ITERRATIVE_ROUND_FOR_KEY,
		key,
		iv
	);
	/* Encrypt the plaintext */
	int salt_len = strlen((const char *)salt);
	int ciphertext_len;
	char* PlainF = T2A(PlainP.GetBuffer(0));
	PlainP.ReleaseBuffer();

	CString path = PlainP;
	int local = path.ReverseFind('.');
	int len = path.GetLength();
	path.Delete(0, local);
	CString name("\\Encrypt_F");
	CString P = CipherP + name + path;
	//进行转换
	char *CipherF = T2A(P.GetBuffer(0));
	P.ReleaseBuffer();
	ciphertext_len = encryptDES((unsigned char *)PlainF, key, iv, (unsigned char *)CipherF, salt, salt_len);
	MessageBox(_T("加密成功！"), 0, 0);

}
/*
用于DES加密的函数
*/
int CSymmetricencryptionEVPDlg::encryptDES(unsigned char *PlainF, unsigned char *key,
	unsigned char *iv, unsigned char *CipherF, unsigned char *salt, int salt_len)
{
	EVP_CIPHER_CTX *ctx;
	unsigned char ciphertext[1184];  //保存密文的缓冲区
	int len;
	unsigned char plaintext[1184];   //保存原文的缓冲区

	int plaintext_len;   //读取文件件的长度

	long ciphertext_len = 0; //密文长度
	FILE *fpIn;
	FILE *fpOut;
	//打开待加密文件
	fpIn = fopen((const char *)PlainF, "rb");
	if (fpIn == NULL)
	{
		printf("，Error!\n");
		exit(0);
	}
	//打开保存密文的文件
	fpOut = fopen((const char *)CipherF, "wb");
	if (fpOut == NULL)
	{
		printf("，Error!\n");
		fclose(fpIn);
		exit(0);
	}
	/* Create and initialise the context 创建并初始化上下文*/
	if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

	/* Initialise the encryption operation. IMPORTANT - ensure you use a key
	 * and IV size appropriate for your cipher
	 * In this example we are using 256 bit AES (i.e. a 256 bit key). The
	 * IV size for *most* modes is the same as the block size. For AES this
	 * is 128 bits初始化加密操作。重要信息 - 确保使用
   适合您的密码的密钥*和IV大小
   *在此示例中，我们使用256位AES（即256位密钥）。
   *大多数*模式的* IV大小与块大小相同。对于AES，此
   *为128位*
	 */
	if (1 != EVP_EncryptInit_ex(ctx, EVP_des_cbc(), NULL, key, iv))              //des加密方法
		handleErrors();
	/* Provide the message to be encrypted, and obtain the encrypted output.
	 * EVP_EncryptUpdate can be called multiple times if necessary
	 提供要加密的消息，并获取加密输出。
   *如果需要，可以多次调用EVP_EncryptUpdate
	 */
	EVP_CIPHER_CTX_set_padding(ctx, EVP_PADDING_PKCS7);
	/*
	将盐值保存到文件的开头
	*/
	const char *flag = "#*#";
	fwrite(salt, 1, salt_len, fpOut);
	fwrite(flag, sizeof(char), 3, fpOut);
	int line = 0;
	for (;;)
	{
		plaintext_len = fread(plaintext, 1, 1024, fpIn);

		if (plaintext_len <= 0)//读取原文结束
			break;
		//加密
		if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
		{
			fclose(fpIn);
			fclose(fpOut);
			handleErrors();
		}
		ciphertext_len += len;
		line = len;
		fwrite(ciphertext, 1, len, fpOut);//保存密文到文件
	}
	//加密结束
	EVP_EncryptFinal_ex(ctx, ciphertext + len, &len);

	fwrite(ciphertext + line, 1, len, fpOut);//保存密文到文件
	ciphertext_len += len;


	fclose(fpIn);
	fclose(fpOut);

	/* Clean up */
	EVP_CIPHER_CTX_free(ctx);
	return 0;
}

/*
//DES解密函数

1*/
int CSymmetricencryptionEVPDlg::decryptDES(unsigned char *CipherF, unsigned char *key,  
	unsigned char * iv, unsigned char * DecryptedF, int salt_len)
{
	EVP_CIPHER_CTX *ctx;
	unsigned char ciphertext[1184];  //保存密文的缓冲区
	int len;
	unsigned char plaintext[1184];   //保存原文的缓冲区

	int ciphertext_len;   //读取文件件的长度

	long plaintext_len = 0; //明文长度
	FILE *fpIn;
	FILE *fpOut;
	//打开加密文件
	fpIn = fopen((const char *)CipherF, "rb");
	if (fpIn == NULL)
	{
		printf("，Error!\n");
		exit(0);
	}
	//打开保存明文的文件
	fpOut = fopen((const char *)DecryptedF, "wb");
	if (fpOut == NULL)
	{

		fclose(fpIn);
		exit(0);
	}
	/* Create and initialise the context 创建并初始化上下文*/
	if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

	/* Initialise the encryption operation. IMPORTANT - ensure you use a key
	 * and IV size appropriate for your cipher
	 * In this example we are using 256 bit AES (i.e. a 256 bit key). The
	 * IV size for *most* modes is the same as the block size. For AES this
	 * is 128 bits初始化加密操作。重要信息 - 确保使用
   适合您的密码的密钥*和IV大小
   *在此示例中，我们使用256位AES（即256位密钥）。
   *大多数*模式的* IV大小与块大小相同。对于AES，此
   *为128位*
	 */
	if (1 != EVP_DecryptInit_ex(ctx, EVP_des_cbc(), NULL, key, iv))
		handleErrors();

	EVP_CIPHER_CTX_set_padding(ctx, EVP_PADDING_PKCS7);
	/* Provide the message to be encrypted, and obtain the encrypted output.
	 * EVP_EncryptUpdate can be called multiple times if necessary
	 提供要加密的消息，并获取加密输出。
   *如果需要，可以多次调用EVP_EncryptUpdate
	 */

	unsigned char salt[1028];
	fread(salt, 1, (salt_len + 3), fpIn);
	int line = 0;//最后一块的大小
	for (;;)
	{
		ciphertext_len = fread(ciphertext, 1, 1024, fpIn);
		if (ciphertext_len <= 0)//读取原文结束
			break;

		if (1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
		{
			fclose(fpIn);
			fclose(fpOut);
			handleErrors();
		}
		plaintext_len += len;
		fwrite(plaintext, 1, len, fpOut);//保存密文到文件
		line = len;


	}
	//解密结束


	EVP_DecryptFinal_ex(ctx, plaintext + len, &len);


	fwrite(plaintext + line, 1, len, fpOut);//保存密文到文件
	plaintext_len += len;


	fclose(fpIn);
	fclose(fpOut);

	/* Clean up */
	EVP_CIPHER_CTX_free(ctx);

	return 0;
}


void CSymmetricencryptionEVPDlg::OnBnClickedButton7()    //des解密事件
{
	// TODO: 在此添加控件通知处理程序代码
	// TODO: 在此添加控件通知处理程序代码
	// TODO: 在此添加控件通知处理程序代码
	const int  ITERRATIVE_ROUND_FOR_KEY = 3;
	unsigned char key[EVP_MAX_KEY_LENGTH];      //秘钥
	unsigned char iv[EVP_MAX_IV_LENGTH];         //初始向量
	USES_CONVERSION;
	;
	//CString转char*

	   //进行转换
	CString KL = koulin2;

	char *passwd = T2A(KL.GetBuffer(0));
	KL.ReleaseBuffer();
	unsigned char salt[1028];

	int salt_len = 0;

	Get_salt((char *)salt, &salt_len);  //从文本中取回盐值
	const EVP_CIPHER *type;
	OpenSSL_add_all_ciphers();
	OpenSSL_add_all_digests();
	type = EVP_des_cbc();      //AES加密算法
	EVP_BytesToKey(
		type,
		EVP_md5(),
		salt,
		(const unsigned char *)passwd,
		(int)strlen(passwd),
		ITERRATIVE_ROUND_FOR_KEY,
		key,
		iv
	);

	char* CipherF = T2A(CipherW.GetBuffer(0));   //带解密文件路径
	CipherW.ReleaseBuffer();

	CString path = CipherW;                       //解密好的明文保存路径
	int local = path.ReverseFind('.');
	int len = path.GetLength();
	path.Delete(0, local);
	CString name("\\Decrypt_F");
	CString P = DecryptedP + name + path;
	//进行转换
	char *DecryptedF = T2A(P.GetBuffer(0));
	P.ReleaseBuffer();

	long decryptedtext_len;
	decryptedtext_len = decryptDES((unsigned char *)CipherF, key, iv, (unsigned char *)DecryptedF, salt_len);
	MessageBox(_T("解密成功！"), 0, 0);
}
