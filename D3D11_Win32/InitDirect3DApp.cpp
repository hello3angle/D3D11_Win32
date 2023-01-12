#include "InitDirect3DApp.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, PSTR cmdLine, int showCmd)
{
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	InitDirect3DApp theApp(hInstance);

	if (!theApp.Init())
		return 0;

	return theApp.Run();
}

InitDirect3DApp::InitDirect3DApp(HINSTANCE hInstance)
	: D3DApp(hInstance)
{
	//DXGI_FORMAT;
	//D3D11_BIND_RENDER_TARGET
	//DXGI_SAMPLE_DESC
	//D3D_FEATURE_LEVEL
	//D3D_DRIVER_TYPE_HARDWARE
	//D3D11_CREATE_DEVICE_DEBUG
	//DXGI_SWAP_CHAIN_DESC
	//DXGI_MODE_DESC
	//DXGI_USAGE
	//DXGI_USAGE_RENDER_TARGET_OUTPUT
	//DXGI_SWAP_EFFECT
	//DXGI_SWAP_CHAIN_FLAG
	//DXGI_MODE_SCANLINE_ORDER
}

InitDirect3DApp::~InitDirect3DApp()
{
	
}

bool InitDirect3DApp::Init()
{
	if (!D3DApp::Init())
		return false;

	return true;
}

void InitDirect3DApp::OnResize()
{
	D3DApp::OnResize();

}

void InitDirect3DApp::UpdateScene(float dt)
{

}

void InitDirect3DApp::DrawScene()
{
	assert(md3dImmediateContext);
	assert(mSwapChain);

	md3dImmediateContext->ClearRenderTargetView(mRenderTargetView,
		reinterpret_cast<const float*>(&Colors::Blue));

	md3dImmediateContext->ClearDepthStencilView(mDepthStencilView,
		D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);

	HR(mSwapChain->Present(0, 0));
}