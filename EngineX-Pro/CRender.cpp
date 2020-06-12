#include "stdafx.h"
#include "CRender.h"
struct SD3DVertex{
	float x, y, z, rhw;
	DWORD colour;
};

CRender::CRender() {}
CRender::~CRender() {}
#ifdef MEDIUM
#define SetVertex SetFVF
#define IndexBuffer LPDIRECT3DINDEXBUFFER9
#define VertexBuffer LPDIRECT3DVERTEXBUFFER9
#else
#define SetVertex SetVertexShader
#define IndexBuffer LPDIRECT3DINDEXBUFFER8
#define VertexBuffer LPDIRECT3DVERTEXBUFFER8
#endif
void CRender::Circle(int x, int y, int z, int radius, int points, D3DCOLOR colour) {
	SD3DVertex* pVertex = new SD3DVertex[points + 1];
	for (int i = 0; i <= points; i++) {
		pVertex[i] = { x + radius * cos(D3DX_PI * (i / (points / 2.0f))), y - radius * sin(D3DX_PI * (i / (points / 2.0f))), 0.0f, 1.0f, colour };
	}
	Device::pDevice->SetVertex(D3DFVF_XYZRHW | D3DFVF_DIFFUSE);
	Device::pDevice->DrawPrimitiveUP(D3DPT_LINESTRIP, points, pVertex, sizeof(SD3DVertex));
	delete[] pVertex;
}

struct SPDTVertexRaw
{
	float px, py, pz;
	DWORD diffuse;
	float u, v;
};
void CRender::Line3D(int x, int y, int z, int ex, int ey, int ez, D3DCOLOR colour) {
	SD3DVertex* pVertex = new SD3DVertex[2];
	pVertex[0] = { (float)x, (float)y,(float)z, 1.0f, colour };
	pVertex[1] = { (float)ex, (float)ey, (float)ez, 1.0f, colour };

	for (int i = 0; i <= 2; i++) {
		Device::pDevice->SetTexture(0, NULL);
		Device::pDevice->SetTexture(1, NULL);
		Device::pDevice->SetVertex(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);
		Device::pDevice->DrawPrimitiveUP(D3DPT_LINESTRIP, 1, pVertex, sizeof(SD3DVertex));
	}
	delete[] pVertex;
}

void CRender::Box3D(int sx, int sy, int sz, int ex, int ey, int ez, D3DCOLOR ms_diffuseColor) {
	SD3DVertex* pVertex = new SD3DVertex[8];
	pVertex[0] = { (float)sx, (float)sy,(float)sz, 1.0f, ms_diffuseColor };
	pVertex[1] = { (float)ex, (float)sy, (float)sz, 1.0f, ms_diffuseColor };
	pVertex[2] = { (float)sx, (float)sy, (float)sz, 1.0f, ms_diffuseColor };
	pVertex[3] = { (float)sx, (float)ey, (float)ez, 1.0f, ms_diffuseColor };
	pVertex[4] = { (float)ex, (float)sy, (float)sz, 1.0f, ms_diffuseColor };
	pVertex[5] = { (float)ex, (float)ey, (float)ez, 1.0f, ms_diffuseColor };
	pVertex[6] = { (float)sx, (float)ey, (float)ez, 1.0f, ms_diffuseColor };
	pVertex[7] = { (float)ex + 1.0f, (float)ey, (float)ez, 1.0f, ms_diffuseColor };
	for (int i = 0; i <= 8; i++) {
		Device::pDevice->SetTexture(0, NULL);
		Device::pDevice->SetTexture(1, NULL);
		Device::pDevice->SetVertex(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);
		Device::pDevice->DrawPrimitiveUP(D3DPT_LINELIST, 12, pVertex, sizeof(SD3DVertex));
	}
	delete[] pVertex;
}

