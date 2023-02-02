# ThemidaPlugin
This is a custom plugin example for Themida (DLLs), that will be embedded inside the protected binary. The embedded plugin have defined callbacks that will be called when a specific protection event occurs, so you can have more control on the protection, add your own custom protections, etc.

A plugin is basically a compiled native DLL that exports specific functions names  that matches a specific name pattern.
For example, the callback *"SecureEngineInitialize"* (notice the wildcard) means that you can define any function (to export) that will contain the "SecureEngineInitialize" string within your function name.

<p align="center"><img src="https://i.imgur.com/Nw9INjG.png" /></p>
