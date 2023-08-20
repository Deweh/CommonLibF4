#pragma once

namespace RE
{
	namespace SendHUDMessage
	{
		inline void PopHUDMode(const HUDModeType& a_hudMode)
		{
			using func_t = decltype(&PopHUDMode);
			REL::Relocation<func_t> func{ REL::ID(1495042) };
			return func(a_hudMode);
		}

		inline void PushHUDMode(const HUDModeType& a_hudMode)
		{
			using func_t = decltype(&SendHUDMessage::PushHUDMode);
			REL::Relocation<func_t> func{ REL::ID(1321764) };
			return func(a_hudMode);
		}

		inline void ShowHUDMessage(const char* a_message, const char* a_sound, bool a_throttle, bool a_warning)
		{
			using func_t = decltype(&ShowHUDMessage);
			REL::Relocation<func_t> func{ REL::ID(1163005) };
			return func(a_message, a_sound, a_throttle, a_warning);
		}

		inline void ClearMessages()
		{
			using func_t = decltype(&ClearMessages);
			REL::Relocation<func_t> func{ REL::ID(973227) };
			return func();
		}
	}
}
