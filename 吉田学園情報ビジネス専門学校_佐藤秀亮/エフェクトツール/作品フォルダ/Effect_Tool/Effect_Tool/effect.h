//*****************************************************************************
// �G�t�F�N�g���� [Effect.h]
// Author : �����G��
//*****************************************************************************

#ifndef _EFFECT_H_
#define _EFFECT_H_

#include "Scene2D.h"

class CEffect : public CScene2D
{
public:
	typedef enum
	{
		ANIMPATTERN_NOMAL,
		ANIMPATTERN_RAND,
		ANIMPATTERN_MAX,
	} ANIMPATTERN;

	CEffect(int nPriority = 3);
	virtual ~CEffect();

	virtual HRESULT Init(D3DXVECTOR3 pos,
		D3DCOLORVALUE color,
		D3DCOLORVALUE Mincolor,
		D3DXVECTOR2 Size,
		D3DXVECTOR2 MinSize,
		int nLife, int nType,
		int Synthetic,
		D3DXVECTOR2 TexNum,
		D3DXVECTOR2 TexMove,
		int nAnimCounter,
		D3DXVECTOR2 nSplit,
		ANIMPATTERN AnimPattern);

	virtual void Uninit();
	virtual void Update();
	virtual void Draw();


protected:
	bool m_bUninit;
	int m_nLife;
	D3DXVECTOR2 m_MinSize;		//�傫���ϓ�
	ANIMPATTERN m_AnimPattern;	//�A�j���[�V�����p�^�[���̓���

	//�J���[�l
	D3DCOLORVALUE m_Color;

	//���炷�J���[�l
	D3DCOLORVALUE m_MinColor;

private:

	D3DXVECTOR2 m_TexMove;


	D3DXVECTOR2 m_move;			//�ړ�

	int m_nSynthetic;
};
#endif
