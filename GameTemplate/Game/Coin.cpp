#include "stdafx.h"
#include "Coin.h"


Coin::Coin()
{
	m_coin.Init(L"Assets/modelData/Coin.cmo");
}


Coin::~Coin()
{
}

void Coin::Update()
{

}

void Coin::Render(int cameraNo)
{
	m_coin.Draw(
		g_camera3D[cameraNo].GetViewMatrix(),
		g_camera3D[cameraNo].GetProjectionMatrix(),
		cameraNo
	);
}

void Coin::SetPosition(CVector3 position)
{
	m_position = position;
}