#pragma once
#include <iostream>


// シングルトンを実現するテンプレートクラス
template <typename T>
class Singleton
{
public:
	// インスタンスを取得する
	static T* getInstance()
	{
		static T* instance = nullptr; // スレッドセーフなシングルトン
		if (!instance)instance = new T();
		return instance;
	}

	// インスタンスを破棄する
	static void destroyInstance()
	{
		delete getInstance();
	}

protected:
	Singleton()
	{
	} // プライベートコンストラクタを使って外部からのインスタンス生成を防ぐ
	Singleton(const Singleton&) = delete; // コピーを禁止
	Singleton& operator=(const Singleton&) = delete; // 代入演算子を禁止
};
