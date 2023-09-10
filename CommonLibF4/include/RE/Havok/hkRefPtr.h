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

		hkRefPtr(hkRefPtr& other) {
			reset(other);
		}
		
		hkRefPtr(hkRefPtr&& other) {
			reset(other.get());
			other.reset();
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
			reset(ptr);
		}

		void operator=(hkRefPtr<T>& other) {
			reset(other.get());
		}

		void operator=(hkRefPtr<T>&& other) {
			reset(other.get());
			other.reset();
		}

		void reset() {
			TryDetach();
			_ptr = nullptr;
		}

		void reset(T* ptr) {
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
