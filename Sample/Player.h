#pragma once
#include "GameObject.h"


class CPlayer : public CCharacter
{
public:
	CPlayer();
	~CPlayer();

	void Update();
	void Render();
private:

	int			speed;				// �ӵ�
	int			ballon_length;		// ��ǳ�� ����
	int			ballon_num;			// ��ǳ�� ����
	int			direction;			// ĳ���� �ü�
	int			state;				// ĳ���� ����





	//�̰� ����
	/*int count;
	int player;
	Ballon ballon[6];
	Bullet bullet[3];*/
};

