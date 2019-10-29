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
	
	Player player;			//�v���C���[
	Map map;				//�}�b�v
};

