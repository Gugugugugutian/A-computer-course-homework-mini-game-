#include "BigHomeworkFinalProject/Picture.h"
//ͷ�ļ�������Main.cppʹ�õ����ļ����Լ�������Ķ��塣

//��Ϸ�У����ֶ���ķ��ࡣ�����Ŀ�������һ�����ƶ�����ң���������Щ�ࡣ
//���������ʲô��������ͼ
enum BlockClass { SPACEBLOCK, PLAYER, WALL, LAVA, CUP };
//��������Ӧ�Ĺ�����ʲô����������
enum BlockSituation { SPACE, YOU, MOVE, STOP, FFLOAT, DIE, WIN };
//��Ϸ�У������Ŀ�ķ���һ����Ŀ���󲻾���������ԡ��������Ӱ����ͼ������Ӱ���ƶ��ķ���
enum direction { W, A, S, D };

//��Ϸ�ڵ�һЩ��Ŀ
class ItemInTheGame
{
public:
	ItemInTheGame(int x0=0, int y0=0, enum BlockClass NewName=SPACEBLOCK, enum BlockSituation Newcondition=SPACE,enum direction DIR = S);
	
	IMAGE GetPicture() { return Picture; };
	//��ȡ�������ͼ
	void SetClass(enum BlockClass NewClass,enum BlockSituation ChangeFunction=SPACE) {
		BlockName = NewClass; 
		CreateImage(NewClass);
		SetSituation(ChangeFunction);
		cout << "Changed to " << NewClass << "		at " << PositionX << "|" << PositionY << endl;
	};
	//���÷�������࣬��ѡ�����ú󷽿�Ĺ��ܡ���GetSituation()Ҳ���Ա������ڵĹ���
	void SetSituation(enum BlockSituation NewSituation) {
		BlockCondition = NewSituation;
		cout << "Situation Changed to " << NewSituation << "		at" << PositionX << "|" << PositionY << endl;
	};
	void CreateImage(enum BlockClass Newclass);
	//�ı��������ࡢ״̬,�������е����ƴ�����ͼ��
	int GetPX() { return PositionX; };
	int GetPY() { return PositionY; };
	int GetX() { return X; };
	int GetY() { return Y; };
	//��ȡ����
	enum BlockClass GetClass() { return BlockName; };
	enum BlockSituation GetSituation() { return BlockCondition; };
	enum direction GetDirec() { return Direc; };
	//��ȡ�������ƺ͹���
	~ItemInTheGame();

protected:
	IMAGE Picture;	//	��ͼ
	int PositionX;	int PositionY;		//������꣬��������ɵĽ��档������꡾�С���ֵ����ע�⣡����	
	int X;	int Y;						//�������꣬��Ӧ�������֡�
	enum BlockClass BlockName;
	enum BlockSituation BlockCondition;
	enum direction Direc;

private:

};

ItemInTheGame::ItemInTheGame(int x0, int y0, enum BlockClass NewName, enum BlockSituation Newcondition, enum direction DIR) :PositionX(x0), PositionY(y0), BlockName(NewName), BlockCondition(Newcondition), Direc(DIR) {
	//���������λ�ú;���λ�ã��¼������ľ������꣺
	X = Length * (PositionX - 0.5);
	Y = Length * (PositionY - 0.5);
	//ֻ��PLAYER���з���
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
//��ͼ�Ĵ���