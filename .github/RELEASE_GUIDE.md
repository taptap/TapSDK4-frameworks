# iOS SDK Release Guide

这份文档说明如何发布 TapTap iOS SDK 到 GitHub 和 CocoaPods。

## 技术栈

本项目使用 **Fastlane** 来自动化发布流程：

- **Xcode**: 16.4+
- **Ruby**: 3.3
- **Fastlane**: 2.228.0+
- **CocoaPods**: 最新版本
- **GitHub Actions**: CI/CD 流程
  - Linux runner: `tapsdk-linux-x64-16c`
  - macOS runner: `macos-15-xlarge`

## 前置要求

### 1. 配置 GitHub Secrets

在 GitHub 仓库中配置以下 Secret：

#### COCOAPODS_TRUNK_TOKEN

这是发布到 CocoaPods 所需的认证 token。

**获取 CocoaPods Trunk Token 的步骤：**

1. 如果还没有注册 CocoaPods Trunk 账号，先注册：
   ```bash
   pod trunk register YOUR_EMAIL 'YOUR_NAME' --description='YOUR_DESCRIPTION'
   ```

2. 检查邮箱并点击确认链接

3. 获取你的 Trunk token：
   ```bash
   cat ~/.netrc
   ```

   或者使用：
   ```bash
   grep -A 2 'trunk.cocoapods.org' ~/.netrc | grep password | awk '{print $2}'
   ```

4. 将获取到的 token 添加到 GitHub Secrets：
   - 进入仓库的 **Settings** → **Secrets and variables** → **Actions**
   - 点击 **New repository secret**
   - Name: `COCOAPODS_TRUNK_TOKEN`
   - Value: 粘贴你的 token
   - 点击 **Add secret**

## 发布流程

### 1. 更新版本号

在发布新版本前，确保更新了 `iOS/PodSpecs/TapTapSDK.podspec` 中的版本号：

```ruby
s.version = '4.7.4'  # 更新为新版本号
```

### 2. 提交并推送代码

```bash
git add .
git commit -m "🚀 Release TapTap SDK v4.7.4"
git push origin main
```

### 3. 创建并推送 Tag

创建一个新的 Git tag 来触发发布流程：

```bash
# 创建 tag（推荐使用 v 前缀）
git tag v4.7.4

# 或者不使用 v 前缀
git tag 4.7.4

# 推送 tag 到远程仓库
git push origin v4.7.4
```

### 4. 自动化流程

一旦 tag 被推送，GitHub Actions 会自动执行以下操作：

1. **创建 GitHub Release**
   - 使用 tag 名称创建 release
   - 自动生成 release notes（基于 commit 历史）
   - 发布到 GitHub Releases 页面

2. **使用 Fastlane 发布到 CocoaPods**
   - 验证 podspec 版本与 tag 版本是否匹配
   - 使用 `pod lib lint` 验证 podspec 格式
   - 使用 `pod trunk push` 推送到 CocoaPods
   - 所有流程通过 Fastlane 自动化管理

### 5. 验证发布

发布完成后，可以通过以下方式验证：

#### 验证 GitHub Release
访问仓库的 Releases 页面：
```
https://github.com/YOUR_ORG/YOUR_REPO/releases
```

#### 验证 CocoaPods
等待几分钟后，检查 CocoaPods 上的版本：
```bash
pod search TapTapSDK
```

或者查看 pod spec：
```bash
pod spec cat TapTapSDK
```

## 本地测试发布流程

在推送 tag 之前，你可以在本地测试 Fastlane 发布流程。

### 安装依赖

本项目使用 **Bundler** 管理 Ruby 依赖，确保版本一致：

```bash
# 安装 Bundler（如果还没安装）
gem install bundler

# 安装项目依赖（Fastlane 和 CocoaPods）
bundle install
```

### 验证 Podspec

```bash
# 只验证，不发布
bundle exec fastlane validate
```

### 测试完整发布流程

```bash
# 验证版本号和 podspec（需要配置 COCOAPODS_TRUNK_TOKEN）
bundle exec fastlane release version:4.7.4
```

