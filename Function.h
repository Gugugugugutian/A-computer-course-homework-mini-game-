#include "Head.h"
//һЩ�����Ķ��壬��Ҫ�ǳ���������

void wholescreen() {
	HWND hwnd = initgraph(rW, rH); // ��ʼ����ͼ���ڲ���ȡ���ھ������ EasyX Ϊ����
	LONG l_WinStyle = GetWindowLong(hwnd, GWL_STYLE); // ��ȡ������Ϣ
	// ���ô�����Ϣ ��� ȡ�����������߿�
	SetWindowLong(hwnd, GWL_STYLE, (l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);// ֱ���޸Ĵ�����ʽ
	SetWindowPos(hwnd, HWND_TOP, 0, 0, rW, rH, 0);
	cout << "Whole Screen Graph created" << endl;
};	 
//����ȫ������Ϸ����
void StartScreenShow() {
	IMAGE StratScreenImage;
	loadimage(&StratScreenImage, L"TestBK.jpg", rW, rH, false);
	putimage(0, 0, &StratScreenImage);
}
//չʾ��ʼ�����ͼƬ��չʾͼƬ����ȷ���������֮����Գ��ߡ�
void GamingScreenShow() {
	IMAGE GamingScreenImage;
	loadimage(&GamingScreenImage, L"GamingBK.jpg", rW, rH, false);
	putimage(0, 0, &GamingScreenImage);
}
//չʾ��Ϸ����
void InitialGameArea();
//���ݽ���Ĵ�С��������Ϸ�������ʾ�Ĵ�С��ͬʱ�������󣬳�ʼ����Ϸ����