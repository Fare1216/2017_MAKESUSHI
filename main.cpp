#include "DxLib.h"
int Key[256]; // キーが押されているフレーム数を格納する

			  // キーの入力状態を更新する
int gpUpdateKey() {
	char tmpKey[256]; // 現在のキーの入力状態を格納する
	GetHitKeyStateAll(tmpKey); // 全てのキーの入力状態を得る
	for (int i = 0; i<256; i++) {
		if (tmpKey[i] != 0) { // i番のキーコードに対応するキーが押されていたら
			Key[i]++;     // 加算
		}
		else {              // 押されていなければ
			Key[i] = 0;   // 0にする
		}
	}
	return 0;
}


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SetGraphMode(640, 640, 32), ChangeWindowMode(TRUE);
	DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);


	////////////大将移動///////////////


	int x = 35;
	int y = 80;
	int taisyou;     // 画像格納用ハンドル
	taisyou = LoadGraph("大将.png"); // 画像のロード

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0) {

		DrawGraph(x, 300, taisyou, TRUE); //画像の描画

		if (Key[KEY_INPUT_LEFT] >= 1) { // 左キーが押されていたら
			x = 80;                       // 左へ移動
		}
		if (Key[KEY_INPUT_DOWN] >= 1) { // 下キーが押されていたら
			x = 245;                      // 下へ移動
		}
		if (Key[KEY_INPUT_RIGHT] >= 1) { // 右キーが押されていたら
			x = 455;                       // 右へ移動
		}

		//}


		///////////////すし移動//////////////




		int Handle;
		Handle = LoadGraph("maguro.png");

		int HandleB;
		HandleB = LoadGraph("ootoro.png");

		int HandleC;
		HandleC = LoadGraph("tamago.png");

		int HandleD;
		HandleD = LoadGraph("hamachi.png");

		int HandleE;
		HandleE = LoadGraph("waku.png");

		//while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0) {
		DrawGraph(90, 500, Handle, TRUE);
		DrawGraph(210, 500, HandleB, TRUE);
		DrawGraph(330, 500, HandleC, TRUE);
		DrawGraph(450, 500, HandleD, TRUE);
		DrawGraph(y, 490, HandleE, TRUE);
		if (Key[KEY_INPUT_A] >= 1) {
			y = 80;
		}
		if (Key[KEY_INPUT_S] >= 1) {
			y = 200;
		}
		if (Key[KEY_INPUT_D] >= 1) {
			y = 320;
		}
		if (Key[KEY_INPUT_F] >= 1) {
			y = 440;
		}

	}

	////////////////////////////////

	DxLib_End(); // DXライブラリ終了処理
	return 0;

}