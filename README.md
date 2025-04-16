# SOC_LVGL

## `main` 分支

### 分支介绍

该分支存在的意义是帮助开发者快速烧录 `LVGL` 示例程序到 `SC` 开发板上。

### 计划进展

- [x] 将 `LVGL` `v8.2.0` 移植到 `SC` 系统板上。
- [x] 裁剪 `LVGL` `v8.2.0`。
- [ ] 升级 `LVGL` 到 `v8.4.0`。

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

## 格式化项目代码

### 使用方法

1. **运行脚本**：

   ```powershell
   cd <项目根目录>
   Set-ExecutionPolicy Bypass -Scope Process -Force  # 临时允许脚本执行
   .\Scripts\format-code.ps1
   ```

2. **文件说明**：`.clang-format-ignore` 记录的内容会被格式化脚本 `format-code.ps1` 忽略。
