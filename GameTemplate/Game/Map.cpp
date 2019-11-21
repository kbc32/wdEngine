#include "stdafx.h"
#include "Map.h"


Map::Map()
{
	//cmoファイルの読み込み。
	m_MapModel.Init(L"Assets/modelData/Map001.cmo");
	m_quarenion.SetRotationDeg(CVector3::AxisX(), 90.0f);
	//静的物理オブジェクトを作成。
	m_phyStaticObject.CreateMeshObject(m_MapModel,m_position,m_quarenion);
}


Map::~Map()
{
}

void Map::Update()
{
	//ワールド行列の更新。
	m_MapModel.UpdateWorldMatrix(m_position, m_quarenion,CVector3::One());
}

void Map::Render()
{
	m_MapModel.Draw(
		g_camera3D.GetViewMatrix(),
		g_camera3D.GetProjectionMatrix()
	);
}
