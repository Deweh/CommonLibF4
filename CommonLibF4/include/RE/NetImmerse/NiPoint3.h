#pragma once

namespace RE
{
	class NiTransform;

	class NiPoint3
	{
	public:
		using value_type = float;
		using size_type = std::size_t;
		using reference = value_type&;
		using const_reference = const value_type&;
		using pointer = value_type*;
		using const_pointer = const value_type*;

		[[nodiscard]] reference operator[](size_type a_pos) noexcept
		{
			assert(a_pos < 3);
			return reinterpret_cast<pointer>(std::addressof(x))[a_pos];
		}

		[[nodiscard]] const_reference operator[](size_type a_pos) const noexcept
		{
			assert(a_pos < 3);
			return reinterpret_cast<const_pointer>(std::addressof(x))[a_pos];
		}

		// members
		value_type x{ 0.0F };  // 0
		value_type y{ 0.0F };  // 4
		value_type z{ 0.0F };  // 8

		void TransformPoint(const NiTransform& a_transform, NiPoint3& a_pointOut)
		{
			using func_t = decltype(&NiPoint3::TransformPoint);
			REL::Relocation<func_t> func{ REL::ID(558870) };
			return func(this, a_transform, a_pointOut);
		}

		void operator+=(const RE::NiPoint3& other) {
			x += other.x;
			y += other.y;
			z += other.z;
		}

		void operator-=(const RE::NiPoint3& other) {
			x -= other.x;
			y -= other.y;
			z -= other.z;
		}

		template <class Archive>
		void serialize(Archive& ar)
		{
			ar(x, y, z);
		}
	};
	static_assert(sizeof(NiPoint3) == 0xC);

	class alignas(0x10) NiPoint3A :
		public NiPoint3
	{
	public:
	};
	static_assert(sizeof(NiPoint3A) == 0x10);
}
