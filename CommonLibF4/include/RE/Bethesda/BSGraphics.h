#pragma once

#include "RE/Bethesda/BSTHashMap.h"

struct ID3D11Buffer;
struct ID3D11ComputeShader;
struct ID3D11DepthStencilView;
struct ID3D11Device;
struct ID3D11DeviceContext;
struct ID3D11DomainShader;
struct ID3D11HullShader;
struct ID3D11PixelShader;
struct ID3D11RenderTargetView;
struct ID3D11ShaderResourceView;
struct ID3D11Texture2D;
struct ID3D11UnorderedAccessView;
struct ID3D11VertexShader;
struct IDXGISwapChain;

namespace RE
{
	enum class DXGI_MODE_SCALING;
	enum class DXGI_MODE_SCANLINE_ORDER;

	class BSD3DResourceCreator;

	struct DXGI_RATIONAL
	{
	public:
		// members
		std::uint32_t numerator;    // 00
		std::uint32_t denominator;  // 04
	};
	static_assert(sizeof(DXGI_RATIONAL) == 0x08);

	struct BSGraphics
	{
		enum class TextureAddressMode;

		class RendererShadowState;
		class Texture;

		class ConstantGroup
		{
		public:
			// members
			ID3D11Buffer* buffer{ nullptr };    // 00
			float* data{ nullptr };             // 08
			bool dataIsCPUWorkBuffer{ false };  // 10
		};
		static_assert(sizeof(ConstantGroup) == 0x18);

		class ComputeShader
		{
		public:
			// members
			std::uint32_t id{ 0 };                         // 00
			ID3D11ComputeShader* shader{ nullptr };        // 08
			std::uint32_t byteCodeSize{ 0 };               // 10
			BSGraphics::ConstantGroup constantBuffers[3];  // 18
			std::uint64_t shaderDesc{ 0 };                 // 60
			std::int8_t constantTable[32]{ 0 };            // 68
		};
		static_assert(sizeof(ComputeShader) == 0x88);

		class DomainShader
		{
		public:
			// members
			std::uint32_t id{ 0 };                              // 00
			ID3D11DomainShader* shader{ nullptr };              // 08
			std::uint32_t byteCodeSize{ 0 };                    // 10
			BSGraphics::ConstantGroup constantBuffers[3]{ 0 };  // 18
			std::uint64_t shaderDesc{ 0 };                      // 60
			std::int8_t constantTable[32]{ 0 };                 // 68
		};
		static_assert(sizeof(DomainShader) == 0x88);

		class HullShader
		{
		public:
			// members
			std::uint32_t id{ 0 };                         // 00
			ID3D11HullShader* shader{ nullptr };           // 08
			std::uint32_t byteCodeSize{ 0 };               // 10
			BSGraphics::ConstantGroup constantBuffers[3];  // 18
			std::uint64_t shaderDesc{ 0 };                 // 60
			std::int8_t constantTable[32]{ 0 };            // 68
		};
		static_assert(sizeof(HullShader) == 0x88);

		class PixelShader
		{
		public:
			// members
			std::uint32_t id{ 0 };                         // 00
			ID3D11PixelShader* shader{ nullptr };          // 08
			BSGraphics::ConstantGroup constantBuffers[3];  // 10
			std::int8_t constantTable[32]{ 0 };            // 58
		};
		static_assert(sizeof(PixelShader) == 0x78);

		class VertexShader
		{
		public:
			// members
			std::uint32_t id{ 0 };                         // 00
			ID3D11VertexShader* shader{ nullptr };         // 08
			std::uint32_t byteCodeSize{ 0 };               // 10
			BSGraphics::ConstantGroup constantBuffers[3];  // 18
			std::uint64_t shaderDesc{ 0 };                 // 60
			std::int8_t constantTable[32]{ 0 };            // 68
		};
		static_assert(sizeof(VertexShader) == 0x88);

		class CubeMapRenderTarget
		{
		public:
			// members
			ID3D11Texture2D* texture;           // 00
			ID3D11RenderTargetView* rtView[6];  // 08
			ID3D11ShaderResourceView* srView;   // 38
		};
		static_assert(sizeof(CubeMapRenderTarget) == 0x40);

