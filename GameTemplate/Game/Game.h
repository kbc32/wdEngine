#pragma once
#include "IGameObject.h"
#include "Player.h"
#include "Map.h"


class Game : public IGameObject
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Game();
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Game();
	/// <summary>
	/// �X�V�����B
	/// </summary>
	void Update();
	/// <summary>
	/// �`�揈���B
	/// </summary>
	void Render();

private:

	//�v���C���[4�l��
	Player player[4];
	Map map;				//�}�b�v
};

