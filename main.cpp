#include "DxLib.h"
int Key[256]; // �L�[��������Ă���t���[�������i�[����

			  // �L�[�̓��͏�Ԃ��X�V����
int gpUpdateKey() {
	char tmpKey[256]; // ���݂̃L�[�̓��͏�Ԃ��i�[����
	GetHitKeyStateAll(tmpKey); // �S�ẴL�[�̓��͏�Ԃ𓾂�
	for (int i = 0; i<256; i++) {
		if (tmpKey[i] != 0) { // i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
			Key[i]++;     // ���Z
		}
		else {              // ������Ă��Ȃ����
			Key[i] = 0;   // 0�ɂ���
		}
	}
	return 0;
}


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SetGraphMode(640, 640, 32), ChangeWindowMode(TRUE);
	DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);


	////////////�叫�ړ�///////////////


	int x = 35;
	int y = 80;
	int taisyou;     // �摜�i�[�p�n���h��
	taisyou = LoadGraph("�叫.png"); // �摜�̃��[�h

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0) {

		DrawGraph(x, 300, taisyou, TRUE); //�摜�̕`��

		if (Key[KEY_INPUT_LEFT] >= 1) { // ���L�[��������Ă�����
			x = 80;                       // ���ֈړ�
		}
		if (Key[KEY_INPUT_DOWN] >= 1) { // ���L�[��������Ă�����
			x = 245;                      // ���ֈړ�
		}
		if (Key[KEY_INPUT_RIGHT] >= 1) { // �E�L�[��������Ă�����
			x = 455;                       // �E�ֈړ�
		}

		//}


		///////////////�����ړ�//////////////




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

	DxLib_End(); // DX���C�u�����I������
	return 0;

}