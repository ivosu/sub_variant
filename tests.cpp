#include "sub_variant.h"

#include <map>

int main() {
	static_assert(sub::variant<int>::is_sub_variant_v<int>);
	static_assert(sub::variant<int, double>::is_sub_variant_v<int>);
	static_assert(sub::variant<double, int>::is_sub_variant_v<int>);
	static_assert(sub::variant<int, double>::is_sub_variant_v<int, double>);
	static_assert(sub::variant<int, double>::is_sub_variant_v<double>);
	static_assert(sub::variant<int, double>::is_sub_variant_v<double, int>);
	static_assert(sub::variant<int, std::map<int, int>, double>::is_sub_variant_v<int, double>);
	static_assert(sub::variant<int, std::map<int, int>, double>::is_sub_variant_v<double, int>);
	static_assert(sub::variant<std::map<int, int>, int, double>::is_sub_variant_v<double, int>);

	static_assert(sub::variant<int, double>::is_sub_variant_v<double, int, std::map<int, int>> == false);
	static_assert(sub::variant<int>::is_sub_variant_v<double, int> == false);
	static_assert(sub::variant<int>::is_sub_variant_v<int, double> == false);
}