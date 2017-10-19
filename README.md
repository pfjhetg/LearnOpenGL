# LearnOpenGL
> 所有代码都亲测用

* 这个教程是基于Xcode的,如果有人感兴趣,可以参照这个教程配置环境:[在Xcode中配置GLEW+GLFW环境](http://blog.csdn.net/longzh_cn/article/details/55001345),然后在main.cpp中去掉需要进行显示的例子的注释即可.

## Assimp配置
* 直接通过brew工具安装
* 使用和glew一样的配置方式
* 使用`#include <assimp/Importer.hpp>`导入
 
## freetype配置
* 通过brew安装:brew install freetype
* 然后使用和glew一样的方式配置
* 这一步和上面不一同:首先需要在Header Search Paths里面加入/usr/local/Cellar/freetype/2.8.1/include/freetype2,然后在Bulid Settings中的Other Linker Flags中填-lfreetype.这样才能保证在#include FT_FREETYPE_H的时候不出错.
* 导入#include <freetype2/ft2build.h>和#include FT_FREETYPE_H 可能需要修改ft2build.h中的#include <freetype/config/ftheader.h>为#include "freetype/config/ftheader.h"



