#pragma once

#include "graphics/shader.h"

class Sprite {
public:
	/// <summary>
	/// �R���X�g���N�^�B
	/// </summary>
	Sprite::Sprite();
	/// <summary>
	/// �f�X�g���N�^�B
	/// </summary>
	Sprite::~Sprite();
	/// <summary>
	/// �������B
	/// </summary>
	/// <param name="textureFilePath">�e�N�X�`���̃t�@�C���p�X�B</param>
	void Init( const wchar_t* textureFilePath, float w, float h );
	/// <summary>
	/// ���[���h�s����X�V�B
	/// </summary>
	/// <param name="pos">���W</param>
	/// <param name="rot">��]</param>
	/// <param name="scale">�g�嗦</param>
	void UpdateWorldMatrix( CVector3 pos, CQuaternion rot, CVector3 scale);
	/// <summary>
	/// �`��B
	/// </summary>
	/// <param name="mView">�J�����s��</param>
	/// /// <param name="mView">�v���W�F�N�V�����s��</param>
	void Draw( CMatrix mView, CMatrix mProj );
private:
	/// <summary>
	/// �V�F�[�_�[�����[�h�B
	/// </summary>
	void LoadShader();
	/// <summary>
	/// ���_�o�b�t�@���쐬�B
	/// </summary>
	void CreateVertexBuffer(float w, float h);
	/// <summary>
	/// �C���f�b�N�X�o�b�t�@���쐬�B
	/// </summary>
	void CreateIndexBuffer();
	/// <summary>
	/// �T���v���X�e�[�g���쐬�B
	/// </summary>
	void CreateSamplerState();
	/// <summary>
	/// �萔�o�b�t�@�̍쐬�B
	/// </summary>
	void CreateConstantBuffer();
	/// <summary>
	/// �e�N�X�`�������\�h�B
	/// </summary>
	/// <param name="textureFIlePath">���[�h����e�N�X�`���̃t�@�C���p�X�B</param>
	void LoadTexture(const wchar_t* textureFIlePath);
private:

	Shader	m_vs;											//���_�V�F�[�_�[�B
	Shader	m_ps;											//�s�N�Z���V�F�[�_�[�B
	ID3D11Buffer*	m_vertexBuffer = nullptr;	//VRAM��̒��_�o�b�t�@�ɃA�N�Z�X���邽�߂̃C���^�[�t�F�[�X�B
	ID3D11Buffer*	m_indexBuffer = nullptr;		//VRAM��̃C���f�b�N�X�o�b�t�@�ɃA�N�Z�X���邽�߂̃C���^�[�t�F�[�X�B
	ID3D11Buffer*	m_cbGPU = nullptr;			//GPU���̒萔�o�b�t�@�ɃA�N�Z�X���邽�߂̃C���^�[�t�F�[�X�B
	ID3D11ShaderResourceView* m_texture = nullptr;	//�e�N�X�`���ɃA�N�Z�X���邽�߂̃C���^�[�t�F�[�X�B
	ID3D11SamplerState* m_samplerState = nullptr;	//�T���v���X�e�[�g�B
	CMatrix m_world = CMatrix::Identity();					//���[���h�s��B
};