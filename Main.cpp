#include "Function.h"
//主程序在这个文件中，以及一些一般函数的定义

int main() {
	wholescreen();
	PlaySound(L"BGMSOUND.wav", NULL, SND_ASYNC | SND_LOOP);
	const int MaxLevelNumber = 14;
	RECT r = { rW * 0.1, rH * 0.8, rW * 0.9, rH * 0.9 };
	outtextxy(rW * 0.4 + 30, rH * 0.4, L"A SIMPLE PUZZLE GAME BY GUTIAN.");
	outtextxy(50, 50, L"Lava Texture from: Minecraft.");
	outtextxy(50, 70, L"Music and sounds from: I Wanna Be The Guy.");
	outtextxy(50, 90, L"Win Picture from: MopeMope _ LeaF.");
	drawtext(_T("请按任意键开始游戏"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	_getch();

	drawtext(_T("加载中……0%"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	ItemInTheGame Coordinate[32][18];
	loadimage(&SPACEPIC, L"SPACE.jpg", Length, Length, false);
	loadimage(&WALLPIC, L"WALL.jpg", Length, Length, false);
	loadimage(&PLAYERPICW, L"UP-P.jpg", Length, Length, false);
	loadimage(&PLAYERPICA, L"LEFT-P.jpg", Length, Length, false);
	loadimage(&PLAYERPICD, L"RIGHT-P.jpg", Length, Length, false);
	loadimage(&PLAYERPICS, L"DOWN-P.jpg", Length, Length, false);
	loadimage(&LAVAPIC, L"LAVA.jpg", Length, Length, false);
	loadimage(&CUPPIC, L"CUP.jpg", Length, Length, false);
	loadimage(&DIEBLOCK, L"DIEBLOCK.jpg", Length, Length, false);
	loadimage(&DIESCREEN, L"DIESCREEN.jpg", rW, rH, false);
	loadimage(&WINSCREEN, L"WINSCREEN.jpg", rW, rH, false);
	loadimage(&WHOLEBLUE, L"WHOLEBLUE.jpg", rW, rH, false);

	bool WhetherWinOrNot = false;
	static int WinPlayerNumber = 0;
	static int LevelNumber = 1;

	StartScreenShow();
	_getch();
	GamingScreenShow();

	while (1) {
		WhetherWinOrNot = false;
		bool Die = false;
		InitialGameArea();
		//初始化游戏界面
		for (int i = 0; i <= 31; i++) {
			for (int j = 0; j <= 17; j++) {
				ItemInTheGame Temp_item(i, j, SPACEBLOCK, SPACE, D);
				Coordinate[i][j] = Temp_item;
				Temp_item.~ItemInTheGame();
			}
		};
		//创建网格式坐标

		Coordinate[0][1].SetClass(WALL, STOP);
		Coordinate[0][3].SetClass(WALL, STOP);
		Coordinate[0][7].SetClass(WALL, STOP);
		Coordinate[0][17].SetClass(WALL, STOP);
		Coordinate[1][3].SetClass(WALL, STOP);
		Coordinate[1][5].SetClass(WALL, STOP);
		Coordinate[1][11].SetClass(WALL, STOP);
		Coordinate[1][13].SetClass(WALL, STOP);
		Coordinate[1][17].SetClass(WALL, STOP);
		Coordinate[2][5].SetClass(WALL, STOP);
		Coordinate[2][13].SetClass(WALL, STOP);
		Coordinate[3][0].SetClass(WALL, STOP);
		Coordinate[3][15].SetClass(WALL, STOP);
		Coordinate[3][16].SetClass(WALL, STOP);
		Coordinate[4][10].SetClass(WALL, STOP);
		Coordinate[4][7].SetClass(WALL, STOP);
		Coordinate[4][9].SetClass(WALL, STOP);
		Coordinate[4][16].SetClass(WALL, STOP);
		Coordinate[5][1].SetClass(WALL, STOP);
		Coordinate[5][3].SetClass(WALL, STOP);
		Coordinate[5][9].SetClass(WALL, STOP);
		Coordinate[6][4].SetClass(WALL, STOP);
		Coordinate[6][9].SetClass(WALL, STOP);
		Coordinate[6][11].SetClass(WALL, STOP);
		Coordinate[6][17].SetClass(WALL, STOP);
		Coordinate[7][8].SetClass(WALL, STOP);
		Coordinate[7][9].SetClass(WALL, STOP);
		Coordinate[7][13].SetClass(WALL, STOP);
		Coordinate[7][14].SetClass(WALL, STOP);
		Coordinate[8][0].SetClass(WALL, STOP);
		Coordinate[8][1].SetClass(WALL, STOP);
		Coordinate[8][2].SetClass(WALL, STOP);
		Coordinate[8][3].SetClass(WALL, STOP);
		Coordinate[8][4].SetClass(WALL, STOP);
		Coordinate[8][5].SetClass(WALL, STOP);
		Coordinate[8][6].SetClass(WALL, STOP);
		Coordinate[8][7].SetClass(WALL, STOP);
		Coordinate[8][12].SetClass(WALL, STOP);
		Coordinate[9][1].SetClass(WALL, STOP);
		Coordinate[9][2].SetClass(WALL, STOP);
		Coordinate[9][3].SetClass(WALL, STOP);
		Coordinate[9][4].SetClass(WALL, STOP);
			Coordinate[9][5].SetClass(WALL, STOP);
		Coordinate[9][15].SetClass(WALL, STOP);
		Coordinate[10][1].SetClass(WALL, STOP);
		Coordinate[11][7].SetClass(WALL, STOP);
		Coordinate[11][8].SetClass(WALL, STOP);
		Coordinate[11][9].SetClass(WALL, STOP);
		Coordinate[11][15].SetClass(WALL, STOP);
		Coordinate[12][4].SetClass(WALL, STOP);
		Coordinate[12][5].SetClass(WALL, STOP);
		Coordinate[12][7].SetClass(WALL, STOP);
		Coordinate[12][14].SetClass(WALL, STOP);
		Coordinate[13][6].SetClass(WALL, STOP);
		Coordinate[13][13].SetClass(WALL, STOP);
		Coordinate[14][16].SetClass(WALL, STOP);
		Coordinate[14][17].SetClass(WALL, STOP);
		Coordinate[15][1].SetClass(WALL, STOP);
		Coordinate[15][8].SetClass(WALL, STOP);
		Coordinate[16][8].SetClass(WALL, STOP);
		Coordinate[16][15].SetClass(WALL, STOP);
		Coordinate[17][5].SetClass(WALL, STOP);
		Coordinate[18][2].SetClass(WALL, STOP);
		Coordinate[18][9].SetClass(WALL, STOP);
		Coordinate[18][10].SetClass(WALL, STOP);
		Coordinate[18][13].SetClass(WALL, STOP);
		Coordinate[18][14].SetClass(WALL, STOP);
		Coordinate[18][15].SetClass(WALL, STOP);
		Coordinate[18][16].SetClass(WALL, STOP);
		Coordinate[18][17].SetClass(WALL, STOP);
		Coordinate[19][0].SetClass(WALL, STOP);
		Coordinate[19][1].SetClass(WALL, STOP);
		Coordinate[19][2].SetClass(WALL, STOP);
		Coordinate[19][7].SetClass(WALL, STOP);
		Coordinate[19][11].SetClass(WALL, STOP);
		Coordinate[19][12].SetClass(WALL, STOP);
		Coordinate[20][2].SetClass(WALL, STOP);
		Coordinate[20][4].SetClass(WALL, STOP);
		Coordinate[21][4].SetClass(WALL, STOP);
		Coordinate[21][10].SetClass(WALL, STOP);
		Coordinate[21][16].SetClass(WALL, STOP);
		Coordinate[21][17].SetClass(WALL, STOP);
		Coordinate[22][4].SetClass(WALL, STOP);
		Coordinate[22][11].SetClass(WALL, STOP);
		Coordinate[23][2].SetClass(WALL, STOP);
		Coordinate[23][9].SetClass(WALL, STOP);
		Coordinate[23][12].SetClass(WALL, STOP);
		Coordinate[24][3].SetClass(WALL, STOP);
		Coordinate[24][7].SetClass(WALL, STOP);
		Coordinate[24][10].SetClass(WALL, STOP);
		Coordinate[24][13].SetClass(WALL, STOP);
		Coordinate[24][14].SetClass(WALL, STOP);
		Coordinate[25][11].SetClass(WALL, STOP);
		Coordinate[25][15].SetClass(WALL, STOP);
		Coordinate[25][17].SetClass(WALL, STOP);
		Coordinate[26][12].SetClass(WALL, STOP);
		Coordinate[27][4].SetClass(WALL, STOP);
		Coordinate[27][13].SetClass(WALL, STOP);
		Coordinate[27][14].SetClass(WALL, STOP);
		Coordinate[27][15].SetClass(WALL, STOP);
		Coordinate[27][17].SetClass(WALL, STOP);
		Coordinate[28][4].SetClass(WALL, STOP);
		Coordinate[28][9].SetClass(WALL, STOP);
		Coordinate[28][14].SetClass(WALL, STOP);
		Coordinate[29][2].SetClass(WALL, STOP);
		Coordinate[29][3].SetClass(WALL, STOP);
		Coordinate[29][4].SetClass(WALL, STOP);
		Coordinate[29][5].SetClass(WALL, STOP);
		Coordinate[29][6].SetClass(WALL, STOP);
		Coordinate[29][12].SetClass(WALL, STOP);
		Coordinate[30][1].SetClass(WALL, STOP);
		Coordinate[30][2].SetClass(WALL, STOP);
		Coordinate[30][3].SetClass(WALL, STOP);
		Coordinate[30][8].SetClass(WALL, STOP);
		Coordinate[30][10].SetClass(WALL, STOP);
		Coordinate[30][16].SetClass(WALL, STOP);
		Coordinate[31][5].SetClass(WALL, STOP);
		Coordinate[31][6].SetClass(WALL, STOP);
		Coordinate[31][12].SetClass(WALL, STOP);
		Coordinate[31][14].SetClass(WALL, STOP);

		Coordinate[0][5].SetClass(LAVA, DIE);
		Coordinate[0][6].SetClass(LAVA, DIE);
		Coordinate[0][7].SetClass(LAVA, DIE);
		Coordinate[0][8].SetClass(LAVA, DIE);
		Coordinate[0][9].SetClass(LAVA, DIE);
		Coordinate[1][6].SetClass(LAVA, DIE);
		Coordinate[2][0].SetClass(LAVA, DIE);
		Coordinate[2][6].SetClass(LAVA, DIE);
		Coordinate[3][1].SetClass(LAVA, DIE);
		Coordinate[3][5].SetClass(LAVA, DIE);
		Coordinate[3][6].SetClass(LAVA, DIE);
		Coordinate[3][7].SetClass(LAVA, DIE);
		Coordinate[3][11].SetClass(LAVA, DIE);
		Coordinate[3][12].SetClass(LAVA, DIE);
		Coordinate[3][13].SetClass(LAVA, DIE);
		Coordinate[3][14].SetClass(LAVA, DIE);
		Coordinate[4][5].SetClass(LAVA, DIE);
		Coordinate[4][6].SetClass(LAVA, DIE);
		Coordinate[4][11].SetClass(LAVA, DIE);
		Coordinate[4][12].SetClass(LAVA, DIE);
				Coordinate[4][13].SetClass(WALL, STOP);
		Coordinate[4][14].SetClass(LAVA, DIE);
		Coordinate[4][15].SetClass(LAVA, DIE);
		Coordinate[5][5].SetClass(LAVA, DIE);
		Coordinate[5][6].SetClass(LAVA, DIE);
		Coordinate[5][4].SetClass(LAVA, DIE);
		Coordinate[5][11].SetClass(LAVA, DIE);
				Coordinate[5][12].SetClass(WALL, STOP);
		Coordinate[6][16].SetClass(LAVA, DIE);
		Coordinate[7][15].SetClass(LAVA, DIE);
		Coordinate[7][16].SetClass(LAVA, DIE);
		Coordinate[7][17].SetClass(LAVA, DIE);
		Coordinate[8][11].SetClass(LAVA, DIE);
		Coordinate[8][13].SetClass(LAVA, DIE);
		Coordinate[8][14].SetClass(LAVA, DIE);
		Coordinate[8][15].SetClass(LAVA, DIE);
		Coordinate[8][16].SetClass(LAVA, DIE);
		Coordinate[8][17].SetClass(LAVA, DIE);
		Coordinate[9][11].SetClass(LAVA, DIE);
		Coordinate[9][17].SetClass(LAVA, DIE);
		Coordinate[10][11].SetClass(LAVA, DIE);
		Coordinate[11][10].SetClass(LAVA, DIE);
		Coordinate[11][11].SetClass(LAVA, DIE);
		Coordinate[12][3].SetClass(LAVA, DIE);
		Coordinate[13][1].SetClass(LAVA, DIE);
		Coordinate[13][2].SetClass(LAVA, DIE);
		Coordinate[13][3].SetClass(LAVA, DIE);
			//Coordinate[13][4].SetClass(LAVA, DIE);
			//Coordinate[13][5].SetClass(LAVA, DIE);
		Coordinate[13][17].SetClass(LAVA, DIE);
			//Coordinate[14][5].SetClass(LAVA, DIE);
		Coordinate[14][6].SetClass(LAVA, DIE);
			//Coordinate[14][10].SetClass(LAVA, DIE);
			//Coordinate[14][11].SetClass(LAVA, DIE);
		Coordinate[14][12].SetClass(LAVA, DIE);
			Coordinate[15][5].SetClass(WALL, STOP);
		Coordinate[15][6].SetClass(LAVA, DIE);
		Coordinate[15][9].SetClass(LAVA, DIE);
		Coordinate[15][10].SetClass(LAVA, DIE);
		Coordinate[15][11].SetClass(LAVA, DIE);
		Coordinate[15][12].SetClass(LAVA, DIE);
		Coordinate[15][15].SetClass(LAVA, DIE);
		Coordinate[16][5].SetClass(LAVA, DIE);
		Coordinate[16][6].SetClass(LAVA, DIE);
		Coordinate[16][7].SetClass(LAVA, DIE);
		Coordinate[16][11].SetClass(LAVA, DIE);
		Coordinate[17][6].SetClass(LAVA, DIE);
		Coordinate[17][7].SetClass(LAVA, DIE);
		Coordinate[17][8].SetClass(LAVA, DIE);
		Coordinate[18][3].SetClass(LAVA, DIE);
		Coordinate[18][4].SetClass(LAVA, DIE);
		Coordinate[18][5].SetClass(LAVA, DIE);
		Coordinate[18][6].SetClass(LAVA, DIE);
		Coordinate[18][7].SetClass(LAVA, DIE);
		Coordinate[18][8].SetClass(LAVA, DIE);
		Coordinate[19][8].SetClass(LAVA, DIE);
		Coordinate[20][0].SetClass(LAVA, DIE);
		Coordinate[20][1].SetClass(LAVA, DIE);
		Coordinate[20][8].SetClass(LAVA, DIE);
		Coordinate[20][13].SetClass(LAVA, DIE);
		Coordinate[21][0].SetClass(LAVA, DIE);
			Coordinate[21][8].SetClass(WALL, STOP);
			Coordinate[21][9].SetClass(WALL, STOP);
		Coordinate[21][13].SetClass(LAVA, DIE);
		Coordinate[23][3].SetClass(LAVA, DIE);
		Coordinate[23][4].SetClass(LAVA, DIE);
		Coordinate[23][5].SetClass(LAVA, DIE);
		Coordinate[23][6].SetClass(LAVA, DIE);
		Coordinate[23][7].SetClass(LAVA, DIE);
		Coordinate[23][8].SetClass(LAVA, DIE);
		Coordinate[24][5].SetClass(LAVA, DIE);
		Coordinate[24][8].SetClass(LAVA, DIE);
		Coordinate[24][9].SetClass(LAVA, DIE);
		Coordinate[26][0].SetClass(LAVA, DIE);
		Coordinate[26][1].SetClass(LAVA, DIE);
		Coordinate[26][2].SetClass(LAVA, DIE);
		Coordinate[26][3].SetClass(LAVA, DIE);
		//Coordinate[27][0].SetClass(LAVA, DIE);
		Coordinate[28][5].SetClass(LAVA, DIE);
		Coordinate[28][6].SetClass(LAVA, DIE);
		Coordinate[28][7].SetClass(LAVA, DIE);
		Coordinate[28][8].SetClass(LAVA, DIE);
		Coordinate[28][10].SetClass(LAVA, DIE);
		Coordinate[28][11].SetClass(LAVA, DIE);
		Coordinate[28][15].SetClass(LAVA, DIE);
		Coordinate[28][16].SetClass(LAVA, DIE);
		Coordinate[28][17].SetClass(LAVA, DIE);
		Coordinate[29][15].SetClass(LAVA, DIE);
		Coordinate[29][16].SetClass(LAVA, DIE);
		Coordinate[29][17].SetClass(LAVA, DIE);
		Coordinate[30][17].SetClass(LAVA, DIE);
		Coordinate[31][13].SetClass(LAVA, DIE);
		Coordinate[31][17].SetClass(LAVA, DIE);
		//建造地图。这个游戏目前只有一个地图，但在同一个地图上进行了多个关卡。

		int CupNumber = 999;
		outtextxy(0, 18 * Length, _T("欢迎游玩！WASD 移动；Q 暂停游戏。只要有一个角色碰到奖杯，你就赢了，可是所有角色都不能死亡哦！"));
		switch (LevelNumber)
		{
		case 1:
			PlaySound(L"BGMSOUND3.wav", NULL, SND_ASYNC | SND_LOOP);
			CupNumber = 3;
			Coordinate[0][0].SetClass(PLAYER, YOU);
			Coordinate[0][2].SetClass(PLAYER, YOU);
			Coordinate[0][4].SetClass(PLAYER, YOU);
			Coordinate[3][2].SetClass(CUP, WIN);
			Coordinate[3][3].SetClass(CUP, WIN);
			Coordinate[3][4].SetClass(CUP, WIN);
			break;
		case 2:
			PlaySound(L"BGMSOUND3.wav", NULL, SND_ASYNC | SND_LOOP);
			CupNumber = 2;
			Coordinate[3][2].SetClass(WALL, STOP);
			Coordinate[3][3].SetClass(WALL, STOP);
			Coordinate[3][4].SetClass(WALL, STOP);
			Coordinate[4][2].SetClass(PLAYER, YOU);
			Coordinate[4][3].SetClass(PLAYER, YOU);
			Coordinate[4][4].SetClass(PLAYER, YOU);
			Coordinate[6][3].SetClass(CUP, WIN);
			Coordinate[7][4].SetClass(CUP, WIN);
			break;
		case 3:
			PlaySound(L"BGMSOUND3.wav", NULL, SND_ASYNC | SND_LOOP);
			CupNumber = 3;
			Coordinate[6][3].SetClass(WALL, STOP);
			Coordinate[7][3].SetClass(WALL, STOP);
			Coordinate[7][4].SetClass(WALL, STOP);
			Coordinate[6][5].SetClass(PLAYER, YOU);
			Coordinate[7][6].SetClass(PLAYER, YOU);
			Coordinate[7][5].SetClass(PLAYER, YOU);
			Coordinate[1][9].SetClass(CUP, WIN);
			Coordinate[2][9].SetClass(CUP, WIN);
			Coordinate[3][9].SetClass(CUP, WIN);
			break;
		case 4:
			PlaySound(L"BGMSOUND3.wav", NULL, SND_ASYNC | SND_LOOP);
			CupNumber = 3;
			Coordinate[1][9].SetClass(WALL, STOP);
			Coordinate[2][9].SetClass(WALL, STOP);
			Coordinate[3][9].SetClass(WALL, STOP);
			Coordinate[1][10].SetClass(PLAYER, YOU);
			Coordinate[2][10].SetClass(PLAYER, YOU);
			Coordinate[3][10].SetClass(PLAYER, YOU);
			Coordinate[1][14].SetClass(CUP, WIN);
			Coordinate[1][15].SetClass(CUP, WIN);
			Coordinate[1][16].SetClass(CUP, WIN);
			break;
		case 5:
			PlaySound(L"BGMSOUND3.wav", NULL, SND_ASYNC | SND_LOOP);
			CupNumber = 3;
			Coordinate[1][14].SetClass(WALL, STOP);
			Coordinate[1][15].SetClass(WALL, STOP);
			Coordinate[1][16].SetClass(WALL, STOP);
			Coordinate[2][14].SetClass(PLAYER, YOU);
			Coordinate[2][15].SetClass(PLAYER, YOU);
			Coordinate[2][16].SetClass(PLAYER, YOU);
			Coordinate[8][9].SetClass(CUP, WIN);
			Coordinate[9][9].SetClass(CUP, WIN);
			Coordinate[10][9].SetClass(CUP, WIN);
			break;
		case 6:
			PlaySound(L"BGMSOUND4.wav", NULL, SND_ASYNC | SND_LOOP);
			CupNumber = 2;
			Coordinate[8][9].SetClass(WALL, STOP);
			Coordinate[9][9].SetClass(WALL, STOP);
			Coordinate[10][9].SetClass(WALL, STOP);
			Coordinate[8][8].SetClass(PLAYER, YOU);
			Coordinate[9][8].SetClass(PLAYER, YOU);
			Coordinate[10][8].SetClass(PLAYER, YOU);
			Coordinate[10][2].SetClass(CUP, WIN);
			Coordinate[11][3].SetClass(CUP, WIN);
			break;
		case 7:
			PlaySound(L"BGMSOUND4.wav", NULL, SND_ASYNC | SND_LOOP);
			CupNumber = 3;
			Coordinate[10][1].SetClass(WALL, STOP);
			Coordinate[10][2].SetClass(WALL, STOP);
			Coordinate[11][3].SetClass(WALL, STOP);
			Coordinate[11][1].SetClass(PLAYER, YOU);
			Coordinate[11][2].SetClass(PLAYER, YOU);
			Coordinate[12][2].SetClass(PLAYER, YOU);
			Coordinate[18][0].SetClass(CUP, WIN);
			Coordinate[14][3].SetClass(CUP, WIN);
			Coordinate[15][3].SetClass(CUP, WIN);
			break;
		case 8:
			PlaySound(L"BGMSOUND4.wav", NULL, SND_ASYNC | SND_LOOP);
			CupNumber = 2;
			Coordinate[13][7].SetClass(PLAYER, YOU);
			Coordinate[14][7].SetClass(PLAYER, YOU);
			Coordinate[15][7].SetClass(PLAYER, YOU);
			Coordinate[14][8].SetClass(PLAYER, YOU);
			Coordinate[9][14].SetClass(CUP, WIN);
			Coordinate[10][15].SetClass(CUP, WIN);
			Coordinate[11][14].SetClass(WALL, STOP);
			Coordinate[10][11].SetClass(WALL, STOP);
			Coordinate[11][11].SetClass(WALL, STOP);
			break;
		case 9:
			PlaySound(L"BGMSOUND4.wav", NULL, SND_ASYNC | SND_LOOP);
			CupNumber = 4;
			Coordinate[10][15].SetClass(WALL, STOP);
			Coordinate[9][16].SetClass(PLAYER, YOU);
			Coordinate[10][16].SetClass(PLAYER, YOU);
			Coordinate[10][17].SetClass(PLAYER, YOU);
			Coordinate[11][16].SetClass(PLAYER, YOU);
			Coordinate[15][16].SetClass(CUP, WIN);
			Coordinate[15][17].SetClass(CUP, WIN);
			Coordinate[16][9].SetClass(CUP, WIN);
			Coordinate[16][10].SetClass(CUP, WIN);
			break;
		case 10:
			PlaySound(L"BGMSOUND2.wav", NULL, SND_ASYNC | SND_LOOP);
			CupNumber = 3;
			Coordinate[19][9].SetClass(PLAYER, YOU);
			Coordinate[19][16].SetClass(PLAYER, YOU);
			Coordinate[19][10].SetClass(PLAYER, YOU);
			Coordinate[19][17].SetClass(PLAYER, YOU);
			Coordinate[25][16].SetClass(CUP, WIN);
			Coordinate[24][17].SetClass(CUP, WIN);
			Coordinate[24][15].SetClass(CUP, WIN);
			break;
		case 11:
			PlaySound(L"BGMSOUND2.wav", NULL, SND_ASYNC | SND_LOOP);
			CupNumber = 3;
			Coordinate[25][16].SetClass(WALL, STOP);
			Coordinate[27][16].SetClass(PLAYER, YOU);
			Coordinate[26][16].SetClass(PLAYER, YOU);
			Coordinate[26][17].SetClass(PLAYER, YOU);
			Coordinate[26][15].SetClass(PLAYER, YOU);
			Coordinate[21][5].SetClass(CUP, WIN);
			Coordinate[21][7].SetClass(CUP, WIN);
			Coordinate[21][6].SetClass(CUP, WIN);
			break;
		case 12:
			PlaySound(L"BGMSOUND2.wav", NULL, SND_ASYNC | SND_LOOP);
			CupNumber = 2;
			Coordinate[21][5].SetClass(WALL, STOP);
			Coordinate[21][6].SetClass(WALL, STOP);
			Coordinate[21][7].SetClass(WALL, STOP);
			Coordinate[20][6].SetClass(PLAYER, YOU);
			Coordinate[20][5].SetClass(PLAYER, YOU);
			Coordinate[20][7].SetClass(PLAYER, YOU);
			Coordinate[24][2].SetClass(CUP, WIN);
			Coordinate[25][3].SetClass(CUP, WIN);
			break;
		case 13:
			PlaySound(L"BGMSOUND2.wav", NULL, SND_ASYNC | SND_LOOP);
			CupNumber = 3;
			Coordinate[25][3].SetClass(WALL, STOP);
			Coordinate[25][4].SetClass(PLAYER, YOU);
			Coordinate[25][5].SetClass(PLAYER, YOU);
			Coordinate[24][4].SetClass(PLAYER, YOU);
			Coordinate[26][9].SetClass(CUP, WIN);
			Coordinate[25][8].SetClass(CUP, WIN);
			Coordinate[27][10].SetClass(CUP, WIN);
			break;
		case 14:
			PlaySound(L"BGMSOUND.wav", NULL, SND_ASYNC | SND_LOOP);
			CupNumber = 3;
			Coordinate[25][7].SetClass(WALL, STOP);
			Coordinate[26][8].SetClass(WALL, STOP);
			Coordinate[27][9].SetClass(WALL, STOP);
			Coordinate[25][8].SetClass(PLAYER, YOU);
			Coordinate[26][9].SetClass(PLAYER, YOU);
			Coordinate[27][10].SetClass(PLAYER, YOU);
			Coordinate[28][3].SetClass(CUP, WIN);
			Coordinate[27][3].SetClass(CUP, WIN);
			Coordinate[31][16].SetClass(CUP, WIN);
			break;
		default:
			break;
		}
		//根据关卡的不同，对游戏进行初始化。

		while (1) {
			char ch = _getch();
			Die = false;
			if (ch == 'Q' || ch == 'q') {
				outtextxy(0, 18 * Length, _T("游戏已暂停。再按一次Q退出或重新开始，按其他任意按键继续游戏。请注意：游戏进度不会保存,别点错啦"));
				char ch2 = _getch();
				if (ch2 == 'Q' || ch2 == 'q') {
					outtextxy(0, 18 * Length, _T("———————————选项：R 重新开始游戏———其他任意键 退出游戏——————————————"));
					break;
				}
				else
					outtextxy(0, 18 * Length, _T("欢迎游玩！WASD 移动；Q 暂停游戏。只要有一个角色碰到奖杯，你就赢了，可是所有角色都不能死亡哦！"));
			};  //双击Q退出游戏
				//先检测是否退出游戏

			int x = 0;
			for (int i = 0; i <= 31; i++) {
				for (int j = 0; j <= 17; j++) {
					if (Coordinate[i][j].GetSituation() == YOU)
						x++;
				}
			}
			//对PLAYER进行计数操作
			if (x == 0)
				Die = true;
			//如果游戏界面内没有玩家，则判定为死亡。

			int* NOWX = new int[x]();
			int* NOWY = new int[x]();
			int* NEXTX = new int[x]();
			int* NEXTY = new int[x]();
			int const m = x;
			enum direction* NewDirection = new enum direction[x];
			enum BlockClass* NewClass = new enum BlockClass[x];
			enum BlockSituation* NewSituation = new enum BlockSituation[x];
			//创建数组，存放每一个PLAYER的移动方式
			x = 0;
			for (int i = 0; i <= 31; i++) {
				for (int j = 0; j <= 17; j++) {
					if (Coordinate[i][j].GetSituation() == YOU) {
						int NowX = Coordinate[i][j].GetPX();
						int NowY = Coordinate[i][j].GetPY();
						int NextX = NowX;
						int NextY = NowY;
						enum direction new_dir;

						int NumOfSpace[4];		//左右上下 0123
						NumOfSpace[0] = NumOfSpace[1] = NumOfSpace[2] = NumOfSpace[3] = 0;
						int a = 0;
						for (a = i - 1; a >= 0; a--) {
							if (Coordinate[a][j].GetSituation() != STOP && Coordinate[a][j].GetSituation() != YOU) NumOfSpace[0]++;
							if (Coordinate[a][j].GetSituation() == STOP) break;
						}
						for (a = i + 1; a <= 31; a++) {
							if (Coordinate[a][j].GetSituation() != STOP && Coordinate[a][j].GetSituation() != YOU) NumOfSpace[1]++;
							if (Coordinate[a][j].GetSituation() == STOP) break;
						}
						for (a = j - 1; a >= 0; a--) {
							if (Coordinate[i][a].GetSituation() != STOP && Coordinate[i][a].GetSituation() != YOU) NumOfSpace[2]++;
							if (Coordinate[i][a].GetSituation() == STOP) break;
						}
						for (a = j + 1; a <= 17; a++) {
							if (Coordinate[i][a].GetSituation() != STOP && Coordinate[i][a].GetSituation() != YOU) NumOfSpace[3]++;
							if (Coordinate[i][a].GetSituation() == STOP) break;
						}
						//获取对象四个方向上的空格数

						switch (ch)
						{
						case 'D':
						case 'd':
							if (i < 31 && Coordinate[i + 1][j].GetSituation() != STOP && NumOfSpace[1] != 0)
								//移动后不会越界 穿墙 重叠(通过空格数判定),下同
								NextX = NowX + 1;
							new_dir = D;
							break;
						case 'A':
						case 'a':
							if (i > 0 && Coordinate[i - 1][j].GetSituation() != STOP && NumOfSpace[0] != 0)
								NextX = NowX - 1;
							new_dir = A;
							break;
						case 'S':
						case 's':
							if (j < 17 && Coordinate[i][j + 1].GetSituation() != STOP && NumOfSpace[3] != 0)
								NextY = NowY + 1;
							new_dir = S;
							break;
						case 'W':
						case 'w':
							if (j > 0 && Coordinate[i][j - 1].GetSituation() != STOP && NumOfSpace[2] != 0)
								NextY = NowY - 1;
							new_dir = W;
							break;
						default:
							new_dir = Coordinate[i][j].GetDirec();
							break;
						}
						//对象移动的条件判断。
						NEXTX[x] = NextX;
						NEXTY[x] = NextY;
						NOWX[x] = NowX;
						NOWY[x] = NowY;
						NewDirection[x] = new_dir;
						//存储数组
						x++;
					}
				}
			}
			//确定移动对象之前和之后的坐标，存储在数组中，在全部计算后再开始函数的实现。

			for (x = 0; x < m; x++) {
				const int NextX = NEXTX[x];
				const int NextY = NEXTY[x];
				const enum BlockClass NewC = NewClass[x];
				const enum BlockSituation NewS = NewSituation[x];
				const enum direction NewD = NewDirection[x];
				if (Coordinate[NextX][NextY].GetSituation() == DIE) {
					Die = true;
					putimage(Length* (NextX-0.5), Length* (NextY-0.5), &DIEBLOCK);
				}
				if (Coordinate[NextX][NextY].GetSituation() == WIN) {
					WinPlayerNumber++;
				}
			}
			//判断移动后是否胜利、死亡。
			if (WinPlayerNumber == CupNumber) {
				WhetherWinOrNot = true;
			}
			else if (WinPlayerNumber == 0 && Die != true) {
				for (x = 0; x < m; x++) {
					const int NowX = NOWX[x];
					const int NowY = NOWY[x];
					const enum direction NewD = NewDirection[x];
					NewClass[x] = Coordinate[NowX][NowY].GetClass();
					NewSituation[x] = Coordinate[NowX][NowY].GetSituation();
					ItemInTheGame Spaceitem(NowX, NowY);
					Coordinate[NowX][NowY] = Spaceitem;
					Spaceitem.~ItemInTheGame();
				}
				//在移动前的位置全部创建空格对象
				for (x = 0; x < m; x++) {
					const int NextX = NEXTX[x];
					const int NextY = NEXTY[x];
					const enum BlockClass NewC = NewClass[x];
					const enum BlockSituation NewS = NewSituation[x];
					const enum direction NewD = NewDirection[x];
					ItemInTheGame Newitem(NextX, NextY, NewC, NewS, NewD);
					//生成移动后的对象
					Coordinate[NextX][NextY] = Newitem;
					//移动的完成
					cout << "Moved." << endl;
				}
				//生成新的对象，完成移动
			}
			else
			{
				outtextxy(0, 18 * Length, _T("这个操作是无效的哦！———————只有所有的奖杯同时被拿到，才能获得胜利——————————"));
			};
			//完成移动

			WinPlayerNumber = 0;
			delete[] NOWX, NEXTX, NOWY, NEXTY, NewDirection, NewClass, NewSituation;

			if (Die == true) {
				PlaySound(L"DIESOUND.wav", NULL, NULL);
				setorigin(0, 0);
				putimage(0, 0, &DIESCREEN);
				setorigin(rW * 0.1, rH * 0.1);
				outtextxy(0, 18 * Length, _T("你失败了！按任意键继续。请注意：退出游戏后，您的进度不会保存。"));
				_getch();
				setorigin(0, 0);
				putimage(0, 0, &WHOLEBLUE);
				setorigin(rW * 0.1, rH * 0.1);
				break;
			}
			//死亡

			if (WhetherWinOrNot == true) {
				PlaySound(L"WINSOUND.wav", NULL, NULL);
				if (LevelNumber < MaxLevelNumber) {
					setorigin(0, 0);
					putimage(0, 0, &WINSCREEN);
					setorigin(rW * 0.1, rH * 0.1);
					outtextxy(0, 18 * Length, _T("本关胜利！请按任意键继续。请注意：退出游戏后，您的进度不会保存。"));
					LevelNumber++;
					_getch();
					setorigin(0, 0);
					putimage(0, 0, &WHOLEBLUE);
					setorigin(rW * 0.1, rH * 0.1);
					break;
					PlaySound(L"DIESOUND.wav", NULL, NULL);
				}
				else {
					setorigin(0, 0);
					putimage(0, 0, &WINSCREEN);
					setorigin(rW * 0.1, rH * 0.1);
					outtextxy(0, 18 * Length, _T("游戏胜利！按任意键从第一关重新开始游戏。"));
					LevelNumber = 1;
					_getch();
					setorigin(0, 0);
					putimage(0, 0, &WHOLEBLUE);
					setorigin(rW * 0.1, rH * 0.1);
					break;
				}
			}
			//进入下一关或者直接判定游戏胜利
		}
		//游戏机制的实现

		if (WhetherWinOrNot == true)
			continue;
		if (Die == true)
			continue;

		char WhetherRestartOrNot = _getch();
		if (WhetherRestartOrNot == 'R' || WhetherRestartOrNot == 'r') {
			continue;
		}
		else
			break;
	}
	closegraph();
	return 0;
};

void InitialGameArea() {
	setorigin(0, 0);
	HRGN GameArea = CreateRectRgn(rW * 0.1 - 0.5 * Length - 2, rH * 0.1 - 0.5 * Length - 2, rW * 0.9 + 0.5 * Length + 2, rH * 0.9 + 0.5 * Length + 2);
	setcliprgn(GameArea);
	DeleteObject(GameArea);
	setbkcolor(DARKGRAY);
	setorigin(rW * 0.1, rH * 0.1);
}