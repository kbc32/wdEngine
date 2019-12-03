#pragma once
#include "IGameObject.h"
#include "Player.h"
#include "Map.h"
#include "graphics/Camera.h"


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
	//�J����4�l��
	//Camera g_camera3D[4];
	Map map;				//�}�b�v
	int PadNom = 0;			//�p�b�h�ԍ�
};

