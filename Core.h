#pragma once
#include <cstdint>
#include <intrin.h>

#pragma intrinsic(__stosd)

namespace CPPSnake {
	
	using Int8 = std::int8_t;
	using UInt8 = std::uint8_t;
	using Byte = UInt8;

	using Int16 = std::int16_t;
	using UInt16 = std::uint16_t;
	using Int32 = std::int32_t;
	using UInt32 = std::uint32_t;
	using Int64 = std::int64_t;
	using UInt64 = std::uint64_t;

	using Float = float;
	using Double = double;
	using Bool = bool;
	using Char = char;
	using Void = void;

	template <typename T>
	struct Size2 {
		Size2() {}
		Size2 (const T& w, const T& h) : width(w), height(h) {}

		T width{};
		T height{};
	};

	using Size2UI32 = Size2<UInt32>;

	template <typename T>
	struct Coord2 {
		Coord2() {}
		Coord2 (const T& _x, const T& _y) : x(_x), y(_y) {}

		T(x) {};
		T(y) {};
	};
	using Coord2I32 = Coord2<Int32>;

	class BGRA32 {
	public:
		BGRA32 () {}
		BGRA32(Byte _b, Byte _g, Byte _r) : b(_b), g(_g), r(_r), a(255) {}
		BGRA32(Byte _b, Byte _g, Byte _r, Byte _a) : b(_b), g(_g), r(_r), a(_a) {}
		BGRA32(UInt32 val) : value(val) {}

		static UInt32 lerp(const BGRA32& c0, const BGRA32& c1, Float t) {
			if (t < 0.0f) t = 0.0f;
			else if (t > 1.0f) t = 1.0f;

			Float oneMinusT = 1.0f - t;
			Byte b = (Byte)(c0.b * oneMinusT + c1.b * t);
			Byte g = (Byte)(c0.g * oneMinusT + c1.g * t);
			Byte r = (Byte)(c0.r * oneMinusT + c1.r * t);
			Byte a = (Byte)(c0.a * oneMinusT + c1.a * t);

			return (UInt32)b | (UInt32)((UInt32)g << 8) |
				(UInt32)((UInt32)r << 16) | (UInt32)((UInt32)a << 24);
		}

		union {
			struct {
				Byte b;
				Byte g;
				Byte r;
				Byte a;
			};
			UInt32 value{};
		};
	};
}