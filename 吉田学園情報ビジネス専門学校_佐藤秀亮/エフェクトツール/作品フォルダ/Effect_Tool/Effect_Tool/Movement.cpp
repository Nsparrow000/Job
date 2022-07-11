//*****************************************************************************
// (�ړ�����)�G�t�F�N�g���� [Movement.cpp]
// Author : �����G��
//*****************************************************************************
#include "Movement.h"
#include "manager.h"

//*****************************************************************************
//�R���X�g���N�^
//*****************************************************************************
CMovement::CMovement(int nPriority) : CEffect(nPriority)
{
	m_move = {};
	m_Addpos = {};
}

//*****************************************************************************
//�f�X�g���N�^
//*****************************************************************************
CMovement::~CMovement()
{

}

//*****************************************************************************
//	������
//*****************************************************************************
HRESULT CMovement::Init(D3DXVECTOR3 pos,
	D3DXVECTOR2 move,
	D3DCOLORVALUE color,
	D3DCOLORVALUE Mincolor,
	D3DXVECTOR2 Size,
	D3DXVECTOR2 MinSize,
	int nLife,
	int nType,
	D3DXVECTOR2 AddMovement,
	int nSynthetic,
	D3DXVECTOR2 TexNum,
	D3DXVECTOR2 TexMove,
	int nAnimCounter,
	D3DXVECTOR2 nSplit,
	ANIMPATTERN AnimPattern,
	SHAPE_TYPE Shapetype,
	float fHight,
	float HigthPos,
	float HigthSize,
	D3DCOLORVALUE Secondcolor,
	D3DCOLORVALUE SecondMincolor)
{
	CEffect::Init(pos, color, Mincolor, Size, MinSize, nLife, nType,nSynthetic, TexNum, TexMove, nAnimCounter, nSplit, AnimPattern);

	m_Addpos = AddMovement;
	m_move = move;

	m_ShapeType = Shapetype;
	m_fHigth = fHight;
	m_HigthPos = HigthPos;
	m_HigthSize = HigthSize;

	m_SecondColor = Secondcolor;
	m_SecondMinColor = SecondMincolor;

	return S_OK;
}

//*****************************************************************************
//�I��
//*****************************************************************************
void CMovement::Uninit()
{
	CEffect::Uninit();
}

//*****************************************************************************
//�X�V
//*****************************************************************************
void CMovement::Update()
{
	D3DXVECTOR3 pos = GetPosition();
	m_Size += m_MinSize;

	m_move += m_Addpos;	//�ړ��l�Ɋ��������Z
	pos += D3DXVECTOR3(m_move.x, m_move.y, 0.0f);

	//�J���[�ύX
	m_SecondColor.r += m_SecondMinColor.r;
	m_SecondColor.g += m_SecondMinColor.g;
	m_SecondColor.b += m_SecondMinColor.b;
	m_SecondColor.a += m_SecondMinColor.a;

	//�J���[��0�ȉ��̎�
	if (m_SecondColor.r < 0)
	{
		m_SecondColor.r = 0;
	}
	if (m_SecondColor.g < 0)
	{
		m_SecondColor.g = 0;
	}
	if (m_SecondColor.b < 0)
	{
		m_SecondColor.b = 0;
	}
	if (m_SecondColor.a < 0)
	{
		m_SecondColor.a = 0;
	}

	//�J���[��255�ȏ�̎�
	if (m_SecondColor.r > 255)
	{
		m_SecondColor.r = 255;
	}
	if (m_SecondColor.g > 255)
	{
		m_SecondColor.g = 255;
	}
	if (m_SecondColor.b > 255)
	{
		m_SecondColor.b = 255;
	}
	if (m_SecondColor.a > 255)
	{
		m_SecondColor.a = 255;
	}


	switch (m_ShapeType)
	{
	case(SHAPE_SQUARE):
		SetPosition(pos);
		ColorChange(m_Color);
		break;
	case(SHAPE_FREE):
		SetfleeSizePos(
			D3DXVECTOR3(pos.x + m_HigthPos - m_HigthSize, pos.y - m_fHigth, 0.0f),
			D3DXVECTOR3(pos.x + m_HigthPos + m_HigthSize, pos.y - m_fHigth, 0.0f),
			D3DXVECTOR3(pos.x - m_Size.x, pos.y, 0.0f),
			D3DXVECTOR3(pos.x + m_Size.x, pos.y, 0.0f));

		SecondColorChange(m_Color, m_SecondColor);
			break;
	default:
		break;
	}

	CEffect::Update();
}

//*****************************************************************************
//�`��
//*****************************************************************************
void CMovement::Draw()
{
	CEffect::Draw();
}

//*****************************************************************************
//�쐬
//*****************************************************************************
CMovement *CMovement::Create(D3DXVECTOR3 pos,
	D3DXVECTOR2 move,
	D3DCOLORVALUE color,
	D3DCOLORVALUE Mincolor,
	D3DXVECTOR2 Size,
	D3DXVECTOR2 MinSize,
	int nLife,
	int nType,
	D3DXVECTOR2 AddMovement,
	int nSynthetic,
	D3DXVECTOR2 TexNum,
	D3DXVECTOR2 TexMove,
	int nAnimCounter,
	D3DXVECTOR2 nSplit,
	ANIMPATTERN AnimPattern,
	SHAPE_TYPE Shapetype,
	float fHight,
	float HigthPos,
	float HigthSize,
	D3DCOLORVALUE Secondcolor,
	D3DCOLORVALUE SecondMincolor)
{
	CMovement *pMovement = NULL;
	pMovement = new CMovement(CManager::PRIORITY_EFFECT);		//�������m��
	//NULL�`�F�b�N
	if (pMovement != NULL)
	{
		pMovement->Init(pos, move, color,
			Mincolor,
			Size,
			MinSize,
			nLife, nType,
			AddMovement, nSynthetic,
			TexNum, TexMove,
			nAnimCounter, nSplit,
			AnimPattern, Shapetype, fHight,
			HigthPos,
			HigthSize,
			Secondcolor,
			SecondMincolor);
	}

	return pMovement;
}
