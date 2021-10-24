using System;

public class KeyGenerator 
{
    private static Random rand = new Random();

    public string Create()
    {
        string key = "";

        while (key.Length != 16)
        {
            int v1;
            int v2;
            int v3;

            v1 = rand.Next() % 255;
            v2 = rand.Next() % 255;
            v3 = rand.Next();

            //Format XXXX XX7C XXXX XXXX
            key = String.Format("{0:X2}{1:X2}{2:X2}7C{3:X2}{4:X2}{5:X2}{6:X2}",
                v1,
                v2 ^ 0x7C,
                (byte)~(byte)v1,
                v2,
                v3 % 255,
                (byte)(v3 % 255) ^ 7,
                v1 ^ (byte)~(v3 % 255));
        }

        return key;
    }
}
