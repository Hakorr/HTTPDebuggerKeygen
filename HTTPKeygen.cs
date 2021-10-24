using Microsoft.Win32;

class HTTPKeygen {
    public RegistryKey key = Registry.CurrentUser.CreateSubKey(@"Software\\MadeForNet\\HTTPDebuggerPro");

    public KeyGenerator keyGen = new KeyGenerator();
    public NameGenerator nameGen = new NameGenerator();

    public void Create() {
        key.SetValue(nameGen.Create(), keyGen.Create());
    } 
}
