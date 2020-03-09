#pragma once
class Weapon
{
public:
	Weapon();
	~Weapon();
	/// <summary>
	/// �X�V����
	/// </summary>
	/// <param name="PlayerNo"></param>
	void Update(int PlayerNo);
	/// <summary>
	/// �`�揈��
	/// </summary>
	/// <param name="PlayerNo"></param>
	void Draw(int PlayerNo);
private:
	
	SkinModel m_weapon;
	CVector3 m_position;
	float m_angle;
	float m_angle2;
	CQuaternion m_rotation;
	CVector3 m_gunLocalPos = {1.0f,1.0f,1.0f };
	CVector3 m_Pos;
};

