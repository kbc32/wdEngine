#include "stdafx.h"
#include "Map.h"


Map::Map()
{
	//cmo�t�@�C���̓ǂݍ��݁B
	m_MapModel.Init(L"Assets/modelData/Map001.cmo");
	m_quarenion.SetRotationDeg(CVector3::AxisX(), 90.0f);
	//�ÓI�����I�u�W�F�N�g���쐬�B
	m_phyStaticObject.CreateMeshObject(m_MapModel,m_position,m_quarenion);
}


Map::~Map()
{
}

void Map::Update()
{
	//���[���h�s��̍X�V�B
	m_MapModel.UpdateWorldMatrix(m_position, m_quarenion,CVector3::One());
}

void Map::Render(int cameraNo)
{
	m_MapModel.Draw(
		g_camera3D[cameraNo].GetViewMatrix(),
		g_camera3D[cameraNo].GetProjectionMatrix()
	);
}
