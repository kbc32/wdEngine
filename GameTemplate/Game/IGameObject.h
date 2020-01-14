#pragma once
class IGameObject
{
public:

	/// <summary>
	/// �X�V�֐�
	/// </summary>
	virtual void Update() = 0;
	/// <summary>
	/// �`��
	/// </summary>
	virtual void Render();

	/// <summary>
	/// �폜�t���O�𗧂Ă�
	/// </summary>
	void RequestDelete()
	{
		isRequestDelete = true;
	}

	/// <summary>
	/// �폜���N�G�X�g���󂯂Ă��邩���ׂ�
	/// </summary>
	/// <returns>
	/// true���Ԃ��Ă�����A���N�G�X�g���󂯂Ă���
	/// </returns>
	bool IsRequestDelete()
	{
		return isRequestDelete;
	}
private:
	bool isRequestDelete = false;
};