const WORD c_FillRectIndices[20] = { 2, 2, 1, 2, 2, 1,2, 2, 1,2, 2, 1,2, 2, 1,2, 2, 1, 2,2 };
void CRender::Cube3D(int sx, int sy, int sz, int ex, int ey, int ez, D3DCOLOR ms_diffuseColor) {
	SD3DVertex* pVertex = new SD3DVertex[8];
	pVertex[0] = { (float)sx, (float)sy,(float)sz, 1.0f, ms_diffuseColor };
	pVertex[1] = { (float)ex, (float)sy, (float)sz, 1.0f, ms_diffuseColor };
	pVertex[2] = { (float)sx, (float)ey, (float)sz, 1.0f, ms_diffuseColor };
	pVertex[3] = { (float)ex, (float)ey, (float)sz, 1.0f, ms_diffuseColor };
	pVertex[4] = { (float)sx, (float)sy, (float)ez, 1.0f, ms_diffuseColor };
	pVertex[5] = { (float)ex, (float)sy, (float)ez, 1.0f, ms_diffuseColor };
	pVertex[6] = { (float)sx, (float)ey, (float)ez, 1.0f, ms_diffuseColor };
	pVertex[7] = { (float)ex, (float)ey, (float)ez, 1.0f, ms_diffuseColor };
	for (int i = 0; i <= 8; i++) {
		Device::pDevice->SetTexture(0, NULL);
		Device::pDevice->SetTexture(1, NULL);
		Device::pDevice->SetVertex(D3DFVF_XYZ | D3DFVF_TEX1 | D3DFVF_DIFFUSE);
		D3DXMATRIX matWorld;
		D3DXMatrixIdentity(&matWorld);
		Device::pDevice->DrawPrimitiveUP(D3DPT_LINELIST, 20, pVertex, sizeof(SD3DVertex));
		//Device::pDevice->DrawIndexedPrimitiveUP(D3DPT_TRIANGLELIST, 0, 8, 12, c_FillRectIndices, D3DFMT_INDEX16, pVertex, sizeof(SD3DVertex));
	}
	delete[] pVertex;
}

void CRender::Circle3D(int fx, int fy, int fz, int radius, int points, D3DCOLOR colour) {
	int count;
	float theta, delta;
	std::vector<D3DXVECTOR3> pts;
	pts.clear();
	pts.resize(points);
	theta = 0.0;
	delta = 2 * D3DX_PI / float(points);
	for (count = 0; count < points; count++)
	{
		pts[count] = D3DXVECTOR3(radius * cosf(theta), radius * sinf(theta), 0.0f);
		theta += delta;
	}
	for (count = 0; count < points - 1; count++)
	{
		Line3D(fx + pts[count].x, fy + pts[count].y, fz + pts[count].z,
			fx + pts[count + 1].x, fy + pts[count + 1].y, fz + pts[count + 1].z, colour);
	}
	Line3D(fx + pts[points - 1].x, fy + pts[points - 1].y, fz + pts[points - 1].z,
		fx + pts[0].x, fy + pts[0].y, fz + pts[0].z, colour);
}


