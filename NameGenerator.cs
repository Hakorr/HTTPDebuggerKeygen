using System;
using System.Text;
using System.Runtime.InteropServices;

/// <summary>
/// Currently, the code is broken and nonfunctional.
/// </summary>

class NameGenerator
{
    [DllImport("kernel32.dll")]
    private static extern long GetVolumeInformation(string PathName, StringBuilder VolumeNameBuffer, UInt32 VolumeNameSize, ref UInt32 VolumeSerialNumber, ref UInt32 MaximumComponentLength, ref UInt32 FileSystemFlags, StringBuilder FileSystemNameBuffer, UInt32 FileSystemNameSize);
    private uint GetVolumeSerial(string strDriveLetter)
    {
        uint serNum = 0;
        uint maxCompLen = 0;
        StringBuilder VolLabel = new StringBuilder(256); // Label
        UInt32 VolFlags = new UInt32();
        StringBuilder FSName = new StringBuilder(256); // File System Name
        strDriveLetter += ":\\"; // fix up the passed-in drive letter for the API call
        long Ret = GetVolumeInformation(strDriveLetter, VolLabel, (UInt32)VolLabel.Capacity, ref serNum, ref maxCompLen, ref VolFlags, FSName, (UInt32)FSName.Capacity);

        return serNum;
    }
    private static int LoWord(int dwValue)
    {
        return (dwValue & 0xFFFF);
    }

    private unsafe int sub_401390(byte* a1)
    {
        int v1;
        int v2;
        int v3;
        byte* v4;

        v1 = 0;
        v2 = 0;
        v3 = *a1;
        v4 = a1 + 1;
        if ((byte)v3 == 2)
        {
            BitConverter.GetBytes(LoWord(v3))[0] = *v4;
            v2 = -1;
            v4 = a1 + 2;
        }
        while ((byte)v3 > 0)
        {
            BitConverter.GetBytes(LoWord(v3))[0] = (byte)(v3 - 48);
            v1 = v3 + 10 * v1;
            BitConverter.GetBytes(LoWord(v3))[0] = *v4++;
        }
        return v2 ^ (v1 + v2);
    }

    private unsafe int sub_4013D0(int a1)
    {
        byte* v1;

        v1 = (byte*)(a1 - 4);

        while (true)
        {
            v1 += 4;
            if (*v1 == 0)
                break;
            if (v1[1] == 0)
                return (int)&v1[-a1 + 1];
            if (v1[2] == 0)
                return (int)&v1[-a1 + 2];
            if (v1[3] == 0)
                return (int)&v1[-a1 + 3];
        }
        return (int)&v1[-a1];
    }

    private unsafe int sub_401420(int a1, int a2)
    {
        int v2;
        char v3;
        uint v4;
        byte* v5;
        int v6;
        int v7;
        char v8;

        v2 = 0;
        do
        {
            v3 = (char)*(byte*)(v2 + a1);
            *(byte*)(v2 + a2) = (byte)v3;
            ++v2;
        }
        while (v3 > 0);
        v4 = (uint)(v2 - 1);
        v5 = (byte*)(v4 + a2 - 1);
        v6 = (int)-(v4 >> 1);
        v7 = a2 - v6;
        do
        {
            v8 = (char)*(byte*)(v6 + v7);
            *(byte*)(v6 + v7) = *v5;
            *v5-- = (byte)v8;
            ++v6;
        }
        while (v6 > 0);
        return a2;
    }

    public unsafe string Create()
    {
        /*
            v4 = (char *)&unk_403373 + sub_4013D0((int)&byte_403374);
            v5 = 0;
            while ( *v4 != 32 )
            {
                if ( *v4 != 46 )
                    String[v5++] = *v4;
                --v4;
            }
            sub_401420((int)String, (int)String);
            dword_40347E = sub_401390((unsigned __int8 *)String);
            ...

        */

        var dword_40347E = 1; //TODO: Solve

        return string.Format("SN{0:d}", dword_40347E ^ ((~GetVolumeSerial("C") >> 1) + 736) ^ 0x590D4);
    }
}