		class DepthStencilTarget
		{
		public:
			// members
			ID3D11Texture2D* texture;                               // 00
			ID3D11DepthStencilView* dsView[4];                      // 08
			ID3D11DepthStencilView* dsViewReadOnlyDepth[4];         // 28
			ID3D11DepthStencilView* dsViewReadOnlyStencil[4];       // 48
			ID3D11DepthStencilView* dsViewReadOnlyDepthStencil[4];  // 68
			ID3D11ShaderResourceView* srViewDepth;                  // 88
			ID3D11ShaderResourceView* srViewStencil;                // 90
		};
		static_assert(sizeof(DepthStencilTarget) == 0x98);

		class RenderTarget
		{
		public:
			// members
			ID3D11Texture2D* texture;              // 00
			ID3D11Texture2D* copyTexture;          // 08
			ID3D11RenderTargetView* rtView;        // 10
			ID3D11ShaderResourceView* srView;      // 18
			ID3D11ShaderResourceView* copySRView;  // 20
			ID3D11UnorderedAccessView* uaView;     // 28
		};
		static_assert(sizeof(RenderTarget) == 0x30);

		class RendererWindow
		{
		public:
			void* hwnd;
			std::int32_t windowX;
			std::int32_t windowY;
			std::int32_t windowWidth;
			std::int32_t windowHeight;
			IDXGISwapChain* swapChain;
			RenderTarget swapChainRenderTarget;
		};
		static_assert(sizeof(RendererWindow) == 0x50);

		class RendererData
		{
		public:
			[[nodiscard]] static RendererData* GetSingleton()
			{
				REL::Relocation<RendererData**> singleton{ REL::ID(1235449) };
				return *singleton;
			}

			// members
			RendererShadowState* shadowState;             // 0000
			BSD3DResourceCreator* resourceCreator;        // 0008
			std::uint32_t adapter;                        // 0010
			DXGI_RATIONAL desiredRefreshRate;             // 0014
			DXGI_RATIONAL actualRefreshRate;              // 001C
			DXGI_MODE_SCALING scaleMode;                  // 0024
			DXGI_MODE_SCANLINE_ORDER scanlineMode;        // 0028
			std::int32_t fullScreen;                      // 002C
			bool appFullScreen;                           // 0030
			bool borderlessWindow;                        // 0031
			bool vsync;                                   // 0032
			bool initialized;                             // 0033
			bool requestWindowSizeChange;                 // 0034
			std::uint32_t newWidth;                       // 0038
			std::uint32_t newHeight;                      // 003C
			std::uint32_t presentInterval;                // 0040
			ID3D11Device* device;                         // 0048
			ID3D11DeviceContext* context;                 // 0050
			RendererWindow renderWindow[32];              // 0058
			RenderTarget renderTargets[101];              // 0A58
			DepthStencilTarget depthStencilTargets[13];   // 1D48
			CubeMapRenderTarget cubeMapRenderTargets[2];  // 2500
			std::byte rendererLock[0x25A8 - 0x2580];      // 2580 - TODO
			const char* className;                        // 25A8
			void* instance;                               // 25B0
			bool nvapiEnabled;                            // 25B8
		};
		static_assert(sizeof(RendererData) == 0x25C0);

		class Renderer
		{
		public:
			using ResetRenderTargets_t = void (*)();

			// members
			bool skipNextPresent;                     // 00
			ResetRenderTargets_t resetRenderTargets;  // 08
			RendererData data;                        // 10
		};
		static_assert(sizeof(Renderer) == 0x25D0);
	};
	static_assert(std::is_empty_v<BSGraphics>);

	namespace BSShaderTechniqueIDMap
	{
		template <class T>
		struct HashPolicy
		{
			[[nodiscard]] std::uint32_t operator()(const T a_shader) const noexcept
			{
				assert(a_shader != nullptr);
				return a_shader->id;
			}
		};

		template <class T>
		struct ComparePolicy
		{
			[[nodiscard]] bool operator()(const T a_lhs, const T a_rhs) const noexcept
			{
				assert(a_lhs != nullptr);
				assert(a_rhs != nullptr);
				return a_lhs->id == a_rhs->id;
			}
		};

		template <class T>
		using MapType = BSTSet<T, HashPolicy<T>, ComparePolicy<T>>;
	}
}
