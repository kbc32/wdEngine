#pragma once
class Coin
{
public:
	Coin();
	~Coin();
	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();
	/// <summary>
	/// �`�揈��
	/// </summary>
	void Render(int cameraNo);
	/// <summary>
	/// �R�C���̍��W��ݒ肷��
	/// </summary>
	/// <param name="position">���W</param>
	void SetPosition(CVector3 position);
private:
	SkinModel m_coin; //�X�L�����f��
	CVector3 m_position; //���W
	CQuaternion m_rotation; //��]


	
};