//void RenderBox3D(DWORD* instance) {
//	D3DXVECTOR3 center;
//	float r;
//	GameFunctions::GetBoundingSphere(GameFunctions::GetGraphicThingInstancePtr(instance), center, r);
//	Settings::box_posx = center.x;
//	Settings::box_posy = center.y;
//	Settings::box_posz = center.z + float(220);
//	GameFunctions::SetDiffuseColor(1.0f, 0.0f, 0.0f, 1.0f);
//	Device::pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
//	GameFunctions::RenderSphere(NULL, center.x, center.y, center.z, r, D3DFILL_WIREFRAME);
//	GameFunctions::RenderCircle3D(Settings::box_posx, Settings::box_posy, Settings::box_posz, 500.0f, 50);
//
//}
//
//void RenderCircle() {
//	//ID3DXFont* g_font = NULL;
//	//HFONT hFont = CreateFont(0, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
//	//	ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
//	//	DEFAULT_QUALITY, DEFAULT_PITCH, L"Arial");
//	//HFONT hFont = CreateFont(14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, L"Arial");
//	//D3DXCreateFont(pDevice, hFont, &g_font);
//	//static char cTitle[256];
//	//sprintf_s(cTitle, "%s | %s\nFrame Rate: %i", "C4US", "METIN", pRender->FrameRate());
//	//pRender->GradientBoxOutlined(pDevice, 40, 70, pRender->StringWidth(pDevice, g_font, cTitle) + 4, 25, 1, D3DCOLOR_RGBA(100, 100, 100, 255), D3DCOLOR_RGBA(50, 50, 50, 255), D3DCOLOR_RGBA(0, 0, 0, 255), true);
//	//pRender->String(pDevice, 42, 70, D3DCOLOR_RGBA(255, 255, 255, 255), g_font, true, cTitle);
//	D3DXVECTOR3 kPPosCur; //world position to project to screen {x,y,z}
//	D3DXVECTOR3 screenPos;
//	DWORD* pCharInstance = GameFunctions::PlayerNEW_GetMainActorPtr();
//	GameFunctions::InstanceBaseNEW_GetPixelPosition(pCharInstance, &kPPosCur);
//	//D3DXVECTOR3 kD3DVt3Cur(kPPosCur.x, -kPPosCur.y, kPPosCur.z);
//	//D3DXVECTOR3 kD3DVt3Dst;
//	//D3DXVECTOR3 kD3DVt3AdvDir(0.0f, -1.0f, 0.0f);
//	//D3DXMATRIX kD3DMatAdv;
//	//D3DXMatrixRotationZ(&kD3DMatAdv, D3DXToRadian(GameFunctions::CameraRotation()));
//	//D3DXVec3TransformCoord(&kD3DVt3AdvDir, &kD3DVt3AdvDir, &kD3DMatAdv);
//	//D3DXVec3Scale(&kD3DVt3AdvDir, &kD3DVt3AdvDir, 300.0f);
//	//D3DXVec3Add(&kD3DVt3Dst, &kD3DVt3AdvDir, &kD3DVt3Cur);
//	//D3DXVECTOR3 kPPosDst;
//	//kPPosDst.x = +kD3DVt3Dst.x;
//	//kPPosDst.y = -kD3DVt3Dst.y;
//	//kPPosDst.z = +kD3DVt3Dst.z;
//	//GameFunctions::GetCenterPosition(&pos);
//	GameFunctions::ProjectPosition(kPPosCur.x, -kPPosCur.y, kPPosCur.z, &screenPos.x, &screenPos.y, &screenPos.z);
//	GameFunctions::SetDiffuseColor(1.0f, 0.0f, 0.0f, 1.0f);
//	//WorldToScreen(pDevice, &screenPos, &screenPos);
//	//pRender->Circle3D(pDevice, screenPos.x + 960.0f, screenPos.y + 510.0f, Settings::BoostSpeed2, 500, 50, D3DCOLOR_RGBA(100, 100, 100, 255));
//	GameFunctions::RenderLine3D(1920.0f / 3, 1080.0f / 3, Settings::BoostSpeed2, 1920.0f / 2, 1080.0f / 2, Settings::BoostSpeed2);
//}


DWORD textureFactor;
DWORD colorArg1;
DWORD colorArg2;
DWORD colorOp;
DWORD alphaArg1;
DWORD alphaArg2;
DWORD alphaOp;
DWORD alpaBlend;
DWORD srcBlend;
DWORD destBlend;

DWORD FillOld;
D3DXMATRIX stateold;

DWORD culling;
DirectTexture Red, Green, Blue, Yellow;
HRESULT GenerateTexture(DirectDevice pDevice, DirectTexture* ppD3Dtex, DWORD colour32)
{
	//pDevice->CreateTexture(8, 8, 1, 0, D3DFMT_A4R4G4B4, D3DPOOL_MANAGED, ppD3Dtex);
	WORD colour16 = ((WORD)((colour32 >> 28) & 0xF) << 12)
		| (WORD)(((colour32 >> 20) & 0xF) << 8)
		| (WORD)(((colour32 >> 12) & 0xF) << 4)
		| (WORD)(((colour32 >> 4) & 0xF) << 0);

	D3DLOCKED_RECT d3dlr;
	(*ppD3Dtex)->LockRect(0, &d3dlr, 0, 0);
	WORD* pDst16 = (WORD*)d3dlr.pBits;

	for (int xy = 0; xy < 8 * 8; xy++)
		*pDst16++ = colour16;

	(*ppD3Dtex)->UnlockRect(0);

	return S_OK;
}

