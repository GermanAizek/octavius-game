mkdir %~dp0\build\Release\gamedata\fonts
copy "%~dp0\res\gamedata\fonts\*.*" "%~dp0\build\Release\gamedata\fonts"
mkdir %~dp0\build\Release\gamedata\sounds
copy "%~dp0\res\gamedata\sounds\*.*" "%~dp0\build\Release\gamedata\sounds"
mkdir %~dp0\build\Release\gamedata\textures
copy "%~dp0\res\gamedata\textures\*.*" "%~dp0\build\Release\gamedata\textures"
copy "%~dp0\res\x86\*.*" "%~dp0\build\Release"