#ifndef MAP_MAKER_TYPES_HPP
#define MAP_MAKER_TYPES_HPP
template<int x>
using int_t = std::integral_constant<int, x>;
template<bool x>
using bool_t = std::integral_constant<bool, x>;
#endif //MAP_MAKER_TYPES_HPP
