//*****************************************************************************
// シーン2D処理 [Scene2D.h]
// Author : 佐藤秀亮
//*****************************************************************************
#ifndef _SCENE2D_H_
#define _SCENE2D_H_

//*****************************************************************************
// インクルード
//*****************************************************************************
#include "main.h"
#include "Scene.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define FVF_VERTEX_2D	(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)

//*****************************************************************************
// 構造体定義
//*****************************************************************************
// 頂点フォーマットに合わせた構造体
typedef struct
{
	D3DXVECTOR3 pos;	// 頂点処理
	float rhw;			// 1.0で固定
	D3DCOLOR col;		// 頂点カラー
	D3DXVECTOR2 tex;	// テクスチャの座標
} VERTEX_2D;

//*****************************************************************************
//オブジェクトクラス
//*****************************************************************************
class CScene2D : public CScene
{
public:
	CScene2D(int nPriority = 3);
	~CScene2D();

	HRESULT Init(D3DXVECTOR3 pos);	//初期化
	void Uninit();				//終了
	void Update();				//更新
	void Draw();				//描画

	static void UninitTexture();

	static void CreateTexture();//テクスチャ読み込み


	void SetPosition(D3DXVECTOR3 pos);		//pos更新用
	D3DXVECTOR3 GetPosition() { return m_pos; }				//pos更新するためにゲット

	float GetHight() { return  m_Size.y; }			//pos更新するためにゲット
	float GetWhidth() { return  m_Size.x; }			//pos更新するためにゲッ

	void SetTexture(int nTex) { m_nType = nTex; }		//テクスチャタイプ

	void ColorChange(D3DCOLORVALUE color);	//カラー変更

	void FadeColorChange(int Alpha);		//フェード用α変更

	void SetTexAnim(D3DXVECTOR2 TexPattern, D3DXVECTOR2 TexAnimSize);						//テクスチャパターン番号、パターン１つのサイズ
	void TexMove(D3DXVECTOR2 MoveTex);				//テクスチャ座標の更新

	void SetGaugeScele(float Whidth, float Hight);				//ゲージタイプのスケール変更
	void SetRotate(D3DXVECTOR3 pos, float Rotate, float Rotate2, float Vectol);			//回転
	void SetfleeSizePos(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2, D3DXVECTOR3 pos3, D3DXVECTOR3 pos4);	//自由な座標指定
	void SecondColorChange(D3DCOLORVALUE color, D3DCOLORVALUE Secondcolor);	//２点変更

protected:
	int m_nAnimCount;
	int m_nSetAnimCnt;
	D3DXVECTOR2 m_nSplit;
	D3DXVECTOR2 m_MaxSplit;
	D3DXVECTOR2 m_PatternSize;
	D3DXVECTOR2 m_TexSize;				//テクスチャサイズ
	D3DXVECTOR2 m_TexNum;
	D3DXVECTOR2 m_Size;				//サイズ

private:

	static LPDIRECT3DTEXTURE9 m_Texture[MAX_TEXTURE];				//テクスチャーポインタ
	static int m_nMaxTex;											//使用する最大テクスチャ
	D3DXVECTOR3 m_pos;				//位置

	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff = NULL;	//頂点バッファへのポインタ

	D3DXVECTOR2 m_TexMove;


	int m_nType;					//種類

	int m_Texpos;					//テクスチャ座標


									//カラー値
};
#endif
