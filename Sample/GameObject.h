#pragma once
#include "stdafx.h"


class CGameObject
{
public:
	CGameObject();
	~CGameObject();

	virtual void Update() = 0;
	virtual void Render() = 0;


private:
	int x, y;		// ��ǥ

	// �̹��� ���� ������ ����

};

class CBallon : public CGameObject
{
public:
	CBallon();
	~CBallon();

	virtual void Update();
	virtual void Render();

private:
	int			state;   //			0������ �ִ°�      1 ó�� ��ġ�ҋ�			 2 ��!
	int			beforeboomcouont;
	int			startboomcount;

	RECT		boundingBox;

};

class CCharacter : public CGameObject
{
public:
	CCharacter() = default;
	~CCharacter() = default;

private:
	int			speed;			// ĳ������ �̵��ӵ�
	int			ballon_length;	// ��ǳ���� ����
	int			ballon_num;		// ��ǳ���� ����
	int			direction;		// ĳ������ ����
	int			state;			// ĳ������ ����
	bool		stop;			// ĳ���� ���� ����
	int			count;			// ���� ��
	CBallon		ballon[6];		// ��ǳ��

	RECT		boundingBox;
};


class CBoard : public CGameObject
{
public:
	CBoard();
	~CBoard();

	virtual void Update();
	virtual void Render();

private:
	int type;				// 1�̸� �Ϲ�Ÿ��, 2�̸� ���, 3�̸� ��ֹ�, 6: �Ź߾�����, 7: ���ٱ������, 8: ��ǳ��������
	int block;				// ���� ��

	RECT		boundingBox;
};





class CItem : public CGameObject
{
public:
	CItem();
	~CItem();

	virtual void Update();
	virtual void Render();

public:
	RECT		boundingBox;

};