class CD3DXMeshRenderingOption
{
public:
	DWORD	m_dwVS;

	CD3DXMeshRenderingOption(D3DFILLMODE d3dFillMode, const D3DXMATRIX& c_rmatWorld, D3DCOLOR colour)
	{
		//BACKUP
		Device::pDevice->GetVertexShader(&m_dwVS);
		Device::pDevice->GetRenderState(D3DRS_CULLMODE, &culling);
		Device::pDevice->GetRenderState(D3DRS_FILLMODE, &FillOld);
		Device::pDevice->GetRenderState(D3DRS_TEXTUREFACTOR, &textureFactor);
		Device::pDevice->GetTextureStageState(0, D3DTSS_COLORARG1, &colorArg1);
		Device::pDevice->GetTextureStageState(0, D3DTSS_COLORARG2, &colorArg2);
		Device::pDevice->GetTextureStageState(0, D3DTSS_COLOROP, &colorOp);
		Device::pDevice->GetTextureStageState(0, D3DTSS_ALPHAARG1, &alphaArg1);
		Device::pDevice->GetTextureStageState(0, D3DTSS_ALPHAARG2, &alphaArg2);
		Device::pDevice->GetTextureStageState(0, D3DTSS_ALPHAOP, &alphaOp);
		Device::pDevice->GetRenderState(D3DRS_ALPHABLENDENABLE, &alpaBlend);
		Device::pDevice->GetRenderState(D3DRS_SRCBLEND, &srcBlend);
		Device::pDevice->GetRenderState(D3DRS_DESTBLEND, &destBlend);
		Device::pDevice->GetTransform(D3DTS_WORLD, &stateold);

		//SET VALUES
		Device::pDevice->SetTexture(0, NULL);
		Device::pDevice->SetTexture(1, NULL);
		Device::pDevice->SetPixelShader(NULL);

		Device::pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
		Device::pDevice->SetRenderState(D3DRS_FILLMODE, d3dFillMode);
		Device::pDevice->SetRenderState(D3DRS_TEXTUREFACTOR, colour);

		Device::pDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TFACTOR);
		Device::pDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_TEXTURE);
		Device::pDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_SELECTARG1);

		Device::pDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TFACTOR);
		Device::pDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_TEXTURE);
		Device::pDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);

		Device::pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
		Device::pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
		Device::pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

		Device::pDevice->SetTransform(D3DTS_WORLD, &c_rmatWorld);
	}

	virtual ~CD3DXMeshRenderingOption()
	{
		//RESTORE
		Device::pDevice->SetVertexShader(m_dwVS);
		Device::pDevice->SetRenderState(D3DRS_CULLMODE, culling);
		Device::pDevice->SetRenderState(D3DRS_TEXTUREFACTOR, textureFactor);
		Device::pDevice->SetTextureStageState(0, D3DTSS_COLORARG1, colorArg1);
		Device::pDevice->SetTextureStageState(0, D3DTSS_COLORARG2, colorArg2);
		Device::pDevice->SetTextureStageState(0, D3DTSS_COLOROP, colorOp);
		Device::pDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, alphaArg1);
		Device::pDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, alphaArg2);
		Device::pDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, alphaOp);
		Device::pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, alpaBlend);
		Device::pDevice->SetRenderState(D3DRS_SRCBLEND, srcBlend);
		Device::pDevice->SetRenderState(D3DRS_DESTBLEND, destBlend);
		Device::pDevice->SetTransform(D3DTS_WORLD, &stateold);
		Device::pDevice->SetRenderState(D3DRS_FILLMODE, FillOld);
	}
};

