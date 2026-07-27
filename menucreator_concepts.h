#pragma once
#include <concepts>

namespace mcr_Concepts {
	template<typename T>
	concept Container = requires(T t) {
		// проверяет, есть ли функция-член t.size(), возвращающая size_t
		{ t.size() } -> std::convertible_to<std::size_t>;
		{ t[0] };			// есть ли хотя бы один элемент
	};
}