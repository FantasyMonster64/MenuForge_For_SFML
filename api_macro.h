#pragma once

#ifdef _WIN32 
	#ifdef MYLIB_EXPORTS	// Если мы создаем библиотеку
		#define MYLIB_API __declspec(dllexport) 
	#else					// Если мы используем библиотеку
		#define MYLIB_API __declspec(dllimport) 
	#endif
#else
	#define MYLIB_API		// Для других платформ можно оставить пустым
#endif