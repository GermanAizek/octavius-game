mkdir %~dp0\build\Debug\gamedata\fonts
copy "%~dp0\res\gamedata\fonts\*.*" "%~dp0\build\Debug\gamedata\fonts"
mkdir %~dp0\build\Debug\gamedata\sounds
copy "%~dp0\res\gamedata\sounds\*.*" "%~dp0\build\Debug\gamedata\sounds"
mkdir %~dp0\build\Debug\gamedata\textures
copy "%~dp0\res\gamedata\textures\*.*" "%~dp0\build\Debug\gamedata\textures"
copy "%~dp0\res\x64\*.*" "%~dp0\build\Debug"