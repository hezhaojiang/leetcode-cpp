# VSCode 刷题环境配置

## 插件列表

``` bash
名称: C/C++
ID: ms-vscode.cpptools
说明: C/C++ IntelliSense, debugging, and code browsing.
发布者: Microsoft
链接: https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools

名称: LeetCode
ID: leetcode.vscode-leetcode
说明: Solve LeetCode problems in VS Code
发布者: 力扣 LeetCode
链接: https://marketplace.visualstudio.com/items?itemName=LeetCode.vscode-leetcode
```

## 调试环境配置（使用MSVC）

配置环境变量如下（VS2019）：

``` bash
# PATH
C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx64\x64\
# INCLUDE
C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.28.29333\include
C:\Program Files (x86)\Windows Kits\10\Include\10.0.18362.0\shared
C:\Program Files (x86)\Windows Kits\10\Include\10.0.18362.0\ucrt
C:\Program Files (x86)\Windows Kits\10\Include\10.0.18362.0\um
C:\Program Files (x86)\Windows Kits\10\Include\10.0.18362.0\winrt
# LIB
C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.28.29333\lib\x64
C:\Program Files (x86)\Windows Kits\10\Lib\10.0.18362.0\um\x64
C:\Program Files (x86)\Windows Kits\10\Lib\10.0.18362.0\ucrt\x64
```
