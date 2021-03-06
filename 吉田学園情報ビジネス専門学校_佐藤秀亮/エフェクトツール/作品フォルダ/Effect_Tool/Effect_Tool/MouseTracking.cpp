//*****************************************************************************
// (マウスに向かって飛んでく)エフェクト処理 [MouseTracking.cpp]
// Author : 佐藤秀亮
//*****************************************************************************
#include "MouseTracking.h"
#include "manager.h"
//*****************************************************************************
//コンストラクタ
//*****************************************************************************
CMouseTracking::CMouseTracking(int nPriority) : CEffect(nPriority)
{
	m_move = {};
	m_Vec = {};
}

//*****************************************************************************
//デストラクタ
//*****************************************************************************
CMouseTracking::~CMouseTracking()
{

}

//*****************************************************************************
//	初期化
//*****************************************************************************
HRESULT CMouseTracking::Init(D3DXVECTOR3 pos,
	D3DXVECTOR2 move,
	D3DCOLORVALUE color,
	D3DCOLORVALUE Mincolor,
	D3DXVECTOR2 Size,
	D3DXVECTOR2 MinSize,
	int nLife, int nType,
	D3DXVECTOR3 Endpos,
	int Diffusion,
	int UninitVectl,
	int Synthetic,
	int Distance,
	D3DXVECTOR3 Playerpos,
	D3DXVECTOR3 rot,
	D3DXVECTOR2 TexNum,
	D3DXVECTOR2 TexMove,
	int nAnimCounter,
	D3DXVECTOR2 nSplit,
	ANIMPATTERN AnimPattern)
{
	CEffect::Init(pos,
		color,
		Mincolor, Size, MinSize, nLife, nType, Synthetic, TexNum, TexMove, nAnimCounter, nSplit, AnimPattern);

	m_Endpos = pos;
	m_PlayerPos = Playerpos;
	m_Vec = pos - Endpos;
	m_move = move;

	m_UninitVectl = UninitVectl;
	m_SerectRot = rot;
	//randで死ぬから最低保障
	int Lowest = Diffusion;
	if (Lowest <= 0)
	{
		Lowest = 1;
	}

	float randAngle = float(rand() % Lowest) - float(rand() % Lowest);
	randAngle /= 100.0f;
	m_Distance = Distance;
	m_fAngle = (float)atan2(m_Vec.x, m_Vec.y);		//角度

	m_fAngle += randAngle;
	m_pos += D3DXVECTOR3(pos.x + sinf(-m_fAngle + m_SerectRot.y) * m_Distance, pos.y + cosf(-m_fAngle + m_SerectRot.y) * -m_Distance, 0.0f);
	SetPosition(m_pos);
	CScene2D::SetRotate(m_pos, -m_fAngle + D3DX_PI / 4 + m_SerectRot.y, -m_fAngle  + D3DX_PI / 4 + m_SerectRot.y, m_Size.x);

	return S_OK;
}

//*****************************************************************************
//終了
//*****************************************************************************
void CMouseTracking::Uninit()
{
	CEffect::Uninit();
}

//*****************************************************************************
//更新
//*****************************************************************************
void CMouseTracking::Update()
{
	D3DXVECTOR3 pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Distance += m_move.x;

	pos += D3DXVECTOR3(m_pos.x + sinf(-m_fAngle + m_SerectRot.y) * m_Distance, m_pos.y + cosf(-m_fAngle + m_SerectRot.y) * -m_Distance, 0.0f);
	m_Size += m_MinSize;

	m_Vec = pos - m_Endpos;

	m_Vectl = sqrtf(m_Vec.x * m_Vec.x + m_Vec.y *  m_Vec.y);

	if (m_Vectl >= m_UninitVectl)
	{
		m_bUninit = true;
	}


	CScene2D::SetRotate(pos, -m_fAngle + D3DX_PI / 4 + m_SerectRot.y, -m_fAngle + D3DX_PI / 4 + m_SerectRot.y, m_Size.x);
	ColorChange(m_Color);

	CEffect::Update();

}

//*****************************************************************************
//描画
//*****************************************************************************
void CMouseTracking::Draw()
{
	CEffect::Draw();
}

//*****************************************************************************
//作成
//*****************************************************************************
CMouseTracking *CMouseTracking::Create(D3DXVECTOR3 pos,
	D3DXVECTOR2 move,
	D3DCOLORVALUE color,
	D3DCOLORVALUE Mincolor,
	D3DXVECTOR2 Size,
	D3DXVECTOR2 MinSize,
	int nLife, int nType,
	D3DXVECTOR3 Endpos,
	int Diffusion,
	int UninitVectl,
	int Synthetic,
	int Distance,
	D3DXVECTOR3 Playerpos,
	D3DXVECTOR3 rot,
	D3DXVECTOR2 TexNum,
	D3DXVECTOR2 TexMove,
	int nAnimCounter,
	D3DXVECTOR2 nSplit,
	ANIMPATTERN AnimPattern)
{
	CMouseTracking *pMouseTracking = NULL;
	pMouseTracking = new CMouseTracking(CManager::PRIORITY_EFFECT);		//メモリ確保
										//NULLチェック
	if (pMouseTracking != NULL)
	{
		pMouseTracking->Init(pos,
			move,
			color,
			Mincolor,
			Size,
			MinSize,
			nLife, nType,
			Endpos, Diffusion,
			UninitVectl, Synthetic,
			Distance, Playerpos, rot,
			TexNum, TexMove, nAnimCounter, nSplit, AnimPattern);
	}

	return pMouseTracking;
}
