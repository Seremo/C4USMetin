#pragma once
class CryptExtension
{
public:
	static void Xor32Encrypt(unsigned char* Buff, int SizeOfHeader, int Len)
	{
		BYTE byXorFilter[32] = { 0 };
		byXorFilter[0] = 0xAB;
		byXorFilter[1] = 0x11;
		byXorFilter[2] = 0xCD;
		byXorFilter[3] = 0xFE;
		byXorFilter[4] = 0x18;
		byXorFilter[5] = 0x23;
		byXorFilter[6] = 0xC5;
		byXorFilter[7] = 0xA3;
		byXorFilter[8] = 0xCA;
		byXorFilter[9] = 0x33;
		byXorFilter[10] = 0xC1;
		byXorFilter[11] = 0xCC;
		byXorFilter[12] = 0x66;
		byXorFilter[13] = 0x67;
		byXorFilter[14] = 0x21;
		byXorFilter[15] = 0xF3;
		byXorFilter[16] = 0x32;
		byXorFilter[17] = 0x12;
		byXorFilter[18] = 0x15;
		byXorFilter[19] = 0x35;
		byXorFilter[20] = 0x29;
		byXorFilter[21] = 0xFF;
		byXorFilter[22] = 0xFE;
		byXorFilter[23] = 0x1D;
		byXorFilter[24] = 0x44;
		byXorFilter[25] = 0xEF;
		byXorFilter[26] = 0xCD;
		byXorFilter[27] = 0x41;
		byXorFilter[28] = 0x26;
		byXorFilter[29] = 0x3C;
		byXorFilter[30] = 0x4E;
		byXorFilter[31] = 0x4D;

		for (int i = 0; i < Len; i++)
		{
			Buff[i] ^= (byXorFilter[(i + SizeOfHeader) & 31] ^ Buff[i - 1]);
		}
			
	}

	static void Xor32Decrypt(unsigned char* Buff, int SizeOfHeader, int Len)
	{
		BYTE byXorFilter[32] = { 0 };
		byXorFilter[0] = 0xAB;
		byXorFilter[1] = 0x11;
		byXorFilter[2] = 0xCD;
		byXorFilter[3] = 0xFE;
		byXorFilter[4] = 0x18;
		byXorFilter[5] = 0x23;
		byXorFilter[6] = 0xC5;
		byXorFilter[7] = 0xA3;
		byXorFilter[8] = 0xCA;
		byXorFilter[9] = 0x33;
		byXorFilter[10] = 0xC1;
		byXorFilter[11] = 0xCC;
		byXorFilter[12] = 0x66;
		byXorFilter[13] = 0x67;
		byXorFilter[14] = 0x21;
		byXorFilter[15] = 0xF3;
		byXorFilter[16] = 0x32;
		byXorFilter[17] = 0x12;
		byXorFilter[18] = 0x15;
		byXorFilter[19] = 0x35;
		byXorFilter[20] = 0x29;
		byXorFilter[21] = 0xFF;
		byXorFilter[22] = 0xFE;
		byXorFilter[23] = 0x1D;
		byXorFilter[24] = 0x44;
		byXorFilter[25] = 0xEF;
		byXorFilter[26] = 0xCD;
		byXorFilter[27] = 0x41;
		byXorFilter[28] = 0x26;
		byXorFilter[29] = 0x3C;
		byXorFilter[30] = 0x4E;
		byXorFilter[31] = 0x4D;

		for (int i = Len - 1; i >= 0; i--)
		{
			Buff[i] ^= (byXorFilter[(i + SizeOfHeader) & 31] ^ Buff[i - 1]);
		}
			
	}

};
	