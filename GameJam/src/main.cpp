//
// アプリ雛形
// ※ファイル分割対応版
//

#include "GameMain.h"

// ↑他の.cppファイルでは、必要なヘッダファイルを
//   適時インクルードする事
AppEnv *app_env;
// アプリのウインドウサイズ
enum Window {
  WIDTH  = 1280,
  HEIGHT = 720
};


// 
// メインプログラム
// 
int main() {
	// アプリウインドウの準備
	app_env = new AppEnv(Window::WIDTH, Window::HEIGHT, false, true);

	GM = new GameMain();

	//	Escapeキーでプログラムを終了
	while (!app_env->isPressKey(GLFW_KEY_ESCAPE)) 
	{
		// アプリウインドウが閉じられたらプログラムを終了
		if (!app_env->isOpen()) return 0;
    
		// 描画準備
		app_env->setupDraw();

		GM->Main();

		// 画面更新
		app_env->update();
  }
  
  // アプリ終了
}
