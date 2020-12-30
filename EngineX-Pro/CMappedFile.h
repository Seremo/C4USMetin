#pragma once
class CFileBase
{
public:
	enum EFileMode
	{
		FILEMODE_READ = (1 << 0),
		FILEMODE_WRITE = (1 << 1)
	};

	CFileBase();
	virtual	~CFileBase();

	void			Destroy();
	void			Close();

	BOOL			Create(const char* filename, EFileMode mode);
	DWORD			Size();
	void			SeekCur(DWORD size);
	void			Seek(DWORD offset);
	DWORD			GetPosition();

	virtual BOOL	Write(const void* src, int bytes);
	BOOL			Read(void* dest, int bytes);

	char* GetFileName();
	BOOL			IsNull();

protected:
	int				m_mode;
	char			m_filename[MAX_PATH + 1];
	HANDLE			m_hFile;
	DWORD			m_dwSize;
};

class CMappedFile : public CFileBase
{
public:
	enum ESeekType
	{
		SEEK_TYPE_BEGIN,
		SEEK_TYPE_CURRENT,
		SEEK_TYPE_END
	};

public:
	CMappedFile();
	virtual ~CMappedFile();

	void		Link(DWORD dwBufSize, const void* c_pvBufData);

	BOOL		Create(const char* filename);
	BOOL		Create(const char* filename, const void** dest, int offset, int size);
	LPCVOID		Get();
	void		Destroy();
	int			Seek(DWORD offset, int iSeekType = SEEK_TYPE_BEGIN);
	int			Map(const void** dest, int offset = 0, int size = 0);
	DWORD		Size();
	DWORD		GetPosition();
	BOOL		Read(void* dest, int bytes);
	DWORD		GetSeekPosition();
	void		BindLZObject(DWORD* pLZObj);
	void		BindLZObjectWithBufferedSize(DWORD* pLZObj);
	BYTE* AppendDataBlock(const void* pBlock, DWORD dwBlockSize);

	BYTE* GetCurrentSeekPoint();

private:
	void		Unmap(LPCVOID data);

private:
	BYTE* m_pbBufLinkData;
	DWORD		m_dwBufLinkSize;

	BYTE* m_pbAppendResultDataBlock;
	DWORD		m_dwAppendResultDataSize;

	DWORD		m_seekPosition;
	HANDLE		m_hFM;
	DWORD		m_dataOffset;
	DWORD		m_mapSize;
	LPVOID		m_lpMapData;
	LPVOID		m_lpData;

	DWORD* m_pLZObj;
};