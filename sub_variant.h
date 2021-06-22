#pragma once

#include <type_traits>

namespace sub {

	template<typename T, typename... Types>
	struct is_included_in;

	template<typename T>
	struct is_included_in<T> : std::false_type {};

	template<typename T, typename... Types>
	struct is_included_in<T, T, Types...> : std::true_type {};

	template<typename T, typename H, typename... Types>
	struct is_included_in<T, H, Types...> : is_included_in<T, Types...> {};

	template< class T, typename... Types >
	inline constexpr bool is_included_in_v = is_included_in<T, Types...>::value;

	template<typename... T>
	class variant {

	public:
		template<typename... Candidates>
		struct is_sub_variant;

		template<typename Candidate, typename... Rest>
		struct is_sub_variant<Candidate, Rest...> : std::bool_constant<is_included_in_v<Candidate, T...> && is_sub_variant<Rest...>::value> {};

		template<typename Candidate>
		struct is_sub_variant<Candidate> : std::bool_constant<is_included_in_v<Candidate, T...>> {};

		template<typename Candidate, typename... Rest>
		static inline constexpr bool is_sub_variant_v = is_sub_variant<Candidate, Rest...>::value;
	};
}