**重要提示：**
- 始终使用 `bundle exec` 前缀来运行 Fastlane，确保使用正确的依赖版本
- 本地运行 `fastlane release` 需要配置 `COCOAPODS_TRUNK_TOKEN` 环境变量

## Fastlane Lanes 说明

项目中的 Fastlane 配置文件位于 `fastlane/Fastfile`，包含以下 lanes：

### `fastlane validate`
- **用途**：仅验证 podspec 格式，不发布
- **适用场景**：本地开发时验证 podspec 是否正确

### `fastlane release_to_cocoapods`
- **用途**：验证并发布到 CocoaPods
- **适用场景**：由 CI/CD 自动调用

### `fastlane release version:X.X.X`
- **用途**：完整的发布流程，包含版本验证
- **适用场景**：由 CI/CD 自动调用，或本地手动发布

## 常见问题

### Q: 版本号不匹配错误

**错误信息：**
```
Error: Podspec version (4.7.3) does not match tag version (4.7.4)
```

**解决方法：**
确保 `iOS/PodSpecs/TapTapSDK.podspec` 中的版本号与 Git tag 的版本号一致。

### Q: CocoaPods 验证失败

**可能原因：**
- podspec 文件格式错误
- 引用的文件不存在
- 依赖项配置错误

**解决方法：**
在本地先运行验证：
```bash
# 使用 Fastlane
fastlane validate

# 或直接使用 CocoaPods 命令
pod spec lint iOS/PodSpecs/TapTapSDK.podspec --allow-warnings --verbose
```

### Q: COCOAPODS_TRUNK_TOKEN 未配置

**错误信息：**
```
Error: COCOAPODS_TRUNK_TOKEN is not set
```

**解决方法：**
按照本文档的"配置 GitHub Secrets"部分配置 token。

### Q: 发布到 CocoaPods 后找不到新版本

**原因：**
CocoaPods 的 CDN 缓存需要时间更新，通常需要 15-30 分钟。

**解决方法：**
等待一段时间后再尝试搜索或安装。

### Q: Fastlane 执行失败

**排查步骤：**
1. 检查 Ruby 版本（需要 3.3+）：`ruby -v`
2. 检查 Fastlane 版本（需要 2.228.0+）：`fastlane --version`
3. 查看详细日志，通常 Fastlane 会提供清晰的错误信息
4. 确认 `fastlane/Fastfile` 配置正确

## 回滚发布

如果需要删除已发布的版本：

### 删除 GitHub Release
1. 访问 Releases 页面
2. 点击对应版本的 "Delete" 按钮
3. 删除对应的 Git tag：
   ```bash
   git tag -d v4.7.4
   git push origin :refs/tags/v4.7.4
   ```

### 删除 CocoaPods 版本
⚠️ **注意：** CocoaPods 不支持删除已发布的版本。如果发布了有问题的版本，应该：
1. 修复问题
2. 发布一个新的补丁版本（如 4.7.4 → 4.7.5）

## 支持的 Tag 格式

workflow 支持以下 tag 格式：
- `v1.0.0`（推荐）
- `1.0.0`
- `v4.7.3`
- `4.7.3`

版本号格式应遵循 [Semantic Versioning](https://semver.org/)：
- MAJOR.MINOR.PATCH
- 例如：4.7.3 表示主版本 4，次版本 7，补丁版本 3

## 项目结构

```
.
├── .github/
│   ├── workflows/
│   │   └── release.yml          # GitHub Actions 工作流
│   └── RELEASE_GUIDE.md         # 本文档
├── fastlane/
│   ├── Fastfile                 # Fastlane 配置文件
│   └── README.md                # Fastlane 使用文档
├── iOS/
│   ├── Frameworks/              # xcframeworks + resource bundles
│   └── PodSpecs/
│       └── TapTapSDK.podspec    # CocoaPods 规范文件（当前版本）
├── Gemfile                      # Ruby 依赖配置
└── Gemfile.lock                 # 依赖版本锁定（自动生成）
```

## 相关链接

- [Fastlane 文档](https://docs.fastlane.tools/)
- [CocoaPods 文档](https://guides.cocoapods.org/)
- [GitHub Actions 文档](https://docs.github.com/actions)
- [Semantic Versioning](https://semver.org/)
