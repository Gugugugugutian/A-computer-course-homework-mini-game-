//最高的头文件
#include <iostream>
#include <easyx.h>
#include <conio.h>
#include <graphics.h>

#include<windows.h>
#include <mmsystem.h>
#include<dsound.h>
#pragma comment(lib, "WINMM.LIB")
using namespace std;

int rW = GetSystemMetrics(SM_CXSCREEN); // 屏幕宽度 像素
int rH = GetSystemMetrics(SM_CYSCREEN); // 屏幕高度 像素	
int Width = rW * 0.8;
int Height = rH * 0.8;
int Length = rW * 0.8 / 32;
//这里用int类变量Width表示游戏区域宽度，Height表示游戏区域高度。
//游戏过程中，需要把游戏区域划分为32*18（暂定）的一个棋盘界面，每一个正方形格子的边长用Length表示

IMAGE SPACEPIC;
IMAGE PLAYERPICW;
IMAGE PLAYERPICA;
IMAGE PLAYERPICS;
IMAGE PLAYERPICD;

IMAGE WALLPIC;
IMAGE CUPPIC;
IMAGE LAVAPIC;

IMAGE DIESCREEN;
IMAGE DIEBLOCK;
IMAGE WHOLEBLUE;
IMAGE WINSCREEN;