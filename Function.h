#include "Head.h"
//一些函数的定义，主要是初级函数。

void wholescreen() {
	HWND hwnd = initgraph(rW, rH); // 初始化绘图窗口并获取窗口句柄（以 EasyX 为例）
	LONG l_WinStyle = GetWindowLong(hwnd, GWL_STYLE); // 获取窗口信息
	// 设置窗口信息 最大化 取消标题栏及边框
	SetWindowLong(hwnd, GWL_STYLE, (l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);// 直接修改窗口样式
	SetWindowPos(hwnd, HWND_TOP, 0, 0, rW, rH, 0);
	cout << "Whole Screen Graph created" << endl;
};	 
//创建全屏的游戏窗口
void StartScreenShow() {
	IMAGE StratScreenImage;
	loadimage(&StratScreenImage, L"TestBK.jpg", rW, rH, false);
	putimage(0, 0, &StratScreenImage);
}
//展示开始界面的图片。展示图片的正确函数在这里，之后可以抄走。
void GamingScreenShow() {
	IMAGE GamingScreenImage;
	loadimage(&GamingScreenImage, L"GamingBK.jpg", rW, rH, false);
	putimage(0, 0, &GamingScreenImage);
}
//展示游戏界面
void InitialGameArea();
//根据界面的大小，决定游戏区域和显示的大小。同时创建对象，初始化游戏区域。