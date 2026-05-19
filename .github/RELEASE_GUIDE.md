# iOS SDK Release Guide

这份文档说明如何发布 TapTap iOS SDK 到 GitHub 和 CocoaPods。

## 技术栈

- **Xcode**: 16.4+
- **CocoaPods**: 最新版本
- **GitHub Actions**: CI/CD 流程
  - Linux runner: `ubuntu-latest`（创建 GitHub Release）
  - macOS runner: `macos-15-xlarge`（发布 CocoaPods）

## 前置要求

### 配置 GitHub Secrets

在仓库 **Settings → Secrets and variables → Actions** 中配置：

#### NETRC_CONTENT

CocoaPods Trunk 认证凭据，格式为 `~/.netrc` 文件内容：

```
machine trunk.cocoapods.org
  login YOUR_EMAIL
  password YOUR_TRUNK_TOKEN
```

**获取 Trunk Token：**

```bash
# 注册（首次）
pod trunk register YOUR_EMAIL 'YOUR_NAME'

# 查看 token
grep -A2 'trunk.cocoapods.org' ~/.netrc
```

## 发布流程

### 1. 更新版本号

确保 `iOS/PodSpecs/TapTapSDK.podspec` 中的版本号已更新（通常由 monorepo CI 自动完成）：

```ruby
s.version = '4.7.4'
```

### 2. 提交并推送代码

```bash
git add .
git commit -m "release: iOS SDK v4.7.4"
git push origin main
```

### 3. 创建并推送 Tag

```bash
git tag 4.7.4
git push origin 4.7.4
```

### 4. 自动化流程

Tag 推送后，GitHub Actions 自动执行：

1. **创建 GitHub Release**（Linux runner）
   - 自动生成 release notes

2. **发布到 CocoaPods**（macOS runner）
   - 校验 podspec 版本与 tag 一致
   - `pod spec lint` 验证 podspec
   - `pod trunk push` 推送到 CocoaPods Trunk
   - 若版本已存在（409），视为幂等成功，不报错

### 5. 验证发布

```bash
# 搜索新版本（CDN 更新需几分钟）
pod search TapTapSDK

# 查看版本列表
pod trunk info TapTapSDK
```

## 本地手动发布

如需在本地手动推送：

```bash
# 配置认证
cat > ~/.netrc <<EOF
machine trunk.cocoapods.org
  login YOUR_EMAIL
  password YOUR_TRUNK_TOKEN
EOF
chmod 600 ~/.netrc

# 验证 podspec
pod spec lint iOS/PodSpecs/TapTapSDK.podspec --allow-warnings --verbose --skip-import-validation

# 推送
pod trunk push iOS/PodSpecs/TapTapSDK.podspec --allow-warnings --verbose
```

## 常见问题

### Q: 版本号不匹配

CI 在推送前会校验 podspec 版本与 tag 是否一致，不一致会报错。确保两者相同。

### Q: pod trunk push 超时（504）

CocoaPods trunk 服务器偶发超时。重跑 workflow 即可。若实际已发布（可能因超时看起来失败），重跑会收到 409 幂等成功提示。

### Q: 409 Conflict

版本已存在于 CocoaPods trunk，CI 会打印警告并正常退出（幂等处理）。

### Q: CocoaPods 找不到新版本

CDN 缓存更新需要 15-30 分钟，等待后重试。

## 项目结构

```
.
├── .github/
│   ├── workflows/
│   │   └── release.yml          # GitHub Actions 工作流
│   └── RELEASE_GUIDE.md         # 本文档
├── iOS/
│   ├── Frameworks/              # xcframeworks + resource bundles
│   └── PodSpecs/
│       └── TapTapSDK.podspec    # CocoaPods 规范文件（当前版本）
└── TapTapSDK/                   # 各版本归档 podspec
    └── {version}/
        └── TapTapSDK.podspec
```

## 支持的 Tag 格式

- `v1.0.0`（推荐）
- `1.0.0`

## 相关链接

- [CocoaPods 文档](https://guides.cocoapods.org/)
- [GitHub Actions 文档](https://docs.github.com/actions)
- [Semantic Versioning](https://semver.org/)
