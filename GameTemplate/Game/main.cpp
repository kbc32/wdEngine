#include "stdafx.h"
#include "system/system.h"
#include "Player.h"
#include "level/Level.h"
#include "graphics/Camera.h"
#include "CGameObjectManager.h"
#include "Map.h"
#include "Game.h"


///////////////////////////////////////////////////////////////////
// �E�B���h�E�v���O�����̃��C���֐��B
///////////////////////////////////////////////////////////////////
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	//�Q�[���̏������B
	InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, "Game");

	//�J�������������B
	for (int cameraNo = 0; cameraNo < 4; cameraNo++) {
		g_camera3D[cameraNo].SetPosition({ 0.0f, 100.0f, 300.0f });
		g_camera3D[cameraNo].SetTarget({ 0.0f, 100.0f, 0.0f });
		g_camera3D[cameraNo].SetFar(10000.0f);
	}

	//�Q�[���N���X���쐬
	Game m_game;

	//�Q�[�����[�v�B
	while (DispatchWindowMessage() == true)
	{
		//GameObject�̍X�V
		g_goMgr.Update();
		
			
		//�`��J�n�B
		g_graphicsEngine->BegineRender();

		//�S��ʕ����`�揈��
		for (int cameraNo = 0; cameraNo < 4; cameraNo++)
		{
			//�������ރr���[�|�[�g��ݒ�
			g_graphicsEngine->SetViewport(cameraNo);
			//�Q�[���p�b�h�̍X�V�B	
			for (auto& pad : g_pad) {
				pad.Update();
			}
			//�Q�[���N���X�̕`��
			m_game.Render(cameraNo);
			
		}

		//�����G���W���̍X�V�B
		g_physics.Update();
		
		//�Q�[���N���X�̍X�V
		m_game.Update();
		//�`��I���B
		g_graphicsEngine->EndRender();
	}
}