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

		RE::NiPoint3 GetVelocity(const RE::NiPoint3& endPoint, float timeDiff) {
			return (endPoint - (*this)) / timeDiff; 
		}

		bool operator==(const NiPoint3& a_rhs) const
		{
			return x == a_rhs.x && y == a_rhs.y && z == a_rhs.z;
		}

		bool operator!=(const NiPoint3& a_rhs) const
		{
			return !operator==(a_rhs);
		}

		NiPoint3 operator+(const NiPoint3& a_rhs) const
		{
			return {
				x + a_rhs.x,
				y + a_rhs.y,
				z + a_rhs.z
			};
		}

		NiPoint3 operator-(const NiPoint3& a_rhs) const
		{
			return {
				x - a_rhs.x,
				y - a_rhs.y,
				z - a_rhs.z
			};
		}

		float operator*(const NiPoint3& a_rhs) const
		{
			return x * a_rhs.x + y * a_rhs.y + z * a_rhs.z;
		}

		NiPoint3 operator*(float a_scalar) const
		{
			return { x * a_scalar, y * a_scalar, z * a_scalar };
		}

		NiPoint3 operator/(float a_scalar) const
		{
			return { x / a_scalar, y / a_scalar, z / a_scalar };
		}

		NiPoint3 operator-() const
		{
			return { -x, -y, -z };
		}

		NiPoint3& operator+=(const NiPoint3& a_rhs)
		{
			x += a_rhs.x;
			y += a_rhs.y;
			z += a_rhs.z;
			return *this;
		}

		NiPoint3& operator-=(const NiPoint3& a_rhs)
		{
			x -= a_rhs.x;
			y -= a_rhs.y;
			z -= a_rhs.z;
			return *this;
		}

		NiPoint3& operator*=(const NiPoint3& a_rhs)
		{
			x *= a_rhs.x;
			y *= a_rhs.y;
			z *= a_rhs.z;
			return *this;
		}

		NiPoint3& operator/=(const NiPoint3& a_rhs)
		{
			x /= a_rhs.x;
			y /= a_rhs.y;
			z /= a_rhs.z;
			return *this;
		}

		NiPoint3& operator*=(float a_scalar)
		{
			x *= a_scalar;
			y *= a_scalar;
			z *= a_scalar;
			return *this;
		}

		NiPoint3& operator/=(float a_scalar)
		{
			return operator*=(1.0F / a_scalar);
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
