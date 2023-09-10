#pragma once

namespace RE
{
	template <class T>
	class hkRefPtr
	{
	public:
		explicit hkRefPtr() {}

		explicit hkRefPtr(T* ptr)
		{
			_ptr = ptr;
			TryAttach();
		}

		~hkRefPtr() noexcept
		{
			TryDetach();
		}

		T* get() const
		{
			return _ptr;
		}

		T* operator->() const
		{
			return _ptr;
		}

		T& operator*() const
		{
			return _ptr;
		}

		void operator=(T* ptr)
		{
			TryDetach();
			_ptr = ptr;
			TryAttach();
		}

		void TryAttach()
		{
			if (_ptr) {
				_ptr->addReference();
			}
		}

		void TryDetach()
		{
			if (_ptr) {
				_ptr->removeReference();
			}
		}

	protected:
		T* _ptr{ nullptr };
	};
}