void CRender::RenderSphere(LPD3DXMESH lpMesh, float fx, float fy, float fz, float fRadius, D3DFILLMODE d3dFillMode, D3DCOLOR colour) {
	D3DXMATRIX matTranslation;
	D3DXMATRIX matScaling;

	D3DXMatrixTranslation(&matTranslation, fx, fy, fz);
	D3DXMatrixScaling(&matScaling, fRadius, fRadius, fRadius);

	D3DXMATRIX matWorld;
	matWorld = matScaling * matTranslation;

	CD3DXMeshRenderingOption SetRenderingOption(d3dFillMode, matWorld, colour);
	IndexBuffer lpIndexBuffer;
	VertexBuffer lpVertexBuffer;
	lpMesh->GetIndexBuffer(&lpIndexBuffer);
	lpMesh->GetVertexBuffer(&lpVertexBuffer);
	Device::pDevice->SetVertexShader(lpMesh->GetFVF());
	Device::pDevice->SetIndices(lpIndexBuffer, 0);
	Device::pDevice->SetStreamSource(0, lpVertexBuffer, 24);
	Device::pDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, lpMesh->GetNumVertices(), 0, lpMesh->GetNumFaces());
}


void CRender::RenderBox(LPD3DXMESH ms_lpSphereMesh, float fx, float fy, float fz, float fRadius, D3DFILLMODE d3dFillMode, D3DCOLOR colour) {
	D3DXMATRIX matTranslation;
	D3DXMATRIX matScaling;
	D3DXMatrixTranslation(&matTranslation, fx, fy, fz);
	D3DXMatrixScaling(&matScaling, fRadius, fRadius, fRadius);
	D3DXMATRIX matWorld;
	matWorld = matScaling * matTranslation;
	CD3DXMeshRenderingOption SetRenderingOption(d3dFillMode, matWorld, colour);
	IndexBuffer lpIndexBuffer;
	VertexBuffer lpVertexBuffer;
	ms_lpSphereMesh->GetIndexBuffer(&lpIndexBuffer);
	ms_lpSphereMesh->GetVertexBuffer(&lpVertexBuffer);
	ms_lpSphereMesh->DrawSubset(0);
	Device::pDevice->SetVertexShader(ms_lpSphereMesh->GetFVF());
	Device::pDevice->SetIndices(lpIndexBuffer, 0);
	Device::pDevice->SetStreamSource(0, lpVertexBuffer, 24);
	Device::pDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, ms_lpSphereMesh->GetNumVertices(), 0, ms_lpSphereMesh->GetNumFaces());
}

void CRender::FilledCircle3D(int x, int y, int z, int radius, int points, D3DCOLOR colour) {
	int count;
	float theta, delta;
	std::vector<D3DXVECTOR3> pts;
	pts.clear();
	pts.resize(points);
	theta = 0.0;
	delta = 2 * D3DX_PI / float(points);
	for (count = 0; count < points; count++)
	{
		pts[count] = D3DXVECTOR3(radius * cosf(theta), radius * sinf(theta), 0.0f);
		theta += delta;
	}
	SD3DVertex* pVertex = new SD3DVertex[points];
	for (int i = 0; i < points; i++) {
		pVertex[i] = { 
			x + pts[i].x,
			y + pts[i].y,
			z + pts[i].z,
			1.0f, colour 
		};
	}
	Device::pDevice->SetTexture(0, NULL);
	Device::pDevice->SetTexture(1, NULL);
	Device::pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	Device::pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	Device::pDevice->SetVertex(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);
	Device::pDevice->DrawPrimitiveUP(D3DPT_LINELIST, points, pVertex, sizeof(SD3DVertex));
	delete[] pVertex;
}

int CRender::FrameRate() {
	static int iFps, iLastFps;
	static float flLastTickCount, flTickCount;
	flTickCount = clock() * 0.001f;
	iFps++;
	if ((flTickCount - flLastTickCount) >= 1.0f) {
		flLastTickCount = flTickCount;
		iLastFps = iFps;
		iFps = 0;
	}
	return iLastFps;
}