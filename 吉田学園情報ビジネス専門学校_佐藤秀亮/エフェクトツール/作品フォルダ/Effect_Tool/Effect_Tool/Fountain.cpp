//=============================================================================
// 3D�����G�t�F�N�g���� [Fountain.cpp]
// Author : �����G��
//=============================================================================
#include "Fountain.h"
#include "manager.h"

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CFountain::CFountain(int nPriority) : CBillEffect(nPriority)
{

}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CFountain::~CFountain()
{

}

//=============================================================================
// ������
//=============================================================================
HRESULT CFountain::Init(D3DXVECTOR3 pos,
	D3DXVECTOR3 Size,
	D3DXVECTOR3 MinSize,
	D3DCOLORVALUE color,
	D3DCOLORVALUE Mincolor,
	int nTex, int nLife,
	D3DXVECTOR2 TexNum,
	D3DXVECTOR2 TexMove,
	int nAnimCounter,
	D3DXVECTOR2 nSplit,
	ANIMPATTERN AnimPattern,
	D3DXVECTOR3 move,
	D3DXVECTOR3 Target,
	int Diffusion,
	int Synhetic,
	HIGHT_PATTERN HigthPattrn)
{
	CBillEffect::Init(Size, MinSize, color, Mincolor, nTex, nLife, TexNum, TexMove, nAnimCounter, nSplit, AnimPattern);

	D3DXVECTOR3 T = Target;
	D3DXVECTOR3 V = Target - pos;


	m_fAngle = atan2(V.x, V.z);

	//�����_���g�U��
	int Lowest = Diffusion;
	if (Lowest <= 0)
	{
		Lowest = 1;
	}
	float randAngle = float(rand() % Lowest) - float(rand() % Lowest);
	randAngle /= 100.0f;
	m_fAngle += randAngle;


	if (move.y > 0)
	{
		if (HigthPattrn == HIGHT_RAND)
		{
			move.y * 100;

			float randHight = float(rand() % (int)move.y) - float(rand() % (int)move.y);
			move.y = randHight;

			m_move = move;
		}
		else
		{
			m_move = move;
		}
	}
	m_pos = pos;

	m_nSynthenic = Synhetic;
	SetPos(m_pos);
	return S_OK;
}

//=============================================================================
// �I��
//=============================================================================
void CFountain::Uninit()
{
	CBillEffect::Uninit();
}

//=============================================================================
// �X�V
//=============================================================================
void CFountain::Update()
{
	m_pos += D3DXVECTOR3(sinf(m_fAngle) *m_move.x, m_move.y, cosf(m_fAngle) * m_move.x);

	m_Size += m_MinSize;

	m_move.y += m_move.z;

	SetPos(m_pos);
	ChangeSize(m_Size);
	CBillEffect::Update();
}

//=============================================================================
// �`��
//=============================================================================
void CFountain::Draw()
{
	CBillEffect::Draw();
}

//=============================================================================
// �쐬
//=============================================================================
CFountain *CFountain::Create(D3DXVECTOR3 pos,
	D3DXVECTOR3 Size,
	D3DXVECTOR3 MinSize,
	D3DCOLORVALUE color,
	D3DCOLORVALUE Mincolor,
	int nTex, int nLife,
	D3DXVECTOR2 TexNum,
	D3DXVECTOR2 TexMove,
	int nAnimCounter,
	D3DXVECTOR2 nSplit,
	ANIMPATTERN AnimPattern,
	D3DXVECTOR3 move,
	D3DXVECTOR3 Target,
	int Diffusion,
	int Synhetic,
	HIGHT_PATTERN HigthPattrn)
{
	CFountain *pFountain = new CFountain(CManager::PRIORITY_EFFECT);

	if (pFountain != NULL)
	{
		pFountain->Init(pos, Size, MinSize, color, Mincolor, nTex, nLife, TexNum,
			TexMove, nAnimCounter, nSplit,
			AnimPattern, move, Target,
			Diffusion, Synhetic, HigthPattrn);
	}

	return pFountain;
}