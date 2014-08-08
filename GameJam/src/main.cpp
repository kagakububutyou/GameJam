//
// アプリ雛形
// ※ファイル分割対応版
//

#include "GameMain.h"
#include "main.h"

// ↑他の.cppファイルでは、必要なヘッダファイルを
//   適時インクルードする事
AppEnv *app_env;

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

		GM->Main();
		
  }
  
  // アプリ終了
}
