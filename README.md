# HTTPDebuggerKeygen
A reverse engineered C# version of a Keygen for the [HTTP Debugger](https://www.httpdebugger.com/).

### Yarr! Ahoy, matey! Ye be welcome 'ere!

The Keygen works by creating a registery key to `Software\\MadeForNet\\HTTPDebuggerPro`.
#### An example key
| Value name      | Value data |
| ----------- | ----------- |
| SNXXXXXXXXXX     | XXXXXX7CXXXXXXXX  (16)|

## Todo

1. Create function(s) for the value name

    * The key needs a correct name so the program recognizes it— e.g, `SN1234567890`. The name isn't static, your disk's serial number affects it, so it can't be shared.

    * The Keygen has functions for this, but I'd still have to translate that to C#. It's a pain.

## Contributing

If you'd like to give the translation/reverse engineering a go, see the **decompiled source** of the Keygen. Start by translating the `sub_40123E` function's sprintf part. I've translated everything else, but can't figure out what value `dword_40347E` should have, the functions relating to that variable are a pain in the ass.

*This is just a project to learn reverse engineering, so don't feel the need to contribute in any way.*
