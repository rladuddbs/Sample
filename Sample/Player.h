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

	int			speed;				// 속도
	int			ballon_length;		// 물풍선 길이
	int			ballon_num;			// 물풍선 개수
	int			direction;			// 캐릭터 시선
	int			state;				// 캐릭터 상태





	//이건 뭐지
	/*int count;
	int player;
	Ballon ballon[6];
	Bullet bullet[3];*/
};

