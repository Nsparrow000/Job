//*****************************************************************************
// �V�[��2D���� [Scene2D.h]
// Author : �����G��
//*****************************************************************************
#ifndef _SCENE2D_H_
#define _SCENE2D_H_

//*****************************************************************************
// �C���N���[�h
//*****************************************************************************
#include "main.h"
#include "Scene.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define FVF_VERTEX_2D	(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)

//*****************************************************************************
// �\���̒�`
//*****************************************************************************
// ���_�t�H�[�}�b�g�ɍ��킹���\����
typedef struct
{
	D3DXVECTOR3 pos;	// ���_����
	float rhw;			// 1.0�ŌŒ�
	D3DCOLOR col;		// ���_�J���[
	D3DXVECTOR2 tex;	// �e�N�X�`���̍��W
} VERTEX_2D;

//*****************************************************************************
//�I�u�W�F�N�g�N���X
//*****************************************************************************
class CScene2D : public CScene
{
public:
	CScene2D(int nPriority = 3);
	~CScene2D();

	HRESULT Init(D3DXVECTOR3 pos);	//������
	void Uninit();				//�I��
	void Update();				//�X�V
	void Draw();				//�`��

	static void UninitTexture();

	static void CreateTexture();//�e�N�X�`���ǂݍ���


	void SetPosition(D3DXVECTOR3 pos);		//pos�X�V�p
	D3DXVECTOR3 GetPosition() { return m_pos; }				//pos�X�V���邽�߂ɃQ�b�g

	float GetHight() { return  m_Size.y; }			//pos�X�V���邽�߂ɃQ�b�g
	float GetWhidth() { return  m_Size.x; }			//pos�X�V���邽�߂ɃQ�b

	void SetTexture(int nTex) { m_nType = nTex; }		//�e�N�X�`���^�C�v

	void ColorChange(D3DCOLORVALUE color);	//�J���[�ύX

	void FadeColorChange(int Alpha);		//�t�F�[�h�p���ύX

	void SetTexAnim(D3DXVECTOR2 TexPattern, D3DXVECTOR2 TexAnimSize);						//�e�N�X�`���p�^�[���ԍ��A�p�^�[���P�̃T�C�Y
	void TexMove(D3DXVECTOR2 MoveTex);				//�e�N�X�`�����W�̍X�V

	void SetGaugeScele(float Whidth, float Hight);				//�Q�[�W�^�C�v�̃X�P�[���ύX
	void SetRotate(D3DXVECTOR3 pos, float Rotate, float Rotate2, float Vectol);			//��]
	void SetfleeSizePos(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2, D3DXVECTOR3 pos3, D3DXVECTOR3 pos4);	//���R�ȍ��W�w��
	void SecondColorChange(D3DCOLORVALUE color, D3DCOLORVALUE Secondcolor);	//�Q�_�ύX

protected:
	int m_nAnimCount;
	int m_nSetAnimCnt;
	D3DXVECTOR2 m_nSplit;
	D3DXVECTOR2 m_MaxSplit;
	D3DXVECTOR2 m_PatternSize;
	D3DXVECTOR2 m_TexSize;				//�e�N�X�`���T�C�Y
	D3DXVECTOR2 m_TexNum;
	D3DXVECTOR2 m_Size;				//�T�C�Y

private:

	static LPDIRECT3DTEXTURE9 m_Texture[MAX_TEXTURE];				//�e�N�X�`���[�|�C���^
	static int m_nMaxTex;											//�g�p����ő�e�N�X�`��
	D3DXVECTOR3 m_pos;				//�ʒu

	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff = NULL;	//���_�o�b�t�@�ւ̃|�C���^

	D3DXVECTOR2 m_TexMove;


	int m_nType;					//���

	int m_Texpos;					//�e�N�X�`�����W


									//�J���[�l
};
#endif
