//��ߵ�ͷ�ļ�
#include <iostream>
#include <easyx.h>
#include <conio.h>
#include <graphics.h>

#include<windows.h>
#include <mmsystem.h>
#include<dsound.h>
#pragma comment(lib, "WINMM.LIB")
using namespace std;

int rW = GetSystemMetrics(SM_CXSCREEN); // ��Ļ��� ����
int rH = GetSystemMetrics(SM_CYSCREEN); // ��Ļ�߶� ����	
int Width = rW * 0.8;
int Height = rH * 0.8;
int Length = rW * 0.8 / 32;
//������int�����Width��ʾ��Ϸ�����ȣ�Height��ʾ��Ϸ����߶ȡ�
//��Ϸ�����У���Ҫ����Ϸ���򻮷�Ϊ32*18���ݶ�����һ�����̽��棬ÿһ�������θ��ӵı߳���Length��ʾ

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