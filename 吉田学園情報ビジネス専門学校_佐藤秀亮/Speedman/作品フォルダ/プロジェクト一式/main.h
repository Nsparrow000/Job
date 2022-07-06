//=============================================================================
//
// メイン処理 [main.h]
// Author : 三上航世
//
//=============================================================================
#ifndef _MAIN_H_
#define _MAIN_H_
#define DIRECTINPUT_VERSION (0x0800)
#define _CRT_SECURE_NO_WARNINGS
//*****************************************************************************
// ヘッダファイルのインクルード
//*****************************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "d3dx9.h"   //描画に必要
#include "dinput.h"  //入力処理に必要
#include "xaudio2.h"   //サウンド関連

//*****************************************************************************
// ライブラリファイルのリンク
//*****************************************************************************
#pragma comment(lib,"d3d9.lib")   //描画に必要
#pragma comment(lib,"d3dx9.lib")   //[d3d9.lib]の拡張ライブラリ
#pragma comment(lib,"dxguid.lib")  //DirectXコンポーネント(部品)使用に必要
#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"dinput8.lib") //入力処理に必要

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define SCREEN_WIDTH (1280)                                          //ウィンドウの幅
#define SCREEN_HEIGHT (720)                                          //ウィンドウの高さ　16:9のサイズ
#define FVF_VERTEX_2D (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1) //頂点フォーマット
#define FVF_VERTEX_3D (D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE | D3DFVF_TEX1) //頂点フォーマット

//*****************************************************************************
// 構造体定義
//*****************************************************************************
//前方宣言
//class CScene2D;

//プロトタイプ宣言
int GetFPS();
//CScene2D **GetScene();
#endif