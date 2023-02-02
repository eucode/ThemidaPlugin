# ThemidaPlugin
This is a custom plugin example for Themida (DLLs), that will be embedded inside the protected binary. The embedded plugin have defined callbacks that will be called when a specific protection event occurs, so you can have more control on the protection, add your own custom protections, etc.

A plugin is basically a compiled native DLL that exports specific functions names  that matches a specific name pattern.
For example, the callback *"SecureEngineInitialize"* (notice the wildcard) means that you can define any function (to export) that will contain the "SecureEngineInitialize" string within your function name.

<p align="center"><img src="https://i.imgur.com/Nw9INjG.png" /></p>



## Perform process hooking
This option will fully emulate the loading of your DLL in memory. This option is only required for specific plugins. Most plugins will work fine without this option. The preferred is to have this option unchecked, because it won't perform any hooking on the current process.


## Testing your plugins
To test your plugin, you can just right-click on it and select "Test Plugin". Your defined callbacks will be called with default/dummy parameters to test your callbacks. If a callback fails (produces exception, etc) it will be reported on the User Interface.


## Plugin Callback
The current defined callbacks (name patterns) are:
| Callback Name  | Function |
| ------------- | ------------- |
| SecureEngineInitialize  | This function is called when the protection starts, before your application has been processed (decrypted, decompressed, etc) to be executed in memory. |
| SecureEngineFinalize  | This function is called when the protection boot loader has been executed, your application is ready to have control of the CPU  |
| SecureEngineShowCustomMessage  | This function is called when a Customized Dialog is going to be displayed by the protection.  |
| SecureEngineGetEncryptionKey  | This function allows you to specify an encryption key to encrypt/decrypt specific areas in your application.  |
| SecureEngineGetProtectedFileName  | This function is called before SecureEngineInitialize. This function receives the name of the executable binary (EXE or DLL) that contains the plugin.  |
| SecureEngineGetFingerPrint  | This function receives the fingerprint or watermark that was inserted in protection time. |
