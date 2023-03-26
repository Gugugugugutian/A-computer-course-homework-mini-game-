#include "BigHomeworkFinalProject/Picture.h"
//头文件包含了Main.cpp使用到的文件，以及各种类的定义。

//游戏中，各种对象的分类。玩家项目对象就是一个可移动的玩家，不具有这些类。
//这个方块是什么：决定贴图
enum BlockClass { SPACEBLOCK, PLAYER, WALL, LAVA, CUP };
//这个方块对应的规则是什么：决定规则
enum BlockSituation { SPACE, YOU, MOVE, STOP, FFLOAT, DIE, WIN };
//游戏中，玩家项目的方向。一般项目对象不具有这个属性。这个方向影响贴图，但不影响移动的方向。
enum direction { W, A, S, D };

//游戏内的一些项目
class ItemInTheGame
{
public:
	ItemInTheGame(int x0=0, int y0=0, enum BlockClass NewName=SPACEBLOCK, enum BlockSituation Newcondition=SPACE,enum direction DIR = S);
	
	IMAGE GetPicture() { return Picture; };
	//获取方块的贴图
	void SetClass(enum BlockClass NewClass,enum BlockSituation ChangeFunction=SPACE) {
		BlockName = NewClass; 
		CreateImage(NewClass);
		SetSituation(ChangeFunction);
		cout << "Changed to " << NewClass << "		at " << PositionX << "|" << PositionY << endl;
	};
	//设置方块的种类，并选择设置后方块的功能。用GetSituation()也可以保持现在的功能
	void SetSituation(enum BlockSituation NewSituation) {
		BlockCondition = NewSituation;
		cout << "Situation Changed to " << NewSituation << "		at" << PositionX << "|" << PositionY << endl;
	};
	void CreateImage(enum BlockClass Newclass);
	//改变对象的种类、状态,根据现有的名称创建贴图。
	int GetPX() { return PositionX; };
	int GetPY() { return PositionY; };
	int GetX() { return X; };
	int GetY() { return Y; };
	//获取坐标
	enum BlockClass GetClass() { return BlockName; };
	enum BlockSituation GetSituation() { return BlockCondition; };
	enum direction GetDirec() { return Direc; };
	//获取方块名称和规则
	~ItemInTheGame();

protected:
	IMAGE Picture;	//	贴图
	int PositionX;	int PositionY;		//相对坐标，相对于生成的界面。相对坐标【有】零值，请注意！！！	
	int X;	int Y;						//绝对坐标，对应像素数字。
	enum BlockClass BlockName;
	enum BlockSituation BlockCondition;
	enum direction Direc;

private:

};

ItemInTheGame::ItemInTheGame(int x0, int y0, enum BlockClass NewName, enum BlockSituation Newcondition, enum direction DIR) :PositionX(x0), PositionY(y0), BlockName(NewName), BlockCondition(Newcondition), Direc(DIR) {
	//对象有相对位置和绝对位置，下计算对象的绝对坐标：
	X = Length * (PositionX - 0.5);
	Y = Length * (PositionY - 0.5);
	//只有PLAYER具有方向。
	CreateImage(NewName);
	cout << "Successfully created:" << BlockName << "|" << BlockCondition << " at " << PositionX << "	" << PositionY << endl;
	}

	ItemInTheGame::~ItemInTheGame() {
	}

void ItemInTheGame::CreateImage(enum BlockClass Newclass) {
	switch (Newclass){
	case SPACEBLOCK:
		Picture = SPACEPIC;
		break;
	case PLAYER:
		switch (Direc)
		{
		case W:
			Picture = PLAYERPICW;
			break;
		case A:
			Picture = PLAYERPICA;
			break;
		case S:
			Picture = PLAYERPICS;
			break;
		case D:
			Picture = PLAYERPICD;
			break;
		default:
			break;
		}
		break;
	case WALL:
		Picture = WALLPIC;
		break;
	case CUP:
		Picture = CUPPIC;
		break;
	case LAVA:
		Picture = LAVAPIC;
		break;
	default:
		break;
	};
	putimage(GetX(), GetY(), &Picture);
};
//贴图的创建