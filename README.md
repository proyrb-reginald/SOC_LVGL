# SOC_LVGL

## `test_fps` 分支

### 分支介绍

该分支存在的意义是帮助开发者进行帧率测试。

### 计划进展

- [x] 设计开发出测试用的 `Demo` 示例。
      要求：在容器内滚动图片，记录最低和最高帧率。

### 工程结构

```plaintext
根目录/
├── Drivers/              # 底层驱动
├── GUI/                  # 图形用户界面（由 SquareLine Studio 生成）
│   ├── components/       # 用户自定义组件
│   ├── drive/            # SquareLine Studio 资源文件
│   ├── fonts/            # 用户自定义字体
│   ├── images/           # 源代码形式的图片资源
│   └── screens/          # 不同屏幕的 UI 代码
├── Headers/              # CMSIS 头文件
├── Middlewares/          # 中间件
│   └── LVGL/             # LVGL 源码
├── Scripts/              # 各平台格式化脚本
├── Startup/              # 启动文件
├── System/               # 用户级代码
├── .clang-format         # 格式化配置信息
├── .clang-format-ignore  # 格式化配置信息
├── .gitignore            # 格式化配置信息
├── LICENSE               # MIT 开源协议
├── README.md             # 项目介绍
├── SOC_LVGL.uvoptx       # Keil uVision5 配置项
├── SOC_LVGL.uvprojx      # Keil uVision5 项目文件
└── Templst.soclst        # SOC 烧录配置项
```

### 如何测试

1. **测试图片**

    - 原图存放路径为：

      ```plaintext
      GUI/drive/assets/background_200.jpg
      ```

      - 尺寸大小：200 * 200
      - 空间占用：4.91 KB（受目标设备ROM空间的限制）

    - 代码存放路径为：

      ```plaintext
      GUI/images/background_200.c
      ```

      > 如果要更换其他图片，建议先对图片进行质量压缩，推荐在线工具 [tinify](https://tinypng.com/)。然后再使用 LVGL 官方的 [在线转换工具](https://lvgl.io/tools/imageconverter) 将图片转化为代码形式（对于 v8 版本，颜色格式建议选择 CF_TRUE_COLOR。最后将 C 代码导入工程，在需要使用图片的代码中添加 LV_IMG_DECLARE(img_name) 这个宏定义。img_name 需要用图片代码的实际变量名进行替换，可以去图片代码最后部分查找 lv_img_dsc_t 类型的变量，这个变量就是图片代码的变量名。

2. **测试选项**
    打开 `ui.h` 文件，选择 `Container_Size` 宏以设置不同的测试条件。

3. **测试流程**
    在容器内滚动图片，观察帧率。

    
## 格式化项目代码

### 使用方法

1. **运行脚本**：

   ```powershell
   cd <项目根目录>
   Set-ExecutionPolicy Bypass -Scope Process -Force  # 临时允许脚本执行
   .\Scripts\format-code.ps1
   ```

2. **文件说明**：`.clang-format-ignore` 记录的内容会被格式化脚本 `format-code.ps1` 忽略。
